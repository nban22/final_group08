#include "staff.h"

////4. LOOK UP
//1
void display_list_of_classes(CLASS_NODE* listclass) {
	CLASS_NODE* cur_listclass = listclass;
	int coordinate_x = 30;
	int coordinate_y = 6;

	int width_no = 8;
	int width_classID = 15;
	int width_className = 40;
	int width_schoolYear = 15;
	int tmp = 5;
	int width = width_no + width_classID + width_className + width_schoolYear + tmp * 4;

	textcolor(LIGHT_YELLOW * 16 + BLACK);
	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 40; i++) {
			gotoXY(coordinate_x + width / 2 - 40 / 2 + i, coordinate_y - 4 + j);
			std::cout << " ";
		}
	gotoXY(coordinate_x + width / 2 - 40 / 2 + 13, coordinate_y - 4 + 1);
	std::cout << "LIST OF CLASS";
	textcolor(WHITE);

	gotoXY(coordinate_x, coordinate_y); std::cout << char(218);
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y); std::cout << char(196);
	}
	gotoXY(coordinate_x + width, coordinate_y); std::cout << char(191);

	gotoXY(coordinate_x + width_no + tmp, coordinate_y); std::cout << char(194);
	gotoXY(coordinate_x + width_no + width_classID + 2 * tmp, coordinate_y); std::cout << char(194);
	gotoXY(coordinate_x + width_no + width_classID + width_className + 3 * tmp, coordinate_y); std::cout << char(194);


	gotoXY(coordinate_x, coordinate_y + 1);
	std::cout << std::setw(tmp) << std::left << char(179) << std::setw(width_no) << std::left << "No"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_classID) << std::left << "Class ID"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_className) << std::left << "Class name"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_schoolYear) << std::left << "School year";

	gotoXY(coordinate_x, coordinate_y + 2); std::cout << char(195);
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y + 2); std::cout << char(196);
	}
	gotoXY(coordinate_x + width, coordinate_y + 2); std::cout << char(180);

	gotoXY(coordinate_x + width_no + +tmp, coordinate_y + 2); std::cout << char(197);
	gotoXY(coordinate_x + width_no + width_classID + 2 * tmp, coordinate_y + 2); std::cout << char(197);
	gotoXY(coordinate_x + width_no + width_classID + width_className + 3 * tmp, coordinate_y + 2); std::cout << char(197);


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
		std::cout << std::setw(tmp) << std::left << char(179) << std::setw(width_no) << std::left << no++
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_classID) << std::left << cur_listclass->listclass.ClassID
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_className) << std::left << cur_listclass->listclass.name
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_schoolYear) << std::left << cur_listclass->listclass.schoolYear;

		if (i == 15 || cur_listclass->next == nullptr) {
			gotoXY(coordinate_x, coordinate_y + 2 + i + 1); std::cout << char(192);
			for (int j = coordinate_x + 1; j < coordinate_x + width; j++) {
				gotoXY(j, coordinate_y + 2 + i + 1); std::cout << char(196);
			}
			gotoXY(coordinate_x + width, coordinate_y + 2 + i + 1); std::cout << char(217);

			gotoXY(coordinate_x + width_no + +tmp, coordinate_y + 2 + i + 1); std::cout << char(193);
			gotoXY(coordinate_x + width_no + width_classID + 2 * tmp, coordinate_y + 2 + i + 1); std::cout << char(193);
			gotoXY(coordinate_x + width_no + width_classID + width_className + 3 * tmp, coordinate_y + 2 + i + 1); std::cout << char(193);
		}
		for (int j = coordinate_y + 1; j <= coordinate_y + i + 2; j++)
			if (j != coordinate_y + 2) {
				gotoXY(coordinate_x, j); std::cout << char(179);
				gotoXY(coordinate_x + width, j); std::cout << char(179);
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
void view_list_of_classes(CLASS_NODE*& listclass, STU_NODE* student) {
	std::system("cls");
	update_list_of_classes(listclass, student);
	display_list_of_classes(listclass);
}
//2
void display_list_students_of_class(STU_NODE*& student, std::string classID) {
	int coordinate_x = 20;
	int coordinate_y = 5;

	int width_no = 5;
	int width_studentID = 15;
	int width_lastName = 20;
	int width_firstName = 12;
	int width_gender = 10;
	int width_DOB = 15;
	int width_socialID = 16;
	int tmp = 4;

	int width = width_no + width_studentID + width_lastName + width_firstName + width_gender + width_DOB + width_socialID + tmp * 7;

	textcolor(LIGHT_YELLOW * 16 + BLACK);
	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 40; i++) {
			gotoXY(coordinate_x + width / 2 - 40 / 2 + i, coordinate_y - 4 + j);
			std::cout << " ";
		}
	gotoXY(coordinate_x + width / 2 - 40 / 2 + 5, coordinate_y - 4 + 1);
	std::cout << "LIST STUDENTS OF CLASS " + classID;
	textcolor(WHITE);

	gotoXY(coordinate_x, coordinate_y); std::cout << char(218);
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y); std::cout << char(196);
	}
	gotoXY(coordinate_x + width, coordinate_y); std::cout << char(191);

	gotoXY(coordinate_x + width_no + tmp, coordinate_y); std::cout << char(194);
	gotoXY(coordinate_x + width_no + width_studentID + 2 * tmp, coordinate_y); std::cout << char(194);
	gotoXY(coordinate_x + width_no + width_studentID + width_lastName + 3 * tmp, coordinate_y); std::cout << char(194);
	gotoXY(coordinate_x + width_no + width_studentID + width_lastName + width_firstName + 4 * tmp, coordinate_y); std::cout << char(194);
	gotoXY(coordinate_x + width_no + width_studentID + width_lastName + width_firstName + width_gender + 5 * tmp, coordinate_y); std::cout << char(194);
	gotoXY(coordinate_x + width_no + width_studentID + width_lastName + width_firstName + width_gender + width_DOB + 6 * tmp, coordinate_y); std::cout << char(194);

	gotoXY(coordinate_x, coordinate_y + 1);
	std::cout
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_no) << std::left << "No"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_studentID) << std::left << "Student ID"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_lastName) << std::left << "Last name"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_firstName) << std::left << "First name"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_gender) << std::left << "Gender"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_DOB) << std::left << "Date of birth"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_socialID) << std::left << "social ID";

	gotoXY(coordinate_x, coordinate_y + 2); std::cout << char(195);
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y + 2); std::cout << char(196);
	}
	gotoXY(coordinate_x + width, coordinate_y + 2); std::cout << char(180);

	gotoXY(coordinate_x + width_no + tmp, coordinate_y + 2); std::cout << char(197);
	gotoXY(coordinate_x + width_no + width_studentID + 2 * tmp, coordinate_y + 2); std::cout << char(197);
	gotoXY(coordinate_x + width_no + width_studentID + width_lastName + 3 * tmp, coordinate_y + 2); std::cout << char(197);
	gotoXY(coordinate_x + width_no + width_studentID + width_lastName + width_firstName + 4 * tmp, coordinate_y + 2); std::cout << char(197);
	gotoXY(coordinate_x + width_no + width_studentID + width_lastName + width_firstName + width_gender + 5 * tmp, coordinate_y + 2); std::cout << char(197);
	gotoXY(coordinate_x + width_no + width_studentID + width_lastName + width_firstName + width_gender + width_DOB + 6 * tmp, coordinate_y + 2); std::cout << char(197);

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
		std::cout
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_no) << std::left << no++
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_studentID) << std::left << cur_list_student->student.StudentID
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_lastName) << std::left << cur_list_student->student.LName
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_firstName) << std::left << cur_list_student->student.FName
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_gender) << std::left << cur_list_student->student.Gender
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_DOB) << std::left << DOB
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_socialID) << std::left << cur_list_student->student.SocialID;

		if (i == 15 || cur_list_student->next == nullptr) {
			gotoXY(coordinate_x, coordinate_y + 2 + i + 1); std::cout << char(192);
			for (int j = coordinate_x + 1; j < coordinate_x + width; j++) {
				gotoXY(j, coordinate_y + 2 + i + 1); std::cout << char(196);
			}
			gotoXY(coordinate_x + width, coordinate_y + 2 + i + 1); std::cout << char(217);
		}

		gotoXY(coordinate_x + width_no + tmp, coordinate_y + 2 + i + 1); std::cout << char(193);
		gotoXY(coordinate_x + width_no + width_studentID + 2 * tmp, coordinate_y + 2 + i + 1); std::cout << char(193);
		gotoXY(coordinate_x + width_no + width_studentID + width_lastName + 3 * tmp, coordinate_y + 2 + i + 1); std::cout << char(193);
		gotoXY(coordinate_x + width_no + width_studentID + width_lastName + width_firstName + 4 * tmp, coordinate_y + 2 + i + 1); std::cout << char(193);
		gotoXY(coordinate_x + width_no + width_studentID + width_lastName + width_firstName + width_gender + 5 * tmp, coordinate_y + 2 + i + 1); std::cout << char(193);
		gotoXY(coordinate_x + width_no + width_studentID + width_lastName + width_firstName + width_gender + width_DOB + 6 * tmp, coordinate_y + 2 + i + 1); std::cout << char(193);

		for (int j = coordinate_y + 1; j <= coordinate_y + i + 2; j++)
			if (j != coordinate_y + 2) {
				gotoXY(coordinate_x, j); std::cout << char(179);
				gotoXY(coordinate_x + width, j); std::cout << char(179);
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
void view_list_students_of_class(STU_NODE* student, CLASS_NODE* listclass) {
	std::string classID;
	int coordinate_x = 35;
	int coordinate_y = 27;
	int width_box = 30;
	int height_box = 2;
	std::system("cls");
	display_list_of_classes(listclass);
enter_classID:
	my_print(coordinate_x, coordinate_y, YELLOW * 16 + BLACK, "Enter class ID which you want to open: ");
	box(coordinate_x, coordinate_y + 1, width_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 1, coordinate_y + 2);
	ShowCur(1);
	classID = my_getline(width_box - 1);
	ShowCur(0);
	if (classID == "-1")
		return;

	if (check_exist_class_node_in_DLL(listclass, classID) == nullptr) {
		my_print(coordinate_x + 50, coordinate_y, RED * 16 + WHITE, "Your selection doesn't exist.");
		my_print(coordinate_x + 50, coordinate_y + 2, LIGHT_GREEN * 16 + BLACK, "Do you want to enter agagin:");
		int choice = enter_again_yes_no(coordinate_x + 50 + 3, coordinate_y + 3, 7, 3, 4, LIGHT_AQUA, YELLOW);
		if (choice == 1) {
			textcolor(BLACK * 16 + BLACK);
			for (int j = 0; j < 5 + 2; j++)
				for (int i = 0; i < 70 + 9; i++) {
					gotoXY(coordinate_x + i, coordinate_y + j);
					std::cout << " ";
				}
			textcolor(WHITE);
			goto enter_classID;
		}
		else return;
	}
	std::system("cls");
	display_list_students_of_class(student, classID);
}
//3
void view_list_of_courses(CR_NODE* course) {
	std::system("cls");
	int coordinate_x = 9;
	int coordinate_y = 5;

	int width_no = 5;
	int width_schoolYear = 11;
	int width_semester = 5;
	int width_courseID = 10;
	int width_courseName = 26;
	int width_teacherName = 23;
	int width_credits = 9;
	int width_registered = 10;
	int width_calendar = 18;
	int tmp = 3;

	int width = width_no + width_schoolYear + width_semester + width_courseID + width_courseName + width_teacherName + width_credits
		+ width_registered + width_calendar + tmp * 8;

	textcolor(LIGHT_YELLOW * 16 + BLACK);
	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 40; i++) {
			gotoXY(coordinate_x + width / 2 - 40 / 2 + i, coordinate_y - 4 + j);
			std::cout << " ";
		}
	gotoXY(coordinate_x + width / 2 - 40 / 2 + 12, coordinate_y - 4 + 1);
	std::cout << "LIST OF COURSES";
	textcolor(WHITE);

	gotoXY(coordinate_x, coordinate_y); std::cout << char(218);
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y); std::cout << char(196);
	}
	gotoXY(coordinate_x + width, coordinate_y); std::cout << char(191);

	gotoXY(coordinate_x + width_no + tmp, coordinate_y); std::cout << char(194);
	gotoXY(coordinate_x + width_no + width_schoolYear + 2 * tmp, coordinate_y); std::cout << char(194);
	gotoXY(coordinate_x + width_no + width_schoolYear + width_semester + 3 * tmp, coordinate_y); std::cout << char(194);
	gotoXY(coordinate_x + width_no + width_schoolYear + width_semester + width_courseID + 4 * tmp, coordinate_y); std::cout << char(194);
	gotoXY(coordinate_x + width_no + width_schoolYear + width_semester + width_courseID + width_courseName + 5 * tmp, coordinate_y); std::cout << char(194);
	gotoXY(coordinate_x + width_no + width_schoolYear + width_semester + width_courseID + width_courseName + width_teacherName + 6 * tmp, coordinate_y); std::cout << char(194);
	gotoXY(coordinate_x + width_no + width_schoolYear + width_semester + width_courseID + width_courseName + width_teacherName + width_credits + 7 * tmp, coordinate_y); std::cout << char(194);
	gotoXY(coordinate_x + width_no + width_schoolYear + width_semester + width_courseID + width_courseName + width_teacherName + width_credits + width_registered + 8 * tmp, coordinate_y); std::cout << char(194);

	gotoXY(coordinate_x, coordinate_y + 1);
	std::cout << std::setw(tmp) << std::left << char(179) << std::setw(width_no) << std::left << "No"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_schoolYear) << std::left << "School year"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_semester) << std::left << "Sem"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_courseID) << std::left << "Course ID"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_courseName) << std::left << "Course name"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_teacherName) << std::left << "Teacher name"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_credits) << std::left << "Credits"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_registered) << std::left << "Registered"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_calendar) << std::left << "Calendar";

	gotoXY(coordinate_x, coordinate_y + 2); std::cout << char(195);
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y + 2); std::cout << char(196);
	}
	gotoXY(coordinate_x + width, coordinate_y + 2); std::cout << char(180);

	gotoXY(coordinate_x + width_no + tmp, coordinate_y + 2); std::cout << char(197);
	gotoXY(coordinate_x + width_no + width_schoolYear + 2 * tmp, coordinate_y + 2); std::cout << char(197);
	gotoXY(coordinate_x + width_no + width_schoolYear + width_semester + 3 * tmp, coordinate_y + 2); std::cout << char(197);
	gotoXY(coordinate_x + width_no + width_schoolYear + width_semester + width_courseID + 4 * tmp, coordinate_y + 2); std::cout << char(197);
	gotoXY(coordinate_x + width_no + width_schoolYear + width_semester + width_courseID + width_courseName + 5 * tmp, coordinate_y + 2); std::cout << char(197);
	gotoXY(coordinate_x + width_no + width_schoolYear + width_semester + width_courseID + width_courseName + width_teacherName + 6 * tmp, coordinate_y + 2); std::cout << char(197);
	gotoXY(coordinate_x + width_no + width_schoolYear + width_semester + width_courseID + width_courseName + width_teacherName + width_credits + 7 * tmp, coordinate_y + 2); std::cout << char(197);
	gotoXY(coordinate_x + width_no + width_schoolYear + width_semester + width_courseID + width_courseName + width_teacherName + width_credits + width_registered + 8 * tmp, coordinate_y + 2); std::cout << char(197);

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
		std::cout
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_no) << std::left << no++
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_schoolYear) << std::left << cur_course->course.Schoolyear
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_semester) << std::left << cur_course->course.Semester
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_courseID) << std::left << cur_course->course.ID
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_courseName) << std::left << cur_course->course.CName
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_teacherName) << std::left << fullname
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_credits) << std::left << cur_course->course.Credits
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_registered) << std::left << registered
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_calendar) << std::left << calendar;

		if (i == 15 || cur_course->next == nullptr) {
			gotoXY(coordinate_x, coordinate_y + 2 + i + 1); std::cout << char(192);
			for (int j = coordinate_x + 1; j < coordinate_x + width; j++) {
				gotoXY(j, coordinate_y + 2 + i + 1); std::cout << char(196);
			}
			gotoXY(coordinate_x + width, coordinate_y + 2 + i + 1); std::cout << char(217);
		}

		gotoXY(coordinate_x + width_no + tmp, coordinate_y + 2 + i + 1); std::cout << char(193);
		gotoXY(coordinate_x + width_no + width_schoolYear + 2 * tmp, coordinate_y + 2 + i + 1); std::cout << char(193);
		gotoXY(coordinate_x + width_no + width_schoolYear + width_semester + 3 * tmp, coordinate_y + 2 + i + 1); std::cout << char(193);
		gotoXY(coordinate_x + width_no + width_schoolYear + width_semester + width_courseID + 4 * tmp, coordinate_y + 2 + i + 1); std::cout << char(193);
		gotoXY(coordinate_x + width_no + width_schoolYear + width_semester + width_courseID + width_courseName + 5 * tmp, coordinate_y + 2 + i + 1); std::cout << char(193);
		gotoXY(coordinate_x + width_no + width_schoolYear + width_semester + width_courseID + width_courseName + width_teacherName + 6 * tmp, coordinate_y + 2 + i + 1); std::cout << char(193);
		gotoXY(coordinate_x + width_no + width_schoolYear + width_semester + width_courseID + width_courseName + width_teacherName + width_credits + 7 * tmp, coordinate_y + 2 + i + 1); std::cout << char(193);
		gotoXY(coordinate_x + width_no + width_schoolYear + width_semester + width_courseID + width_courseName + width_teacherName + width_credits + width_registered + 8 * tmp, coordinate_y + 2 + i + 1); std::cout << char(193);

		for (int j = coordinate_y + 1; j <= coordinate_y + i + 2; j++)
			if (j != coordinate_y + 2) {
				gotoXY(coordinate_x, j); std::cout << char(179);
				gotoXY(coordinate_x + width, j); std::cout << char(179);
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
//4
void display_list_students_of_course(STU_COURSE_NODE* stu_course, STU_NODE* student, std::string CourseID) {
	int coordinate_x = 20;
	int coordinate_y = 5;

	int width_no = 5;
	int width_studentID = 15;
	int width_studentName = 30;
	int width_gender = 10;
	int width_DOB = 15;
	int socialID = 15;
	int tmp = 5;

	int width = width_no + width_studentID + width_studentName + width_gender + width_DOB + socialID + tmp * 6;

	textcolor(LIGHT_YELLOW * 16 + BLACK);
	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 40; i++) {
			gotoXY(coordinate_x + width / 2 - 40 / 2 + i, coordinate_y - 4 + j);
			std::cout << " ";
		}
	gotoXY(coordinate_x + width / 2 - 40 / 2 + 5, coordinate_y - 4 + 1);
	std::cout << "LIST STUDENTS OF COURSE " + CourseID;
	textcolor(WHITE);

	gotoXY(coordinate_x, coordinate_y); std::cout << char(218);
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y); std::cout << char(196);
	}
	gotoXY(coordinate_x + width, coordinate_y); std::cout << char(191);

	gotoXY(coordinate_x + width_no + tmp, coordinate_y); std::cout << char(194);
	gotoXY(coordinate_x + width_no + width_studentID + 2 * tmp, coordinate_y); std::cout << char(194);
	gotoXY(coordinate_x + width_no + width_studentID + width_studentName + 3 * tmp, coordinate_y); std::cout << char(194);
	gotoXY(coordinate_x + width_no + width_studentID + width_studentName + width_gender + 4 * tmp, coordinate_y); std::cout << char(194);
	gotoXY(coordinate_x + width_no + width_studentID + width_studentName + width_gender + width_DOB + 5 * tmp, coordinate_y); std::cout << char(194);

	gotoXY(coordinate_x, coordinate_y + 1);
	std::cout
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_no) << std::left << "No"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_studentID) << std::left << "Student ID"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_studentName) << std::left << "Student's name"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_gender) << std::left << "Gender"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_DOB) << std::left << "Date of birth"
		<< std::setw(tmp) << std::left << char(179) << std::setw(socialID) << std::left << "Social ID";

	gotoXY(coordinate_x, coordinate_y + 2); std::cout << char(195);
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y + 2); std::cout << char(196);
	}
	gotoXY(coordinate_x + width, coordinate_y + 2); std::cout << char(180);

	gotoXY(coordinate_x + width_no + tmp, coordinate_y + 2); std::cout << char(197);
	gotoXY(coordinate_x + width_no + width_studentID + 2 * tmp, coordinate_y + 2); std::cout << char(197);
	gotoXY(coordinate_x + width_no + width_studentID + width_studentName + 3 * tmp, coordinate_y + 2); std::cout << char(197);
	gotoXY(coordinate_x + width_no + width_studentID + width_studentName + width_gender + 4 * tmp, coordinate_y + 2); std::cout << char(197);
	gotoXY(coordinate_x + width_no + width_studentID + width_studentName + width_gender + width_DOB + 5 * tmp, coordinate_y + 2); std::cout << char(197);


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

		STU_NODE* tmp_student = getInformationByStudentID(cur_list_course->stu_course.StuID, student);
		std::string DoB = std::to_string(tmp_student->student.DoB.day / 10) + std::to_string(tmp_student->student.DoB.day % 10) + "/"
			+ std::to_string(tmp_student->student.DoB.month / 10) + std::to_string(tmp_student->student.DoB.month % 10) + "/"
			+ std::to_string(tmp_student->student.DoB.year);
		std::string fullname = tmp_student->student.LName + " " + tmp_student->student.FName;
		std::cout
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_no) << std::left << no++
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_studentID) << std::left << cur_list_course->stu_course.StuID
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_studentName) << std::left << fullname
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_gender) << std::left << tmp_student->student.Gender
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_DOB) << std::left << DoB
			<< std::setw(tmp) << std::left << char(179) << std::setw(socialID) << std::left << tmp_student->student.SocialID;

		if (i == 15 || cur_list_course->next == nullptr) {
			gotoXY(coordinate_x, coordinate_y + 2 + i + 1); std::cout << char(192);
			for (int j = coordinate_x + 1; j < coordinate_x + width; j++) {
				gotoXY(j, coordinate_y + 2 + i + 1); std::cout << char(196);
			}
			gotoXY(coordinate_x + width, coordinate_y + 2 + i + 1); std::cout << char(217);
		}

		gotoXY(coordinate_x + width_no + tmp, coordinate_y + 2 + i + 1); std::cout << char(193);
		gotoXY(coordinate_x + width_no + width_studentID + 2 * tmp, coordinate_y + 2 + i + 1); std::cout << char(193);
		gotoXY(coordinate_x + width_no + width_studentID + width_studentName + 3 * tmp, coordinate_y + 2 + i + 1); std::cout << char(193);
		gotoXY(coordinate_x + width_no + width_studentID + width_studentName + width_gender + 4 * tmp, coordinate_y + 2 + i + 1); std::cout << char(193);
		gotoXY(coordinate_x + width_no + width_studentID + width_studentName + width_gender + width_DOB + 5 * tmp, coordinate_y + 2 + i + 1); std::cout << char(193);

		for (int j = coordinate_y + 1; j <= coordinate_y + i + 2; j++)
			if (j != coordinate_y + 2) {
				gotoXY(coordinate_x, j); std::cout << char(179);
				gotoXY(coordinate_x + width, j); std::cout << char(179);
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
void view_list_students_of_course(STU_COURSE_NODE* stu_course, STU_NODE* student, CR_NODE* course) {
	int coordinate_x = 35;
	int coordinate_y = 27;
	int width_box = 30;
	int height_box = 2;
	int check = 0;
	std::string CourseID;

	std::system("cls");
	view_list_of_courses(course);
enter_courseID:
	my_print(coordinate_x, coordinate_y, YELLOW * 16 + BLACK, "Enter Course ID which you want to open: ");
	box(coordinate_x, coordinate_y + 1, width_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 1, coordinate_y + 2);
	ShowCur(1);
	CourseID = (my_getline(width_box - 1));
	ShowCur(0);
	if (CourseID == "-1")
		return;

	CR_NODE* cur = course;
	while (cur) {
		if (cur->course.ID == CourseID)
			check = 1;
		cur = cur->next;
	}
	if (check == 0) {
		my_print(coordinate_x + 50, coordinate_y, RED * 16 + WHITE, "Your selection doesn't exist.");
		my_print(coordinate_x + 50, coordinate_y + 2, LIGHT_GREEN * 16 + BLACK, "Do you want to enter agagin:");
		int choice = enter_again_yes_no(coordinate_x + 50 + 3, coordinate_y + 3, 7, 3, 4, LIGHT_AQUA, YELLOW);
		if (choice == 1) {
			textcolor(BLACK * 16 + BLACK);
			for (int j = 0; j < 5 + 2; j++)
				for (int i = 0; i < 70 + 9; i++) {
					gotoXY(coordinate_x + i, coordinate_y + j);
					std::cout << " ";
				}
			textcolor(WHITE);
			goto enter_courseID;
		}
		else return;
	}
	std::system("cls");
	display_list_students_of_course(stu_course, student, CourseID);
}
//5
void display_scoreboard_in_course(STU_COURSE_NODE* stu_course, STU_NODE* student, std::string CourseID) {
	int coordinate_x = 13;
	int coordinate_y = 5;

	int width_no = 5;
	int width_studentID = 10;
	int width_lastName = 25;
	int width_firstName = 15;
	int width_mark = 10;
	int tmp = 5;

	int width = width_no + width_studentID + width_lastName + width_firstName + 4 * width_mark + tmp * 8;

	textcolor(LIGHT_YELLOW * 16 + BLACK);
	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 40; i++) {
			gotoXY(coordinate_x + width / 2 - 40 / 2 + i, coordinate_y - 4 + j);
			std::cout << " ";
		}
	gotoXY(coordinate_x + width / 2 - 40 / 2 + 5, coordinate_y - 4 + 1);
	std::cout << "LIST STUDENTS OF COURSE " + CourseID;
	textcolor(WHITE);

	gotoXY(coordinate_x, coordinate_y); std::cout << char(218);
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y); std::cout << char(196);
	}
	gotoXY(coordinate_x + width, coordinate_y); std::cout << char(191);

	gotoXY(coordinate_x + width_no + tmp, coordinate_y); std::cout << char(194);
	gotoXY(coordinate_x + width_no + width_studentID + 2 * tmp, coordinate_y); std::cout << char(194);
	gotoXY(coordinate_x + width_no + width_studentID + width_lastName + 3 * tmp, coordinate_y); std::cout << char(194);
	gotoXY(coordinate_x + width_no + width_studentID + width_lastName + width_firstName + 4 * tmp, coordinate_y); std::cout << char(194);
	gotoXY(coordinate_x + width_no + width_studentID + width_lastName + width_firstName + width_mark + 5 * tmp, coordinate_y); std::cout << char(194);
	gotoXY(coordinate_x + width_no + width_studentID + width_lastName + width_firstName + width_mark + width_mark + 6 * tmp, coordinate_y); std::cout << char(194);
	gotoXY(coordinate_x + width_no + width_studentID + width_lastName + width_firstName + width_mark + width_mark + width_mark + 7 * tmp, coordinate_y); std::cout << char(194);

	gotoXY(coordinate_x, coordinate_y + 1);
	std::cout
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_no) << std::left << "No"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_studentID) << std::left << "Student ID"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_lastName) << std::left << "Last name"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_firstName) << std::left << "First name"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_mark) << std::left << "Other"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_mark) << std::left << "Midterm"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_mark) << std::left << "Final"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_mark) << std::left << "Total";

	gotoXY(coordinate_x, coordinate_y + 2); std::cout << char(195);
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y + 2); std::cout << char(196);
	}
	gotoXY(coordinate_x + width, coordinate_y + 2); std::cout << char(180);

	gotoXY(coordinate_x + width_no + tmp, coordinate_y + 2); std::cout << char(197);
	gotoXY(coordinate_x + width_no + width_studentID + 2 * tmp, coordinate_y + 2); std::cout << char(197);
	gotoXY(coordinate_x + width_no + width_studentID + width_lastName + 3 * tmp, coordinate_y + 2); std::cout << char(197);
	gotoXY(coordinate_x + width_no + width_studentID + width_lastName + width_firstName + 4 * tmp, coordinate_y + 2); std::cout << char(197);
	gotoXY(coordinate_x + width_no + width_studentID + width_lastName + width_firstName + width_mark + 5 * tmp, coordinate_y + 2); std::cout << char(197);
	gotoXY(coordinate_x + width_no + width_studentID + width_lastName + width_firstName + width_mark + width_mark + 6 * tmp, coordinate_y + 2); std::cout << char(197);
	gotoXY(coordinate_x + width_no + width_studentID + width_lastName + width_firstName + width_mark + width_mark + width_mark + 7 * tmp, coordinate_y + 2); std::cout << char(197);

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
		STU_NODE* tmp_student = getInformationByStudentID(cur_list_stu_course->stu_course.StuID, student);
		std::cout
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_no) << std::left << no++
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_studentID) << std::left << cur_list_stu_course->stu_course.StuID
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_lastName) << std::left << tmp_student->student.LName
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_firstName) << std::left << tmp_student->student.FName
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_mark) << std::left << cur_list_stu_course->stu_course.other
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_mark) << std::left << cur_list_stu_course->stu_course.midterm
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_mark) << std::left << cur_list_stu_course->stu_course.final
			<< std::setw(tmp) << std::left << char(179) << std::setw(width_mark) << std::left << cur_list_stu_course->stu_course.total;

		if (i == 15 || cur_list_stu_course->next == nullptr) {
			gotoXY(coordinate_x, coordinate_y + 2 + i + 1); std::cout << char(192);
			for (int j = coordinate_x + 1; j < coordinate_x + width; j++) {
				gotoXY(j, coordinate_y + 2 + i + 1); std::cout << char(196);
			}
			gotoXY(coordinate_x + width, coordinate_y + 2 + i + 1); std::cout << char(217);

			gotoXY(coordinate_x + width_no + tmp, coordinate_y + 2 + i + 1); std::cout << char(193);
			gotoXY(coordinate_x + width_no + width_studentID + 2 * tmp, coordinate_y + 2 + i + 1); std::cout << char(193);
			gotoXY(coordinate_x + width_no + width_studentID + width_lastName + 3 * tmp, coordinate_y + 2 + i + 1); std::cout << char(193);
			gotoXY(coordinate_x + width_no + width_studentID + width_lastName + width_firstName + 4 * tmp, coordinate_y + 2 + i + 1); std::cout << char(193);
			gotoXY(coordinate_x + width_no + width_studentID + width_lastName + width_firstName + width_mark + 5 * tmp, coordinate_y + 2 + i + 1); std::cout << char(193);
			gotoXY(coordinate_x + width_no + width_studentID + width_lastName + width_firstName + width_mark + width_mark + 6 * tmp, coordinate_y + 2 + i + 1); std::cout << char(193);
			gotoXY(coordinate_x + width_no + width_studentID + width_lastName + width_firstName + width_mark + width_mark + width_mark + 7 * tmp, coordinate_y + 2 + i + 1); std::cout << char(193);
		}

		for (int j = coordinate_y + 1; j <= coordinate_y + i + 2; j++)
			if (j != coordinate_y + 2) {
				gotoXY(coordinate_x, j); std::cout << char(179);
				gotoXY(coordinate_x + width, j); std::cout << char(179);
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
void view_scoreboard_in_course(CR_NODE* course, STU_COURSE_NODE* stu_course, STU_NODE* student) {
	int coordinate_x = 35;
	int coordinate_y = 27;
	int width_box = 30;
	int height_box = 2;
	int check = 0;
	std::string CourseID;

	std::system("cls");
	view_list_of_courses(course);
enter_courseID:
	my_print(coordinate_x, coordinate_y, YELLOW * 16 + BLACK, "Enter Course ID which you want to open: ");
	box(coordinate_x, coordinate_y + 1, width_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 1, coordinate_y + 2);
	ShowCur(1);
	CourseID = (my_getline(width_box - 1));
	ShowCur(0);
	if (CourseID == "-1")
		return;

	CR_NODE* cur = course;
	while (cur) {
		if (cur->course.ID == CourseID)
			check = 1;
		cur = cur->next;
	}
	if (check == 0) {
		my_print(coordinate_x + 50, coordinate_y, RED * 16 + WHITE, "Your Course ID doesn't exist.");
		my_print(coordinate_x + 50, coordinate_y + 2, LIGHT_GREEN * 16 + BLACK, "Do you want to enter agagin:");
		int choice = enter_again_yes_no(coordinate_x + 50 + 3, coordinate_y + 3, 7, 3, 4, LIGHT_AQUA, YELLOW);
		if (choice == 1) {
			textcolor(BLACK * 16 + BLACK);
			for (int j = 0; j < 5 + 2; j++)
				for (int i = 0; i < 70 + 9; i++) {
					gotoXY(coordinate_x + i, coordinate_y + j);
					std::cout << " ";
				}
			textcolor(WHITE);
			goto enter_courseID;
		}
		else return;
	}
	std::system("cls");
	display_scoreboard_in_course(stu_course, student, CourseID);

}
//6
void display_scoreboard_in_class(STU_COURSE_NODE* stu_course, STU_NODE* student, std::string ClassID) {
	int coordinate_x = 10;
	int coordinate_y = 3;

	int width_no = 5;
	int width_studentID = 10;
	int width_lastName = 25;
	int width_firstName = 15;
	int width_subject = 25;
	int width_mark = 15;

	int width = width_no + width_studentID + width_lastName + width_firstName + width_subject
		+ width_mark + 5 * 6;

	gotoXY(coordinate_x, coordinate_y); std::cout << char(218);
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y); std::cout << char(196);
	}
	gotoXY(coordinate_x + width, coordinate_y); std::cout << char(191);

	/*
		  194
	218	┌  ┬  ┐ 191         197 ┼

	195 ├  ┼  ┤ 180			179 │

	192 └  ┴  ┘ 217			196 ─
		  193
	*/

	gotoXY(coordinate_x, coordinate_y + 1);
	std::cout << std::setw(5) << std::left << char(179) << std::setw(width_no) << std::left << "No" << std::setw(5) << std::left << char(179)
		<< std::setw(width_studentID) << std::left << "Student ID" << std::setw(5) << std::left << char(179)
		<< std::setw(width_lastName) << std::left << "Last name" << std::setw(5) << std::left << char(179)
		<< std::setw(width_firstName) << std::left << "Firse name" << std::setw(5) << std::left << char(179)
		<< std::setw(width_subject) << std::left << "Subject" << std::setw(5) << std::left << char(179)
		<< std::setw(width_mark) << std::left << "Mark" << char(179);
	gotoXY(coordinate_x, coordinate_y + 2); std::cout << char(195);
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y + 2); std::cout << char(196);
	}
	gotoXY(coordinate_x + width, coordinate_y + 2); std::cout << char(180);

	int count = 0;
	STU_NODE* cur_student = student;
	STU_COURSE_NODE* cur = stu_course;
	int i = 0;
	while (cur_student) {
		if (cur_student->student.Classes.ClassID == ClassID) {
			float GPA = 0;
			int count_subject = 0;
			while (cur->stu_course.StuID == cur_student->student.StudentID) {
				gotoXY(coordinate_x, coordinate_y + 2 + ++i);
				std::cout << std::setw(5) << std::left << char(179) << std::setw(5) << std::left << " " << std::setw(5) << std::left << char(179)
					<< std::setw(width_studentID) << std::left << " " << std::setw(5) << std::left << char(179)
					<< std::setw(width_lastName) << std::left << " " << std::setw(5) << std::left << char(179)
					<< std::setw(width_firstName) << std::left << " " << std::setw(5) << std::left << char(179)
					<< std::setw(width_subject) << std::left << cur->stu_course.Cname << std::setw(5) << std::left << char(179)
					<< std::setw(width_mark) << std::left << cur->stu_course.total << char(179);
				GPA += cur->stu_course.total;
				count_subject++;
				cur = cur->next;
			}
			if (count_subject == 0) {
				gotoXY(coordinate_x, coordinate_y + 2 + ++i);
				std::cout << std::setw(5) << std::left << char(179) << std::setw(5) << std::left << ++count << std::setw(5) << std::left << char(179)
					<< std::setw(width_studentID) << std::left << cur_student->student.StudentID << std::setw(5) << std::left << char(179)
					<< std::setw(width_lastName) << std::left << cur_student->student.LName << std::setw(5) << std::left << char(179)
					<< std::setw(width_firstName) << std::left << cur_student->student.FName << std::setw(5) << std::left << char(179)
					<< std::setw(width_subject) << std::left << "GPA" << std::setw(5) << std::left << char(179)
					<< std::setw(width_mark) << std::left << std::fixed << std::setprecision(2) << 0 << char(179);
			}
			else {
				gotoXY(coordinate_x, coordinate_y + 2 + ++i);
				std::cout << std::setw(5) << std::left << char(179) << std::setw(5) << std::left << ++count << std::setw(5) << std::left << char(179)
					<< std::setw(width_studentID) << std::left << cur_student->student.StudentID << std::setw(5) << std::left << char(179)
					<< std::setw(width_lastName) << std::left << cur_student->student.LName << std::setw(5) << std::left << char(179)
					<< std::setw(width_firstName) << std::left << cur_student->student.FName << std::setw(5) << std::left << char(179)
					<< std::setw(width_subject) << std::left << "GPA" << std::setw(5) << std::left << char(179)
					<< std::setw(width_mark) << std::left << std::fixed << std::setprecision(2) << GPA / count_subject << char(179);
			}
			i++;
			gotoXY(coordinate_x, coordinate_y + 2 + i); std::cout << char(195);
			for (int j = coordinate_x + 1; j < coordinate_x + width; j++) {
				gotoXY(j, coordinate_y + 2 + i); std::cout << char(196);
			}
			gotoXY(coordinate_x + width, coordinate_y + 2 + i); std::cout << char(180);

		}
		cur_student = cur_student->next;
	}
	gotoXY(coordinate_x, coordinate_y + 2 + i); std::cout << char(192);
	for (int j = coordinate_x + 1; j < coordinate_x + width; j++) {
		gotoXY(j, coordinate_y + 2 + i); std::cout << char(196);
	}
	gotoXY(coordinate_x + width, coordinate_y + 2 + i); std::cout << char(217);

	gotoXY(whereX() - 2 * width / 3, whereY() + 2);
	system("pause");
}
void view_scoreboard_in_class(STU_COURSE_NODE* stu_course, STU_NODE* student, CLASS_NODE* listclass) {
	int coordinate_x = 35;
	int coordinate_y = 27;
	int width_box = 30;
	int height_box = 2;
	int check = 0;
	std::string ClassID;

	std::system("cls");
	view_list_of_classes(listclass, student);
enter_class_ID:
	my_print(coordinate_x, coordinate_y, YELLOW * 16 + BLACK, "Enter the class ID which you want to open:");
	box(coordinate_x, coordinate_y + 1, width_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 1, coordinate_y + 2);
	ShowCur(1);
	ClassID = (my_getline(width_box - 1));
	ShowCur(0);
	if (ClassID == "-1")
		return;

	if (check_exist_classID_in_DLL(student, ClassID) == nullptr) {
		my_print(coordinate_x + 50, coordinate_y, RED * 16 + WHITE, "Your Class ID doesn't exist.");
		my_print(coordinate_x + 50, coordinate_y + 2, LIGHT_GREEN * 16 + BLACK, "Do you want to enter agagin:");
		int choice = enter_again_yes_no(coordinate_x + 50 + 3, coordinate_y + 3, 7, 3, 4, LIGHT_AQUA, YELLOW);
		if (choice == 1) {
			textcolor(BLACK * 16 + BLACK);
			for (int j = 0; j < 5 + 2; j++)
				for (int i = 0; i < 70 + 9; i++) {
					gotoXY(coordinate_x + i, coordinate_y + j);
					std::cout << " ";
				}
			textcolor(WHITE);
			goto enter_class_ID;
		}
		else return;
	}
	std::system("cls");
	display_scoreboard_in_class(stu_course, student, ClassID);
}

