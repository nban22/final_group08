#include "staff.h"

////3. Edit for course
//1
void create_new_course(STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE*& head) {
	CR_NODE* NewCourse = new CR_NODE;
	CR_NODE* cur = head;

	int coordinate_x = 95;
	int coordinate_y = 2;
	int width_big_box = 40;
	int width_small_box = 25;
	int height_box = 2;

	std::string curYear, curSemester;
	get_curYear_and_curSemester(coordinate_x, coordinate_y, curYear, curSemester);

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

	ShowCur(1);
	my_print(coordinate_x, coordinate_y, LIGHT_AQUA, "School Year:");
	box(coordinate_x, coordinate_y + 1, width_small_box, height_box, LIGHT_AQUA);
	my_print(coordinate_x + 1 + 7, coordinate_y + 1 + 1, LIGHT_RED, curYear + "-" + std::to_string(stoi(curYear) + 1));
	NewCourse->course.Schoolyear = curYear;

	my_print(coordinate_x + 30, coordinate_y, LIGHT_AQUA, "Semester:");
	box(coordinate_x + 30, coordinate_y + 1, width_small_box, height_box, LIGHT_AQUA);
	my_print(coordinate_x + 30 + 1 + 12, coordinate_y + 1 + 1, LIGHT_RED, curSemester);
	NewCourse->course.Semester = stoi(curSemester);

	std::string  tmp;

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

	reread_after_update_course(stu_course, teacher, head);
	gotoXY(coordinate_x, coordinate_y + 12);
	std::system("pause");
	return;
}

//2
void Add_Student_To_Course(STU_COURSE_NODE* stu_course, STU_NODE* student, STFF_NODE* teacher, CR_NODE* course) {

	int coordinate_x = 95;
	int coordinate_y = 8;
	int width_box = 40;
	int height_box = 2;
	int width_small_box = 25;
	std::string curYear, curSemester;
	STU_COURSE newStudent;

	get_curYear_and_curSemester(coordinate_x, coordinate_y, curYear, curSemester);

	textcolor(LIGHT_YELLOW * 16 + BLACK);
	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 40; i++) {
			gotoXY(coordinate_x + 7 + i, coordinate_y - 5 + j);
			std::cout << " ";
		}
	gotoXY(coordinate_x + 7 + 8, coordinate_y - 5 + 1);
	std::cout << "ADD A STUDENT TO COURSE";
	textcolor(WHITE);

	ShowCur(1);
	my_print(coordinate_x, coordinate_y, LIGHT_AQUA, "School Year:");
	box(coordinate_x, coordinate_y + 1, width_small_box, height_box, LIGHT_AQUA);
	my_print(coordinate_x + 1 + 7, coordinate_y + 1 + 1, LIGHT_RED, curYear + "-" + std::to_string(stoi(curYear) + 1));
	newStudent.Schoolyear = curYear + "-" + std::to_string(stoi(curYear) + 1);

	my_print(coordinate_x + 30, coordinate_y, LIGHT_AQUA, "Semester:");
	box(coordinate_x + 30, coordinate_y + 1, width_small_box, height_box, LIGHT_AQUA);
	my_print(coordinate_x + 30 + 1 + 12, coordinate_y + 1 + 1, LIGHT_RED, curSemester);
	newStudent.Semester = stoi(curSemester);

enter_StudentID:
	ShowCur(1);
	my_print(coordinate_x, coordinate_y + 5, YELLOW, "Enter student ID which you want to add to course:");
	box(coordinate_x, coordinate_y + 5 + 1, width_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 1, coordinate_y + 5 + 1 + 1);
	newStudent.StuID = my_getline(width_box);
	if (newStudent.StuID == "-1")
		return;

	STU_NODE* cur_student = student;
	while (cur_student) {
		if (cur_student->student.StudentID == newStudent.StuID)
			break;
		cur_student = cur_student->next;
	}
	if (cur_student == nullptr) {
		ShowCur(0);
		my_print(coordinate_x + 8, coordinate_y + 10, RED * 16 + LIGHT_AQUA, "Student ID doesn't exist.");

		my_print(coordinate_x + 8, coordinate_y + 10 + 2, LIGHT_GREEN * 16 + BLACK, "Do you want to enter again:");
		int choice = enter_again_yes_no(coordinate_x + 10, coordinate_y + 10 + 4, 8, 3, 4, LIGHT_AQUA, LIGHT_GREEN);
		if (choice == 1) {

			textcolor(BLACK * 16 + BLACK);
			for (int j = 0; j < 13; j++)
				for (int i = 0; i < 50; i++) {
					gotoXY(coordinate_x + i, coordinate_y + 5 + j);
					std::cout << " ";
				}
			textcolor(WHITE);
			goto enter_StudentID;
		}
		else {
			return;
		}
	}

