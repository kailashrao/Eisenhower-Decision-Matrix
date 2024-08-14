// Kailash Rao 8/13/2024
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Task {
  string title;
  string description;
  string dueDate;
  int quadrant;
public:
  Task() {
    cin.ignore(10, '\n');
    cout << "Task Name: ";
    getline(cin, title);

    cout << "Task Description: ";
    getline(cin, description);

    cout << "Task Due Date (mm/dd/yyyy): ";
    cin >> dueDate;

    cout << "Task Quadrant: ";
    cin >> quadrant;
  }
 /* Task(string title, string desc, string due, int quad) : title(title), description(desc), dueDate(due), quadrant(quad) {}
  Task(string title, int quad) : title(title), quadrant(quad) {
    description = "";
    dueDate = "";
  }*/
  string getTitle() const { return title; }
  string getDesc() const { return description; }
  string getDueDate() const { return dueDate; }
  int getQuad() const { return quadrant; }

  friend ostream& operator<<(ostream&, const Task* const);

};

ostream& operator<<(ostream&, const Task* const);

int main(){
  vector<Task> tasks;
  char option;
  bool cont = true;
  while (cont) {
    cout << "*-------------------------------------------------------------*\n";
    cout << "| Add Task (a) | Delete Task (d) | Print Tasks (p) | Quit (q) |\n";
    cout << "*-------------------------------------------------------------*\n>> ";
    cin >> option;

    if (option == 'a') { tasks.push_back(Task()); }

    else if (option == 'd') {
      string delTask;

      cin.ignore(10, '\n');
      cout << "Enter the name of the task to delete\n>> ";
      getline(cin, delTask);

      int count = 0;
      for (auto task : tasks) {
        if (delTask == task.getTitle()) { tasks.erase(tasks.begin()+count); }
        else { cout << "Task not found." << endl; }
      }
    }

    else if (option == 'p') { for (auto task : tasks) { cout << &task; } }

    else if (option == 'q') { cont = false; }
    else { cout << "Invalid option. Try again.\n"; }
  }
}

ostream& operator<<(ostream& out, const Task* const pTask) {
  out << "Task: " << pTask->title << endl;
  out << "Description: " << pTask->description << endl;
  out << "Due Date: " << pTask->dueDate << endl;
  out << "Quadrant: " << pTask->quadrant << endl;
  return out;
}