#include "header.h"

//1
void changePasswordOfStudentAccount(STU_NODE*& student, STU_NODE*& loggedinStudent) {
	int coordinate_x = 70;
	int coordinate_y = 10;

	int width_box = 40;
	int height_box = 2;
AGAIN_changepass:
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

	if (loggedinStudent->student.Password != old_password) {
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
		goto AGAIN_changepass;
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
		goto AGAIN_changepass;
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
		loggedinStudent->student.Password = new_password;
		Read_After_Update_Students(student);

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
//2
void UpdateStudentInfo(STU_NODE*& student, STU_NODE*& loggedinStudent) {
	STU_NODE* cur_student = student;
	int check = 0;
	while (cur_student) {
		if (cur_student->student.StudentID == loggedinStudent->student.StudentID) {
			check = 1;
			break;
		}
		cur_student = cur_student->next;
	}

update_Yourinfor:
	std::system("cls");
	int coordinate_x_infor = 45;
	int coordinate_y_infor = 3;
	int width_box_infor = 60;
	int height_box_infor = 8;
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

	my_print(coordinate_x_infor + width_box_infor / 2 - width_small_box_infor / 2 + 1, coordinate_y_infor - 2 + 1, color_text, " Student's information");

	std::string fullname = loggedinStudent->student.LName + " " + loggedinStudent->student.FName;
	std::string DoB = std::to_string(loggedinStudent->student.DoB.day / 10) + std::to_string(loggedinStudent->student.DoB.day % 10) + "/"
		+ std::to_string(loggedinStudent->student.DoB.month / 10) + std::to_string(loggedinStudent->student.DoB.month % 10) + "/"
		+ std::to_string(loggedinStudent->student.DoB.year);

	textcolor(color_text);
	gotoXY(coordinate_x_infor + 1, coordinate_y_infor + 1);
	std::cout << std::setw(15) << std::left << "Full name : " << std::setw(44) << std::right << fullname;
	gotoXY(coordinate_x_infor + 1, coordinate_y_infor + 2);
	std::cout << std::setw(15) << std::left << "Student ID: " << std::setw(44) << std::right << loggedinStudent->student.StudentID;
	gotoXY(coordinate_x_infor + 1, coordinate_y_infor + 3);
	std::cout << std::setw(15) << std::left << "Gender: " << std::setw(44) << std::right << loggedinStudent->student.Gender;
	gotoXY(coordinate_x_infor + 1, coordinate_y_infor + 4);
	std::cout << std::setw(15) << std::left << "Date of birth: " << std::setw(44) << std::right << DoB;
	gotoXY(coordinate_x_infor + 1, coordinate_y_infor + 5);
	std::cout << std::setw(15) << std::left << "Social ID: " << std::setw(44) << std::right << loggedinStudent->student.SocialID;
	gotoXY(coordinate_x_infor + 1, coordinate_y_infor + 6);
	std::cout << std::setw(15) << std::left << "Class ID: " << std::setw(44) << std::right << loggedinStudent->student.Classes.ClassID;
	gotoXY(coordinate_x_infor + 1, coordinate_y_infor + 7);
	std::cout << std::setw(15) << std::left << "Class Name: " << std::setw(44) << std::right << loggedinStudent->student.Classes.name;
	textcolor(WHITE);

	std::string option[] = { "1. Update your gender.",
					"2. Update your date of birth.",
					"3. Update your social ID.",
					"0. Come back." };
	int coordinate_x_option = 10;
	int coordinate_y_option = 14;
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
			loggedinStudent->student.Gender = tmp;
			Read_After_Update_Students(student);
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
			loggedinStudent->student.DoB = newDOB;
			Read_After_Update_Students(student);
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
			loggedinStudent->student.SocialID = tmp;
			Read_After_Update_Students(student);
		}
		goto update_Yourinfor;
	}
	else if (choice == 0 + 4) {
		return;
	}
}