enter_CourseID:
	ShowCur(1);
	my_print(coordinate_x, coordinate_y + 10, YELLOW, "Enter course ID which you want to add a student:");
	box(coordinate_x, coordinate_y + 10 + 1, width_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 1, coordinate_y + 10 + 1 + 1);
	newStudent.CouID = my_getline(width_box);
	if (newStudent.CouID == "-1")
		return;

	CR_NODE* cur_course = course;
	while (cur_course) {
		if (cur_course->course.ID == newStudent.CouID)
			break;
		cur_course = cur_course->next;
	}
	if (cur_course == nullptr) {
		ShowCur(0);
		my_print(coordinate_x + 8, coordinate_y + 15, RED * 16 + LIGHT_AQUA, "Course ID doesn't exist.");

		my_print(coordinate_x + 8, coordinate_y + 15 + 2, LIGHT_GREEN * 16 + BLACK, "Do you want to enter again:");
		int choice = enter_again_yes_no(coordinate_x + 10, coordinate_y + 15 + 4, 8, 3, 4, LIGHT_AQUA, LIGHT_GREEN);
		if (choice == 1) {
			textcolor(BLACK * 16 + BLACK);
			for (int j = 0; j < 13; j++)
				for (int i = 0; i < 50; i++) {
					gotoXY(coordinate_x + i, coordinate_y + 10 + j);
					std::cout << " ";
				}
			textcolor(WHITE);
			goto enter_CourseID;
		}
		else {
			return;
		}
	}
	STU_COURSE_NODE* cur_stu_course = stu_course;
	while (cur_stu_course) {
		if (cur_stu_course->stu_course.CouID == newStudent.CouID && cur_stu_course->stu_course.StuID == newStudent.StuID) {
			ShowCur(0);
			textcolor(LIGHT_RED * 16 + BLACK);
			for (int j = 0; j < 3; j++)
				for (int i = 0; i < 50; i++) {
					gotoXY(coordinate_x + i, coordinate_y + 15 + j);
					std::cout << " ";
				}
			gotoXY(coordinate_x + 1, coordinate_y + 15 + 1);
			std::cout << "This student ID has registered for this course.";
			textcolor(WHITE);

			char ans = _getch();
			return;
		}
		cur_stu_course = cur_stu_course->next;
	}

	cur_stu_course = stu_course;
	if (cur_stu_course == nullptr) {
		return;
	}
	while (cur_stu_course->next) {
		cur_stu_course = cur_stu_course->next;
	}

	newStudent.No = cur_stu_course->stu_course.No + 1;
	newStudent.Class = cur_student->student.Classes.ClassID;
	newStudent.Cname = cur_course->course.CName;
	newStudent.credits = cur_course->course.Credits;
	newStudent.startdate = cur_course->course.startDate;
	newStudent.enddate = cur_course->course.endDate;
	newStudent.StudentName = cur_student->student.FName + " " + cur_student->student.LName;
	newStudent.Gen = cur_student->student.Gender;
	newStudent.Max_stdn = cur_course->course.Max_stdn;
	newStudent.Schoolyear = cur_course->course.Schoolyear;
	newStudent.Semester = cur_course->course.Semester;
	newStudent.session = cur_course->course.session;
	newStudent.weekday = cur_course->course.dayOfWeek;
	newStudent.TeacherID = cur_course->course.teacherID;
	newStudent.TeacherID = cur_course->course.FNameTeacher + " " + cur_course->course.LNameTeacher;
	newStudent.midterm = 0;
	newStudent.final = 0;
	newStudent.other = 0;
	newStudent.total = 0;


	cur_stu_course->next = new STU_COURSE_NODE;
	cur_stu_course->next->stu_course = newStudent;
	cur_stu_course->next->prev = cur_stu_course;
	cur_stu_course = cur_stu_course->next;
	cur_stu_course->next = nullptr;

	reread_after_update_student_course(student, course, teacher, stu_course);
	update_cur_stdn_in_course(course, stu_course);

	ShowCur(0);
	textcolor(LIGHT_GREEN * 16 + BLACK);
	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 48; i++) {
			gotoXY(coordinate_x + i, coordinate_y + 15 + j);
			std::cout << " ";
		}
	gotoXY(coordinate_x + 8, coordinate_y + 15 + 1);
	std::cout << "Add a student successfully.";
	textcolor(WHITE);

	char ans = _getch();
	return;
}

