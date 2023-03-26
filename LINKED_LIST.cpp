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
//Weekday
WEEKDAY ConvertEnumWD(std::string& str) {
	if (str.compare("MON") == 0) return MON;
	else if (str.compare("TUE") == 0) return TUE;
	else if (str.compare("WED") == 0) return WED;
	else if (str.compare("THU") == 0) return THU;
	else if (str.compare("FRI") == 0) return FRI;
	else return SAT;
}

//Session
SESSION ConvertEnumSS(std::string& str) {
	if (str.compare("S1") == 0) return S1;
	else if (str.compare("S2") == 0) return S2;
	else if (str.compare("S3") == 0) return S3;
	else return S4;
}

void getDataCourse_csv(ifstream& input, CR_NODE *& head) {
	input.open("courses.csv"); //put this in main.cpp
	COURSE course;

	getline(input, course.ID);
	while (!input.eof())
	{
		string tmp;
		getline(input, tmp, ',');
		course.No = stoi(tmp);
		getline(input, course.ID, ',');
		getline(input, course.CName, ',');
		getline(input, tmp, ',');
		getline(input, course.teacherName, ',');
		getline(input, course.teacherID, ',');
		getline(input, tmp, ',');
		course.Credits = stoi(tmp);
		getline(input, tmp, ',');
		course.Max_stdn = stoi(tmp);

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

void EnterCourseScore(STU_COURSE_NODE* &SC, CR_NODE* C, STFF_NODE* loggedinStaff, int &check) {

	STU_COURSE_NODE* cur1 = SC;
	CR_NODE* cur2 = C;
	int choice;
	int count = 0;
	std::string courseID = "0";

	cout << "choose a course" << endl;
	while (cur2) {
		if (cur2->course.teacherID == loggedinStaff->staff.TeacherID) {
			cout << cur2->course.No << "  " << cur2->course.ID << "  " << cur2->course.CName << endl;
			count++;
		}
		cur2 = cur2->next;
	}
	if (count == 0) {
		cout << "you have not attend any course" << endl;
		check = 0;
		return;
	}
	cout << "your choice: ";
	cin >> choice;
	while (cur1) {
		if (cur1->stu_course.No == choice) {
			courseID = cur1->stu_course.CouID;
			break;
		}
		else
			cur1 = cur1->next;
	}

	if (courseID == "0") {
		cout << "Invalid selection, please enter again.\n\n";
		check = 0;
		system("pause");
		return;
	}

	cur1 = SC;
	cout << "\n\n";

	while (cur1) {
		if (courseID == cur1->stu_course.Cname) {
			cout << "\t\tEnter Score for student:" << endl;
			cout << cur1->stu_course.StudentName << "  " << cur1->stu_course.StuID << "  " << endl;
			cout << "Midterm mark: ";
			cin >> cur1->stu_course.midterm;
			cout << "Final mark: ";
			cin >> cur1->stu_course.final;
			cout << "Other mark: ";
			cin >> cur1->stu_course.other;
			cur1->stu_course.total = (cur1->stu_course.other + cur1->stu_course.midterm + 2 * cur1->stu_course.final) / 4;
			system("cls");
		}
		cur1 = cur1->next;
	}
	check = 1;
}


void Get_Data_StudentCourse_csv(std::ifstream& input, STU_COURSE_NODE*& head) {
	input.open("student_course.csv"); //put this in main.cpp
	STU_COURSE studentcourse;

	getline(input, studentcourse.StuID);
	while (!input.eof())
	{
		string tmp;
		getline(input, tmp, ',');
		if (tmp == "") {
			break;
		}
		studentcourse.No = stoi(tmp);
		getline(input, studentcourse.StuID, ',');
		getline(input, studentcourse.StudentName, ',');
		getline(input, studentcourse.Gen, ',');
		getline(input, studentcourse.Class, ',');
		getline(input, studentcourse.CouID, ',');
		getline(input, studentcourse.Cname, ',');
		getline(input, tmp, ',');
		studentcourse.credits = stoi(tmp);
		getline(input, tmp, ',');
		studentcourse.Max_stdn = stoi(tmp);
		getline(input, studentcourse.Teachername, ',');
		getline(input, studentcourse.TeacherID, ',');
		getline(input, studentcourse.weekday, ',');
		getline(input, studentcourse.session, ',');
		getline(input, tmp, ',');
		studentcourse.startdate.day = stoi(tmp);
		getline(input, tmp, ',');
		studentcourse.startdate.month = stoi(tmp);
		getline(input, tmp, ',');
		studentcourse.enddate.day = stoi(tmp);
		getline(input, tmp, ',');
		studentcourse.enddate.month = stoi(tmp);
		getline(input, tmp, ',');
		studentcourse.midterm = stoi(tmp);
		getline(input, tmp, ',');
		studentcourse.final = stoi(tmp);
		getline(input, tmp, ',');
		studentcourse.other = stoi(tmp);
		getline(input, tmp);
		studentcourse.total = stoi(tmp);

		getData_A_StuCourse(studentcourse, head);
	}
	input.close();
	return;
}

void getData_A_StuCourse(STU_COURSE studentcourse, STU_COURSE_NODE*& head) {
	STU_COURSE_NODE* tmp = new STU_COURSE_NODE;
	tmp->stu_course = studentcourse;
	tmp->next = nullptr;

	if (!head) {
		head = tmp;
		head->prev = nullptr;
	}
	else {
		STU_COURSE_NODE* cur = head;
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

bool Read_After_Update_Courses(CR_NODE*& head) {
	ofstream outfile;
	outfile.open("coursetest.csv");
	if (!outfile.is_open()) {
		return 0;
	}
	outfile << "ID,Cname,teacherName,Credits,Max_stdn,Weekday,Session,Start date,End date" << endl;
	for (CR_NODE* c = head; c != nullptr; c = c->next) {
		outfile << c->course.ID << "," << c->course.CName << "," << c->course.teacherName << ","
			<< c->course.Credits << "," << c->course.Max_stdn << "," << c->course.dayOfWeek << ","
			<< c->course.session << "," 
			<< c->course.startDate.day / 10 << c->course.startDate.day % 10 << "/" << c->course.startDate.month / 10 << c->course.startDate.month % 10 << "/" << c->course.startDate.year << ","
			<< c->course.endDate.day / 10 << c->course.endDate.day % 10 << "/" << c->course.endDate.month / 10 << c->course.endDate.month % 10 << "/" << c->course.endDate.year;
		if (c->next != nullptr) {
			outfile << "\n";
		}
	}
	outfile.close();
	return 1;
}

bool Read_After_Update_Student_Course(STU_COURSE_NODE*& head) {
	ofstream outfile;
	outfile.open("UpdatedStudentCourse.csv");
	if (!outfile.is_open()) {
		return 0;
	}
	outfile << "No.,Student ID,Student Name,Gender,Class Name,Course ID,Course Name,Credits,Max_stdn,Teacher Name, Teacher ID, Week day, Session, Day start, Month start, Day end, Month end, Midterm Mark, Final Mark, Other Mark, Total Mark" << endl;
	for (STU_COURSE_NODE* h = head; h != nullptr; h = h->next) {
		outfile << h->stu_course.No << "," << h->stu_course.StuID << "," << h->stu_course.StudentName << "," << h->stu_course.Gen << ","
			<< h->stu_course.Class << "," << h->stu_course.Class << ","
			<< h->stu_course.CouID << h->stu_course.Cname << h->stu_course.credits << h->stu_course.Max_stdn << "/"
			<< h->stu_course.Teachername << "," << h->stu_course.TeacherID << "," << h->stu_course.weekday << "," << h->stu_course.session << "," << h->stu_course.startdate.day
			<< "," << h->stu_course.startdate.month << "," << h->stu_course.enddate.day << "," << h->stu_course.enddate.month
			<< "," << h->stu_course.midterm << "," << h->stu_course.final << "," << h->stu_course.other << "," << h->stu_course.total;
		if (h->next != nullptr)
			outfile << "\n";
	}
	outfile.close();
	return 1;
}
