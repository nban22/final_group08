#include "student.h"

//1
void change_password_of_student_account(STU_NODE*& student, STU_NODE*& loggedinStudent) {
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
		reread_after_update_student(student);

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
void update_student_information(STU_NODE*& student, STU_NODE*& loggedinStudent) {
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
			reread_after_update_student(student);
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
			reread_after_update_student(student);
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
			reread_after_update_student(student);
		}
		goto update_Yourinfor;
	}
	else if (choice == 0 + 4) {
		return;
	}
}
//3
void register_for_course(STU_NODE*& student, STFF_NODE*& teacher, CR_NODE*& course, STU_COURSE_NODE*& stu_course, STU_NODE* loggedinStudent) {
	std::string cur_year;
	std::string cur_semester;
	get_curYear_and_curSemester(80, 15, cur_year, cur_semester);

	std::ifstream fileCrsRegis("timeCrsRegis" + cur_year + "_" + std::to_string(stoi(cur_year) + 1) + "_" + cur_semester + ".txt");
	if (!fileCrsRegis.is_open()) {
		my_print(80, 15, RED * 16 + LIGHT_AQUA, "Can not open file timeCrsRegis" + cur_year + "_" + std::to_string(stoi(cur_year) + 1) + "_" + cur_semester + ".txt");
		char ans = _getch();
		return;
	}
	else {
		Time start_time, end_time;
		Date start_date, end_date;
		std::string tmp;
		std::getline(fileCrsRegis, tmp, ':');
		start_time.hour = stoi(tmp);
		std::getline(fileCrsRegis, tmp, ':');
		start_time.minute = stoi(tmp);
		std::getline(fileCrsRegis, tmp);
		start_time.second = stoi(tmp);

		std::getline(fileCrsRegis, tmp, '/');
		start_date.day = stoi(tmp);
		std::getline(fileCrsRegis, tmp, '/');
		start_date.month = stoi(tmp);
		std::getline(fileCrsRegis, tmp);
		start_date.year = stoi(tmp);

		std::getline(fileCrsRegis, tmp, ':');
		end_time.hour = stoi(tmp);
		std::getline(fileCrsRegis, tmp, ':');
		end_time.minute = stoi(tmp);
		std::getline(fileCrsRegis, tmp);
		end_time.second = stoi(tmp);

		std::getline(fileCrsRegis, tmp, '/');
		end_date.day = stoi(tmp);
		std::getline(fileCrsRegis, tmp, '/');
		end_date.month = stoi(tmp);
		std::getline(fileCrsRegis, tmp);
		end_date.year = stoi(tmp);

		if (check_time(start_time, start_date, end_time, end_date) == false) {
			my_print(80, 15, RED * 16 + LIGHT_AQUA, "The course registration function is not available yet.");
			my_print(80, 17, RED * 16 + LIGHT_AQUA, "Please come back later.");
			char ans = _getch();
			return;
		}
	}
	std::system("cls");
	update_cur_stdn_in_course(course, stu_course);

	int coordinate_x = 50;
	int coordinate_y = 26;
	int width_box = 30;
	int height_box = 2;

	int check = 0;
	std::string CourseID;
	CR_NODE* cur_course = course;

	std::system("cls");
	view_list_of_courses(course);
again_courseID:

	my_print(coordinate_x, coordinate_y, LIGHT_YELLOW * 16 + BLACK, "Enter Course ID which you want to register:");
	ShowCur(1);
	box(coordinate_x, coordinate_y + 1, width_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 1, coordinate_y + 2);
	CourseID = my_getline(width_box - 1);
	ShowCur(0);

	CR_NODE* cur = course;
	while (cur != nullptr) {
		if (cur->course.ID == CourseID) {
			cur_course = cur;
			check = 1;
			break;
		}
		cur = cur->next;
	}
	if (check == 0) {
		my_print(coordinate_x + 50, coordinate_y, RED * 16 + LIGHT_AQUA, "Your Course ID doesn't exist.");
		my_print(coordinate_x + 50, coordinate_y + 2, LIGHT_GREEN * 16 + BLACK, "Do you want to enter again:");

		int choice = enter_again_yes_no(coordinate_x + 50 + 4, coordinate_y + 3, 7, 3, 4, LIGHT_AQUA, YELLOW);
		if (choice == 1) {
			textcolor(BLACK * 16 + BLACK);
			for (int j = 0; j < 7; j++)
				for (int i = 0; i < 79; i++) {
					gotoXY(coordinate_x + i, coordinate_y + j);
					std::cout << " ";
				}
			textcolor(WHITE);
			goto again_courseID;
		}
	}

	bool check1 = false;
	bool check2 = false;
	bool check3 = true;
	bool check4 = true;
	//điều kiện để chấp nhận đăng ký khóa học
	//1. lớp còn trống slot
	//2. không đăng ký quá 5 môn học
	//3. môn đó chưa được đăng ký
	//4. không bị trùng lịch học

	//1
	update_cur_stdn_in_course(course, stu_course);
	if (cur_course->course.Cur_stdn < cur_course->course.Max_stdn) {
		check1 = true;
	}
	//2
	STU_COURSE_NODE* cur_stu_course = stu_course;
	int count = 0;
	while (cur_stu_course) {
		if (cur_stu_course->stu_course.StuID == loggedinStudent->student.StudentID)
			count++;
		cur_stu_course = cur_stu_course->next;
	}
	if (count < 5)
		check2 = true;
	//4
	cur_stu_course = stu_course;
	cur_course = course;

	while (cur_course) {
		if (cur_course->course.ID == CourseID)
			break;
		cur_course = cur_course->next;
	}
	if (cur_course == nullptr)
		return;

	while (cur_stu_course) {
		if (cur_stu_course->stu_course.StuID == loggedinStudent->student.StudentID) {
			if (cur_stu_course->stu_course.session == ConvertStringSS(cur_course->course.session) && cur_stu_course->stu_course.weekday == ConvertStringWD(cur_course->course.dayOfWeek)) {
				check4 = false;
				break;
			}
		}
		cur_stu_course = cur_stu_course->next;
	}
	//3
	cur_stu_course = stu_course;
	while (cur_stu_course) {
		if (cur_stu_course->stu_course.StuID == loggedinStudent->student.StudentID && cur_stu_course->stu_course.CouID == CourseID) {
			check3 = false;
			break;
		}
		else
			cur_stu_course = cur_stu_course->next;
	}
	// update
	if (check1 == false) {
		my_print(coordinate_x + 50, coordinate_y, RED * 16 + LIGHT_AQUA, "This course is full.");
		my_print(coordinate_x + 50, coordinate_y + 2, LIGHT_GREEN * 16 + BLACK, "Do you want to enter again:");

		int choice = enter_again_yes_no(coordinate_x + 50 + 4, coordinate_y + 3, 7, 3, 4, LIGHT_AQUA, YELLOW);
		if (choice == 1) {
			textcolor(BLACK * 16 + BLACK);
			for (int j = 0; j < 7; j++)
				for (int i = 0; i < 110; i++) {
					gotoXY(coordinate_x + i, coordinate_y + j);
					std::cout << " ";
				}
			textcolor(WHITE);
			goto again_courseID;
		}
	}
	else if (check2 == false) {
		my_print(coordinate_x + 50, coordinate_y, RED * 16 + LIGHT_AQUA, "You have registered 5 courses, cannot register more.");
		my_print(coordinate_x + 50, coordinate_y + 2, LIGHT_GREEN * 16 + BLACK, "Do you want to enter again:");

		int choice = enter_again_yes_no(coordinate_x + 50 + 4, coordinate_y + 3, 7, 3, 4, LIGHT_AQUA, YELLOW);
		if (choice == 1) {
			textcolor(BLACK * 16 + BLACK);
			for (int j = 0; j < 7; j++)
				for (int i = 0; i < 110; i++) {
					gotoXY(coordinate_x + i, coordinate_y + j);
					std::cout << " ";
				}
			textcolor(WHITE);
			goto again_courseID;
		}
	}
	else if (check3 == false) {
		my_print(coordinate_x + 50, coordinate_y, RED * 16 + LIGHT_AQUA, "Your have already registed to this course.");
		my_print(coordinate_x + 50, coordinate_y + 2, LIGHT_GREEN * 16 + BLACK, "Do you want to enter again:");

		int choice = enter_again_yes_no(coordinate_x + 50 + 4, coordinate_y + 3, 7, 3, 4, LIGHT_AQUA, YELLOW);
		if (choice == 1) {
			textcolor(BLACK * 16 + BLACK);
			for (int j = 0; j < 7; j++)
				for (int i = 0; i < 110; i++) {
					gotoXY(coordinate_x + i, coordinate_y + j);
					std::cout << " ";
				}
			textcolor(WHITE);
			goto again_courseID;
		}
	}
	else if (check4 == false) {
		my_print(coordinate_x + 50, coordinate_y, RED * 16 + LIGHT_AQUA, "Conflict between your calendar and the course's calendar.");
		my_print(coordinate_x + 50, coordinate_y + 2, LIGHT_GREEN * 16 + BLACK, "Do you want to enter again:");

		int choice = enter_again_yes_no(coordinate_x + 50 + 4, coordinate_y + 3, 7, 3, 4, LIGHT_AQUA, YELLOW);
		if (choice == 1) {
			textcolor(BLACK * 16 + BLACK);
			for (int j = 0; j < 7; j++)
				for (int i = 0; i < 110; i++) {
					gotoXY(coordinate_x + i, coordinate_y + j);
					std::cout << " ";
				}
			textcolor(WHITE);
			goto again_courseID;
		}
	}
	else {
		my_print(coordinate_x + 50, coordinate_y, LIGHT_GREEN * 16 + BLACK, "Are you sure you want to register to this course?");

		int choice = enter_again_yes_no(coordinate_x + 50 + 4, coordinate_y + 3, 7, 3, 4, LIGHT_AQUA, YELLOW);
		if (choice == 1) {
			textcolor(BLACK * 16 + BLACK);
			for (int j = 0; j < 7; j++)
				for (int i = 0; i < 110; i++) {
					gotoXY(coordinate_x + i, coordinate_y + j);
					std::cout << " ";
				}
			textcolor(WHITE);

			cur_stu_course = stu_course;
			if (cur_stu_course == nullptr)
				return;
			while (cur_stu_course->next)
				cur_stu_course = cur_stu_course->next;

			CR_NODE* cr_tmp = course;
			while (cr_tmp) {
				if (cr_tmp->course.ID == CourseID)
					break;
				cr_tmp = cr_tmp->next;
			}
			if (cr_tmp == nullptr)
				return;

			STU_COURSE_NODE* stu_cr_tmp = new STU_COURSE_NODE;
			stu_cr_tmp->prev = cur_stu_course;

			stu_cr_tmp->stu_course.Class = loggedinStudent->student.Classes.ClassID;
			stu_cr_tmp->stu_course.Cname = cr_tmp->course.CName;
			stu_cr_tmp->stu_course.CouID = cr_tmp->course.ID;
			stu_cr_tmp->stu_course.credits = cr_tmp->course.Credits;
			stu_cr_tmp->stu_course.enddate.day = cr_tmp->course.endDate.day;
			stu_cr_tmp->stu_course.enddate.month = cr_tmp->course.endDate.month;
			stu_cr_tmp->stu_course.enddate.year = cr_tmp->course.endDate.year;
			stu_cr_tmp->stu_course.Gen = loggedinStudent->student.Gender;
			stu_cr_tmp->stu_course.Max_stdn = cr_tmp->course.Max_stdn;
			stu_cr_tmp->stu_course.No = stu_cr_tmp->prev->stu_course.No + 1;
			stu_cr_tmp->stu_course.session = ConvertStringSS(cr_tmp->course.session);
			stu_cr_tmp->stu_course.startdate.day = cr_tmp->course.startDate.day;
			stu_cr_tmp->stu_course.startdate.month = cr_tmp->course.startDate.month;
			stu_cr_tmp->stu_course.startdate.year = cr_tmp->course.startDate.year;
			stu_cr_tmp->stu_course.StudentName = loggedinStudent->student.LName + " " + loggedinStudent->student.FName;
			stu_cr_tmp->stu_course.StuID = loggedinStudent->student.StudentID;
			stu_cr_tmp->stu_course.TeacherID = cr_tmp->course.teacherID;
			stu_cr_tmp->stu_course.Teachername = cr_tmp->course.LNameTeacher + " " + cr_tmp->course.FNameTeacher;
			stu_cr_tmp->stu_course.weekday = ConvertStringWD(cr_tmp->course.dayOfWeek);
			stu_cr_tmp->stu_course.final = stu_cr_tmp->stu_course.midterm = stu_cr_tmp->stu_course.other = stu_cr_tmp->stu_course.total = 0;
			cr_tmp->course.Cur_stdn += 1;
			stu_cr_tmp->stu_course.Schoolyear = cur_year + "-" + std::to_string(stoi(cur_year) + 1);
			stu_cr_tmp->stu_course.Semester = stoi(cur_semester);

			cur_stu_course->next = stu_cr_tmp;
			stu_cr_tmp->next = nullptr;

			textcolor(LIGHT_GREEN * 16 + BLACK);
			for (int j = 0; j < 3; j++)
				for (int i = 0; i < 40; i++) {
					gotoXY(coordinate_x + 10 + i, coordinate_y + j);
					std::cout << " ";
				}
			gotoXY(coordinate_x + 10 + 8, coordinate_y + 1);
			std::cout << "Register successfully.";
			textcolor(WHITE);
			char ans = _getch();

			reread_after_update_student_course(student, course, teacher, stu_course);
		}
	}
}
//4
void result_registration(STU_COURSE_NODE* stu_course, STU_NODE* loggedinStudent) {
	std::system("cls");
	int coordinate_x = 15;
	int coordinate_y = 6;

	textcolor(LIGHT_YELLOW * 16 + BLACK);
	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 40; i++) {
			gotoXY(coordinate_x + 45 + i, coordinate_y - 4 + j);
			std::cout << " ";
		}
	gotoXY(coordinate_x + 45 + 5, coordinate_y - 4 + 1);
	std::cout << "RESULT OF COURSE REGISTRATION";
	textcolor(WHITE);

	int width_no = 5;
	int width_courseID = 13;
	int width_courseName = 25;
	int width_TeacherName = 25;
	int width_Credits = 9;
	int width_maxstd = 13;
	int width_calendar = 18;

	int width = width_no + width_courseID + width_courseName + width_TeacherName + width_Credits + width_maxstd + width_calendar + 3 * 7;

	gotoXY(coordinate_x, coordinate_y); std::cout << "+";
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y); std::cout << "-";
	}
	gotoXY(coordinate_x + width, coordinate_y); std::cout << "+";

	gotoXY(coordinate_x, coordinate_y + 1);
	std::cout << std::setw(3) << std::left << char(179) << std::setw(width_no) << std::left << "No" << std::setw(3) << std::left << char(179)
		<< std::setw(width_courseID) << std::left << "Course ID" << std::setw(3) << std::left << char(179)
		<< std::setw(width_courseName) << std::left << "Course name" << std::setw(3) << std::left << char(179)
		<< std::setw(width_TeacherName) << std::left << "Teacher's Name" << std::setw(3) << std::left << char(179)
		<< std::setw(width_Credits) << std::left << "Credits" << std::setw(3) << std::left << char(179)
		<< std::setw(width_maxstd) << std::left << "Max student" << std::setw(3) << std::left << char(179)
		<< std::setw(width_calendar) << std::left << "Calendar";

	gotoXY(coordinate_x, coordinate_y + 2); std::cout << "+";
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y + 2); std::cout << "-";
	}
	gotoXY(coordinate_x + width, coordinate_y + 2); std::cout << "+";

	int count = 0;
	STU_COURSE_NODE* cur_stu_student = stu_course;
	STU_COURSE_NODE* list_stu_student = nullptr;
	STU_COURSE_NODE* cur_list_stu_student = list_stu_student;
	while (cur_stu_student) {
		if (cur_stu_student->stu_course.StuID == loggedinStudent->student.StudentID) {
			count++;
			if (list_stu_student == nullptr) {
				cur_list_stu_student = list_stu_student = new STU_COURSE_NODE;
				cur_list_stu_student->stu_course = cur_stu_student->stu_course;
				cur_list_stu_student->next = nullptr;
				cur_list_stu_student->prev = nullptr;
			}
			else {
				cur_list_stu_student->next = new STU_COURSE_NODE;
				cur_list_stu_student->next->stu_course = cur_stu_student->stu_course;
				cur_list_stu_student->next->prev = cur_list_stu_student;
				cur_list_stu_student = cur_list_stu_student->next;
				cur_list_stu_student->next = nullptr;
			}
		}
		cur_stu_student = cur_stu_student->next;
	}
	int page_max = (count - 1) / 15 + 1;
	int page_index = 1;

