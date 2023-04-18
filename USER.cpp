
#include "header.h"

//*****************LOGIN/LOGOUT*****************

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@STAFF@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//menu teacher
void printInformation_A_Staff(STFF_NODE* loggedinStaff) {
	std::string fullname = loggedinStaff->staff.LName + " " + loggedinStaff->staff.FName;
	std::string DoB = std::to_string(loggedinStaff->staff.DoB.day / 10) + std::to_string(loggedinStaff->staff.DoB.day % 10) + "/"
		+ std::to_string(loggedinStaff->staff.DoB.month / 10) + std::to_string(loggedinStaff->staff.DoB.month % 10) + "/"
		+ std::to_string(loggedinStaff->staff.DoB.year);
	std::cout << std::setw(45) << std::right << "Teacher's information"
		<< "\n\t" << std::setfill('*') << std::setw(55) << "*" << std::setfill(' ')
		<< "\n\t" << std::setw(15) << std::left << "Full name : " << std::setw(40) << std::right << fullname
		<< "\n\t" << std::setw(15) << std::left << "Teacher ID: " << std::setw(40) << std::right << loggedinStaff->staff.TeacherID
		<< "\n\t" << std::setw(15) << std::left << "Gender: " << std::setw(40) << std::right << loggedinStaff->staff.Gender
		<< "\n\t" << std::setw(15) << std::left << "Date of birth: " << std::setw(40) << std::right << DoB
		<< "\n\t" << std::setw(15) << std::left << "Faculty: " << std::setw(40) << std::right << loggedinStaff->staff.Faculty << "\n\n";
}

//============================ view list of class============================ 
CLASS_NODE* checkExistClassNODEIDinDLL(CLASS_NODE* listclass, std::string classID) {
	CLASS_NODE* cur = listclass;
	while (cur) {
		if (cur->listclass.ClassID == classID)
			return cur;
		cur = cur->next;
	}
	return nullptr;
}
STU_NODE* checkExistClassIDinDLL(STU_NODE*& listclass, std::string classID) {
	STU_NODE* cur = listclass;
	while (cur) {
		if (cur->student.Classes.ClassID == classID)
			return cur;
		cur = cur->next;
	}
	return nullptr;
}

void deleteSTU_NODE(STU_NODE*& head) {
	STU_NODE* tmp = head;
	while (head) {
		tmp = head;
		head = head->next;
		delete tmp;
	}
}


void ViewListOfTeachers(STFF_NODE* teacher) {
	STFF_NODE* cur = teacher;
	std::system("cls");

	std::cout << "============================================LIST OF TEACHERS ============================================\n\n";
	std::cout << std::setw(5) << std::left << " " << std::setw(5) << std::left << "No" << std::setw(5) << std::left << "|"
		<< std::setw(15) << std::left << "Teachers ID" << std::setw(5) << std::left << "|"
		<< std::setw(20) << std::left << "Teacher's last name" << std::setw(5) << std::left << "|"
		<< std::setw(20) << std::left << "Teacher's first name" << std::setw(5) << std::left << "|"
		<< std::setw(10) << std::left << "Gender" << std::setw(5) << std::left << "|"
		<< std::setw(20) << std::left << "Day of Birth" << std::setw(5) << std::left << "|"
		<< std::setw(20) << std::left << "Social ID" << std::setw(5) << std::left << "|"
		<< std::setw(40) << std::left << "Faculty" << std::setw(5) << std::left << "|" << std::endl;
	std::cout << std::setfill('-') << std::setw(190) << std::left << "-" << std::setfill(' ') << "\n";

	while (cur) {
		std::string birthday = std::to_string(cur->staff.DoB.day) + "/" + std::to_string(cur->staff.DoB.month) + "/" + std::to_string(cur->staff.DoB.year);
		std::cout << std::setw(5) << std::left << " " << std::setw(5) << std::left << cur->staff.No_Staff << std::setw(5) << std::left << "|"
			<< std::setw(15) << std::left << cur->staff.TeacherID << std::setw(5) << std::left << "|"
			<< std::setw(20) << std::left << cur->staff.LName << std::setw(5) << std::left << "|"
			<< std::setw(20) << std::left << cur->staff.FName << std::setw(5) << std::left << "|"
			<< std::setw(10) << std::left << cur->staff.Gender << std::setw(5) << std::left << "|"
			<< std::setw(20) << std::left << birthday << std::setw(5) << "|"
			<< std::setw(20) << std::left << cur->staff.SocialID << std::setw(5) << std::left << "|"
			<< std::setw(40) << std::left << cur->staff.Faculty << std::setw(5) << std::left << "|" << std::endl;
		cur = cur->next;
	}
}


void View_Y_Scoreboard(STU_COURSE_NODE* stu_course, STU_NODE* loggedinStudent) {
	std::system("cls");
	STU_COURSE_NODE* current = stu_course;

	int count = 1;

	std::system("cls");

	std::cout << "====================================================================YOUR SCOREBOARD=========================================================================\n";
	int coordinate_x = 0;
	int coordinate_y = 3;

	int width_no = 5;
	int width_Schoolyear = 15;
	int width_Sem = 10;
	int width_CourseID = 10;
	int width_courseName = 25;
	int width_mid = 8;
	int width_final = 8;
	int width_other = 8;
	int width_total = 8;
	int width_Ranking = 8;


	int width = width_no + width_CourseID + width_courseName + width_Schoolyear + width_Sem
		+ width_mid + width_final + width_other + width_total + width_Ranking + 5 * 10;

	gotoXY(coordinate_x, coordinate_y); std::cout << "+";
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y); std::cout << "-";
	}
	gotoXY(coordinate_x + width, coordinate_y); std::cout << "+\n";

	gotoXY(coordinate_x, coordinate_y + 1);
	std::cout << std::setw(5) << std::left << "|" << std::setw(width_no) << std::left << "No" << std::setw(5) << std::left << "|"
		<< std::setw(width_Schoolyear) << std::left << "SchoolYear" << std::setw(5) << std::left << "|"
		<< std::setw(width_Sem) << std::left << " Sem" << std::setw(5) << std::left << "|"
		<< std::setw(width_CourseID) << std::left << "Course ID" << std::setw(5) << std::left << "|"
		<< std::setw(width_courseName) << std::left << "Course name" << std::setw(5) << std::left << "|"
		<< std::setw(width_mid) << std::left << "Midterm" << std::setw(5) << std::left << "|"
		<< std::setw(width_final) << std::left << "Final" << std::setw(5) << std::left << "|"
		<< std::setw(width_other) << std::left << "Other" << std::setw(5) << std::left << "|"
		<< std::setw(width_total) << std::left << "Total" << std::setw(5) << std::left << "|"
		<< std::setw(width_Ranking) << std::left << "Ranking" << std::setw(5) << std::left << "|" << "\n";

	gotoXY(coordinate_x, coordinate_y + 2); std::cout << "+";
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y + 2); std::cout << "-";
	}
	gotoXY(coordinate_x + width, coordinate_y + 2); std::cout << "+\n";

	while (current != nullptr) {
		ShowCur(1);
		if (current->stu_course.StuID == loggedinStudent->student.StudentID) {
			count++;
			std::cout << std::setw(5) << std::left << "|" << std::setw(width_no) << std::left << count << std::setw(5) << std::left << "|"
				<< std::setw(width_Schoolyear) << std::left << current->stu_course.Schoolyear << std::setw(5) << std::left << "|"
				<< std::setw(width_Sem) << std::left << current->stu_course.Semester << std::setw(5) << std::left << "|"
				<< std::setw(width_CourseID) << std::left << current->stu_course.CouID << std::setw(5) << std::left << "|"
				<< std::setw(width_courseName) << std::left << current->stu_course.Cname << std::setw(5) << std::left << "|"
				<< std::setw(width_mid) << std::left << current->stu_course.midterm << std::setw(5) << std::left << "|"
				<< std::setw(width_final) << std::left << current->stu_course.final << std::setw(5) << std::left << "|"
				<< std::setw(width_other) << std::left << current->stu_course.other << std::setw(5) << std::left << "|"
				<< std::setw(width_total) << std::left << current->stu_course.total << std::setw(5) << std::left << "|"
				<< std::setw(width_total) << std::left << GetRanking(current->stu_course.total) << "|" << std::endl;
		}
		current = current->next;
	}
		
