#include "header.h"

using namespace std;

//***********GET DATA AND BUILD LINKED LISTS**********

//STAFF
void getDataTeachers_csv(ifstream& input, STFF_NODE*& head)
{
	input.open("teachers.csv");
	STAFF teacher;

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

		getData_A_Teacher(teacher, head);
	}
	input.close();
};

void getData_A_Teacher(STAFF staff, STFF_NODE*& head) {
	STFF_NODE* tmp = new STFF_NODE;
	tmp->staff = staff;
	tmp->next = nullptr;

	if (!head) {
		head = tmp;
		head->prev = nullptr;
	}
	else {
		STFF_NODE* cur = head;
		while (cur->next) {
			cur = cur->next;
		}
		cur->next = tmp;
		tmp->prev = cur;
	}
}


//COURSE
void getDataCourse_csv(ifstream& input, CR_NODE *& head) {
	input.open("courses.csv"); //put this in main.cpp
	COURSE course;

	getline(input, course.ID);
	while (!input.eof())
	{
		string tmp;
		getline(input, course.ID, ',');
		getline(input, course.CName, ',');
		getline(input, course.teacherName, ',');
		input >> course.Credits;
		input >> course.Max_stdn;

		//GET ENUM VARIABLE:
		string weekday;
		getline(input, weekday, ',');
		WEEKDAY enumwd = ConvertEnumWD(weekday);
		course.dayOfWeek = enumwd;
		string session;
		getline(input, session, ',');
		SESSION enumss = ConvertEnumSS(session);
		course.session = enumss;

		getline(input, tmp, '/');
		course.startDate.day = stoi(tmp);
		getline(input, tmp, '/');
		course.startDate.month = stoi(tmp);
		getline(input, tmp, '/');
		course.startDate.year = stoi(tmp);
		getline(input, tmp, '/');

		course.endDate.day = stoi(tmp);
		getline(input, tmp, '/');
		course.endDate.month = stoi(tmp);
		getline(input, tmp, '/');
		course.endDate.year = stoi(tmp);

		getData_A_Course(course, head);
	}
	input.close();
	return;
}

void getData_A_Course(COURSE course, CR_NODE *& head) {
    CR_NODE* tmp = new CR_NODE;
    tmp->course = course;
    tmp->next = nullptr;

    if (!head) {
        head = tmp;
		head->prev = nullptr;
    } else {
        CR_NODE* cur = head;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = tmp;
		tmp->prev = cur;
    }
}

//STUDENT
void getDataStudents_csv(ifstream& input, STU_NODE*& head) {
	input.open("students.csv");

	STUDENT student;

	getline(input, student.StudentID);
	while (!input.eof()) {
		string tmp;
		getline(input, tmp, ',');
		student.No_Student = stoi(tmp);
		getline(input, student.StudentID, ',');
		getline(input, student.Password, ',');
		getline(input, student.LName, ',');
		getline(input, student.FName, ',');
		getline(input, student.Gender, ',');
		getline(input, tmp, '/');
		student.DoB.day = stoi(tmp);
		getline(input, tmp, '/');
		student.DoB.month = stoi(tmp);
		getline(input, tmp, ',');
		student.DoB.year = stoi(tmp);
		getline(input, student.SocialID, ',');
		getline(input, student.Classes.name, ',');
		getline(input, student.Classes.ClassID);
		getData_A_Student(student, head);
	}

	input.close();
}

void getData_A_Student(STUDENT student, STU_NODE*& head) {
	STU_NODE* tmp = new STU_NODE;
	tmp->student = student;
	tmp->next = nullptr;

	if (!head) {
		head = tmp;
		head->prev = nullptr;
	}
	else {
		STU_NODE* cur = head;
		while (cur->next) {
			cur = cur->next;
		}
		cur->next = tmp;
		tmp->prev = cur;
	}
}
// Doc lai file sau khi da cap nhat
bool Read_After_Update_Teachers(STFF_NODE*& head) {
	ofstream outfile;
	outfile.open("Test.csv");
	if (!outfile.is_open()) {
		return 0;
	}
	outfile << "No,Teacher ID,Password,Last Name,First Name,Gender,Date Of Birth,Social ID,Faculty" << endl;
	for (STFF_NODE* k = head; k != nullptr; k = k->next) {
		outfile << k->staff.No_Staff << "," << k->staff.TeacherID << "," << k->staff.Password << ","
			<< k->staff.LName << "," << k->staff.FName << "," << k->staff.Gender << ","
			<< k->staff.DoB.day / 10 << k->staff.DoB.day % 10 << "/" << k->staff.DoB.month / 10 << k->staff.DoB.month % 10 << "/" << k->staff.DoB.year << ","
			<< k->staff.SocialID << "," << k->staff.Faculty;
		if (k->next != nullptr)
			outfile << "\n";
	}
	outfile.close();
	return 1;
}
bool Read_After_Update_Students(STU_NODE*& head) {
	ofstream outfile;
	outfile.open("Test1.csv");
	if (!outfile.is_open()) {
		return 0;
	}
	outfile << "No.,Student ID,Password,Last Name,First Name,Gender,Date Of Birth,Social ID,Classes,Class ID" << endl;
	for (STU_NODE* h = head; h != nullptr; h = h->next) {
		outfile << h->student.No_Student << "," << h->student.StudentID << "," << h->student.Password << "," << h->student.LName << ","
			<< h->student.FName << "," << h->student.Gender << ","
			<< h->student.DoB.day / 10 << h->student.DoB.day % 10 << "/" << h->student.DoB.month / 10 << h->student.DoB.month % 10 << "/"
			<< h->student.DoB.year << "," << h->student.SocialID << "," << h->student.Classes.name << "," << h->student.Classes.ClassID;
		if (h->next != nullptr)
			outfile << "\n";
	}
	outfile.close();
	return 1;
}


