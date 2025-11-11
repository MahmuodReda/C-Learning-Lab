
#include <iostream>
#include <vector>
#include <string>
#include <mutex>
#include <iomanip>

// -----------------------------
// BackTrace class (singleton)
// -----------------------------
class BackTrace {
public:
    // Get singleton instance
    static BackTrace &getInstance() {
        static BackTrace instance;
        return instance;
    }

    // push function name on the stack (entering a function)
    void Enter(const std::string &name) {
        std::lock_guard<std::mutex> lock(mutex_);
        stack_.push_back(name);
        // Print minimal runtime message
        std::cout << "Enter to [" << name << "]\n";
    }

    // pop the last function name (exiting a function)
    void Exit() {
        std::lock_guard<std::mutex> lock(mutex_);
        if (!stack_.empty()) {
            std::string name = stack_.back();
            stack_.pop_back();
            std::cout << "Exit From [" << name << "]\n"; 
        } else {
            // defensive: nothing to pop
            std::cout << "Exit called but stack empty\n";
        }
    }
 
    // print the backtrace from bottom (0) to top (N)
    void Print() {
        std::lock_guard<std::mutex> lock(mutex_);
        std::cout << "Backtrace as follows :\n";
        for (size_t i = 0; i < stack_.size(); ++i) {
            std::cout << i << "- " << stack_[i] << "\n";
        }
        std::cout << "Back Trace is Finished\n";
    }

    // clear stack (if needed)
    void Clear() {
        std::lock_guard<std::mutex> lock(mutex_);
        stack_.clear();
    }

private:
    BackTrace() = default;
    ~BackTrace() = default;
    BackTrace(const BackTrace&) = delete;
    BackTrace& operator=(const BackTrace&) = delete;

    std::vector<std::string> stack_;
    std::mutex mutex_;
};

// -----------------------------
// RAII helper: push name on ctor and pop on dtor
// usage: ScopedTrace t(__FUNCTION__);
// -----------------------------
class ScopedTrace {
public:
    explicit ScopedTrace(const char* fn_name) : name_(fn_name) {
        BackTrace::getInstance().Enter(name_);
    }
    ~ScopedTrace() {
        BackTrace::getInstance().Exit();
    }

    // non-copyable
    ScopedTrace(const ScopedTrace&) = delete;
    ScopedTrace& operator=(const ScopedTrace&) = delete;

private:
    const char* name_;
};

// -----------------------------
// Macros for convenience
// -----------------------------
#define EnterFn BackTrace::getInstance().Enter(__FUNCTION__)
#define ExitFn  BackTrace::getInstance().Exit()
#define PRINT_BT BackTrace::getInstance().Print()
#define SCOPED_TRACE ScopedTrace __scoped_trace__(__FUNCTION__)

// -----------------------------
// Example functions
// -----------------------------
void fun3(int x) {
    // use RAII so we don't forget to call Exit
    SCOPED_TRACE;
    // do some work...
    std::cout << "fun3: doing work with x=" << x << "\n";

    // print current backtrace (optional)
    PRINT_BT;
    // when function returns, ScopedTrace destructor will call Exit()
}

void fun2(int x) {
    SCOPED_TRACE;
    std::cout << "fun2: begin\n";
    fun3(x + 1);
    std::cout << "fun2: end\n";
}

void fun1(int x) {
    SCOPED_TRACE;
    std::cout << "fun1: begin\n";
    fun2(x + 1);
    std::cout << "fun1: end\n";
}

int main() {
    SCOPED_TRACE; // marks "main"
    std::cout << "Start program\n";

    fun1(1);

    std::cout << "Program finished\n";
    return 0;
}

// Enter to [main]
// Start program
// Enter to [fun1]
// fun1: begin
// Enter to [fun2]
// fun2: begin
// Enter to [fun3]
// fun3: doing work with x=3
// Backtrace as follows :
// 0- main
// 1- fun1
// 2- fun2
// 3- fun3
// Back Trace is Finished
// Exit From [fun3]
// fun2: end
// Exit From [fun2]
// fun1: end
// Exit From [fun1]
// Program finished
// Exit From [main]