
#include "header.h"

void printInformation_A_Staff(STFF_NODE* loggedinStaff) {
	std::string fullname = loggedinStaff->staff.LName + " " + loggedinStaff->staff.FName;
	std::string DoB = std::to_string(loggedinStaff->staff.DoB.day / 10) + std::to_string(loggedinStaff->staff.DoB.day % 10) + "/"
		+ std::to_string(loggedinStaff->staff.DoB.month / 10) + std::to_string(loggedinStaff->staff.DoB.month % 10) + "/"
		+ std::to_string(loggedinStaff->staff.DoB.year);
	std::cout << std::setw(45) << std::right << "Teacher's information"
		<< "\n\t" << std::setfill('*') << std::setw(55) << "*" << std::setfill(' ')
		<< "\n\t" << std::setw(15) << std::left << "Full name : " << std::setw(40) << std::right << fullname
		<< "\n\t" << std::setw(15) << std::left << "Teacher ID: " << std::setw(40) << std::right << loggedinStaff->staff.TeacherID
		<< "\n\t" << std::setw(15) << std::left << "Gender: " << std::setw(40) << std::right << loggedinStaff->staff.Gender
		<< "\n\t" << std::setw(15) << std::left << "Date of birth: " << std::setw(40) << std::right << DoB
		<< "\n\t" << std::setw(15) << std::left << "Faculty: " << std::setw(40) << std::right << loggedinStaff->staff.Faculty << "\n\n";
}

CLASS_NODE* checkExistClassNODEIDinDLL(CLASS_NODE* listclass, std::string classID) {
	CLASS_NODE* cur = listclass;
	while (cur) {
		if (cur->listclass.ClassID == classID)
			return cur;
		cur = cur->next;
	}
	return nullptr;
}
STU_NODE* checkExistClassIDinDLL(STU_NODE*& listclass, std::string classID) {
	STU_NODE* cur = listclass;
	while (cur) {
		if (cur->student.Classes.ClassID == classID)
			return cur;
		cur = cur->next;
	}
	return nullptr;
}

void displayListOfTeachers(STFF_NODE* teacher) {
	STFF_NODE* cur_teacher = teacher;
	int coordinate_x = 10;
	int coordinate_y = 3;

	int width_no = 5;
	int width_teacherID = 12;
	int width_teacherName = 25;
	int width_gender = 8;
	int width_DOB = 14;
	int width_socialID = 14;
	int width_faculty = 40;

	int width = width_no + width_teacherID + width_teacherName + width_gender + width_DOB + width_socialID + width_faculty + 3 * 10 - 8;

	gotoXY(coordinate_x, coordinate_y); std::cout << "+";
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y); std::cout << "-";
	}
	gotoXY(coordinate_x + width, coordinate_y); std::cout << "+";

	gotoXY(coordinate_x, coordinate_y + 1);
	std::cout << std::setw(4) << std::left << "|" << std::setw(width_no) << std::left << "No" << std::setw(3) << std::left << "|"
		<< std::setw(width_teacherID) << std::left << "Teacher ID" << std::setw(3) << std::left << "|"
		<< std::setw(width_teacherName) << std::left << "Teacher's Name" << std::setw(3) << std::left << "|"
		<< std::setw(width_gender) << std::left << "Gender" << std::setw(3) << std::left << "|"
		<< std::setw(width_DOB) << std::left << "Day of Birth" << std::setw(3) << std::left << "|"
		<< std::setw(width_socialID) << std::left << "Social ID" << std::setw(3) << std::left << "|"
		<< std::setw(width_faculty) << std::left << "Faculty";

	gotoXY(coordinate_x, coordinate_y + 2); std::cout << "+";
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y + 2); std::cout << "-";
	}
	gotoXY(coordinate_x + width, coordinate_y + 2); std::cout << "+";

	int count = 0;
	while (cur_teacher) {
		count++;
		cur_teacher = cur_teacher->next;
	}
	int page_max = (count - 1) / 15 + 1;
	int page_index = 1;

