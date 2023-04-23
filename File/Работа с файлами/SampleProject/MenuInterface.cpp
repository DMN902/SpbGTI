#include <iostream>
#include "InputValidation.h"
#include "FileWork.h"

using namespace std;

void ShowFileMenu() {
	cout << "������ � �������." << endl;
	cout << "�������� ����� ����:" << endl;
	cout << "[1] - ���������" << endl;
	cout << "[2] - ���������" << endl;
	cout << "[3] - �����" << endl;
	cout << "��� �����: ";
}

void StartProgram() {
  menuItem userChoice = static_cast<menuItem>(0);

  do {
    ShowFileMenu();
    userChoice = GetMenuItem();
    switch (userChoice) {
    case LOAD: {
      int myArraySize = 0;
      int *myArray = nullptr;
      myArray = InputData(myArraySize);
      for (int i = 0; i < myArraySize; i++) {
        cout << myArray[i] << endl;
      }
      delete[] myArray;
      myArray = nullptr;
      cout << endl;
      break;
    }
    case SAVE:
      OutputData();
      cout << endl;
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