#include <iostream>
#include "MenuItems.h"

using namespace std;

template<typename T>
T GetInput() {
  T userInput{};
  cin >> userInput;
  while (cin.fail()) {
    cout << "Повторите ввод." << endl;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cin >> userInput;
  }
  cin.ignore(INT_MAX, '\n');
  return userInput;
}

int GetInt() {
  return GetInput<int>();
}

menuItem GetMenuItem() {
  return static_cast<menuItem>(GetInt());
}