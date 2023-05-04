﻿#include "header.h"

////1. CREATE NEW
//1
void create_a_new_school_year() {
	int coordinate_x = 100;
	int coordinate_y = 8;
	int width_box = 40;
	int height_box = 3;
	int width_small_box = 10;

	coordinate_x += 10;
	my_print(coordinate_x - 10, coordinate_y, LIGHT_YELLOW, "Do you want to create a new school year");

	int x_tmp = 110;
	int y_tmp = 10;
	int choice = enter_again_yes_no(x_tmp, y_tmp, 8, 3, 5, LIGHT_AQUA, LIGHT_YELLOW);

	coordinate_x -= 10;
	if (choice == 1) {
		std::ifstream file_schoolYear("schoolYear.txt");
		if (!file_schoolYear.is_open()) {
			textcolor(WHITE * 16 + BLACK);
			gotoXY(coordinate_x - 10, coordinate_y + 8);
			std::cout << "Can not open file schoolYear.txt" << std::endl;
			gotoXY(coordinate_x - 10, coordinate_y + 10);
			std::system("pause");
			textcolor(WHITE);
			return;
		}
		std::string cur_schYear;
		while (!file_schoolYear.eof()) {
			file_schoolYear >> cur_schYear;
		}
		file_schoolYear.close();
		int schYear = stoi(cur_schYear.substr(0, 4));

		std::ifstream file_semester("semester" + std::to_string(schYear) + "_" + std::to_string(schYear + 1) + ".txt");
		if (!file_semester.is_open()) {
			textcolor(WHITE * 16 + BLACK);
			gotoXY(coordinate_x - 10, coordinate_y + 8);
			std::cout << "Can not open file semester" + std::to_string(schYear) + "_" + std::to_string(schYear + 1) + ".txt" << std::endl;
			gotoXY(coordinate_x - 10, coordinate_y + 10);
			std::system("pause");
			textcolor(WHITE);
			return;
		}
		SEMESTER* smter = new SEMESTER[3];
		int i = 0;
		if (file_semester.is_open()) {
			while (!file_semester.eof() && i < 3) {
				std::string tmp;
				std::getline(file_semester, tmp);
				smter[i].semester = stoi(tmp.substr(0, 1));
				i++;
			}
			if (smter[i - 1].semester != 3) {
				textcolor(BLACK * 16 + BLACK);
				for (int j = 0; j < 10; j++)
					for (int i = 0; i < 50; i++) {
						gotoXY(x_tmp - 10 + i, y_tmp - 3 + j);
						std::cout << " ";
					}
				textcolor(WHITE);

				textcolor(WHITE * 16 + BLACK);
				gotoXY(coordinate_x - 10, coordinate_y + 2);
				std::cout << "Please create the next semester for the current school year before." << std::endl;
				gotoXY(coordinate_x - 10, coordinate_y + 4);
				std::system("pause");
				textcolor(WHITE);
			}
			else {
				std::ofstream file_schoolYear("schoolYear.txt", std::ios::app);
				file_schoolYear << "\n" << schYear + 1 << "-" << schYear + 2;
				file_schoolYear.close();

				std::ofstream file_next_semester("semester" + std::to_string(schYear + 1) + "_" + std::to_string(schYear + 2) + ".txt");
				SEMESTER* smter_next = new SEMESTER;
				textcolor(BLACK * 16 + BLACK);
				for (int j = 0; j < 10; j++)
					for (int i = 0; i < 50; i++) {
						gotoXY(x_tmp - 10 + i, y_tmp - 3 + j);
						std::cout << " ";
					}
				textcolor(WHITE);

				textcolor(LIGHT_YELLOW * 16 + BLACK);
				for (int j = 0; j < 3; j++)
					for (int i = 0; i < 40; i++) {
						gotoXY(coordinate_x + 2 + i, coordinate_y - 5 + j);
						std::cout << " ";
					}
				gotoXY(coordinate_x + 2 + 8, coordinate_y - 5 + 1);
				std::cout << "CREATE A NEW SCHOOL YEAR";
				textcolor(WHITE);

				my_print(coordinate_x, coordinate_y, LIGHT_AQUA, "Semester:");
				box(coordinate_x, coordinate_y + 1, width_small_box, height_box, LIGHT_AQUA);
				my_print(coordinate_x + 1 + 4, coordinate_y + 2, LIGHT_RED, "1");

				my_print(coordinate_x, coordinate_y + 5, LIGHT_AQUA, "School Year:");
				box(coordinate_x, coordinate_y + 5 + 1, width_box, height_box, LIGHT_AQUA);
				my_print(coordinate_x + 1 + 15, coordinate_y + 5 + 2, LIGHT_RED, std::to_string(schYear + 1) + "-" + std::to_string(schYear + 2));

				my_print(coordinate_x, coordinate_y + 10, LIGHT_AQUA, "The start date of the semester:");
				box(coordinate_x, coordinate_y + 10 + 1, width_small_box, height_box, LIGHT_AQUA);
				my_print(coordinate_x + width_small_box + 1, coordinate_y + 10 + 2, LIGHT_AQUA, "/");
				box(coordinate_x + width_small_box + 2, coordinate_y + 10 + 1, width_small_box, height_box, LIGHT_AQUA);
				my_print(coordinate_x + 2 * width_small_box + 3, coordinate_y + 10 + 2, LIGHT_AQUA, "/");
				box(coordinate_x + 2 * width_small_box + 4, coordinate_y + 10 + 1, width_small_box, height_box, LIGHT_AQUA);

				my_print(coordinate_x, coordinate_y + 15, LIGHT_AQUA, "The end date of the semester:");
				box(coordinate_x, coordinate_y + 15 + 1, width_small_box, height_box, LIGHT_AQUA);
				my_print(coordinate_x + width_small_box + 1, coordinate_y + 15 + 2, LIGHT_AQUA, "/");
				box(coordinate_x + width_small_box + 2, coordinate_y + 15 + 1, width_small_box, height_box, LIGHT_AQUA);
				my_print(coordinate_x + 2 * width_small_box + 3, coordinate_y + 15 + 2, LIGHT_AQUA, "/");
				box(coordinate_x + 2 * width_small_box + 4, coordinate_y + 15 + 1, width_small_box, height_box, LIGHT_AQUA);

				ShowCur(1);

				gotoXY(coordinate_x + 1 + 3, coordinate_y + 10 + 1 + 1);
				std::string tmp = my_getline_onlyNumber(2);
				if (tmp == "-1") return;
				else smter_next->startDate.day = stoi(tmp);

				gotoXY(coordinate_x + width_small_box + 2 + 1 + 3, coordinate_y + 10 + 1 + 1);
				tmp = my_getline_onlyNumber(2);
				if (tmp == "-1") return;
				else smter_next->startDate.month = stoi(tmp);

				gotoXY(coordinate_x + 2 * width_small_box + 4 + 1 + 2, coordinate_y + 10 + 1 + 1);
				tmp = my_getline_onlyNumber(4);
				if (tmp == "-1") return;
				else smter_next->startDate.year = stoi(tmp);


				gotoXY(coordinate_x + 1 + 3, coordinate_y + 15 + 1 + 1);
				tmp = my_getline_onlyNumber(2);
				if (tmp == "-1") return;
				else smter_next->endDate.day = stoi(tmp);

				gotoXY(coordinate_x + width_small_box + 2 + 1 + 3, coordinate_y + 15 + 1 + 1);
				tmp = my_getline_onlyNumber(2);
				if (tmp == "-1") return;
				else smter_next->endDate.month = stoi(tmp);

				gotoXY(coordinate_x + 2 * width_small_box + 4 + 1 + 2, coordinate_y + 15 + 1 + 1);
				tmp = my_getline_onlyNumber(4);
				if (tmp == "-1") return;
				else smter_next->endDate.year = stoi(tmp);

				//TESTING

				if (Test_ifValid_Date(smter_next)) {
					file_next_semester << "1,"
						<< smter_next->startDate.day << "/"
						<< smter_next->startDate.month << "/"
						<< smter_next->startDate.year << ","
						<< smter_next->endDate.day << "/"
						<< smter_next->endDate.month << "/"
						<< smter_next->endDate.year;

					textcolor(BLACK * 16 + BLACK);
					for (int j = 0; j < 20; j++)
						for (int i = 0; i < 41; i++) {
							gotoXY(coordinate_x + i, coordinate_y + j);
							std::cout << " ";
						}
					textcolor(WHITE);

					textcolor(LIGHT_GREEN * 16 + BLACK);
					for (int j = 0; j < 3; j++)
						for (int i = 0; i < 41; i++) {
							gotoXY(coordinate_x + 2 + i, coordinate_y + 8 + j);
							std::cout << " ";
						}
					gotoXY(coordinate_x + 4 + 1, coordinate_y + 8 + 1);
					std::cout << "Created the new school year successfully.";
					textcolor(WHITE);

					char ch;
					ch = _getch();

					delete smter_next;
					file_next_semester.close();
				}
				else {
					textcolor(BLACK * 16 + BLACK);
					for (int j = 0; j < 20; j++)
						for (int i = 0; i < 41; i++) {
							gotoXY(coordinate_x + i, coordinate_y + j);
							std::cout << " ";
						}
					textcolor(WHITE);

					textcolor(LIGHT_GREEN * 16 + BLACK);
					for (int j = 0; j < 3; j++)
						for (int i = 0; i < 41; i++) {
							gotoXY(coordinate_x + i, coordinate_y + 8 + j);
							std::cout << " ";
						}
					gotoXY(coordinate_x + 2 + 1, coordinate_y + 8 + 1);
					std::cout << "Date is not valid.";
					textcolor(WHITE);

					char ch;
					ch = _getch();

					delete smter_next;
					delete[] smter;
					file_semester.close();
					return;
				}
			}
		}
		delete[] smter;
		file_semester.close();
	}
	else if (choice == 2) {
		return;
	}
}
//2
void create_semester() {
	int coordinate_x = 100;
	int coordinate_y = 8;
	int width_box = 40;
	int height_box = 3;
	int width_small_box = 10;

	std::ifstream file_schoolYear("schoolYear.txt");
	if (!file_schoolYear.is_open()) {
		textcolor(WHITE * 16 + BLACK);
		gotoXY(coordinate_x - 10, coordinate_y + 8);
		std::cout << "Can not open file schoolYear.txt" << std::endl;
		gotoXY(coordinate_x - 10, coordinate_y + 10);
		std::system("pause");
		textcolor(WHITE);
		return;
	}
	std::string cur_schYear;
	while (!file_schoolYear.eof()) {
		file_schoolYear >> cur_schYear;
	}
	file_schoolYear.close();
	int schYear = stoi(cur_schYear.substr(0, 4));

	std::ifstream file_semester("semester" + std::to_string(schYear) + "_" + std::to_string(schYear + 1) + ".txt");
	if (!file_semester.is_open()) {
		textcolor(WHITE * 16 + BLACK);
		gotoXY(coordinate_x - 10, coordinate_y + 8);
		std::cout << "Can not open file semester" + std::to_string(schYear) + "_" + std::to_string(schYear + 1) + ".txt" << std::endl;
		gotoXY(coordinate_x - 10, coordinate_y + 10);
		std::system("pause");
		textcolor(WHITE);
		return;
	}
	SEMESTER* smter = new SEMESTER[3];
	int i = 0;
	if (file_semester.is_open()) {
		while (!file_semester.eof() && i < 3) {
			std::string tmp;
			std::getline(file_semester, tmp);
			smter[i].semester = stoi(tmp.substr(0, 1));
			i++;
		}
		if (smter[i - 1].semester == 3) {
			textcolor(WHITE * 16 + BLACK);
			gotoXY(coordinate_x - 10, coordinate_y + 8);
			std::cout << "You have created three semesters" << std::endl;
			gotoXY(coordinate_x - 10, coordinate_y + 10);
			std::system("pause");
			textcolor(WHITE);
			return;
		}
		else {
			SEMESTER* smter_next = new SEMESTER;

			textcolor(LIGHT_YELLOW * 16 + BLACK);
			for (int j = 0; j < 3; j++)
				for (int i = 0; i < 40; i++) {
					gotoXY(coordinate_x + 2 + i, coordinate_y - 5 + j);
					std::cout << " ";
				}
			gotoXY(coordinate_x + 2 + 8, coordinate_y - 5 + 1);
			std::cout << "CREATE A NEW SCHOOL YEAR";
			textcolor(WHITE);

			my_print(coordinate_x, coordinate_y, LIGHT_AQUA, "Semester:");
			box(coordinate_x, coordinate_y + 1, width_small_box, height_box, LIGHT_AQUA);
			my_print(coordinate_x + 1 + 4, coordinate_y + 2, LIGHT_RED, std::to_string(++i));

			my_print(coordinate_x, coordinate_y + 5, LIGHT_AQUA, "School Year:");
			box(coordinate_x, coordinate_y + 5 + 1, width_box, height_box, LIGHT_AQUA);
			my_print(coordinate_x + 1 + 15, coordinate_y + 5 + 2, LIGHT_RED, std::to_string(schYear) + "-" + std::to_string(schYear + 1));

			my_print(coordinate_x, coordinate_y + 10, LIGHT_AQUA, "The start date of the semester:");
			box(coordinate_x, coordinate_y + 10 + 1, width_small_box, height_box, LIGHT_AQUA);
			my_print(coordinate_x + width_small_box + 1, coordinate_y + 10 + 2, LIGHT_AQUA, "/");
			box(coordinate_x + width_small_box + 2, coordinate_y + 10 + 1, width_small_box, height_box, LIGHT_AQUA);
			my_print(coordinate_x + 2 * width_small_box + 3, coordinate_y + 10 + 2, LIGHT_AQUA, "/");
			box(coordinate_x + 2 * width_small_box + 4, coordinate_y + 10 + 1, width_small_box, height_box, LIGHT_AQUA);

			my_print(coordinate_x, coordinate_y + 15, LIGHT_AQUA, "The end date of the semester:");
			box(coordinate_x, coordinate_y + 15 + 1, width_small_box, height_box, LIGHT_AQUA);
			my_print(coordinate_x + width_small_box + 1, coordinate_y + 15 + 2, LIGHT_AQUA, "/");
			box(coordinate_x + width_small_box + 2, coordinate_y + 15 + 1, width_small_box, height_box, LIGHT_AQUA);
			my_print(coordinate_x + 2 * width_small_box + 3, coordinate_y + 15 + 2, LIGHT_AQUA, "/");
			box(coordinate_x + 2 * width_small_box + 4, coordinate_y + 15 + 1, width_small_box, height_box, LIGHT_AQUA);

			ShowCur(1);

			gotoXY(coordinate_x + 1 + 3, coordinate_y + 10 + 1 + 1);
			std::string tmp = my_getline_onlyNumber(2);
			if (tmp == "-1") return;
			else smter_next->startDate.day = stoi(tmp);

			gotoXY(coordinate_x + width_small_box + 2 + 1 + 3, coordinate_y + 10 + 1 + 1);
			tmp = my_getline_onlyNumber(2);
			if (tmp == "-1") return;
			else smter_next->startDate.month = stoi(tmp);

			gotoXY(coordinate_x + 2 * width_small_box + 4 + 1 + 2, coordinate_y + 10 + 1 + 1);
			tmp = my_getline_onlyNumber(4);
			if (tmp == "-1") return;
			else smter_next->startDate.year = stoi(tmp);


			gotoXY(coordinate_x + 1 + 3, coordinate_y + 15 + 1 + 1);
			tmp = my_getline_onlyNumber(2);
			if (tmp == "-1") return;
			else smter_next->endDate.day = stoi(tmp);

			gotoXY(coordinate_x + width_small_box + 2 + 1 + 3, coordinate_y + 15 + 1 + 1);
			tmp = my_getline_onlyNumber(2);
			if (tmp == "-1") return;
			else smter_next->endDate.month = stoi(tmp);

			gotoXY(coordinate_x + 2 * width_small_box + 4 + 1 + 2, coordinate_y + 15 + 1 + 1);
			tmp = my_getline_onlyNumber(4);
			if (tmp == "-1") return;
			else smter_next->endDate.year = stoi(tmp);

			//TESTING
			if (Test_ifValid_Date(smter_next)) {
				std::fstream file_next_semester("semester" + std::to_string(schYear) + "_" + std::to_string(schYear + 1) + ".txt", std::ios::app);

				file_next_semester << "\n" << i << ","
					<< smter_next->startDate.day << "/"
					<< smter_next->startDate.month << "/"
					<< smter_next->startDate.year << ","
					<< smter_next->endDate.day << "/"
					<< smter_next->endDate.month << "/"
					<< smter_next->endDate.year;

				textcolor(BLACK * 16 + BLACK);
				for (int j = 0; j < 20; j++)
					for (int i = 0; i < 41; i++) {
						gotoXY(coordinate_x + i, coordinate_y + j);
						std::cout << " ";
					}
				textcolor(WHITE);

				textcolor(LIGHT_GREEN * 16 + BLACK);
				for (int j = 0; j < 3; j++)
					for (int i = 0; i < 41; i++) {
						gotoXY(coordinate_x + 2 + i, coordinate_y + 8 + j);
						std::cout << " ";
					}
				gotoXY(coordinate_x + 4 + 1, coordinate_y + 8 + 1);
				std::cout << "Created the semester successfully.";
				textcolor(WHITE);

				char ch;
				ch = _getch();

				delete smter_next;
				file_next_semester.close();
			}
		}
		delete[] smter;
		file_semester.close();
	}
}
//3
void create_a_new_class(CLASS_NODE*& listclass) {

	int coordinate_x = 100;
	int coordinate_y = 10;
	int width_box = 40;
	int width_small_box = 10;
	int height_box = 2;

	int color_box_title = LIGHT_AQUA;

	textcolor(LIGHT_YELLOW * 16 + BLACK);
	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 40; i++) {
			gotoXY(coordinate_x + i, coordinate_y - 7 + j);
			std::cout << " ";
		}
	gotoXY(coordinate_x + 11, coordinate_y - 7 + 1);
	std::cout << "CREATE A NEW CLASS";
	textcolor(BLACK);

