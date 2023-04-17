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



void UpdateCourseInfo(STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE*& head) {
	system("cls");
	CR_NODE* cur = head;
	viewListOfCourses(cur);
	int x_tmp = 30;
	int y_tmp = 26;
	int width_tmp = 40;
	int height_tmp = 2;
	my_print(x_tmp, y_tmp, LIGHT_RED, "Enter Course ID: ");
	box(x_tmp, y_tmp + 1, width_tmp, height_tmp, LIGHT_AQUA);
Here_enter_y:
	gotoXY(x_tmp + 1, y_tmp + 1 + 1);
	std::string UpID;
	UpID = my_getline(width_tmp - 1);
	CR_NODE* UpNode = checkExistOfCourseRecord(head, UpID);
	int coordinate_x = 10;
	int coordinate_y = 2;
	int width_box = 40;
	int height_box = 3;
	int distance = 5;

	while (UpNode) {
		system("cls");
		std::string option[] = { "1. Course ID.",
								"2. Course Name.",
								"3. Course Teacher name.",
								"4. Course Credits.",
								"5. Course Max Students.",
								"6. Course Weekday.",
								"7. Course Session.",
								"8. Course Start Date.",
								"9. Course End Date.",
								"0.Come back." };

		int amount = sizeof(option) / sizeof(option[0]);

		int choice;

		n_box(coordinate_x + width_box + distance, coordinate_y, width_box, height_box, amount, LIGHT_AQUA);

		my_print(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 0 * height_box, LIGHT_AQUA, UpNode->course.ID);
		my_print(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 1 * height_box, LIGHT_AQUA, UpNode->course.CName);
		my_print(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 2 * height_box, LIGHT_AQUA, UpNode->course.LNameTeacher + " " + UpNode->course.FNameTeacher);
		my_print(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 3 * height_box, LIGHT_AQUA, std::to_string(UpNode->course.Credits));
		my_print(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 4 * height_box, LIGHT_AQUA, std::to_string(UpNode->course.Max_stdn));
		my_print(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 5 * height_box, LIGHT_AQUA, ConvertStringWD(UpNode->course.dayOfWeek));
		my_print(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 6 * height_box, LIGHT_AQUA, ConvertStringSS(UpNode->course.session));
		std::string startDate = std::to_string(UpNode->course.startDate.day / 10) + std::to_string(UpNode->course.startDate.day % 10) + "/"
			+ std::to_string(UpNode->course.startDate.month / 10) + std::to_string(UpNode->course.startDate.month % 10) + "/"
			+ std::to_string(UpNode->course.startDate.year);
		my_print(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 7 * height_box, LIGHT_AQUA, startDate);
		std::string endDate = std::to_string(UpNode->course.endDate.day / 10) + std::to_string(UpNode->course.endDate.day % 10) + "/"
			+ std::to_string(UpNode->course.endDate.month / 10) + std::to_string(UpNode->course.endDate.month % 10) + "/"
			+ std::to_string(UpNode->course.endDate.year);
		my_print(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 8 * height_box, LIGHT_AQUA, endDate);

		choice = menu(coordinate_x, coordinate_y, width_box, height_box, amount, option, WHITE, LIGHT_YELLOW, LIGHT_GREEN);

	loop_here:




		//system("pause");
		switch (choice) {
		case 1: {
			ShowCur(1);
			my_print(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 0 * height_box, BLACK, UpNode->course.ID);
			textcolor(LIGHT_AQUA);
			gotoXY(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 0 * height_box);
			UpNode->course.ID = my_getline(width_box - 1);
			textcolor(WHITE);
			ShowCur(0);
		}
			  break;
		case 2: {
			ShowCur(1);
			my_print(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 1 * height_box, BLACK, UpNode->course.CName);
			textcolor(LIGHT_AQUA);
			gotoXY(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 1 * height_box);
			UpNode->course.CName = my_getline_addSpace(width_box - 1);
			textcolor(WHITE);
			ShowCur(0);
		} break;
		case 3: {
			ShowCur(1);
			my_print(coordinate_x + 2 * width_box + distance + 5, coordinate_y + height_box, LIGHT_AQUA, "Enter Course Teacher Last name:");
			box(coordinate_x + 2 * width_box + distance + 5, coordinate_y + height_box + 1, width_box - 5, 3, LIGHT_AQUA);
			my_print(coordinate_x + 2 * width_box + distance + 5, coordinate_y + height_box + 5, LIGHT_AQUA, "Enter Course Teacher First name:");
			box(coordinate_x + 2 * width_box + distance + 5, coordinate_y + height_box + +6, width_box - 5, 3, LIGHT_AQUA);

			std::string oldName = UpNode->course.LNameTeacher + " " + UpNode->course.FNameTeacher;

			gotoXY(coordinate_x + 2 * width_box + distance + 5 + 1, coordinate_y + height_box + 1 + 1);
			UpNode->course.LNameTeacher = my_getline_addSpace(width_box - 5 - 1);

			gotoXY(coordinate_x + 2 * width_box + distance + 5 + 1, coordinate_y + height_box + 6 + 1);
			UpNode->course.FNameTeacher = my_getline_addSpace(width_box - 5 - 1);

			my_print(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 2 * height_box, BLACK, oldName);

			my_print(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 2 * height_box, LIGHT_AQUA, UpNode->course.LNameTeacher + " " + UpNode->course.FNameTeacher);

			textcolor(BLACK);
			for (int k = 0; k < 10; k++)
				for (int j = 0; j <= 55; j++) {
					gotoXY(coordinate_x + 2 * width_box + distance + 5 + j, coordinate_y + height_box + k);
					std::cout << " ";
				}
			textcolor(WHITE);
			ShowCur(0);
		} break;
		case 4: {
			ShowCur(1);
			my_print(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 3 * height_box, BLACK, std::to_string(UpNode->course.Credits));
			textcolor(LIGHT_AQUA);
			gotoXY(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 3 * height_box);
			UpNode->course.Credits = stoi(my_getline_onlyNumber(3));
			textcolor(WHITE);
			ShowCur(0);
		} break;
		case 5: {
			ShowCur(1);
			my_print(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 4 * height_box, BLACK, std::to_string(UpNode->course.Max_stdn));
			textcolor(LIGHT_AQUA);
			gotoXY(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 4 * height_box);
			UpNode->course.Max_stdn = stoi(my_getline_onlyNumber(3));
			textcolor(WHITE);
			ShowCur(0);
		} break;
		case 6: {
			ShowCur(1);
			my_print(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 5 * height_box, BLACK, ConvertStringWD(UpNode->course.dayOfWeek));
			textcolor(LIGHT_AQUA);
			gotoXY(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 5 * height_box);
			UpNode->course.dayOfWeek = ConvertEnumWD(my_getline(3));
			textcolor(WHITE);
			ShowCur(0);
		} break;
		case 7: {
			ShowCur(1);
			my_print(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 6 * height_box, BLACK, ConvertStringSS(UpNode->course.session));
			textcolor(LIGHT_AQUA);
			gotoXY(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 6 * height_box);
			UpNode->course.session = ConvertEnumSS(my_getline(2));
			textcolor(WHITE);
			ShowCur(0);
		} break;
		case 8: {
			ShowCur(1);
			int width_small_box = 8;
			/*my_print(coordinate_x, coordinate_y + 3, LIGHT_AQUA, "Enter enrollment day:");*/
			box(coordinate_x + 2 * width_box + distance + 5, coordinate_y + 7 * height_box, width_small_box, height_box, LIGHT_AQUA);
			my_print(coordinate_x + 2 * width_box + distance + 5 + width_small_box + 1, coordinate_y + 7 * height_box + 1, LIGHT_AQUA, "/");
			box(coordinate_x + 2 * width_box + distance + 5 + width_small_box + 2, coordinate_y + 7 * height_box, width_small_box, height_box, LIGHT_AQUA);
			my_print(coordinate_x + 2 * width_box + distance + 5 + 2 * width_small_box + 3, coordinate_y + 7 * height_box + 1, LIGHT_AQUA, "/");
			box(coordinate_x + 2 * width_box + distance + 5 + 2 * width_small_box + 4, coordinate_y + 7 * height_box, width_small_box, height_box, LIGHT_AQUA);

			gotoXY(coordinate_x + 2 * width_box + distance + 5 + 1, coordinate_y + 7 * height_box + 1);
			UpNode->course.startDate.day = stoi(my_getline_onlyNumber(2));

			gotoXY(coordinate_x + 2 * width_box + distance + 5 + width_small_box + 2 + 1, coordinate_y + 7 * height_box + 1);
			UpNode->course.startDate.month = stoi(my_getline_onlyNumber(2));

			gotoXY(coordinate_x + 2 * width_box + distance + 5 + 2 * width_small_box + 3 + 2, coordinate_y + 7 * height_box + 1);
			UpNode->course.startDate.year = stoi(my_getline_onlyNumber(4));
			ShowCur(0);
		} break;
		case 9: {
			ShowCur(1);
			int width_small_box = 8;
			/*my_print(coordinate_x, coordinate_y + 3, LIGHT_AQUA, "Enter enrollment day:");*/
			box(coordinate_x + 2 * width_box + distance + 5, coordinate_y + 8 * height_box, width_small_box, height_box, LIGHT_AQUA);
			my_print(coordinate_x + 2 * width_box + distance + 5 + width_small_box + 1, coordinate_y + 8 * height_box +1  , LIGHT_AQUA, "/");
			box(coordinate_x + 2 * width_box + distance + 5 + width_small_box + 2, coordinate_y + 8 * height_box, width_small_box, height_box, LIGHT_AQUA);
			my_print(coordinate_x + 2 * width_box + distance + 5 + 2 * width_small_box + 3, coordinate_y + 8 * height_box+1 , LIGHT_AQUA, "/");
			box(coordinate_x + 2 * width_box + distance + 5 + 2 * width_small_box + 4, coordinate_y + 8 * height_box, width_small_box, height_box, LIGHT_AQUA);

			gotoXY(coordinate_x + 2 * width_box + distance + 5 + 1, coordinate_y + 8 * height_box +1);
			UpNode->course.endDate.day = stoi(my_getline_onlyNumber(2));

			gotoXY(coordinate_x + 2 * width_box + distance + 5 + width_small_box + 2 + 1, coordinate_y + 8 * height_box +1);
			UpNode->course.endDate.month = stoi(my_getline_onlyNumber(2));

			gotoXY(coordinate_x + 2 * width_box + distance + 5 + 2 * width_small_box + 3 + 2, coordinate_y + 8 * height_box + 1);
			UpNode->course.endDate.year = stoi(my_getline_onlyNumber(4));
			ShowCur(0);
		} break;
		case 0 + 10:
			return;
			break;
		}

		my_print(coordinate_x + 2 * width_box + distance + 10, coordinate_y + 6, LIGHT_GREEN, "Update Course Successfully");
		Read_After_Update_Course(stu_course, teacher, head);
		gotoXY(coordinate_x + 2 * width_box + distance + 10, coordinate_y + 8);
		std::system("pause");

		textcolor(BLACK);
		for (int j = 0; j <= 55; j++) {
			gotoXY(coordinate_x + 2 * width_box + distance + 10, coordinate_y + 6);
			std::cout << " ";
			gotoXY(coordinate_x + 2 * width_box + distance + 10, coordinate_y + 8);
			std::cout << " ";
		}
		textcolor(WHITE);
	}

	my_print(x_tmp + 3, y_tmp + 4, RED, "Your course ID which you entered it does not exist.");
	my_print(x_tmp + 3, y_tmp + 6, LIGHT_GREEN, "Search for Course again? (y/n): ");
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
		for (int j = 0; j < width_tmp - 1; j++) {
			gotoXY(x_tmp + 1 + j, y_tmp + 1 + 1);
			std::cout << " ";
		}
		for (int j = 0; j <= 55; j++) {
			gotoXY(x_tmp + 3 + j, y_tmp + 4);
			std::cout << " ";
			gotoXY(x_tmp + 3 + j, y_tmp + 6);
			std::cout << " ";
		}
		textcolor(WHITE);
		goto Here_enter_y;
	}
	else
		return;

}



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

