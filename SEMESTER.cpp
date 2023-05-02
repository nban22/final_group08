#include "header.h"

CR_NODE* checkExistOfCourseRecord(CR_NODE*& head, std::string ID) {
	CR_NODE* current = head;
	CR_NODE* FoundNode = nullptr;
	while (current) {
		if (ID == current->course.ID) {
			return FoundNode = current;
		}
		else {
			current = current->next;
		}
	}
	return FoundNode;
}

STU_COURSE_NODE* checkExistOfStudentCourseRecord(STU_COURSE_NODE*& stu_course, std::string courseID) {
	STU_COURSE_NODE* cur_stu_course = stu_course;
	while (cur_stu_course) {
		if (cur_stu_course->stu_course.StuID == courseID) {
			return cur_stu_course;
		}
		cur_stu_course = cur_stu_course->next;
	}
	return nullptr;
}

void AddStudent_csv(CLASS_NODE*& listclass) {
AGAIN:
	system("cls");
	int x_box = 5;
	int y_box = 2;
	int width_box = 42;
	int height_box = 2;

	char check;
	int tmp_width = 60;
	int box_width = 32;
	my_print(tmp_width, -20, LIGHT_YELLOW, "Choose your option of importing student(s):");

	std::string option_1[] = { "1. Add to a new Class.",
			"2. Add onto existing class.",
			"0. Come back." };

	int x_boxOption1 = x_box + width_box + 2;
	int y_boxOption1 = y_box;
	int width_boxOption1 = 50;
	int height_boxOption1 = 3;
	int amount_option1 = sizeof(option_1) / sizeof(option_1[0]);
	int choose;
	choose = menu(x_boxOption1 - 39, y_boxOption1 + 8, width_boxOption1, height_boxOption1, amount_option1, option_1, WHITE, LIGHT_YELLOW, LIGHT_GREEN);

	if (choose == 1) {
		system("cls");
		ShowCur(1);
		int width_tmp1 = 50;
		int height_tmp1 = 10;
		int width_box1 = 40;
		int height_box1 = 2;

		system("cls");
		//S: CREATE A NEW CLASS
	HERE:
		std::system("cls");
		std::string ClassID, ClassName, SchoolYear;
		std::cout << "Enter class ID: ";
		std::getline(std::cin, ClassID);
		std::cout << "Enter class name: ";
		std::getline(std::cin, ClassName);
		std::cout << "Enter School Year: ";
		std::getline(std::cin, SchoolYear);

		bool check = 0;
		CLASS_NODE* cur_listclass = listclass;
		while (cur_listclass != nullptr) {
			if (cur_listclass->listclass.ClassID == ClassID) {
				check = 1;
			}
			cur_listclass = cur_listclass->next;
		}
		if (check == 1) {
			std::cout << "The class ID you entered already exists! Please enter again!";
			std::system("pause");
			goto HERE;
		}
		cur_listclass = listclass;
		while (cur_listclass->next != nullptr) {
			cur_listclass = cur_listclass->next;
		}
		cur_listclass->next = new CLASS_NODE;
		cur_listclass->next->listclass.ClassID = ClassID;
		cur_listclass->next->listclass.name = ClassName;
		cur_listclass->next->listclass.schoolYear = stoi(SchoolYear);
		//E: CREATE A NEW CLASS

		my_print(width_tmp1, height_tmp1, YELLOW, "Enter the import file (.csv): ");
		box(width_tmp1, height_tmp1 + 1, width_box1, height_box1, YELLOW);

		gotoXY(width_tmp1 + 1, height_tmp1 + 2);
		std::string filename = my_getline(width_box1 - 1);
		lay_vao_file_newclass(listclass, filename);

		my_print(width_tmp1, height_tmp1 + 5, RED, "Are you sure you want commit? (y/n): ");
		char ans;
		std::cin >> ans;
		gotoXY(width_tmp1, height_tmp1 + 17);
		std::cin.ignore();
		if (ans == 'y' || ans == 'Y') {
			system("cls");
			std::cout << "Add Student(s) to new Class successfully!";
		}
		else {
			system("cls");
			goto AGAIN;
		}
	}
	else if (choose == 2) {
		system("cls");
		ShowCur(1);
		int width_tmp1 = 50;
		int height_tmp1 = 10;
		int width_box1 = 40;
		int height_box1 = 2;

		my_print(width_tmp1, height_tmp1, YELLOW, "Enter the ClassID : ");
		box(width_tmp1, height_tmp1 + 1, width_box1, height_box1, YELLOW);

		gotoXY(width_tmp1 + 1, height_tmp1 + 2);
		std::string NClassID = my_getline(width_box1 - 1);

		if (checkExistClassNODEIDinDLL(listclass, NClassID)) {
			my_print(width_tmp1, height_tmp1, YELLOW, "Enter the import file (.csv): ");
			box(width_tmp1, height_tmp1 + 1, width_box1, height_box1, YELLOW);

			gotoXY(width_tmp1 + 1, height_tmp1 + 2);
			std::string filename = my_getline(width_box1 - 1);
			lay_vao_file_oldclass(listclass, filename);

			my_print(width_tmp1, height_tmp1 + 5, RED, "Are you sure you want commit? (y/n): ");
			std::cin >> check;
			gotoXY(width_tmp1, height_tmp1 + 17);
			std::cin.ignore();
			if (check == 'y' || check == 'Y') {
				system("cls");
				std::cout << "Add Student(s) to new Class successfully!";
			}
			else {
				system("cls");
				goto AGAIN;
			}
		}
		else {
			my_print(width_tmp1, height_tmp1 + 5, RED, "The ClassID you entered does not exist!");
			std::system("pause");
			return;
		}
	}
	else if (choose == 0 + 3) {
		return;
	}
}

void get_current_schoolYear_semester(int coordinate_x, int coordinate_y, std::string& cur_year, std::string& cur_semester) {
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

