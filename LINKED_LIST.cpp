#include "header.h"

using namespace std;

//***********GET DATA AND BUILD LINKED LISTS**********

//STAFF
void getDataStaff_csv(ifstream& input, STFF_NODE*& head)
{
	input.open("staffs.csv");
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

		getData_A_Staff(teacher, head);
	}
	input.close();
};
void getData_A_Staff(STAFF staff, STFF_NODE*& head) {
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
std::string ConvertStringonlySS(SESSION& ss) {
	if (ss == S1) return "S1";
	else if (ss == S2) return "S2";
	else if (ss == S3) return "S3";
	else return "S4";
}

void getDataCourse_csv(ifstream& input, CR_NODE *& head) {
	input.open("courses.csv"); //put this in main.cpp
	if (input.is_open() == false)
		return;
	string tem;
	getline(input, tem);
	CR_NODE* cur = head;
	while (input.eof() != true){
		if (head == nullptr) {
			head = new CR_NODE;
			cur = head;
			getData_A_Course(input, cur->course);
			head->next = nullptr;
			head->prev = nullptr;
		}
		else {
			cur->next = new CR_NODE;
			cur->next->prev = cur;
			cur = cur->next;
			cur->next = nullptr;
			getData_A_Course(input, cur->course);			
		}
	}
	input.close();
	return;
}
void getData_A_Course(ifstream& input, COURSE& course) {
	string tmp;
	getline(input, tmp, ',');
	course.No = stoi(tmp);
	getline(input, course.ID, ',');
	getline(input, course.CName, ',');
	getline(input, course.LNameTeacher, ',');
	getline(input, course.FNameTeacher, ',');
	getline(input, course.teacherID, ',');
	getline(input, tmp, ',');
	course.Credits = stoi(tmp);
	getline(input, tmp, ',');
	course.Cur_stdn = stoi(tmp);
	getline(input, tmp, ',');
	course.Max_stdn = stoi(tmp);

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
	getline(input, tmp, ',');
	course.startDate.year = stoi(tmp);

	getline(input, tmp, '/');
	course.endDate.day = stoi(tmp);
	getline(input, tmp, '/');
	course.endDate.month = stoi(tmp);
	getline(input, tmp);
	course.endDate.year = stoi(tmp);
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
		if (courseID == cur1->stu_course.CouID) {
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
			input.close();
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
		studentcourse.midterm = stof(tmp);
		getline(input, tmp, ',');
		studentcourse.final = stof(tmp);
		getline(input, tmp, ',');
		studentcourse.other = stof(tmp);
		getline(input, tmp);
		studentcourse.total = stof(tmp);

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


//========================STUDENT============================
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
		student.DoB.month = stoi(tmp);
		getline(input, tmp, '/');
		student.DoB.day = stoi(tmp);
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

// ===============Doc lai file sau khi da cap nhat=============
bool Read_After_Update_Teachers(STFF_NODE*& head) {
	ofstream outfile;
	outfile.open("staffs.csv");
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
	outfile.open("students.csv");
	if (!outfile.is_open()) {
		return 0;
	}
	outfile << "No,Student ID,Password,Last Name,First Name,Gender,Date Of Birth,Social ID,Classes,Class ID" << endl;
	for (STU_NODE* h = head; h != nullptr; h = h->next) {
		outfile << h->student.No_Student << "," 
			<< h->student.StudentID << "," 
			<< h->student.Password << "," 
			<< h->student.LName << ","
			<< h->student.FName << "," 
			<< h->student.Gender << ","
			<< h->student.DoB.month / 10 << h->student.DoB.month % 10 << "/"
			<< h->student.DoB.day / 10 << h->student.DoB.day % 10 << "/" 
			<< h->student.DoB.year << "," 
			<< h->student.SocialID << "," 
			<< h->student.Classes.name << "," 
			<< h->student.Classes.ClassID;
		if (h->next != nullptr)
			outfile << "\n";
	}
	outfile.close();
	return 1;
}

bool Read_After_Update_Course(CR_NODE*& head) {
	ofstream outfile;
	outfile.open("coursestest.csv");
	if (!outfile.is_open()) {
		return 0;
	}
	outfile << "ID,Cname,teacherName,Credits,Max_stdn,Cur_stdn,Weekday,Session,Start date,End date" << endl;
	for (CR_NODE* c = head; c != nullptr; c = c->next) {
		outfile << c->course.ID << "," << c->course.CName << "," << c->course.LNameTeacher << "," << c->course.FNameTeacher << ","
			<< c->course.Credits << "," << c->course.Max_stdn << "," << c->course.Cur_stdn << "," << ConvertStringWD(c->course.dayOfWeek) << ","
			<< ConvertStringonlySS(c->course.session) << "," 
			<< c->course.startDate.day / 10 << c->course.startDate.day % 10 << "/" << c->course.startDate.month / 10 << c->course.startDate.month % 10 << "/" << c->course.startDate.year << ","
			<< c->course.endDate.day / 10 << c->course.endDate.day % 10 << "/" << c->course.endDate.month / 10 << c->course.endDate.month % 10 << "/" << c->course.endDate.year;
		if (c->next != nullptr) {
			outfile << "\n";
		}
	}
	outfile.close();

	return 1;
}

bool Read_After_Update_Student_Course(CR_NODE*& course ,STU_COURSE_NODE*& head) {
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
	updateCur_stdnInCourse(course, head);
	return 1;
}
void updateCur_stdnInCourse(CR_NODE*& course, STU_COURSE_NODE* head) {
	CR_NODE* cur_course = course;
	while (cur_course) {
		cur_course->course.Cur_stdn = countTheNumberOfStudentsInEachCourse(cur_course->course.ID, head);
		cur_course = cur_course->next;
	}
}
int countTheNumberOfStudentsInEachCourse(std::string CourseID, STU_COURSE_NODE* head) {
	STU_COURSE_NODE* cur = head;
	int count = 0;
	while (cur) {
		if (cur->stu_course.CouID == CourseID)
			count++;
		cur = cur->next;
	}
	return count;
}

void CreateSchoolYear(int& sYEAR) {
	std::cout << "Input the starting year of the school year: ";
	std::cin >> sYEAR;

	std::ofstream outfile("NewSchoolYear.csv");
	if (!outfile.is_open()) {
		std::cout << "Failed to create file." << std::endl;
		return;
	}
	outfile << "School Year" << std::endl;
	outfile << sYEAR << "-" << sYEAR + 1 << std::endl;
	outfile.close();

	std::cout << "New school year created: " << sYEAR << "-" << sYEAR + 1 << std::endl;
}

void ExportScoreBoard(STU_COURSE_NODE* SC, CR_NODE* C, STFF_NODE* loggedinStaff, int& check) {
	STU_COURSE_NODE* studentcourse = SC;
	CR_NODE* course = C;
	int choice;
	int count = 0;
	std::string courseID = "0";
	ofstream output;

	cout << "choose a course" << endl;
	while (course) {
		if (course->course.teacherID == loggedinStaff->staff.TeacherID) {
			cout << course->course.No << "  " << course->course.ID << "  " << course->course.CName << endl;
			count++;
		}
		course = course->next;
	}
	if (count == 0) {
		cout << "you have not attend any course" << endl;
		check = 0;
		return;
	}

	course = C;

	cout << "your choice: ";
	cin >> choice;
	while (course) {
		if (course->course.No == choice) {
			courseID = course->course.ID;
			break;
		}
		else
			course = course->next;
	}

	if (courseID == "0") {
		cout << "Invalid selection, please enter again.\n\n";
		check = 0;
		system("pause");
		return;
	}

	studentcourse = SC;

	output.open("scoreboard.csv");

	output << "No.,Student ID,Student Name,Gender,Class Name,Course ID,Course Name,Credits,Max_stdn,Teacher Name, Teacher ID, Week day, Session, Day start, Month start, Day end, Month end, Midterm Mark, Final Mark, Other Mark, Total Mark" << endl;
	for (studentcourse; studentcourse != nullptr; studentcourse = studentcourse->next) {
		if (studentcourse->stu_course.CouID == courseID) {
			output << studentcourse->stu_course.No << "," << studentcourse->stu_course.StuID << "," << studentcourse->stu_course.StudentName << "," << studentcourse->stu_course.Gen << ","
				<< studentcourse->stu_course.Class << ","
				<< studentcourse->stu_course.CouID << "," << studentcourse->stu_course.Cname << "," << studentcourse->stu_course.credits << "," << studentcourse->stu_course.Max_stdn << ","
				<< studentcourse->stu_course.Teachername << "," << studentcourse->stu_course.TeacherID << "," << studentcourse->stu_course.weekday << "," << studentcourse->stu_course.session << "," << studentcourse->stu_course.startdate.day
				<< "," << studentcourse->stu_course.startdate.month << "," << studentcourse->stu_course.enddate.day << "," << studentcourse->stu_course.enddate.month
				<< "," << studentcourse->stu_course.midterm << "," << studentcourse->stu_course.final << "," << studentcourse->stu_course.other << "," << studentcourse->stu_course.total;
			if (studentcourse->next != nullptr)
				output << "\n";
		}
	}
	check = 1;
	output.close();
	return;
}

void UpdateStaffInfo(STFF_NODE* staff, STFF_NODE* loggedinStaff) {
	cout << "Enter new information:" << endl;
	cout << "Teacher ID: ";
	cin >> loggedinStaff->staff.TeacherID;
	cout << "Password: ";
	cin >> loggedinStaff->staff.Password;
	cout << "First Name: ";
	cin >> loggedinStaff->staff.FName;
	cout << "Last Name: ";
	cin >> loggedinStaff->staff.LName;
	cout << "Gender: ";
	cin >> loggedinStaff->staff.Gender;
	cout << "Date of Birth (DD MM YYYY): ";
	cin >> loggedinStaff->staff.DoB.day >> loggedinStaff->staff.DoB.month >> loggedinStaff->staff.DoB.year;
	cout << "Social ID: ";
	cin >> loggedinStaff->staff.SocialID;
	cout << "Faculty: ";
	cin >> loggedinStaff->staff.Faculty;
}
//Update student
void UpdateStudentInfo(STU_NODE* student, STU_NODE* loggedinStudent) {
	if (!student || !loggedinStudent) {
		std::cout << "Invalid input.\n";
		return;
	}

	// check if the logged in staff is authorized to update student info
	if (loggedinStudent->student.Classes.ClassID != student->student.Classes.ClassID) {
		std::cout << "You are not authorized to update this student's information.\n";
		return;
	}

	std::cout << "Enter new first name: ";
	std::getline(std::cin, student->student.FName);
	std::cout << "Enter new last name: ";
	std::getline(std::cin, student->student.LName);
	std::cout << "Enter new social ID: ";
	std::getline(std::cin, student->student.SocialID);
	std::cout << "Enter new gender: ";
	std::getline(std::cin, student->student.Gender);
	std::cout << "Enter new date of birth (format: DD/MM/YYYY): ";
	std::cin >> student->student.DoB.day >> student->student.DoB.month >> student->student.DoB.year;

	std::cout << "Student information updated successfully.\n";
}

STU_NODE* getInformationByStudentID(std::string StuID, STU_NODE* student) {
	STU_NODE* cur = student;
	while (cur) {
		if (cur->student.StudentID == StuID)
			return cur;
		cur = cur->next;
	}
	return nullptr;
	
}

