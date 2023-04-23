#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include "InputValidation.h"

using namespace std;
using namespace filesystem;

void OutputData() {
	string filePath = "";
	bool isDataSaved = false;
	do {
		cout << "Сохранить в:" << endl;
		getline(cin, filePath);

		if (ifstream(filePath)) {
			cout << "Файл уже существует." << endl;
			cout << "[0] - Перезаписать существующий файл." << endl;
			cout << "[1] - Повторить ввод." << endl;
			int tryAnotherFile = GetBool();
			if (tryAnotherFile) {
				continue;
			}
		}

		ofstream myFile(filePath, ofstream::app);
		
		error_code ec{};
		if (!is_regular_file(filePath, ec)) {
      cout << "Адрес содержит недопустимые значения. Повторите ввод." << endl;
 			continue;
		}

		if (!myFile) {
			cout << "Запись запрещена. Повторите ввод." << endl;
			myFile.close();
			continue;
		}

		myFile.close();
		myFile.open(filePath, ofstream::trunc);
		int myValue = 5;
		myFile << myValue;
		myFile.close();
		cout << "Запись завершена." << endl;
		isDataSaved = true;
	} while (!isDataSaved);
}

int* InputData(int& myArraySize) {
	string filePath = "";
	bool isDataLoaded = false;
	myArraySize = 0;
	int *myArray = nullptr;
	do {
		cout << "Загрузить из:" << endl;
		getline(cin, filePath);

		if (!ifstream(filePath)) {
			cout << "Файл не существует. Повторите ввод." << endl;
			continue;
		}

		error_code ec;
		if (!is_regular_file(filePath, ec)) {
			cout << "Адрес содержит недопустимые значения. Повторите ввод." << endl;
			continue;
		}

		ifstream myFile(filePath);

		if (!myFile) {
			cout << "Загрузка запрещена. Повторите ввод." << endl;
			myFile.close();
			continue;
		}

		if (!(myFile >> myArraySize) || myArraySize <= 0) {
			cout << "Некорректный размер массива." << endl;
			myFile.close();
			continue;
		}

		myArray = new int[myArraySize];

		int i = 0;
		for (; i < myArraySize; i++) {
			if (!(myFile >> myArray[i])) {
				cout << "Некорректные данные." << endl;
				myFile.close();
				break;
			}
		}

		if (i == myArraySize) {
			cout << "Загрузка завершена." << endl;
			isDataLoaded = true;
		}
		else {
			delete[] myArray;
			myArray = nullptr;
		}

		myFile.close();
	} while (!isDataLoaded);
	return myArray;
}