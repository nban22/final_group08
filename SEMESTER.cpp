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