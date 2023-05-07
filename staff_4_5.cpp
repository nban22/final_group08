#include "staff.h"

////4
void change_password_of_staff_account(STFF_NODE* loggedinStaff, STFF_NODE* staff) {

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
		reread_after_update_staff(staff);

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

////5
void update_your_information(STFF_NODE*& loggedinStaff, STFF_NODE*& teacher, STFF_NODE*& staff) {
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
				reread_after_update_teacher(teacher);
			}
			reread_after_update_staff(staff);
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
				reread_after_update_teacher(teacher);
			}
			reread_after_update_staff(staff);
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
				reread_after_update_teacher(teacher);
			}
			reread_after_update_staff(staff);
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
				reread_after_update_teacher(teacher);
			}
			reread_after_update_staff(staff);
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
				reread_after_update_teacher(teacher);
			}
			reread_after_update_staff(staff);
		}
		goto update_Yourinfor;
	}
	else if (choice == 0 + 6) {
		return;
	}
}