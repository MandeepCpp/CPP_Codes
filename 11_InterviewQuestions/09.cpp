#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <future>

// LogEntry class to represent each log entry
class LogEntry {
public:
    std::string date;
    int processId;
    std::string processName;
    std::string fileName;
    std::string message;

    LogEntry(const std::string& d, int pid, const std::string& pname, const std::string& fname, const std::string& msg)
        : date(d), processId(pid), processName(pname), fileName(fname), message(msg) {}
};

// LogManager class to handle storing and querying log entries
class LogManager {
private:
    std::unordered_map<int, std::vector<LogEntry>> logData;
    std::mutex mtx;

public:
    void addLogEntry(const LogEntry& entry) {
        std::lock_guard<std::mutex> lock(mtx);
        logData[entry.processId].push_back(entry);
    }

    void queryByProcessId(int processId) {
        std::lock_guard<std::mutex> lock(mtx);
        auto it = logData.find(processId);
        if (it != logData.end()) {
            std::cout << "Process name : " << it->second[0].processName << std::endl;
            for (const auto& entry : it->second) {
                std::cout << "FileName:" << entry.fileName
                          << ", Message: " << entry.message << std::endl;
            }
        } else {
            std::cout << "No logs found for process ID " << processId << std::endl;
        }
    }

    void parseFile(const std::string& filename, bool multiThreaded) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        if (multiThreaded) {
            // Multi-threaded parsing
            std::vector<std::future<void>> futures;
            std::streampos fileSize = file.tellg();
            file.seekg(0, std::ios::end);
            fileSize = file.tellg();
            file.seekg(0, std::ios::beg);

            std::streampos half = fileSize / 2;

            auto parseChunk = [this, &file](std::streampos start, std::streampos end) {
                file.seekg(start);
                std::string line;
                while (file.tellg() < end && std::getline(file, line)) {
                    parseLine(line);
                }
            };

            futures.push_back(std::async(std::launch::async, parseChunk, 0, half));
            futures.push_back(std::async(std::launch::async, parseChunk, half, fileSize));

            for (auto& fut : futures) {
                fut.get();
            }
        } else {
            // Single-threaded parsing
            std::string line;
            while (std::getline(file, line)) {
                parseLine(line);
            }
        }
    }

private:
    void parseLine(const std::string& line) {
        std::istringstream iss(line);
        std::string date, processName, fileName, message;
        int processId;

        // Read in the format: Date [process id] [process name] [filename] log message
        iss >> date;
        iss.ignore(1); // Skip '['
        iss >> processId;
        iss.ignore(1); // Skip ']'
        iss >> processName;
        iss >> fileName;
        std::getline(iss, message);

        LogEntry entry(date, processId, processName, fileName, message);
        addLogEntry(entry);
    }
};

// Main function
int main() {
    LogManager logManager;

    std::string filename = "logfile.txt";
    bool multiThreaded = true; // Set to false for single-threaded

    logManager.parseFile(filename, multiThreaded);

    int processId;
    std::cout << "Enter the process ID: ";
    //std::cin >> processId;

    logManager.queryByProcessId(1);

    return 0;
}