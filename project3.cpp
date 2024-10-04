#include <iostream>
#include <vector>
#include <string>

class TodoList {
private:
    std::vector<std::string> tasks;

public:
    // Add a task to the to-do list
    void addTask(const std::string& task) {
        tasks.push_back(task);
        std::cout << "Task added: " << task << std::endl;
    }

    // View all tasks in the to-do list
    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks in the to-do list." << std::endl;
            return;
        }

        std::cout << "To-Do List:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i] << std::endl;
        }
    }

    // Remove a task from the to-do list by index
    void removeTask(size_t index) {
        if (index > 0 && index <= tasks.size()) {
            std::cout << "Task removed: " << tasks[index - 1] << std::endl;
            tasks.erase(tasks.begin() + (index - 1));
        } else {
            std::cout << "Invalid task number." << std::endl;
        }
    }
};

int main() {
    TodoList todoList;
    int choice;
    std::string task;
    
    do {
        std::cout << "\nTo-Do List Menu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Remove Task\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter the task: ";
                std::cin.ignore(); // Clear the newline character from the buffer
                std::getline(std::cin, task);
                todoList.addTask(task);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                std::cout << "Enter the task number to remove: ";
                size_t taskNumber;
                std::cin >> taskNumber;
                todoList.removeTask(taskNumber);
                break;
            case 4:
                std::cout << "Exiting the application." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}