//7
void export_course_students_to_csv(STU_COURSE_NODE* stu_course, CR_NODE* course, STU_NODE* student) {
	std::system("cls");
	view_list_of_courses(course);

	int coordinate_x = 15;
	int coordinate_y = 26;
	int width_box = 30;
	int height_box = 2;

	CR_NODE* cur_course = course;
	STU_COURSE_NODE* cur_stu_course = stu_course;
	int count = 0;
	int check = 0;
	std::string courseID = "0", tmp;


	std::ofstream output;
	int i = 1;
Here_enter_y:
	my_print(coordinate_x, coordinate_y + 1, YELLOW * 16 + BLACK, "Enter course ID for which you want to export:");
	box(coordinate_x, coordinate_y + 1 + 1, width_box, height_box, LIGHT_YELLOW);
	ShowCur(1);
	gotoXY(coordinate_x + 1, coordinate_y + 1 + 2);
	tmp = my_getline(width_box - 1);
	if (tmp == "-1")
		return;
	else
		courseID = tmp;
	cur_course = course;
	while (cur_course) {
		if (cur_course->course.ID == courseID) {
			check = 1;
			break;
		}
		cur_course = cur_course->next;
	}
	if (check == 0) {
		ShowCur(0);
		my_print(coordinate_x + 70, coordinate_y, RED * 16 + LIGHT_AQUA, "Course ID does not exist.");

		my_print(coordinate_x + 70, coordinate_y + 2, LIGHT_GREEN * 16 + BLACK, "Do you want to enter again:");
		int choice_enter = enter_again_yes_no(coordinate_x + 4 + 70, coordinate_y + 4, 8, 3, 4, LIGHT_AQUA, LIGHT_GREEN);
		if (choice_enter == 1) {
			textcolor(BLACK * 16 + BLACK);
			for (int j = 0; j < 8; j++)
				for (int i = 0; i < 107 + 20; i++) {
					gotoXY(coordinate_x + i, coordinate_y + j);
					std::cout << " ";
				}
			textcolor(WHITE);
			goto Here_enter_y;
		}

	}
	else {
		output.open("List_of_students_K22_2_" + cur_course->course.ID + ".csv");
		if (!output.is_open()) {
			std::system("cls");
			std::cout << "cannot open file " << std::endl;
			return;
		}
		output << "No,ID,Last Name,First Name,Gender,Date Of Birth,Social ID,Classes,Class ID";

		while (cur_stu_course) {
			if (cur_stu_course->stu_course.CouID == courseID) {
				STU_NODE* tmp_student = getInformationByStudentID(cur_stu_course->stu_course.StuID, student);
				if (tmp_student == nullptr)
					continue;
				output << "\n" << i++ << ",";
				output << cur_stu_course->stu_course.StuID << ","
					<< tmp_student->student.LName << ","
					<< tmp_student->student.FName << ","
					<< tmp_student->student.Gender << ","
					<< tmp_student->student.DoB.month << "/"
					<< tmp_student->student.DoB.day << "/"
					<< tmp_student->student.DoB.year << ","
					<< tmp_student->student.SocialID << ","
					<< tmp_student->student.Classes.name << ","
					<< tmp_student->student.Classes.ClassID;
			}
			cur_stu_course = cur_stu_course->next;
		}
		output.close();
		ShowCur(0);
		textcolor(LIGHT_GREEN * 16 + BLACK);
		for (int j = 0; j < 3; j++)
			for (int i = 0; i < 41; i++) {
				gotoXY(coordinate_x + width_box + 5 + i, coordinate_y + 1 + 5 - 1 + j);
				std::cout << " ";
			}
		gotoXY(coordinate_x + width_box + 9, coordinate_y + 1 + 5);
		std::cout << "Export to csv file successfully.";
		textcolor(WHITE);
		char ans = _getch();
		return;

	}
}

