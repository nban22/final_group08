#include "header.h"

//***********GET DATA AND BUILD LINKED LISTS**********

//STAFF

//%%%%%%%%%%%%%%    HAM DOC DU LIEU TU FILE CSV VÀO DLL     %%%%%%%%%%%%%
//Read Teacher's Data and create D_Linked List
void getData_A_Teacher(STAFF teacher, STFF_NODE*& head) {
	STFF_NODE* tmp = new STFF_NODE;
	tmp->staff = teacher;
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
void getDataTeacher_csv(std::ifstream& input, STFF_NODE*& head) {
	input.open("teachers.csv");
	STAFF teacher;

	std::getline(input, teacher.TeacherID);
	while (!input.eof())
	{
		std::string tmp;
		std::getline(input, tmp, ',');
		teacher.No_Staff = stoi(tmp);
		std::getline(input, teacher.TeacherID, ',');
		std::getline(input, teacher.LName, ',');
		std::getline(input, teacher.FName, ',');
		std::getline(input, teacher.Gender, ',');
		std::getline(input, tmp, '/');

		teacher.DoB.month = stoi(tmp);
		std::getline(input, tmp, '/');
		teacher.DoB.day = stoi(tmp);
		std::getline(input, tmp, ',');
		teacher.DoB.year = stoi(tmp);
		std::getline(input, teacher.SocialID, ',');
		std::getline(input, teacher.Faculty);

		getData_A_Staff(teacher, head);
	}
	input.close();
}
//Read Staff's Data and create D_Linked List
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
void getDataStaff_csv(std::ifstream& input, STFF_NODE*& head) {
	input.open("staffs.csv");
	STAFF teacher;

	std::getline(input, teacher.TeacherID);
	while (!input.eof())
	{
		std::string tmp;
		std::getline(input, tmp, ',');
		teacher.No_Staff = stoi(tmp);
		std::getline(input, teacher.TeacherID, ',');
		std::getline(input, teacher.Password, ',');
		std::getline(input, teacher.LName, ',');
		std::getline(input, teacher.FName, ',');
		std::getline(input, teacher.Gender, ',');
		std::getline(input, tmp, '/');

		teacher.DoB.month = stoi(tmp);
		std::getline(input, tmp, '/');
		teacher.DoB.day = stoi(tmp);
		std::getline(input, tmp, ',');
		teacher.DoB.year = stoi(tmp);
		std::getline(input, teacher.SocialID, ',');
		std::getline(input, teacher.Faculty);

		getData_A_Staff(teacher, head);
	}
	input.close();
}
//Read Student's Data and create D_Linked List
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
void getDataStudents_csv(std::ifstream& input, STU_NODE*& head) {
	input.open("students.csv");

	STUDENT student;

	std::getline(input, student.StudentID);
	while (!input.eof()) {
		std::string tmp;
		std::getline(input, tmp, ',');
		student.No_Student = stoi(tmp);
		std::getline(input, student.StudentID, ',');
		std::getline(input, student.Password, ',');
		std::getline(input, student.LName, ',');
		std::getline(input, student.FName, ',');
		std::getline(input, student.Gender, ',');
		std::getline(input, tmp, '/');
		student.DoB.month = stoi(tmp);
		std::getline(input, tmp, '/');
		student.DoB.day = stoi(tmp);
		std::getline(input, tmp, ',');
		student.DoB.year = stoi(tmp);
		std::getline(input, student.SocialID, ',');
		std::getline(input, student.Classes.name, ',');
		std::getline(input, student.Classes.ClassID, ',');
		std::getline(input, tmp);
		student.Classes.schoolYear = stoi(tmp);
		getData_A_Student(student, head);
	}

	input.close();
}
//Read Course'getDataCourse_csvs Data and create D_Linked List
void getDataCourse_csv(std::ifstream& input, CR_NODE*& head) {
	input.open("courses.csv");
	if (input.is_open() == false) return;
	std::string tem;
	std::getline(input, tem);
	CR_NODE* cur = head;
	while (input.eof() != true) {
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
void getData_A_Course(std::ifstream& input, COURSE& course) {
	std::string tmp;
	std::getline(input, tmp, ',');
	course.No = stoi(tmp);
	std::getline(input, course.Schoolyear, ','); //new
	std::getline(input, tmp, ',');
	course.Semester = stoi(tmp); //end new
	std::getline(input, course.ID, ',');
	std::getline(input, course.CName, ',');
	std::getline(input, course.LNameTeacher, ',');
	std::getline(input, course.FNameTeacher, ',');
	std::getline(input, course.teacherID, ',');
	std::getline(input, tmp, ',');
	course.Credits = stoi(tmp);
	std::getline(input, tmp, ',');
	course.Cur_stdn = stoi(tmp);
	std::getline(input, tmp, ',');
	course.Max_stdn = stoi(tmp);

	std::string weekday;
	std::getline(input, weekday, ',');
	course.dayOfWeek = ConvertEnumWD(weekday);
	std::string session;
	std::getline(input, session, ',');
	course.session = ConvertEnumSS(session);;

	std::getline(input, tmp, '/');
	course.startDate.month = stoi(tmp);
	std::getline(input, tmp, '/');
	course.startDate.day = stoi(tmp);
	std::getline(input, tmp, ',');
	course.startDate.year = stoi(tmp);

	std::getline(input, tmp, '/');
	course.endDate.month = stoi(tmp);
	std::getline(input, tmp, '/');
	course.endDate.day = stoi(tmp);
	std::getline(input, tmp);
	course.endDate.year = stoi(tmp);
}

//Read Course'getDataStu_Course_csvs Data and create D_Linked List
void Get_Data_StudentCourse_csv(std::ifstream& input, STU_COURSE_NODE*& head) {
	input.open("student_course.csv"); //put this in main.cpp
	STU_COURSE studentcourse;

	std::string tem;
	std::getline(input, tem);
	while (!input.eof())
	{
		std::string tmp;
		std::getline(input, tmp, ',');
		if (tmp == "") {
			input.close();
			break;
		}
		studentcourse.No = stoi(tmp);
		std::getline(input, studentcourse.Schoolyear, ',');
		std::getline(input, tmp, ',');
		studentcourse.Semester = stoi(tmp);
		std::getline(input, studentcourse.StuID, ',');
		std::getline(input, studentcourse.StudentName, ',');
		std::getline(input, studentcourse.Gen, ',');
		std::getline(input, studentcourse.Class, ',');
		std::getline(input, studentcourse.CouID, ',');
		std::getline(input, studentcourse.Cname, ',');
		std::getline(input, tmp, ',');
		studentcourse.credits = stoi(tmp);
		std::getline(input, tmp, ',');
		studentcourse.Max_stdn = stoi(tmp);
		std::getline(input, studentcourse.Teachername, ',');
		std::getline(input, studentcourse.TeacherID, ',');
		std::getline(input, studentcourse.weekday, ',');
		std::getline(input, studentcourse.session, ',');
		std::getline(input, tmp, ',');
		studentcourse.startdate.day = stoi(tmp);
		std::getline(input, tmp, ',');
		studentcourse.startdate.month = stoi(tmp);
		std::getline(input, tmp, ',');
		studentcourse.enddate.day = stoi(tmp);
		std::getline(input, tmp, ',');
		studentcourse.enddate.month = stoi(tmp);
		std::getline(input, tmp, ',');
		studentcourse.midterm = stof(tmp);
		std::getline(input, tmp, ',');
		studentcourse.final = stof(tmp);
		std::getline(input, tmp, ',');
		studentcourse.other = stof(tmp);
		std::getline(input, tmp);
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
//checkAcount
int checkExistOfStudentAccount(STU_NODE*& head, std::string user, std::string password, STU_NODE*& logged) {
	STU_NODE* current = head;

	while (current) {
		if (user == current->student.StudentID && password == current->student.Password) {
			logged = current;
			return 1;
		}
		else if (user == current->student.StudentID && password != current->student.Password)
			return -1;
		else
			current = current->next;
	}
	return 0;
}
int checkExistOfStaffAccount(STFF_NODE*& head, std::string user, std::string password, STFF_NODE*& logged) {

	STFF_NODE* current = head;

	while (current) {
		if (user == current->staff.TeacherID && password == current->staff.Password) {
			logged = current;
			return 1;
		}
		else if (user == current->staff.TeacherID && password != current->staff.Password)
			return -1;
		else
			current = current->next;
	}
	return 0;
}


//COURSE
//Weekday
WEEKDAY ConvertEnumWD(std::string str) {
	if (str.compare("MON") == 0 || str.compare("mon") == 0 || str.compare("Mon") == 0) return MON;
	else if (str.compare("TUE") == 0 || str.compare("tue") == 0 || str.compare("Tue") == 0) return TUE;
	else if (str.compare("WED") == 0 || str.compare("wed") == 0 || str.compare("Wed") == 0) return WED;
	else if (str.compare("THU") == 0 || str.compare("thu") == 0 || str.compare("Thu") == 0) return THU;
	else if (str.compare("FRI") == 0 || str.compare("fri") == 0 || str.compare("Fri") == 0) return FRI;
	else return SAT;
}
//Session
SESSION ConvertEnumSS(std::string str) {
	if (str.compare("S1") == 0 || str.compare("s1") == 0) return S1;
	else if (str.compare("S2") == 0 || str.compare("s2") == 0) return S2;
	else if (str.compare("S3") == 0 || str.compare("s3") == 0) return S3;
	else return S4;
}
std::string ConvertStringonlySS(SESSION& ss) {
	if (ss == S1) return "S1";
	else if (ss == S2) return "S2";
	else if (ss == S3) return "S3";
	else return "S4";
}


void EnterCourseScore(STU_COURSE_NODE*& SC, CR_NODE* C, STFF_NODE* loggedinStaff, int& check) {

	STU_COURSE_NODE* cur1 = SC;
	CR_NODE* cur2 = C;
	int choice;
	int count = 0;
	std::string courseID = "0";

	std::cout << "choose a course" << std::endl;
	while (cur2) {
		if (cur2->course.teacherID == loggedinStaff->staff.TeacherID) {
			std::cout << cur2->course.No << "  " << cur2->course.ID << "  " << cur2->course.CName << std::endl;
			count++;
		}
		cur2 = cur2->next;
	}
	if (count == 0) {
		std::cout << "you have not attend any course" << std::endl;
		check = 0;
		return;
	}
	std::cout << "your choice: ";
	std::cin >> choice;
	while (cur1) {
		if (cur1->stu_course.No == choice) {
			courseID = cur1->stu_course.CouID;
			break;
		}
		else
			cur1 = cur1->next;
	}

	if (courseID == "0") {
		std::cout << "Invalid selection, please enter again.\n\n";
		check = 0;
		system("pause");
		return;
	}

	cur1 = SC;
	std::cout << "\n\n";

	while (cur1) {
		if (courseID == cur1->stu_course.CouID) {
			std::cout << "\t\tEnter Score for student:" << std::endl;
			std::cout << cur1->stu_course.StudentName << "  " << cur1->stu_course.StuID << "  " << std::endl;
			std::cout << "Midterm mark: ";
			std::cin >> cur1->stu_course.midterm;
			std::cout << "Final mark: ";
			std::cin >> cur1->stu_course.final;
			std::cout << "Other mark: ";
			std::cin >> cur1->stu_course.other;
			cur1->stu_course.total = (cur1->stu_course.other + cur1->stu_course.midterm + 2 * cur1->stu_course.final) / 4;
			system("cls");
		}
		cur1 = cur1->next;
	}
	check = 1;
}




//========================STUDENT============================




// ===============Doc lai file sau khi da cap nhat=============
bool Read_After_Update_Staffs(STFF_NODE* staff) {
	std::ofstream outfile;
	outfile.open("staffs_test.csv");
	if (!outfile.is_open()) {
		return 0;
	}
	outfile << "No,Teacher ID,Password,Last Name,First Name,Gender,Date Of Birth,Social ID,Faculty";
	STFF_NODE* cur_staff = staff;
	int i = 1;
	while (cur_staff) {
		outfile << "\n" << i++ << ","
			<< cur_staff->staff.TeacherID << ","
			<< cur_staff->staff.Password << ","
			<< cur_staff->staff.LName << ","
			<< cur_staff->staff.FName << ","
			<< cur_staff->staff.Gender << ","
			<< cur_staff->staff.DoB.month / 10
			<< cur_staff->staff.DoB.month % 10 << "/"
			<< cur_staff->staff.DoB.day / 10
			<< cur_staff->staff.DoB.day % 10 << "/"
			<< cur_staff->staff.DoB.year << ","
			<< cur_staff->staff.SocialID << ","
			<< cur_staff->staff.Faculty;
		cur_staff = cur_staff->next;
	}
	outfile.close();
	return 1;
}
bool Read_After_Update_Teachers(STFF_NODE* teacher) {
	std::ofstream outfile;
	outfile.open("teachers_test.csv");
	if (!outfile.is_open()) {
		return 0;
	}
	outfile << "No,Teacher ID,Last Name,First Name,Gender,Date Of Birth,Social ID,Faculty";
	STFF_NODE* cur_teacher = teacher;
	int i = 1;
	while (cur_teacher) {
		outfile << "\n" << i++ << ","
			<< cur_teacher->staff.TeacherID << ","
			<< cur_teacher->staff.LName << ","
			<< cur_teacher->staff.FName << ","
			<< cur_teacher->staff.Gender << ","
			<< cur_teacher->staff.DoB.month / 10
			<< cur_teacher->staff.DoB.month % 10 << "/"
			<< cur_teacher->staff.DoB.day / 10
			<< cur_teacher->staff.DoB.day % 10 << "/"
			<< cur_teacher->staff.DoB.year << ","
			<< cur_teacher->staff.SocialID << ","
			<< cur_teacher->staff.Faculty;
		cur_teacher = cur_teacher->next;
	}
	outfile.close();
	return 1;
}
bool Read_After_Update_Students(STU_NODE* student) {
	std::ofstream outfile;
	outfile.open("students_TEST.csv");
	if (!outfile.is_open()) {
		return 0;
	}
	outfile << "No,Student ID,Password,Last Name,First Name,Gender,Date Of Birth,Social ID,Classes,Class ID,School year";
	STU_NODE* cur_student = student;
	int i = 1;
	while (cur_student) {
		outfile << "\n" << i++ << ","
			<< cur_student->student.StudentID << ","
			<< cur_student->student.Password << ","
			<< cur_student->student.LName << ","
			<< cur_student->student.FName << ","
			<< cur_student->student.Gender << ","
			<< cur_student->student.DoB.month / 10
			<< cur_student->student.DoB.month % 10 << "/"
			<< cur_student->student.DoB.day / 10
			<< cur_student->student.DoB.day % 10 << "/"
			<< cur_student->student.DoB.year << ","
			<< cur_student->student.SocialID << ","
			<< cur_student->student.Classes.name << ","
			<< cur_student->student.Classes.ClassID << ","
			<< "2022";
		cur_student = cur_student->next;
	}
	outfile.close();
	return 1;
}
bool Read_After_Update_Course(STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE* course) {
	std::ofstream outfile;
	outfile.open("coursestest.csv");
	if (!outfile.is_open()) {
		return 0;
	}
	updateCur_stdnInCourse(course, stu_course);
	int i = 1;
	CR_NODE* cur_course = course;

	outfile << "No,School Year,Semester,ID,Cname,Last Name,First Name,Teacher ID,Credits,Cur_stdn,Max_stdn,Weekday,Session,Start Date,End Date";
	while (cur_course) {
		STFF_NODE* tmp_teacher = getInformationByTeacherID(cur_course->course.teacherID, teacher);
		if (!tmp_teacher) {
			//i++;
			cur_course = cur_course->next;
			continue;
		}
		std::string session = ConvertStringonlySS(cur_course->course.session);
		std::string week = ConvertStringWD(cur_course->course.dayOfWeek);
		outfile << "\n" << i++ << ","
			<< cur_course->course.Schoolyear << ","
			<< cur_course->course.Semester << ","
			<< cur_course->course.ID << ","
			<< cur_course->course.CName << ","
			<< tmp_teacher->staff.LName << ","
			<< tmp_teacher->staff.FName << ","
			<< cur_course->course.teacherID << ","
			<< cur_course->course.Credits << ","
			<< cur_course->course.Cur_stdn << ","
			<< cur_course->course.Max_stdn << ","
			<< week << ","
			<< session << ","
			<< cur_course->course.startDate.month / 10
			<< cur_course->course.startDate.month % 10 << "/"
			<< cur_course->course.startDate.day / 10
			<< cur_course->course.startDate.day % 10 << "/"
			<< cur_course->course.startDate.year << ","
			<< cur_course->course.endDate.month << "/"
			<< cur_course->course.endDate.day << "/"
			<< cur_course->course.endDate.year;
		cur_course = cur_course->next;
	}

	outfile.close();

	return 1;
}
bool Read_After_Update_Student_Course(STU_NODE* student, CR_NODE* course, STFF_NODE* teacher, STU_COURSE_NODE* stu_course) {
	std::ofstream outfile;
	outfile.open("Student_Course_test.csv");
	if (!outfile.is_open()) {
		return 0;
	}
	int i = 1;
	STU_COURSE_NODE* cur_stu_course = stu_course;
	outfile << "No,School Year,Sem,Student ID,Student Name,Gender,Class ID,Course ID,Course Name,Credits,Max_stdn,Teacher Name,Teacher ID,Week day,session,day start,month start,day end,month end,Midterm Mark,Final Mark,Other Mark,Total Mark";
	while (cur_stu_course) {
		STU_NODE* tmp_student = getInformationByStudentID(cur_stu_course->stu_course.StuID, student);
		CR_NODE* tmp_course = getInformationByCourseID(cur_stu_course->stu_course.CouID, course);
		STFF_NODE* tmp_teacher = getInformationByTeacherID(cur_stu_course->stu_course.TeacherID, teacher);
		if (!tmp_student || !tmp_course || !tmp_teacher) {
			i++;
			cur_stu_course = cur_stu_course->next;
			continue;
		}
		std::string student_name = tmp_student->student.LName + " " + tmp_student->student.FName;
		std::string teacher_name = tmp_teacher->staff.LName + " " + tmp_teacher->staff.FName;
		std::string session = ConvertStringonlySS(tmp_course->course.session);
		std::string week = ConvertStringWD(tmp_course->course.dayOfWeek);
		outfile << "\n" << i++ << ","
			<< cur_stu_course->stu_course.Schoolyear << "," //new
			<< cur_stu_course->stu_course.Semester << "," //new
			<< cur_stu_course->stu_course.StuID << ","
			<< student_name << ","
			<< tmp_student->student.Gender << ","
			<< tmp_student->student.Classes.ClassID << ","
			<< cur_stu_course->stu_course.CouID << ","
			<< tmp_course->course.CName << ","
			<< tmp_course->course.Credits << ","
			<< tmp_course->course.Max_stdn << ","
			<< teacher_name << ","
			<< cur_stu_course->stu_course.TeacherID << ","
			<< week << ","
			<< session << ","
			<< tmp_course->course.startDate.day << ","
			<< tmp_course->course.startDate.month << ","
			<< tmp_course->course.endDate.day << ","
			<< tmp_course->course.endDate.month << ","
			<< cur_stu_course->stu_course.midterm << ","
			<< cur_stu_course->stu_course.final << ","
			<< cur_stu_course->stu_course.other << ","
			<< cur_stu_course->stu_course.total;
		cur_stu_course = cur_stu_course->next;
	}
	outfile.close();
	/*updateCur_stdnInCourse(course, stu_course);*/
	return 1;
}
void updateCur_stdnInCourse(CR_NODE*& course, STU_COURSE_NODE* head) {
	CR_NODE* cur_course = course;
	while (cur_course) {
		cur_course->course.Cur_stdn = countTheNumberOfStudentsInEachCourse(cur_course->course.ID, head);
		cur_course = cur_course->next;
	}
}

void updateListClass(CLASS_NODE*& listclass, STU_NODE* student) {
	CLASS_NODE* cur_listclass = listclass;
	STU_NODE* cur1_student = student;
	int i = 1;
	while (cur1_student) {
		if (checkExistClassNODEIDinDLL(listclass, cur1_student->student.Classes.ClassID) == 0)
		{
			if (i != 1) {
				cur_listclass->next = new CLASS_NODE;
				cur_listclass = cur_listclass->next;
			}
			i++;
			cur_listclass->listclass = cur1_student->student.Classes;
		}
		cur1_student = cur1_student->next;
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

bool checkExistOfSchoolyear(std::string year) {
	std::ifstream infile;
	infile.open("NewSchoolYear.csv");
	if (!infile.is_open()) {
		std::cout << "No file founded";
		return 0;
	}

	std::string tmp;
	std::getline(infile, tmp);

	while (!infile.eof()) {
		std::string line;
		std::getline(infile, line, '\n');
		if (line == "") {
			return 0;
		}
		if (line.compare(year) == 0) {
			return 1;
		}
	}
	return 0;
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

void UpdateStaffInfo(STFF_NODE* staff, STFF_NODE* loggedinStaff) {
	std::cout << "Enter new information:" << std::endl;
	std::cout << "Teacher ID: ";
	std::cin >> loggedinStaff->staff.TeacherID;
	std::cout << "Password: ";
	std::cin >> loggedinStaff->staff.Password;
	std::cout << "First Name: ";
	std::cin >> loggedinStaff->staff.FName;
	std::cout << "Last Name: ";
	std::cin >> loggedinStaff->staff.LName;
	std::cout << "Gender: ";
	std::cin >> loggedinStaff->staff.Gender;
	std::cout << "Date of Birth (DD MM YYYY): ";
	std::cin >> loggedinStaff->staff.DoB.day >> loggedinStaff->staff.DoB.month >> loggedinStaff->staff.DoB.year;
	std::cout << "Social ID: ";
	std::cin >> loggedinStaff->staff.SocialID;
	std::cout << "Faculty: ";
	std::cin >> loggedinStaff->staff.Faculty;
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
CR_NODE* getInformationByCourseID(std::string CourseID, CR_NODE* course) {
	CR_NODE* cur = course;
	while (cur) {
		if (cur->course.ID == CourseID)
			return cur;
		cur = cur->next;
	}
	return nullptr;
}
STFF_NODE* getInformationByTeacherID(std::string TeacherID, STFF_NODE* teacher) {
	STFF_NODE* cur = teacher;
	while (cur) {
		if (cur->staff.TeacherID == TeacherID)
			return cur;
		cur = cur->next;
	}
	return nullptr;
}
STU_NODE* importClassFromCSV(std::string ClassID) {
	//Kiểm tra sự tồn tại của file csv
	std::string filename = ClassID + ".csv";
	std::ifstream file(filename);

	if (!file) {
		std::cout << "File not found!";
		return nullptr;
	}

	//Đọc thông tin học sinh từ file csv và lưu vào danh sách liên kết
	STU_NODE* head = nullptr;
	STU_NODE* tail = nullptr;
	std::string line;
	std::getline(file, line); //Bỏ qua dòng đầu tiên của file csv
	while (std::getline(file, line)) {
		STUDENT student;
		std::stringstream ss(line);
		std::string field;
		std::getline(ss, field, ',');
		student.No_Student = stoi(field);
		std::getline(ss, field, ',');
		student.StudentID = field;
		std::getline(ss, field, ',');
		student.Password = field;
		std::getline(ss, field, ',');
		student.FName = field;
		std::getline(ss, field, ',');
		student.LName = field;
		std::getline(ss, field, ',');
		student.Gender = field;
		std::getline(ss, field, ',');
		student.SocialID = field;
		std::getline(ss, field, ',');
		student.DoB.day = stoi(field);
		std::getline(ss, field, ',');
		student.DoB.month = stoi(field);
		std::getline(ss, field, ',');
		student.DoB.year = stoi(field);
		std::getline(ss, field, ',');
		student.Classes.name = field;
		std::getline(ss, field, ',');
		student.Classes.ClassID = field;

		STU_NODE* node = new STU_NODE;
		node->student = student;
		node->next = nullptr;
		node->prev = tail;
		if (head == nullptr) {
			head = node;
		}
		if (tail != nullptr) {
			tail->next = node;
		}
		tail = node;
	}

	file.close();
	return head;
}

void DeleteLL1(STU_NODE* head1)
{
	STU_NODE* tmp = head1;
	while (tmp != nullptr)
	{
		STU_NODE* p = tmp;
		tmp = tmp->next;
		delete p;
	}
	head1 = nullptr;
}
void DeleteLL2(STFF_NODE* head2)
{
	STFF_NODE* tmp = head2;
	while (tmp != nullptr)
	{
		STFF_NODE* p = tmp;
		tmp = tmp->next;
		delete p;
	}
	head2 = nullptr;
}
void DeleteLL3(CR_NODE* head3)
{
	CR_NODE* tmp = head3;
	while (tmp != nullptr)
	{
		CR_NODE* p = tmp;
		tmp = tmp->next;
		delete p;
	}
	head3 = nullptr;
}
void DeleteLL4(STU_COURSE_NODE* head4)
{
	STU_COURSE_NODE* tmp = head4;
	while (tmp != nullptr)
	{
		STU_COURSE_NODE* p = tmp;
		tmp = tmp->next;
		delete p;
	}
	head4 = nullptr;
}
void DeleteLL5(CLASS_NODE* head5)
{
	CLASS_NODE* tmp = head5;
	while (tmp != nullptr)
	{
		CLASS_NODE* p = tmp;
		tmp = tmp->next;
		delete p;
	}
	head5 = nullptr;
}
void DeleteALLLinkList(STU_NODE* head1, STFF_NODE* head2, CR_NODE* head3, STU_COURSE_NODE* head4, CLASS_NODE* head5)
{
	DeleteLL1(head1);
	DeleteLL2(head2);
	DeleteLL3(head3);
	DeleteLL4(head4);
	DeleteLL5(head5);
}

