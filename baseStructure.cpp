#include "baseStructure.h"

//Weekday
WEEKDAY ConvertEnumWD(std::string str) {
	if (str.compare("MON") == 0 || str.compare("mon") == 0 || str.compare("Mon") == 0) return MON;
	else if (str.compare("TUE") == 0 || str.compare("tue") == 0 || str.compare("Tue") == 0) return TUE;
	else if (str.compare("WED") == 0 || str.compare("wed") == 0 || str.compare("Wed") == 0) return WED;
	else if (str.compare("THU") == 0 || str.compare("thu") == 0 || str.compare("Thu") == 0) return THU;
	else if (str.compare("FRI") == 0 || str.compare("fri") == 0 || str.compare("Fri") == 0) return FRI;
	else return SAT;
}
std::string ConvertStringWD(WEEKDAY wd) {
	if (wd == MON) return "MON";
	else if (wd == TUE) return "TUE";
	else if (wd == WED) return "WED";
	else if (wd == THU) return "THU";
	else if (wd == FRI) return "FRI";
	else return "SAT";
}
//Session
SESSION ConvertEnumSS(std::string str) {
	if (str.compare("S1") == 0 || str.compare("s1") == 0) return S1;
	else if (str.compare("S2") == 0 || str.compare("s2") == 0) return S2;
	else if (str.compare("S3") == 0 || str.compare("s3") == 0) return S3;
	else return S4;
}
std::string ConvertStringSS(SESSION ss) {
	if (ss == S1) return "S1(07:30)";
	else if (ss == S2) return "S2(09:30)";
	else if (ss == S3) return "S3(13:30)";
	else return "S4(15:30)";
}
std::string ConvertStringonlySS(SESSION ss) {
	if (ss == S1) return "S1";
	else if (ss == S2) return "S2";
	else if (ss == S3) return "S3";
	else return "S4";
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

CLASS_NODE* check_exist_class_node_in_DLL(CLASS_NODE* listclass, std::string classID) {
	CLASS_NODE* cur = listclass;
	while (cur) {
		if (cur->listclass.ClassID == classID)
			return cur;
		cur = cur->next;
	}
	return nullptr;
}
STU_NODE* check_exist_classID_in_DLL(STU_NODE* listclass, std::string classID) {
	STU_NODE* cur = listclass;
	while (cur) {
		if (cur->student.Classes.ClassID == classID)
			return cur;
		cur = cur->next;
	}
	return nullptr;
}


CR_NODE* check_exist_of_course_record(CR_NODE*& course, std::string courseID) {
	CR_NODE* cur_course = course;
	while (cur_course) {
		if (courseID == cur_course->course.ID) {
			return cur_course;
		}
		cur_course = cur_course->next;
	}
	return nullptr;
}
STU_COURSE_NODE* check_exist_of_student_course_record(STU_COURSE_NODE*& stu_course, std::string courseID) {
	STU_COURSE_NODE* cur_stu_course = stu_course;
	while (cur_stu_course) {
		if (cur_stu_course->stu_course.StuID == courseID) {
			return cur_stu_course;
		}
		cur_stu_course = cur_stu_course->next;
	}
	return nullptr;
}

void get_curYear_and_curSemester(int coordinate_x, int coordinate_y, std::string& cur_year, std::string& cur_semester) {
	std::ifstream fileSchoolYear("schoolYear.txt");
	if (!fileSchoolYear.is_open()) {
		my_print(coordinate_x, coordinate_y, RED * 16 + LIGHT_AQUA, "Can not open file schoolYear.txt");
		char ans = _getch();
		return;
	}
	else {
		while (!fileSchoolYear.eof())
			std::getline(fileSchoolYear, cur_year);
		std::string filename_semester = "semester" + cur_year.substr(0, 4) + "_" + std::to_string(stoi(cur_year.substr(0, 4)) + 1) + ".txt";
		std::ifstream fileSemester(filename_semester);
		if (!fileSemester.is_open()) {
			my_print(coordinate_x, coordinate_y, RED * 16 + LIGHT_AQUA, "Can not open file " + filename_semester);
			char ans = _getch();
			fileSchoolYear.close();
			return;
		}
		else {

			while (!fileSemester.eof())
				std::getline(fileSemester, cur_semester);
			cur_semester = cur_semester.substr(0, 1);
			cur_year = cur_year.substr(0, 4);
			fileSchoolYear.close();
			fileSemester.close();
			return;
		}
		fileSemester.close();
	}
	fileSchoolYear.close();
}

int check_exist_of_student_account(STU_NODE*& head, std::string user, std::string password, STU_NODE*& logged) {
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
int check_exist_of_staff_account(STFF_NODE*& head, std::string user, std::string password, STFF_NODE*& logged) {

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

bool check_time(Time start_time, Date start_date, Time end_time, Date end_date) {
	std::time_t now = std::time(nullptr);
	std::tm parts;
	localtime_s(&parts, &now);

	// check year
	if (parts.tm_year + 1900 < start_date.year || parts.tm_year + 1900 > end_date.year) {
		return false;
	}

	// check month
	if (parts.tm_year + 1900 == start_date.year && parts.tm_mon + 1 < start_date.month) {
		return false;
	}
	if (parts.tm_year + 1900 == end_date.year && parts.tm_mon + 1 > end_date.month) {
		return false;
	}

	// check day
	if (parts.tm_year + 1900 == start_date.year && parts.tm_mon + 1 == start_date.month && parts.tm_mday < start_date.day) {
		return false;
	}
	if (parts.tm_year + 1900 == end_date.year && parts.tm_mon + 1 == end_date.month && parts.tm_mday > end_date.day) {
		return false;
	}

	// check hour
	if (parts.tm_year + 1900 == start_date.year && parts.tm_mon + 1 == start_date.month && parts.tm_mday == start_date.day && parts.tm_hour < start_time.hour) {
		return false;
	}
	if (parts.tm_year + 1900 == end_date.year && parts.tm_mon + 1 == end_date.month && parts.tm_mday == end_date.day && parts.tm_hour > end_time.hour) {
		return false;
	}

	// check minute
	if (parts.tm_year + 1900 == start_date.year && parts.tm_mon + 1 == start_date.month && parts.tm_mday == start_date.day && parts.tm_hour == start_time.hour && parts.tm_min < start_time.minute) {
		return false;
	}
	if (parts.tm_year + 1900 == end_date.year && parts.tm_mon + 1 == end_date.month && parts.tm_mday == end_date.day && parts.tm_hour == end_time.hour && parts.tm_min > end_time.minute) {
		return false;
	}
	//check seconđ
	if (parts.tm_year + 1900 == start_date.year && parts.tm_mon + 1 == start_date.month && parts.tm_mday == start_date.day && parts.tm_hour == start_time.hour && parts.tm_min == start_time.minute && parts.tm_sec < start_time.second) {
		return false;
	}
	if (parts.tm_year + 1900 == end_date.year && parts.tm_mon + 1 == end_date.month && parts.tm_mday == end_date.day && parts.tm_hour == end_time.hour && parts.tm_min == end_time.minute && parts.tm_sec > end_time.second) {
		return false;
	}
	return true;
}

void print_infor_staff(STAFF staff, int coordinate_x, int coordinate_y) {
	int width = 43;
	int height = 3;
	std::string curYear, curSemester;
	int backgroundColor = LIGHT_YELLOW;
	int textColor = BLACK;

	textcolor(backgroundColor * 16 + textColor);
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++) {
			gotoXY(coordinate_x + j, coordinate_y + i);
			std::cout << " ";
		}
	get_curYear_and_curSemester(coordinate_x, coordinate_y, curYear, curSemester);
	//box(coordinate_x, coordinate_y, width, height, YELLOW);
	my_print(coordinate_x + 3, coordinate_y, backgroundColor * 16 + textColor, "School Year: " + curYear + "-" + std::to_string(stoi(curYear) + 1));
	my_print(coordinate_x + 3 + 27, coordinate_y, backgroundColor * 16 + textColor, "Semester: " + curSemester);
	my_print(coordinate_x + 3, coordinate_y + 1, backgroundColor * 16 + textColor, "ID: " + staff.TeacherID);
	my_print(coordinate_x + 3, coordinate_y + 2, backgroundColor * 16 + textColor, "Name: " + staff.LName + " " + staff.FName);
	textcolor(WHITE);
}

void print_infor_student(STUDENT student, int coordinate_x, int coordinate_y)
{
	int width = 43;
	int height = 3;
	std::string curYear, curSemester;
	int backgroundColor = LIGHT_YELLOW;
	int textColor = BLACK;

	textcolor(backgroundColor * 16 + textColor);
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++) {
			gotoXY(coordinate_x + j, coordinate_y + i);
			std::cout << " ";
		}
	get_curYear_and_curSemester(coordinate_x, coordinate_y, curYear, curSemester);
	//box(coordinate_x, coordinate_y, width, height, YELLOW);
	my_print(coordinate_x + 3, coordinate_y, backgroundColor * 16 + textColor, "School Year: " + curYear + "-" + std::to_string(stoi(curYear) + 1));
	my_print(coordinate_x + 3 + 27, coordinate_y, backgroundColor * 16 + textColor, "Semester: " + curSemester);
	my_print(coordinate_x + 3, coordinate_y + 1, backgroundColor * 16 + textColor, "ID: " + student.StudentID);
	my_print(coordinate_x + 3, coordinate_y + 2, backgroundColor * 16 + textColor, "Name: " + student.LName + " " + student.FName);
	textcolor(WHITE);
}

void user_guide(int coordinate_x, int coordinate_y) {
	int width = 23;
	int height = 3;
	int backgroundColor = LIGHT_YELLOW;
	int textColor = BLACK;

	textcolor(backgroundColor * 16 + textColor);
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++) {
			gotoXY(coordinate_x + j, coordinate_y + i);
			std::cout << " ";
		}

	gotoXY(coordinate_x + 1, coordinate_y);
	std::cout << "Choose selection: " << char(31) << " " << char(30);
	gotoXY(coordinate_x + 1, coordinate_y + 1);
	std::cout << "Next page: " << char(17) << " " << char(16);
	gotoXY(coordinate_x + 1, coordinate_y + 2);
	std::cout << "Comback: esc";


	textcolor(WHITE);
}