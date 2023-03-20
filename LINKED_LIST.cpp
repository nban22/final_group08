#include "header.h"

using namespace std;

//***********GET DATA AND BUILD LINKED LISTS**********

//STAFF
void getData_A_Teacher(ifstream& input, STFF_NODE*& head) {
    input.open("teachers.csv");

	STAFF teacher; 
    while (!input.eof()) {
		cin >> teacher.No_Staff;
        getline(input, teacher.TeacherID, ',');
		cin >> ws;
		getline(input, teacher.Password, ',');
		cin >> ws;
		getline(input, teacher.LName, ',');
		cin >> ws;
		getline(input, teacher.FName, ',');
		cin >> ws;
		getline(input, teacher.Gender, ',');
		cin >> ws;
		cin >> teacher.DoB.day >> teacher.DoB.month >> teacher.DoB.year;
		getline(input, teacher.SocialID, ',');
		cin >> ws;
		getline(input, teacher.Faculty, ',');
		getDataTeachers_csv(teacher, head);
    }

    input.close();
}

void getDataTeachers_csv(STAFF staff, STFF_NODE*& head) {
    STFF_NODE* tmp = new STFF_NODE;
    tmp->staff = staff;
    tmp->next = nullptr;

    if (!head) {
        head = tmp;
		head->prev = nullptr;
    } else {
        STFF_NODE* cur = head;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = tmp;
		tmp->prev = cur;
    }

} 

//STUDENT
void getData_A_Student(ifstream& input, STU_NODE*& head) {
    input.open("students.csv");

	STUDENT student; 
    while (!input.eof()) {
		cin >> student.No_Student;
        getline(input, student.StudentID, ',');
		cin >> ws;
		getline(input, student.Password, ',');
		cin >> ws;
		getline(input, student.LName, ',');
		cin >> ws;
		getline(input, student.FName, ',');
		cin >> ws;
		getline(input, student.Gender, ',');
		cin >> ws;
		cin >> student.DoB.day >> student.DoB.month >> student.DoB.year;
		getline(input, student.SocialID, ',');
		cin >> ws;
		getline(input, student.Classes.name, ',');
		cin >> ws;
		getline(input, student.Classes.ClassID, ',');
		getDataStudents_csv(student, head);
    }

    input.close();
}

void getDataStudents_csv(STUDENT student, STU_NODE*& head) {
    STU_NODE* tmp = new STU_NODE;
    tmp->student = student;
    tmp->next = nullptr;

    if (!head) {
        head = tmp;
		head->prev = nullptr;
    } else {
        STU_NODE* cur = head;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = tmp;
		tmp->prev = cur;
    }
}