LOOP1:
	cur_list_stu_student = list_stu_student;
	int i = 0;
	int page = 0;
	int no = 1;
	while (cur_list_stu_student) {
		ShowCur(1);
		i++;
		if (no > count)
			no = 0;

		gotoXY(coordinate_x, coordinate_y + 2 + i);
		std::string calendar = ConvertStringWD(ConvertEnumWD(cur_list_stu_student->stu_course.weekday)) + "-" + ConvertStringSS(ConvertEnumSS(cur_list_stu_student->stu_course.session));
		std::cout << std::setw(3) << std::left << char(179) << std::setw(width_no) << std::left << no++ << std::setw(3) << std::left << char(179)
			<< std::setw(width_courseID) << std::left << cur_list_stu_student->stu_course.CouID << std::setw(3) << std::left << char(179)
			<< std::setw(width_courseName) << std::left << cur_list_stu_student->stu_course.Cname << std::setw(3) << std::left << char(179)
			<< std::setw(width_TeacherName) << std::left << cur_list_stu_student->stu_course.Teachername << std::setw(3) << std::left << char(179)
			<< std::setw(width_Credits) << std::left << cur_list_stu_student->stu_course.credits << std::setw(3) << std::left << char(179)
			<< std::setw(width_maxstd) << std::left << cur_list_stu_student->stu_course.Max_stdn << std::setw(3) << std::left << char(179)
			<< std::setw(width_calendar) << std::left << calendar;

		if (i == 15 || cur_list_stu_student->next == nullptr) {
			gotoXY(coordinate_x, coordinate_y + 2 + i + 1); std::cout << "+";
			for (int j = coordinate_x + 1; j < coordinate_x + width; j++) {
				gotoXY(j, coordinate_y + 2 + i + 1); std::cout << "-";
			}
			gotoXY(coordinate_x + width, coordinate_y + 2 + i + 1); std::cout << "+";
		}
		for (int j = coordinate_y + 1; j <= coordinate_y + i + 2; j++)
			if (j != coordinate_y + 2) {
				gotoXY(coordinate_x, j); std::cout << char(179);
				gotoXY(coordinate_x + width, j); std::cout << char(179);
			}
		if (cur_list_stu_student->next == nullptr) {
			for (int p = coordinate_x; p <= coordinate_x + width; p++)
				for (int k = coordinate_y + 2 + i + 2; k <= coordinate_y + 2 + 15 + 1; k++) {
					my_print(p, k, BLACK, " ");
				}
		}
		if (i == 15 || cur_list_stu_student->next == nullptr) {
			page++;
			my_print(coordinate_x + width / 2 - 4, coordinate_y + 20, GREEN, "page " + std::to_string(page_index) + "/" + std::to_string(page_max));
			i = 0;
			if (page != page_index) {
				cur_list_stu_student = cur_list_stu_student->next;
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
		cur_list_stu_student = cur_list_stu_student->next;
	}
	cur_list_stu_student = list_stu_student;
	while (cur_list_stu_student) {
		STU_COURSE_NODE* tmp = cur_list_stu_student;
		cur_list_stu_student = cur_list_stu_student->next;
		delete tmp;
	}
}
//5
void delete_registered_course(STU_COURSE_NODE*& stu_course, STU_NODE* loggedinStudent, CR_NODE* course, STU_NODE* student, STFF_NODE* teacher) {
	std::string cur_year;
	std::string cur_semester;
	get_curYear_and_curSemester(65, 14, cur_year, cur_semester);

	std::ifstream fileCrsRegis("timeCrsRegis" + cur_year + "_" + std::to_string(stoi(cur_year) + 1) + "_" + cur_semester + ".txt");
	if (!fileCrsRegis.is_open()) {
		my_print(65, 14, RED * 16 + LIGHT_AQUA, "Can not open file timeCrsRegis" + cur_year + "_" + std::to_string(stoi(cur_year) + 1) + "_" + cur_semester + ".txt");
		char ans = _getch();
		return;
	}
	else {
		Time start_time, end_time;
		Date start_date, end_date;
		std::string tmp;
		std::getline(fileCrsRegis, tmp, ':');
		start_time.hour = stoi(tmp);
		std::getline(fileCrsRegis, tmp, ':');
		start_time.minute = stoi(tmp);
		std::getline(fileCrsRegis, tmp);
		start_time.second = stoi(tmp);

		std::getline(fileCrsRegis, tmp, '/');
		start_date.day = stoi(tmp);
		std::getline(fileCrsRegis, tmp, '/');
		start_date.month = stoi(tmp);
		std::getline(fileCrsRegis, tmp);
		start_date.year = stoi(tmp);

		std::getline(fileCrsRegis, tmp, ':');
		end_time.hour = stoi(tmp);
		std::getline(fileCrsRegis, tmp, ':');
		end_time.minute = stoi(tmp);
		std::getline(fileCrsRegis, tmp);
		end_time.second = stoi(tmp);

		std::getline(fileCrsRegis, tmp, '/');
		end_date.day = stoi(tmp);
		std::getline(fileCrsRegis, tmp, '/');
		end_date.month = stoi(tmp);
		std::getline(fileCrsRegis, tmp);
		end_date.year = stoi(tmp);

		if (check_time(start_time, start_date, end_time, end_date) == false) {
			my_print(64, 14, RED * 16 + LIGHT_AQUA, "The course has exceeded the registration deadline. Cannot be deleted.");
			my_print(64, 16, RED * 16 + LIGHT_AQUA, "Please contact the administrator for further information.");
			char ans = _getch();
			return;
		}
	}
	result_registration(stu_course, loggedinStudent);
	int coordinate_x_tmp = 30;
	int coordinate_y_tmp = 23;
	int width_box = 30;
	int height_box = 2;

	textcolor(BLACK * 16 + BLACK);
	for (int j = 0; j < 1; j++)
		for (int i = 0; i < 8; i++) {
			gotoXY(75 + i, 26 + j);
			std::cout << " ";
		}
	textcolor(WHITE);

	std::string courseID;
again_coutseID_delete:
	my_print(coordinate_x_tmp, coordinate_y_tmp, YELLOW * 16 + BLACK, "Enter course ID which you want to delete:");
	box(coordinate_x_tmp, coordinate_y_tmp + 1, width_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x_tmp + 1, coordinate_y_tmp + 1 + 1);
	ShowCur(1);
	courseID = my_getline(width_box - 1);
	ShowCur(0);
	if (courseID == "-1")
		return;
	STU_COURSE_NODE* cur_stu_node = stu_course;
	while (cur_stu_node) {
		if (cur_stu_node->stu_course.CouID == courseID && cur_stu_node->stu_course.StuID == loggedinStudent->student.StudentID) {
			my_print(coordinate_x_tmp + 50, coordinate_y_tmp, LIGHT_GREEN * 16 + BLACK, "Are you sure you want to delete this course:");
			int choice = enter_again_yes_no(coordinate_x_tmp + 50 + 10, coordinate_y_tmp + 2, 7, 3, 4, LIGHT_AQUA, YELLOW);

			if (choice == 1) {
				STU_COURSE_NODE* tmp = new STU_COURSE_NODE;
				tmp = cur_stu_node;
				if (tmp == stu_course) {
					stu_course = stu_course->next;
					stu_course->prev = nullptr;
					delete tmp;
				}
				else {
					tmp->prev->next = tmp->next;
					if (tmp->next)
						tmp->next->prev = tmp->prev;
					cur_stu_node = cur_stu_node->prev;
					delete tmp;
				}
				textcolor(BLACK * 16 + BLACK);
				for (int j = 0; j < 6; j++)
					for (int i = 0; i < 70 + 24; i++) {
						gotoXY(coordinate_x_tmp + i, coordinate_y_tmp + j);
						std::cout << " ";
					}
				textcolor(WHITE);

				textcolor(LIGHT_GREEN * 16 + BLACK);
				for (int j = 0; j < 3; j++)
					for (int i = 0; i < 40; i++) {
						gotoXY(coordinate_x_tmp + 30 + i, coordinate_y_tmp + j);
						std::cout << " ";
					}
				gotoXY(coordinate_x_tmp + 30 + 10, coordinate_y_tmp + 1);
				std::cout << "Delete successfully.";
				textcolor(WHITE);
				reread_after_update_student_course(student, course, teacher, stu_course);
				char ans = _getch();
				return;
			}
			else
				return;
		}
		cur_stu_node = cur_stu_node->next;
	}

	my_print(coordinate_x_tmp + 50, coordinate_y_tmp, RED * 16 + LIGHT_AQUA, "This course is not registered.");
	my_print(coordinate_x_tmp + 50, coordinate_y_tmp + 2, LIGHT_GREEN * 16 + BLACK, "Do you want to enter again:");
	int choice = enter_again_yes_no(coordinate_x_tmp + 50 + 3, coordinate_y_tmp + 3, 7, 3, 4, LIGHT_AQUA, YELLOW);

	if (choice == 1) {
		textcolor(BLACK * 16 + BLACK);
		for (int j = 0; j < 7; j++)
			for (int i = 0; i < 70 + 24; i++) {
				gotoXY(coordinate_x_tmp + i, coordinate_y_tmp + j);
				std::cout << " ";
			}
		textcolor(WHITE);
		goto again_coutseID_delete;
		return;
	}
	else
		return;
}
//6
void view_academic_result(STU_COURSE_NODE* stu_course, STU_NODE* loggedinStudent) {
	std::system("cls");
	int coordinate_x = 15;
	int coordinate_y = 6;

	textcolor(LIGHT_YELLOW * 16 + BLACK);
	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 40; i++) {
			gotoXY(coordinate_x + 45 + i, coordinate_y - 4 + j);
			std::cout << " ";
		}
	gotoXY(coordinate_x + 45 + 5, coordinate_y - 4 + 1);
	std::cout << "ACADEMIC RESULT";
	textcolor(WHITE);

	int width_no = 5;
	int width_courseID = 13;
	int width_courseName = 25;
	int width_Credits = 9;
	int width_mark = 10;

	int width = width_no + width_courseID + width_courseName + width_Credits + width_mark * 4 + 3 * 8;

	gotoXY(coordinate_x, coordinate_y); std::cout << "+";
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y); std::cout << "-";
	}
	gotoXY(coordinate_x + width, coordinate_y); std::cout << "+";

	gotoXY(coordinate_x, coordinate_y + 1);
	std::cout << std::setw(3) << std::left << char(179) << std::setw(width_no) << std::left << "No" << std::setw(3) << std::left << char(179)
		<< std::setw(width_courseID) << std::left << "Course ID" << std::setw(3) << std::left << char(179)
		<< std::setw(width_courseName) << std::left << "Course name" << std::setw(3) << std::left << char(179)
		<< std::setw(width_Credits) << std::left << "Credits" << std::setw(3) << std::left << char(179)
		<< std::setw(width_mark) << std::left << "Other" << std::setw(3) << std::left << char(179)
		<< std::setw(width_mark) << std::left << "Midterm" << std::setw(3) << std::left << char(179)
		<< std::setw(width_mark) << std::left << "Final" << std::setw(3) << std::left << char(179)
		<< std::setw(width_mark) << std::left << "Total";

	gotoXY(coordinate_x, coordinate_y + 2); std::cout << "+";
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y + 2); std::cout << "-";
	}
	gotoXY(coordinate_x + width, coordinate_y + 2); std::cout << "+";

	int count = 0;
	STU_COURSE_NODE* cur_stu_student = stu_course;
	STU_COURSE_NODE* list_stu_student = nullptr;
	STU_COURSE_NODE* cur_list_stu_student = list_stu_student;
	while (cur_stu_student) {
		if (cur_stu_student->stu_course.StuID == loggedinStudent->student.StudentID) {
			count++;
			if (list_stu_student == nullptr) {
				cur_list_stu_student = list_stu_student = new STU_COURSE_NODE;
				cur_list_stu_student->stu_course = cur_stu_student->stu_course;
				cur_list_stu_student->next = nullptr;
				cur_list_stu_student->prev = nullptr;
			}
			else {
				cur_list_stu_student->next = new STU_COURSE_NODE;
				cur_list_stu_student->next->stu_course = cur_stu_student->stu_course;
				cur_list_stu_student->next->prev = cur_list_stu_student;
				cur_list_stu_student = cur_list_stu_student->next;
				cur_list_stu_student->next = nullptr;
			}
		}
		cur_stu_student = cur_stu_student->next;
	}
	int page_max = (count - 1) / 15 + 1;
	int page_index = 1;

