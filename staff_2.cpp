#include "staff.h"

////2. ENTER INFORMATION
//1
void add_new_first_year_student(STU_NODE*& student, CLASS_NODE* listclass) {
	STU_NODE* new_student = new STU_NODE;
	bool check;
	STU_NODE* cur_student = student;

	int coordinate_x = 88;
	int coordinate_y = 7;
	int width_big_box = 40;
	int width_small_box = 10;
	int height_box = 2;

	std::ifstream fileSchoolYear("schoolYear.txt");
	if (!fileSchoolYear.is_open()) {
		my_print(coordinate_x, coordinate_y, RED * 16 + LIGHT_AQUA, "Can not open file schoolYear.txt");
		char ans = _getch();
		return;
	}
	else {
		std::string cur_year;
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
			std::string cur_semester;
			while (!fileSemester.eof())
				std::getline(fileSemester, cur_semester);
			if (cur_semester.substr(0, 1) != "1") {
				my_print(coordinate_x, coordinate_y, RED * 16 + LIGHT_AQUA, "Please create a new school year before add new students to classes.");
				char ans = _getch();
				fileSchoolYear.close();
				fileSemester.close();
				return;
			}

		}
		fileSemester.close();

	}
	fileSchoolYear.close();

	do {
		check = 0;
		ShowCur(1);
		my_print(coordinate_x + 23, coordinate_y - 3, LIGHT_AQUA, "GENERAL INFORMATION");


	enterClassID:
		my_print(coordinate_x, coordinate_y, LIGHT_AQUA, "Enter class ID:");
		box(coordinate_x + 25, coordinate_y - 1, width_big_box, height_box, LIGHT_AQUA);
		gotoXY(coordinate_x + 25 + 1, coordinate_y);
		std::string tmp = my_getline(width_big_box - 1);
		if (tmp == "-1")
			return;
		else
			new_student->student.Classes.ClassID = tmp;

		cur_student = student;
		while (cur_student) {
			if (cur_student->student.Classes.ClassID == new_student->student.Classes.ClassID)
				check = 1;
			cur_student = cur_student->next;
		}
		if (check == 0) {
			ShowCur(0);
			my_print(coordinate_x + 3, coordinate_y + 3, RED * 16 + LIGHT_AQUA, "Your class ID which you entered it does not exist.");
			my_print(coordinate_x + 17, coordinate_y + 5, LIGHT_GREEN * 16 + BLACK, "Do you want to enter again:");
			int choice_again = enter_again_yes_no(coordinate_x + 19, coordinate_y + 7, 7, 3, 4, LIGHT_AQUA, YELLOW);
			if (choice_again == 1) {
				textcolor(BLACK * 16 + BLACK);
				for (int j = 0; j < 12; j++)
					for (int i = 0; i < 66; i++) {
						gotoXY(coordinate_x + i, coordinate_y - 1 + j);
						std::cout << " ";
					}
				textcolor(WHITE);
				ShowCur(1);
				goto enterClassID;
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
	std::string tmp;

	gotoXY(coordinate_x + 25 + 1, coordinate_y + 3);
	tmp = my_getline_onlyNumber(2);
	if (tmp == "-1")
		return;
	else
		enrollment_day = stoi(tmp);

	gotoXY(coordinate_x + width_small_box + 2 + 25 + 1, coordinate_y + 3);
	tmp = my_getline_onlyNumber(2);
	if (tmp == "-1")
		return;
	else
		enrollment_month = stoi(tmp);

	gotoXY(coordinate_x + 2 * width_small_box + 3 + 25 + 2, coordinate_y + 3);
	tmp = my_getline_onlyNumber(4);
	if (tmp == "-1")
		return;
	else
		enrollment_year = stoi(tmp);

	gotoXY(coordinate_x + 25 + 1, coordinate_y + 6);
	new_student->student.LName = my_getline_addSpace(width_big_box - 1);
	if (new_student->student.LName == "-1")
		return;
	gotoXY(coordinate_x + 25 + 1, coordinate_y + 9);
	new_student->student.FName = my_getline_addSpace(width_big_box - 1);
	if (new_student->student.FName == "-1")
		return;
	gotoXY(coordinate_x + 25 + 1, coordinate_y + 12);
	new_student->student.Gender = my_getline_addSpace(width_big_box - 1);
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
	reread_after_update_student(student);
}
//2
void set_time_course_regis() {
	int coordinate_x = 105;
	int coordinate_y = 7;
	int width_big_box = 40;
	int width_small_box = 10;
	int height_box = 2;
	std::string cur_year;
	std::string cur_semester;

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
			my_print(coordinate_x, coordinate_y, LIGHT_AQUA, "Enter start time:");
			box(coordinate_x, coordinate_y + 1, width_small_box, height_box, LIGHT_AQUA);
			my_print(coordinate_x + width_small_box + 1, coordinate_y + 1 + 1, LIGHT_AQUA, ":");
			box(coordinate_x + width_small_box + 2, coordinate_y + 1, width_small_box, height_box, LIGHT_AQUA);
			my_print(coordinate_x + 2 * width_small_box + 3, coordinate_y + 1 + 1, LIGHT_AQUA, ":");
			box(coordinate_x + 2 * width_small_box + 4, coordinate_y + 1, width_small_box, height_box, LIGHT_AQUA);

			my_print(coordinate_x, coordinate_y + 4, LIGHT_AQUA, "Enter start date:");
			box(coordinate_x, coordinate_y + 4 + 1, width_small_box, height_box, LIGHT_AQUA);
			my_print(coordinate_x + width_small_box + 1, coordinate_y + 4 + 1 + 1, LIGHT_AQUA, "/");
			box(coordinate_x + width_small_box + 2, coordinate_y + 4 + 1, width_small_box, height_box, LIGHT_AQUA);
			my_print(coordinate_x + 2 * width_small_box + 3, coordinate_y + 4 + 1 + 1, LIGHT_AQUA, "/");
			box(coordinate_x + 2 * width_small_box + 4, coordinate_y + 4 + 1, width_small_box, height_box, LIGHT_AQUA);

			my_print(coordinate_x, coordinate_y + 8, LIGHT_AQUA, "Enter end time:");
			box(coordinate_x, coordinate_y + 8 + 1, width_small_box, height_box, LIGHT_AQUA);
			my_print(coordinate_x + width_small_box + 1, coordinate_y + 8 + 1 + 1, LIGHT_AQUA, ":");
			box(coordinate_x + width_small_box + 2, coordinate_y + 8 + 1, width_small_box, height_box, LIGHT_AQUA);
			my_print(coordinate_x + 2 * width_small_box + 3, coordinate_y + 8 + 1 + 1, LIGHT_AQUA, ":");
			box(coordinate_x + 2 * width_small_box + 4, coordinate_y + 8 + 1, width_small_box, height_box, LIGHT_AQUA);

			my_print(coordinate_x, coordinate_y + 12, LIGHT_AQUA, "Enter start date:");
			box(coordinate_x, coordinate_y + 12 + 1, width_small_box, height_box, LIGHT_AQUA);
			my_print(coordinate_x + width_small_box + 1, coordinate_y + 12 + 1 + 1, LIGHT_AQUA, "/");
			box(coordinate_x + width_small_box + 2, coordinate_y + 12 + 1, width_small_box, height_box, LIGHT_AQUA);
			my_print(coordinate_x + 2 * width_small_box + 3, coordinate_y + 12 + 1 + 1, LIGHT_AQUA, "/");
			box(coordinate_x + 2 * width_small_box + 4, coordinate_y + 12 + 1, width_small_box, height_box, LIGHT_AQUA);

			Date start_date, end_date;
			Time start_time, end_time;
			ShowCur(1);
			std::string tmp;

			textcolor(LIGHT_YELLOW * 16 + BLACK);
			for (int j = 0; j < 3; j++)
				for (int i = 0; i < 35; i++) {
					gotoXY(coordinate_x + i, coordinate_y - 5 + j);
					std::cout << " ";
				}
			gotoXY(coordinate_x + 4, coordinate_y - 5 + 1);
			std::cout << "COURSE REGISTRATION PERIOD";
			textcolor(WHITE);

			gotoXY(coordinate_x + 1, coordinate_y + 1 + 1);
			tmp = my_getline_onlyNumber(2);
			if (tmp == "-1") return;
			else start_time.hour = stoi(tmp);

			gotoXY(coordinate_x + width_small_box + 2 + 1, coordinate_y + 1 + 1);
			tmp = my_getline_onlyNumber(2);
			if (tmp == "-1") return;
			else start_time.minute = stoi(tmp);

			gotoXY(coordinate_x + 2 * width_small_box + 4 + 1, coordinate_y + 1 + 1);
			tmp = my_getline_onlyNumber(2);
			if (tmp == "-1") return;
			else start_time.second = stoi(tmp);

			gotoXY(coordinate_x + 1, coordinate_y + 4 + 1 + 1);
			tmp = my_getline_onlyNumber(2);
			if (tmp == "-1") return;
			else start_date.day = stoi(tmp);

			gotoXY(coordinate_x + width_small_box + 2 + 1, coordinate_y + 4 + 1 + 1);
			tmp = my_getline_onlyNumber(2);
			if (tmp == "-1") return;
			else start_date.month = stoi(tmp);

			gotoXY(coordinate_x + 2 * width_small_box + 4 + 1, coordinate_y + 4 + 1 + 1);
			tmp = my_getline_onlyNumber(4);
			if (tmp == "-1") return;
			else start_date.year = stoi(tmp);

			gotoXY(coordinate_x + 1, coordinate_y + 8 + 1 + 1);
			tmp = my_getline_onlyNumber(2);
			if (tmp == "-1") return;
			else end_time.hour = stoi(tmp);

			gotoXY(coordinate_x + width_small_box + 2 + 1, coordinate_y + 8 + 1 + 1);
			tmp = my_getline_onlyNumber(2);
			if (tmp == "-1") return;
			else end_time.minute = stoi(tmp);

			gotoXY(coordinate_x + 2 * width_small_box + 4 + 1, coordinate_y + 8 + 1 + 1);
			tmp = my_getline_onlyNumber(2);
			if (tmp == "-1") return;
			else end_time.second = stoi(tmp);

			gotoXY(coordinate_x + 1, coordinate_y + 12 + 1 + 1);
			tmp = my_getline_onlyNumber(2);
			if (tmp == "-1") return;
			else end_date.day = stoi(tmp);

			gotoXY(coordinate_x + width_small_box + 2 + 1, coordinate_y + 12 + 1 + 1);
			tmp = my_getline_onlyNumber(2);
			if (tmp == "-1") return;
			else end_date.month = stoi(tmp);

			gotoXY(coordinate_x + 2 * width_small_box + 4 + 1, coordinate_y + 12 + 1 + 1);
			tmp = my_getline_onlyNumber(4);
			if (tmp == "-1") return;
			else  end_date.year = stoi(tmp);

			while (!fileSemester.eof())
				std::getline(fileSemester, cur_semester);
			cur_semester = cur_semester.substr(0, 1);
			std::ofstream file_CourseRegis("timeCrsRegis" + cur_year.substr(0, 4) + "_" + std::to_string(stoi(cur_year.substr(0, 4)) + 1) + "_" + cur_semester + ".txt");
			if (file_CourseRegis.is_open()) {

				ShowCur(0);

				my_print(coordinate_x + 1, coordinate_y + 18, LIGHT_GREEN * 16 + BLACK, "Are you sure you want to create:");
				int choice = enter_again_yes_no(coordinate_x + 7, coordinate_y + 18 + 1, 7, 3, 5, LIGHT_AQUA, YELLOW);
				if (choice == 1) {
					file_CourseRegis
						<< start_time.hour << ":" << start_time.minute << ":" << start_time.second << "\n"
						<< start_date.day << "/" << start_date.month << "/" << start_date.year << "\n"
						<< end_time.hour << ":" << end_time.minute << ":" << end_time.second << "\n"
						<< end_date.day << "/" << end_date.month << "/" << end_date.year;
					textcolor(BLACK * 16 + BLACK);
					for (int j = 0; j < 25; j++)
						for (int i = 0; i < 40; i++) {
							gotoXY(coordinate_x + i, coordinate_y + j);
							std::cout << " ";
						}
					textcolor(WHITE);

					textcolor(LIGHT_GREEN * 16 + BLACK);
					for (int j = 0; j < 3; j++)
						for (int i = 0; i < 48; i++) {
							gotoXY(coordinate_x - 5 + i, coordinate_y + 10 + j);
							std::cout << " ";
						}
					gotoXY(coordinate_x - 4, coordinate_y + 10 + 1);
					std::cout << "Created course registration time successfully.";
					textcolor(WHITE);
				}
			}
			char ans = _getch();
			file_CourseRegis.close();
			fileSchoolYear.close();
			fileSemester.close();
			return;
		}
		fileSemester.close();

	}
	fileSchoolYear.close();
}
//3
void import_students_from_file(STU_NODE* student, CLASS_NODE* listclass) {
	int coordinate_x = 100;
	int coordinate_y = 7;
	int width_box = 40;
	int height_box = 2;

	textcolor(LIGHT_YELLOW * 16 + BLACK);
	for (int j = 0; j < 3; j++)
		for (int i = 0; i < width_box; i++) {
			gotoXY(coordinate_x + i, coordinate_y - 5 + j);
			std::cout << " ";
		}
	gotoXY(coordinate_x + 10, coordinate_y - 5 + 1);
	std::cout << "CSV STUDENTS IMPORT";
	textcolor(WHITE);

	std::string fileName, classID, className, curYear, curSemester;
	get_curYear_and_curSemester(coordinate_x, coordinate_y, curYear, curSemester);

	if (curSemester != "1") {
		my_print(coordinate_x, coordinate_y + height_box + 2, LIGHT_RED * 16 + BLACK, "Please create new school year before!");
		char c;
		c = _getch();
		return;
	}

	my_print(coordinate_x, coordinate_y, YELLOW * 16 + BLACK, "School year:");
	box(coordinate_x, coordinate_y + 1, width_box, height_box, LIGHT_AQUA);

	my_print(coordinate_x, coordinate_y + 5, YELLOW * 16 + BLACK, "Enter file name (link to file):");
	box(coordinate_x, coordinate_y + 5 + 1, width_box, height_box, LIGHT_AQUA);

	my_print(coordinate_x, coordinate_y + 10, YELLOW * 16 + BLACK, "Enter class ID:");
	box(coordinate_x, coordinate_y + 10 + 1, width_box, height_box, LIGHT_AQUA);

	my_print(coordinate_x, coordinate_y + 15, YELLOW * 16 + BLACK, "Enter class name:");
	box(coordinate_x, coordinate_y + 15 + 1, width_box, height_box, LIGHT_AQUA);

	my_print(coordinate_x + 1 + 15, coordinate_y + 2, LIGHT_RED, curYear + "-" + std::to_string(stoi(curYear) + 1));

	ShowCur(1);

	gotoXY(coordinate_x + 1, coordinate_y + 5 + 1 + 1);
	fileName = my_getline_addSpace(width_box - 1);
	if (fileName == "-1")
		return;
	
	gotoXY(coordinate_x + 1, coordinate_y + 10 + 1 + 1);
	classID = my_getline_addSpace(width_box - 1);
	if (classID == "-1")
		return;

	gotoXY(coordinate_x + 1, coordinate_y + 15 + 1 + 1);
	className = my_getline_addSpace(width_box - 1);
	if (className == "-1")
		return;

	int check = get_data_to_import_list_students_to_class(fileName, student, listclass, classID, className, curYear);


	if (check == 0) {
		ShowCur(0);
		my_print(coordinate_x, coordinate_y + 21, RED * 16 + BLACK, "The file could not be found at the specified path.");
		my_print(coordinate_x, coordinate_y + 23, GREEN * 16 + BLACK, "Please check the file path and try again.");
		char ans = _getch();
		return;
	}
	else {
		textcolor(LIGHT_GREEN * 16 + BLACK);
		for (int j = 0; j < 3; j++)
			for (int i = 0; i < width_box; i++) {
				gotoXY(coordinate_x + i, coordinate_y + 21 + j);
				std::cout << " ";
			}
		gotoXY(coordinate_x + 10, coordinate_y + 21 + 1);
		std::cout << "Import successfully.";
		textcolor(WHITE);

		char ans = _getch();
		return;
	}
}

