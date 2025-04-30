#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

class TodoList {
private:
    std::string filename;

    std::vector<std::pair<std::string, bool> > loadTasks() {
        std::ifstream file(filename);
        std::vector<std::pair<std::string, bool> > tasks;
        std::string line;
        
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string task;
            bool done;
            
            std::getline(ss, task, '|');
            ss >> done;
            
            tasks.push_back({task, done});
        }

        return tasks;
    }

    void saveTasks(const std::vector<std::pair<std::string, bool> >& tasks) {
        std::ofstream file(filename, std::ios::trunc);
        for (const auto& task : tasks) {
            file << task.first << " | " << task.second << "\n";
        }
    }

public:
    TodoList(const std::string& filename = "tasks.txt") : filename(filename) {}

    void addTask(const std::string& taskDescription) {
        std::ofstream file(filename, std::ios::app);
        file << taskDescription << " | 0\n";
    }

    void viewTasks() {
        std::vector<std::pair<std::string, bool> > tasks = loadTasks();
        if (tasks.empty()) {
            std::cout << "No tasks available!" << std::endl;
        } else {
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". " << tasks[i].first 
                          << " ["
                          << (tasks[i].second ? "Done" : "Not Done") 
                          << "]\n";
            }
        }
    }

    void markTaskAsDone(int taskIndex) {
        std::vector<std::pair<std::string, bool> > tasks = loadTasks();
        if (taskIndex > 0 && taskIndex <= tasks.size()) {
            tasks[taskIndex - 1].second = true;
            saveTasks(tasks);
            std::cout << "Task marked as done!" << std::endl;
        } else {
            std::cout << "Invalid task index!" << std::endl;
        }
    }
};

int main() {
    TodoList todo;
    int choice;
    
    do {
        std::cout << "\nTo-Do List Menu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Done\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();
        
        if (choice == 1) {
            std::string task;
            std::cout << "Enter task description: ";
            std::getline(std::cin, task);
            todo.addTask(task);
            std::cout << "Task added!\n";
        }
        else if (choice == 2) {
            todo.viewTasks();
        }
        else if (choice == 3) {
            int taskIndex;
            std::cout << "Enter task number to mark as done: ";
            std::cin >> taskIndex;
            todo.markTaskAsDone(taskIndex);
        }
        else if (choice != 4) {
            std::cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}

