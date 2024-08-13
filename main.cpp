#include <iostream>
#include <string>
using namespace std;

class Task {
  string title;
  string description;
  string dueDate;
  int quadrant;
public:
  Task(string title, string desc, string due, int quad) : title(title), description(desc), dueDate(due), quadrant(quad) {}
  Task(string title, int quad) : title(title), quadrant(quad) {
    description = "";
    dueDate = "";
  }
  string getTitle() const { return title; }
  string getDesc() const { return description; }
  string getDueDate() const { return dueDate; }
  int getQuad() const { return quadrant; }
};

int main(){
  Task hw("homework", 2);
  cout << hw.getTitle();
}