//3
void Remove_Student_From_Course(STU_COURSE_NODE*& stu_course, STU_NODE* student, STFF_NODE* teacher, CR_NODE* course) {
comeBackHere:
	system("cls");

	view_list_of_courses(course);

	int coordinate_x = 35;
	int coordinate_y = 27;
	int width_box = 30;
	int height_box = 2;
	std::string courseID;

enter_courseID:
	my_print(coordinate_x, coordinate_y, YELLOW * 16 + BLACK, "Enter Course ID which you want to open: ");
	box(coordinate_x, coordinate_y + 1, width_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 1, coordinate_y + 2);
	ShowCur(1);
	courseID = (my_getline(width_box - 1));
	if (courseID == "-1")
		return;

	STU_COURSE_NODE* cur1 = stu_course;
	while (cur1) {
		if (cur1->stu_course.CouID == courseID) {
			system("cls");
			display_list_students_of_course(stu_course, student, courseID);

		enter_StudentID:
			my_print(coordinate_x, coordinate_y, YELLOW * 16 + BLACK, "Enter the ID of the student you want to remove:");
			box(coordinate_x, coordinate_y + 1, width_box, height_box, LIGHT_AQUA);
			std::string studentID;
			gotoXY(coordinate_x + 1, coordinate_y + 2);
			ShowCur(1);
			studentID = my_getline(width_box - 1);
			if (studentID == "-1")
				goto comeBackHere;

			STU_COURSE_NODE* cur2 = stu_course;
			while (cur2) {
				if (cur2->stu_course.StuID == studentID) {
					STU_COURSE_NODE* cur3 = stu_course;
					while (cur3) {
						if (cur3->stu_course.CouID == courseID && cur3->stu_course.StuID == studentID) {
							if (cur3 == stu_course)
								stu_course = stu_course->next;
							else
								cur3->prev->next = cur3->next;

							if (cur3->next != nullptr)
								cur3->next->prev = cur3->prev;

							delete cur3;
							reread_after_update_student_course(student, course, teacher, stu_course);
							update_cur_stdn_in_course(course, stu_course);
							textcolor(LIGHT_GREEN * 16 + BLACK);
							for (int j = 0; j < 3; j++)
								for (int i = 0; i < 48; i++) {
									gotoXY(coordinate_x + 60 + i, coordinate_y + j);
									std::cout << " ";
								}
							gotoXY(coordinate_x + 60 + 8, coordinate_y + 1);
							std::cout << "Removed student successfully.";
							textcolor(WHITE);

							char ans = _getch();
							return;

						}
						cur3 = cur3->next;
					}
					textcolor(LIGHT_RED * 16 + BLACK);
					for (int j = 0; j < 3; j++)
						for (int i = 0; i < 48; i++) {
							gotoXY(coordinate_x + 60 + i, coordinate_y + j);
							std::cout << " ";
						}
					gotoXY(coordinate_x + 60 + 10, coordinate_y + 1);
					std::cout << "There are some problem!";
					textcolor(WHITE);

					char ans = _getch();
					return;
				}
				cur2 = cur2->next;
			}
			ShowCur(0);
			my_print(coordinate_x + 53, coordinate_y, RED * 16 + LIGHT_AQUA, "Student ID doesn't exist.");

			my_print(coordinate_x + 53, coordinate_y + 2, LIGHT_GREEN * 16 + BLACK, "Do you want to enter again:");
			int choice = enter_again_yes_no(coordinate_x + 53, coordinate_y + 4, 8, 3, 4, LIGHT_AQUA, LIGHT_GREEN);
			if (choice == 1) {
				textcolor(BLACK * 16 + BLACK);
				for (int j = 0; j < 8; j++)
					for (int i = 0; i < 80; i++) {
						gotoXY(coordinate_x + i, coordinate_y + j);
						std::cout << " ";
					}
				textcolor(WHITE);
				goto enter_StudentID;
			}
			else {
				return;
			}
		}
		cur1 = cur1->next;
	}
	ShowCur(0);
	my_print(coordinate_x + 53, coordinate_y, RED * 16 + LIGHT_AQUA, "No student in the course.");

	my_print(coordinate_x + 53, coordinate_y + 2, LIGHT_GREEN * 16 + BLACK, "Do you want to enter again:");
	int choice = enter_again_yes_no(coordinate_x + 53, coordinate_y + 4, 8, 3, 4, LIGHT_AQUA, LIGHT_GREEN);
	if (choice == 1) {
		textcolor(BLACK * 16 + BLACK);
		for (int j = 0; j < 8; j++)
			for (int i = 0; i < 80; i++) {
				gotoXY(coordinate_x + i, coordinate_y + j);
				std::cout << " ";
			}
		textcolor(WHITE);
		goto enter_courseID;
	}
	else {
		return;
	}
}

