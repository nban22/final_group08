#pragma once
#include "header.h"
#include <conio.h>
using namespace std;

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
	int count = 0;

	ifstream input;
	STFF_NODE* staff = nullptr;
	getDataStaff_csv(input, staff);
	STFF_NODE* loggedinStaff = new STFF_NODE;

	ifstream input_T;
	STFF_NODE* teacher = nullptr;
	getDataTeacher_csv(input_T, teacher);

	//STAFF ACCOUNT TO TEST RUN: 
	//USER:   33383147
	//PASSWORD:    123456

	//STUDENT ACCOUNT TO TEST RUN: 
	//USER:   22240001
	//PASSWORD:    678910

	ifstream input_S;
	STU_NODE* student = nullptr;
	getDataStudents_csv(input_S, student);
	STU_NODE* loggedinStudent = new STU_NODE;

	ifstream input_STU_CR;
	STU_COURSE_NODE* stu_course = nullptr;
	Get_Data_StudentCourse_csv(input_STU_CR, stu_course);

	ifstream input_CR;
	CR_NODE* course = nullptr;
	getDataCourse_csv(input_CR, course);

	updateCur_stdnInCourse(course, stu_course);

	/*Read_After_Update_Teachers(teacher);
	Read_After_Update_Staffs(staff);
	Read_After_Update_Students(student);
	Read_After_Update_Course(stu_course, teacher, course);
	Read_After_Update_Student_Course(student, course, teacher, stu_course);
	return 0;*/

	while (69) {
		int check_T, check_S;
		do {
			std::system("cls");

			string user, pass;
			int tmp_width = 40;
			int box_width = 30;

			SetColor(LIGHT_YELLOW);
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
			
			string option[] = { "1.Create new.",
				"2.Enter information.",
				"3.Look up.",
				"4.Change password.",
				"0.Log out.",
				"-1.Exit." };
			int x_boxStaff = 40;
			int y_boxStaff = 5;
			int width_boxStaff = 30;
			int height_boxStaff = 2;
			int amount = sizeof(option) / sizeof(option[0]);
			int choose;

			choose = menu_staff(x_boxStaff, y_boxStaff, width_boxStaff, height_boxStaff, amount, option, WHITE, LIGHT_YELLOW, LIGHT_GREEN);

			//printInformation_A_Staff(loggedinStaff);

			if (choose == 1) { //Create new
				while (1) {
					std::system("cls");
					std::cout << "======================Create new======================";
					std::cout << "\n\t1.Create a new school year."
						<< "\n\t2.Create semester."
						<< "\n\t3.Create a new class."
						<< "\n\t4.Change information of a teacher."
						<< "\n\t5.Change your information."
						<< "\n\t6.Create a new staff's account."
						<< "\n\t0.Come back.\n";
					std::cout << "=========================END==========================\n\n";
					std::cout << "\nEnter select the option you want to choose: ";
					std::cin >> choose;
					std::cin.ignore();
					if (choose == 1) {
						std::system("cls");
						std::cout << " Create a school year " << endl;
						int schoolYear;
						CreateSchoolYear(schoolYear);
						std::system("pause");
					}
					else if (choose == 2) {


					}
					else if (choose == 3) {
						std::system("cls");
						std::string className;

						createClass(className);

						importStudents(className);

						std::cout << "Enter class";

						std::system("pause");

					}
					else if (choose == 4) {
						string teacherID;
						std::system("cls");
						std::cout << "======================Update personal information======================" << endl;
						ViewListOfTeachers(teacher);
						cout << "\n\nEnter the ID of the teacher you want to update: ";
						cin >> teacherID;
						UpdateTeacherInfor(teacherID, teacher);
						std::system("pause");
					}
					else if (choose == 5) {
						std::system("cls");
						std::cout << "======================Update your information======================" << endl;

						UpdateYourInfor(loggedinStaff, teacher);

					}
					else if (choose == 6) {
						std::system("cls");
						std::cout << "======================Create a new staff's account======================" << endl;
						Create_newStaff(staff);
					}
					else if (choose == 0) {
						break;
					}
					else {
						std::cout << "Invalid selection, please enter again.\n\n";
						std::system("pause");
					}
				}
			}
			else if (choose == 2) { //Enter information
				while (1) {
					std::system("cls");
					std::cout << "======================Enter information======================";
					std::cout << "\n\t1.Add new 1st year students to 1st year classes."//them sinh vien nam nhat vao lop
						<< "\n\t2.Create a course registration session."//tao phien DKHP
						<< "\n\t3.Add a new course."//Them khoa hoc
						<< "\n\t4.Export the file to import the list of students in each class."//Xuat file nhap DSSV tung lop
						<< "\n\t5.Delete a course."//Xoa khoa hoc
						<< "\n\t6.Update a course."//Cap nhat khoa hoc
						<< "\n\t7.Update the marks in a course."//Cap nhat diem trong khoa hoc
						<< "\n\t0.Come back.\n";
					std::cout << "=============================END=============================\n\n";
					std::cout << "\nEnter select the option you want to choose: ";
					std::cin >> choose;
					std::cin.ignore();
					if (choose == 1) { //Add new 1st year students to 1st year classes
						addNew1styearStudent(student);
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
						std::cout << "\n\t\t\t ********************************************" << endl;
						std::cout << "\t\t\t\t      ";
						std::cout << "Enter the scoreboard of a course." << endl;
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
					else if (choose == 0) { //COME BACK
						break;
					}
					else {
						std::cout << "Invalid selection, please enter again.\n\n";
						std::system("pause");
					}
				}
			}
			else if (choose == 3) { //Look up
				while (1) {
					std::system("cls");
					std::cout << "======================Look up======================";
					std::cout << "\n\t1.List of classes." //Danh sach lop
						<< "\n\t2.List of students in class." //Danh sach sinh vien trong lop
						<< "\n\t3.List of courses." // Danh sach khoa hoc
						<< "\n\t4.List of students in a course." //Danh sach sinh vien trong trong khoa hoc
						<< "\n\t5.View a scoreboard in a course." //Xem bang diem trong khoa hoc
						<< "\n\t6.View a scoreboard in class." //Xem bang diem trong lop
						<< "\n\t7.Export csv file about a scoreboard of students in course to enter score."
						//Xuat csv file bang diem sinh vien trong khoa hoc de nhap diem
						<< "\n\t0.Come back.\n";
					std::cout << "========================END========================\n\n";
					std::cout << "\nEnter select the option you want to choose: ";
					std::cin >> choose;
					std::cin.ignore();
					if (choose == 1) { //List of classes
						std::system("cls");
						viewListOfClasses(student);
						std::system("pause");
					}
					else if (choose == 2) { //List of students in class
						viewListStudentsOfClass(student);
					}
					else if (choose == 3) { //List of courses
						system("cls");
						viewListOfCourses(course);
						system("pause");
					}
					else if (choose == 4) { //List of students in a course
						int check = 0;
						string CourseID;
						do {
							system("cls");
							viewListOfCourses(course);
							cout << "\n\nEnter Course ID which you want to view: ";
							getline(cin, CourseID);

							CR_NODE* cur = course;
							while (cur) {
								if (cur->course.ID == CourseID)
									check = 1;
								cur = cur->next;
							}
							if (check == 0) {
								cout << "Your Course ID doesn't exist. Please enter again.\n";
								system("pause");
							}
						} while (check == 0);
						system("cls");
						viewListStudentsOfCourse(stu_course, student, CourseID);
						system("pause");
					}
					else if (choose == 5) { //View a scoreboard in a course
						int check = 0;
						string CourseID;
						do {
							system("cls");
							viewListOfCourses(course);
							cout << "\n\nEnter the course ID which you want to view the scoreboard: ";
							getline(cin, CourseID);

							CR_NODE* cur = course;
							while (cur) {
								if (cur->course.ID == CourseID)
									check = 1;
								cur = cur->next;
							}
							if (check == 0) {
								cout << "Your Course ID doesn't exist. Please enter again.\n";
								system("pause");
							}
						} while (check == 0);
						system("cls");
						viewScoreBoard_Course(stu_course, student, CourseID);
						system("pause");
					}
					else if (choose == 6) { //View a scoreboard in class
						int check = 0;
						string ClassID;
						do {
							std::system("cls");
							viewListOfClasses(student);
							cout << "\n\nEnter the class ID which you want to view the scoreboard: ";
							getline(cin, ClassID);

							if (checkExistClassIDinDLL(student, ClassID) != nullptr)
								check = 1;

							if (check == 0) {
								cout << "Your class ID doesn't exist. Please enter again.\n";
								system("pause");
							}
						} while (check == 0);
						system("cls");
						viewScoreBoard_Class(stu_course, student, ClassID);
						system("pause");
					}
					else if (choose == 7) { //Export csv file about a scoreboard of students in course to enter score
						ExportScoreBoard(stu_course, course, student);
					}
					else if (choose == 0) {
						break;
					}
					else {
						std::cout << "Invalid selection, please enter again.\n\n";
						std::system("pause");
					}
				}
			}
			else if (choose == 4) { // +++++++++++++++++++++++++CHANGE PASSWORD+++++++++++++++++++++
				changePassWordOfStaffAccount(staff, loggedinStaff);
			}
			else if (choose == 0 + 5) { // ++++++++++++++++++++++++++LOG OUT++++++++++++++++++++++++++
				break;
			}
			else if (choose == -1 + 7) { // ++++++++++++++++++++++++++++EXIT++++++++++++++++++++++++++++
				system("cls");
				std::cout << "****************************THANK YOU FOR USING!********************************";
				return 0;
			}
			else {
				std::cout << "Invalid selection, please enter again.\n\n";
				std::system("pause");
			}
		}

		//THE FUNCTIONS OF STUDENT
		while (check_S == 1) {
			std::system("cls");
			std::cout << "======================STUDENT======================";
			std::cout << "\n1. Change password.\n"
				<< "2. Update your personal information.\n"
				<< "3. Register for the course.\n"
				<< "4. The result of register for the course.\n"
				<< "5. Delete the course which registered.\n"
				<< "6. View your schedule.\n"
				<< "7. View your scoreboard.\n"
				<< "0. Log out.\n"
				<< "-1. Exit.\n";
			std::cout << "========================END========================\n\n";

			printInformation_A_Student(loggedinStudent);

			std::cout << "Enter select the option you want to choose: ";
			int choose;
			std::cin >> choose;
			std::cin.ignore();

			if (choose == 1) {
				changePasswordOfStudentAccount(student, loggedinStudent);
			}
			else if (choose == 2) {
				UpdateStudentInfo(student, loggedinStudent);
			}
			else if (choose == 3) {
			AGAIN:
				system("cls");
				updateCur_stdnInCourse(course, stu_course);
				viewListOfCourses(course);

				int check = 0;
				string CourseID;
				CR_NODE* cur_course = course;
				do {
					system("cls");
					viewListOfCourses(course);
					cout << "\n\nEnter Course ID which you want to view: ";
					getline(cin, CourseID);

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
						cout << "Your Course ID doesn't exist. Please enter again.\n";
						cout << "\nSearch for Course again? (y/n)";
						char ans;
						cin >> ans;
						cin.ignore();
						if (ans == 'y' || ans == 'Y') {
							goto AGAIN;
						}
						else {
							check = 2;
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
					cout << "No more slot for this course " << endl;
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
					cout << "You have registered 5 courses, cannot register more " << endl;
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
							cout << "Conflict between your calendar and the course's calendar" << endl;
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
						cout << "Your have already registed to this course " << endl;
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
					cout << "\nAre you sure you want to register to this course? (y/n): ";
					cin >> lastcheck;
					if (lastcheck == 'y' || lastcheck == 'Y') {
						cur_stu_course = stu_course;
						while (cur_stu_course->next)
							cur_stu_course = cur_stu_course->next;

						CR_NODE* cr_tmp = course;

						while (cr_tmp) {
							if (cr_tmp->course.ID == CourseID)
								break;
							else
								cr_tmp = cr_tmp->next;
						}

						STU_COURSE_NODE* stu_cr_tmp = new STU_COURSE_NODE;
						stu_cr_tmp->prev = cur_stu_course;
						stu_cr_tmp->next = nullptr;
						cur_stu_course->next = stu_cr_tmp;
						stu_cr_tmp->stu_course.Class = cr_tmp->course.Class;
						stu_cr_tmp->stu_course.Cname = cr_tmp->course.CName;
						stu_cr_tmp->stu_course.CouID = cr_tmp->course.ID; //Missing ending 0
						stu_cr_tmp->stu_course.credits = cr_tmp->course.Credits;
						stu_cr_tmp->stu_course.enddate.day = cr_tmp->course.endDate.day;
						stu_cr_tmp->stu_course.enddate.month = cr_tmp->course.endDate.month;
						stu_cr_tmp->stu_course.enddate.year = cr_tmp->course.endDate.year; 
						stu_cr_tmp->stu_course.Gen = loggedinStudent->student.Gender;
						stu_cr_tmp->stu_course.Max_stdn = cr_tmp->course.Max_stdn;
						stu_cr_tmp->stu_course.No = stu_cr_tmp->prev->stu_course.No + 1; //Wrong output
						stu_cr_tmp->stu_course.session = cr_tmp->course.session;
						stu_cr_tmp->stu_course.startdate.day = cr_tmp->course.startDate.day;
						stu_cr_tmp->stu_course.startdate.month = cr_tmp->course.startDate.month;
						stu_cr_tmp->stu_course.startdate.year = cr_tmp->course.startDate.year;
						stu_cr_tmp->stu_course.StudentName = loggedinStudent->student.LName + " " + loggedinStudent->student.FName;
						stu_cr_tmp->stu_course.StuID = loggedinStudent->student.StudentID;
						stu_cr_tmp->stu_course.TeacherID = cr_tmp->course.teacherID;
						stu_cr_tmp->stu_course.Teachername = cr_tmp->course.LNameTeacher + " " + cr_tmp->course.FNameTeacher;
						stu_cr_tmp->stu_course.weekday = cr_tmp->course.dayOfWeek;
						stu_cr_tmp->stu_course.final = stu_cr_tmp->stu_course.midterm = stu_cr_tmp->stu_course.other = stu_cr_tmp->stu_course.total = 0;
						Read_After_Update_Student_Course(student, course, teacher, stu_course);
						delete cr_tmp;
						cout << "\nRegister successfully " << endl;
					}
				}
				system("pause");
			}
			else if (choose == 4) {
				ResultRegistration(stu_course, loggedinStudent, course);
			}
			else if (choose == 5) {
				DeleteRegisteredCourse(stu_course, loggedinStudent, course);
			}
			else if (choose == 6) {
				ViewSchedule(stu_course, loggedinStudent, course);
			}
			else if (choose == 7) {
				View_Y_Scoreboard(stu_course, loggedinStudent);
				system("pause");
			}
			else if (choose == 0) {
				break;
			}
			else if (choose == -1) {
				std::system("pause");
				return 0;
			}
			else {
				std::cout << "Invalid selection, please enter again.\n\n";
				std::system("pause");
			}

		}
	}
}

