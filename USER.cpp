
#include "header.h"

//*****************LOGIN/LOGOUT*****************

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@STAFF@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//menu teacher
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

//2 - nter information - 1.Add new 1st year students to 1st year classes.
void addNew1styearStudent(STU_NODE*& student, CLASS_NODE* listclass) {
HERE:
	STU_NODE* new_student = new STU_NODE;
	bool check;
	STU_NODE* cur_student = student;
	do {
		check = 0;
		std::system("cls");
		viewListOfClasses(listclass, cur_student);
		std::cout << "Enter student's class id: ";
		std::getline(std::cin, new_student->student.Classes.ClassID);
		cur_student = student;
		while (cur_student) {
			if (cur_student->student.Classes.ClassID == new_student->student.Classes.ClassID)
				check = 1;
			cur_student = cur_student->next;
		}
		if (check == 0) {
			std::cout << "Your class ID which you entered it does not exist.\n";
			std::cout << "\nSearch for Course again? (y/n)";
			char ans;
			std::cin >> ans;
			std::cin.ignore();
			if (ans == 'y' || ans == 'Y') {
				goto HERE;
			}
			else {
				return;
			}
		}
	} while (check == 0);
	std::cout << "Enter student's last name: ";
	std::getline(std::cin, new_student->student.LName);
	std::cout << "Enter student's first name: ";
	std::getline(std::cin, new_student->student.FName);
	std::cout << "Enter student's gender: ";
	std::getline(std::cin, new_student->student.Gender);
	std::cout << "Enter student's date of birth: (dd mm yyyy): ";
	std::cin >> new_student->student.DoB.day >> new_student->student.DoB.month >> new_student->student.DoB.year;
	std::cin.ignore();
	std::cout << "Enter student's social ID: ";
	std::getline(std::cin, new_student->student.SocialID);

	std::system("cls");
	cur_student = student;
	check = 0;
	while (cur_student->next) {
		if (cur_student->student.Classes.ClassID == new_student->student.Classes.ClassID) {
			check = 1;
			new_student->student.Classes.name = cur_student->student.Classes.name;
		}
		if (check == 1 && cur_student->next->student.Classes.name != new_student->student.Classes.name)
			break;
		cur_student = cur_student->next;
	}
	new_student->student.StudentID = std::to_string(stoi(cur_student->student.StudentID) + 1);
	new_student->student.Password = "678910";

	std::system("cls");
	std::cout << "Information of new student is: \n";
	std::cout << "ID: " << new_student->student.StudentID
		<< "\nPassword: " << new_student->student.Password
		<< "\nFull name: " << new_student->student.LName << " " << new_student->student.FName
		<< "\nDate of birth: " << new_student->student.DoB.day << "/" << new_student->student.DoB.month << "/" << new_student->student.DoB.year
		<< "\nSocial ID: " << new_student->student.SocialID
		<< "\nClass name: " << new_student->student.Classes.name
		<< "\nClass ID: " << new_student->student.Classes.ClassID << std::endl;
	std::system("pause");

	new_student->next = cur_student->next;
	new_student->prev = cur_student;
	if (cur_student->next != nullptr)
		cur_student->next->prev = new_student;
	cur_student->next = new_student;


	int i = 1;
	cur_student = student;
	while (cur_student) {
		cur_student->student.No_Student = i++;
		cur_student = cur_student->next;
	}
	Read_After_Update_Students(student);
}

//============================ view list of class============================ 
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
void deleteSTU_NODE(STU_NODE*& head) {
	STU_NODE* tmp = head;
	while (head) {
		tmp = head;
		head = head->next;
		delete tmp;
	}
}
void displayLISTOFCLASS(CLASS_NODE* listclass) {
	CLASS_NODE* cur_listclass = listclass;
	int coordinate_x = 15;
	int coordinate_y = 3;

	int width_no = 10;
	int width_classID = 15;
	int width_className = 40;
	int width_schoolYear = 25;

	int width = width_no + width_classID + width_className + width_schoolYear + 5 * 3;

	gotoXY(coordinate_x, coordinate_y); std::cout << "+";
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y); std::cout << "-";
	}
	gotoXY(coordinate_x + width, coordinate_y); std::cout << "+";

	gotoXY(coordinate_x, coordinate_y + 1);
	std::cout << std::setw(9) << std::left << "|" << std::setw(width_no) << std::left << "No" << std::setw(5) << std::left << "|"
		<< std::setw(width_classID) << std::left << "Class ID" << std::setw(5) << std::left << "|"
		<< std::setw(width_className) << std::left << "Class name" << std::setw(5) << std::left << "|"
		<< std::setw(width_schoolYear) << std::left << "School year";

	gotoXY(coordinate_x, coordinate_y + 2); std::cout << "+";
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y + 2); std::cout << "-";
	}
	gotoXY(coordinate_x + width, coordinate_y + 2); std::cout << "+";

	int count = 0;
	while (cur_listclass) {
		count++;
		cur_listclass = cur_listclass->next;
	}
	int page_max = (count - 1) / 15 + 1;
	int page_index = 1;

LOOP1:
	cur_listclass = listclass;
	int i = 0;
	int page = 0;
	int no = 1;
	while (cur_listclass) {
		ShowCur(1);
		i++;
		if (no > count)
			no = 0;
		gotoXY(coordinate_x, coordinate_y + 2 + i);
		std::cout << std::setw(9) << std::left << "|" << std::setw(width_no) << std::left << no++ << std::setw(5) << std::left << "|"
			<< std::setw(width_classID) << std::left << cur_listclass->listclass.ClassID << std::setw(5) << std::left << "|"
			<< std::setw(width_className) << std::left << cur_listclass->listclass.name << std::setw(5) << std::left << "|"
			<< std::setw(width_schoolYear) << std::left << cur_listclass->listclass.schoolYear;

		if (i == 15 || cur_listclass->next == nullptr) {
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
		if (cur_listclass->next == nullptr) {
			for (int p = coordinate_x; p <= coordinate_x + width; p++)
				for (int k = coordinate_y + 2 + i + 2; k <= coordinate_y + 2 + 15 + 1; k++) {
					my_print(p, k, BLACK, " ");
				}
		}
		if (i == 15 || cur_listclass->next == nullptr) {
			page++;
			my_print(coordinate_x + width / 2 - 4, coordinate_y + 20, GREEN, "page " + std::to_string(page_index) + "/" + std::to_string(page_max));
			i = 0;
			if (page != page_index) {
				cur_listclass = cur_listclass->next;
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
		cur_listclass = cur_listclass->next;
	}
}

void viewListOfClasses(CLASS_NODE*& listclass, STU_NODE* student) {
	std::system("cls");
	updateListClass(listclass, student);
	displayLISTOFCLASS(listclass);
}

//============================ List of students in class============================ 
void viewListStudentsOfClass(STU_NODE* student, CLASS_NODE* listclass) {

	std::string classID;
	int coordinate_x = 20;
	int coordinate_y = 27;
	int width_box = 30;
	int height_box = 2;
	while (1) {
		std::system("cls");
		displayLISTOFCLASS(listclass);
		my_print(coordinate_x, coordinate_y, GREEN, "Enter class ID which you want to open: ");
		box(coordinate_x + 40, coordinate_y - 1, width_box, height_box, BLUE);
		gotoXY(coordinate_x + 40 + 1, coordinate_y);
		classID = my_getline(width_box - 1);

		if (checkExistClassNODEIDinDLL(listclass, classID) == nullptr) {
			my_print(coordinate_x + 10, coordinate_y + 4, RED, "Your selection doesn't exist.");
			char ch;
			ch = _getch();
			continue;
		}
		break;
	}
	std::system("cls");
	displayListStudentsOfCourse(student, classID);
	std::system("pause");
}

//============================ List of courses============================ 
void viewListOfCourses(CR_NODE* course) {
	std::system("cls");
	int coordinate_x = 0;
	int coordinate_y = 3;

	int width_no = 5;
	int width_schoolYear = 11;
	int width_semester = 5;
	int width_courseID = 10;
	int width_courseName = 26;
	int width_teacherName = 23;
	int width_credits = 9;
	int width_registered = 10;
	int width_calendar = 20;

	int width = width_no + width_schoolYear + width_semester + width_courseID + width_courseName + width_teacherName + width_credits
		+ width_registered + width_calendar + 5 * 8;

	gotoXY(coordinate_x, coordinate_y); std::cout << "+";
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y); std::cout << "-";
	}
	gotoXY(coordinate_x + width, coordinate_y); std::cout << "+";

	gotoXY(coordinate_x, coordinate_y + 1);
	std::cout << std::setw(5) << std::left << "|" << std::setw(width_no) << std::left << "No" << std::setw(5) << std::left << "|"
		<< std::setw(width_schoolYear) << std::left << "School year" << std::setw(5) << std::left << "|"
		<< std::setw(width_semester) << std::left << "Sem" << std::setw(5) << std::left << "|"
		<< std::setw(width_courseID) << std::left << "Course ID" << std::setw(5) << std::left << "|"
		<< std::setw(width_courseName) << std::left << "Course name" << std::setw(5) << std::left << "|"
		<< std::setw(width_teacherName) << std::left << "Teacher name" << std::setw(5) << std::left << "|"
		<< std::setw(width_credits) << std::left << "Credits" << std::setw(5) << std::left << "|"
		<< std::setw(width_registered) << std::left << "Registered" << std::setw(5) << std::left << "|"
		<< std::setw(width_calendar) << std::left << "Calendar";

	gotoXY(coordinate_x, coordinate_y + 2); std::cout << "+";
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y + 2); std::cout << "-";
	}
	gotoXY(coordinate_x + width, coordinate_y + 2); std::cout << "+";

	int count = 0;
	CR_NODE* cur_course = course;
	while (cur_course) {
		count++;
		cur_course = cur_course->next;
	}
	int page_max = (count - 1) / 15 + 1;
	int page_index = 1;

