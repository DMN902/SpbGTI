#include "InputValidation.h"
#include "ClassWork.h"

void ShowInheritanceMenu() {
  cout << "Работа с наследованием." << endl;
  cout << "Выберите пункт меню:" << endl;
  cout << "[1] - Добавить объект производного класса" << endl;
  cout << "[2] - Удалить объект производного класса" << endl;
  cout << "[3] - Получить список объектов в контейнере" << endl;
  cout << "[4] - Выйти" << endl;
  cout << "Ваш выбор: ";
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
      cout << "Объект #" << children.back()->GetID() << " добавлен." << endl << endl;
      break;
    }
    case DELETE: {
      if (!children.empty()) {
        OutputData(children);
        cout << "Введите номер объекта для удаления: #";
        int id = GetInt();
        if (IsObjectDeleted(children, id)) {
          cout << "Объект #" << id << " удален." << endl << endl;
        }
        else {
          cout << "Объект #" << id << " не найден." << endl << endl;
        }
      }
      else {
        cout << "Контейнер пуст." << endl << endl;
      }
      break;
    }
    case SHOW:
      if (!children.empty()) {
        OutputData(children);
      }
      else {
        cout << "Контейнер пуст." << endl << endl;
      }
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