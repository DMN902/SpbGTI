#include "InputValidation.h"
#include "ClassWork.h"

void ShowInheritanceMenu() {
  cout << "������ � �������������." << endl;
  cout << "�������� ����� ����:" << endl;
  cout << "[1] - �������� ������ ������������ ������" << endl;
  cout << "[2] - ������� ������ ������������ ������" << endl;
  cout << "[3] - �������� ������ �������� � ����������" << endl;
  cout << "[4] - �����" << endl;
  cout << "��� �����: ";
}

void StartProgram() {
  menuItem userChoice = static_cast<menuItem>(0);
  vector<shared_ptr<Parent>> children;

  do {
    ShowInheritanceMenu();
    userChoice = GetMenuItem();
    switch (userChoice) {
    case ADD: {
      children.push_back(make_shared<Child>());
      cout << "������ #" << children.back()->GetID() << " ��������." << endl << endl;
      break;
    }
    case DELETE: {
      if (!children.empty()) {
        OutputData(children);
        cout << "������� ����� ������� ��� ��������: #";
        int id = GetInt();
        if (IsObjectDeleted(children, id)) {
          cout << "������ #" << id << " ������." << endl << endl;
        }
        else {
          cout << "������ #" << id << " �� ������." << endl << endl;
        }
      }
      else {
        cout << "��������� ����." << endl << endl;
      }
      break;
    }
    case SHOW:
      if (!children.empty()) {
        OutputData(children);
      }
      else {
        cout << "��������� ����." << endl << endl;
      }
      break;
    case QUIT:
      cout << "���������� ������." << endl;
      break;
    default:
      cout << "��������� ����." << endl;
      cout << endl;
      break;
    }
  } while (userChoice != QUIT);
}