//#include <iostream>
//#include <string>
//
//using namespace std;
//
//struct students {
//    string surname;
//    string group;
//    int succes[5];
//};
//
//void classifyStudents(students* studentList, int size) {
//    cout << "Результати:" << endl;
//    for (int i = 0; i < size; ++i) {
//        int vidminnoCount = 0;
//        int poganoCount = 0;
//
//        for (int j = 0; j < 5; ++j) {
//            if (studentList[i].succes[j] >= 10) {
//                vidminnoCount++;
//            }
//            if (studentList[i].succes[j] <= 3) {
//                poganoCount++;
//            }
//        }
//
//        string result = (vidminnoCount > 3) ? (studentList[i].surname + " " + studentList[i].group + " - відмінник/відмінниця") :
//            (poganoCount > 2) ? (studentList[i].surname + " " + studentList[i].group + " - двієчник/двієчниця") : "";
//        cout << result << endl;
//    }
//}
//
//int main() {
//    system("chcp 1251>null");
//    int size = 6;
//    students* studentSpisok = new students[size]{
//        {"Котик", "g1", {12, 11, 10, 12, 11}},
//        {"Дудка", "g2", {2, 3, 4, 3, 2}},
//        {"Квас", "g3", {10, 12, 11, 10, 11}},
//        {"Борщ", "g4", {3, 2, 2, 3, 2}},
//        {"Білоус", "g5", {4, 2, 6, 3, 2}},
//        {"Відаль", "g6", {10, 10, 10, 12, 10}}
//    };
//
//    classifyStudents(studentSpisok, size);
//
//    delete[] studentSpisok;
//    return 0;
//}

#include <iostream>
#include <string>

using namespace std;

struct man {
    string surname;
    string name;
    short age;
    string birthday;
};

void surname(man* people, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (people[j].surname > people[j + 1].surname) {
                swap(people[j], people[j + 1]);
            }
        }
    }
}

void name(man* people, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (people[j].name > people[j + 1].name) {
                swap(people[j], people[j + 1]);
            }
        }
    }
}

void birthday(man* people, int size, int month) {
    cout << "іменинники місяця: " << month << endl;
    for (int i = 0; i < size; ++i) {
        if (stoi(people[i].birthday.substr(3, 2)) == month) {
            cout << people[i].name << " " << people[i].surname << " - " << people[i].birthday << endl;
        }
    }
}

man* add_person(man* people, int& size, const man& new_man) {
    man* new_people = new man[size + 1];
    for (int i = 0; i < size; ++i) {
        new_people[i] = people[i];
    }
    new_people[size] = new_man;
    delete[] people;
    size++;
    return new_people;
}

man* remove_person(man* people, int& size, const string& surname) {
    man* new_people = new man[size - 1];
    int newSize = 0;
    for (int i = 0; i < size; ++i) {
        if (people[i].surname != surname) {
            new_people[newSize++] = people[i];
        }
    }
    delete[] people;
    size = newSize;
    return new_people;
}

void edit_person(man* people, int size, const string& surname) {
    for (int i = 0; i < size; ++i) {
        if (people[i].surname == surname) {
            cout << "введіть нові дані:" << endl;
            cout << "нове прізвище: "; cin >> people[i].surname; 
            cout << "ім'я: "; cin >> people[i].name;
            cout << "вік: "; cin >> people[i].age;
            cout << "дата народження (ДД.ММ.РРРР): "; cin >> people[i].birthday;
            cout << "запис відредаговано" << endl;
            break;
        }
    }
}

void show_people(man* people, int size) {
    for (int i = 0; i < size; ++i) {
        cout << people[i].surname << " " << people[i].name << " " << people[i].age << " " << people[i].birthday << endl;
    }
}

int main() {
    system("chcp 1251>null");
    int size = 0;
    man* people = nullptr;

    while (true) {
        cout << "\nменю:\n";
        cout << "1. додати людину\n";
        cout << "2. вивести список людей\n";
        cout << "3. сортувати за прізвищем\n";
        cout << "4. сортувати за ім'ям\n";
        cout << "5. вивести іменинників місяця\n";
        cout << "6. редагувати запис\n"; // Fixed the spelling here
        cout << "7. видалити людину\n";
        cout << "0. вихід\n";
        cout << "оберіть дію: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            man new_man;
            cout << "введіть прізвище: "; cin >> new_man.surname;
            cout << "введіть ім'я: "; cin >> new_man.name;
            cout << "введіть вік: "; cin >> new_man.age;
            cout << "введіть дату народження (ДД.ММ.РРРР): "; cin >> new_man.birthday;
            people = add_person(people, size, new_man);
            cout << "людину додано" << endl;
        }
        else if (choice == 2) {
            cout << "список людей:" << endl;
            show_people(people, size);
        }
        else if (choice == 3) {
            surname(people, size);
            cout << "список людей (сортовано за прізвищем):" << endl;
            show_people(people, size);
        }
        else if (choice == 4) {
            name(people, size);
            cout << "список людей (сортовано за ім'ям):" << endl;
            show_people(people, size);
        }
        else if (choice == 5) {
            int month;
            cout << "введіть місяць (1-12): "; cin >> month;
            birthday(people, size, month);
        }
        else if (choice == 6) {
            string surname;
            cout << "введіть прізвище для редагування: "; cin >> surname;
            edit_person(people, size, surname);
        }
        else if (choice == 7) {
            string surname;
            cout << "введіть прізвище для видалення: "; cin >> surname;
            people = remove_person(people, size, surname);
            cout << "запис видалено" << endl;
        }
        else if (choice == 0) {
            break;
        }
        else {
            cout << "помилка" << endl;
        }
    }

    delete[] people;
    return 0;
}
