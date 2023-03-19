#include "header.h"

using namespace std;

//***********GET DATA AND BUILD LINKED LISTS**********

//STAFF
void getData_A_Teacher(ifstream& input, STAFF& teacher)
{
	input >> teacher.No_Staff;
	input.seekg(1);
	getline(input, teacher.TeacherID, ',');
	getline(input, teacher.Password, ',');
	getline(input, teacher.LName, ',');
	getline(input, teacher.FName, ',');
	getline(input, teacher.Gender, ',');
	input >> teacher.DoB.day;
	input.seekg(1);
	input >> teacher.DoB.month;
	input.seekg(1);
	input >> teacher.DoB.year;
	input.seekg(1);
	getline(input, teacher.SocialID, ',');
	getline(input, teacher.Faculty, ',');
}

void getDataTeachers_csv(ifstream& input, STFF_NODE*& head)
{
	

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
		cin >> ws;
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

void print_Students(STU_NODE* head) {
        STU_NODE* cur = head;
	while (cur) {
		cout << cur->student.No_Student << " " << cur->student.StudentID << " " << cur->student.LName << " " << cur->student.FName << " " << cur->student.Gender << " " << cur->student.SocialID <<  " " << cur->student.Classes.ClassID << " " << cur->student.Classes.name << "\n";
		cur = cur->next;
	}
}
