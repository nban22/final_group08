#include "header.h"

using namespace std;

//COURSE
void ViewCourses(CR_NODE *head) {
    system("cls");

    CR_NODE* cur = head;
    while (cur) {

    }
}

void CreateNewCourse(CR_NODE *&head) {
    CR_NODE* NewCourse = new CR_NODE;
}

void UpdateCourseInfo(CR_NODE *&head) {

}

void DeleteCourse() {

}

void Back() {

}

int DisplayMenu(int &choice) {
    system("cls");

    cout << "======================COURSE======================";
    cout << "\n\t1. View list of course.\n"
        << "\t2. Create a new course.\n"
        << "\t3. Update course's information.\n"
        << "\t4. Delete a course.\n"
        << "\t0. Back forward.\n"
        << "\t-1. Exit\n";
    cout << "========================END========================\n\n";

    cout << "Enter select the option you want to choice: ";
    cin >> choice;
    cin.ignore();
    return choice;
}

void getOption(int &choice, CR_NODE *head) {
    if (choice == 1) {
        ViewCourses(head);
    }
    else if (choice == 2) {
        CreateNewCourse(*&head);
    }
    else if (choice == 3) {
        UpdateCourseInfo(*&head); 
    }
    else if (choice == 4) {
        DeleteCourse();
    }
    else if (choice == 0) {
        Back();
    }
    else if (choice == -1) {
        system("pause");
        return;
    }
    else {
        cout << "Invalid selection, please enter again.\n\n";
        system("pause");
    }
}
 