#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Logger {
private:
    vector<string> logs;
    const size_t MAX_LOGS = 1000;

    void storeLog(const string& msg) {
        if (logs.size() >= MAX_LOGS)
            logs.erase(logs.begin());
        logs.push_back(msg);
    }

public:
    void log(const string& severity, const string& module, const string& message) {
        string logMsg = "[" + severity + "] [" + module + "] " + message;
        storeLog(logMsg);
    }

    vector<string> getLogs(string password) const {
        if (password == "admin123") {
            return logs;
        } else {
            return vector<string>{ "Access Denied" };
        }
    }
};

int main() {
    Logger logger;
    logger.log("INFO", "Network", "Connected to server.");
    logger.log("ERROR", "Database", "Failed to connect.");
    logger.log("WARN", "Cache", "Using stale data.");

    auto logs = logger.getLogs("admin123"); 
    for (auto& log : logs)
        cout << log << endl;
}


