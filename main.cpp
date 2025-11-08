#include <windows.h>   // Required for Windows API (SetConsoleCtrlHandler, Sleep, etc.)
#include <iostream>    
#include <atomic>      // For thread-safe flag (std::atomic_bool)

// Global atomic flag to indicate when Ctrl+C was pressed
// std::atomic_bool g_quit{false};

// ---------------------------------------------------------------------------
// CtrlHandler: This function is called automatically by the system
// whenever the user presses Ctrl+C (or other console events like Ctrl+Break).
// ---------------------------------------------------------------------------
BOOL WINAPI CtrlHandler(DWORD fdwCtrlType) {
    // Check which control event occurred
    if (fdwCtrlType == CTRL_C_EVENT) {
        // Print message to notify the user
        std::cout << "\nCtrl+C caught. Setting quit flag.\n";
        
        // Set the atomic flag to true, telling the main loop to exit
        // g_quit = true;

        TerminateProcess(GetCurrentProcess(), 0);


        // Return TRUE to tell Windows we handled this event
        return TRUE;
    }

    // Return FALSE for other types of console events (we don't handle them)
    return FALSE;
}

// ---------------------------------------------------------------------------
// main function
// ---------------------------------------------------------------------------
int main() {
    // Register our CtrlHandler function with the system
    // TRUE means "add this handler"; FALSE would remove it
    if (!SetConsoleCtrlHandler(CtrlHandler, TRUE)) {
        // If registration fails, print an error message
        std::cerr << "Failed to install handler\n";
        return 1;
    }

    // Inform the user that the program is running
    std::cout << "Running. Press Ctrl+C to quit.\n";

    // Main loop — runs until user presses Ctrl+C
    while (1) {
  
    }

    // When the flag becomes true, exit the loop and print message
    std::cout << "Exiting cleanly.\n";
    return 0;
}