LOOP1:
	cur_teacher = teacher;
	int i = 0;
	int page = 0;
	int no = 1;
	while (cur_teacher) {
		ShowCur(1);
		i++;
		if (no > count)
			no = 0;
		gotoXY(coordinate_x, coordinate_y + 2 + i);
		std::string birthday = std::to_string(cur_teacher->staff.DoB.day) + "/" + std::to_string(cur_teacher->staff.DoB.month) + "/" + std::to_string(cur_teacher->staff.DoB.year);
		std::string fullname = cur_teacher->staff.LName + " " + cur_teacher->staff.FName;

		std::cout << std::setw(4) << std::left << "|" << std::setw(width_no) << std::left << no++ << std::setw(3) << std::left << "|"
			<< std::setw(width_teacherID) << std::left << cur_teacher->staff.TeacherID << std::setw(3) << std::left << "|"
			<< std::setw(width_teacherName) << std::left << fullname << std::setw(3) << std::left << "|"
			<< std::setw(width_gender) << std::left << cur_teacher->staff.Gender << std::setw(3) << std::left << "|"
			<< std::setw(width_DOB) << std::left << birthday << std::setw(3) << "|"
			<< std::setw(width_socialID) << std::left << cur_teacher->staff.SocialID << std::setw(3) << std::left << "|"
			<< std::setw(width_faculty) << std::left << cur_teacher->staff.Faculty << std::setw(3) << std::left << "|";

		if (i == 15 || cur_teacher->next == nullptr) {
			gotoXY(coordinate_x, coordinate_y + 2 + i + 1); std::cout << "+";
			for (int j = coordinate_x + 1; j < coordinate_x + width; j++) {
				gotoXY(j, coordinate_y + 2 + i + 1); std::cout << "-";
			}
			gotoXY(coordinate_x + width, coordinate_y + 2 + i + 1); std::cout << "+";
		}
		for (int j = coordinate_y + 1; j <= coordinate_y + i + 2; j++)
			if (j != coordinate_y + 2) {
				gotoXY(coordinate_x, j); std::cout << "|";
				gotoXY(coordinate_x + width, j); std::cout << "|";
			}
		if (cur_teacher->next == nullptr) {
			for (int p = coordinate_x; p <= coordinate_x + width; p++)
				for (int k = coordinate_y + 2 + i + 2; k <= coordinate_y + 2 + 15 + 1; k++) {
					my_print(p, k, BLACK, " ");
				}
		}
		if (i == 15 || cur_teacher->next == nullptr) {
			page++;
			my_print(coordinate_x + width / 2 - 4, coordinate_y + 20, GREEN, "page " + std::to_string(page_index) + "/" + std::to_string(page_max));
			i = 0;
			if (page != page_index) {
				cur_teacher = cur_teacher->next;
				continue;
			}
			char ch;
		LOOP:

			ch = _getch();
			if (ch == 75) {
				if (page_index == 1)
					goto LOOP;
				page_index--;
				goto LOOP1;
			}
			else if (ch == 77) {
				page_index++;
			}
			else {
				goto LOOP;
			}
		}
		cur_teacher = cur_teacher->next;
	}

}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@STUDENT@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

void printInformation_A_Student(STU_NODE* loggedinStudent) {
	std::string fullname = loggedinStudent->student.LName + " " + loggedinStudent->student.FName;
	std::string DoB = std::to_string(loggedinStudent->student.DoB.day / 10) + std::to_string(loggedinStudent->student.DoB.day % 10) + "/"
		+ std::to_string(loggedinStudent->student.DoB.month / 10) + std::to_string(loggedinStudent->student.DoB.month % 10) + "/"
		+ std::to_string(loggedinStudent->student.DoB.year);

	std::cout << std::setw(45) << std::right << "Student's information"
		<< "\n\t" << std::setfill('*') << std::setw(55) << "*" << std::setfill(' ')
		<< "\n\t" << std::setw(15) << std::left << "Full name : " << std::setw(40) << std::right << fullname
		<< "\n\t" << std::setw(15) << std::left << "Teacher ID: " << std::setw(40) << std::right << loggedinStudent->student.StudentID
		<< "\n\t" << std::setw(15) << std::left << "Gender: " << std::setw(40) << std::right << loggedinStudent->student.Gender
		<< "\n\t" << std::setw(15) << std::left << "Date of birth: " << std::setw(40) << std::right << DoB
		<< "\n\t" << std::setw(15) << std::left << "Class ID: " << std::setw(40) << std::right << loggedinStudent->student.Classes.ClassID
		<< "\n\t" << std::setw(15) << std::left << "Class name: " << std::setw(40) << std::right << loggedinStudent->student.Classes.name << "\n\n";
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
char GetRanking(float Grade) {
	if (Grade >= 90 && Grade <= 100)
		return 'A';
	else if (Grade >= 80 && Grade <= 89)
		return 'B';
	else if (Grade >= 70 && Grade <= 79)
		return 'C';
	else if (Grade >= 60 && Grade <= 69)
		return 'D';
	else if (Grade >= 0 && Grade <= 59)
		return 'F';
	else
		return 'E';
}