/* 	std::cout << "+" << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << "+";
	std::cout << std::setw(3) << std::left << "|" << std::setw(5) << std::left << "No" << std::setw(5) << std::left << "|"
		<< std::setw(15) << std::left << "SchoolYear" << std::setw(5) << std::left << "|"
		<< std::setw(10) << std::left << " Sem" << std::setw(5) << std::left << "|"
		<< std::setw(10) << std::left << "Course ID" << std::setw(5) << std::left << "|"
		<< std::setw(30) << std::left << "Course Name" << std::setw(5) << std::left << "|"
		<< std::setw(10) << std::left << "Midterm" << std::setw(5) << std::left << "|"
		<< std::setw(10) << std::left << "Final" << std::setw(5) << std::left << "|"
		<< std::setw(10) << std::left << "Total" << std::setw(5) << std::left << "|"
		<< std::setw(11) << std::left << "Ranking" << "|" << std::endl;
	std::cout << "+" << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << "+";

	while (current != nullptr) {
		if (current->stu_course.StuID == loggedinStudent->student.StudentID) {
			std::cout << std::setw(3) << std::left << "|" << std::setw(5) << std::left << count << std::setw(5) << std::left << "|"
				<< std::setw(15) << std::left << current->stu_course.Schoolyear << std::setw(5) << std::left << "|"
				<< std::setw(10) << std::left << current->stu_course.Semester << std::setw(5) << std::left << "|"
				<< std::setw(10) << std::left << current->stu_course.CouID << std::setw(5) << std::left << "|"
				<< std::setw(30) << std::left << current->stu_course.Cname << std::setw(5) << std::left << "|"
				<< std::setw(10) << std::left << current->stu_course.midterm << std::setw(5) << std::left << "|"
				<< std::setw(10) << std::left << current->stu_course.final << std::setw(5) << std::left << "|"
				<< std::setw(10) << std::left << current->stu_course.total << std::setw(5) << std::left << "|"
				<< std::setw(11) << std::left << GetRanking(current->stu_course.total) << "|" << std::endl;
			count++;
		}
		current = current->next;
	}
	std::cout << "+" << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << "+"; */
}


