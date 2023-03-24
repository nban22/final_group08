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
void getDataCourse_csv(std::ifstream& input, CR_NODE*& head){
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

void EnterCourseScore(std::string student_ID, STU_COURSE_NODE* SC, CR_NODE* C) {

	STU_COURSE_NODE* cur1 = SC;
	CR_NODE* cur2 = C;

	while (cur1 && cur2) {
		if (cur2->course.ID == cur1->stu_course.CouID && student_ID == cur1->stu_course.StuID) {
			cout << "\t\tEnter Score for student:" << endl;
			cout << cur1->stu_course.Lname << endl;
			cout << "Final mark: ";
			cin >> cur1->stu_course.final;
			cout << "Midterm mark: ";
			cin >> cur1->stu_course.midterm;
			cout << "Other mark: ";
			cin >> cur1->stu_course.other;
			cur1->stu_course.total = (cur1->stu_course.other + cur1->stu_course.midterm + 2 * cur1->stu_course.final) / 4;
			system("cls");
		}
			cur1 = cur1->next;
	}
}

// viet danh sach sinh vien da dang ky khoa hoc, (mac dinh moi sinh vien 1 mon hoc) random cac mon hoc cho sinh  vien.
void WriteRegisterStuDefault(CR_NODE* C, STU_NODE* S, STU_COURSE_NODE*& SC) {
	STU_COURSE_NODE* cur_stu_node = SC;
	STU_NODE* cur_stu = S;
	CR_NODE* cur_cr = C;

	while (cur_stu && cur_cr) {
		if (SC == nullptr) {
			SC = new STU_COURSE_NODE;
			SC->stu_course.No = cur_stu->student.No_Student;
			SC->stu_course.StuID = cur_stu->student.StudentID;
			SC->stu_course.Fname = cur_stu->student.FName;
			SC->stu_course.Lname = cur_stu->student.LName;
			SC->stu_course.Gen = cur_stu->student.Gender;
			SC->stu_course.Class = cur_stu->student.Classes.name;

			SC->stu_course.CouID = cur_cr->course.ID;
			SC->stu_course.Max_stdn = cur_cr->course.Max_stdn;
			SC->stu_course.Cname = cur_cr->course.CName;
			SC->stu_course.credits = cur_cr->course.Credits;
			SC->stu_course.Tname = cur_cr->course.teacherName;
			SC->stu_course.day1 = cur_cr->course.dayOfWeek;
			SC->stu_course.session1 = cur_cr->course.session;
			SC->stu_course.startdate = cur_cr->course.startDate;
			SC->stu_course.enddate = cur_cr->course.endDate;
			SC->stu_course.other = rand() % 11;
			SC->stu_course.midterm = rand() % 11;
			SC->stu_course.final = rand() % 11;
			SC->stu_course.total = (SC->stu_course.other + SC->stu_course.midterm + 2 * SC->stu_course.final) / 4;
			cur_stu_node = SC;
		}
		else {
			STU_COURSE_NODE* tmp = new STU_COURSE_NODE;
			cur_stu_node->next = tmp;
			tmp->prev = cur_stu_node;
			tmp->next = nullptr;
			tmp->stu_course.No = cur_stu->student.No_Student;
			tmp->stu_course.StuID = cur_stu->student.StudentID;
			tmp->stu_course.Fname = cur_stu->student.FName;
			tmp->stu_course.Lname = cur_stu->student.LName;
			tmp->stu_course.Gen = cur_stu->student.Gender;
			tmp->stu_course.Class = cur_stu->student.Classes.name;

			tmp->stu_course.CouID = cur_cr->course.ID;
			tmp->stu_course.Cname = cur_cr->course.CName;
			tmp->stu_course.Max_stdn = cur_cr->course.Max_stdn;
			tmp->stu_course.credits = cur_cr->course.Credits;
			tmp->stu_course.Tname = cur_cr->course.teacherName;
			tmp->stu_course.day1 = cur_cr->course.dayOfWeek;
			tmp->stu_course.session1 = cur_cr->course.session;
			tmp->stu_course.startdate = cur_cr->course.startDate;
			tmp->stu_course.enddate = cur_cr->course.endDate;
			tmp->stu_course.other = rand() % 11;
			tmp->stu_course.midterm = rand() % 11;
			tmp->stu_course.final = rand() % 11;
			tmp->stu_course.total = (SC->stu_course.other + SC->stu_course.midterm + 2 * SC->stu_course.final) / 4;
			cur_stu_node = cur_stu_node->next;
		}
	}
	cur_cr = cur_cr->next;
	cur_stu = cur_stu->next;
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


bool Read_After_Update_Course(STU_COURSE_NODE*& head) {
	ofstream outfile;
	outfile.open("Test2.csv");
	if (!outfile.is_open()) {
		return 0;
	}
	outfile << "ID,CName,teacherName,Credits,Max_stdn,Weekday,Session,Start date,End date" << endl;
	for (STU_COURSE_NODE* h = head; h != nullptr; h = h->next) {
		outfile << h->stu_course.CouID << "," << h->stu_course.Cname << "," << h->stu_course.Tname << "," << h->stu_course.credits << ","
			<< h->stu_course.Max_stdn << "," << h->stu_course.day1 << ","
			<< h->stu_course.session1 << "," << h->stu_course.startdate.day << "/" << h->stu_course.startdate.month << "/" << h->stu_course.startdate.year << ","
			<< h->stu_course.enddate.day << "/" << h->stu_course.enddate.month << "/" << h->stu_course.enddate.year;
		if (h->next != nullptr)
			outfile << "\n";
	}
	outfile.close();
	return 1;
}