//8
void export_scoreboard(STU_COURSE_NODE* stu_course, CR_NODE* course, STU_NODE* student) {
	std::system("cls");
	view_list_of_courses(course);
	std::string option[] = { "1. Export all the courses.",
				"2. Export only a course.",
				"0.Come back." };
	int coordinate_x = 20;
	int coordinate_y = 26;
	int width_box = 30;
	int height_box = 2;
	int amount = sizeof(option) / sizeof(option[0]);
	int choice;

	choice = menu(coordinate_x, coordinate_y, width_box, height_box, amount, option, WHITE, LIGHT_YELLOW, LIGHT_GREEN);

	CR_NODE* cur_course = course;
	STU_COURSE_NODE* cur_stu_course = stu_course;
	int count = 0;
	int check = 0;
	std::string courseID = "0", tmp;

	if (choice == 1) {
		while (cur_course) {
			std::ofstream output;
			cur_stu_course = stu_course;
			int i = 1;

			output.open("Scoreboard_K22_2_" + cur_course->course.ID + ".csv");

			if (!output.is_open()) {
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
		my_print(coordinate_x + width_box + 5, coordinate_y + 3, LIGHT_RED, "Export successfully");
		gotoXY(coordinate_x + width_box + 5, coordinate_y + 4);
		std::system("pause");
	}
	else if (choice == 2) {
		std::ofstream output;
		int i = 1;
		//view_list_of_courses(course);
	Here_enter_y:
		my_print(coordinate_x + width_box + 5, coordinate_y + 1, YELLOW * 16 + BLACK, "Enter ID of the course you want to export:");
		box(coordinate_x + width_box + 5, coordinate_y + 1 + 1, width_box, height_box, LIGHT_YELLOW);
		ShowCur(1);
		gotoXY(coordinate_x + width_box + 5 + 1, coordinate_y + 1 + 2);
		tmp = my_getline(width_box - 1);
		if (tmp == "-1")
			return;
		else
			courseID = tmp;
		cur_course = course;
		while (cur_course) {
			if (cur_course->course.ID == courseID) {
				check = 1;
				break;
			}
			cur_course = cur_course->next;
		}
		if (check == 0) {
			ShowCur(0);
			my_print(coordinate_x + width_box + 50, coordinate_y, RED * 16 + LIGHT_AQUA, "Course ID does not exist.");

			my_print(coordinate_x + width_box + 50, coordinate_y + 2, LIGHT_GREEN * 16 + BLACK, "Do you want to enter again:");
			int choice_enter = enter_again_yes_no(coordinate_x + width_box + 4 + 50, coordinate_y + 4, 8, 3, 4, LIGHT_AQUA, LIGHT_GREEN);
			if (choice_enter == 1) {
				textcolor(BLACK * 16 + BLACK);
				for (int j = 0; j < 8; j++)
					for (int i = 0; i < 107; i++) {
						gotoXY(coordinate_x + i, coordinate_y + j);
						std::cout << " ";
					}
				textcolor(WHITE);
				goto Here_enter_y;
			}

		}
		else {
			output.open("Scoreboard_K22_2_" + cur_course->course.ID + ".csv");
			if (!output.is_open()) {
				std::system("cls");
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
			ShowCur(0);
			textcolor(LIGHT_GREEN * 16 + BLACK);
			for (int j = 0; j < 3; j++)
				for (int i = 0; i < 41; i++) {
					gotoXY(coordinate_x + width_box + 5 + i, coordinate_y + 1 + 5 - 1 + j);
					std::cout << " ";
				}
			gotoXY(coordinate_x + width_box + 9, coordinate_y + 1 + 5);
			std::cout << "Export to file successfully.";
			textcolor(WHITE);
			char ans = _getch();
			return;

		}
	}
	else
		return;
}