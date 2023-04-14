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

std::string ConvertStringWD(WEEKDAY& wd) {
	if (wd == MON) return "MON";
	else if (wd == TUE) return "TUE";
	else if (wd == WED) return "WED";
	else if (wd == THU) return "THU";
	else if (wd == FRI) return "FRI";
	else return "SAT";
}

std::string ConvertStringSS(SESSION& ss) {
	if (ss == S1) return "S1(07:30)";
	else if (ss == S2) return "S2(09:30)";
	else if (ss == S3) return "S3(13:30)";
	else return "S4(15:30)";
}

//--------Main functions---------

void CreateNewCourse(STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE*& head) {
	system("cls");
	CR_NODE* NewCourse = new CR_NODE;
	CR_NODE* cur = head;
	viewListOfCourses(cur);
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
	std::cout << "Enter Schoolyear: ";
	std::getline(std::cin, NewSchoolyear);
	if (checkExistOfSchoolyear(NewSchoolyear)) {
		NewCourse->course.Schoolyear = NewSchoolyear;
	}
	else {
		std::cout << "Schoolyear does not exist yet!\n";
		std::cout << "\nPlease create new schoolyear first!";
		system("pause");
		return;
	}

	int NewSemester;
	std::cout << "Enter Semester: ";
	std::cin >> NewSemester;
	if (NewSemester > 0 && NewSemester <= 3) {
		NewCourse->course.Semester = NewSemester;
	}
	else {
		std::cout << "Semester must be 1 to 3!\n";
		system("pause");
		return;
	}
	std::cin.ignore();
	std::string NewCName;
	std::cout << "Enter New Course Name: ";
	std::getline(std::cin, NewCName);
	NewCourse->course.CName = NewCName;
	std::string NewID;
	std::cout << "Enter Course ID: ";
	std::getline(std::cin, NewID);
	NewCourse->course.ID = NewID;
	std::string LName;
	std::cout << "Enter Teacher's last name: ";
	std::getline(std::cin, LName);
	NewCourse->course.LNameTeacher = LName;
	std::string FName;
	std::cout << "Enter Teacher's first name: ";
	std::getline(std::cin, FName);
	NewCourse->course.FNameTeacher = FName;
	int NewCredits;
	std::cout << "Enter Credits: ";
	std::cin >> NewCredits;
	NewCourse->course.Credits = NewCredits;
	int NewMax_stdn;
	std::cout << "Enter Max Students: ";
	std::cin >> NewMax_stdn;
	NewCourse->course.Max_stdn = NewMax_stdn;
	NewCourse->course.Cur_stdn = 0; //default
	std::string NewSession;
	std::cout << "Enter Session(S1->S4): ";
	std::cin >> NewSession;
	NewCourse->course.session = ConvertEnumSS(NewSession);
	std::string NewWeekday;
	std::cout << "Enter Weekday(MON->SAT): ";
	std::cin >> NewWeekday;
	NewCourse->course.dayOfWeek = ConvertEnumWD(NewWeekday);
	std::cout << "Enter Start date (Please seperate with spaces) (dd mm yyy)";
	std::cin >> NewCourse->course.startDate.day >> NewCourse->course.startDate.month >> NewCourse->course.startDate.year;
	std::cout << "Enter End date (Please seperate with spaces) (dd mm yyy)";
	std::cin >> NewCourse->course.endDate.day >> NewCourse->course.endDate.month >> NewCourse->course.endDate.year;

	//Add course at the end
	if (!cur) {
		cur = NewCourse;
		NewCourse->prev = nullptr;
	}
	cur->next = NewCourse;
	NewCourse->prev = cur;

	system("cls");
	std::cout << "Added Course Successfully\n";
	Read_After_Update_Course(stu_course, teacher, head);
	system("pause");
	return;
}

void UpdateCourseInfo(STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE*& head) {
AGAIN:
	system("cls");
	CR_NODE* cur = head;
	viewListOfCourses(cur);
	std::cout << "Enter Course ID: ";
	std::string UpID;
	std::cin >> UpID;
	CR_NODE* UpNode = checkExistOfCourseRecord(head, UpID);
	if (UpNode) {
		system("cls");

		std::cout << "======================COURSE======================";
		std::cout << "\n\t1. Course ID.\n" //No changing schoolyear and semester
			<< "\t2. Course Name.\n"
			<< "\t3. Course Teacher name.\n"
			<< "\t4. Course Credits.\n"
			<< "\t5. Course Max Students.\n"
			<< "\t6. Course Weekday.\n"
			<< "\t7. Course Session.\n"
			<< "\t8. Course Start Date.\n"
			<< "\t9. Course End Date.\n";
		std::cout << "========================END========================\n\n";
		std::cout << "What would you like to update?: ";

		//system("pause");

		int choice;
		std::cin >> choice;
		switch (choice) {
		case 1: {
			std::cout << "Enter Course ID: ";
			std::cin.ignore();
			std::getline(std::cin, UpNode->course.ID);
		} break;
		case 2: {
			std::cout << "Enter Course Name: ";
			std::cin.ignore();
			std::getline(std::cin, UpNode->course.CName);
		} break;
		case 3: {
			std::cout << "Enter Course Teacher Last name: ";
			std::cin.ignore();
			std::getline(std::cin, UpNode->course.LNameTeacher);
			std::cout << "Enter Course Teacher First name: ";
			std::getline(std::cin, UpNode->course.LNameTeacher);
		} break;
		case 4: {
			std::cout << "Enter Course Credits: ";
			std::cin >> UpNode->course.Credits;
		} break;
		case 5: {
			std::cout << "Enter Course Max Students: ";
			std::cin >> UpNode->course.Max_stdn;
		} break;
		case 6: {
			std::cout << "Enter Course Weekday: ";
			std::string wd;
			std::cin >> wd;
			UpNode->course.dayOfWeek = ConvertEnumWD(wd);
		} break;
		case 7: {
			std::cout << "Enter Course Session: ";
			std::string ss;
			std::cin >> ss;
			UpNode->course.session = ConvertEnumSS(ss);
		} break;
		case 8: {
			std::cout << "Enter Start Date (Please seperate with spaces)";
			std::cin >> UpNode->course.startDate.day >> UpNode->course.startDate.month >> UpNode->course.startDate.year;
		} break;
		case 9: {
			std::cout << "Enter End date (Please seperate with spaces)";
			std::cin >> UpNode->course.endDate.day >> UpNode->course.endDate.month >> UpNode->course.endDate.year;
		} break;
		default: {
			std::cout << "Invalid selection, please enter again.\n\n";
		} break;
		}

		system("cls");
		std::cout << "Update Course Successfully\n";
		Read_After_Update_Course(stu_course, teacher, head);
		system("pause");
		return;
	}
	else {
		std::cout << "No Course Founded!";
		std::cout << "\nSearch for Course again? (y/n)";
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

void DeleteCourse(STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE*& head) {
AGAIN:
	system("cls");
	CR_NODE* cur = head;
	viewListOfCourses(cur);
	std::cout << "Enter Course ID You Want To Delete: ";
	std::string DelID;
	std::cin >> DelID;
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

		system("cls");
		std::cout << "Delete Course Successfully\n";
		Read_After_Update_Course(stu_course, teacher, *&head);
		system("pause");
		return;
	}
	else {
		std::cout << "No Course Founded!";
		std::cout << "\nSearch for Course again? (y/n)";
		//system("pause");
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
