#include "header.h"


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@COURSE@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//-------Support functions------
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

std::string ConvertStringWD(WEEKDAY wd) {
	if (wd == MON) return "MON";
	else if (wd == TUE) return "TUE";
	else if (wd == WED) return "WED";
	else if (wd == THU) return "THU";
	else if (wd == FRI) return "FRI";
	else return "SAT";
}

std::string ConvertStringSS(SESSION ss) {
	if (ss == S1) return "S1(07:30)";
	else if (ss == S2) return "S2(09:30)";
	else if (ss == S3) return "S3(13:30)";
	else return "S4(15:30)";
}

//--------Main functions---------



//@@@@@@@@@@@@@@@@@@@@@@@@@COURSE_STUDENT@@@@@@@@@@@@@@@@@@@@@@
STU_COURSE* checkExistOfStudentCourseRecord(STU_COURSE_NODE*& head, std::string ID) {
	STU_COURSE_NODE* cur = head;
	while (cur) {
		if (cur->stu_course.StuID == ID) {
			return &cur->stu_course;
		}
		cur = cur->next;
	}
	return nullptr;
}

void UpdateMarksInfo(STU_NODE* student, STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE*& head) {
	system("cls");
	CR_NODE* cur = head;
	viewListOfCourses(cur);

	std::cout << "Enter Course ID: ";
	std::string UpCID;
	std::cin >> UpCID;
	CR_NODE* UpCNode = checkExistOfCourseRecord(head, UpCID);
	if (UpCNode) {
	AGAIN:
		system("cls");
		displayLISTSTUDENTOFCOURSE(stu_course, student, UpCID);
		std::cout << "Enter Student ID: ";
		std::string UpID;
		std::cin >> UpID;
		STU_COURSE* UpNode = checkExistOfStudentCourseRecord(stu_course, UpID);
		if (UpNode) {
			system("cls");

			std::cout << "======================COURSE======================";
			std::cout << "\n\t1. Midterm Grade.\n"
				<< "\t2. Final Grade.\n"
				<< "\t3. Other Grades.\n";
			std::cout << "========================END========================\n\n";
			std::cout << "What would you like to update?: ";

			//system("pause");

			int choice;
			std::cin >> choice;
			switch (choice) {
			case 1: {
				std::cout << "Enter Midterm: ";
				std::cin >> UpNode->midterm;
			} break;
			case 2: {
				std::cout << "Enter Midterm: ";
				std::cin >> UpNode->final;
			} break;
			case 3: {
				std::cout << "Enter Midterm: ";
				std::cin >> UpNode->other;
			} break;
			default: {
				std::cout << "Invalid selection, please enter again.\n\n";
			} break;
			}

			system("cls");
			std::cout << "Update Grade(s) Successfully\n";
			//STU_NODE* student, CR_NODE* course, STFF_NODE* teacher, STU_COURSE_NODE* stu_course
			Read_After_Update_Student_Course(student, head, teacher, stu_course);
			system("pause");
			return;
		}
		else {
			std::cout << "No Student Founded! They might be in another course";
			std::cout << "\nSearch for Student again? (y/n)";
			char ans;
			std::cin >> ans;
			if (ans == 'y' || ans == 'Y') {
				goto AGAIN;
			}
			else {
				return;
			}
		}
	}
	else {
		std::cout << "No Course Found!";
		std::cout << "\nSearch for Course again? (y/n)";
		char ans;
		std::cin >> ans;
		if (ans == 'y' || ans == 'Y') {
			UpdateMarksInfo(student, stu_course, teacher, head);
		}
		else {
			return;
		}
	}
}

/* void updateListCourseRes(CLASS_NODE*& listclass, STU_NODE* student) {
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
} */

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