void createNewSem(SEMESTER semester[], int& count) {
	system("cls");

	if (count > 2) {
		std::cout << "All of semesters have already been created" << std::endl;
		system("pause");
		return;
	}

	ShowCur(1);
	std::ifstream in;
	in.open("NewSchoolYear.csv");

	if (!in.is_open()) {
		std::cout << "cannot open schoolyear file" << std::endl;
		return;
	}


	std::string tmp, schoolyear, tmp2;
	int day, month, year;
	getline(in, tmp);
	while (!in.eof()) {
		getline(in, tmp);
		if (tmp != "")
			schoolyear = tmp;
	}

	tmp = schoolyear.substr(0, 4);
	tmp2 = schoolyear.substr(5);

	semester[count].schoolyear = schoolyear;
	std::cout << "Semester " << count + 1 << std::endl;
	std::cout << "\nSchool Year " << semester[count].schoolyear << std::endl;
	std::cout << "\nInput start date (dd/mm/yy) : ";
	std::cin >> day >> month >> year;
	if (year > stoi(tmp2) || year < stoi(tmp) || month < 1 || month > 12) {
		std::cout << "Your date is invalid, please enter again" << std::endl;
		system("pause");
		return;
	}
	semester[count].startDate.day = (day);
	semester[count].startDate.month = (month);
	semester[count].startDate.year = (year);

	std::cout << "\nInput end date (dd/mm/yy) : ";
	std::cin >> day >> month >> year;
	if (year > stoi(tmp2) || year < stoi(tmp) || month < 1 || month >12) {
		std::cout << "Your date is invalid, please enter again" << std::endl;
		system("pause");
		return;
	}
	semester[count].endDate.day = (day);
	semester[count].endDate.month = (month);
	semester[count].endDate.year = (year);

	count++;
	return;
}

