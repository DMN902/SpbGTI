#include "ClassWork.h"

int Parent::counter = 0;

void OutputData(const vector<shared_ptr<Parent>>& children) {
  for (const auto& element : children) {
    element->Print();

    if (const auto& child = dynamic_pointer_cast<Child>(element)) {
      child->Hello();
    }
  }
}

bool IsObjectDeleted(vector<shared_ptr<Parent>>& children, int id) {
  int low = 0, high = static_cast<int>(children.size() - 1);

  while (low <= high) {
    int middle = low + (high - low) / 2;
    if (children[middle]->GetID() == id) {
      children.erase(children.begin() + middle);
      return true;
    }
    if (children[middle]->GetID() < id) {
      low = middle + 1;
    }
    else {
      high = middle - 1;
    }
  }
  return false;
}