LOOP1:
	cur_course = course;
	int i = 0;
	int page = 0;
	int no = 1;
	while (cur_course) {
		ShowCur(1);
		i++;
		if (no > count)
			no = 0;
		gotoXY(coordinate_x, coordinate_y + 2 + i);

		std::string fullname = cur_course->course.LNameTeacher + " " + cur_course->course.FNameTeacher;
		std::string registered = std::to_string(cur_course->course.Cur_stdn) + "/" + std::to_string(cur_course->course.Max_stdn);
		std::string calendar = ConvertStringWD(cur_course->course.dayOfWeek) + "-" + ConvertStringSS(cur_course->course.session);
		std::cout << std::setw(5) << std::left << "|" << std::setw(width_no) << std::left << no++ << std::setw(5) << std::left << "|"
			<< std::setw(width_schoolYear) << std::left << cur_course->course.Schoolyear << std::setw(5) << std::left << "|"
			<< std::setw(width_semester) << std::left << cur_course->course.Semester << std::setw(5) << std::left << "|"
			<< std::setw(width_courseID) << std::left << cur_course->course.ID << std::setw(5) << std::left << "|"
			<< std::setw(width_courseName) << std::left << cur_course->course.CName << std::setw(5) << std::left << "|"
			<< std::setw(width_teacherName) << std::left << fullname << std::setw(5) << std::left << "|"
			<< std::setw(width_credits) << std::left << cur_course->course.Credits << std::setw(5) << std::left << "|"
			<< std::setw(width_registered) << std::left << registered << std::setw(5) << std::left << "|"
			<< std::setw(width_calendar) << std::left << calendar;

		if (i == 15 || cur_course->next == nullptr) {
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
		if (cur_course->next == nullptr) {
			for (int p = coordinate_x; p <= coordinate_x + width; p++)
				for (int k = coordinate_y + 2 + i + 2; k <= coordinate_y + 2 + 15 + 1; k++) {
					my_print(p, k, BLACK, " ");
				}
		}
		if (i == 15 || cur_course->next == nullptr) {
			page++;
			my_print(coordinate_x + width / 2 - 4, coordinate_y + 20, GREEN, "page " + std::to_string(page_index) + "/" + std::to_string(page_max));
			i = 0;
			if (page != page_index) {
				cur_course = cur_course->next;
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
		cur_course = cur_course->next;
	}
}

//============================view list of teachers============================

void ViewListOfTeachers(STFF_NODE* teacher) {
	STFF_NODE* cur = teacher;
	std::system("cls");

	std::cout << "============================================LIST OF TEACHERS ============================================\n\n";
	std::cout << std::setw(5) << std::left << " " << std::setw(5) << std::left << "No" << std::setw(5) << std::left << "|"
		<< std::setw(15) << std::left << "Teachers ID" << std::setw(5) << std::left << "|"
		<< std::setw(20) << std::left << "Teacher's last name" << std::setw(5) << std::left << "|"
		<< std::setw(20) << std::left << "Teacher's first name" << std::setw(5) << std::left << "|"
		<< std::setw(10) << std::left << "Gender" << std::setw(5) << std::left << "|"
		<< std::setw(20) << std::left << "Day of Birth" << std::setw(5) << std::left << "|"
		<< std::setw(20) << std::left << "Social ID" << std::setw(5) << std::left << "|"
		<< std::setw(40) << std::left << "Faculty" << std::setw(5) << std::left << "|" << std::endl;
	std::cout << std::setfill('-') << std::setw(190) << std::left << "-" << std::setfill(' ') << "\n";

	while (cur) {
		std::string birthday = std::to_string(cur->staff.DoB.day) + "/" + std::to_string(cur->staff.DoB.month) + "/" + std::to_string(cur->staff.DoB.year);
		std::cout << std::setw(5) << std::left << " " << std::setw(5) << std::left << cur->staff.No_Staff << std::setw(5) << std::left << "|"
			<< std::setw(15) << std::left << cur->staff.TeacherID << std::setw(5) << std::left << "|"
			<< std::setw(20) << std::left << cur->staff.LName << std::setw(5) << std::left << "|"
			<< std::setw(20) << std::left << cur->staff.FName << std::setw(5) << std::left << "|"
			<< std::setw(10) << std::left << cur->staff.Gender << std::setw(5) << std::left << "|"
			<< std::setw(20) << std::left << birthday << std::setw(5) << "|"
			<< std::setw(20) << std::left << cur->staff.SocialID << std::setw(5) << std::left << "|"
			<< std::setw(40) << std::left << cur->staff.Faculty << std::setw(5) << std::left << "|" << std::endl;
		cur = cur->next;
	}
}

//============================ List of students in course============================4 
void displayLISTSTUDENTOFCOURSE(STU_COURSE_NODE* stu_course, STU_NODE* student, std::string CourseID) {

	int coordinate_x = 10;
	int coordinate_y = 3;

	int width_no = 5;
	int width_studentID = 15;
	int width_studentName = 30;
	int width_gender = 10;
	int width_DOB = 15;
	int socialID = 20;


	int width = width_no + width_studentID + width_studentName + width_gender + width_DOB + socialID + 5 * 7;

	gotoXY(coordinate_x, coordinate_y); std::cout << "+";
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y); std::cout << "-";
	}
	gotoXY(coordinate_x + width, coordinate_y); std::cout << "+";

	gotoXY(coordinate_x, coordinate_y + 1);
	std::cout << std::setw(5) << std::left << "|" << std::setw(width_no) << std::left << "No" << std::setw(5) << std::left << "|"
		<< std::setw(width_studentID) << std::left << "Student ID" << std::setw(5) << std::left << "|"
		<< std::setw(width_studentName) << std::left << "Student's name" << std::setw(5) << std::left << "|"
		<< std::setw(width_gender) << std::left << "Gender" << std::setw(5) << std::left << "|"
		<< std::setw(width_DOB) << std::left << "Date of birth" << std::setw(5) << std::left << "|"
		<< std::setw(socialID) << std::left << "Social ID";

	gotoXY(coordinate_x, coordinate_y + 2); std::cout << "+";
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y + 2); std::cout << "-";
	}
	gotoXY(coordinate_x + width, coordinate_y + 2); std::cout << "+";

	int count = 0;
	STU_COURSE_NODE* cur = stu_course;
	STU_COURSE_NODE* list_course = nullptr;
	STU_COURSE_NODE* cur_list_course = list_course;
	while (cur) {
		if (cur->stu_course.CouID == CourseID) {
			count++;
			if (cur_list_course == nullptr) {
				cur_list_course = list_course = new STU_COURSE_NODE;
				cur_list_course->stu_course = cur->stu_course;
				cur_list_course->next = nullptr;
				cur_list_course->prev = nullptr;
			}
			else {
				cur_list_course->next = new STU_COURSE_NODE;
				cur_list_course->next->stu_course = cur->stu_course;
				cur_list_course->next->prev = cur_list_course;
				cur_list_course = cur_list_course->next;
				cur_list_course->next = nullptr;
			}
		}
		cur = cur->next;
	}
	int page_max = (count - 1) / 15 + 1;
	int page_index = 1;

