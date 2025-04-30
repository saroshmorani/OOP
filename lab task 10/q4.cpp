#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <sys/stat.h>
#include <sstream>

std::string to_string(int value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

class RotatingLogger {
private:
    std::string logFile;
    std::size_t maxSize;

    std::size_t getFileSize(const std::string& filename) {
        struct stat fileStat;
        if (stat(filename.c_str(), &fileStat) == 0) {
            return fileStat.st_size;
        }
        return 0;
    }

    bool fileExists(const std::string& filename) {
        std::ifstream file(filename.c_str());
        return file.good();
    }

    void rotateLogs() {
        int i = 1;
        std::string newName;
        do {
            newName = "log" + to_string(i) + ".txt";
            ++i;
        } while (fileExists(newName));

        if (std::rename(logFile.c_str(), newName.c_str()) != 0) {
            std::cerr << "Error renaming file " << logFile << " to " << newName << std::endl;
        }
    }

public:
    RotatingLogger(const std::string& filename = "log.txt", std::size_t maxSizeBytes = 1048576)
        : logFile(filename), maxSize(maxSizeBytes) {}

    void log(const std::string& message) {
        if (fileExists(logFile) && getFileSize(logFile) >= maxSize) {
            rotateLogs();
        }

        std::ofstream outFile(logFile.c_str(), std::ios::app);
        if (!outFile) {
            std::cerr << "Failed to open log file " << logFile << " for writing.\n";
        } else {
            outFile << message << '\n';
        }
    }
};

int main() {
    RotatingLogger logger;

    for (int i = 0; i < 100000; ++i) {
        logger.log("Log entry number: " + to_string(i));
    }

    return 0;
}

