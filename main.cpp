
#include "baseStructure.h"
#include "getDataAndSynch.h"
#include "myGraphicsLib.h"
#include "staff.h"
#include "student.h"
#include "deleteDLL.h"

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_AQUA 11
#define LIGHT_RED 12
#define LIGHT_PURPLE 13
#define LIGHT_YELLOW 14
#define BRIGHT_WHITE 15

int main()
{
	resizeConsole(1200, 600);

	std::ifstream input;
	STFF_NODE* staff = nullptr;
	getDataStaff_csv(input, staff);
	STFF_NODE* loggedinStaff = new STFF_NODE;

	std::ifstream input_T;
	STFF_NODE* teacher = nullptr;
	getDataTeacher_csv(input_T, teacher);

	//STAFF ACCOUNT TO TEST RUN: 
	//USER:   33383147
	//PASSWORD:    123456

	//STUDENT ACCOUNT TO TEST RUN: 
	//USER:   22240001
	//PASSWORD:    678910

	std::ifstream input_S;
	STU_NODE* student = nullptr;
	getDataStudents_csv(input_S, student);
	STU_NODE* loggedinStudent = new STU_NODE;

	std::ifstream input_STU_CR;
	STU_COURSE_NODE* stu_course = nullptr;
	Get_Data_StudentCourse_csv(input_STU_CR, stu_course);

	std::ifstream input_CR;
	CR_NODE* course = nullptr;
	getDataCourse_csv(input_CR, course);

	update_cur_stdn_in_course(course, stu_course);

	CLASS_NODE* listclass = new CLASS_NODE;
	update_list_of_classes(listclass, student);

	//tach_ra_tung_file_class(student, listclass);

	while (69) {
		int check_T, check_S;
		do {
			std::system("cls");

			std::string user, pass;
			int tmp_width = 60;
			int box_width = 32;

			my_print(tmp_width, 1, LIGHT_YELLOW, "UNIVERSITY OF NATURAL SCIENCE");
			my_print(tmp_width + 7, 2, LIGHT_YELLOW, "HO CHI MINH CITY");

			my_print(tmp_width + 4, 5, LIGHT_YELLOW, "HCMUS Portal - Log in");

			my_print(tmp_width - 2, 7, LIGHT_YELLOW, "User name: ");
			box(tmp_width - 2, 8, box_width, 2, BRIGHT_WHITE);

			my_print(tmp_width - 2, 11, LIGHT_YELLOW, "Password: ");
			box(tmp_width - 2, 12, box_width, 2, BRIGHT_WHITE);

			ShowCur(1);

			gotoXY(tmp_width - 1, 9);
			//user = my_getline(box_width - 1);

			gotoXY(tmp_width - 1, 13);
			//pass = my_getline(box_width - 1);

			 user = "33383147";
			pass = "123456"; 

			/* user = "22240001";
			pass = "678910";  */

			check_T = check_exist_of_staff_account(staff, user, pass, loggedinStaff);
			check_S = check_exist_of_student_account(student, user, pass, loggedinStudent);

			if (check_T == 1 || check_S == 1) {
				continue;
			}
			if (check_T == -1 || check_S == -1) {
				my_print(tmp_width - 6, 16, RED, "Your password isn't correct. Please, enter again.");
				ShowCur(0);
				char c;
				c = _getch();
				ShowCur(1);
				continue;
			}
			if (check_T == 0 || check_S == 0) {
				my_print(tmp_width - 6, 16, RED, "Your account doesn't exist. Please, enter again.");
				ShowCur(0);
				char c;
				c = _getch();
				ShowCur(1);
			}
		} while (!(check_T == 1 || check_S == 1));

		//THE FUNCTIONS OF STAFF
		while (check_T == 1) {
			std::system("cls");
			std::string option[] = { "1.Create new.",
				"2.Enter information.",
				"3.Edit about course",
				"4.Look up.",
				"5.Change password.",
				"6.Update your info.",
				"0.Log out.",
				"-1.Exit." };
			int x_boxStaff = 5;
			int y_boxStaff = 4;
			int width_boxStaff = 22;
			int height_boxStaff = 3;
			int amount = sizeof(option) / sizeof(option[0]);
			int choose_staff;

			user_guide(x_boxStaff, y_boxStaff + 26);
			print_infor_staff(loggedinStaff->staff, x_boxStaff, y_boxStaff-3);

			choose_staff = menu(x_boxStaff, y_boxStaff, width_boxStaff, height_boxStaff, amount, option, WHITE, LIGHT_YELLOW, LIGHT_GREEN);

			//printInformation_A_Staff(loggedinStaff);

			if (choose_staff == 1) { //Create new
				while (1) {
					std::system("cls");
					menu_Staff(x_boxStaff, y_boxStaff, width_boxStaff, height_boxStaff, amount, option, WHITE, LIGHT_YELLOW, LIGHT_GREEN, choose_staff);

					std::string option_1[] = {
						"1.Create a new school year.",
						"2.Create semester.",
						"3.Create a new class.",
						"4.Create a new staff's account.",
						"0.Come back."
					};
					int x_boxOption1 = x_boxStaff + width_boxStaff + 2;
					int y_boxOption1 = y_boxStaff;
					int width_boxOption1 = 50;
					int height_boxOption1 = 3;
					int amount_option1 = sizeof(option_1) / sizeof(option_1[0]);
					int choose;

					user_guide(x_boxStaff, y_boxStaff + 26);
					print_infor_staff(loggedinStaff->staff, x_boxStaff, y_boxStaff - 3);
					choose = menu(x_boxOption1, y_boxOption1, width_boxOption1, height_boxOption1, amount_option1, option_1, WHITE, LIGHT_YELLOW, LIGHT_GREEN);

					if (choose == 1) {
						create_a_new_school_year();
					}
					else if (choose == 2) {
						create_semester();
					}
					else if (choose == 3) {
						create_a_new_class(listclass);
					}
					else if (choose == 4) {
						Create_newStaff(staff);
					}
					else if (choose == 0 + 5) {
						break;
					}
				}
			}
			else if (choose_staff == 2) { //Enter information
				while (1) {
					std::system("cls");

					user_guide(x_boxStaff, y_boxStaff + 26);
					print_infor_staff(loggedinStaff->staff, x_boxStaff, y_boxStaff - 3);
					menu_Staff(x_boxStaff, y_boxStaff, width_boxStaff, height_boxStaff, amount, option, WHITE, LIGHT_YELLOW, LIGHT_GREEN, choose_staff);
					std::string option_2[] = { "1.Add new 1st year students to 1st year classes.",
						"2.Create a course registration session.",
						"3.Import CSV for Batch Student Addition.",
						"4.Change information of a teacher.",
						"0.Come back." };
					int x_boxOption2 = x_boxStaff + width_boxStaff + 2;
					int y_boxOption2 = y_boxStaff;
					int width_boxOption2 = 50;
					int height_boxOption2 = 3;
					int amount_option2 = sizeof(option_2) / sizeof(option_2[0]);
					int choose;
					choose = menu(x_boxOption2, y_boxOption2, width_boxOption2, height_boxOption2, amount_option2, option_2, WHITE, LIGHT_YELLOW, LIGHT_GREEN);

					if (choose == 1) { //Add new 1st year students to 1st year classes
						add_new_first_year_student(student, listclass);
					}
					else if (choose == 2) { //Registration
						set_time_course_regis();
					}
					else if (choose == 3) { 
						import_students_from_file(student, listclass);
					}
					else if (choose == 4) {
						update_information_of_teacher(teacher);
					}
					else if (choose == 0 +5) { //COME BACK
						break;
					}
				}
			}
			else if (choose_staff == 3) { //Edit about course
				while (1) {
					std::system("cls");

					user_guide(x_boxStaff, y_boxStaff + 26);
					print_infor_staff(loggedinStaff->staff, x_boxStaff, y_boxStaff - 3);
					menu_Staff(x_boxStaff, y_boxStaff, width_boxStaff, height_boxStaff, amount, option, WHITE, LIGHT_YELLOW, LIGHT_GREEN, choose_staff);

					std::string option_3[] = { 
						"1.Add a new course.",
						"2.Add a student to the course.",
						"3.Remove a student from the course.",
						"4.Delete a course.",
						"5.Update course information.",
						"6.Upload CSV file with enrolled students' list.",
						"7.Export course students to CSV.",
						"8.Update a student's result.",
						"9.Export course scoreboard to enter scores.",
						"0.Come back." };
					int x_boxOption3 = x_boxStaff + width_boxStaff + 2;
					int y_boxOption3 = y_boxStaff;
					int width_boxOption3 = 50;
					int height_boxOption3 = 3;
					int amount_option3 = sizeof(option_3) / sizeof(option_3[0]);
					int choose;
					choose = menu(x_boxOption3, y_boxOption3, width_boxOption3, height_boxOption3, amount_option3, option_3, WHITE, LIGHT_YELLOW, LIGHT_GREEN);

					if (choose == 1) { 
						create_new_course(stu_course, teacher, course);
					}
					else if (choose == 2) {
						Add_Student_To_Course(stu_course, student,teacher, course);
					}
					else if (choose == 3) {
						Remove_Student_From_Course(stu_course, student, teacher, course);
					}
					else if (choose == 4) { 
						delete_course(stu_course, teacher, course);
					}
					else if (choose == 5) { 
						update_course_information(stu_course, teacher, course);
					}
					else if (choose == 6) { 
						//"6.Upload CSV file with enrolled students' list.",
						system("cls");
						std::string course_id, filename;

						my_print(5, 5, YELLOW, "What is the ID of the course you want to update?\n");
						box(5, 6, 10, 2, GREEN);
						gotoXY(6, 7);
						course_id = my_getline(10);
						if (course_id == "-1")
							break;

						my_print(5, 10, YELLOW, "What is the name of your csv file?\n");
						box(5, 11, 30, 2, GREEN);
						gotoXY(6, 12);
						filename = my_getline(30);
						if (filename == "-1")
							break;

						Update_from_enrolled_students_file(stu_course, course_id, filename, course, student);
					}
					else if (choose == 7) { 
						//"7.Export course students to CSV.",
					}
					else if (choose == 8) {
						update_mark_information(student, stu_course, teacher, course);
					}
					else if (choose == 9) { 
						export_scoreboard(stu_course, course, student);
					}
					else if (choose == 0 + 10) {
						break;
					}
				}
			}
			else if (choose_staff == 4) { //Look up
				while (1) {
					std::system("cls");

					user_guide(x_boxStaff, y_boxStaff + 26);
					print_infor_staff(loggedinStaff->staff, x_boxStaff, y_boxStaff - 3);
					menu_Staff(x_boxStaff, y_boxStaff, width_boxStaff, height_boxStaff, amount, option, WHITE, LIGHT_YELLOW, LIGHT_GREEN, choose_staff);

					std::string option_4[] = { "1.List of classes.",
						"2.List of students in class.",
						"3.List of courses.",
						"4.List of students in a course.",
						"5.View a scoreboard in a course.",
						"6.View a scoreboard in class.",
						"0.Come back." };
					int x_boxOption4 = x_boxStaff + width_boxStaff + 2;
					int y_boxOption4 = y_boxStaff;
					int width_boxOption4 = 75;
					int height_boxOption4 = 3;
					int amount_option4 = sizeof(option_4) / sizeof(option_4[0]);
					int choose;
					choose = menu(x_boxOption4, y_boxOption4, width_boxOption4, height_boxOption4, amount_option4, option_4, WHITE, LIGHT_YELLOW, LIGHT_GREEN);

					if (choose == 1) { //List of classes
						view_list_of_classes(listclass, student);
					}
					else if (choose == 2) { //List of students in class
						view_list_students_of_class(student, listclass);
					}
					else if (choose == 3) { //List of courses
						view_list_of_courses(course);
					}
					else if (choose == 4) { //List of students in a course
						view_list_students_of_course(stu_course, student, course);
					}
					else if (choose == 5) { //View a scoreboard in a course
						view_scoreboard_in_course(course, stu_course, student);
					}
					else if (choose == 6) { //View a scoreboard in class
						view_scoreboard_in_class(stu_course, student, listclass);
					}
					else if (choose == 0 + 7) {
						break;
					}
				}
			}
			else if (choose_staff == 5) {
				change_password_of_staff_account(loggedinStaff, staff);
			}
			else if (choose_staff == 6) {
				update_your_information(loggedinStaff, teacher, staff);
					}
			else if (choose_staff == 0 + 7) { // ++++++++++++++++++++++++++LOG OUT++++++++++++++++++++++++++
				break;
			}
			else if (choose_staff == -1 + 9) { // ++++++++++++++++++++++++++++EXIT++++++++++++++++++++++++++++
				std::system("cls");
				std::cout << "****************************THANK YOU FOR USING!********************************";
				return 0;
			}
		}

		//THE FUNCTIONS OF STUDENT
		while (check_S == 1) {
			std::system("cls");
			std::string option[] = { "1. Change password.",
						"2. Update your personal information.",
						"3. Register for the course.",
						"4. The result of register for the course.",
						"5. Delete the course which registered.",
						"6. View your scoreboard.",
						"0. Log out.",
						"-1. Exit." };

			int x_boxStudent = 5;
			int y_boxStudent = 2;
			int width_boxStudent = 42;
			int height_boxStudent = 3;
			int amount = sizeof(option) / sizeof(option[0]);
			int choose;
			choose = menu(x_boxStudent, y_boxStudent, width_boxStudent, height_boxStudent, amount, option, WHITE, LIGHT_YELLOW, LIGHT_GREEN);

			if (choose == 1) {
				change_password_of_student_account(student, loggedinStudent);
			}
			else if (choose == 2) {
				update_student_information(student, loggedinStudent);
			}
			else if (choose == 3) {
				register_for_course(student, teacher, course, stu_course, loggedinStudent);
			}
			else if (choose == 4) {
				result_registration(stu_course, loggedinStudent);
			}
			else if (choose == 5) {
				delete_registered_course(stu_course, loggedinStudent, course, student, teacher);
			}
			else if (choose == 6) {
				view_academic_result(stu_course, loggedinStudent);
			}
			else if (choose == 0 + 7) {
				break;
			}
			else if (choose == -1 + 9) {
				std::system("cls");
				std::cout << "****************************THANK YOU FOR USING!********************************\n\n";

				delete_all_DLL(student, staff, teacher, course, stu_course, listclass);

				return 0;
			}
		}
	}
}


