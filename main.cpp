#include <iostream>
#include <vector>
#include <string>
#include <mutex>
#include <iomanip>


class BackTrace {
public:
  static void Enter( const  std::string &name) {
     std::lock_guard<std::mutex> lock(BackTrace::mutex_);
     BackTrace::stack.push_back(name);

     
      std::cout << "Enter to [" << name << "]\n";
  
    }
    static void  Exit() {
   std::lock_guard<std::mutex> lock(BackTrace::mutex_);
     if (!BackTrace::stack.empty()) {
        std::cout << "Exit From [" << BackTrace::stack.back() << "]\n"; 
       BackTrace::stack.pop_back();
        } else {
            // defensive: nothing to pop
            std::cout << "Exit called but stack empty\n";
        }

    }

     
private: 
static std::vector<std::string> stack ;
static std::mutex mutex_;
};
std::vector<std::string> BackTrace::stack;
std::mutex BackTrace::mutex_;
// -----------------------------
// Example functions
// -----------------------------
void fun3(int x) {
BackTrace::Enter(__func__);
    std::cout << "fun3: begin\n";

    std::cout << "fun3: end\n";
    BackTrace::Exit() ;
  
}

void fun2(int x) {
BackTrace::Enter(__func__);
    std::cout << "fun2: begin\n";
    fun3(x + 1);
    std::cout << "fun2: end\n";
     BackTrace::Exit() ;
}

void fun1(int x) {

    BackTrace::Enter(__func__);
    
    std::cout << "fun1: begin\n";
    fun2(x + 1);
    std::cout << "fun1: end\n";
     BackTrace::Exit() ;
}

int main(){
BackTrace::Enter(__func__);
    std::cout << "Start program\n";

    fun1(1);
 BackTrace::Exit() ;
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
// fun3: begin
// fun3: end
// Exit From [fun3]
// fun2: end
// Exit From [fun2]
// fun1: end
// Exit From [fun1]
// Exit From [main]
// Program finished