//4
void delete_course(STU_COURSE_NODE*& stu_course, STFF_NODE* teacher, CR_NODE*& course) {
	system("cls");

	int coordinate_x = 30;
	int coordinate_y = 26;
	int width_box = 30;
	int height_box = 2;

	view_list_of_courses(course);
	std::string courseID;
	CR_NODE* cur = course;
Here_enter_y3:
	my_print(coordinate_x, coordinate_y, YELLOW * 16 + BLACK, "Enter Course ID you want to delete:");
	box(coordinate_x, coordinate_y + 1, width_box, height_box, LIGHT_AQUA);
	ShowCur(1);
	gotoXY(coordinate_x + 1, coordinate_y + 1 + 1);
	courseID = (my_getline(width_box - 1));
	if (courseID == "-1")
		return;
	CR_NODE* DelNode = check_exist_of_course_record(course, courseID);

	if (DelNode) {
		if (DelNode == course)
			course = course->next;
		else
			DelNode->prev->next = DelNode->next;
		if (DelNode->next != nullptr)
			DelNode->next->prev = DelNode->prev;
		delete DelNode;
		my_print(coordinate_x, coordinate_y + 5, LIGHT_GREEN, "Delete Course Successfully.");
		gotoXY(coordinate_x, coordinate_y + 7);
		reread_after_update_course(stu_course, teacher, *&course);
		system("pause");
		return;
	}
	else {
		ShowCur(0);
		my_print(coordinate_x + 60, coordinate_y, RED * 16 + LIGHT_AQUA, "Course ID does not exist.");

		my_print(coordinate_x + 60, coordinate_y + 2, LIGHT_GREEN * 16 + BLACK, "Do you want to enter again:");
		int choice = enter_again_yes_no(coordinate_x + 60, coordinate_y + 4, 8, 3, 4, LIGHT_AQUA, LIGHT_GREEN);
		if (choice == 1) {
			textcolor(BLACK * 16 + BLACK);
			for (int j = 0; j < 8; j++)
				for (int i = 0; i < 87; i++) {
					gotoXY(coordinate_x + i, coordinate_y + j);
					std::cout << " ";
				}
			textcolor(WHITE);
			goto Here_enter_y3;
		}
		else {
			return;
		}
	}
}

//5
void update_course_information(STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE*& head) {
	system("cls");
	CR_NODE* cur = head;
	view_list_of_courses(cur);
	int x_tmp = 30;
	int y_tmp = 26;
	int width_tmp = 40;
	int height_tmp = 2;
	std::string UpID, tmp;
Here_enter_y:
	ShowCur(1);
	my_print(x_tmp, y_tmp, YELLOW * 16 + BLACK, "Enter Course ID: ");
	box(x_tmp, y_tmp + 1, width_tmp, height_tmp, LIGHT_AQUA);
	gotoXY(x_tmp + 1, y_tmp + 1 + 1);
	tmp = (my_getline(width_tmp - 1));
	if (tmp == "-1")
		return;
	else
		UpID = tmp;
	CR_NODE* UpNode = check_exist_of_course_record(head, UpID);
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
		reread_after_update_course(stu_course, teacher, head);
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

	ShowCur(0);
	my_print(x_tmp + 60, y_tmp, RED * 16 + LIGHT_AQUA, "Course ID does not exist.");

	my_print(x_tmp + 60, y_tmp + 2, LIGHT_GREEN * 16 + BLACK, "Do you want to enter again:");
	int choice = enter_again_yes_no(x_tmp + 60, y_tmp + 4, 8, 3, 4, LIGHT_AQUA, LIGHT_GREEN);
	if (choice == 1) {
		textcolor(BLACK * 16 + BLACK);
		for (int j = 0; j < 8; j++)
			for (int i = 0; i < 87; i++) {
				gotoXY(x_tmp + i, y_tmp + j);
				std::cout << " ";
			}
		textcolor(WHITE);
		goto Here_enter_y;
	}
	else {
		return;
	}
}