Here:
	my_print(coordinate_x, coordinate_y, color_box_title, "Enter Class ID:");
	box(coordinate_x, coordinate_y + 1, width_box, height_box, color_box_title);

	my_print(coordinate_x, coordinate_y + height_box + 2, color_box_title, "Enter Class Name:");
	box(coordinate_x, coordinate_y + height_box + 2 + 1, width_box, height_box, color_box_title);

	my_print(coordinate_x, coordinate_y + 2 * height_box + 4, color_box_title, "Enter School Year:");
	box(coordinate_x, coordinate_y + 2 * height_box + 4 + 1, width_small_box, height_box, color_box_title);
	my_print(coordinate_x + width_small_box + 1, coordinate_y + 2 * height_box + 4 + 2, color_box_title, "-");
	box(coordinate_x + width_small_box + 2, coordinate_y + 2 * height_box + 4 + 1, width_small_box, height_box, color_box_title);

	CLASS newClass;
	ShowCur(1);
	//getline
	std::string tmp;
	gotoXY(coordinate_x + 1, coordinate_y + 1 + 1);
	tmp = my_getline(width_box - 1);
	if (tmp == "-1") return;
	else newClass.ClassID = tmp;

	gotoXY(coordinate_x + 1, coordinate_y + height_box + 2 + 1 + 1);
	tmp = my_getline_addSpace(width_box - 1);
	if (tmp == "-1") return;
	else newClass.name = tmp;

	gotoXY(coordinate_x + 1, coordinate_y + 2 * height_box + 4 + 1 + 1);
	tmp = my_getline_onlyNumber(4);
	if (tmp == "-1") return;
	else newClass.schoolYear = stoi(tmp);

	gotoXY(coordinate_x + width_small_box + 2 + 1, coordinate_y + 2 * height_box + 4 + 1 + 1);
	std::cout << newClass.schoolYear + 1;

	bool check = 0;
	CLASS_NODE* cur_listclass = listclass;
	while (cur_listclass != nullptr) {
		if (cur_listclass->listclass.ClassID == newClass.ClassID) {
			check = 1;
		}
		cur_listclass = cur_listclass->next;
	}
	cur_listclass = nullptr;
	if (check == 1) {

		my_print(coordinate_x, coordinate_y + 14, RED * 16 + LIGHT_AQUA, "The class ID you entered already exists.");


		my_print(coordinate_x, coordinate_y + 16, LIGHT_GREEN * 16 + BLACK, "Do you want to enter again:");

		ShowCur(0);
		int choice = enter_again_yes_no(coordinate_x + 5, coordinate_y + 18, 7, 3, 3, LIGHT_AQUA, LIGHT_GREEN);

		if (choice == 1) {
			textcolor(BLACK * 16 + BLACK);
			for (int j = 0; j < 22; j++)
				for (int i = 0; i < 41; i++) {
					gotoXY(coordinate_x + i, coordinate_y + j);
					std::cout << " ";
				}
			textcolor(BLACK * 16 + WHITE);
			goto Here;
		}
		else
			return;
	}
	textcolor(LIGHT_GREEN * 16 + BLACK);
	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 40; i++) {
			gotoXY(coordinate_x + i, coordinate_y + 14 + j);
			std::cout << " ";
		}
	gotoXY(coordinate_x + 3, coordinate_y + 14 + 1);
	std::cout << "Created a new class successfully.";
	textcolor(WHITE);
	char ans = _getch();


	if (listclass == nullptr) {
		listclass = new CLASS_NODE;
		listclass->listclass = newClass;
	}
	else {
		cur_listclass = listclass;
		while (cur_listclass != nullptr) {
			if (cur_listclass->next == nullptr)
				break;
			cur_listclass = cur_listclass->next;
		}
		cur_listclass->next = new CLASS_NODE;
		cur_listclass->next->listclass = newClass;
	}
}
//4
void UpdateTeacherInfor(STFF_NODE*& teacher) {
	std::system("cls");
	displayListOfTeachers(teacher);

	int coordinate_x_display = 30;
	int coordinate_y_display = 25;
	int width_box_display = 40;
	int height_box_display = 2;

enter_teacherID:

	my_print(coordinate_x_display, coordinate_y_display, BLACK * 16 + LIGHT_RED, "Enter the ID of the teacher you want to update:");
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
		my_print(coordinate_x_display, coordinate_y_display + 5, RED * 16 + LIGHT_AQUA, "Teacher ID doesn't exist.");

		my_print(coordinate_x_display + 50, coordinate_y_display + 1, LIGHT_GREEN * 16 + BLACK, "Do you want to enter again:");
		int choice = enter_again_yes_no(coordinate_x_display + 50, coordinate_y_display + 3, 8, 3, 4, LIGHT_AQUA, LIGHT_GREEN);
		if (choice == 1) {
			textcolor(BLACK * 16 + BLACK);
			for (int j = 0; j < 8; j++)
				for (int i = 0; i < 77; i++) {
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
			Read_After_Update_Teachers(teacher);
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
			Read_After_Update_Teachers(teacher);
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
			Read_After_Update_Teachers(teacher);
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
			Read_After_Update_Teachers(teacher);
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
			Read_After_Update_Teachers(teacher);
		}
		goto update_infor;
	}
	else if (choice == 0 + 6) {
		return;
	}
}
//5
void UpdateYourInfor(STFF_NODE*& loggedinStaff, STFF_NODE*& teacher, STFF_NODE*& staff) {
	STFF_NODE* cur_teacher = teacher;
	int check = 0;
	while (cur_teacher) {
		if (cur_teacher->staff.TeacherID == loggedinStaff->staff.TeacherID) {
			check = 1;
			break;
		}
		cur_teacher = cur_teacher->next;
	}

update_Yourinfor:
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

	std::string fullname = loggedinStaff->staff.LName + " " + loggedinStaff->staff.FName;
	std::string DoB = std::to_string(loggedinStaff->staff.DoB.day / 10) + std::to_string(loggedinStaff->staff.DoB.day % 10) + "/"
		+ std::to_string(loggedinStaff->staff.DoB.month / 10) + std::to_string(loggedinStaff->staff.DoB.month % 10) + "/"
		+ std::to_string(loggedinStaff->staff.DoB.year);

	textcolor(color_text);
	gotoXY(coordinate_x_infor + 1, coordinate_y_infor + 1);
	std::cout << std::setw(15) << std::left << "Full name : " << std::setw(44) << std::right << fullname;
	gotoXY(coordinate_x_infor + 1, coordinate_y_infor + 2);
	std::cout << std::setw(15) << std::left << "Teacher ID: " << std::setw(44) << std::right << loggedinStaff->staff.TeacherID;
	gotoXY(coordinate_x_infor + 1, coordinate_y_infor + 3);
	std::cout << std::setw(15) << std::left << "Gender: " << std::setw(44) << std::right << loggedinStaff->staff.Gender;
	gotoXY(coordinate_x_infor + 1, coordinate_y_infor + 4);
	std::cout << std::setw(15) << std::left << "Date of birth: " << std::setw(44) << std::right << DoB;
	gotoXY(coordinate_x_infor + 1, coordinate_y_infor + 5);
	std::cout << std::setw(15) << std::left << "Social ID: " << std::setw(44) << std::right << loggedinStaff->staff.SocialID;
	gotoXY(coordinate_x_infor + 1, coordinate_y_infor + 6);
	std::cout << std::setw(15) << std::left << "Faculty: " << std::setw(44) << std::right << loggedinStaff->staff.Faculty;
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
			goto update_Yourinfor;

		ShowCur(1);
		gotoXY(coordinate_x + 1, coordinate_y + -2 + 11 + 2);
		FName = my_getline_addSpace(width_box - 1);
		ShowCur(0);
		if (FName == "-1")
			goto update_Yourinfor;

		my_print(coordinate_x + 36 + 1, coordinate_y - 5 + 6 + 2 + 4, LIGHT_GREEN, "Are you sure you want to change?");
		int choose = enter_again_yes_no(coordinate_x + 36 + 1, coordinate_y - 5 + 13, 8, 3, 4, LIGHT_AQUA, LIGHT_GREEN);
		if (choose == 1) {
			loggedinStaff->staff.LName = LName;
			loggedinStaff->staff.FName = FName;
			if (check == 1) {
				cur_teacher->staff.LName = LName;
				cur_teacher->staff.FName = FName;
				Read_After_Update_Teachers(teacher);
			}
			Read_After_Update_Staffs(staff);
		}
		goto update_Yourinfor;
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
			goto update_Yourinfor;

		my_print(coordinate_x + 1, coordinate_y + 6 + 2 + 4, LIGHT_GREEN, "Are you sure you want to change?");
		int choose = enter_again_yes_no(coordinate_x + 1, coordinate_y + 13, 8, 3, 4, LIGHT_AQUA, LIGHT_GREEN);
		if (choose == 1) {
			loggedinStaff->staff.Gender = tmp;
			if (check == 1) {
				cur_teacher->staff.Gender = tmp;
				Read_After_Update_Teachers(teacher);
			}
			Read_After_Update_Staffs(staff);
		}
		goto update_Yourinfor;
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
			goto update_Yourinfor;
		else
			newDOB.day = stoi(tmp);

		ShowCur(1);
		gotoXY(coordinate_x + width_small_box + 2 + 1, coordinate_y + 6 + 2);
		tmp = my_getline_onlyNumber(2);
		ShowCur(0);
		if (tmp == "-1")
			goto update_Yourinfor;
		else
			newDOB.month = stoi(tmp);

		ShowCur(1);
		gotoXY(coordinate_x + 2 * width_small_box + 4 + 1, coordinate_y + 6 + 2);
		tmp = my_getline_onlyNumber(4);
		ShowCur(0);
		if (tmp == "-1")
			goto update_Yourinfor;
		else
			newDOB.year = stoi(tmp);

		my_print(coordinate_x + 1, coordinate_y + 6 + 2 + 4, LIGHT_GREEN, "Are you sure you want to change?");
		int choose = enter_again_yes_no(coordinate_x + 1, coordinate_y + 13, 8, 3, 4, LIGHT_AQUA, LIGHT_GREEN);
		if (choose == 1) {
			loggedinStaff->staff.DoB = newDOB;
			if (check == 1) {
				cur_teacher->staff.DoB = newDOB;
				Read_After_Update_Teachers(teacher);
			}
			Read_After_Update_Staffs(staff);
		}
		goto update_Yourinfor;
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
		tmp = my_getline(width_box - 1);
		ShowCur(0);
		if (tmp == "-1")
			goto update_Yourinfor;

		my_print(coordinate_x + 1, coordinate_y + 6 + 2 + 4, LIGHT_GREEN, "Are you sure you want to change?");
		int choose = enter_again_yes_no(coordinate_x + 1, coordinate_y + 13, 8, 3, 4, LIGHT_AQUA, LIGHT_GREEN);
		if (choose == 1) {
			loggedinStaff->staff.SocialID = tmp;
			if (check == 1) {
				cur_teacher->staff.SocialID = tmp;
				Read_After_Update_Teachers(teacher);
			}
			Read_After_Update_Staffs(staff);
		}
		goto update_Yourinfor;
	}
	else if (choice == 5) {
		textcolor(LIGHT_YELLOW * 16 + BLACK);
		for (int j = 0; j < 3; j++)
			for (int i = 0; i < 40; i++) {
				gotoXY(coordinate_x + i, coordinate_y + j);
				std::cout << " ";
			}
		gotoXY(coordinate_x + 13 + 1, coordinate_y + 1);
		std::cout << "UPDATE FACULTY";
		textcolor(WHITE);

		my_print(coordinate_x, coordinate_y + 6, LIGHT_RED, "Enter faculty which you want to update:");
		box(coordinate_x, coordinate_y + 6 + 1, width_box, height_box, LIGHT_AQUA);
		gotoXY(coordinate_x + 1, coordinate_y + 6 + 2);
		ShowCur(1);
		tmp = my_getline_addSpace(width_box - 1);
		ShowCur(0);
		if (tmp == "-1")
			goto update_Yourinfor;

		my_print(coordinate_x + 1, coordinate_y + 6 + 2 + 4, LIGHT_GREEN, "Are you sure you want to change?");
		int choose = enter_again_yes_no(coordinate_x + 1, coordinate_y + 13, 8, 3, 4, LIGHT_AQUA, LIGHT_GREEN);
		if (choose == 1) {
			loggedinStaff->staff.Faculty = tmp;
			if (check == 1) {
				cur_teacher->staff.Faculty = tmp;
				Read_After_Update_Teachers(teacher);
			}
			Read_After_Update_Staffs(staff);
		}
		goto update_Yourinfor;
	}
	else if (choice == 0 + 6) {
		return;
	}
}
//6 
void Create_newStaff(STFF_NODE* staff) {
	int coordinate_x = 100;
	int coordinate_y = 1;
	int width_box = 40;
	int width_small_box = 10;
	int height_box = 2;
	int text_color = YELLOW;
	int color = LIGHT_AQUA;

	textcolor(LIGHT_YELLOW * 16 + BLACK);
	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 40; i++) {
			gotoXY(coordinate_x + i, coordinate_y + j);
			std::cout << " ";
		}
	gotoXY(coordinate_x + 6, coordinate_y + 1);
	std::cout << "CREATE A NEW STAFF ACCOUNT";
	textcolor(WHITE);

	my_print(coordinate_x, coordinate_y + 4, text_color, "Enter Last Name:");
	box(coordinate_x, coordinate_y + 1 + 4, width_box - 20, height_box, color);

	my_print(coordinate_x + 25, coordinate_y + 4, text_color, "First Name:");
	box(coordinate_x + 25, coordinate_y + 1 + 4, width_small_box + 5, height_box, color);

	my_print(coordinate_x, coordinate_y + 8, text_color, "Enter The Staff's Gender:");
	box(coordinate_x, coordinate_y + 1 + 8, width_box, height_box, color);

	my_print(coordinate_x, coordinate_y + 12, text_color, "Enter Staff's ID :");
	box(coordinate_x, coordinate_y + 1 + 12, width_box, height_box, color);

	my_print(coordinate_x, coordinate_y + 16, text_color, "Enter Staff's Password:");
	box(coordinate_x, coordinate_y + 1 + 16, width_box, height_box, color);

	my_print(coordinate_x, coordinate_y + 20, text_color, "Enter Staff's Date of Birth:");
	box(coordinate_x, coordinate_y + 1 + 20, width_small_box, height_box, color);
	my_print(coordinate_x + width_small_box + 1, coordinate_y + 1 + 20 + 1, color, "/");
	box(coordinate_x + width_small_box + 2, coordinate_y + 1 + 20, width_small_box, height_box, color);
	my_print(coordinate_x + 2 * width_small_box + 3, coordinate_y + 1 + 20 + 1, color, "/");
	box(coordinate_x + 2 * width_small_box + 4, coordinate_y + 1 + 20, width_small_box, height_box, color);

	my_print(coordinate_x, coordinate_y + 24, text_color, "Enter Staff's Social ID:");
	box(coordinate_x, coordinate_y + 1 + 24, width_box, height_box, color);

	my_print(coordinate_x, coordinate_y + 28, text_color, "Enter Staff's Faculty:");
	box(coordinate_x, coordinate_y + 1 + 28, width_box, height_box, color);

	//getline
	std::string tmp;
	STAFF NewStaff;
	STFF_NODE* cur = staff;
	while (cur->next) {
		cur = cur->next;
	}
	if (staff == nullptr)
		NewStaff.No_Staff = 1;
	else
		NewStaff.No_Staff = cur->staff.No_Staff + 1;

	ShowCur(1);

	gotoXY(coordinate_x + 1, coordinate_y + 1 + 4 + 1);
	tmp = my_getline_addSpace(width_box - 20 - 1);
	if (tmp == "-1")
		return;
	else
		NewStaff.LName = tmp;

	gotoXY(coordinate_x + 25 + 1, coordinate_y + 1 + 4 + 1);
	tmp = my_getline_addSpace(width_small_box + 5 - 1);
	if (tmp == "-1")
		return;
	else
		NewStaff.FName = tmp;

	gotoXY(coordinate_x + 1, coordinate_y + 1 + 8 + 1);
	tmp = my_getline_addSpace(width_box - 1);
	if (tmp == "-1")
		return;
	else
		NewStaff.Gender = tmp;

	gotoXY(coordinate_x + 1, coordinate_y + 1 + 12 + 1);
	tmp = my_getline(width_box - 1);
	if (tmp == "-1")
		return;
	else
		NewStaff.TeacherID = tmp;

	gotoXY(coordinate_x + 1, coordinate_y + 1 + 16 + 1);
	tmp = my_getline(width_box - 1);
	if (tmp == "-1")
		return;
	else
		NewStaff.Password = tmp;

	gotoXY(coordinate_x + 1, coordinate_y + 1 + 20 + 1);
	tmp = my_getline_onlyNumber(2);
	if (tmp == "-1")
		return;
	else
		NewStaff.DoB.day = stoi(tmp);

	gotoXY(coordinate_x + width_small_box + 2 + 1, coordinate_y + 1 + 20 + 1);
	tmp = my_getline_onlyNumber(2);
	if (tmp == "-1")
		return;
	else
		NewStaff.DoB.month = stoi(tmp);

	gotoXY(coordinate_x + 2 * width_small_box + 4 + 1, coordinate_y + 1 + 20 + 1);
	tmp = my_getline_onlyNumber(4);
	if (tmp == "-1")
		return;
	else
		NewStaff.DoB.year = stoi(tmp);

	gotoXY(coordinate_x + 1, coordinate_y + 1 + 24 + 1);
	tmp = my_getline(width_box - 1);
	if (tmp == "-1")
		return;
	else
		NewStaff.SocialID = tmp;

	gotoXY(coordinate_x + 1, coordinate_y + 1 + 28 + 1);
	tmp = my_getline_addSpace(width_box - 1);
	if (tmp == "-1")
		return;
	else
		NewStaff.Faculty = tmp;

	//Add course at the end

	if (staff == nullptr) {
		staff = new STFF_NODE;
		staff->staff = NewStaff;
	}
	else {
		cur->next = new STFF_NODE;
		cur->next->staff = NewStaff;
		cur->next->prev = cur;
	}
	ShowCur(0);
	textcolor(BLACK * 16 + BLACK);
	for (int j = 0; j < 28; j++)
		for (int i = 0; i < 41; i++) {
			gotoXY(coordinate_x + i, coordinate_y + 4 + j);
			std::cout << " ";
		}
	textcolor(WHITE);

	textcolor(LIGHT_GREEN * 16 + BLACK);
	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 41; i++) {
			gotoXY(coordinate_x + i, coordinate_y + 10 + j);
			std::cout << " ";
		}
	gotoXY(coordinate_x + 4, coordinate_y + 10 + 1);
	std::cout << "Create a new staff successfully.";
	textcolor(WHITE);

	char ans = _getch();

	Read_After_Update_Staffs(staff);
	return;
}
////2. ENTER INFORMATION
//1
void addNew1styearStudent(STU_NODE*& student, CLASS_NODE* listclass) {
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
	Read_After_Update_Students(student);
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

	std::string NewSchoolyear, tmp;
	my_print(coordinate_x, coordinate_y, LIGHT_AQUA, "Enter School Year:");
	box(coordinate_x, coordinate_y + 1, width_small_box, height_box, LIGHT_AQUA);
Here_enter_y:
	gotoXY(coordinate_x + 1, coordinate_y + 1 + 1);
	tmp = (my_getline_onlyNumber(4));
	if (tmp == "-1")
		return;
	else
		NewSchoolyear = (tmp);
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
	tmp = my_getline_onlyNumber(1);
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
	tmp = (my_getline_addSpace(width_big_box - 1));
	if (tmp == "-1")
		return;
	else
		NewCourse->course.CName = (tmp);

	my_print(coordinate_x, coordinate_y + 8, LIGHT_AQUA, "Enter Course ID:");
	box(coordinate_x, coordinate_y + 8 + 1, width_big_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 1, coordinate_y + 8 + 1 + 1);
	tmp = (my_getline(width_big_box - 1));
	if (tmp == "-1")
		return;
	else
		NewCourse->course.ID = (tmp);

	my_print(coordinate_x, coordinate_y + 12, LIGHT_AQUA, "Enter Teacher's last name:");
	box(coordinate_x, coordinate_y + 12 + 1, width_small_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 1, coordinate_y + 12 + 1 + 1);
	tmp = (my_getline_addSpace(width_small_box - 1));
	if (tmp == "-1")
		return;
	else
		NewCourse->course.LNameTeacher = (tmp);

	my_print(coordinate_x + 30, coordinate_y + 12, LIGHT_AQUA, "Enter Teacher's first name:");
	box(coordinate_x + 30, coordinate_y + 12 + 1, width_small_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 30 + 1, coordinate_y + 12 + 1 + 1);
	tmp = (my_getline_addSpace(width_small_box - 1));
	if (tmp == "-1")
		return;
	else
		NewCourse->course.FNameTeacher = (tmp);

	my_print(coordinate_x, coordinate_y + 16, LIGHT_AQUA, "Enter Credits:");
	box(coordinate_x, coordinate_y + 16 + 1, width_small_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 1, coordinate_y + 16 + 1 + 1);
	tmp = (my_getline_onlyNumber(3));
	if (tmp == "-1")
		return;
	else
		NewCourse->course.Credits = stoi(tmp);

	my_print(coordinate_x + 30, coordinate_y + 16, LIGHT_AQUA, "Enter Max Students:");
	box(coordinate_x + 30, coordinate_y + 16 + 1, width_small_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 30 + 1, coordinate_y + 16 + 1 + 1);
	tmp = (my_getline_onlyNumber(3));
	if (tmp == "-1")
		return;
	else
		NewCourse->course.Max_stdn = stoi(tmp);

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
	tmp = (my_getline_onlyNumber(2));
	if (tmp == "-1")
		return;
	else
		NewCourse->course.startDate.day = stoi(tmp);
	gotoXY(coordinate_x + width_small_box + 2 + 1, coordinate_y + 24 + 2);
	tmp = (my_getline_onlyNumber(2));
	if (tmp == "-1")
		return;
	else
		NewCourse->course.startDate.month = stoi(tmp);
	gotoXY(coordinate_x + 2 * width_small_box + 3 + 2, coordinate_y + 24 + 2);
	tmp = (my_getline_onlyNumber(4));
	if (tmp == "-1")
		return;
	else
		NewCourse->course.startDate.year = stoi(tmp);

	my_print(coordinate_x, coordinate_y + 28, LIGHT_AQUA, "Enter End date (dd mm yyy)");
	box(coordinate_x, coordinate_y + 28 + 1, width_small_box, height_box, LIGHT_AQUA);
	my_print(coordinate_x + width_small_box + 1, coordinate_y + 28 + 2, LIGHT_AQUA, "/");
	box(coordinate_x + width_small_box + 2, coordinate_y + 28 + 1, width_small_box, height_box, LIGHT_AQUA);
	my_print(coordinate_x + 2 * width_small_box + 3, coordinate_y + 28 + 2, LIGHT_AQUA, "/");
	box(coordinate_x + 2 * width_small_box + 4, coordinate_y + 28 + 1, width_small_box, height_box, LIGHT_AQUA);

	gotoXY(coordinate_x + 1, coordinate_y + 28 + 2);
	tmp = (my_getline_onlyNumber(2));
	if (tmp == "-1")
		return;
	else
		NewCourse->course.endDate.day = stoi(tmp);
	gotoXY(coordinate_x + width_small_box + 2 + 1, coordinate_y + 28 + 2);
	tmp = (my_getline_onlyNumber(2));
	if (tmp == "-1")
		return;
	else
		NewCourse->course.endDate.month = stoi(tmp);
	gotoXY(coordinate_x + 2 * width_small_box + 3 + 2, coordinate_y + 28 + 2);
	tmp = (my_getline_onlyNumber(4));
	if (tmp == "-1")
		return;
	else
		NewCourse->course.endDate.year = stoi(tmp);



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
//5
void DeleteCourse(STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE*& head) {
	system("cls");
	CR_NODE* cur = head;

	int coordinate_x = 30;
	int coordinate_y = 25;
	int width_box = 30;
	int height_box = 2;

	viewListOfCourses(cur);
	std::string DelID, tmp;
	my_print(coordinate_x, coordinate_y, LIGHT_AQUA, "Enter Course ID you want to delete:");
Here_enter_y3:
	box(coordinate_x, coordinate_y + 1, width_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 1, coordinate_y + 1 + 1);
	tmp = (my_getline(width_box - 1));
	if (tmp == "-1")
		return;
	else
		DelID = tmp;
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
//6
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
	std::string UpID, tmp;
	tmp = (my_getline(width_tmp - 1));
	if (tmp == "-1")
		return;
	else
		UpID = tmp;
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




		//system("pause");
		switch (choice) {
		case 1: {
			ShowCur(1);
			my_print(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 0 * height_box, BLACK, UpNode->course.ID);
			textcolor(LIGHT_AQUA);
			gotoXY(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 0 * height_box);
			tmp = (my_getline(width_box - 1));
			if (tmp == "-1")
				return;
			else
				UpNode->course.ID = (tmp);
			textcolor(WHITE);
			ShowCur(0);
		}
			  break;
		case 2: {
			ShowCur(1);
			my_print(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 1 * height_box, BLACK, UpNode->course.CName);
			textcolor(LIGHT_AQUA);
			gotoXY(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 1 * height_box);
			tmp = (my_getline_addSpace(width_box - 1));
			if (tmp == "-1")
				return;
			else
				UpNode->course.CName = (tmp);
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
			tmp = (my_getline_addSpace(width_box - 1 - 5));
			if (tmp == "-1")
				return;
			else
				UpNode->course.LNameTeacher = (tmp);

			gotoXY(coordinate_x + 2 * width_box + distance + 5 + 1, coordinate_y + height_box + 6 + 1);
			tmp = (my_getline_addSpace(width_box - 1 - 5));
			if (tmp == "-1")
				return;
			else
				UpNode->course.FNameTeacher = (tmp);

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
			tmp = (my_getline_onlyNumber(3));
			if (tmp == "-1")
				return;
			else
				UpNode->course.Credits = stoi(tmp);
			textcolor(WHITE);
			ShowCur(0);
		} break;
		case 5: {
			ShowCur(1);
			my_print(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 4 * height_box, BLACK, std::to_string(UpNode->course.Max_stdn));
			textcolor(LIGHT_AQUA);
			gotoXY(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 4 * height_box);
			tmp = (my_getline_addSpace(3));
			if (tmp == "-1")
				return;
			else
				UpNode->course.Max_stdn = stoi(tmp);
			textcolor(WHITE);
			ShowCur(0);
		} break;
		case 6: {
			ShowCur(1);
			my_print(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 5 * height_box, BLACK, ConvertStringWD(UpNode->course.dayOfWeek));
			textcolor(LIGHT_AQUA);
			gotoXY(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 5 * height_box);
			tmp = (my_getline(3));
			if (tmp == "-1")
				return;
			else
				UpNode->course.dayOfWeek = ConvertEnumWD(tmp);
			textcolor(WHITE);
			ShowCur(0);
		} break;
		case 7: {
			ShowCur(1);
			my_print(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 6 * height_box, BLACK, ConvertStringSS(UpNode->course.session));
			textcolor(LIGHT_AQUA);
			gotoXY(coordinate_x + width_box + distance + 1, coordinate_y + 1 + 6 * height_box);
			tmp = (my_getline(2));
			if (tmp == "-1")
				return;
			else
				UpNode->course.session = ConvertEnumSS(tmp);
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
			tmp = (my_getline_onlyNumber(2));
			if (tmp == "-1")
				return;
			else
				UpNode->course.startDate.day = stoi(tmp);

			gotoXY(coordinate_x + 2 * width_box + distance + 5 + width_small_box + 2 + 1, coordinate_y + 7 * height_box + 1);
			tmp = (my_getline_onlyNumber(2));
			if (tmp == "-1")
				return;
			else
				UpNode->course.startDate.month = stoi(tmp);

			gotoXY(coordinate_x + 2 * width_box + distance + 5 + 2 * width_small_box + 3 + 2, coordinate_y + 7 * height_box + 1);
			tmp = (my_getline_onlyNumber(4));
			if (tmp == "-1")
				return;
			else
				UpNode->course.startDate.year = stoi(tmp);
			ShowCur(0);
		} break;
		case 9: {
			ShowCur(1);
			int width_small_box = 8;
			/*my_print(coordinate_x, coordinate_y + 3, LIGHT_AQUA, "Enter enrollment day:");*/
			box(coordinate_x + 2 * width_box + distance + 5, coordinate_y + 8 * height_box, width_small_box, height_box, LIGHT_AQUA);
			my_print(coordinate_x + 2 * width_box + distance + 5 + width_small_box + 1, coordinate_y + 8 * height_box + 1, LIGHT_AQUA, "/");
			box(coordinate_x + 2 * width_box + distance + 5 + width_small_box + 2, coordinate_y + 8 * height_box, width_small_box, height_box, LIGHT_AQUA);
			my_print(coordinate_x + 2 * width_box + distance + 5 + 2 * width_small_box + 3, coordinate_y + 8 * height_box + 1, LIGHT_AQUA, "/");
			box(coordinate_x + 2 * width_box + distance + 5 + 2 * width_small_box + 4, coordinate_y + 8 * height_box, width_small_box, height_box, LIGHT_AQUA);

			gotoXY(coordinate_x + 2 * width_box + distance + 5 + 1, coordinate_y + 8 * height_box + 1);
			tmp = (my_getline_onlyNumber(2));
			if (tmp == "-1")
				return;
			else
				UpNode->course.endDate.day = stoi(tmp);

			gotoXY(coordinate_x + 2 * width_box + distance + 5 + width_small_box + 2 + 1, coordinate_y + 8 * height_box + 1);
			tmp = (my_getline_onlyNumber(2));
			if (tmp == "-1")
				return;
			else
				UpNode->course.endDate.month = stoi(tmp);

			gotoXY(coordinate_x + 2 * width_box + distance + 5 + 2 * width_small_box + 3 + 2, coordinate_y + 8 * height_box + 1);
			tmp = (my_getline_onlyNumber(4));
			if (tmp == "-1")
				return;
			else
				UpNode->course.endDate.year = stoi(tmp);
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
//7
void UpdateMarksInfo(STU_NODE* student, STU_COURSE_NODE*& stu_course, STFF_NODE* teacher, CR_NODE*& course) {
	system("cls");
	int coordinate_x = 40;
	int coordinate_y = 25;
	int width_box = 30;
	int width_small_box = 10;
	int height_box = 2;

again_courseID2:
	CR_NODE* cur = course;
	viewListOfCourses(cur);

again_courseID:
	my_print(coordinate_x, coordinate_y, YELLOW * 16 + BLACK, "Enter Course ID:");
	box(coordinate_x, coordinate_y + 1, width_box, height_box, LIGHT_AQUA);
	std::string courseID;
	gotoXY(coordinate_x + 1, coordinate_y + 2);
	ShowCur(1);
	courseID = my_getline(width_box - 1);
	if (courseID == "-1")
		return;
	ShowCur(0);

	CR_NODE* course_node = checkExistOfCourseRecord(course, courseID);
	if (course_node) {
		std::system("cls");
		displayLISTSTUDENTOFCOURSE(stu_course, student, courseID);

	again_studentID:
		my_print(coordinate_x, coordinate_y, YELLOW * 16 + BLACK, "Enter Student ID:");
		box(coordinate_x, coordinate_y + 1, width_box, height_box, LIGHT_AQUA);
		std::string studentID;
		gotoXY(coordinate_x + 1, coordinate_y + 2);
		ShowCur(1);
		studentID = my_getline(width_box - 1);
		if (studentID == "-1")
			goto again_courseID2;
		ShowCur(0);

		STU_COURSE_NODE* stu_course_node = checkExistOfStudentCourseRecord(stu_course, studentID);
		if (stu_course_node) {

			textcolor(BLACK * 16 + BLACK);
			for (int iy = 0; iy < 7; iy++)
				for (int ix = 0; ix < 80 + 11; ix++) {
					gotoXY(coordinate_x + ix, coordinate_y + iy);
					std::cout << " ";
				}
			textcolor(WHITE);

			my_print(coordinate_x, coordinate_y, YELLOW * 16 + BLACK, "1. Other Grade:");
			box(coordinate_x, coordinate_y + 1, width_small_box, height_box, LIGHT_AQUA);

			my_print(coordinate_x + 20, coordinate_y, YELLOW * 16 + BLACK, "Midterm Grade:");
			box(coordinate_x + 20, coordinate_y + 1, width_small_box, height_box, LIGHT_AQUA);

			my_print(coordinate_x + 40, coordinate_y, YELLOW * 16 + BLACK, "Final Grade:");
			box(coordinate_x + 40, coordinate_y + 1, width_small_box, height_box, LIGHT_AQUA);

			my_print(coordinate_x + 60, coordinate_y, YELLOW * 16 + BLACK, "Total Grade:");
			box(coordinate_x + 60, coordinate_y + 1, width_small_box, height_box, LIGHT_AQUA);

			std::string other, midterm, final, total;

			gotoXY(coordinate_x + 1, coordinate_y + 1 + 1);
			ShowCur(1);
			other = my_getline_onlyNumber(width_small_box - 1);
			ShowCur(0);
			if (other == "-1")
				return;

			gotoXY(coordinate_x + 20 + 1, coordinate_y + 1 + 1);
			ShowCur(1);
			midterm = my_getline_onlyNumber(width_small_box - 1);
			ShowCur(0);
			if (midterm == "-1")
				return;

			gotoXY(coordinate_x + 40 + 1, coordinate_y + 1 + 1);
			ShowCur(1);
			final = my_getline_onlyNumber(width_small_box - 1);
			ShowCur(0);
			if (final == "-1")
				return;

			gotoXY(coordinate_x + 60 + 1, coordinate_y + 1 + 1);
			ShowCur(1);
			total = my_getline_onlyNumber(width_small_box - 1);
			ShowCur(0);
			if (final == "-1")
				return;

			my_print(coordinate_x + 25 - 8, coordinate_y + 4, LIGHT_GREEN * 16 + BLACK, "Are you sure you want to update these:");
			int choice = enter_again_yes_no(coordinate_x + 25 + 1, coordinate_y + 5, 7, 3, 4, LIGHT_AQUA, YELLOW);
			if (choice == 1) {
				textcolor(BLACK * 16 + BLACK);
				for (int iy = 0; iy < 9; iy++)
					for (int ix = 0; ix < 80 + 11; ix++) {
						gotoXY(coordinate_x + ix, coordinate_y + iy);
						std::cout << " ";
					}
				textcolor(WHITE);

				stu_course_node->stu_course.midterm = stof(midterm);
				stu_course_node->stu_course.final = stof(final);
				stu_course_node->stu_course.other = stof(other);
				stu_course_node->stu_course.total = stof(total);

				textcolor(GREEN * 16 + BLACK);
				for (int iy = 0; iy < 3; iy++)
					for (int ix = 0; ix < 40; ix++) {
						gotoXY(coordinate_x + 20 + ix, coordinate_y + 2 + iy);
						std::cout << " ";
					}
				gotoXY(coordinate_x + 20 + 10, coordinate_y + 2 + 1);
				std::cout << "Update Successfully.";
				textcolor(WHITE);
				Read_After_Update_Student_Course(student, course, teacher, stu_course);
				char ans = _getch();
			}
			else
				return;
		}
		else {
			my_print(coordinate_x + 40, coordinate_y, RED * 16 + BLACK, "No Student Founded! They might be in another course");
			my_print(coordinate_x + 40, coordinate_y + 2, LIGHT_GREEN * 16 + BLACK, "Do you want to enter again:");
			int choice = enter_again_yes_no(coordinate_x + 40 + 5, coordinate_y + 3, 7, 3, 4, LIGHT_AQUA, YELLOW);
			if (choice == 1) {
				textcolor(BLACK * 16 + BLACK);
				for (int iy = 0; iy < 7; iy++)
					for (int ix = 0; ix < 80 + 11; ix++) {
						gotoXY(coordinate_x + ix, coordinate_y + iy);
						std::cout << " ";
					}
				textcolor(WHITE);
				goto again_studentID;
			}
		}
	}
	else {
		my_print(coordinate_x + 40, coordinate_y, RED * 16 + BLACK, "No Course Found!");
		my_print(coordinate_x + 40, coordinate_y + 2, LIGHT_GREEN * 16 + BLACK, "Do you want to enter again:");
		int choice = enter_again_yes_no(coordinate_x + 40 + 5, coordinate_y + 3, 7, 3, 4, LIGHT_AQUA, YELLOW);
		if (choice == 1) {
			textcolor(BLACK * 16 + BLACK);
			for (int iy = 0; iy < 7; iy++)
				for (int ix = 0; ix < 80 - 13; ix++) {
					gotoXY(coordinate_x + ix, coordinate_y + iy);
					std::cout << " ";
				}
			textcolor(WHITE);
			goto again_courseID;
		}
	}
}

////3. LOOK UP
	/*
		  194
	218	┌  ┬  ┐ 191         197 ┼

	195 ├  ┼  ┤ 180			179 │

	192 └  ┴  ┘ 217			196 ─
		  193
	*/
	//1
void displayLISTOFCLASS(CLASS_NODE* listclass) {
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
		<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_classID) << std::left << "Class ID" 
		<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_className) << std::left << "Class name" 
		<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_schoolYear) << std::left << "School year";

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
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_classID) << std::left << cur_listclass->listclass.ClassID
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_className) << std::left << cur_listclass->listclass.name
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_schoolYear) << std::left << cur_listclass->listclass.schoolYear;

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
void viewListOfClasses(CLASS_NODE*& listclass, STU_NODE* student) {
	std::system("cls");
	updateListClass(listclass, student);
	displayLISTOFCLASS(listclass);
}
//2
void displayListStudentsOfCourse(STU_NODE*& student, std::string classID) {
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
		<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_studentID) << std::left << "Student ID" 
		<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_lastName) << std::left << "Last name" 
		<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_firstName) << std::left << "First name"
		<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_gender) << std::left << "Gender"
		<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_DOB) << std::left << "Date of birth" 
		<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_socialID) << std::left << "social ID";

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
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_studentID) << std::left << cur_list_student->student.StudentID
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_lastName) << std::left << cur_list_student->student.LName
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_firstName) << std::left << cur_list_student->student.FName 
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_gender) << std::left << cur_list_student->student.Gender
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_DOB) << std::left << DOB 
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_socialID) << std::left << cur_list_student->student.SocialID;

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
void viewListStudentsOfClass(STU_NODE* student, CLASS_NODE* listclass) {
	std::string classID;
	int coordinate_x = 35;
	int coordinate_y = 27;
	int width_box = 30;
	int height_box = 2;
	std::system("cls");
	displayLISTOFCLASS(listclass);
enter_classID:
	my_print(coordinate_x, coordinate_y, YELLOW * 16 + BLACK, "Enter class ID which you want to open: ");
	box(coordinate_x, coordinate_y + 1, width_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 1, coordinate_y + 2);
	ShowCur(1);
	classID = my_getline(width_box - 1);
	ShowCur(0);
	if (classID == "-1")
		return;

	if (checkExistClassNODEIDinDLL(listclass, classID) == nullptr) {
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
	displayListStudentsOfCourse(student, classID);
}
//3
void viewListOfCourses(CR_NODE* course) {
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
		<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_schoolYear) << std::left << "School year"
		<< std::setw(tmp) << std::left << char(179) << std::setw(width_semester) << std::left << "Sem" 
		<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_courseID) << std::left << "Course ID" 
		<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_courseName) << std::left << "Course name"
		<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_teacherName) << std::left << "Teacher name"
		<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_credits) << std::left << "Credits" 
		<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_registered) << std::left << "Registered"
		<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_calendar) << std::left << "Calendar";

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
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_schoolYear) << std::left << cur_course->course.Schoolyear
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_semester) << std::left << cur_course->course.Semester
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_courseID) << std::left << cur_course->course.ID
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_courseName) << std::left << cur_course->course.CName
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_teacherName) << std::left << fullname
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_credits) << std::left << cur_course->course.Credits 
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_registered) << std::left << registered 
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_calendar) << std::left << calendar;

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
void displayLISTSTUDENTOFCOURSE(STU_COURSE_NODE* stu_course, STU_NODE* student, std::string CourseID) {
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
		<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_studentID) << std::left << "Student ID"
		<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_studentName) << std::left << "Student's name" 
		<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_gender) << std::left << "Gender"
		<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_DOB) << std::left << "Date of birth" 
		<< std::setw(tmp) << std::left << char(179)	<< std::setw(socialID) << std::left << "Social ID";

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
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_studentID) << std::left << cur_list_course->stu_course.StuID
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_studentName) << std::left << fullname 
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_gender) << std::left << tmp_student->student.Gender
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_DOB) << std::left << DoB 
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(socialID) << std::left << tmp_student->student.SocialID;

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
void viewListStudentsOfCourse(STU_COURSE_NODE* stu_course, STU_NODE* student, CR_NODE* course) {
	int coordinate_x = 35;
	int coordinate_y = 27;
	int width_box = 30;
	int height_box = 2;
	int check = 0;
	std::string CourseID;

	std::system("cls");
	viewListOfCourses(course);
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
		displayLISTSTUDENTOFCOURSE(stu_course, student, CourseID);
}
//5
void displayScoreBoard_Course(STU_COURSE_NODE* stu_course, STU_NODE* student, std::string CourseID) {
	int coordinate_x = 13;
	int coordinate_y = 5;

	int width_no = 5;
	int width_studentID = 10;
	int width_lastName = 25;
	int width_firstName = 15;
	int width_mark = 10;
	int tmp = 5;

	int width = width_no + width_studentID + width_lastName + width_firstName + 4 *width_mark + tmp * 8;

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
		<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_studentID) << std::left << "Student ID"
		<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_lastName) << std::left << "Last name"
		<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_firstName) << std::left << "First name"
		<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_mark) << std::left << "Other"
		<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_mark) << std::left << "Midterm"
		<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_mark) << std::left << "Final"
		<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_mark) << std::left << "Total";

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
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_studentID) << std::left << cur_list_stu_course->stu_course.StuID
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_lastName) << std::left << tmp_student->student.LName
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_firstName) << std::left << tmp_student->student.FName
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_mark) << std::left << cur_list_stu_course->stu_course.other 
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_mark) << std::left << cur_list_stu_course->stu_course.midterm
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_mark) << std::left << cur_list_stu_course->stu_course.final
			<< std::setw(tmp) << std::left << char(179)	<< std::setw(width_mark) << std::left << cur_list_stu_course->stu_course.total;

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
void viewScoreboardInCourse(CR_NODE* course, STU_COURSE_NODE* stu_course, STU_NODE* student) {
	int coordinate_x = 35;
	int coordinate_y = 27;
	int width_box = 30;
	int height_box = 2;
	int check = 0;
	std::string CourseID;

	std::system("cls");
	viewListOfCourses(course);
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
	displayScoreBoard_Course(stu_course, student, CourseID);

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
	int width_GPA = 10;

	int width = width_no + width_studentID + width_lastName + width_firstName + width_subject
		+ width_mark + width_GPA + 5 * 7;

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
		<< std::setw(width_firstName) << std::left << "First name" << std::setw(5) << std::left << char(179)
		<< std::setw(width_subject) << std::left << "Subject" << std::setw(5) << std::left << char(179)
		<< std::setw(width_mark) << std::left << "Mark" << std::setw(5) << std::left << char(179)
		<< std::setw(width_GPA) << std::left << "GPA" << char(179);
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
					<< std::setw(width_mark) << std::left << std::fixed << std::setprecision(2) << cur->stu_course.total << std::setw(5) << std::left << char(179)
					<< std::setw(width_GPA) << std::left << " " << char(179);
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
					<< std::setw(width_subject) << std::left << " " << std::setw(5) << std::left << char(179)
					<< std::setw(width_mark) << std::left << " "  << std::setw(5) << std::left << char(179)
 					//<< std::setw(width_subject) << std::left << "GPA" << std::setw(5) << std::left << char(179)
					<< std::setw(width_GPA) << std::left << std::fixed << std::setprecision(2) << 0 << char(179); 
			}
			else {
				gotoXY(coordinate_x, coordinate_y + 2 + ++i);
				std::cout << std::setw(5) << std::left << char(179) << std::setw(5) << std::left << ++count << std::setw(5) << std::left << char(179)
					<< std::setw(width_studentID) << std::left << cur_student->student.StudentID << std::setw(5) << std::left << char(179)
					<< std::setw(width_lastName) << std::left << cur_student->student.LName << std::setw(5) << std::left << char(179)
					<< std::setw(width_firstName) << std::left << cur_student->student.FName << std::setw(5) << std::left << char(179)
					<< std::setw(width_subject) << std::left << " " << std::setw(5) << std::left << char(179)
					<< std::setw(width_mark) << std::left << " " << std::setw(5) << std::left << char(179)
					//<< std::setw(width_subject) << std::left << "GPA" << std::setw(5) << std::left << char(179)
					<< std::setw(width_GPA) << std::left << std::fixed << std::setprecision(2) << GPA / count_subject << char(179);
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
void viewScoreBoard_Class(STU_COURSE_NODE* stu_course, STU_NODE* student, CLASS_NODE* listclass) {
	int coordinate_x = 35;
	int coordinate_y = 27;
	int width_box = 30;
	int height_box = 2;
	int check = 0;
	std::string ClassID;

	std::system("cls");
	viewListOfClasses(listclass, student);
enter_class_ID:
	my_print(coordinate_x, coordinate_y, YELLOW * 16 + BLACK, "Enter the class ID which you want to open:");
	box(coordinate_x, coordinate_y + 1, width_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 1, coordinate_y + 2);
	ShowCur(1);
	ClassID = (my_getline(width_box - 1));
	ShowCur(0);
	if (ClassID == "-1")
		return;

	if (checkExistClassIDinDLL(student, ClassID) == nullptr) {
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
	displayScoreBoard_Class(stu_course, student, ClassID);
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
		//viewListOfCourses(course);
		my_print(coordinate_x + width_box + 5, coordinate_y + 1, LIGHT_RED, "Enter ID of the course you want to export:");
		box(coordinate_x + width_box + 5, coordinate_y + 1 + 1, width_box, height_box, LIGHT_YELLOW);
		ShowCur(1);
	Here_enter_y:
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

////4
void changePasswordOfStaff(STFF_NODE* loggedinStaff, STFF_NODE* staff) {

	int coordinate_x = 70;
	int coordinate_y = 10;

	int width_box = 40;
	int height_box = 2;
AGAIN_4:
	textcolor(LIGHT_YELLOW * 16 + BLACK);
	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 41; i++) {
			gotoXY(coordinate_x + i, coordinate_y - 5 + j);
			std::cout << " ";
		}
	gotoXY(coordinate_x + 12, coordinate_y - 5 + +1);
	std::cout << "CHANGE PASSWORD";
	textcolor(WHITE);

	my_print(coordinate_x, coordinate_y, YELLOW, "Old password:");
	box(coordinate_x, coordinate_y + 1, width_box, height_box, YELLOW);

	my_print(coordinate_x, coordinate_y + 5, YELLOW, "New password:");
	box(coordinate_x, coordinate_y + 6, width_box, height_box, YELLOW);

	my_print(coordinate_x, coordinate_y + 10, YELLOW, "Verify:");
	box(coordinate_x, coordinate_y + 11, width_box, height_box, YELLOW);

	std::string old_password, new_password, new_password_again;
	ShowCur(1);

	gotoXY(coordinate_x + 1, coordinate_y + 2);
	old_password = my_getline(width_box - 1);
	if (old_password == "-1")
		return;

	gotoXY(coordinate_x + 1, coordinate_y + 7);
	new_password = my_getline(width_box - 1);
	if (new_password == "-1")
		return;

	gotoXY(coordinate_x + 1, coordinate_y + 12);
	new_password_again = my_getline(width_box - 1);
	if (new_password_again == "-1")
		return;

	if (loggedinStaff->staff.Password != old_password) {
		ShowCur(0);
		my_print(coordinate_x, coordinate_y + 15, RED * 16 + LIGHT_AQUA, "Your old password has been entered incorrectly.");
		my_print(coordinate_x, coordinate_y + 17, LIGHT_GREEN * 16 + BLACK, "Please enter again. ");
		char ans = _getch();

		textcolor(BLACK * 16 + BLACK);
		for (int j = 0; j < 18; j++)
			for (int i = 0; i < 41 + 6; i++) {
				gotoXY(coordinate_x + i, coordinate_y + j);
				std::cout << " ";
			}
		textcolor(WHITE);

		ShowCur(1);
		goto AGAIN_4;
	}
	if (new_password != new_password_again) {
		ShowCur(0);
		my_print(coordinate_x, coordinate_y + 15, RED * 16 + LIGHT_AQUA, "Confirmation password is not correct.");
		my_print(coordinate_x, coordinate_y + 17, LIGHT_GREEN * 16 + BLACK, "Please enter again. ");
		char ans = _getch();

		textcolor(BLACK * 16 + BLACK);
		for (int j = 0; j < 18; j++)
			for (int i = 0; i < 41; i++) {
				gotoXY(coordinate_x + i, coordinate_y + j);
				std::cout << " ";
			}
		textcolor(WHITE);

		ShowCur(1);
		goto AGAIN_4;
	}
	textcolor(BLACK * 16 + BLACK);
	for (int j = 0; j < 18; j++)
		for (int i = 0; i < 41; i++) {
			gotoXY(coordinate_x + i, coordinate_y + j);
			std::cout << " ";
		}
	textcolor(WHITE);

	ShowCur(0);
	my_print(coordinate_x, coordinate_y + 5, LIGHT_GREEN * 16 + BLACK, "Are you sure you want to save this password:");
	int choice = enter_again_yes_no(coordinate_x + 13, coordinate_y + 7, 7, 3, 4, LIGHT_AQUA, YELLOW);
	if (choice == 1) {
		loggedinStaff->staff.Password = new_password;
		Read_After_Update_Staffs(staff);

		textcolor(LIGHT_GREEN * 16 + BLACK);
		for (int j = 0; j < 3; j++)
			for (int i = 0; i < 41; i++) {
				gotoXY(coordinate_x + i, coordinate_y + 12 + j);
				std::cout << " ";
			}
		gotoXY(coordinate_x + 6, coordinate_y + 12 + 1);
		std::cout << "Changed password successfully.";
		textcolor(WHITE);
		char ans = _getch();
	}
	else
		return;
}

//////////////////////////////////////////TEST FUNCTION//////////////////////////////////////////
bool Test_ifValid_Date(SEMESTER* smter) {
	if (smter->startDate.year > smter->endDate.year) {
		return 0;
	}
	else if (smter->startDate.year < smter->endDate.year) {
		if (smter->startDate.month > smter->endDate.month) {
			return 0;
		}
		else if (smter->startDate.month < smter->endDate.month) {
			if (smter->startDate.day > smter->endDate.day) {
				return 0;
			}
		}
	}
	else if (smter->startDate.year == smter->endDate.year) {
		if (smter->startDate.month >= smter->endDate.month) {
			return 0;
		}
		else if (smter->startDate.month < smter->endDate.month) {
			if (smter->startDate.day > smter->endDate.day) {
				return 0;
			}
		}
		else if (smter->startDate.month == smter->endDate.month) {
			if (smter->startDate.day >= smter->endDate.day) {
				return 0;
			}
		}
	}
	return 1;
}
