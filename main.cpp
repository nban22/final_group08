#include "header.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int count = 0;

	ifstream input;
	STFF_NODE* staff = nullptr; 
	getDataTeachers_csv(input, staff);
	STFF_NODE* loggedinStaff = new STFF_NODE;

	//ACCOUNT TO TEST RUN: 
	//USER:   24061530
	//PASSWORD:    123456

	ifstream input_S;
	STU_NODE* student = nullptr;
	getDataStudents_csv(input_S, student);
	STU_NODE* loggedinStudent = new STU_NODE;

	ifstream input_STU_CR;
	STU_COURSE_NODE *stu_course = nullptr;
	Get_Data_StudentCourse_csv(input_STU_CR, stu_course);

	ifstream input_CR;
	CR_NODE* course = nullptr;
	getDataCourse_csv(input_CR, course);

	while (69) {
		int check_T, check_S;
		do {
			system("cls");
			string user, pass;
			cout << "ID of Your User: ";
			getline(cin, user);
			cout << "Password: ";
			getline(cin, pass);

			check_T = checkExistOfStaffAccount(staff, user, pass, loggedinStaff);
			check_S = checkExistOfStudentAccount(student, user, pass, loggedinStudent);

			if (check_T == 1 || check_S == 1) {
				cout << "Logged in successfully.\n\n";
				system("pause");
				continue;
			}
			if (check_T == -1 || check_S == -1) {
				cout << "Your password isn't correct. Please, enter again.\n\n";
				system("pause");
				continue;
			}
			if (check_T == 0 || check_S == 0) {
				cout << "Your account doesn't exist. Please, enter again.\n\n";
				system("pause");
			}
		} while (!(check_T == 1 || check_S == 1));

		//THE FUNCTIONS OF STAFF
		while (check_T == 1) {
			system("cls");

			cout << "======================TEACHER======================";
			//cout << "\n\t1. Change password.\n"
			//	<< "\t2. Update your persinal information.\n"
			//	<< "\t3. Create a school year.\n"
			//	<< "\t4. Add new 1st year students to 1st year classes.\n"
			//	<< "\t5. Create a course registration session.\n"
			//	<< "\t6. ...... a scoreboard of a course.\n"
			//			//	<< "\t1. Enter and view the scoreboard of a course.\n"
			//			//	<< "\t2. View the scoreboard of a course.\n"
			//			//	<< "\t3. Import the scoreboard of a course.\n"
			//	<< "\t7. View the scoreboard of a course.\n"
			//	<< "\t8. Update a student result.\n"
			//	<< "\t9. View the scoreboard of a class.\n"
			//	<< "\t0. Log out.\n"
			//	<< "\t-1. Exit\n";
			cout << "\n\t1.Create new."//Tao moi
				<< "\n\t2.Enter information."//Nhap thong tin
				<< "\n\t3.Look up."//Tra cuu
				<< "\n\t4.Change password."//Doi mat khau
				<< "\n\t0.Log out."//Dang xuat
				<< "\n\t-1.Exit.\n";
			cout << "========================END========================\n\n";

			cout << "Teacher.\n";
			cout << "Numerical order: " << loggedinStaff->staff.No_Staff << endl;
			cout << "Full name: " << loggedinStaff->staff.LName << " " << loggedinStaff->staff.FName << "\tTeacher ID: " << loggedinStaff->staff.TeacherID << endl;
			cout << "Gender: " << loggedinStaff->staff.Gender << "\tDate of birth: " 
				<< loggedinStaff->staff.DoB.day << "/" << loggedinStaff->staff.DoB.month << "/" << loggedinStaff->staff.DoB.year << endl;
			cout << "Faculty: " << loggedinStaff->staff.Faculty << "\n\n";

			cout << "Enter select the option you want to choose: ";
			int choose;
			cin >> choose;
			cin.ignore();

			if (choose == 1) { //Create new
				system("cls");
				cout << "======================Look up======================";
				cout << "\n\t1.Create a new school year."
					<< "\n\t2.Create semester."
					<< "\n\t3.List of courses."
					<< "\n\t0.Come back.\n";
				cout << "========================END========================\n\n";
				cin >> choose;
				cin.ignore();
				if (choose == 1) {
					system("cls");
					cout << " Create a school year " << endl;
					int schoolYear;
					CreateSchoolYear(schoolYear);
					system("pause");
				}
				else if (choose == 2) {

			
				}
				else if (choose == 3) {

				}
				else if (choose == 4) {

				}
				else if (choose == 0) {
					break;
				}
				else {
					cout << "Invalid selection, please enter again.\n\n";
					system("pause");
				}
			}
			else if (choose == 2) { //Enter information
				system("cls");
				cout << "======================Look up======================";
				cout << "\n\t1.Add new 1st year students to 1st year classes."//them sinh vien nam nhat vao lop
					<< "\n\t2.Create a course registration session."//tao phien DKHP
					<< "\n\t3.Add a course."//Them khoa hoc
					<< "\n\t4.Export the file to import the list of students in each class."//Xuat file nhap DSSV tung lop
					<< "\n\t5.Delete a course."//Xoa khoa hoc
					<< "\n\t6.Update a course."//Cap nhat khoa hoc
					<< "\n\t7.Update the marks in a course."//Cap nhat diem trong khoa hoc
					<< "\n\t0.Come back.\n";
				cout << "========================END========================\n\n";
				cin >> choose;
				cin.ignore();
				if (choose == 1) { //Add new 1st year students to 1st year classes

				}
				else if (choose == 2) { //Create a course registration session

				}
				else if (choose == 3) { //Add a course

				}
				else if (choose == 4) { //Export the file to import the list of students in each class
					int check;
					system("cls");
					cout << "\n\t\t\t ********************************************" << endl;
					cout << "\t\t\t\t      ";
					cout << "Enter the scoreboard of a course." << endl;
					EnterCourseScore(stu_course, course, loggedinStaff, check);
					if (check != 0) {
						Read_After_Update_Student_Course(stu_course);
						count = 7;
					}
					system("pause");
				}
				else if (choose == 5) { //Delete a course

				}
				else if (choose == 6) { //Update a course

				}
				else if (choose == 7) { //Update the marks in a course

				}
				else if (choose == 0) {
					break;
				}
				else {
					cout << "Invalid selection, please enter again.\n\n";
					system("pause");
				}
			}
			else if (choose == 3) { //Look up
				system("cls");
				cout << "======================Look up======================";
				cout << "\n\t1.List of classes." //Danh sach lop
					<< "\n\t2.List of students in class." //Danh sach sinh vien trong lop
					<< "\n\t3.List of courses." // Danh sach khoa hoc
					<< "\n\t4.List of students in a course." //Danh sach sinh vien trong trong khoa hoc
					<< "\n\t5.View a scoreboard in a course." //Xem bang diem trong khoa hoc
					<< "\n\t6.View a scoreboard in class." //Xem bang diem trong lop
					<< "\n\t7.Export csv file about a scoreboard of students in course to enter score."
					//Xuat csv file bang diem sinh vien trong khoa hoc de nhap diem
					<< "\n\t0.Come back.\n";
				cout << "========================END========================\n\n";
				cin >> choose;
				cin.ignore();
				if (choose == 1) { //List of classes
					/*STU_NODE* listclass = new STU_NODE;*/
					
				}
				else if (choose == 2) { //List of students in class

				}
				else if (choose == 3) { //List of courses

				}
				else if (choose == 4) { //List of students in a course

				}
				else if (choose == 5) { //View a scoreboard in a course
					int check;
					system("cls");
					cout << "\n\t\t\t ********************************************" << endl;
					cout << "\t\t\t\t      ";
					cout << "Enter the scoreboard of a course." << endl;
					EnterCourseScore(stu_course, course, loggedinStaff, check);
					if (check != 0) {
						Read_After_Update_Student_Course(stu_course);
						count = 7;
					}
					system("pause");
				}
				else if (choose == 6) { //View a scoreboard in class

				}
				else if (choose == 7) { //View a scoreboard in class

				}
				else if (choose == 0) { //Export csv file about a scoreboard of students in course to enter score
					break;
				}
				else {
					cout << "Invalid selection, please enter again.\n\n";
					system("pause");
				}
			}
			else if (choose == 4) {
				changePassWordOfStaffAccount(staff, loggedinStaff);
			}
			else if (choose == 0) {
				break;
			}
			else if (choose == -1) {
				system("pause");
				return 0;
			}
			else {
				cout << "Invalid selection, please enter again.\n\n";
				system("pause");
			}
		}

		//	if (choose == 1) {
		//		changePassWordOfStaffAccount(staff, loggedinStaff);
		//	}
		//	else if (choose == 2) {

		//	}
		//	else if (choose == 3) {

		//	}
		//	else if (choose == 4) {

		//	}
		//	else if (choose == 5) {
		//		DisplayMenu(choose);
		//	}
		//	else if (choose == 6) { // ong lam cai menu o day nhe.
		//		int check;
		//		system("cls");
		//		cout << "\n\t\t\t ********************************************" << endl;
		//		cout << "\t\t\t\t      ";
		//		cout << "Enter the scoreboard of a course." << endl;
		//		EnterCourseScore(stu_course, course, loggedinStaff, check);
		//		if (check != 0) {
		//			Read_After_Update_Student_Course(stu_course);
		//			count = 7;
		//		}
		//		system("pause");
		//	}
		//	else if (choose == 7) {
		//		
		//	}
		//	else if (choose == 8) {

		//	}
		//	else if (choose == 9) {

		//	}
		//	else if (choose == 0) {
		//		break;
		//	}
		//	else if (choose == -1) {
		//		system("pause");
		//		return 0;
		//	}
		//	else {
		//		cout << "Invalid selection, please enter again.\n\n";
		//		system("pause");
		//	}
		//}

		//THE FUNCTIONS OF STUDENT
		while (check_S == 1) {
			system("cls");
			cout << "======================STUDENT======================";
			cout << "\n1. Change password.\n"
				<< "2. Update your personal information.\n"
				<< "3. Register for the course.\n"
				<< "4. View your schedule.\n"
				<< "5. View your scoraboard.\n"
				<< "6. View list of student in a course.\n"
				<< "7. View of classes.\n"
				<< "8. View list of student in a class.\n"
				<< "0. Log out.\n"
				<< "-1. Exit.\n";
			cout << "========================END========================\n";

			cout << "Student.\n";
			cout << "Numerical order: " << loggedinStudent->student.No_Student << endl;
			cout << "Full name: " << loggedinStudent->student.LName << " " << loggedinStudent->student.FName << "\tStudent ID: " << loggedinStudent->student.StudentID << endl;
			cout << "Gender: " << loggedinStudent->student.Gender << "\tDate of birth: " 
				<< loggedinStudent->student.DoB.day/10 << loggedinStudent->student.DoB.day % 10 << "/" << loggedinStudent->student.DoB.month/10 << loggedinStudent->student.DoB.month % 10 << "/" << loggedinStudent->student.DoB.year << endl;
			cout << "Class name: " << loggedinStudent->student.Classes.name << "\tClass ID: " << loggedinStudent->student.Classes.ClassID << "\n\n";

			cout << "Enter select the option you want to choose: ";
			int choose;
			cin >> choose;
			cin.ignore();

			if (choose == 1) {
				string oldPass;
				string newPass;
				string newPassAgain;
				do {
					system("cls");
					cout << "Enter your old password: ";
					getline(cin, oldPass);
					if (loggedinStudent->student.Password != oldPass) {
						cout << "Your old password has been entered incorrectly. Please, enter again.\n";
						system("pause");
						continue;
					}
					else {
						cout << "Enter your new password: ";
						getline(cin, newPass);
						cout << "Enter your new password again: ";
						getline(cin, newPassAgain);
						if (newPass != newPassAgain) {
							cout << "Confirmation password is not correct. Please, enter again.\n";
							system("pause");
							continue;
						}
						loggedinStudent->student.Password = newPass;
						Read_After_Update_Students(student);
						cout << "Change password successfully.\n";
						system("pause");
						break;
					}
				} while (loggedinStudent->student.Password != oldPass || newPass != newPassAgain);
				


				
			}
			else if (choose == 2) {

			}
			else if (choose == 3) {

			}
			else if (choose == 4) {

			}
			else if (choose == 5) {

			}
			else if (choose == 6) {

			}
			else if (choose == 7) {

			}
			else if (choose == 8) {

			}
			else if (choose == 0) {
				break;
			}
			else if (choose == -1) {
				system("pause");
				return 0;
			}
			else {
				cout << "Invalid selection, please enter again.\n\n";
				system("pause");
			}

		}
	}
}

		