void AddStudent_csv(CLASS_NODE *&listclass) {
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
		getline(std::cin, ClassID);
		std::cout << "Enter class name: ";
		getline(std::cin, ClassName);
		std::cout << "Enter School Year: ";
		getline(std::cin, SchoolYear);

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

		my_print(width_tmp1, height_tmp1, YELLOW, "Enter the import file (Ex: 22CTT02.csv): ");
		box(width_tmp1, height_tmp1 + 1, width_box1, height_box1, YELLOW);
		
		gotoXY(width_tmp1 + 1, height_tmp1 + 2);
		std::string filename = my_getline(width_box1 - 1);
		lay_vao_file_newclass(listclass, filename);

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
	else if (choose == 2) {
		system("cls");
		ShowCur(1);
		int width_tmp1 = 50;
		int height_tmp1 = 10;
		int width_box1 = 40;
		int height_box1 = 2;

		my_print(width_tmp1, height_tmp1, YELLOW, "Enter the new ClassID : ");
		box(width_tmp1, height_tmp1 + 1, width_box1, height_box1, YELLOW);

		gotoXY(width_tmp1 + 1, height_tmp1 + 2);
		std::string NClassID = my_getline(width_box1 - 1); 

		if (checkExistClassNODEIDinDLL(listclass, NClassID)) {
			my_print(width_tmp1, height_tmp1, YELLOW, "Enter the import file (Ex: 22CTT02.csv): ");
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