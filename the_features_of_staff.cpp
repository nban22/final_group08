#include "header.h"

////2. ENTER INFORMATION
//1
void addNew1styearStudent(STU_NODE*& student, CLASS_NODE* listclass, std::string current_school_year) {

	STU_NODE* new_student = new STU_NODE;
	bool check;
	STU_NODE* cur_student = student;

	int coordinate_x = 88;
	int coordinate_y = 7;
	int width_big_box = 40;
	int width_small_box = 10;
	int height_box = 2;

	if (current_school_year == "") {
		system("cls");
		my_print(coordinate_x - 40, coordinate_y + 3, RED, "Please create a new school year before add new students to classes.\n");
		system("pause");
		return;
	}

	do {
		check = 0;
		ShowCur(1);
		//std::system("cls");
		/*viewListOfClasses(listclass, cur_student);*/
		my_print(coordinate_x + 23, coordinate_y - 3, LIGHT_AQUA, "GENERAL INFORMATION");
		my_print(coordinate_x, coordinate_y, LIGHT_AQUA, "Enter class ID:");
		box(coordinate_x + 25, coordinate_y - 1, width_big_box, height_box, LIGHT_AQUA);
	Here_enter_y:
		gotoXY(coordinate_x + 25 + 1, coordinate_y);
		new_student->student.Classes.ClassID = my_getline(width_big_box - 1);
		if (new_student->student.Classes.ClassID == "-1")
			return;
		cur_student = student;
		while (cur_student) {
			if (cur_student->student.Classes.ClassID == new_student->student.Classes.ClassID)
				check = 1;
			cur_student = cur_student->next;
		}
		if (check == 0) {
			my_print(coordinate_x + 3, coordinate_y + 3, RED, "Your class ID which you entered it does not exist.");
			my_print(coordinate_x + 3, coordinate_y + 4, LIGHT_GREEN, "Search for Course again? (y/n): ");
			std::string ans;
			int x_old = whereX();
			int y_old = whereY();
		LOOP_ans:
			gotoXY(x_old, y_old);
			textcolor(WHITE);
			ans = my_getline(1);
			if (ans == "-1")
				return;
			if (ans != "y" && ans != "Y" && ans != "n" && ans != "N") {
				gotoXY(x_old, y_old);
				textcolor(BLACK);
				std::cout << " ";
				goto LOOP_ans;
			}
			if (ans == "y" || ans == "Y") {
				textcolor(BLACK);
				for (int j = 0; j < width_big_box - 1; j++) {
					gotoXY(coordinate_x + 25 + 1 + j, coordinate_y);
					std::cout << " ";
				}
				for (int j = 0; j <= 55; j++) {
					gotoXY(coordinate_x + 3 + j, coordinate_y + 3);
					std::cout << " ";
					gotoXY(coordinate_x + 3 + j, coordinate_y + 4);
					std::cout << " ";
				}
				textcolor(WHITE);
				goto Here_enter_y;
			}
			else
				return;
		}
	} while (check == 0);

	my_print(coordinate_x, coordinate_y + 3, LIGHT_AQUA, "Enter enrollment day:");
	box(coordinate_x + 25, coordinate_y + 3 - 1, width_small_box, height_box, LIGHT_AQUA);
	my_print(coordinate_x + width_small_box + 1 + 25, coordinate_y + 3, LIGHT_AQUA, "/");
	box(coordinate_x + width_small_box + 2 + 25, coordinate_y + 3 - 1, width_small_box, height_box, LIGHT_AQUA);
	my_print(coordinate_x + 2 * width_small_box + 3 + 25, coordinate_y + 3, LIGHT_AQUA, "/");
	box(coordinate_x + 2 * width_small_box + 4 + 25, coordinate_y + 3 - 1, width_small_box, height_box, LIGHT_AQUA);

	my_print(coordinate_x, coordinate_y + 6, LIGHT_AQUA, "Enter last name:");
	box(coordinate_x + 25, coordinate_y + 6 - 1, width_big_box, height_box, LIGHT_AQUA);

	my_print(coordinate_x, coordinate_y + 9, LIGHT_AQUA, "Enter first name:");
	box(coordinate_x + 25, coordinate_y + 9 - 1, width_big_box, height_box, LIGHT_AQUA);

	my_print(coordinate_x, coordinate_y + 12, LIGHT_AQUA, "Enter gender:");
	box(coordinate_x + 25, coordinate_y + 12 - 1, width_big_box, height_box, LIGHT_AQUA);

	my_print(coordinate_x, coordinate_y + 15, LIGHT_AQUA, "Enter birth date:");
	box(coordinate_x + 25, coordinate_y + 15 - 1, width_small_box, height_box, LIGHT_AQUA);
	my_print(coordinate_x + width_small_box + 1 + 25, coordinate_y + 15, LIGHT_AQUA, "/");
	box(coordinate_x + width_small_box + 2 + 25, coordinate_y + 15 - 1, width_small_box, height_box, LIGHT_AQUA);
	my_print(coordinate_x + 2 * width_small_box + 3 + 25, coordinate_y + 15, LIGHT_AQUA, "/");
	box(coordinate_x + 2 * width_small_box + 4 + 25, coordinate_y + 15 - 1, width_small_box, height_box, LIGHT_AQUA);


	my_print(coordinate_x, coordinate_y + 18, LIGHT_AQUA, "Enter social ID:");
	box(coordinate_x + 25, coordinate_y + 18 - 1, width_big_box, height_box, LIGHT_AQUA);

	//getline
	int enrollment_day;
	int enrollment_month;
	int enrollment_year;//edit tại đây

	gotoXY(coordinate_x + 25 + 1, coordinate_y + 3);
	enrollment_day = stoi(my_getline_onlyNumber(2));
	if (std::to_string(enrollment_day) == "-1")
		return;
	gotoXY(coordinate_x + width_small_box + 2 + 25 + 1, coordinate_y + 3);
	enrollment_month = stoi(my_getline_onlyNumber(2));
	if (std::to_string(enrollment_month) == "-1")
		return;
	gotoXY(coordinate_x + 2 * width_small_box + 3 + 25 + 2, coordinate_y + 3);
	enrollment_year = stoi(my_getline_onlyNumber(4));
	if (std::to_string(enrollment_year) == "-1")
		return;
	gotoXY(coordinate_x + 25 + 1, coordinate_y + 6);
	new_student->student.LName = my_getline_addSpace(width_big_box - 1);
	if (new_student->student.LName == "-1")
		return;
	gotoXY(coordinate_x + 25 + 1, coordinate_y + 9);
	new_student->student.FName = my_getline_addSpace(width_big_box - 1);
	if (new_student->student.FName == "-1")
		return;
	gotoXY(coordinate_x + 25 + 1, coordinate_y + 12);
	new_student->student.Gender = my_getline(width_big_box - 1);
	if (new_student->student.Gender == "-1")
		return;

	gotoXY(coordinate_x + 25 + 1, coordinate_y + 15);
	new_student->student.DoB.day = stoi(my_getline_onlyNumber(2));
	if (std::to_string(new_student->student.DoB.day) == "-1")
		return;
	gotoXY(coordinate_x + width_small_box + 2 + 25 + 1, coordinate_y + 15);
	new_student->student.DoB.month = stoi(my_getline_onlyNumber(2));
	if (std::to_string(new_student->student.DoB.month) == "-1")
		return;
	gotoXY(coordinate_x + 2 * width_small_box + 3 + 25 + 2, coordinate_y + 15);
	new_student->student.DoB.year = stoi(my_getline_onlyNumber(4));
	if (std::to_string(new_student->student.DoB.year) == "-1")
		return;

	gotoXY(coordinate_x + 25 + 1, coordinate_y + 18);
	new_student->student.SocialID = my_getline_onlyNumber(width_big_box - 1);
	if ((new_student->student.SocialID) == "-1")
		return;

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

	textcolor(BLACK);
	for (int k = 0 - 3; k <= 20; k++) {
		for (int p = 0; p <= 25 + width_big_box; p++) {
			gotoXY(coordinate_x + p, coordinate_y - 1 + k);
			std::cout << " ";
		}
	}
	textcolor(WHITE);
	coordinate_x += 10;
	my_print(coordinate_x + 10, coordinate_y - 3, LIGHT_BLUE, "DETAILED INFORMATION");

	std::string fullname = new_student->student.LName + " " + new_student->student.FName;
	my_print(coordinate_x, coordinate_y, LIGHT_BLUE, "Student Name:");
	my_print(coordinate_x + 25, coordinate_y, LIGHT_AQUA, fullname);

	my_print(coordinate_x, coordinate_y + 2, LIGHT_BLUE, "Gender:");
	my_print(coordinate_x + 25, coordinate_y + 2, LIGHT_AQUA, new_student->student.Gender);

	std::string birthDate = std::to_string(new_student->student.DoB.day / 10) + std::to_string(new_student->student.DoB.day % 10) + "/"
		+ std::to_string(new_student->student.DoB.month / 10) + std::to_string(new_student->student.DoB.month % 10) + "/"
		+ std::to_string(new_student->student.DoB.year);
	my_print(coordinate_x, coordinate_y + 4, LIGHT_BLUE, "Birth Date:");
	my_print(coordinate_x + 25, coordinate_y + 4, LIGHT_AQUA, birthDate);

	std::string schoolYear = std::to_string(enrollment_year) + " - " + std::to_string(enrollment_year + 1);
	my_print(coordinate_x, coordinate_y + 6, LIGHT_BLUE, "School Year:");
	my_print(coordinate_x + 25, coordinate_y + 6, LIGHT_AQUA, schoolYear);

	my_print(coordinate_x, coordinate_y + 8, LIGHT_BLUE, "Class ID:");
	my_print(coordinate_x + 25, coordinate_y + 8, LIGHT_AQUA, new_student->student.Classes.ClassID);

	my_print(coordinate_x, coordinate_y + 10, LIGHT_BLUE, "Class Name:");
	my_print(coordinate_x + 25, coordinate_y + 10, LIGHT_AQUA, new_student->student.Classes.name);

	my_print(coordinate_x, coordinate_y + 12, LIGHT_BLUE, "Student ID:");
	my_print(coordinate_x + 25, coordinate_y + 12, LIGHT_AQUA, new_student->student.StudentID);

	my_print(coordinate_x, coordinate_y + 14, LIGHT_BLUE, "Password:");
	my_print(coordinate_x + 25, coordinate_y + 14, LIGHT_AQUA, new_student->student.Password);

	my_print(coordinate_x, coordinate_y + 16, LIGHT_BLUE, "Social ID:");
	my_print(coordinate_x + 25, coordinate_y + 16, LIGHT_AQUA, new_student->student.SocialID);

	gotoXY(coordinate_x + 25, coordinate_y + 18);
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

//2
void course_registration_Session(CR_NODE*& course, STU_COURSE_NODE* stu_course, STFF_NODE* teacher) {
	HERE:
	system("cls");
	int tmp_width = 60;
	int box_width = 32;
	std::string day_tmp, month_tmp;

	my_print(tmp_width, 1, LIGHT_YELLOW, "COURSE REGISTRATION SESSION");

	my_print(tmp_width + 5, 5, LIGHT_YELLOW, "INPUT CURRENT TIME");
	
	my_print(tmp_width - 2, 7, LIGHT_YELLOW, "Day: ");
	box(tmp_width - 2, 8, box_width, 2, LIGHT_AQUA);
	my_print(tmp_width - 2, 11, LIGHT_YELLOW, "Month: ");
	box(tmp_width - 2, 12, box_width, 2, LIGHT_AQUA);

	gotoXY(tmp_width - 1, 9);
	day_tmp = my_getline(box_width - 1);
	gotoXY(tmp_width - 1, 13);
	month_tmp = my_getline(box_width - 1);

	int day, month;
	day = std::stoi(day_tmp);
	month = std::stoi(month_tmp);

	if (day < 1 || day > 31 || month > 12 || month < 1) {
		std::cout << "\n\nYour date is invalid, please input again" << std::endl;
		goto HERE;
	}

	std::system("cls");
	std::string option[] = { "1.View list of courses.",
		"2.Create new course.",
		"3.Update course's information.",
		"4.Delete course.",
		"-1.Exit." };
	int x_boxStaff = 5;
	int y_boxStaff = 4;
	int width_boxStaff = 35;
	int height_boxStaff = 3;
	int amount = sizeof(option) / sizeof(option[0]);
	int choice;

	choice = menu(x_boxStaff, y_boxStaff, width_boxStaff, height_boxStaff, amount, option, WHITE, LIGHT_YELLOW, LIGHT_GREEN);

	if (choice == 1) {
		View_List_of_courses_From_current_time(course, day, month);
	}
	else if (choice == 2) {
		View_List_of_courses_From_current_time(course, day, month);
		system("cls");
		CreateNewCourse_from_current_time(stu_course, teacher, course);
	}
	else if (choice == 3) {
		View_List_of_courses_From_current_time(course, day, month);
		system("cls");
		UpdateCourseInfo_from_current_time(stu_course, teacher, course);
	}
	else if (choice == 4) {
		View_List_of_courses_From_current_time(course, day, month);
		system("cls");
		DeleteCourse_from_current_time(stu_course, teacher, course);
	}
	else
		return;
}


//3
void CreateNewCourse(STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE*& head) {
	ShowCur(1);
	CR_NODE* NewCourse = new CR_NODE;
	CR_NODE* cur = head;

	int coordinate_x = 95;
	int coordinate_y = 2;
	int width_big_box = 40;
	int width_small_box = 25;
	int height_box = 2;

	while (cur->next) {
		cur = cur->next;
	}
	//create new course
	if (!cur) {
		NewCourse->course.No = 1;
	}
	else {
		int NewNo = cur->course.No;
		NewNo++;
		NewCourse->course.No = NewNo;
	}

	std::string NewSchoolyear;
	my_print(coordinate_x, coordinate_y, LIGHT_AQUA, "Enter School Year:");
	box(coordinate_x, coordinate_y + 1, width_small_box, height_box, LIGHT_AQUA);
Here_enter_y:
	gotoXY(coordinate_x + 1, coordinate_y + 1 + 1);
	NewSchoolyear = my_getline(4);
	if (NewSchoolyear == "-1")
		return;
	if (checkExistOfSchoolyear(NewSchoolyear)) {
		NewCourse->course.Schoolyear = NewSchoolyear;
	}
	else {
		my_print(coordinate_x + 10, coordinate_y + 5, RED, "School year does not exist yet!");
		my_print(coordinate_x + 10, coordinate_y + 7, RED, "Please create new schoolyear first!");
		my_print(coordinate_x + 10, coordinate_y + 9, LIGHT_GREEN, "Search for Course again? (y/n): ");
		std::string ans;
		int x_old = whereX();
		int y_old = whereY();
	LOOP_ans:
		gotoXY(x_old, y_old);
		textcolor(WHITE);
		ans = my_getline(1);
		if (ans == "-1")
			return;
		if (ans != "y" && ans != "Y" && ans != "n" && ans != "N") {
			gotoXY(x_old, y_old);
			textcolor(BLACK);
			std::cout << " ";
			goto LOOP_ans;
		}
		if (ans == "y" || ans == "Y") {
			textcolor(BLACK);
			for (int j = 0; j < width_small_box - 1; j++) {
				gotoXY(coordinate_x + 1 + j, coordinate_y + 1 + 1);
				std::cout << " ";
			}
			for (int j = 0; j <= 55; j++) {
				gotoXY(coordinate_x + 3 + j, coordinate_y + 5);
				std::cout << " ";
				gotoXY(coordinate_x + 3 + j, coordinate_y + 7);
				std::cout << " ";
				gotoXY(coordinate_x + 3 + j, coordinate_y + 9);
				std::cout << " ";
			}
			textcolor(WHITE);
			goto Here_enter_y;
		}
		else
			return;
	}

	int NewSemester;

	my_print(coordinate_x + 30, coordinate_y, LIGHT_AQUA, "Enter Semester (1 - 2 - 3 ):");
	box(coordinate_x + 30, coordinate_y + 1, width_small_box, height_box, LIGHT_AQUA);
Here_enter_y2:
	gotoXY(coordinate_x + 30 + 1, coordinate_y + 1 + 1);
	std::string tmp = my_getline_onlyNumber(1);
	if (tmp == "-1")
		return;
	NewSemester = stoi(tmp);
	

	if (NewSemester > 0 && NewSemester <= 3) {
		NewCourse->course.Semester = NewSemester;
	}
	else {
		my_print(coordinate_x + 10, coordinate_y + 5, RED, "Semester must be 1 to 3!");
		my_print(coordinate_x + 10, coordinate_y + 7, LIGHT_GREEN, "Search for Course again? (y/n): ");
		std::string ans;
		int x_old = whereX();
		int y_old = whereY();
	LOOP_ans2:
		gotoXY(x_old, y_old);
		textcolor(WHITE);
		ans = my_getline(1);
		if (ans == "-1")
			return;
		if (ans != "y" && ans != "Y" && ans != "n" && ans != "N") {
			gotoXY(x_old, y_old);
			textcolor(BLACK);
			std::cout << " ";
			goto LOOP_ans2;
		}
		if (ans == "y" || ans == "Y") {
			textcolor(BLACK);
			for (int j = 0; j < width_small_box - 1; j++) {
				gotoXY(coordinate_x + 30 + 1 + j, coordinate_y + 1 + 1);
				std::cout << " ";
			}
			for (int j = 0; j <= 55; j++) {
				gotoXY(coordinate_x + 3 + j, coordinate_y + 5);
				std::cout << " ";
				gotoXY(coordinate_x + 3 + j, coordinate_y + 7);
				std::cout << " ";
			}
			textcolor(WHITE);
			goto Here_enter_y2;
		}
		else
			return;
	}

	my_print(coordinate_x, coordinate_y + 4, LIGHT_AQUA, "Enter New Course Name:");
	box(coordinate_x, coordinate_y + 4 + 1, width_big_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 1, coordinate_y + 4 + 1 + 1);
	NewCourse->course.CName = my_getline_addSpace(width_big_box - 1);
	if (NewCourse->course.CName == "-1")
		return;

	my_print(coordinate_x, coordinate_y + 8, LIGHT_AQUA, "Enter Course ID:");
	box(coordinate_x, coordinate_y + 8 + 1, width_big_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 1, coordinate_y + 8 + 1 + 1);
	NewCourse->course.ID = my_getline_addSpace(width_big_box - 1);
	if (NewCourse->course.ID == "-1")
		return;

	my_print(coordinate_x, coordinate_y + 12, LIGHT_AQUA, "Enter Teacher's last name:");
	box(coordinate_x, coordinate_y + 12 + 1, width_small_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 1, coordinate_y + 12 + 1 + 1);
	NewCourse->course.LNameTeacher = my_getline_addSpace(width_small_box - 1);
	if (NewCourse->course.LNameTeacher == "-1")
		return;

	my_print(coordinate_x + 30, coordinate_y + 12, LIGHT_AQUA, "Enter Teacher's first name:");
	box(coordinate_x + 30, coordinate_y + 12 + 1, width_small_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 30 + 1, coordinate_y + 12 + 1 + 1);
	NewCourse->course.FNameTeacher = my_getline_addSpace(width_small_box - 1);
	if (NewCourse->course.FNameTeacher == "-1")
		return;

	my_print(coordinate_x, coordinate_y + 16, LIGHT_AQUA, "Enter Credits:");
	box(coordinate_x, coordinate_y + 16 + 1, width_small_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 1, coordinate_y + 16 + 1 + 1);
	NewCourse->course.Credits = stoi(my_getline_onlyNumber(3));
	if (std::to_string(NewCourse->course.Credits) == "-1")
		return;

	my_print(coordinate_x + 30, coordinate_y + 16, LIGHT_AQUA, "Enter Max Students:");
	box(coordinate_x + 30, coordinate_y + 16 + 1, width_small_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 30 + 1, coordinate_y + 16 + 1 + 1);
	NewCourse->course.Max_stdn = stoi(my_getline_onlyNumber(3));
	if (std::to_string(NewCourse->course.Max_stdn) == "-1")
		return;

	NewCourse->course.Cur_stdn = 0; //default

	my_print(coordinate_x, coordinate_y + 20, LIGHT_AQUA, "Enter Session(S1->S4):");
	box(coordinate_x, coordinate_y + 20 + 1, width_small_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 1, coordinate_y + 20 + 1 + 1);
	tmp = my_getline(2);
	if (tmp == "-1")
		return;
	NewCourse->course.session = ConvertEnumSS(tmp);

	my_print(coordinate_x + 30, coordinate_y + 20, LIGHT_AQUA, "Enter Weekday(MON->SAT):");
	box(coordinate_x + 30, coordinate_y + 20 + 1, width_small_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 30 + 1, coordinate_y + 20 + 1 + 1);
	tmp = my_getline(3);
	if (tmp == "-1")
		return;
	NewCourse->course.dayOfWeek = ConvertEnumWD(tmp);

	width_small_box -= 10;
	my_print(coordinate_x, coordinate_y + 24, LIGHT_AQUA, "Enter Start date (dd mm yyy)");
	box(coordinate_x, coordinate_y + 24 + 1, width_small_box, height_box, LIGHT_AQUA);
	my_print(coordinate_x + width_small_box + 1, coordinate_y + 24 + 2, LIGHT_AQUA, "/");
	box(coordinate_x + width_small_box + 2, coordinate_y + 24 + 1, width_small_box, height_box, LIGHT_AQUA);
	my_print(coordinate_x + 2 * width_small_box + 3, coordinate_y + 24 + 2, LIGHT_AQUA, "/");
	box(coordinate_x + 2 * width_small_box + 4, coordinate_y + 24 + 1, width_small_box, height_box, LIGHT_AQUA);

	gotoXY(coordinate_x + 1, coordinate_y + 24 + 2);
	NewCourse->course.startDate.day = stoi(my_getline_onlyNumber(2));
	if (std::to_string(NewCourse->course.startDate.day) == "-1")
		return;
	gotoXY(coordinate_x + width_small_box + 2 + 1, coordinate_y + 24 + 2);
	NewCourse->course.startDate.month = stoi(my_getline_onlyNumber(2));
	if (std::to_string(NewCourse->course.startDate.month) == "-1")
		return;
	gotoXY(coordinate_x + 2 * width_small_box + 3 + 2, coordinate_y + 24 + 2);
	NewCourse->course.startDate.year = stoi(my_getline_onlyNumber(4));
	if (std::to_string(NewCourse->course.startDate.year) == "-1")
		return;

	my_print(coordinate_x, coordinate_y + 28, LIGHT_AQUA, "Enter End date (dd mm yyy)");
	box(coordinate_x, coordinate_y + 28 + 1, width_small_box, height_box, LIGHT_AQUA);
	my_print(coordinate_x + width_small_box + 1, coordinate_y + 28 + 2, LIGHT_AQUA, "/");
	box(coordinate_x + width_small_box + 2, coordinate_y + 28 + 1, width_small_box, height_box, LIGHT_AQUA);
	my_print(coordinate_x + 2 * width_small_box + 3, coordinate_y + 28 + 2, LIGHT_AQUA, "/");
	box(coordinate_x + 2 * width_small_box + 4, coordinate_y + 28 + 1, width_small_box, height_box, LIGHT_AQUA);

	gotoXY(coordinate_x + 1, coordinate_y + 28 + 2);
	NewCourse->course.endDate.day = stoi(my_getline_onlyNumber(2));
	if (std::to_string(NewCourse->course.endDate.day) == "-1")
		return;
	gotoXY(coordinate_x + width_small_box + 2 + 1, coordinate_y + 28 + 2);
	NewCourse->course.endDate.month = stoi(my_getline_onlyNumber(2));
	if (std::to_string(NewCourse->course.endDate.month) == "-1")
		return;
	gotoXY(coordinate_x + 2 * width_small_box + 3 + 2, coordinate_y + 28 + 2);
	NewCourse->course.endDate.year = stoi(my_getline_onlyNumber(4));
	if (std::to_string(NewCourse->course.endDate.year) == "-1")
		return;

	//Add course at the end
	if (!cur) {
		cur = NewCourse;
		NewCourse->prev = nullptr;
	}
	else {
		cur->next = NewCourse;
		NewCourse->prev = cur;
	}
	textcolor(BLACK);
	for (int k = 0 - 2; k <= 32; k++) {
		for (int p = 0; p <= 25 + width_big_box; p++) {
			gotoXY(coordinate_x + p, coordinate_y - 1 + k);
			std::cout << " ";
		}
	}
	textcolor(WHITE);
	my_print(coordinate_x, coordinate_y + 10, LIGHT_GREEN, "Added Course Successfully");

	Read_After_Update_Course(stu_course, teacher, head);
	gotoXY(coordinate_x, coordinate_y + 12);
	std::system("pause");
	return;
}
//4
void DeleteCourse(STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE*& head) {
	system("cls");
	CR_NODE* cur = head;

	int coordinate_x = 30;
	int coordinate_y = 25;
	int width_box = 30;
	int height_box = 2;

	viewListOfCourses(cur);
	std::string DelID;
	my_print(coordinate_x, coordinate_y, LIGHT_AQUA, "Enter Course ID You Want To Delete:");
Here_enter_y3:
	box(coordinate_x, coordinate_y + 1, width_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 1, coordinate_y + 1 + 1);
	DelID = my_getline(width_box - 1);
	CR_NODE* DelNode = checkExistOfCourseRecord(head, DelID);
	if (DelNode) {
		CR_NODE* tmp = DelNode;
		(DelNode->next)->prev = tmp->prev;
		if (!DelNode->prev) {
			DelNode->prev = nullptr;
		}
		else {
			(DelNode->prev)->next = tmp->next;
			delete tmp;
		}
		my_print(coordinate_x, coordinate_y + 5, LIGHT_GREEN, "Delete Course Successfully.");
		gotoXY(coordinate_x, coordinate_y + 7);
		Read_After_Update_Course(stu_course, teacher, *&head);
		system("pause");
		return;
	}
	else {
		my_print(coordinate_x + 3, coordinate_y + 5, RED, "No Course Founded!");
		my_print(coordinate_x + 3, coordinate_y + 6, LIGHT_GREEN, "Search for Course again? (y/n): ");
		std::string ans;
		int x_old = whereX();
		int y_old = whereY();
	LOOP_ans:
		gotoXY(x_old, y_old);
		textcolor(WHITE);
		ans = my_getline(1);
		if (ans != "y" && ans != "Y" && ans != "n" && ans != "N") {
			gotoXY(x_old, y_old);
			textcolor(BLACK);
			std::cout << " ";
			goto LOOP_ans;
		}
		if (ans == "y" || ans == "Y") {
			textcolor(BLACK);
			for (int j = 0; j < width_box - 1; j++) {
				gotoXY(coordinate_x + 1 + j, coordinate_y + 1 + 1);
				std::cout << " ";
			}
			for (int j = 0; j <= 55; j++) {
				gotoXY(coordinate_x + 3 + j, coordinate_y + 5);
				std::cout << " ";
				gotoXY(coordinate_x + 3 + j, coordinate_y + 6);
				std::cout << " ";
			}
			textcolor(WHITE);
			goto Here_enter_y3;
		}
		else
			return;
	}
}


////3. LOOK UP
//1
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
//2
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
//3
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
//4
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
//5
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
		<< std::setw(15) << std::left << "First name" << std::setw(5) << std::left << "|"
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
//6
void displayScoreBoard_Class(STU_COURSE_NODE* stu_course, STU_NODE* student, std::string ClassID) {
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

	gotoXY(coordinate_x, coordinate_y); std::cout << "+";
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y); std::cout << "-";
	}
	gotoXY(coordinate_x + width, coordinate_y); std::cout << "+";

	gotoXY(coordinate_x, coordinate_y + 1);
	std::cout << std::setw(5) << std::left << "|" << std::setw(width_no) << std::left << "No" << std::setw(5) << std::left << "|"
		<< std::setw(width_studentID) << std::left << "Student ID" << std::setw(5) << std::left << "|"
		<< std::setw(width_lastName) << std::left << "Last name" << std::setw(5) << std::left << "|"
		<< std::setw(width_firstName) << std::left << "Firse name" << std::setw(5) << std::left << "|"
		<< std::setw(width_subject) << std::left << "Subject" << std::setw(5) << std::left << "|"
		<< std::setw(width_mark) << std::left << "Mark" << "|";
	gotoXY(coordinate_x, coordinate_y + 2); std::cout << "+";
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y + 2); std::cout << "-";
	}
	gotoXY(coordinate_x + width, coordinate_y + 2); std::cout << "+";

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
				std::cout << std::setw(5) << std::left << "|" << std::setw(5) << std::left << " " << std::setw(5) << std::left << "|"
					<< std::setw(width_studentID) << std::left << " " << std::setw(5) << std::left << "|"
					<< std::setw(width_lastName) << std::left << " " << std::setw(5) << std::left << "|"
					<< std::setw(width_firstName) << std::left << " " << std::setw(5) << std::left << "|"
					<< std::setw(width_subject) << std::left << cur->stu_course.Cname << std::setw(5) << std::left << "|"
					<< std::setw(width_mark) << std::left << cur->stu_course.total << "|";
				GPA += cur->stu_course.total;
				count_subject++;
				cur = cur->next;
			}
			if (count_subject == 0) {
				gotoXY(coordinate_x, coordinate_y + 2 + ++i);
				std::cout << std::setw(5) << std::left << "|" << std::setw(5) << std::left << ++count << std::setw(5) << std::left << "|"
					<< std::setw(width_studentID) << std::left << cur_student->student.StudentID << std::setw(5) << std::left << "|"
					<< std::setw(width_lastName) << std::left << cur_student->student.LName << std::setw(5) << std::left << "|"
					<< std::setw(width_firstName) << std::left << cur_student->student.FName << std::setw(5) << std::left << "|"
					<< std::setw(width_subject) << std::left << "GPA" << std::setw(5) << std::left << "|"
					<< std::setw(width_mark) << std::left << std::fixed << std::setprecision(2) << 0 << "|";
			}
			else {
				gotoXY(coordinate_x, coordinate_y + 2 + ++i);
				std::cout << std::setw(5) << std::left << "|" << std::setw(5) << std::left << ++count << std::setw(5) << std::left << "|"
					<< std::setw(width_studentID) << std::left << cur_student->student.StudentID << std::setw(5) << std::left << "|"
					<< std::setw(width_lastName) << std::left << cur_student->student.LName << std::setw(5) << std::left << "|"
					<< std::setw(width_firstName) << std::left << cur_student->student.FName << std::setw(5) << std::left << "|"
					<< std::setw(width_subject) << std::left << "GPA" << std::setw(5) << std::left << "|"
					<< std::setw(width_mark) << std::left << std::fixed << std::setprecision(2) << GPA / count_subject << "|";
			}
			i++;
			gotoXY(coordinate_x, coordinate_y + 2 + i); std::cout << "+";
			for (int j = coordinate_x + 1; j < coordinate_x + width; j++) {
				gotoXY(j, coordinate_y + 2 + i); std::cout << "-";
			}
			gotoXY(coordinate_x + width, coordinate_y + 2 + i); std::cout << "+";

		}
		cur_student = cur_student->next;
	}
	gotoXY(whereX() - 2 * width / 3, whereY() + 2);
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
//7
void ExportScoreBoard(STU_COURSE_NODE* stu_course, CR_NODE* course, STU_NODE* student) {
	std::system("cls");
	viewListOfCourses(course);
	std::string option[] = { "1. Export all the courses.",
				"2. Export only a course.",
				"0.Come back." };
	int coordinate_x = 20;
	int coordinate_y = 25;
	int width_box = 30;
	int height_box = 2;
	int amount = sizeof(option) / sizeof(option[0]);
	int choice;

	choice = menu(coordinate_x, coordinate_y, width_box, height_box, amount, option, WHITE, LIGHT_YELLOW, LIGHT_GREEN);

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
		//viewListOfCourses(course);
		my_print(coordinate_x + width_box + 5, coordinate_y + 1, LIGHT_RED, "Enter ID of the course you want to export:");
		box(coordinate_x + width_box + 5, coordinate_y + 1 + 1, width_box, height_box, LIGHT_YELLOW);
		ShowCur(1);
	Here_enter_y:
		gotoXY(coordinate_x + width_box + 5 + 1, coordinate_y + 1 + 2);
		courseID = my_getline(width_box - 1);
		cur_course = course;
		while (cur_course) {
			if (cur_course->course.ID == courseID) {
				check = 1;
				break;
			}
			cur_course = cur_course->next;
		}
		if (check == 0) {
			my_print(coordinate_x + width_box + 5, coordinate_y + 1 + 5, RED, "Your course ID which you entered does not exist.");
			my_print(coordinate_x + width_box + 5, coordinate_y + 1 + 6, LIGHT_RED, "Search for Course again? (y/n): ");
			std::string ans;
			int x_old = whereX();
			int y_old = whereY();
		LOOP_ans:
			gotoXY(x_old, y_old);
			textcolor(WHITE);
			ans = my_getline(1);
			if (ans != "y" && ans != "Y" && ans != "n" && ans != "N") {
				gotoXY(x_old, y_old);
				textcolor(BLACK);
				std::cout << " ";
				goto LOOP_ans;
			}
			if (ans == "y" || ans == "Y") {
				textcolor(BLACK);
				for (int j = 0; j < width_box - 1; j++) {
					gotoXY(coordinate_x + width_box + 5 + 1 + j, coordinate_y + 1 + 2);
					std::cout << " ";
				}
				for (int j = 0; j <= 50; j++) {
					gotoXY(coordinate_x + width_box + 5 + j, coordinate_y + 1 + 5);
					std::cout << " ";
					gotoXY(coordinate_x + width_box + 5 + j, coordinate_y + 1 + 6);
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
				output.close();
				my_print(coordinate_x + width_box + 5, coordinate_y + 1 + 5, LIGHT_RED, "Export successfully");
				gotoXY(coordinate_x + width_box + 5, coordinate_y + 1 + 6);
				std::system("pause");
			}
		}
	}
	else if (choice == 0 + 3)
		return;
}