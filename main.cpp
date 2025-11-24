#include <iostream>
#include <string>
#include <vector>

//
// ========================= CLASS MyLOG =========================
//  A simple logger class supporting multiple log levels (INFO, WARN, ERROR).
//  All log messages are stored inside a shared static buffer (vector).
//
class MyLOG
{
public:
    // Log levels
    enum Level
    {
        INFO,
        WARN,
        ERROR
    };

    // Shared buffer for all log entries
    static std::vector<std::string> vec;

    // The log level for this object
    Level val;

    // Default constructor
    MyLOG() {}

    // Constructor that sets the log level
    MyLOG(Level l) : val(l) {}

    // Operator >> used to add messages to the log buffer
    void operator>>(const std::string &msg)
    {
        if (val == INFO)
            vec.push_back("[INFO] " + msg);
        else if (val == WARN)
            vec.push_back("[WARN] " + msg);
        else if (val == ERROR)
            vec.push_back("[ERROR] " + msg);
    }

    // Prints all stored log messages
    static void Dump()
    {
        std::cout << "======= LOG DUMP =======" << std::endl;

        for (const auto &m : vec)
            std::cout << m << std::endl;

        std::cout << "========================" << std::endl;
    }

    // Clears all log messages
    static void Clear()
    {
        vec.clear();
    }
};

// Static member definition
std::vector<std::string> MyLOG::vec;

//
// ========================= TEST SECTION =========================
//
int main()
{
    // Add some log entries using temporary objects
    MyLOG(MyLOG::INFO) >> "First entry.";
    MyLOG(MyLOG::WARN) >> "Second entry.";
    MyLOG(MyLOG::ERROR) >> "Third entry.";

    // Print the log contents
    MyLOG::Dump();

    // Clear all stored messages
    MyLOG::Clear();

    // Add a new message after clearing
    MyLOG(MyLOG::INFO) >> "Fourth entry after clear.";

    // Print the log again
    MyLOG::Dump();

    return 0;
}

// ======= LOG DUMP =======
// [INFO] First entry.
// [WARN] Second entry.
// [ERROR] Third entry.
// ========================
// ======= LOG DUMP =======
// [INFO] Fourth entry after clear.
// ========================