//6
bool Update_from_enrolled_students_file(STU_COURSE_NODE*& stu_course, std::string courseID, std::string fileName, CR_NODE* course, STU_NODE* student, STFF_NODE* teacher) {
	std::ifstream in;
	STU_COURSE_NODE* cur_stu_course = stu_course;
	CR_NODE* cur_course = course;
	STU_NODE* cur_student = student;

	while (cur_course->course.ID != courseID)
		cur_course = cur_course->next;

	while (cur_stu_course->next)
		cur_stu_course = cur_stu_course->next;

	int i = cur_stu_course->stu_course.No + 1;

	in.open(fileName);

	if (!in.is_open()) {
		return false;
	}
	std::string curYear, curSemester;
	get_curYear_and_curSemester(80, 25, curYear, curSemester);

	std::string tmp;
	std::getline(in, tmp);

	while (!in.eof()) {
		STU_COURSE_NODE* new_stu_course = new STU_COURSE_NODE;
		new_stu_course->stu_course.final = new_stu_course->stu_course.midterm = new_stu_course->stu_course.other = new_stu_course->stu_course.total = 0;

		std::getline(in, tmp, ',');
		std::getline(in, tmp, ',');
		new_stu_course->stu_course.Schoolyear = curYear;
		new_stu_course->stu_course.Semester = stoi(curSemester);

		while (cur_student->student.StudentID != tmp)
			cur_student = cur_student->next;

		new_stu_course->stu_course.StudentName = cur_student->student.LName + " " + cur_student->student.FName;
		new_stu_course->stu_course.StuID = cur_student->student.StudentID;
		new_stu_course->stu_course.No = i;

		new_stu_course->stu_course.Gen = cur_student->student.Gender;

		new_stu_course->stu_course.Class = cur_student->student.Classes.ClassID;

		new_stu_course->stu_course.CouID = cur_course->course.ID;
		new_stu_course->stu_course.Cname = cur_course->course.CName;
		new_stu_course->stu_course.credits = cur_course->course.Credits;
		new_stu_course->stu_course.Max_stdn = cur_course->course.Max_stdn;
		new_stu_course->stu_course.Teachername = cur_course->course.LNameTeacher + cur_course->course.FNameTeacher;

		new_stu_course->stu_course.TeacherID = cur_course->course.teacherID;
		new_stu_course->stu_course.weekday = ConvertStringWD(cur_course->course.dayOfWeek);
		new_stu_course->stu_course.session = ConvertStringSS(cur_course->course.session);
		new_stu_course->stu_course.startdate.day = cur_course->course.startDate.day;
		new_stu_course->stu_course.startdate.month = cur_course->course.startDate.month;
		new_stu_course->stu_course.enddate.day = cur_course->course.endDate.day;
		new_stu_course->stu_course.enddate.month = cur_course->course.endDate.month;

		cur_stu_course->next = new_stu_course;
		new_stu_course->next = nullptr;
		new_stu_course->prev = cur_stu_course;
		cur_stu_course = cur_stu_course->next;
		i++;

		cur_student = student;
		std::getline(in, tmp, '\n');
	}
	reread_after_update_student_course(student, course, teacher, stu_course);
	in.close();
	return true;
}
void upload_CSV_of_enrolled_students(STU_COURSE_NODE* stu_course, CR_NODE* course, STU_NODE* student, STFF_NODE* teacher) {
	int coordinate_x = 95;
	int coordinate_y = 8;
	int width_box = 40;
	int height_box = 2;
	int width_small_box = 25;
	std::string curYear, curSemester;
	STU_COURSE newStudent;

	get_curYear_and_curSemester(coordinate_x, coordinate_y, curYear, curSemester);

	textcolor(LIGHT_YELLOW * 16 + BLACK);
	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 40; i++) {
			gotoXY(coordinate_x + 7 + i, coordinate_y - 5 + j);
			std::cout << " ";
		}
	gotoXY(coordinate_x + 7 + 4, coordinate_y - 5 + 1);
	std::cout << "UPLOAD CSV OF ENROLLED STUDENTS";
	textcolor(WHITE);

	ShowCur(1);
	my_print(coordinate_x, coordinate_y, LIGHT_AQUA, "School Year:");
	box(coordinate_x, coordinate_y + 1, width_small_box, height_box, LIGHT_AQUA);
	my_print(coordinate_x + 1 + 7, coordinate_y + 1 + 1, LIGHT_RED, curYear + "-" + std::to_string(stoi(curYear) + 1));
	newStudent.Schoolyear = curYear + "-" + std::to_string(stoi(curYear) + 1);

	my_print(coordinate_x + 30, coordinate_y, LIGHT_AQUA, "Semester:");
	box(coordinate_x + 30, coordinate_y + 1, width_small_box, height_box, LIGHT_AQUA);
	my_print(coordinate_x + 30 + 1 + 12, coordinate_y + 1 + 1, LIGHT_RED, curSemester);
	newStudent.Semester = stoi(curSemester);

	std::string courseID, fileName;