LOOP1:
	cur_list_course = list_course;
	int i = 0;
	int page = 0;
	int no = 1;
	while (cur_list_course) {
		ShowCur(1);
		i++;
		if (no > count)
			no = 0;
		gotoXY(coordinate_x, coordinate_y + 2 + i);

		STU_NODE* tmp = getInformationByStudentID(cur_list_course->stu_course.StuID, student);
		std::string DoB = std::to_string(tmp->student.DoB.day / 10) + std::to_string(tmp->student.DoB.day % 10) + "/"
			+ std::to_string(tmp->student.DoB.month / 10) + std::to_string(tmp->student.DoB.month % 10) + "/"
			+ std::to_string(tmp->student.DoB.year);
		std::string fullname = tmp->student.LName + " " + tmp->student.FName;
		std::cout << std::setw(5) << std::left << "|" << std::setw(width_no) << std::left << no++ << std::setw(5) << std::left << "|"
			<< std::setw(width_studentID) << std::left << cur_list_course->stu_course.StuID << std::setw(5) << std::left << "|"
			<< std::setw(width_studentName) << std::left << fullname << std::setw(5) << std::left << "|"
			<< std::setw(width_gender) << std::left << tmp->student.Gender << std::setw(5) << std::left << "|"
			<< std::setw(width_DOB) << std::left << DoB << std::setw(5) << std::left << "|"
			<< std::setw(socialID) << std::left << tmp->student.SocialID;

		if (i == 15 || cur_list_course->next == nullptr) {
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
		if (cur_list_course->next == nullptr) {
			for (int p = coordinate_x; p <= coordinate_x + width; p++)
				for (int k = coordinate_y + 2 + i + 2; k <= coordinate_y + 2 + 15 + 1; k++) {
					my_print(p, k, BLACK, " ");
				}
		}
		if (i == 15 || cur_list_course->next == nullptr) {
			page++;
			my_print(coordinate_x + width / 2 - 4, coordinate_y + 20, GREEN, "page " + std::to_string(page_index) + "/" + std::to_string(page_max));
			i = 0;
			if (page != page_index) {
				cur_list_course = cur_list_course->next;
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
		cur_list_course = cur_list_course->next;
	}
	cur_list_course = cur_list_course;
	while (cur_list_course) {
		STU_COURSE_NODE* tmp = cur_list_course;
		cur_list_course = cur_list_course->next;
		delete tmp;
	}
}
void viewListStudentsOfCourse(STU_COURSE_NODE* stu_course, STU_NODE* student, CR_NODE* course) {
	int coordinate_x = 20;
	int coordinate_y = 27;
	int width_box = 30;
	int height_box = 2;
	int check = 0;

	std::string CourseID;
	do {
		std::system("cls");
		viewListOfCourses(course);
		my_print(coordinate_x, coordinate_y, GREEN, "Enter Course ID which you want to open: ");
		box(coordinate_x + 41, coordinate_y - 1, width_box, height_box, BLUE);
		gotoXY(coordinate_x + 41 + 1, coordinate_y);
		CourseID = my_getline(width_box - 1);

		CR_NODE* cur = course;
		while (cur) {
			if (cur->course.ID == CourseID)
				check = 1;
			cur = cur->next;
		}
		if (check == 0) {
			my_print(coordinate_x + 10, coordinate_y + 4, RED, "Your Course ID doesn't exist. Please enter again.");
			char ch;
			ch = _getch();
		}
	} while (check == 0);
	std::system("cls");
	displayLISTSTUDENTOFCOURSE(stu_course, student, CourseID);
	std::system("pause");
}
//============================view list of students in a course============================ 
void displayListStudentsOfCourse(STU_NODE*& student, std::string classID) {

	int coordinate_x = 10;
	int coordinate_y = 3;

	int width_no = 5;
	int width_studentID = 15;
	int width_lastName = 20;
	int width_firstName = 10;
	int width_gender = 10;
	int width_DOB = 15;
	int width_socialID = 20;

	int width = width_no + width_studentID + width_lastName + width_firstName + width_gender + width_DOB + width_socialID + 5 * 7;

	gotoXY(coordinate_x, coordinate_y); std::cout << "+";
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y); std::cout << "-";
	}
	gotoXY(coordinate_x + width, coordinate_y); std::cout << "+";

	gotoXY(coordinate_x, coordinate_y + 1);
	std::cout << std::setw(5) << std::left << "|" << std::setw(width_no) << std::left << "No" << std::setw(5) << std::left << "|"
		<< std::setw(width_studentID) << std::left << "Student ID" << std::setw(5) << std::left << "|"
		<< std::setw(width_lastName) << std::left << "Last name" << std::setw(5) << std::left << "|"
		<< std::setw(width_firstName) << std::left << "First name" << std::setw(5) << std::left << "|"
		<< std::setw(width_gender) << std::left << "Gender" << std::setw(5) << std::left << "|"
		<< std::setw(width_DOB) << std::left << "Date of birth" << std::setw(5) << std::left << "|"
		<< std::setw(width_socialID) << std::left << "social ID";

	gotoXY(coordinate_x, coordinate_y + 2); std::cout << "+";
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y + 2); std::cout << "-";
	}
	gotoXY(coordinate_x + width, coordinate_y + 2); std::cout << "+";

	int count = 0;
	STU_NODE* cur_student = student;
	STU_NODE* list_student = nullptr;
	STU_NODE* cur_list_student = list_student;
	while (cur_student) {
		if (cur_student->student.Classes.ClassID == classID) {
			count++;
			if (list_student == nullptr) {
				cur_list_student = list_student = new STU_NODE;
				cur_list_student->student = cur_student->student;
				cur_list_student->next = nullptr;
				cur_list_student->prev = nullptr;
			}
			else {
				cur_list_student->next = new STU_NODE;
				cur_list_student->next->student = cur_student->student;
				cur_list_student->next->prev = cur_list_student;
				cur_list_student = cur_list_student->next;
				cur_list_student->next = nullptr;
			}
		}
		cur_student = cur_student->next;
	}
	int page_max = (count - 1) / 15 + 1;
	int page_index = 1;