//4
void display_list_of_teachers(STFF_NODE* teacher) {
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
void update_information_of_teacher(STFF_NODE*& teacher) {
	std::system("cls");
	display_list_of_teachers(teacher);

	int coordinate_x_display = 30;
	int coordinate_y_display = 26;
	int width_box_display = 40;
	int height_box_display = 2;

enter_teacherID:

	my_print(coordinate_x_display, coordinate_y_display, YELLOW * 16 + BLACK, "Enter the ID of the teacher you want to update:");
	box(coordinate_x_display, coordinate_y_display + 1, width_box_display, height_box_display, LIGHT_AQUA);
	std::string teacherID;
	gotoXY(coordinate_x_display + 1, coordinate_y_display + 2);
	ShowCur(1);
	teacherID = my_getline(width_box_display - 1);
	ShowCur(0);
	if (teacherID == "-1")
		return;
	STFF_NODE* cur_teacher = teacher;
	int check = 0;
	while (cur_teacher) {
		if (cur_teacher->staff.TeacherID == teacherID) {
			check = 1;
			break;
		}
		cur_teacher = cur_teacher->next;
	}

	if (check != 1) {
		ShowCur(0);
		my_print(coordinate_x_display + 53, coordinate_y_display, RED * 16 + LIGHT_AQUA, "Teacher ID doesn't exist.");

		my_print(coordinate_x_display + 53, coordinate_y_display + 2, LIGHT_GREEN * 16 + BLACK, "Do you want to enter again:");
		int choice = enter_again_yes_no(coordinate_x_display + 53, coordinate_y_display + 4, 8, 3, 4, LIGHT_AQUA, LIGHT_GREEN);
		if (choice == 1) {
			textcolor(BLACK * 16 + BLACK);
			for (int j = 0; j < 8; j++)
				for (int i = 0; i < 80; i++) {
					gotoXY(coordinate_x_display + i, coordinate_y_display + j);
					std::cout << " ";
				}
			textcolor(WHITE);
			goto enter_teacherID;
		}
		else {
			return;
		}
	}
update_infor:
	std::system("cls");

	int coordinate_x_infor = 45;
	int coordinate_y_infor = 3;
	int width_box_infor = 60;
	int height_box_infor = 7;
	int width_small_box_infor = 25;
	int color_infor = LIGHT_YELLOW;
	int color_text = LIGHT_YELLOW;

	box(coordinate_x_infor, coordinate_y_infor, width_box_infor, height_box_infor, color_infor);
	box(coordinate_x_infor + width_box_infor / 2 - width_small_box_infor / 2, coordinate_y_infor - 2, width_small_box_infor, 2, color_infor);
	textcolor(color_infor);
	gotoXY(coordinate_x_infor + width_box_infor / 2 - width_small_box_infor / 2, coordinate_y_infor);
	std::cout << (char)193;
	gotoXY(coordinate_x_infor + width_box_infor / 2 - width_small_box_infor / 2 + width_small_box_infor, coordinate_y_infor);
	std::cout << (char)193;
	textcolor(WHITE);

	my_print(coordinate_x_infor + width_box_infor / 2 - width_small_box_infor / 2 + 1, coordinate_y_infor - 2 + 1, color_text, " Teacher's information");

	std::string fullname = cur_teacher->staff.LName + " " + cur_teacher->staff.FName;
	std::string DoB = std::to_string(cur_teacher->staff.DoB.day / 10) + std::to_string(cur_teacher->staff.DoB.day % 10) + "/"
		+ std::to_string(cur_teacher->staff.DoB.month / 10) + std::to_string(cur_teacher->staff.DoB.month % 10) + "/"
		+ std::to_string(cur_teacher->staff.DoB.year);

	textcolor(color_text);
	gotoXY(coordinate_x_infor + 1, coordinate_y_infor + 1);
	std::cout << std::setw(15) << std::left << "Full name : " << std::setw(44) << std::right << fullname;
	gotoXY(coordinate_x_infor + 1, coordinate_y_infor + 2);
	std::cout << std::setw(15) << std::left << "Teacher ID: " << std::setw(44) << std::right << cur_teacher->staff.TeacherID;
	gotoXY(coordinate_x_infor + 1, coordinate_y_infor + 3);
	std::cout << std::setw(15) << std::left << "Gender: " << std::setw(44) << std::right << cur_teacher->staff.Gender;
	gotoXY(coordinate_x_infor + 1, coordinate_y_infor + 4);
	std::cout << std::setw(15) << std::left << "Date of birth: " << std::setw(44) << std::right << DoB;
	gotoXY(coordinate_x_infor + 1, coordinate_y_infor + 5);
	std::cout << std::setw(15) << std::left << "Social ID: " << std::setw(44) << std::right << cur_teacher->staff.SocialID;
	gotoXY(coordinate_x_infor + 1, coordinate_y_infor + 6);
	std::cout << std::setw(15) << std::left << "Faculty: " << std::setw(44) << std::right << cur_teacher->staff.Faculty;
	textcolor(WHITE);

	std::string option[] = {
				"1.Update Teacher's name",
				"2.Update gender.",
				"3.Update date of birth.",
				"4.Update social ID.",
				"5.Update Faculty.",
				"0.Come back." };
	int coordinate_x_option = 10;
	int coordinate_y_option = 11;
	int width_box_option = 30;
	int height_box_option = 3;
	int amount = sizeof(option) / sizeof(option[0]);
	int choice;

	choice = menu(coordinate_x_option, coordinate_y_option, width_box_option, height_box_option, amount, option, WHITE, LIGHT_YELLOW, LIGHT_GREEN);

	int coordinate_x = 75;
	int coordinate_y = 14;
	int width_box = 30;
	int width_small_box = 10;
	int height_box = 3;

	std::string tmp;
	if (choice == 1) {
		textcolor(LIGHT_YELLOW * 16 + BLACK);
		for (int j = 0; j < 3; j++)
			for (int i = 0; i < 40; i++) {
				gotoXY(coordinate_x + i, coordinate_y - 2 + j);
				std::cout << " ";
			}
		gotoXY(coordinate_x + 13 + 1, coordinate_y + 1 - 2);
		std::cout << "UPDATE NAME";
		textcolor(WHITE);

		my_print(coordinate_x, coordinate_y + 6 - 2, LIGHT_RED, "Enter Last Name:");
		box(coordinate_x, coordinate_y + 6 + 1 - 2, width_box, height_box, LIGHT_AQUA);

		my_print(coordinate_x, coordinate_y + 11 - 2, LIGHT_RED, "Enter First Name:");
		box(coordinate_x, coordinate_y + 11 + 1 - 2, width_box, height_box, LIGHT_AQUA);

		std::string LName, FName;
		ShowCur(1);
		gotoXY(coordinate_x + 1, coordinate_y - 2 + 6 + 2);
		LName = my_getline_addSpace(width_box - 1);
		ShowCur(0);
		if (LName == "-1")
			goto update_infor;

		ShowCur(1);
		gotoXY(coordinate_x + 1, coordinate_y + -2 + 11 + 2);
		FName = my_getline_addSpace(width_box - 1);
		ShowCur(0);
		if (FName == "-1")
			goto update_infor;


		my_print(coordinate_x + 36 + 1, coordinate_y - 5 + 6 + 2 + 4, LIGHT_GREEN, "Are you sure you want to change?");
		int check = enter_again_yes_no(coordinate_x + 36 + 1, coordinate_y - 5 + 13, 8, 3, 4, LIGHT_AQUA, LIGHT_GREEN);
		if (check == 1) {
			cur_teacher->staff.LName = LName;
			cur_teacher->staff.FName = FName;
			reread_after_update_teacher(teacher);
		}
		goto update_infor;
	}
	else if (choice == 2) {
		textcolor(LIGHT_YELLOW * 16 + BLACK);
		for (int j = 0; j < 3; j++)
			for (int i = 0; i < 40; i++) {
				gotoXY(coordinate_x + i, coordinate_y + j);
				std::cout << " ";
			}
		gotoXY(coordinate_x + 13 + 1, coordinate_y + 1);
		std::cout << "UPDATE GENDER";
		textcolor(WHITE);

		my_print(coordinate_x, coordinate_y + 6, LIGHT_RED, "Enter gender which you want to update:");
		box(coordinate_x, coordinate_y + 6 + 1, width_box, height_box, LIGHT_AQUA);
		ShowCur(1);
		gotoXY(coordinate_x + 1, coordinate_y + 6 + 2);
		tmp = my_getline_addSpace(width_box - 1);
		ShowCur(0);
		if (tmp == "-1")
			goto update_infor;

		my_print(coordinate_x + 1, coordinate_y + 6 + 2 + 4, LIGHT_GREEN, "Are you sure you want to change?");
		int check = enter_again_yes_no(coordinate_x + 1, coordinate_y + 13, 8, 3, 4, LIGHT_AQUA, LIGHT_GREEN);
		if (check == 1) {
			cur_teacher->staff.Gender = tmp;
			reread_after_update_teacher(teacher);
		}
		goto update_infor;
	}
	else if (choice == 3) {
		textcolor(LIGHT_YELLOW * 16 + BLACK);
		for (int j = 0; j < 3; j++)
			for (int i = 0; i < 40; i++) {
				gotoXY(coordinate_x + i, coordinate_y + j);
				std::cout << " ";
			}
		gotoXY(coordinate_x + 9 + 1, coordinate_y + 1);
		std::cout << "UPDATE DATE OF BIRTH";
		textcolor(WHITE);

		my_print(coordinate_x, coordinate_y + 6, LIGHT_RED, "Enter date of birth which you want to update:");
		box(coordinate_x, coordinate_y + 6 + 1, width_small_box, height_box, LIGHT_AQUA);
		my_print(coordinate_x + width_small_box + 1, coordinate_y + 6 + 2, LIGHT_AQUA, "/");
		box(coordinate_x + width_small_box + 2, coordinate_y + 6 + 1, width_small_box, height_box, LIGHT_AQUA);
		my_print(coordinate_x + 2 * width_small_box + 3, coordinate_y + 6 + 2, LIGHT_AQUA, "/");
		box(coordinate_x + 2 * width_small_box + 4, coordinate_y + 6 + 1, width_small_box, height_box, LIGHT_AQUA);

		Date newDOB;
		ShowCur(1);
		gotoXY(coordinate_x + 1, coordinate_y + 6 + 2);
		tmp = my_getline_onlyNumber(2);
		ShowCur(0);
		if (tmp == "-1")
			goto update_infor;
		else
			newDOB.day = stoi(tmp);

		ShowCur(1);
		gotoXY(coordinate_x + width_small_box + 2 + 1, coordinate_y + 6 + 2);
		tmp = my_getline_onlyNumber(2);
		ShowCur(0);
		if (tmp == "-1")
			goto update_infor;
		else
			newDOB.month = stoi(tmp);

		ShowCur(1);
		gotoXY(coordinate_x + 2 * width_small_box + 4 + 1, coordinate_y + 6 + 2);
		tmp = my_getline_onlyNumber(4);
		ShowCur(0);
		if (tmp == "-1")
			goto update_infor;
		else
			newDOB.year = stoi(tmp);

		my_print(coordinate_x + 1, coordinate_y + 6 + 2 + 4, LIGHT_GREEN, "Are you sure you want to change?");
		int check = enter_again_yes_no(coordinate_x + 1, coordinate_y + 13, 8, 3, 4, LIGHT_AQUA, LIGHT_GREEN);
		if (check == 1) {
			cur_teacher->staff.DoB = newDOB;
			reread_after_update_teacher(teacher);
		}
		goto update_infor;
	}
	else if (choice == 4) {
		textcolor(LIGHT_YELLOW * 16 + BLACK);
		for (int j = 0; j < 3; j++)
			for (int i = 0; i < 40; i++) {
				gotoXY(coordinate_x + i, coordinate_y + j);
				std::cout << " ";
			}
		gotoXY(coordinate_x + 13 + 1, coordinate_y + 1);
		std::cout << "UPDATE SOCIAL ID";
		textcolor(WHITE);

		my_print(coordinate_x, coordinate_y + 6, LIGHT_RED, "Enter social ID which you want to update:");
		box(coordinate_x, coordinate_y + 6 + 1, width_box, height_box, LIGHT_AQUA);
		ShowCur(1);
		gotoXY(coordinate_x + 1, coordinate_y + 6 + 2);
		tmp = my_getline_addSpace(width_box - 1);
		ShowCur(0);
		if (tmp == "-1")
			goto update_infor;

		my_print(coordinate_x + 1, coordinate_y + 6 + 2 + 4, LIGHT_GREEN, "Are you sure you want to change?");
		int check = enter_again_yes_no(coordinate_x + 1, coordinate_y + 13, 8, 3, 4, LIGHT_AQUA, LIGHT_GREEN);
		if (check == 1) {
			cur_teacher->staff.SocialID = tmp;
			reread_after_update_teacher(teacher);
		}
		goto update_infor;
	}
	else if (choice == 5) {
		textcolor(LIGHT_YELLOW * 16 + BLACK);
		for (int j = 0; j < 3; j++)
			for (int i = 0; i < 40; i++) {
				gotoXY(coordinate_x + i, coordinate_y + j);
				std::cout << " ";
			}
		gotoXY(coordinate_x + 13 + 1, coordinate_y + 1);
		std::cout << "UPDATE GENDER";
		textcolor(WHITE);

		my_print(coordinate_x, coordinate_y + 6, LIGHT_RED, "Enter faculty which you want to update:");
		box(coordinate_x, coordinate_y + 6 + 1, width_box, height_box, LIGHT_AQUA);
		ShowCur(1);
		gotoXY(coordinate_x + 1, coordinate_y + 6 + 2);
		tmp = my_getline_addSpace(width_box - 1);
		ShowCur(0);
		if (tmp == "-1")
			goto update_infor;

		my_print(coordinate_x + 1, coordinate_y + 6 + 2 + 4, LIGHT_GREEN, "Are you sure you want to change?");
		int check = enter_again_yes_no(coordinate_x + 1, coordinate_y + 13, 8, 3, 4, LIGHT_AQUA, LIGHT_GREEN);
		if (check == 1) {
			cur_teacher->staff.Faculty = tmp;
			reread_after_update_teacher(teacher);
		}
		goto update_infor;
	}
	else if (choice == 0 + 6) {
		return;
	}
}