enter_StudentID:
	ShowCur(1);
	my_print(coordinate_x, coordinate_y + 5, LIGHT_AQUA, "Enter course ID for which you want to add students: \n");
	box(coordinate_x, coordinate_y + 5 + 1, width_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 1, coordinate_y + 5 + 1 + 1);
	courseID = my_getline_addSpace(width_box - 1);
	if (courseID == "-1")
		return;
	if (check_exist_of_course_record(course, courseID) == nullptr) {
		ShowCur(0);
		my_print(coordinate_x + 8, coordinate_y + 10, RED * 16 + LIGHT_AQUA, "Course ID doesn't exist.");

		my_print(coordinate_x + 8, coordinate_y + 10 + 2, LIGHT_GREEN * 16 + BLACK, "Do you want to enter again:");
		int choice = enter_again_yes_no(coordinate_x + 10, coordinate_y + 10 + 4, 8, 3, 4, LIGHT_AQUA, LIGHT_GREEN);
		if (choice == 1) {
			textcolor(BLACK * 16 + BLACK);
			for (int j = 0; j < 13; j++)
				for (int i = 0; i < 50; i++) {
					gotoXY(coordinate_x + i, coordinate_y + 5 + j);
					std::cout << " ";
				}
			textcolor(WHITE);
			goto enter_StudentID;
		}
		else {
			return;
		}
	}

	my_print(coordinate_x, coordinate_y + 10, LIGHT_AQUA, "What is the name of your csv file?\n");
	box(coordinate_x, coordinate_y + 10 + 1, width_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 1, coordinate_y + 10 + 2);
	fileName = my_getline_addSpace(width_box - 1);
	if (fileName == "-1")
		return;

	if (!Update_from_enrolled_students_file(stu_course, courseID, fileName, course, student, teacher)) {
		ShowCur(0);
		textcolor(LIGHT_RED * 16 + BLACK);
		for (int j = 0; j < 4; j++)
			for (int i = 0; i < 48; i++) {
				gotoXY(coordinate_x + i, coordinate_y + 15 + j);
				std::cout << " ";
			}
		gotoXY(coordinate_x + 3, coordinate_y + 15 + 1);
		std::cout << "We're sorry, there was an issue with the ";
		gotoXY(coordinate_x + 3, coordinate_y + 15 + 2);
		std::cout << "file you provided. Please try again later";
		textcolor(WHITE);

		char ans = _getch();
		return;
	}
	else {
		reread_after_update_student_course(student, course, teacher, stu_course);
		update_cur_stdn_in_course(course, stu_course);
		ShowCur(0);
		textcolor(LIGHT_GREEN * 16 + BLACK);
		for (int j = 0; j < 3; j++)
			for (int i = 0; i < 48; i++) {
				gotoXY(coordinate_x + i, coordinate_y + 15 + j);
				std::cout << " ";
			}
		gotoXY(coordinate_x + 6, coordinate_y + 15 + 1);
		std::cout << "Upload students successfully.";
		textcolor(WHITE);

		char ans = _getch();
		return;
	}
}

//7
void update_mark_information(STU_NODE* student, STU_COURSE_NODE*& stu_course, STFF_NODE* teacher, CR_NODE*& course) {
	system("cls");
	int coordinate_x = 40;
	int coordinate_y = 27;
	int width_box = 30;
	int width_small_box = 10;
	int height_box = 2;

again_courseID2:
	CR_NODE* cur = course;
	view_list_of_courses(cur);

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

	CR_NODE* course_node = check_exist_of_course_record(course, courseID);
	if (course_node) {
		std::system("cls");
		display_list_students_of_course(stu_course, student, courseID);

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

		STU_COURSE_NODE* stu_course_node = check_exist_of_student_course_record(stu_course, studentID);
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
				reread_after_update_student_course(student, course, teacher, stu_course);
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
		my_print(coordinate_x + 40, coordinate_y, RED * 16 + BLACK, "Course ID does not exist.");
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