LOOP1:
	cur_list_student = list_student;
	int i = 0;
	int page = 0;
	int no = 1;
	while (cur_list_student) {
		ShowCur(1);
		i++;
		if (no > count)
			no = 0;
		gotoXY(coordinate_x, coordinate_y + 2 + i);
		std::string DOB = std::to_string(cur_list_student->student.DoB.day / 10) + std::to_string(cur_list_student->student.DoB.day % 10) + "/"
			+ std::to_string(cur_list_student->student.DoB.month / 10) + std::to_string(cur_list_student->student.DoB.month % 10) + "/"
			+ std::to_string(cur_list_student->student.DoB.year);
		std::cout << std::setw(5) << std::left << "|" << std::setw(width_no) << std::left << no++ << std::setw(5) << std::left << "|"
			<< std::setw(width_studentID) << std::left << cur_list_student->student.StudentID << std::setw(5) << std::left << "|"
			<< std::setw(width_lastName) << std::left << cur_list_student->student.LName << std::setw(5) << std::left << "|"
			<< std::setw(width_firstName) << std::left << cur_list_student->student.FName << std::setw(5) << std::left << "|"
			<< std::setw(width_gender) << std::left << cur_list_student->student.Gender << std::setw(5) << std::left << "|"
			<< std::setw(width_DOB) << std::left << DOB << std::setw(5) << std::left << "|"
			<< std::setw(width_socialID) << std::left << cur_list_student->student.SocialID;

		if (i == 15 || cur_list_student->next == nullptr) {
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
		if (cur_list_student->next == nullptr) {
			for (int p = coordinate_x; p <= coordinate_x + width; p++)
				for (int k = coordinate_y + 2 + i + 2; k <= coordinate_y + 2 + 15 + 1; k++) {
					my_print(p, k, BLACK, " ");
				}
		}
		if (i == 15 || cur_list_student->next == nullptr) {
			page++;
			my_print(coordinate_x + width / 2 - 4, coordinate_y + 20, GREEN, "page " + std::to_string(page_index) + "/" + std::to_string(page_max));
			i = 0;
			if (page != page_index) {
				cur_list_student = cur_list_student->next;
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
		cur_list_student = cur_list_student->next;
	}
	cur_list_student = list_student;
	while (cur_list_student) {
		STU_NODE* tmp = cur_list_student;
		cur_list_student = cur_list_student->next;
		delete tmp;
	}
}


//============================view a scoreboard in a course============================ 
void displayScoreBoard_Course(STU_COURSE_NODE* stu_course, STU_NODE* student, std::string CourseID) {

	int coordinate_x = 3;
	int coordinate_y = 3;

	int width_no = 5;
	int width_studentID = 10;
	int width_lastName = 25;
	int width_firstName = 15;
	int width_other = 15;
	int width_midterm = 15;
	int width_final = 15;
	int width_total = 15;

	int width = width_no + width_studentID + width_lastName + width_firstName + width_other
		+ width_midterm + width_final + width_total + 5 * 8;

	gotoXY(coordinate_x, coordinate_y); std::cout << "+";
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y); std::cout << "-";
	}
	gotoXY(coordinate_x + width, coordinate_y); std::cout << "+";

	gotoXY(coordinate_x, coordinate_y + 1);
	std::cout << std::setw(5) << std::left << "|" << std::setw(width_no) << std::left << "No" << std::setw(5) << std::left << "|"
		<< std::setw(10) << std::left << "Student ID" << std::setw(5) << std::left << "|"
		<< std::setw(25) << std::left << "Last name" << std::setw(5) << std::left << "|"
		<< std::setw(15) << std::left << "Firse name" << std::setw(5) << std::left << "|"
		<< std::setw(15) << std::left << "Other Mark" << std::setw(5) << std::left << "|"
		<< std::setw(15) << std::left << "Midterm Mark" << std::setw(5) << std::left << "|"
		<< std::setw(15) << std::left << "Final Mark" << std::setw(5) << std::left << "|"
		<< std::setw(15) << std::left << "Total Mark";
	gotoXY(coordinate_x, coordinate_y + 2); std::cout << "+";
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y + 2); std::cout << "-";
	}
	gotoXY(coordinate_x + width, coordinate_y + 2); std::cout << "+";

	int count = 0;
	STU_COURSE_NODE* cur = stu_course;
	STU_COURSE_NODE* list_stu_course = nullptr;
	STU_COURSE_NODE* cur_list_stu_course = list_stu_course;

	while (cur) {
		if (cur->stu_course.CouID == CourseID) {
			count++;
			if (cur_list_stu_course == nullptr) {
				cur_list_stu_course = list_stu_course = new STU_COURSE_NODE;
				cur_list_stu_course->stu_course = cur->stu_course;
				cur_list_stu_course->next = nullptr;
				cur_list_stu_course->prev = nullptr;
			}
			else {
				cur_list_stu_course->next = new STU_COURSE_NODE;
				cur_list_stu_course->next->stu_course = cur->stu_course;
				cur_list_stu_course->next->prev = cur_list_stu_course;
				cur_list_stu_course = cur_list_stu_course->next;
				cur_list_stu_course->next = nullptr;
			}
		}
		cur = cur->next;
	}
	int page_max = (count - 1) / 15 + 1;
	int page_index = 1;