void View_List_of_courses_From_current_time(CR_NODE *course, int day, int month) {
	std::system("cls");
	int coordinate_x = 0;
	int coordinate_y = 3;

	int width_no = 5;
	int width_schoolYear = 11;
	int width_semester = 5;
	int width_courseID = 10;
	int width_courseName = 26;
	int width_teacherName = 23;
	int width_credits = 9;
	int width_registered = 10;
	int width_calendar = 20;

	int width = width_no + width_schoolYear + width_semester + width_courseID + width_courseName + width_teacherName + width_credits
		+ width_registered + width_calendar + 5 * 8;

	gotoXY(coordinate_x, coordinate_y); std::cout << "+";
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y); std::cout << "-";
	}
	gotoXY(coordinate_x + width, coordinate_y); std::cout << "+";

	gotoXY(coordinate_x, coordinate_y + 1);
	std::cout << std::setw(5) << std::left << "|" << std::setw(width_no) << std::left << "No" << std::setw(5) << std::left << "|"
		<< std::setw(width_schoolYear) << std::left << "School year" << std::setw(5) << std::left << "|"
		<< std::setw(width_semester) << std::left << "Sem" << std::setw(5) << std::left << "|"
		<< std::setw(width_courseID) << std::left << "Course ID" << std::setw(5) << std::left << "|"
		<< std::setw(width_courseName) << std::left << "Course name" << std::setw(5) << std::left << "|"
		<< std::setw(width_teacherName) << std::left << "Teacher name" << std::setw(5) << std::left << "|"
		<< std::setw(width_credits) << std::left << "Credits" << std::setw(5) << std::left << "|"
		<< std::setw(width_registered) << std::left << "Registered" << std::setw(5) << std::left << "|"
		<< std::setw(width_calendar) << std::left << "Calendar";

	gotoXY(coordinate_x, coordinate_y + 2); std::cout << "+";
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y + 2); std::cout << "-";
	}
	gotoXY(coordinate_x + width, coordinate_y + 2); std::cout << "+";

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

		if (cur_course->course.startDate.day >= day && cur_course->course.startDate.month >= month || cur_course->course.startDate.month >= month) {
			std::string fullname = cur_course->course.LNameTeacher + " " + cur_course->course.FNameTeacher;
			std::string registered = std::to_string(cur_course->course.Cur_stdn) + "/" + std::to_string(cur_course->course.Max_stdn);
			std::string calendar = ConvertStringWD(cur_course->course.dayOfWeek) + "-" + ConvertStringSS(cur_course->course.session);
			std::cout << std::setw(5) << std::left << "|" << std::setw(width_no) << std::left << no++ << std::setw(5) << std::left << "|"
				<< std::setw(width_schoolYear) << std::left << cur_course->course.Schoolyear << std::setw(5) << std::left << "|"
				<< std::setw(width_semester) << std::left << cur_course->course.Semester << std::setw(5) << std::left << "|"
				<< std::setw(width_courseID) << std::left << cur_course->course.ID << std::setw(5) << std::left << "|"
				<< std::setw(width_courseName) << std::left << cur_course->course.CName << std::setw(5) << std::left << "|"
				<< std::setw(width_teacherName) << std::left << fullname << std::setw(5) << std::left << "|"
				<< std::setw(width_credits) << std::left << cur_course->course.Credits << std::setw(5) << std::left << "|"
				<< std::setw(width_registered) << std::left << registered << std::setw(5) << std::left << "|"
				<< std::setw(width_calendar) << std::left << calendar;
		}

		if (i == 15 || cur_course->next == nullptr) {
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


void CreateNewCourse_from_current_time(STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE*& head) {
	ShowCur(1);
	CR_NODE* NewCourse = new CR_NODE;
	CR_NODE* cur = head;

	int coordinate_x = 60;
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

	std::string NewSchoolyear;
	my_print(coordinate_x, coordinate_y, LIGHT_AQUA, "Enter School Year:");
	box(coordinate_x, coordinate_y + 1, width_small_box, height_box, LIGHT_AQUA);
Here_enter_y:
	gotoXY(coordinate_x + 1, coordinate_y + 1 + 1);
	NewSchoolyear = my_getline(4);
	if (NewSchoolyear == "-1")
		return;
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
	std::string tmp = my_getline_onlyNumber(1);
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
	NewCourse->course.CName = my_getline_addSpace(width_big_box - 1);
	if (NewCourse->course.CName == "-1")
		return;

	my_print(coordinate_x, coordinate_y + 8, LIGHT_AQUA, "Enter Course ID:");
	box(coordinate_x, coordinate_y + 8 + 1, width_big_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 1, coordinate_y + 8 + 1 + 1);
	NewCourse->course.ID = my_getline_addSpace(width_big_box - 1);
	if (NewCourse->course.ID == "-1")
		return;

	my_print(coordinate_x, coordinate_y + 12, LIGHT_AQUA, "Enter Teacher's last name:");
	box(coordinate_x, coordinate_y + 12 + 1, width_small_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 1, coordinate_y + 12 + 1 + 1);
	NewCourse->course.LNameTeacher = my_getline_addSpace(width_small_box - 1);
	if (NewCourse->course.LNameTeacher == "-1")
		return;

	my_print(coordinate_x + 30, coordinate_y + 12, LIGHT_AQUA, "Enter Teacher's first name:");
	box(coordinate_x + 30, coordinate_y + 12 + 1, width_small_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 30 + 1, coordinate_y + 12 + 1 + 1);
	NewCourse->course.FNameTeacher = my_getline_addSpace(width_small_box - 1);
	if (NewCourse->course.FNameTeacher == "-1")
		return;

	my_print(coordinate_x, coordinate_y + 16, LIGHT_AQUA, "Enter Credits:");
	box(coordinate_x, coordinate_y + 16 + 1, width_small_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 1, coordinate_y + 16 + 1 + 1);
	NewCourse->course.Credits = stoi(my_getline_onlyNumber(3));
	if (std::to_string(NewCourse->course.Credits) == "-1")
		return;

	my_print(coordinate_x + 30, coordinate_y + 16, LIGHT_AQUA, "Enter Max Students:");
	box(coordinate_x + 30, coordinate_y + 16 + 1, width_small_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 30 + 1, coordinate_y + 16 + 1 + 1);
	NewCourse->course.Max_stdn = stoi(my_getline_onlyNumber(3));
	if (std::to_string(NewCourse->course.Max_stdn) == "-1")
		return;

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
	NewCourse->course.startDate.day = stoi(my_getline_onlyNumber(2));
	if (std::to_string(NewCourse->course.startDate.day) == "-1")
		return;
	gotoXY(coordinate_x + width_small_box + 2 + 1, coordinate_y + 24 + 2);
	NewCourse->course.startDate.month = stoi(my_getline_onlyNumber(2));
	if (std::to_string(NewCourse->course.startDate.month) == "-1")
		return;
	gotoXY(coordinate_x + 2 * width_small_box + 3 + 2, coordinate_y + 24 + 2);
	NewCourse->course.startDate.year = stoi(my_getline_onlyNumber(4));
	if (std::to_string(NewCourse->course.startDate.year) == "-1")
		return;

	my_print(coordinate_x, coordinate_y + 28, LIGHT_AQUA, "Enter End date (dd mm yyy)");
	box(coordinate_x, coordinate_y + 28 + 1, width_small_box, height_box, LIGHT_AQUA);
	my_print(coordinate_x + width_small_box + 1, coordinate_y + 28 + 2, LIGHT_AQUA, "/");
	box(coordinate_x + width_small_box + 2, coordinate_y + 28 + 1, width_small_box, height_box, LIGHT_AQUA);
	my_print(coordinate_x + 2 * width_small_box + 3, coordinate_y + 28 + 2, LIGHT_AQUA, "/");
	box(coordinate_x + 2 * width_small_box + 4, coordinate_y + 28 + 1, width_small_box, height_box, LIGHT_AQUA);

	gotoXY(coordinate_x + 1, coordinate_y + 28 + 2);
	NewCourse->course.endDate.day = stoi(my_getline_onlyNumber(2));
	if (std::to_string(NewCourse->course.endDate.day) == "-1")
		return;
	gotoXY(coordinate_x + width_small_box + 2 + 1, coordinate_y + 28 + 2);
	NewCourse->course.endDate.month = stoi(my_getline_onlyNumber(2));
	if (std::to_string(NewCourse->course.endDate.month) == "-1")
		return;
	gotoXY(coordinate_x + 2 * width_small_box + 3 + 2, coordinate_y + 28 + 2);
	NewCourse->course.endDate.year = stoi(my_getline_onlyNumber(4));
	if (std::to_string(NewCourse->course.endDate.year) == "-1")
		return;

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

void UpdateCourseInfo_from_current_time(STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE*& head) {
	system("cls");
	CR_NODE* cur = head;
	int x_tmp = 60;
	int y_tmp = 10;
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
			my_print(coordinate_x + 2 * width_box + distance + 5 + width_small_box + 1, coordinate_y + 8 * height_box + 1, LIGHT_AQUA, "/");
			box(coordinate_x + 2 * width_box + distance + 5 + width_small_box + 2, coordinate_y + 8 * height_box, width_small_box, height_box, LIGHT_AQUA);
			my_print(coordinate_x + 2 * width_box + distance + 5 + 2 * width_small_box + 3, coordinate_y + 8 * height_box + 1, LIGHT_AQUA, "/");
			box(coordinate_x + 2 * width_box + distance + 5 + 2 * width_small_box + 4, coordinate_y + 8 * height_box, width_small_box, height_box, LIGHT_AQUA);

			gotoXY(coordinate_x + 2 * width_box + distance + 5 + 1, coordinate_y + 8 * height_box + 1);
			UpNode->course.endDate.day = stoi(my_getline_onlyNumber(2));

			gotoXY(coordinate_x + 2 * width_box + distance + 5 + width_small_box + 2 + 1, coordinate_y + 8 * height_box + 1);
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

void DeleteCourse_from_current_time(STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE*& head) {
	system("cls");
	CR_NODE* cur = head;

	int coordinate_x = 60;
	int coordinate_y = 10;
	int width_box = 30;
	int height_box = 2;

	std::string DelID;
	my_print(coordinate_x, coordinate_y, LIGHT_AQUA, "Enter Course ID You Want To Delete:");
Here_enter_y3:
	box(coordinate_x, coordinate_y + 1, width_box, height_box, LIGHT_AQUA);
	gotoXY(coordinate_x + 1, coordinate_y + 1 + 1);
	DelID = my_getline(width_box - 1);
	CR_NODE* DelNode = checkExistOfCourseRecord(head, DelID);
	if (DelNode) {
		CR_NODE* tmp = DelNode;
		(DelNode->next)->prev = tmp->prev;
		if (!DelNode->prev) {
			head = DelNode->next;
			DelNode = nullptr;
			delete tmp;
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


void changePassWordOfStaffAccount(STFF_NODE*& staff, STFF_NODE*& loggedinStaff) {
	std::string oldPass;
	std::string newPass;
	std::string newPassAgain;
	do {
		std::system("cls");
		std::cout << "Enter your old password: ";
		std::getline(std::cin, oldPass);
		if (loggedinStaff->staff.Password != oldPass) {
			std::cout << "Your old password has been entered incorrectly. Please, enter again.\n\n";
			std::system("pause");
			continue;
		}
		else {
			std::cout << "Enter your new password: ";
			std::getline(std::cin, newPass);
			std::cout << "Enter your new password again: ";
			std::getline(std::cin, newPassAgain);
			if (newPass != newPassAgain) {
				std::cout << "Confirmation password is not correct. Please, enter again.\n\n";
				std::system("pause");
				continue;
			}
			loggedinStaff->staff.Password = newPass;
			Read_After_Update_Staffs(staff);
			std::cout << "Change password successfully.\n\n";
			std::system("pause");
			break;
		}
	} while (loggedinStaff->staff.Password != oldPass || newPass != newPassAgain);
}



//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@STUDENT@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


void printInformation_A_Student(STU_NODE* loggedinStudent) {
	std::string fullname = loggedinStudent->student.LName + " " + loggedinStudent->student.FName;
	std::string DoB = std::to_string(loggedinStudent->student.DoB.day / 10) + std::to_string(loggedinStudent->student.DoB.day % 10) + "/"
		+ std::to_string(loggedinStudent->student.DoB.month / 10) + std::to_string(loggedinStudent->student.DoB.month % 10) + "/"
		+ std::to_string(loggedinStudent->student.DoB.year);

	std::cout << std::setw(45) << std::right << "Student's information"
		<< "\n\t" << std::setfill('*') << std::setw(55) << "*" << std::setfill(' ')
		<< "\n\t" << std::setw(15) << std::left << "Full name : " << std::setw(40) << std::right << fullname
		<< "\n\t" << std::setw(15) << std::left << "Teacher ID: " << std::setw(40) << std::right << loggedinStudent->student.StudentID
		<< "\n\t" << std::setw(15) << std::left << "Gender: " << std::setw(40) << std::right << loggedinStudent->student.Gender
		<< "\n\t" << std::setw(15) << std::left << "Date of birth: " << std::setw(40) << std::right << DoB
		<< "\n\t" << std::setw(15) << std::left << "Class ID: " << std::setw(40) << std::right << loggedinStudent->student.Classes.ClassID
		<< "\n\t" << std::setw(15) << std::left << "Class name: " << std::setw(40) << std::right << loggedinStudent->student.Classes.name << "\n\n";
}

void changePasswordOfStudentAccount(STU_NODE*& student, STU_NODE*& loggedinStudent) {
	ShowCur(1);
	int width_tmp = 70;
	int height_tmp = 10;

	int width_box = 40;
	int height_box = 2;

	my_print(width_tmp, height_tmp, YELLOW, "Old password:");
	box(width_tmp, height_tmp + 1, width_box, height_box, YELLOW);

	my_print(width_tmp, height_tmp + 5, YELLOW, "New password:");
	box(width_tmp, height_tmp + 6, width_box, height_box, YELLOW);

	my_print(width_tmp, height_tmp + 10, YELLOW, "Verify:");
	box(width_tmp, height_tmp + 11, width_box, height_box, YELLOW);

	std::string old_password, new_password, new_password_again;

	gotoXY(width_tmp + 1, height_tmp + 2);
	old_password = my_getline(width_box - 1);

	gotoXY(width_tmp + 1, height_tmp + 7);
	new_password = my_getline(width_box - 1);

	gotoXY(width_tmp + 1, height_tmp + 12);
	new_password_again = my_getline(width_box - 1);

	if (loggedinStudent->student.Password != old_password) {
		my_print(width_tmp, height_tmp + 15, RED, "Your old password has been entered incorrectly.");
		gotoXY(width_tmp, height_tmp + 17);
		system("pause");
		return;
	}
	if (new_password != new_password_again) {
		my_print(width_tmp, height_tmp + 15, RED, "Confirmation password is not correct.");
		gotoXY(width_tmp, height_tmp + 17);
		system("pause");
		return;
	}
	loggedinStudent->student.Password = new_password;
	Read_After_Update_Students(student);
	my_print(width_tmp, height_tmp + 15, RED, "Change password successfully.");
	system("pause");
}

bool ViewSchedule(STU_COURSE_NODE* stu_course, STU_NODE* loggedinStudent, CR_NODE* course) {
	STU_COURSE_NODE* cur_stu_course = stu_course;
	CR_NODE* cur_course = course;
	int count = 0;

	std::system("cls");
	std::cout << "====================================================================YOUR SCHEDULE=========================================================================\n";
	int coordinate_x = 0;
	int coordinate_y = 3;

	int width_no = 5;
	int width_CourseID = 10;
	int width_courseName = 25;
	int width_teacherName = 16;
	int width_credits = 8;
	int width_registered = 10;
	int width_calendar = 20;


	int width = width_no + width_CourseID + width_courseName + width_teacherName + width_credits +
				width_registered + width_calendar + 5 * 7;

	gotoXY(coordinate_x, coordinate_y); std::cout << "+";
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y); std::cout << "-";
	}
	gotoXY(coordinate_x + width, coordinate_y); std::cout << "+\n";

	gotoXY(coordinate_x, coordinate_y + 1);
	std::cout << std::setw(5) << std::left << "|" << std::setw(width_no) << std::left << "No" << std::setw(5) << std::left << "|"
		<< std::setw(width_CourseID) << std::left << "Course ID" << std::setw(5) << std::left << "|"
		<< std::setw(width_courseName) << std::left << "Course name" << std::setw(5) << std::left << "|"
		<< std::setw(width_teacherName) << std::left << "Teacher name" << std::setw(5) << std::left << "|"
		<< std::setw(width_credits) << std::left << "Credits" << std::setw(5) << std::left << "|"
		<< std::setw(width_registered) << std::left << "Registered" << std::setw(5) << std::left << "|"
		<< std::setw(width_calendar) << std::left << "Calendar" << std::setw(5) << std::left << "|" << "\n";

	gotoXY(coordinate_x, coordinate_y + 2); std::cout << "+";
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y + 2); std::cout << "-";
	}
	gotoXY(coordinate_x + width, coordinate_y + 2); std::cout << "+\n";

	while (cur_stu_course) {
		ShowCur(1);
		if (cur_stu_course->stu_course.StuID == loggedinStudent->student.StudentID) {
			count++;
			std::string fullname = cur_course->course.LNameTeacher + " " + cur_course->course.FNameTeacher;
			std::string registered = std::to_string(cur_course->course.Cur_stdn) + "/" + std::to_string(cur_course->course.Max_stdn);
		    std::string calendar = ConvertStringWD(cur_course->course.dayOfWeek) + "-" + ConvertStringSS(cur_course->course.session);
			std::cout << std::setw(5) << std::left << "|" << std::setw(width_no) << std::left << count << std::setw(5) << std::left << "|"
				<< std::setw(width_CourseID) << std::left << cur_course->course.ID << std::setw(5) << std::left << "|"
				<< std::setw(width_courseName) << std::left << cur_course->course.CName << std::setw(5) << std::left << "|"
				<< std::setw(width_teacherName) << std::left << fullname << std::setw(5) << std::left << "|"
				<< std::setw(width_credits) << std::left << cur_course->course.Credits << std::setw(5) << std::left << "|"
				<< std::setw(width_registered) << std::left << registered << std::setw(5) << std::left << "|"
				<< std::setw(width_calendar) << std::left << calendar << "|\n";
		}
		cur_course = cur_course->next;
		cur_stu_course = cur_stu_course->next;
	}
	
/* 	std::cout << "====================================================================YOUR SCHEDULE=========================================================================\n\n";
	std::cout << "+" << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << "+";
	std::cout << std::setw(5) << std::left << "|" << std::setw(5) << std::left << "No" << std::setw(5) << std::left << "|"
		<< std::setw(10) << std::left << "Course ID" << std::setw(5) << std::left << "|"
		<< std::setw(30) << std::left << "Course name" << std::setw(5) << std::left << "|"
		<< std::setw(25) << std::left << "Teacher name" << std::setw(5) << std::left << "|"
		<< std::setw(10) << std::left << "Credits" << std::setw(5) << std::left << "|"
		<< std::setw(10) << std::left << "Registered" << std::setw(5) << std::left << "|"
		<< std::setw(20) << std::left << "Calendar" << std::endl;
	std::cout << "+" << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << "+";
	while (cur_stu_course) {
		if (cur_stu_course->stu_course.StuID == loggedinStudent->student.StudentID && cur_stu_course->stu_course.CouID == cur_course->course.ID) {

			std::string registered = std::to_string(cur_course->course.Cur_stdn) + "/" + std::to_string(cur_course->course.Max_stdn);
			std::string fullname = cur_course->course.LNameTeacher + " " + cur_course->course.FNameTeacher;

			std::cout << std::setw(5) << std::left << "|" << std::setw(5) << std::left << cur_course->course.No << std::setw(5) << std::left << "|"
				<< std::setw(10) << std::left << cur_course->course.ID << std::setw(5) << std::left << "|"
				<< std::setw(30) << std::left << cur_course->course.CName << std::setw(5) << std::left << "|"
				<< std::setw(25) << std::left << fullname << std::setw(5) << std::left << "|"
				<< std::setw(10) << std::left << cur_course->course.Credits << std::setw(5) << std::left << "|"
				<< std::setw(10) << std::left << registered << std::setw(5) << std::left << "|"
				<< ConvertStringWD(cur_course->course.dayOfWeek) << "-" << ConvertStringSS(cur_course->course.session) << std::endl;
			count++;
			cur_course = cur_course->next;
			cur_stu_course = cur_stu_course->next;
		}
		else if (cur_stu_course->stu_course.StuID == loggedinStudent->student.StudentID && cur_stu_course->stu_course.CouID != cur_course->course.ID) {
			if (cur_course->next)
				cur_course = cur_course->next;
		}
		else {
			cur_course = cur_course->next;
			cur_stu_course = cur_stu_course->next;
		}
	}
	std::cout << "+" << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << "+"; */
	
	if (count == 0) {
		std::cout << "\nYou haven't registered any course!\n" << std::endl;
		return 0;
	}
	std::system("pause");
	return 1;
}

void RegisterForCourse(STU_NODE* student, STFF_NODE* teacher, CR_NODE* course, STU_COURSE_NODE* stu_course, STU_NODE* loggedinStudent) { //new
AGAIN:
	std::system("cls");
	updateCur_stdnInCourse(course, stu_course);

	int coordinate_x = 20;
	int coordinate_y = 27;
	int width_box = 30;
	int height_box = 2;

	int check = 0;
	std::string CourseID;
	CR_NODE* cur_course = course;
	do {
		std::system("cls");
		viewListOfCourses(course);

		ShowCur(1);
		my_print(coordinate_x, coordinate_y, GREEN, "Enter Course ID which you want to register: ");
		box(coordinate_x + 43, coordinate_y - 1, width_box, height_box, BLUE);
		gotoXY(coordinate_x + 44, coordinate_y);
		CourseID = my_getline(width_box - 1);

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
			system("cls");
			my_print(coordinate_x, coordinate_y, GREEN, "Your Course ID doesn't exist. Please enter again.");
			my_print(coordinate_x, coordinate_y + 1, GREEN, "Search for Course again? (y/n)");
			gotoXY(coordinate_x + 31, coordinate_y + 1);
			char ans;
			std::cin >> ans;
			if (ans == 'y' || ans == 'Y') {
				goto AGAIN;
			}
			else if (ans == 'n' || ans == 'N') {
				check = 2;
				return;
			}
		}
	} while (check == 0);

	bool check1 = false;
	bool check2 = false;
	bool check3 = false;
	bool check4 = false;
	//điều kiện để chấp nhận đăng ký khóa học
	//1. lớp còn trống slot
	//2. không đăng ký quá 5 môn học
	//3. không bị trùng lịch học
	//4. môn đó chưa được đăng ký

	//1
	if (cur_course->course.Cur_stdn < cur_course->course.Max_stdn) {
		check1 = true;
	}
	else {
		system("cls");
		my_print(coordinate_x, coordinate_y, GREEN, "This course is full.");
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
	else {
		system("cls");
		my_print(coordinate_x, coordinate_y, GREEN, "You have registered 5 courses, cannot register more.");
	}
	//3
	cur_stu_course = stu_course;
	cur_course = course;

	while (cur_course) {
		if (cur_course->course.ID == CourseID)
			break;
		cur_course = cur_course->next;
	}

	while (cur_stu_course) {
		if (cur_stu_course->stu_course.StuID == loggedinStudent->student.StudentID) {
			if (cur_stu_course->stu_course.session == ConvertStringSS(cur_course->course.session) && cur_stu_course->stu_course.weekday == ConvertStringWD(cur_course->course.dayOfWeek)) {
				system("cls");
				my_print(coordinate_x, coordinate_y, GREEN, "Conflict between your calendar and the course's calendar.");
				break;
			}
		}
		cur_stu_course = cur_stu_course->next;
	}
	if (cur_stu_course == nullptr)
		check3 = true;
	//4
	cur_stu_course = stu_course;

	while (cur_stu_course) {
		if (cur_stu_course->stu_course.StuID == loggedinStudent->student.StudentID && cur_stu_course->stu_course.CouID == CourseID) {
			system("cls");
			my_print(coordinate_x, coordinate_y, GREEN, "Your have already registed to this course.");
			break;
		}
		else
			cur_stu_course = cur_stu_course->next;
	}
	if (cur_stu_course == nullptr)
		check4 = true;

	// update

	if (check1 == check2 == check3 == check4 == true) {
		system("cls");
		char lastcheck;
		my_print(coordinate_x, coordinate_y, GREEN, "Are you sure you want to register to this course? (y/n):");
		std::cin >> lastcheck;
		if (lastcheck == 'y' || lastcheck == 'Y') {
			cur_stu_course = stu_course;
			while (cur_stu_course->next)
				cur_stu_course = cur_stu_course->next;

			CR_NODE* cr_tmp = new CR_NODE;
			cr_tmp = course;

			while (cr_tmp) {
				if (cr_tmp->course.ID == CourseID)
					break;
				else
					cr_tmp = cr_tmp->next;
			}

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

			cur_stu_course->next = stu_cr_tmp;
			stu_cr_tmp->next = nullptr;

			Read_After_Update_Student_Course(student, course, teacher, stu_course);

			system("cls");
			my_print(coordinate_x, coordinate_y, GREEN, "Register successfully!");
			gotoXY(coordinate_x, coordinate_y + 1);
		}
	}
	std::system("pause");
}

void DeleteRegisteredCourse(STU_COURSE_NODE*& stu_course, STU_NODE* loggedinStudent, CR_NODE* course, STU_NODE* student, STFF_NODE* teacher) {
	std::system("cls");
	char check;
	std::string courseID;
	STU_COURSE_NODE* cur_stu_node = stu_course;
	CR_NODE* cur_course = course;

	if (!ViewSchedule(stu_course, loggedinStudent, course)) {
		system("pause");
		return;
	}

	ShowCur(1);
	int width_tmp1 = 55;
	int height_tmp1 = 25;
	int width_box1 = 45;
	int height_box1 = 2;

	my_print(width_tmp1, height_tmp1, YELLOW, "Enter the ID of the course you want to delete: ");
	box(width_tmp1, height_tmp1 + 1, width_box1, height_box1, YELLOW);

	gotoXY(width_tmp1 + 1, height_tmp1 + 2);
	courseID = my_getline(width_box1 - 1);

	while (cur_stu_node) {
		if (cur_stu_node->stu_course.CouID == courseID && cur_stu_node->stu_course.StuID == loggedinStudent->student.StudentID) {
			my_print(width_tmp1, height_tmp1 + 5, RED, "Are you sure you want to change to cancel this course? (y/n): ");
			std::cin >> check;
			gotoXY(width_tmp1, height_tmp1 + 17);
			std::cin.ignore();
			if (check == 'y' || check == 'Y') {
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
				Read_After_Update_Student_Course(student, course, teacher, stu_course);
				std::system("cls");
				my_print(width_tmp1, height_tmp1 + 5, RED, "Delete successfully!");
				std::system("pause");
				return;
			}
			else
				system("cls");
				return;
		}
		else
			cur_stu_node = cur_stu_node->next;
	}
	my_print(width_tmp1, height_tmp1 + 5, RED, "This course is not registered");
	std::system("pause");
	return;
}


//Update student
void UpdateStudentInfo(STU_NODE*& student, STU_NODE*& loggedinStudent) {
AGAIN:
	system("cls");
	
	int x_boxStudent = 5;
	int y_boxStudent = 2;
	int width_boxStudent = 42;
	int height_boxStudent = 2;

	char check;
	std::string tmp;
	int tmp_width = 60;
	int box_width = 32;

	printInformation_A_Student(student);

	std::string option_1[] = { "1. Update your gender.",
			"2. Update your date of birth.",
			"3. Update your social ID.",
			"0. Come back." };

	int x_boxOption1 = x_boxStudent + width_boxStudent + 2;
	int y_boxOption1 = y_boxStudent;
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

		my_print(width_tmp1, height_tmp1, YELLOW, "Enter the gender you want to update to: ");
		box(width_tmp1, height_tmp1 + 1, width_box1, height_box1, YELLOW);

		gotoXY(width_tmp1 + 1, height_tmp1 + 2);
		tmp = my_getline(width_box1 - 1);

		my_print(width_tmp1, height_tmp1 + 5, RED, "Are you sure you want to change to this gender? (y/n): ");
		std::cin >> check;
		gotoXY(width_tmp1, height_tmp1 + 17);
		std::cin.ignore();
		if (check == 'y' || check == 'Y') {
			loggedinStudent->student.Gender = tmp;
			Read_After_Update_Students(student);
			system("cls");
		}
		else
			system("cls");
		goto AGAIN;
	}
	else if (choose == 2) {
		system("cls");
		ShowCur(1);
		int width_tmp1 = 50;
		int height_tmp1 = 10;
		int width_box1 = 40;
		int height_box1 = 2;

		my_print(width_tmp1, height_tmp1, YELLOW, "Enter date of birth which you want to update (dd/mm/yyyy): ");
		box(width_tmp1, height_tmp1 + 1, width_box1, height_box1, YELLOW);

		int day, month, year;
		gotoXY(width_tmp1 + 1, height_tmp1 + 2);
		std::cin >> day >> month >> year;

		my_print(width_tmp1, height_tmp1 + 5, RED, "Are you sure you want to change to this date? (y/n): ");
		std::cin >> check;
		gotoXY(width_tmp1, height_tmp1 + 17);
		std::cin.ignore();
		if (check == 'y' || check == 'Y') {
			loggedinStudent->student.DoB.day = day;
			loggedinStudent->student.DoB.month = month;
			loggedinStudent->student.DoB.year = year;
			Read_After_Update_Students(student);
			system("cls");
		}
		else
			system("cls");
		goto AGAIN;
	}
	else if (choose == 3) {
		system("cls");
		ShowCur(1);
		int width_tmp1 = 50;
		int height_tmp1 = 10;
		int width_box1 = 40;
		int height_box1 = 2;

		my_print(width_tmp1, height_tmp1, YELLOW, "Enter social ID which you want to update: ");
		box(width_tmp1, height_tmp1 + 1, width_box1, height_box1, YELLOW);

		gotoXY(width_tmp1 + 1, height_tmp1 + 2);
		tmp = my_getline(width_box1 - 1);

		my_print(width_tmp1, height_tmp1 + 5, RED, "Are you sure you want to change to this ID? (y/n): ");
		std::cin >> check;
		gotoXY(width_tmp1, height_tmp1 + 17);
		std::cin.ignore();
		if (check == 'y' || check == 'Y') {
			loggedinStudent->student.SocialID = tmp;
			Read_After_Update_Students(student);
			system("cls");
		}
		else
			system("cls");
		goto AGAIN;
	}
	else if (choose == 4) {
		return;
	}
	else {
		std::cout << "Invalid selection, please enter again.\n\n";
		std::system("pause");
		UpdateStudentInfo(student, loggedinStudent);
	}
}

void UpdateTeacherInfor(std::string teacherID, STFF_NODE*& teacher) {
	STFF_NODE* cur = teacher;
	std::string tmp;
	int check = 0;
	std::system("cls");

	while (cur) {
		if (cur->staff.TeacherID == teacherID) {
			check = 1;
			break;
		}
		cur = cur->next;
	}

	if (check == 0) {
		std::cout << "Your ID is invalid, please type again" << std::endl;
		return;
	}

	printInformation_A_Staff(cur);
	std::cout << "\n\nWhat do you want to update? " << std::endl;

	int choice;
	std::cout << "\n\t1. Update gender."
		<< "\n\t2. Update date of birth."
		<< "\n\t3. Update social ID."
		<< "\n\t4. Update Faculty."
		<< "\n\t0. Come back.";
	std::cout << "\n\nEnter select the option you want to choose: ";
	std::cin >> choice;

	if (choice == 1) {
		std::cout << "\nEnter gender which you want to update: ";
		std::cin.ignore();
		std::getline(std::cin, tmp);
		std::cout << "Are you sure you want to change? (y/n): ";
		std::cin >> check;
		if (check == 'y' || check == 'Y') {
			cur->staff.Gender = tmp;
			Read_After_Update_Teachers(teacher);
		}
		UpdateTeacherInfor(teacherID, teacher);
	}
	else if (choice == 2) {
		std::cout << "\nEnter date of birth which you want to update (dd mm yyyy): ";
		int day, month, year;
		std::cin >> day >> month >> year;
		std::cout << "Are you sure you want to change? (y/n): ";
		std::cin >> check;
		if (check == 'y' || check == 'Y') {
			cur->staff.DoB.day = day;
			cur->staff.DoB.month = month;
			cur->staff.DoB.year = year;
			Read_After_Update_Teachers(teacher);
		}
		UpdateTeacherInfor(teacherID, teacher);
	}
	else if (choice == 3) {
		std::cout << "\nEnter social ID which you want to update: ";
		std::cin.ignore();
		std::getline(std::cin, tmp);
		std::cout << "Are you sure you want to change? (y/n): ";
		std::cin >> check;
		if (check == 'y' || check == 'Y') {
			cur->staff.SocialID = tmp;
			Read_After_Update_Teachers(teacher);
		}
		UpdateTeacherInfor(teacherID, teacher);
	}
	else if (choice == 4) {
		std::cout << "\nEnter your new faculty: ";
		std::cin.ignore();
		std::getline(std::cin, tmp);
		std::cout << "Are you sure you want to change? (y/n): ";
		std::cin >> check;
		if (check == 'y' || check == 'Y') {
			cur->staff.Faculty = tmp;
			Read_After_Update_Teachers(teacher);
		}
		UpdateTeacherInfor(teacherID, teacher);
	}
	else if (choice == 0) {
		return;
	}
	else {
		std::cout << "Invalid selection, please enter again.\n\n";
		std::system("pause");
		UpdateTeacherInfor(teacherID, teacher);
	}
}

void UpdateYourInfor(STFF_NODE* loggedinStaff, STFF_NODE*& teacher) {
	STFF_NODE* cur = teacher;
	char check;
	std::string tmp;

	std::system("cls");
	printInformation_A_Staff(loggedinStaff);


	while (cur) {
		if (cur->staff.TeacherID == loggedinStaff->staff.TeacherID)
			break;
		else
			cur = cur->next;
	}

	std::cout << "\n\nWhat do you want to update? " << std::endl;

	int choice;
	std::cout << "\n\t1. Update gender."
		<< "\n\t2. Update date of birth."
		<< "\n\t3. Update social ID."
		<< "\n\t4. Update Faculty."
		<< "\n\t0. Come back.";
	std::cout << "\n\nEnter select the option you want to choose: ";
	std::cin >> choice;

	if (choice == 1) {
		std::cout << "\nEnter gender which you want to update: ";
		std::cin.ignore();
		std::getline(std::cin, tmp);
		std::cout << "Are you sure you want to change? (y/n): ";
		std::cin >> check;
		if (check == 'y' || check == 'Y') {
			cur->staff.Gender = tmp;
			Read_After_Update_Teachers(teacher);
		}
		UpdateYourInfor(loggedinStaff, teacher);
	}
	else if (choice == 2) {
		std::cout << "\nEnter date of birth which you want to update (dd mm yyyy): ";
		int day, month, year;
		std::cin >> day >> month >> year;
		std::cout << "Are you sure you want to change? (y/n): ";
		std::cin >> check;
		if (check == 'y' || check == 'Y') {
			cur->staff.DoB.day = day;
			cur->staff.DoB.month = month;
			cur->staff.DoB.year = year;
			Read_After_Update_Teachers(teacher);
		}
		UpdateYourInfor(loggedinStaff, teacher);
	}
	else if (choice == 3) {
		std::cout << "\nEnter social ID which you want to update: ";
		std::cin.ignore();
		std::getline(std::cin, tmp);
		std::cout << "Are you sure you want to change? (y/n): ";
		std::cin >> check;
		if (check == 'y' || check == 'Y') {
			cur->staff.SocialID = tmp;
			Read_After_Update_Teachers(teacher);
		}
		UpdateYourInfor(loggedinStaff, teacher);
	}
	else if (choice == 4) {
		std::cout << "\nEnter your new faculty: ";
		std::cin.ignore();
		std::getline(std::cin, tmp);
		std::cout << "Are you sure you want to change? (y/n): ";
		std::cin >> check;
		if (check == 'y' || check == 'Y') {
			cur->staff.Faculty = tmp;
			Read_After_Update_Teachers(teacher);
		}
		UpdateYourInfor(loggedinStaff, teacher);
	}
	else if (choice == 0) {
		return;
	}
	else {
		std::cout << "Invalid selection, please enter again.\n\n";
		std::system("pause");
		UpdateYourInfor(loggedinStaff, teacher);
	}
}

void Create_newStaff(STFF_NODE* staff) {
	std::system("cls");
	STFF_NODE* NewStaff = new STFF_NODE;
	STFF_NODE* cur = staff;
	while (cur->next) {
		cur = cur->next;
	}
	//create new staff account

	if (!cur) {
		NewStaff->staff.No_Staff = 1;
	}
	else {
		int NewNo = cur->staff.No_Staff;
		NewNo++;
		NewStaff->staff.No_Staff = NewNo;
	}
	std::string NewLName;
	std::cout << "Enter The Staff's Last Name: ";
	std::getline(std::cin, NewLName);
	NewStaff->staff.LName = NewLName;
	std::string NewFName;
	std::cout << "Enter The Staff's First Name: ";
	std::getline(std::cin, NewFName);
	NewStaff->staff.FName = NewFName;
	std::string NewGender;
	std::cout << "Enter The Staff's Gender: ";
	std::getline(std::cin, NewGender);
	NewStaff->staff.Gender = NewGender;

	std::string NewSocialID;
	std::cout << "Enter Staff's Social ID: ";
	std::getline(std::cin, NewSocialID);
	NewStaff->staff.SocialID = NewSocialID;
	std::string NewID;
	std::cout << "Enter Staff's ID (This will be the login username): ";
	std::getline(std::cin, NewID);
	NewStaff->staff.TeacherID = NewID;
	std::string NewPass;
	std::cout << "Enter Staff's Password: ";
	std::getline(std::cin, NewPass);
	NewStaff->staff.Password = NewPass;

	std::string NewFaculty;
	std::cout << "Enter Staff's Faculty: ";
	std::getline(std::cin, NewFaculty);
	NewStaff->staff.Faculty = NewFaculty;

	std::cout << "Enter Staff's Date of Birth (Please seperate with spaces) (dd/mm/yyyy)";
	std::cin >> NewStaff->staff.DoB.day >> NewStaff->staff.DoB.month >> NewStaff->staff.DoB.year;

	//Add course at the end
	if (!cur) {
		cur = NewStaff;
		NewStaff->prev = nullptr;
	}
	else {
		cur->next = NewStaff;
		NewStaff->prev = cur;
	}

	std::system("cls");
	std::cout << "Added Staff Successfully\n";
	Read_After_Update_Staffs(staff);
	std::system("pause");
	return;
}

//Roke additional function
char GetRanking(float Grade) {
	if (Grade >= 90 && Grade <= 100)
		return 'A';
	else if (Grade >= 80 && Grade <= 89)
		return 'B';
	else if (Grade >= 70 && Grade <= 79)
		return 'C';
	else if (Grade >= 60 && Grade <= 69)
		return 'D';
	else if (Grade >= 0 && Grade <= 59)
		return 'F';
	else
		return 'E';
}

void ResultRegistration(STU_COURSE_NODE* stu_course, STU_NODE* loggedinStudent, CR_NODE* course) {
	std::system("cls");
	STU_COURSE_NODE* cur_stu_course = stu_course;
	CR_NODE* cur_course = course;
	int count = 0;

	std::system("cls");
	std::cout << "=================================================================YOUR COURSES RESULTS=======================================================================\n";
	int coordinate_x = 0;
	int coordinate_y = 3;

	int width_no = 5;
	int width_CourseID = 10;
	int width_courseName = 25;
	int width_teacherName = 16;
	int width_credits = 8;
	int width_mid = 8;
	int width_final = 8;
	int width_other = 8;
	int width_total = 8;
	int width_Ranking = 8;


	int width = width_no + width_CourseID + width_courseName + width_teacherName + width_credits
		+ width_mid + width_final + width_other + width_total + width_Ranking + 5 * 10;

	gotoXY(coordinate_x, coordinate_y); std::cout << "+";
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y); std::cout << "-";
	}
	gotoXY(coordinate_x + width, coordinate_y); std::cout << "+\n";

	gotoXY(coordinate_x, coordinate_y + 1);
	std::cout << std::setw(5) << std::left << "|" << std::setw(width_no) << std::left << "No" << std::setw(5) << std::left << "|"
		<< std::setw(width_CourseID) << std::left << "Course ID" << std::setw(5) << std::left << "|"
		<< std::setw(width_courseName) << std::left << "Course name" << std::setw(5) << std::left << "|"
		<< std::setw(width_teacherName) << std::left << "Teacher name" << std::setw(5) << std::left << "|"
		<< std::setw(width_credits) << std::left << "Credits" << std::setw(5) << std::left << "|"
		<< std::setw(width_mid) << std::left << "Midterm" << std::setw(5) << std::left << "|"
		<< std::setw(width_final) << std::left << "Final" << std::setw(5) << std::left << "|"
		<< std::setw(width_other) << std::left << "Other" << std::setw(5) << std::left << "|"
		<< std::setw(width_total) << std::left << "Total" << std::setw(5) << std::left << "|"
		<< std::setw(width_Ranking) << std::left << "Ranking" << std::setw(5) << std::left << "|" << "\n";

	gotoXY(coordinate_x, coordinate_y + 2); std::cout << "+";
	for (int i = coordinate_x + 1; i < coordinate_x + width; i++) {
		gotoXY(i, coordinate_y + 2); std::cout << "-";
	}
	gotoXY(coordinate_x + width, coordinate_y + 2); std::cout << "+\n";

	while (cur_stu_course) {
		ShowCur(1);
		if (cur_stu_course->stu_course.StuID == loggedinStudent->student.StudentID) {
			count++;
			std::string fullname = cur_course->course.LNameTeacher + " " + cur_course->course.FNameTeacher;
			std::cout << std::setw(5) << std::left << "|" << std::setw(width_no) << std::left << count << std::setw(5) << std::left << "|"
				<< std::setw(width_CourseID) << std::left << cur_course->course.ID << std::setw(5) << std::left << "|"
				<< std::setw(width_courseName) << std::left << cur_course->course.CName << std::setw(5) << std::left << "|"
				<< std::setw(width_teacherName) << std::left << fullname << std::setw(5) << std::left << "|"
				<< std::setw(width_credits) << std::left << cur_course->course.Credits << std::setw(5) << std::left << "|"
				<< std::setw(width_mid) << std::left << cur_stu_course->stu_course.midterm << std::setw(5) << std::left << "|"
				<< std::setw(width_final) << std::left << cur_stu_course->stu_course.final << std::setw(5) << std::left << "|"
				<< std::setw(width_other) << std::left << cur_stu_course->stu_course.other << std::setw(5) << std::left << "|"
				<< std::setw(width_total) << std::left << cur_stu_course->stu_course.total << std::setw(5) << std::left << "|"
				<< std::setw(width_Ranking) << std::left << GetRanking(cur_stu_course->stu_course.total) << std::setw(5) << std::left << "|" << std::endl;
		}
		cur_course = cur_course->next;
		cur_stu_course = cur_stu_course->next;
	}
		
