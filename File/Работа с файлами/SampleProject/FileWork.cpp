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
		cout << "��������� �:" << endl;
		getline(cin, filePath);

		if (ifstream(filePath)) {
			cout << "���� ��� ����������." << endl;
			cout << "[0] - ������������ ������������ ����." << endl;
			cout << "[1] - ��������� ����." << endl;
			int tryAnotherFile = GetBool();
			if (tryAnotherFile) {
				continue;
			}
		}

		ofstream myFile(filePath, ofstream::app);
		
		error_code ec{};
		if (!is_regular_file(filePath, ec)) {
      cout << "����� �������� ������������ ��������. ��������� ����." << endl;
 			continue;
		}

		if (!myFile) {
			cout << "������ ���������. ��������� ����." << endl;
			myFile.close();
			continue;
		}

		myFile.close();
		myFile.open(filePath, ofstream::trunc);
		int myValue = 5;
		myFile << myValue;
		myFile.close();
		cout << "������ ���������." << endl;
		isDataSaved = true;
	} while (!isDataSaved);
}

int* InputData(int& myArraySize) {
	string filePath = "";
	bool isDataLoaded = false;
	myArraySize = 0;
	int *myArray = nullptr;
	do {
		cout << "��������� ��:" << endl;
		getline(cin, filePath);

		if (!ifstream(filePath)) {
			cout << "���� �� ����������. ��������� ����." << endl;
			continue;
		}

		error_code ec;
		if (!is_regular_file(filePath, ec)) {
			cout << "����� �������� ������������ ��������. ��������� ����." << endl;
			continue;
		}

		ifstream myFile(filePath);

		if (!myFile) {
			cout << "�������� ���������. ��������� ����." << endl;
			myFile.close();
			continue;
		}

		if (!(myFile >> myArraySize) || myArraySize <= 0) {
			cout << "������������ ������ �������." << endl;
			myFile.close();
			continue;
		}

		myArray = new int[myArraySize];

		int i = 0;
		for (; i < myArraySize; i++) {
			if (!(myFile >> myArray[i])) {
				cout << "������������ ������." << endl;
				myFile.close();
				break;
			}
		}

		if (i == myArraySize) {
			cout << "�������� ���������." << endl;
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