LOOP1:
	cur_list_stu_student = list_stu_student;
	int i = 0;
	int page = 0;
	int no = 1;
	while (cur_list_stu_student) {
		ShowCur(1);
		i++;
		if (no > count)
			no = 0;

		gotoXY(coordinate_x, coordinate_y + 2 + i);
		std::string calendar = ConvertStringWD(ConvertEnumWD(cur_list_stu_student->stu_course.weekday)) + "-" + ConvertStringSS(ConvertEnumSS(cur_list_stu_student->stu_course.session));
		std::cout << std::setw(3) << std::left << char(179) << std::setw(width_no) << std::left << no++ << std::setw(3) << std::left << char(179)
			<< std::setw(width_courseID) << std::left << cur_list_stu_student->stu_course.CouID << std::setw(3) << std::left << char(179)
			<< std::setw(width_courseName) << std::left << cur_list_stu_student->stu_course.Cname << std::setw(3) << std::left << char(179)
			<< std::setw(width_Credits) << std::left << cur_list_stu_student->stu_course.credits << std::setw(3) << std::left << char(179)
			<< std::setw(width_mark) << std::left << cur_list_stu_student->stu_course.other << std::setw(3) << std::left << char(179)
			<< std::setw(width_mark) << std::left << cur_list_stu_student->stu_course.midterm << std::setw(3) << std::left << char(179)
			<< std::setw(width_mark) << std::left << cur_list_stu_student->stu_course.final << std::setw(3) << std::left << char(179)
			<< std::setw(width_mark) << std::left << cur_list_stu_student->stu_course.total;

		if (i == 15 || cur_list_stu_student->next == nullptr) {
			gotoXY(coordinate_x, coordinate_y + 2 + i + 1); std::cout << "+";
			for (int j = coordinate_x + 1; j < coordinate_x + width; j++) {
				gotoXY(j, coordinate_y + 2 + i + 1); std::cout << "-";
			}
			gotoXY(coordinate_x + width, coordinate_y + 2 + i + 1); std::cout << "+";
		}
		for (int j = coordinate_y + 1; j <= coordinate_y + i + 2; j++)
			if (j != coordinate_y + 2) {
				gotoXY(coordinate_x, j); std::cout << char(179);
				gotoXY(coordinate_x + width, j); std::cout << char(179);
			}
		if (cur_list_stu_student->next == nullptr) {
			for (int p = coordinate_x; p <= coordinate_x + width; p++)
				for (int k = coordinate_y + 2 + i + 2; k <= coordinate_y + 2 + 15 + 1; k++) {
					my_print(p, k, BLACK, " ");
				}
		}
		if (i == 15 || cur_list_stu_student->next == nullptr) {
			page++;
			my_print(coordinate_x + width / 2 - 4, coordinate_y + 20, GREEN, "page " + std::to_string(page_index) + "/" + std::to_string(page_max));
			i = 0;
			if (page != page_index) {
				cur_list_stu_student = cur_list_stu_student->next;
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
		cur_list_stu_student = cur_list_stu_student->next;
	}
	cur_list_stu_student = list_stu_student;
	while (cur_list_stu_student) {
		STU_COURSE_NODE* tmp = cur_list_stu_student;
		cur_list_stu_student = cur_list_stu_student->next;
		delete tmp;
	}
}