/* 	std::cout << "+" << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << "+";
	std::cout << std::setw(3) << std::left << "|" << std::setw(5) << std::left << "No" << std::setw(5) << std::left << "|"
		<< std::setw(10) << std::left << "Course ID" << std::setw(5) << std::left << "|"
		<< std::setw(25) << std::left << "Course name" << std::setw(5) << std::left << "|"
		<< std::setw(16) << std::left << "Teacher name" << std::setw(5) << std::left << "|"
		<< std::setw(8) << std::left << "Credits" << std::setw(5) << std::left << "|"
		<< std::setw(8) << std::left << "Midterm" << std::setw(5) << std::left << "|"
		<< std::setw(8) << std::left << "Final" << std::setw(5) << std::left << "|"
		<< std::setw(8) << std::left << "Other" << std::setw(5) << std::left << "|"
		<< std::setw(8) << std::left << "TOTAL" << std::setw(5) << std::left << "|"
		<< std::setw(8) << std::left << "RANKING" << std::setw(6) << std::left << "|" << "\n";
	std::cout << "+" << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << "+";
	
	while (cur_stu_course) {
		if (cur_stu_course->stu_course.StuID == loggedinStudent->student.StudentID) {
			count++;
			std::string fullname = cur_course->course.LNameTeacher + " " + cur_course->course.FNameTeacher;
			std::cout << std::setw(3) << std::left << "|" << std::setw(5) << std::left << count << std::setw(5) << std::left << "|"
				<< std::setw(10) << std::left << cur_course->course.ID << std::setw(5) << std::left << "|"
				<< std::setw(25) << std::left << cur_course->course.CName << std::setw(5) << std::left << "|"
				<< std::setw(16) << std::left << fullname << std::setw(5) << std::left << "|"
				<< std::setw(8) << std::left << cur_course->course.Credits << std::setw(5) << std::left << "|"
				<< std::setw(8) << std::left << cur_stu_course->stu_course.midterm << std::setw(5) << std::left << "|"
				<< std::setw(8) << std::left << cur_stu_course->stu_course.final << std::setw(5) << std::left << "|"
				<< std::setw(8) << std::left << cur_stu_course->stu_course.other << std::setw(5) << std::left << "|"
				<< std::setw(8) << std::left << cur_stu_course->stu_course.total << std::setw(5) << std::left << "|"
				<< std::setw(8) << std::left << GetRanking(cur_stu_course->stu_course.total) << std::setw(6) << std::left << "|" << std::endl;
		}
		cur_course = cur_course->next;
		cur_stu_course = cur_stu_course->next;
	}
	std::cout << "+" << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << "+"; */
	if (count == 0) {
		std::cout << "You haven't registered any course " << std::endl;
	}
	std::system("pause");
	return;
}