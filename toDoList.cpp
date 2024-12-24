#include <iostream>
#include <vector>
#include <string>

using namespace std;

class toDoList
{
private:
	vector <string> tasks;

public:
	void addTask(const string& task)
	{
		tasks.push_back(task);
		cout << "Task added: " << task endl;
	}
	void removeTask(int index)
	{
		if (index >= 0 && index < tasks.size())
		{
			cout << "Task removed: " << tasks[index] << endl;
			tasks.erase(tasks.begin() + index);
		}
		else
		{
			cout << "Invalid Index!" << endl;
		}
	}

	void displayTasks() const
	{
		if (tasks.empty())
		{
			cout << "No tasks to display." << endl;
		}
		else
		{
			cout << "To Do List:" << endl;
			for (size_t i = 0; i < tasks.size(); ++i)
			{
				cout << i + 1 << ". " << tasks[i] << endl;
			}
		}
	}

};

int main()
{
	toDoList todo;
	int choice;
	string task;
	int taskIndex;

	do
	{
		cout << "\nTo-Do List Menu:" << endl;
		cout << "1. Add Task" << endl;
		cout << "2. Remove Task" << endl;
		cout << "3. Display Tasks" << endl;
		cout << "4. EXIT" << endl;
		cout << "Enter your choice: ";
		cin << choice;

		switch (choice)
		{
		case 1:
			cout << "Enter the task: ";
			cin.ignore();
			getline(cin, task);
			todo.addTask(task);
			break;
		case 2:
			cout << "Enter the task nuber to remove: ";
			cin >> taskIndex;
			todo.removeTask(taskIndex - 1);
			break;
		case 3:
			todo.displayTasks();
			break;
		case 4:
			cout << "EXITING..." << endl;
			break;
		default:
			cout << "Invalid choice, please try again." << endl;
	
		}
	} 
	while (choice != 4);
	return 0;
}