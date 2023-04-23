#include <iostream>
#include "InputValidation.h"
#include "FileWork.h"

using namespace std;

void ShowFileMenu() {
	cout << "Работа с файлами." << endl;
	cout << "Выберите пункт меню:" << endl;
	cout << "[1] - Загрузить" << endl;
	cout << "[2] - Сохранить" << endl;
	cout << "[3] - Выйти" << endl;
	cout << "Ваш выбор: ";
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
      cout << "Завершение работы." << endl;
      break;
    default:
      cout << "Повторите ввод." << endl;
      cout << endl;
      break;
    }
  } while (userChoice != QUIT);
}