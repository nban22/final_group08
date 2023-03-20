#include "header.h"

using namespace std;

//***********GET DATA AND BUILD LINKED LISTS**********

//STAFF
void getData_A_Teacher(ifstream& input, STFF_NODE*& head)
{
	input.open("teachers.csv");
	STAFF teacher;

	getline(input, teacher.TeacherID, ',');
	getline(input, teacher.TeacherID, ',');
	getline(input, teacher.TeacherID, ',');
	getline(input, teacher.TeacherID, ',');
	getline(input, teacher.TeacherID, ',');
	getline(input, teacher.TeacherID, ',');
	getline(input, teacher.TeacherID, ',');
	getline(input, teacher.TeacherID, ',');
	getline(input, teacher.TeacherID);
	

	while (!input.eof())
	{
		
		string tmp;
		getline(input, tmp, ',');
		teacher.No_Staff = stoi(tmp);
		getline(input, teacher.TeacherID, ',');
		getline(input, teacher.Password, ',');
		getline(input, teacher.LName, ',');
		getline(input, teacher.FName, ',');
		getline(input, teacher.Gender, ',');
		getline(input, tmp, '/');
		teacher.DoB.day = stoi(tmp);
		getline(input, tmp, '/');
		teacher.DoB.month = stoi(tmp);
		getline(input, tmp, ',');
		teacher.DoB.year = stoi(tmp);
		getline(input, teacher.SocialID, ',');
		getline(input, teacher.Faculty);

		getDataTeachers_csv(teacher, head);
	}
	input.close();
};

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

void print_Staffs(STFF_NODE* head) {
        STFF_NODE* cur = head;
	while (cur) {
		cout << cur->staff.No_Staff << " " << cur->staff.TeacherID << " " << cur->staff.LName << " " << cur->staff.FName << " " << cur->staff.Gender << " " << cur->staff.SocialID <<  " " << cur->staff.Faculty << "\n";
		cur = cur->next;
	}
} //for testing

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
 //for testing