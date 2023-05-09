#include "header.h"
#include "baseStructure.h"
#include "getDataAndSynch.h"
#include "myGraphicsLib.h"
#include "staff.h"
#include "student.h"
//void import_students_from_file(CLASS_NODE*& listclass) {
//AGAIN:
//	system("cls");
//	int coordinate_x = 5;
//	int coordinate_y = 2;
//	int width_box = 42;
//	int height_box = 2;
//	
//	my_print(coordinate_x, coordinate_y -2, YELLOW*16 + BLACK, "Which method do you want to import:");
//
//	std::string option[] = { "1. Add to a new Class.",
//			"2. Add onto existing class.",
//			"0. Come back." };
//
//	
//	int amount_option = sizeof(option) / sizeof(option[0]);
//	int choose;
//	choose = menu(coordinate_x, coordinate_y, width_box, height_box, amount_option, option, WHITE, LIGHT_YELLOW, LIGHT_GREEN);
//
//	if (choose == 1) {
//		
//	HERE:
//		std::string ClassID, ClassName, SchoolYear;
//		std::cout << "Enter class ID: ";
//		std::getline(std::cin, ClassID);
//		std::cout << "Enter class name: ";
//		std::getline(std::cin, ClassName);
//		std::cout << "Enter School Year: ";
//		std::getline(std::cin, SchoolYear);
//
//		bool check = 0;
//		CLASS_NODE* cur_listclass = listclass;
//		while (cur_listclass != nullptr) {
//			if (cur_listclass->listclass.ClassID == ClassID) {
//				check = 1;
//			}
//			cur_listclass = cur_listclass->next;
//		}
//		if (check == 1) {
//			std::cout << "The class ID you entered already exists! Please enter again!";
//			std::system("pause");
//			goto HERE;
//		}
//		cur_listclass = listclass;
//		while (cur_listclass->next != nullptr) {
//			cur_listclass = cur_listclass->next;
//		}
//		cur_listclass->next = new CLASS_NODE;
//		cur_listclass->next->listclass.ClassID = ClassID;
//		cur_listclass->next->listclass.name = ClassName;
//		cur_listclass->next->listclass.schoolYear = stoi(SchoolYear);
//		//E: CREATE A NEW CLASS
//
//		my_print(width_tmp1, height_tmp1, YELLOW, "Enter the import file (.csv): ");
//		box(width_tmp1, height_tmp1 + 1, width_box1, height_box1, YELLOW);
//
//		gotoXY(width_tmp1 + 1, height_tmp1 + 2);
//		std::string filename = my_getline(width_box1 - 1);
//		lay_vao_file_newclass(listclass, filename);
//
//		my_print(width_tmp1, height_tmp1 + 5, RED, "Are you sure you want commit? (y/n): ");
//		char ans;
//		std::cin >> ans;
//		gotoXY(width_tmp1, height_tmp1 + 17);
//		std::cin.ignore();
//		if (ans == 'y' || ans == 'Y') {
//			system("cls");
//			std::cout << "Add Student(s) to new Class successfully!";
//		}
//		else {
//			system("cls");
//			goto AGAIN;
//		}
//	}
//	else if (choose == 2) {
//		system("cls");
//		ShowCur(1);
//		int width_tmp1 = 50;
//		int height_tmp1 = 10;
//		int width_box1 = 40;
//		int height_box1 = 2;
//
//		my_print(width_tmp1, height_tmp1, YELLOW, "Enter the ClassID : ");
//		box(width_tmp1, height_tmp1 + 1, width_box1, height_box1, YELLOW);
//
//		gotoXY(width_tmp1 + 1, height_tmp1 + 2);
//		std::string NClassID = my_getline(width_box1 - 1);
//
//		if (check_exist_class_node_in_DLL(listclass, NClassID)) {
//			my_print(width_tmp1, height_tmp1, YELLOW, "Enter the import file (.csv): ");
//			box(width_tmp1, height_tmp1 + 1, width_box1, height_box1, YELLOW);
//
//			gotoXY(width_tmp1 + 1, height_tmp1 + 2);
//			std::string filename = my_getline(width_box1 - 1);
//			lay_vao_file_oldclass(listclass, filename);
//
//			my_print(width_tmp1, height_tmp1 + 5, RED, "Are you sure you want commit? (y/n): ");
//			std::cin >> check;
//			gotoXY(width_tmp1, height_tmp1 + 17);
//			std::cin.ignore();
//			if (check == 'y' || check == 'Y') {
//				system("cls");
//				std::cout << "Add Student(s) to new Class successfully!";
//			}
//			else {
//				system("cls");
//				goto AGAIN;
//			}
//		}
//		else {
//			my_print(width_tmp1, height_tmp1 + 5, RED, "The ClassID you entered does not exist!");
//			std::system("pause");
//			return;
//		}
//	}
//	else if (choose == 0 + 3) {
//		return;
//	}
//}

void EnterCourseScore(STU_COURSE_NODE*& SC, CR_NODE* C, STFF_NODE* loggedinStaff, int& check) {
	STU_COURSE_NODE* cur1 = SC;
	CR_NODE* cur2 = C;
	int choice;
	int count = 0;
	std::string courseID = "0";

	std::cout << "choose a course" << std::endl;
	while (cur2) {
		if (cur2->course.teacherID == loggedinStaff->staff.TeacherID) {
			std::cout << cur2->course.No << "  " << cur2->course.ID << "  " << cur2->course.CName << std::endl;
			count++;
		}
		cur2 = cur2->next;
	}
	if (count == 0) {
		std::cout << "you have not attend any course" << std::endl;
		check = 0;
		return;
	}
	std::cout << "your choice: ";
	std::cin >> choice;
	while (cur1) {
		if (cur1->stu_course.No == choice) {
			courseID = cur1->stu_course.CouID;
			break;
		}
		else
			cur1 = cur1->next;
	}

	if (courseID == "0") {
		std::cout << "Invalid selection, please enter again.\n\n";
		check = 0;
		system("pause");
		return;
	}

	cur1 = SC;
	std::cout << "\n\n";

	while (cur1) {
		if (courseID == cur1->stu_course.CouID) {
			std::cout << "\t\tEnter Score for student:" << std::endl;
			std::cout << cur1->stu_course.StudentName << "  " << cur1->stu_course.StuID << "  " << std::endl;
			std::cout << "Midterm mark: ";
			std::cin >> cur1->stu_course.midterm;
			std::cout << "Final mark: ";
			std::cin >> cur1->stu_course.final;
			std::cout << "Other mark: ";
			std::cin >> cur1->stu_course.other;
			cur1->stu_course.total = (cur1->stu_course.other + cur1->stu_course.midterm + 2 * cur1->stu_course.final) / 4;
			system("cls");
		}
		cur1 = cur1->next;
	}
	check = 1;
}