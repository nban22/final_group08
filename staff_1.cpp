#include "staff.h"

////1. CREATE NEW
//1
bool is_valid_date(const Date& date) {
	if (date.year < 0) {
		return false;
	}
	if (date.month < 1 || date.month > 12) {
		return false;
	}
	int max_day = 31;
	if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) {
		max_day = 30;
	}
	else if (date.month == 2) {
		if (date.year % 4 == 0 && (date.year % 100 != 0 || date.year % 400 == 0)) {
			max_day = 29;
		}
		else {
			max_day = 28;
		}
	}

	if (date.day < 1 || date.day > max_day) {
		return false;
	}

	return true;
}
bool check_valid_date(SEMESTER* smter) {
	if (smter->startDate.year > smter->endDate.year) {
		return false;
	}
	else if (smter->startDate.year < smter->endDate.year) {
		return true;
	}
	else {
		if (smter->startDate.month > smter->endDate.month) {
			return false;
		}
		else if (smter->startDate.month < smter->endDate.month) {
			return true;
		}
		else {
			if (!is_valid_date(smter->startDate) || !is_valid_date(smter->endDate)) {
				return false;
			}
			return smter->startDate.day <= smter->endDate.day;
		}
	}
}
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
				if (tmp == "-1")
				{
					file_semester.close();
					return;
				}
				else smter_next->startDate.day = stoi(tmp);

				gotoXY(coordinate_x + width_small_box + 2 + 1 + 3, coordinate_y + 10 + 1 + 1);
				tmp = my_getline_onlyNumber(2);
				if (tmp == "-1")
				{
					file_semester.close();
					return;
				}
				else smter_next->startDate.month = stoi(tmp);

				gotoXY(coordinate_x + 2 * width_small_box + 4 + 1 + 2, coordinate_y + 10 + 1 + 1);
				tmp = my_getline_onlyNumber(4);
				if (tmp == "-1")
				{
					file_semester.close();
					return;
				}
				else smter_next->startDate.year = stoi(tmp);


				gotoXY(coordinate_x + 1 + 3, coordinate_y + 15 + 1 + 1);
				tmp = my_getline_onlyNumber(2);
				if (tmp == "-1")
				{
					file_semester.close();
					return;
				}
				else smter_next->endDate.day = stoi(tmp);

				gotoXY(coordinate_x + width_small_box + 2 + 1 + 3, coordinate_y + 15 + 1 + 1);
				tmp = my_getline_onlyNumber(2);
				if (tmp == "-1")
				{
					file_semester.close();
					return;
				}
				else smter_next->endDate.month = stoi(tmp);

				gotoXY(coordinate_x + 2 * width_small_box + 4 + 1 + 2, coordinate_y + 15 + 1 + 1);
				tmp = my_getline_onlyNumber(4);
				if (tmp == "-1")
				{
					file_semester.close();
					return;
				}
				else smter_next->endDate.year = stoi(tmp);

				//TESTING

				if (check_valid_date(smter_next)) {
					std::ofstream file_schoolYear("schoolYear.txt", std::ios::app);
					file_schoolYear << "\n" << schYear + 1 << "-" << schYear + 2;
					file_schoolYear.close();
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
						for (int i = 0; i < 46; i++) {
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
	else if (choice == 0) {
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
			if (check_valid_date(smter_next)) {
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

	std::string curYear, curSemester;
	get_curYear_and_curSemester(coordinate_x, coordinate_y, curYear, curSemester);

	if (curSemester != "1") {
		my_print(coordinate_x, coordinate_y + height_box + 2, LIGHT_RED * 16 + BLACK, "Please create new school year before!");
		char c;
		c = _getch();
		return;
	}
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
	my_print(coordinate_x, coordinate_y, color_box_title, "School Year:");
	box(coordinate_x, coordinate_y + 1, width_small_box, height_box, color_box_title);
	my_print(coordinate_x + width_small_box + 1, coordinate_y + 2, color_box_title, "-");
	box(coordinate_x + width_small_box + 2, coordinate_y + 1, width_small_box, height_box, color_box_title);

	my_print(coordinate_x, coordinate_y + height_box + 2, color_box_title, "Enter Class ID:");
	box(coordinate_x, coordinate_y + height_box + 2 + 1, width_box, height_box, color_box_title);

	my_print(coordinate_x, coordinate_y + 2 * height_box + 4, color_box_title, "Enter Class Name:");
	box(coordinate_x, coordinate_y + 2 * height_box + 4 + 1, width_box, height_box, color_box_title);


	CLASS newClass;
	ShowCur(1);
	my_print(coordinate_x + 1 + 2, coordinate_y + 1 + 1, YELLOW, curYear);
	newClass.schoolYear = stoi(curYear);

	my_print(coordinate_x + width_small_box + 2 + 1 + 2, coordinate_y + 1 + 1, YELLOW, std::to_string(stoi(curYear) + 1));
	//getline
	std::string tmp;
	gotoXY(coordinate_x + 1, coordinate_y + height_box + 2 + 1 + 1);
	tmp = my_getline(width_box - 1);
	if (tmp == "-1") return;
	else newClass.ClassID = tmp;

	gotoXY(coordinate_x + 1, coordinate_y + 2 * height_box + 4 + 1 + 1);
	tmp = my_getline_addSpace(width_box - 1);
	if (tmp == "-1") return;
	else newClass.name = tmp;


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

	reread_after_update_staff(staff);
	return;
}