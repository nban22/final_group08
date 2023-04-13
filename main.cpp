
#include "header.h"
#include <conio.h>

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
	int count = 0;

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

	updateCur_stdnInCourse(course, stu_course);

	CLASS_NODE* listclass = new CLASS_NODE;
	updateListClass(listclass, student);

	while (69) {
		int check_T, check_S;
		do {
			std::system("cls");

			ShowCur(1);

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

			gotoXY(tmp_width - 1, 9);
			user = my_getline(box_width - 1);
			//user = "33383147";

			gotoXY(tmp_width - 1, 13);
			pass = my_getline(box_width - 1);
			//pass = "123456";

			check_T = checkExistOfStaffAccount(staff, user, pass, loggedinStaff);
			check_S = checkExistOfStudentAccount(student, user, pass, loggedinStudent);

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
				"3.Look up.",
				"4.Change password.",
				"0.Log out.",
				"-1.Exit." };
			int x_boxStaff = 5;
			int y_boxStaff = 4;
			int width_boxStaff = 22;
			int height_boxStaff = 3;
			int amount = sizeof(option) / sizeof(option[0]);
			int choose_staff;

			choose_staff = menu(x_boxStaff, y_boxStaff, width_boxStaff, height_boxStaff, amount, option, WHITE, LIGHT_YELLOW, LIGHT_GREEN);

			//printInformation_A_Staff(loggedinStaff);

			if (choose_staff == 1) { //Create new
				while (1) {
					std::system("cls");
					menu_Staff(x_boxStaff, y_boxStaff, width_boxStaff, height_boxStaff, amount, option, WHITE, LIGHT_YELLOW, LIGHT_GREEN, choose_staff);

					std::string option_1[] = { "1.Create a new school year.",
						"2.Create semester.",
						"3.Create a new class.",
						"4.Change information of a teacher.",
						"5.Change your information.",
						"6.Create a new staff's account.",
						"0.Come back." };
					int x_boxOption1 = x_boxStaff + width_boxStaff + 2;
					int y_boxOption1 = y_boxStaff;
					int width_boxOption1 = 50;
					int height_boxOption1 = 3;
					int amount_option1 = sizeof(option_1) / sizeof(option_1[0]);
					int choose;
					choose = menu(x_boxOption1, y_boxOption1, width_boxOption1, height_boxOption1, amount_option1, option_1, WHITE, LIGHT_YELLOW, LIGHT_GREEN);

					if (choose == 1) {
						std::system("cls");
						std::cout << " Create a school year " << std::endl;
						int schoolYear;
						CreateSchoolYear(schoolYear);
						std::system("pause");
					}
					else if (choose == 2) {

					}
					else if (choose == 3) {
					Here:
						std::system("cls");
						std::string ClassID, ClassName, SchoolYear;
						std::cout << "Enter class ID: ";
						getline(std::cin, ClassID);
						std::cout << "Enter class name: ";
						getline(std::cin, ClassName);
						std::cout << "Enter School Year: ";
						getline(std::cin, SchoolYear);

						bool check = 0;
						CLASS_NODE* cur_listclass = listclass;
						while (cur_listclass != nullptr) {
							if (cur_listclass->listclass.ClassID == ClassID) {
								check = 1;
							}
							cur_listclass = cur_listclass->next;
						}
						if (check == 1) {
							std::cout << "The class ID you entered already exists, please enter gain.";
							std::system("pause");
							goto Here;
						}
						cur_listclass = listclass;
						while (cur_listclass->next != nullptr) {
							cur_listclass = cur_listclass->next;
						}
						cur_listclass->next = new CLASS_NODE;
						cur_listclass->next->listclass.ClassID = ClassID;
						cur_listclass->next->listclass.name = ClassName;
						cur_listclass->next->listclass.schoolYear = stoi(SchoolYear);
					}
					else if (choose == 4) {
						std::system("cls");
						std::string teacherID;
						std::cout << "======================Update personal information======================" << std::endl;
						ViewListOfTeachers(teacher);
						std::cout << "\n\nEnter the ID of the teacher you want to update: ";
						std::cin >> teacherID;
						UpdateTeacherInfor(teacherID, teacher);
						std::system("pause");
					}
					else if (choose == 5) {
						std::system("cls");
						std::cout << "======================Update your information======================" << std::endl;

						UpdateYourInfor(loggedinStaff, teacher);
					}
					else if (choose == 6) {
						std::system("cls");
						std::cout << "======================Create a new staff's account======================" << std::endl;
						Create_newStaff(staff);
					}
					else if (choose == 0 + 7) {
						break;
					}
					else {
						std::cout << "Invalid selection, please enter again.\n\n";
						std::system("pause");
					}
				}
			}
			else if (choose_staff == 2) { //Enter information
				while (1) {
					std::system("cls");
					menu_Staff(x_boxStaff, y_boxStaff, width_boxStaff, height_boxStaff, amount, option, WHITE, LIGHT_YELLOW, LIGHT_GREEN, choose_staff);
					std::string option_2[] = { "1.Add new 1st year students to 1st year classes.",
						"2.Create a course registration session.",
						"3.Add a new course.",
						"4.Export the file to import the list of students in each class.",
						"5.Delete a course.",
						"6.Update a course.",
						"7.Update the marks in a course.",
						"0.Come back." };
					int x_boxOption2 = x_boxStaff + width_boxStaff + 2;
					int y_boxOption2 = y_boxStaff;
					int width_boxOption2 = 70;
					int height_boxOption2 = 3;
					int amount_option2 = sizeof(option_2) / sizeof(option_2[0]);
					int choose;
					choose = menu(x_boxOption2, y_boxOption2, width_boxOption2, height_boxOption2, amount_option2, option_2, WHITE, LIGHT_YELLOW, LIGHT_GREEN);

					if (choose == 1) { //Add new 1st year students to 1st year classes
						addNew1styearStudent(student, listclass);
					}
					else if (choose == 2) { //Registration
						break;
					}
					else if (choose == 3) { //Add a course
						CreateNewCourse(stu_course, teacher, course);
					}
					else if (choose == 4) { //Export the file to import the list of students in each class
						int check;
						std::system("cls");
						std::cout << "\n\t\t\t ********************************************" << std::endl;
						std::cout << "\t\t\t\t      ";
						std::cout << "Enter the scoreboard of a course." << std::endl;
						EnterCourseScore(stu_course, course, loggedinStaff, check);
						if (check != 0) {
							Read_After_Update_Student_Course(student, course, teacher, stu_course);
							count = 7;
						}
						std::system("pause");
					}
					else if (choose == 5) { //Delete a course
						DeleteCourse(stu_course, teacher, course);
					}
					else if (choose == 6) { //Update a course
						UpdateCourseInfo(stu_course, teacher, course);
					}
					else if (choose == 7) { //Update the marks in a course
						UpdateMarksInfo(student, stu_course, teacher, course);
					}
					else if (choose == 0 + 8) { //COME BACK
						break;
					}
					else {
						std::cout << "Invalid selection, please enter again.\n\n";
						std::system("pause");
					}
				}
			}
			else if (choose_staff == 3) { //Look up
				while (1) {
					std::system("cls");
					menu_Staff(x_boxStaff, y_boxStaff, width_boxStaff, height_boxStaff, amount, option, WHITE, LIGHT_YELLOW, LIGHT_GREEN, choose_staff);

					std::string option_3[] = { "1.List of classes.",
						"2.List of students in class.",
						"3.List of courses.",
						"4.List of students in a course.",
						"5.View a scoreboard in a course.",
						"6.View a scoreboard in class.",
						"7.Export csv file about a scoreboard of students in course to enter score.",
						"0.Come back." };
					int x_boxOption3 = x_boxStaff + width_boxStaff + 2;
					int y_boxOption3 = y_boxStaff;
					int width_boxOption3 = 78;
					int height_boxOption3 = 3;
					int amount_option3 = sizeof(option_3) / sizeof(option_3[0]);
					int choose;
					choose = menu(x_boxOption3, y_boxOption3, width_boxOption3, height_boxOption3, amount_option3, option_3, WHITE, LIGHT_YELLOW, LIGHT_GREEN);

					if (choose == 1) { //List of classes
						viewListOfClasses(listclass, student);
					}
					else if (choose == 2) { //List of students in class
						viewListStudentsOfClass(student, listclass);
					}
					else if (choose == 3) { //List of courses
						viewListOfCourses(course);
						//std::system("pause");
					}
					else if (choose == 4) { //List of students in a course
						viewListStudentsOfCourse(stu_course, student, course);
					}
					else if (choose == 5) { //View a scoreboard in a course
						viewScoreboardInCourse(course, stu_course, student);
					}
					else if (choose == 6) { //View a scoreboard in class
						viewScoreBoard_Class(stu_course, student, listclass);
					}
					else if (choose == 7) { //Export csv file about a scoreboard of students in course to enter score
						ExportScoreBoard(stu_course, course, student);
					}
					else if (choose == 0 + 8) {
						break;
					}
					else {
						std::cout << "Invalid selection, please enter again.\n\n";
						std::system("pause");
					}
				}
			}
			else if (choose_staff == 4) { // +++++++++++++++++++++++++CHANGE PASSWORD+++++++++++++++++++++
				//changePassWordOfStaffAccount(staff, loggedinStaff);

			AGAIN_4:
				std::system("cls");
				ShowCur(1);

				menu_Staff(x_boxStaff, y_boxStaff, width_boxStaff, height_boxStaff, amount, option, WHITE, LIGHT_YELLOW, LIGHT_GREEN, choose_staff);

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

				if (loggedinStaff->staff.Password != old_password) {
					my_print(width_tmp, height_tmp + 15, RED, "Your old password has been entered incorrectly. Please, enter again.");
					gotoXY(width_tmp, height_tmp + 17);
					std::system("pause");
					goto AGAIN_4;
				}
				if (new_password != new_password_again) {
					my_print(width_tmp, height_tmp + 15, RED, "Confirmation password is not correct. Please, enter again.");
					gotoXY(width_tmp, height_tmp + 17);
					std::system("pause");
					goto AGAIN_4;
				}
				loggedinStaff->staff.Password = new_password;
				Read_After_Update_Staffs(staff);
				my_print(width_tmp, height_tmp + 15, RED, "Change password successfully.");
			}
			else if (choose_staff == 0 + 5) { // ++++++++++++++++++++++++++LOG OUT++++++++++++++++++++++++++
				break;
			}
			else if (choose_staff == -1 + 7) { // ++++++++++++++++++++++++++++EXIT++++++++++++++++++++++++++++
				std::system("cls");
				std::cout << "****************************THANK YOU FOR USING!********************************";
				return 0;
			}
		}

		//THE FUNCTIONS OF STUDENT
		while (check_S == 1) {
		RESTART:
			std::system("cls");
			std::string option[] = { "1. Change password.",
						"2. Update your personal information.",
						"3. Register for the course.",
						"4. The result of register for the course.",
						"5. Delete the course which registered.",
						"6. View your schedule.",
						"7. View your scoreboard.",
						"0. Log out.",
						"-1. Exit." };

			int x_boxStudent = 5;
			int y_boxStudent = 2;
			int width_boxStudent = 42;
			int height_boxStudent = 2;
			int amount = sizeof(option) / sizeof(option[0]);
			int choose;
			choose = menu(x_boxStudent, y_boxStudent, width_boxStudent, height_boxStudent, amount, option, WHITE, LIGHT_YELLOW, LIGHT_GREEN);

			//printInformation_A_Student(loggedinStudent);

			if (choose == 1) {
				changePasswordOfStudentAccount(student, loggedinStudent);
			}
			else if (choose == 2) {
				UpdateStudentInfo(student, loggedinStudent);
			}
			else if (choose == 3) {
				std::system("cls");
				updateCur_stdnInCourse(course, stu_course);

				int check = 0;
				std::string CourseID;
				CR_NODE* cur_course = course;
				do {
					std::system("cls");
					viewListOfCourses(course);
				AGAIN:
					std::cin.ignore();
					std::cout << "\n\nEnter Course ID which you want to register: ";
					getline(std::cin, CourseID);

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
						std::cout << "Your Course ID doesn't exist. Please enter again.\n";
						std::cout << "\nSearch for Course again? (y/n)";
						char ans;
						std::cin >> ans;
						if (ans == 'y' || ans == 'Y') {
							goto AGAIN;
						}
						else if (ans == 'n' || ans == 'N') {
							check = 2;
							goto RESTART;
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
					std::cout << "No more slot for this course " << std::endl;
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
					std::cout << "You have registered 5 courses, cannot register more " << std::endl;
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
							std::cout << "Conflict between your calendar and the course's calendar" << std::endl;
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
						std::cout << "Your have already registed to this course " << std::endl;
						break;
					}
					else
						cur_stu_course = cur_stu_course->next;
				}
				if (cur_stu_course == nullptr)
					check4 = true;

				// update

				if (check1 == check2 == check3 == check4 == true) {
					char lastcheck;
					std::cout << "\nAre you sure you want to register to this course? (y/n): ";
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

						std::cout << "\nRegister successfully " << std::endl;
					}
				}
				std::system("pause");
			}

			else if (choose == 4) {
				ResultRegistration(stu_course, loggedinStudent, course);
			}
			else if (choose == 5) {
				DeleteRegisteredCourse(stu_course, loggedinStudent, course, student, teacher);
			}
			else if (choose == 6) {
				ViewSchedule(stu_course, loggedinStudent, course);
			}
			else if (choose == 7) {
				View_Y_Scoreboard(stu_course, loggedinStudent);
				std::system("pause");
			}
			else if (choose == 0 + 8) {
				break;
			}
			else if (choose == -1 + 10) {
				std::system("cls");
				std::cout << "****************************THANK YOU FOR USING!********************************";
				return 0;
			}
		}
	}
}