LOOP1:
	cur_list_stu_course = list_stu_course;
	int i = 0;
	int page = 0;
	int no = 1;
	while (cur_list_stu_course) {
		ShowCur(1);
		i++;
		if (no > count)
			no = 0;
		gotoXY(coordinate_x, coordinate_y + 2 + i);
		STU_NODE* tmp = getInformationByStudentID(cur_list_stu_course->stu_course.StuID, student);
		std::cout << std::setw(5) << std::left << "|" << std::setw(width_no) << std::left << no++ << std::setw(5) << std::left << "|"
			<< std::setw(10) << std::left << cur_list_stu_course->stu_course.StuID << std::setw(5) << std::left << "|"
			<< std::setw(25) << std::left << tmp->student.LName << std::setw(5) << std::left << "|"
			<< std::setw(15) << std::left << tmp->student.FName << std::setw(5) << std::left << "|"
			<< std::setw(15) << std::left << cur_list_stu_course->stu_course.other << std::setw(5) << std::left << "|"
			<< std::setw(15) << std::left << cur_list_stu_course->stu_course.midterm << std::setw(5) << std::left << "|"
			<< std::setw(15) << std::left << cur_list_stu_course->stu_course.final << std::setw(5) << std::left << "|"
			<< std::setw(15) << std::left << cur_list_stu_course->stu_course.total;
		if (i == 15 || cur_list_stu_course->next == nullptr) {
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
		if (cur_list_stu_course->next == nullptr) {
			for (int p = coordinate_x; p <= coordinate_x + width; p++)
				for (int k = coordinate_y + 2 + i + 2; k <= coordinate_y + 2 + 15 + 1; k++) {
					my_print(p, k, BLACK, " ");
				}
		}
		if (i == 15 || cur_list_stu_course->next == nullptr) {
			page++;
			my_print(coordinate_x + width / 2 - 4, coordinate_y + 20, GREEN, "page " + std::to_string(page_index) + "/" + std::to_string(page_max));
			i = 0;
			if (page != page_index) {
				cur_list_stu_course = cur_list_stu_course->next;
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
		cur_list_stu_course = cur_list_stu_course->next;
	}
	cur_list_stu_course = list_stu_course;
	while (cur_list_stu_course) {
		STU_COURSE_NODE* tmp = cur_list_stu_course;
		cur_list_stu_course = cur_list_stu_course->next;
		delete tmp;
	}
}

void viewScoreboardInCourse(CR_NODE* course, STU_COURSE_NODE* stu_course, STU_NODE* student) {
	int check = 0;
	int coordinate_x = 30;
	int coordinate_y = 26;
	int width_box = 40;
	int height_box = 2;
	std::string CourseID;
	do {
		std::system("cls");
		viewListOfCourses(course);
		my_print(coordinate_x, coordinate_y, LIGHT_RED, "Enter the course ID which you want to view the scoreboard : ");
		box(coordinate_x, coordinate_y + 1, width_box, height_box, PURPLE);
		gotoXY(coordinate_x + 1, coordinate_y + 2);
		CourseID = my_getline(width_box - 1);
		CR_NODE* cur = course;
		while (cur) {
			if (cur->course.ID == CourseID)
				check = 1;
			cur = cur->next;
		}
		if (check == 0) {
			my_print(coordinate_x, coordinate_y + 4, RED, "Your Course ID doesn't exist. Please enter again.");
			std::system("pause");
		}
	} while (check == 0);
	std::system("cls");
	displayScoreBoard_Course(stu_course, student, CourseID);
	std::system("pause");
}

void displayScoreBoard_Class(STU_COURSE_NODE* stu_course, STU_NODE* student, std::string ClassID) {
	int i = 1;
	STU_NODE* cur_student = student;
	STU_COURSE_NODE* cur = stu_course;
	std::cout << "============================================A SCOREBOARD IN CLASS " << ClassID << "============================================\n\n";
	std::cout << std::setw(5) << std::left << " " << std::setw(5) << std::left << "No" << std::setw(5) << std::left << "|"
		<< std::setw(10) << std::left << "Student ID" << std::setw(5) << std::left << "|"
		<< std::setw(25) << std::left << "Last name" << std::setw(5) << std::left << "|"
		<< std::setw(15) << std::left << "Firse name" << std::setw(5) << std::left << "|"
		<< std::setw(25) << std::left << "Subject" << std::setw(5) << std::left << "|"
		<< std::setw(15) << std::left << "Mark" << std::endl;
	std::cout << std::setfill('-') << std::setw(125) << std::left << "-" << std::setfill(' ') << std::endl;
	while (cur_student) {
		if (cur_student->student.Classes.ClassID == ClassID) {
			float GPA = 0;
			int count = 0;
			while (cur->stu_course.StuID == cur_student->student.StudentID) {
				std::cout << std::setw(5) << std::left << " " << std::setw(5) << std::left << " " << std::setw(5) << std::left << "|"
					<< std::setw(10) << std::left << " " << std::setw(5) << std::left << "|"
					<< std::setw(25) << std::left << " " << std::setw(5) << std::left << "|"
					<< std::setw(15) << std::left << " " << std::setw(5) << std::left << "|"
					<< std::setw(25) << std::left << cur->stu_course.Cname << std::setw(5) << std::left << "|"
					<< std::setw(15) << std::left << cur->stu_course.total << std::endl;
				GPA += cur->stu_course.total;
				count++;
				cur = cur->next;
			}
			if (count == 0)
				std::cout << std::setw(5) << std::left << " " << std::setw(5) << std::left << i++ << std::setw(5) << std::left << "|"
				<< std::setw(10) << std::left << cur_student->student.StudentID << std::setw(5) << std::left << "|"
				<< std::setw(25) << std::left << cur_student->student.LName << std::setw(5) << std::left << "|"
				<< std::setw(15) << std::left << cur_student->student.FName << std::setw(5) << std::left << "|"
				<< std::setw(25) << std::left << "GPA of this semester" << std::setw(5) << std::left << "|"
				<< std::setw(15) << std::left << std::fixed << std::setprecision(2) << 0 << std::endl;
			else
				std::cout << std::setw(5) << std::left << " " << std::setw(5) << std::left << i++ << std::setw(5) << std::left << "|"
				<< std::setw(10) << std::left << cur_student->student.StudentID << std::setw(5) << std::left << "|"
				<< std::setw(25) << std::left << cur_student->student.LName << std::setw(5) << std::left << "|"
				<< std::setw(15) << std::left << cur_student->student.FName << std::setw(5) << std::left << "|"
				<< std::setw(25) << std::left << "GPA of this semester" << std::setw(5) << std::left << "|"
				<< std::setw(15) << std::left << std::fixed << std::setprecision(2) << GPA / count << std::endl;
			std::cout << std::setfill('-') << std::setw(125) << std::left << "-" << std::setfill(' ') << std::endl;
		}
		cur_student = cur_student->next;
	}
}
void viewScoreBoard_Class(STU_COURSE_NODE* stu_course, STU_NODE* student, CLASS_NODE* listclass) {
	int check = 0;
	std::string ClassID;
	int coordinate_x = 20;
	int coordinate_y = 25;
	int width_box = 30;
	int height_box = 2;
	do {
		std::system("cls");
		viewListOfClasses(listclass, student);
		my_print(coordinate_x, coordinate_y, LIGHT_RED, "Enter the class ID which you want to view the scoreboard: ");
		box(coordinate_x + 59, coordinate_y - 1, width_box, height_box, LIGHT_AQUA);
		gotoXY(coordinate_x + 59 + 1, coordinate_y);
		ClassID = my_getline(width_box - 1);

		if (checkExistClassIDinDLL(student, ClassID) != nullptr)
			check = 1;

		if (check == 0) {
			my_print(coordinate_x, coordinate_y + 3, RED, "Your class ID doesn't exist. Please enter again.");
			system("pause");
		}
	} while (check == 0);
	system("cls");
	displayScoreBoard_Class(stu_course, student, ClassID);
	system("pause");
}
void View_Y_Scoreboard(STU_COURSE_NODE* stu_course, STU_NODE* loggedinStudent) {
	std::system("cls");
	STU_COURSE_NODE* current = stu_course;

	int count = 1;

	std::system("cls");

	std::cout << "=========================================================YOUR SCOREBOARD======================================================\n\n";
	std::cout << std::setw(5) << std::left << " " << std::setw(5) << std::left << "No" << std::setw(5) << std::left << "|"
		<< std::setw(15) << std::left << "SchoolYear" << std::setw(5) << std::left << "|"
		<< std::setw(10) << std::left << "Sem" << std::setw(5) << std::left << "|"
		<< std::setw(10) << std::left << "Course ID" << std::setw(5) << std::left << "|"
		<< std::setw(30) << std::left << "Course name" << std::setw(5) << std::left << "|"
		<< std::setw(10) << std::left << "Midterm" << std::setw(5) << std::left << "|"
		<< std::setw(10) << std::left << "Final" << std::setw(5) << std::left << "|"
		<< std::setw(10) << std::left << "Total" << std::setw(5) << std::left << "|"
		<< std::setw(10) << std::left << "Ranking" << std::endl;
	std::cout << std::setfill('-') << std::setw(150) << std::left << "-" << std::setfill(' ') << std::endl;

	while (current != nullptr) {
		if (current->stu_course.StuID == loggedinStudent->student.StudentID) {
			std::cout << std::setw(5) << std::left << " " << std::setw(5) << std::left << count << std::setw(5) << std::left << "|"
				<< std::setw(15) << std::left << current->stu_course.Schoolyear << std::setw(5) << std::left << "|"
				<< std::setw(10) << std::left << current->stu_course.Semester << std::setw(5) << std::left << "|"
				<< std::setw(10) << std::left << current->stu_course.CouID << std::setw(5) << std::left << "|"
				<< std::setw(30) << std::left << current->stu_course.Cname << std::setw(5) << std::left << "|"
				<< std::setw(10) << std::left << current->stu_course.midterm << std::setw(5) << std::left << "|"
				<< std::setw(10) << std::left << current->stu_course.final << std::setw(5) << std::left << "|"
				<< std::setw(10) << std::left << current->stu_course.total << std::setw(5) << std::left << "|"
				<< std::setw(10) << std::left << GetRanking(current->stu_course.total) << std::endl;
			count++;
		}
		current = current->next;
	}
}





void ExportScoreBoard(STU_COURSE_NODE* stu_course, CR_NODE* course, STU_NODE* student) {
Here:
	std::system("cls");
	viewListOfCourses(course);

	std::cout << "\n\n\t1. Export all the courses. ";
	std::cout << "\n\t2. Export only a course. ";
	std::cout << "\n\t0. Come back. ";
	std::cout << "\nEnter select the option you want to choose: ";
	int choice;
	std::cin >> choice;
	CR_NODE* cur_course = course;
	STU_COURSE_NODE* cur_stu_course = stu_course;
	int count = 0;
	int check = 0;
	std::string courseID = "0";

	if (choice == 1) {
		while (cur_course) {
			std::ofstream output;
			cur_stu_course = stu_course;
			int i = 1;

			output.open("Scoreboard_K22_2_" + cur_course->course.ID + ".csv");

			if (!output.is_open()) {
				std::cout << "cannot open file " << std::endl;
				return;
			}

			output << "No,ID,Last Name,First Name,Other Mark,Midterm Mark,Final Mark,Total Mark";

			while (cur_stu_course) {
				if (cur_stu_course->stu_course.CouID == cur_course->course.ID) {
					STU_NODE* tmp = getInformationByStudentID(cur_stu_course->stu_course.StuID, student);
					output << "\n" << i++ << ",";
					output << cur_stu_course->stu_course.StuID << ","
						<< tmp->student.LName << ","
						<< tmp->student.FName << ","
						<< cur_stu_course->stu_course.other << ","
						<< cur_stu_course->stu_course.midterm << ","
						<< cur_stu_course->stu_course.final << ","
						<< cur_stu_course->stu_course.total;
				}
				cur_stu_course = cur_stu_course->next;
			}
			output.close();
			cur_course = cur_course->next;
		}
	}
	else if (choice == 2) {
		std::ofstream output;
		int i = 1;
		cur_course = course;
		std::system("cls");
		viewListOfCourses(cur_course);
		std::cout << "\n\nEnter ID of the course you want to export: ";
		std::cin >> courseID;
		while (cur_course) {
			if (cur_course->course.ID == courseID) {
				check = 1;
				break;
			}
			cur_course = cur_course->next;
		}
		if (check == 0) {
			std::cout << "Your course ID which you entered does not exist.\n";
			std::cout << "\nSearch for Course again? (y/n)";
			char ans;
			std::cin >> ans;
			std::cin.ignore();
			if (ans == 'y' || ans == 'Y') {
				ExportScoreBoard(stu_course, course, student);
			}
			else {
				return;
			}
		}
		else {
			output.open("Scoreboard_K22_2_" + cur_course->course.ID + ".csv");
			if (!output.is_open()) {
				std::cout << "cannot open file " << std::endl;
				return;
			}
			output << "No,ID,Last Name,First Name,Other Mark,Midterm Mark,Final Mark,Total Mark";

			while (cur_stu_course) {
				if (cur_stu_course->stu_course.CouID == courseID) {
					STU_NODE* tmp = getInformationByStudentID(cur_stu_course->stu_course.StuID, student);
					output << "\n" << i++ << ",";
					output << cur_stu_course->stu_course.StuID << ","
						<< tmp->student.LName << ","
						<< tmp->student.FName << ","
						<< cur_stu_course->stu_course.other << ","
						<< cur_stu_course->stu_course.midterm << ","
						<< cur_stu_course->stu_course.final << ","
						<< cur_stu_course->stu_course.total;
				}
				cur_stu_course = cur_stu_course->next;
			}
			output.close();
		}
	}
	else if (choice == 0)
		return;
	else {
		std::cout << "your choice is invalid, pleasre choose again" << std::endl;
		std::system("pause");
		goto Here;
	}
	std::system("cls");
	std::cout << "Export finished" << std::endl;
	std::system("pause");
}

void changePassWordOfStaffAccount(STFF_NODE*& staff, STFF_NODE*& loggedinStaff) {
	std::string oldPass;
	std::string newPass;
	std::string newPassAgain;
	do {
		std::system("cls");
		std::cout << "Enter your old password: ";
		std::getline(std::cin, oldPass);
		if (loggedinStaff->staff.Password != oldPass) {
			std::cout << "Your old password has been entered incorrectly. Please, enter again.\n\n";
			std::system("pause");
			continue;
		}
		else {
			std::cout << "Enter your new password: ";
			std::getline(std::cin, newPass);
			std::cout << "Enter your new password again: ";
			std::getline(std::cin, newPassAgain);
			if (newPass != newPassAgain) {
				std::cout << "Confirmation password is not correct. Please, enter again.\n\n";
				std::system("pause");
				continue;
			}
			loggedinStaff->staff.Password = newPass;
			Read_After_Update_Staffs(staff);
			std::cout << "Change password successfully.\n\n";
			std::system("pause");
			break;
		}
	} while (loggedinStaff->staff.Password != oldPass || newPass != newPassAgain);
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

void changePasswordOfStudentAccount(STU_NODE*& student, STU_NODE*& loggedinStudent) {
/* 	std::string oldPass;
	std::string newPass;
	std::string newPassAgain;
	do {
		std::system("cls");
		std::cout << "Enter your old password: ";
		std::getline(std::cin, oldPass);
		if (loggedinStudent->student.Password != oldPass) {
			std::cout << "Your old password has been entered incorrectly. Please, enter again.\n";
			std::system("pause");
			continue;
		}
		else {
			std::cout << "Enter your new password: ";
			std::getline(std::cin, newPass);
			std::cout << "Enter your new password again: ";
			std::getline(std::cin, newPassAgain);
			if (newPass != newPassAgain) {
				std::cout << "Confirmation password is not correct. Please, enter again.\n";
				std::system("pause");
				continue;
			}
			loggedinStudent->student.Password = newPass;
			Read_After_Update_Students(student);
			std::cout << "Change password successfully.\n";
			std::system("pause");
			break;
		}
	} while (loggedinStudent->student.Password != oldPass || newPass != newPassAgain);  */

	ShowCur(1);
	int width_tmp = 70;
	int height_tmp = 10;

	int width_box = 40;
	int height_box = 2;

	my_print(width_tmp, height_tmp, YELLOW, "Old password:");
	box(width_tmp, height_tmp + 1, width_box, height_box, YELLOW);

	my_print(width_tmp, height_tmp + 5, YELLOW, "New password:");
	box(width_tmp, height_tmp + 6, width_box, height_box, YELLOW);

	my_print(width_tmp, height_tmp + 10, YELLOW, "Verify:");
	box(width_tmp, height_tmp + 11, width_box, height_box, YELLOW);

	std::string old_password, new_password, new_password_again;

	gotoXY(width_tmp + 1, height_tmp + 2);
	old_password = my_getline(width_box - 1);

	gotoXY(width_tmp + 1, height_tmp + 7);
	new_password = my_getline(width_box - 1);

	gotoXY(width_tmp + 1, height_tmp + 12);
	new_password_again = my_getline(width_box - 1);

	if (loggedinStudent->student.Password != old_password) {
		my_print(width_tmp, height_tmp + 15, RED, "Your old password has been entered incorrectly.");
		gotoXY(width_tmp, height_tmp + 17);
		system("pause");
		return;
	}
	if (new_password != new_password_again) {
		my_print(width_tmp, height_tmp + 15, RED, "Confirmation password is not correct.");
		gotoXY(width_tmp, height_tmp + 17);
		system("pause");
		return;
	}
	loggedinStudent->student.Password = new_password;
	Read_After_Update_Students(student);
	my_print(width_tmp, height_tmp + 15, RED, "Change password successfully.");
	system("pause");
}

bool ViewSchedule(STU_COURSE_NODE* stu_course, STU_NODE* loggedinStudent, CR_NODE* course) {
	STU_COURSE_NODE* cur_stu_course = stu_course;
	CR_NODE* cur_course = course;
	int count = 0;

	std::system("cls");

	std::cout << "============================================YOUR COURSES============================================\n\n";
	std::cout << std::setw(5) << std::left << " " << std::setw(5) << std::left << "No" << std::setw(5) << std::left << "|"
		<< std::setw(10) << std::left << "Course ID" << std::setw(5) << std::left << "|"
		<< std::setw(30) << std::left << "Course name" << std::setw(5) << std::left << "|"
		<< std::setw(25) << std::left << "Teacher name" << std::setw(5) << std::left << "|"
		<< std::setw(10) << std::left << "Credits" << std::setw(5) << std::left << "|"
		<< std::setw(10) << std::left << "Registered" << std::setw(5) << std::left << "|"
		<< std::setw(20) << std::left << "Calendar" << std::endl;
	std::cout << std::setfill('-') << std::setw(140) << std::left << "-" << std::setfill(' ') << std::endl;

	while (cur_stu_course) {
		if (cur_stu_course->stu_course.StuID == loggedinStudent->student.StudentID && cur_stu_course->stu_course.CouID == cur_course->course.ID) {

			std::string registered = std::to_string(cur_course->course.Cur_stdn) + "/" + std::to_string(cur_course->course.Max_stdn);
			std::string fullname = cur_course->course.LNameTeacher + " " + cur_course->course.FNameTeacher;

			std::cout << std::setw(5) << std::left << " " << std::setw(5) << std::left << cur_course->course.No << std::setw(5) << std::left << "|"
				<< std::setw(10) << std::left << cur_course->course.ID << std::setw(5) << std::left << "|"
				<< std::setw(30) << std::left << cur_course->course.CName << std::setw(5) << std::left << "|"
				<< std::setw(25) << std::left << fullname << std::setw(5) << std::left << "|"
				<< std::setw(10) << std::left << cur_course->course.Credits << std::setw(5) << std::left << "|"
				<< std::setw(10) << std::left << registered << std::setw(5) << std::left << "|"
				<< ConvertStringWD(cur_course->course.dayOfWeek) << "-" << ConvertStringSS(cur_course->course.session) << std::endl;
			count++;
			cur_course = cur_course->next;
			cur_stu_course = cur_stu_course->next;
		}
		else if (cur_stu_course->stu_course.StuID == loggedinStudent->student.StudentID && cur_stu_course->stu_course.CouID != cur_course->course.ID) {
			if (cur_course->next)
				cur_course = cur_course->next;
		}
		else {
			cur_course = cur_course->next;
			cur_stu_course = cur_stu_course->next;
		}
	}

	if (count == 0) {
		std::cout << "You haven't registered any course " << std::endl;
		return 0;
	}
	std::system("pause");
	return 1;
}

void DeleteRegisteredCourse(STU_COURSE_NODE*& stu_course, STU_NODE* loggedinStudent, CR_NODE* course, STU_NODE* student, STFF_NODE* teacher) {
	std::system("cls");
	char check;
	std::string courseID;
	STU_COURSE_NODE* cur_stu_node = stu_course;
	CR_NODE* cur_course = course;

	if (!ViewSchedule(stu_course, loggedinStudent, course)) {
		std::system("pause");
		return;
	}
	std::cout << "\n\n";
	std::cout << "Enter the ID of the course you want to delete: ";
	std::cin >> courseID;

	while (cur_stu_node) {
		if (cur_stu_node->stu_course.CouID == courseID && cur_stu_node->stu_course.StuID == loggedinStudent->student.StudentID) {
			std::cout << "Are you sure you want to delete this course? (y/n): ";
			std::cin >> check;
			if (check == 'y' || check == 'Y') {
				STU_COURSE_NODE* tmp = new STU_COURSE_NODE;
				tmp = cur_stu_node;
				if (tmp == stu_course) {
					stu_course = stu_course->next;
					stu_course->prev = nullptr;
					delete tmp;
				}
				else {
					tmp->prev->next = tmp->next;
					if (tmp->next)
						tmp->next->prev = tmp->prev;
					cur_stu_node = cur_stu_node->prev;
					delete tmp;
				}
				Read_After_Update_Student_Course(student, course, teacher, stu_course);
				std::system("cls");
				std::cout << "Delete successfully" << std::endl;
				std::system("pause");
				return;
			}
			else
				return;
		}
		else
			cur_stu_node = cur_stu_node->next;
	}
	std::cout << "The course ID you entered is incorrect" << std::endl;
	std::system("pause");
	return;
}


//Update student
void UpdateStudentInfo(STU_NODE*& student, STU_NODE*& loggedinStudent) {
AGAIN:
	int x_boxStudent = 5;
	int y_boxStudent = 2;
	int width_boxStudent = 42;
	int height_boxStudent = 2;

	char check;
	std::string tmp;
	int tmp_width = 60;
	int box_width = 32;
	my_print(tmp_width, 1, LIGHT_YELLOW, "Update your personal information.");

	std::string option_1[] = { "1. Update your gender.",
			"2. Update your date of birth.",
			"3. Update your social ID.",
			"0. Come back." };

	int x_boxOption1 = x_boxStudent + width_boxStudent + 2;
	int y_boxOption1 = y_boxStudent;
	int width_boxOption1 = 50;
	int height_boxOption1 = 3;
	int amount_option1 = sizeof(option_1) / sizeof(option_1[0]);
	int choose;
	choose = menu(x_boxOption1, y_boxOption1, width_boxOption1, height_boxOption1, amount_option1, option_1, WHITE, LIGHT_YELLOW, LIGHT_GREEN);

	if (choose == 1) {
		system("cls");
		ShowCur(1);
		int width_tmp1 = 50;
		int height_tmp1 = 10;
		int width_box1 = 40;
		int height_box1 = 2;

		my_print(width_tmp1, height_tmp1, YELLOW, "Enter the gender you want to update to: ");
		box(width_tmp1, height_tmp1 + 1, width_box1, height_box1, YELLOW);

		gotoXY(width_tmp1 + 1, height_tmp1 + 2);
		tmp = my_getline(width_box1 - 1);

		my_print(width_tmp1, height_tmp1 + 5, RED, "Are you sure you want to change to this gender? (y/n): ");
		std::cin >> check;
		gotoXY(width_tmp1, height_tmp1 + 17);
		std::cin.ignore();
		if (check == 'y' || check == 'Y') {
			loggedinStudent->student.Gender = tmp;
			Read_After_Update_Students(student);
			system("cls");
		}
		else
		system("cls"); 
		goto AGAIN;
	}
	else if (choose == 2) {
		system("cls");
		ShowCur(1);
		int width_tmp1 = 50;
		int height_tmp1 = 10;
		int width_box1 = 40;
		int height_box1 = 2;

		my_print(width_tmp1, height_tmp1, YELLOW, "Enter date of birth which you want to update (dd/mm/yyyy): ");
		box(width_tmp1, height_tmp1 + 1, width_box1, height_box1, YELLOW);

		int day, month, year;
		gotoXY(width_tmp1 + 1, height_tmp1 + 2);
		std::cin >> day >> month >> year;

		my_print(width_tmp1, height_tmp1 + 5, RED, "Are you sure you want to change to this date? (y/n): ");
		std::cin >> check;
		gotoXY(width_tmp1, height_tmp1 + 17);
		std::cin.ignore();
		if (check == 'y' || check == 'Y') {
			loggedinStudent->student.DoB.day = day;
			loggedinStudent->student.DoB.month = month;
			loggedinStudent->student.DoB.year = year;
			Read_After_Update_Students(student);
			system("cls");
		}
		else
		system("cls");  
		goto AGAIN;
	}
	else if (choose == 3) {
		system("cls");
		ShowCur(1);
		int width_tmp1 = 50;
		int height_tmp1 = 10;
		int width_box1 = 40;
		int height_box1 = 2;

		my_print(width_tmp1, height_tmp1, YELLOW, "Enter social ID which you want to update: ");
		box(width_tmp1, height_tmp1 + 1, width_box1, height_box1, YELLOW);

		gotoXY(width_tmp1 + 1, height_tmp1 + 2);
		tmp = my_getline(width_box1 - 1);

		my_print(width_tmp1, height_tmp1 + 5, RED, "Are you sure you want to change to this ID? (y/n): ");
		std::cin >> check;
		gotoXY(width_tmp1, height_tmp1 + 17);
		std::cin.ignore();
		if (check == 'y' || check == 'Y') {
			loggedinStudent->student.SocialID = tmp;
			Read_After_Update_Students(student);
			system("cls");
		}
		else
		system("cls");  
		goto AGAIN;
	}
	else if (choose == 4) {
		return;
	}
	else {
		std::cout << "Invalid selection, please enter again.\n\n";
		std::system("pause");
		UpdateStudentInfo(student, loggedinStudent);
	}
}

void UpdateTeacherInfor(std::string teacherID, STFF_NODE*& teacher) {
	STFF_NODE* cur = teacher;
	std::string tmp;
	int check = 0;
	std::system("cls");

	while (cur) {
		if (cur->staff.TeacherID == teacherID) {
			check = 1;
			break;
		}
		cur = cur->next;
	}

	if (check == 0) {
		std::cout << "Your ID is invalid, please type again" << std::endl;
		return;
	}

	printInformation_A_Staff(cur);
	std::cout << "\n\nWhat do you want to update? " << std::endl;

	int choice;
	std::cout << "\n\t1. Update gender."
		<< "\n\t2. Update date of birth."
		<< "\n\t3. Update social ID."
		<< "\n\t4. Update Faculty."
		<< "\n\t0. Come back.";
	std::cout << "\n\nEnter select the option you want to choose: ";
	std::cin >> choice;

	if (choice == 1) {
		std::cout << "\nEnter gender which you want to update: ";
		std::cin.ignore();
		std::getline(std::cin, tmp);
		std::cout << "Are you sure you want to change? (y/n): ";
		std::cin >> check;
		if (check == 'y' || check == 'Y') {
			cur->staff.Gender = tmp;
			Read_After_Update_Teachers(teacher);
		}
		UpdateTeacherInfor(teacherID, teacher);
	}
	else if (choice == 2) {
		std::cout << "\nEnter date of birth which you want to update (dd mm yyyy): ";
		int day, month, year;
		std::cin >> day >> month >> year;
		std::cout << "Are you sure you want to change? (y/n): ";
		std::cin >> check;
		if (check == 'y' || check == 'Y') {
			cur->staff.DoB.day = day;
			cur->staff.DoB.month = month;
			cur->staff.DoB.year = year;
			Read_After_Update_Teachers(teacher);
		}
		UpdateTeacherInfor(teacherID, teacher);
	}
	else if (choice == 3) {
		std::cout << "\nEnter social ID which you want to update: ";
		std::cin.ignore();
		std::getline(std::cin, tmp);
		std::cout << "Are you sure you want to change? (y/n): ";
		std::cin >> check;
		if (check == 'y' || check == 'Y') {
			cur->staff.SocialID = tmp;
			Read_After_Update_Teachers(teacher);
		}
		UpdateTeacherInfor(teacherID, teacher);
	}
	else if (choice == 4) {
		std::cout << "\nEnter your new faculty: ";
		std::cin.ignore();
		std::getline(std::cin, tmp);
		std::cout << "Are you sure you want to change? (y/n): ";
		std::cin >> check;
		if (check == 'y' || check == 'Y') {
			cur->staff.Faculty = tmp;
			Read_After_Update_Teachers(teacher);
		}
		UpdateTeacherInfor(teacherID, teacher);
	}
	else if (choice == 0) {
		return;
	}
	else {
		std::cout << "Invalid selection, please enter again.\n\n";
		std::system("pause");
		UpdateTeacherInfor(teacherID, teacher);
	}
}

void UpdateYourInfor(STFF_NODE* loggedinStaff, STFF_NODE*& teacher) {
	STFF_NODE* cur = teacher;
	char check;
	std::string tmp;

	std::system("cls");
	printInformation_A_Staff(loggedinStaff);


	while (cur) {
		if (cur->staff.TeacherID == loggedinStaff->staff.TeacherID)
			break;
		else
			cur = cur->next;
	}

	std::cout << "\n\nWhat do you want to update? " << std::endl;

	int choice;
	std::cout << "\n\t1. Update gender."
		<< "\n\t2. Update date of birth."
		<< "\n\t3. Update social ID."
		<< "\n\t4. Update Faculty."
		<< "\n\t0. Come back.";
	std::cout << "\n\nEnter select the option you want to choose: ";
	std::cin >> choice;

	if (choice == 1) {
		std::cout << "\nEnter gender which you want to update: ";
		std::cin.ignore();
		std::getline(std::cin, tmp);
		std::cout << "Are you sure you want to change? (y/n): ";
		std::cin >> check;
		if (check == 'y' || check == 'Y') {
			cur->staff.Gender = tmp;
			Read_After_Update_Teachers(teacher);
		}
		UpdateYourInfor(loggedinStaff, teacher);
	}
	else if (choice == 2) {
		std::cout << "\nEnter date of birth which you want to update (dd mm yyyy): ";
		int day, month, year;
		std::cin >> day >> month >> year;
		std::cout << "Are you sure you want to change? (y/n): ";
		std::cin >> check;
		if (check == 'y' || check == 'Y') {
			cur->staff.DoB.day = day;
			cur->staff.DoB.month = month;
			cur->staff.DoB.year = year;
			Read_After_Update_Teachers(teacher);
		}
		UpdateYourInfor(loggedinStaff, teacher);
	}
	else if (choice == 3) {
		std::cout << "\nEnter social ID which you want to update: ";
		std::cin.ignore();
		std::getline(std::cin, tmp);
		std::cout << "Are you sure you want to change? (y/n): ";
		std::cin >> check;
		if (check == 'y' || check == 'Y') {
			cur->staff.SocialID = tmp;
			Read_After_Update_Teachers(teacher);
		}
		UpdateYourInfor(loggedinStaff, teacher);
	}
	else if (choice == 4) {
		std::cout << "\nEnter your new faculty: ";
		std::cin.ignore();
		std::getline(std::cin, tmp);
		std::cout << "Are you sure you want to change? (y/n): ";
		std::cin >> check;
		if (check == 'y' || check == 'Y') {
			cur->staff.Faculty = tmp;
			Read_After_Update_Teachers(teacher);
		}
		UpdateYourInfor(loggedinStaff, teacher);
	}
	else if (choice == 0) {
		return;
	}
	else {
		std::cout << "Invalid selection, please enter again.\n\n";
		std::system("pause");
		UpdateYourInfor(loggedinStaff, teacher);
	}
}

void Create_newStaff(STFF_NODE* staff) {
	std::system("cls");
	STFF_NODE* NewStaff = new STFF_NODE;
	STFF_NODE* cur = staff;
	while (cur->next) {
		cur = cur->next;
	}
	//create new staff account

	if (!cur) {
		NewStaff->staff.No_Staff = 1;
	}
	else {
		int NewNo = cur->staff.No_Staff;
		NewNo++;
		NewStaff->staff.No_Staff = NewNo;
	}
	std::string NewLName;
	std::cout << "Enter The Staff's Last Name: ";
	std::getline(std::cin, NewLName);
	NewStaff->staff.LName = NewLName;
	std::string NewFName;
	std::cout << "Enter The Staff's First Name: ";
	std::getline(std::cin, NewFName);
	NewStaff->staff.FName = NewFName;
	std::string NewGender;
	std::cout << "Enter The Staff's Gender: ";
	std::getline(std::cin, NewGender);
	NewStaff->staff.Gender = NewGender;

	std::string NewSocialID;
	std::cout << "Enter Staff's Social ID: ";
	std::getline(std::cin, NewSocialID);
	NewStaff->staff.SocialID = NewSocialID;
	std::string NewID;
	std::cout << "Enter Staff's ID (This will be the login username): ";
	std::getline(std::cin, NewID);
	NewStaff->staff.TeacherID = NewID;
	std::string NewPass;
	std::cout << "Enter Staff's Password: ";
	std::getline(std::cin, NewPass);
	NewStaff->staff.Password = NewPass;

	std::string NewFaculty;
	std::cout << "Enter Staff's Faculty: ";
	std::getline(std::cin, NewFaculty);
	NewStaff->staff.Faculty = NewFaculty;

	std::cout << "Enter Staff's Date of Birth (Please seperate with spaces) (dd/mm/yyyy)";
	std::cin >> NewStaff->staff.DoB.day >> NewStaff->staff.DoB.month >> NewStaff->staff.DoB.year;

	//Add course at the end
	cur->next = NewStaff;
	NewStaff->prev = cur;

	std::system("cls");
	std::cout << "Added Staff Successfully\n";
	Read_After_Update_Staffs(staff);
	std::system("pause");
	return;
}

//Roke additional function
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

void ResultRegistration(STU_COURSE_NODE* stu_course, STU_NODE* loggedinStudent, CR_NODE* course) {
	std::system("cls");
	STU_COURSE_NODE* cur_stu_course = stu_course;
	CR_NODE* cur_course = course;
	int count = 0;

	std::cout << "===============================================================YOUR COURSES RESULTS=====================================================================\n\n";
	std::cout << std::setw(3) << std::left << " " << std::setw(5) << std::left << "No" << std::setw(5) << std::left << "|"
		<< std::setw(10) << std::left << "Course ID" << std::setw(5) << std::left << "|"
		<< std::setw(25) << std::left << "Course name" << std::setw(5) << std::left << "|"
		<< std::setw(16) << std::left << "Teacher name" << std::setw(5) << std::left << "|"
		<< std::setw(8) << std::left << "Credits" << std::setw(5) << std::left << "|"
		<< std::setw(8) << std::left << "Midterm" << std::setw(5) << std::left << "|"
		<< std::setw(8) << std::left << "Final" << std::setw(5) << std::left << "|"
		<< std::setw(8) << std::left << "Other" << std::setw(5) << std::left << "|"
		<< std::setw(8) << std::left << "TOTAL" << std::setw(5) << std::left << "|"
		<< std::setw(8) << std::left << "RANKING" << std::setw(6) << std::left << "|";
	std::cout << "\n";
	std::cout << std::setfill('-') << std::setw(144) << std::left << "-" << std::setfill(' ') << std::endl;
	while (cur_stu_course) {
		if (cur_stu_course->stu_course.StuID == loggedinStudent->student.StudentID) {
			count++;
			std::string fullname = cur_course->course.LNameTeacher + " " + cur_course->course.FNameTeacher;
			std::cout << std::setw(3) << std::left << " " << std::setw(5) << std::left << count << std::setw(5) << std::left << "|"
				<< std::setw(10) << std::left << cur_course->course.ID << std::setw(5) << std::left << "|"
				<< std::setw(25) << std::left << cur_course->course.CName << std::setw(5) << std::left << "|"
				<< std::setw(16) << std::left << fullname << std::setw(5) << std::left << "|"
				<< std::setw(8) << std::left << cur_course->course.Credits << std::setw(5) << std::left << "|"
				<< std::setw(8) << std::left << cur_stu_course->stu_course.midterm << std::setw(5) << std::left << "|"
				<< std::setw(8) << std::left << cur_stu_course->stu_course.final << std::setw(5) << std::left << "|"
				<< std::setw(8) << std::left << cur_stu_course->stu_course.other << std::setw(5) << std::left << "|"
				<< std::setw(8) << std::left << cur_stu_course->stu_course.total << std::setw(5) << std::left << "|"
				<< std::setw(8) << std::left << GetRanking(cur_stu_course->stu_course.total) << std::setw(6) << std::left << "|";
			std::cout << std::endl;
		}
		cur_course = cur_course->next;
		cur_stu_course = cur_stu_course->next;
	}

	if (count == 0) {
		std::cout << "You haven't registered any course " << std::endl;
	}
	std::system("pause");
	return;
}