#pragma once
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Parent {
 public:
  virtual ~Parent() = default;
  Parent() {
    id = ++counter;
  }
  virtual void Print() = 0;
  int GetID() {
    return id;
  }
 protected:
  int id{};
 private:
  static int counter;
};

class Child : public Parent {
 public:
  void Print() override {
    cout << "Объект #" << id << endl;
  }
  void Hello() {
    cout << "Привет #" << id << endl << endl;
  }
};

void OutputData(const vector<shared_ptr<Parent>>& children);
bool IsObjectDeleted(vector<shared_ptr<Parent>>& children, int id);