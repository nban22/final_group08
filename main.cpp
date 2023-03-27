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
	STU_COURSE_NODE* stu_course = nullptr;
	Get_Data_StudentCourse_csv(input_STU_CR, stu_course);

	ifstream input_CR;
	CR_NODE* course = nullptr;
	getDataCourse_csv(input_CR, course);

	while (69) {
		int check_T, check_S;
		do {
			std::system("cls");
			string user, pass;
			std::cout << "ID of Your User: ";
			getline(std::cin, user);
			std::cout << "Password: ";
			getline(std::cin, pass);

			check_T = checkExistOfStaffAccount(staff, user, pass, loggedinStaff);
			check_S = checkExistOfStudentAccount(student, user, pass, loggedinStudent);

			if (check_T == 1 || check_S == 1) {
				std::cout << "Logged in successfully.\n\n";
				std::system("pause");
				continue;
			}
			if (check_T == -1 || check_S == -1) {
				std::cout << "Your password isn't correct. Please, enter again.\n\n";
				std::system("pause");
				continue;
			}
			if (check_T == 0 || check_S == 0) {
				std::cout << "Your account doesn't exist. Please, enter again.\n\n";
				std::system("pause");
			}
		} while (!(check_T == 1 || check_S == 1));

		//THE FUNCTIONS OF STAFF
		while (check_T == 1) {
			std::system("cls");

			std::cout << "======================TEACHER======================";
			std::cout << "\n\t1.Create new."//Tao moi
				<< "\n\t2.Enter information."//Nhap thong tin
				<< "\n\t3.Look up."//Tra cuu
				<< "\n\t4.Change password."//Doi mat khau
				<< "\n\t0.Log out."//Dang xuat
				<< "\n\t-1.Exit.\n";
			std::cout << "========================END========================\n\n";

			std::cout << "Teacher.\n";
			std::cout << "Numerical order: " << loggedinStaff->staff.No_Staff << endl;
			std::cout << "Full name: " << loggedinStaff->staff.LName << " " << loggedinStaff->staff.FName << "\tTeacher ID: " << loggedinStaff->staff.TeacherID << endl;
			std::cout << "Gender: " << loggedinStaff->staff.Gender << "\tDate of birth: "
				<< loggedinStaff->staff.DoB.day << "/" << loggedinStaff->staff.DoB.month << "/" << loggedinStaff->staff.DoB.year << endl;
			std::cout << "Faculty: " << loggedinStaff->staff.Faculty << "\n\n";

			std::cout << "Enter select the option you want to choose: ";
			int choose;
			std::cin >> choose;
			std::cin.ignore();

			if (choose == 1) { //Create new
				while (1) {
					std::system("cls");
					std::cout << "======================Look up======================";
					std::cout << "\n\t1.Create a new school year."
						<< "\n\t2.Create semester."
						<< "\n\t3.List of courses."
						<< "\n\t0.Come back.\n";
					std::cout << "========================END========================\n\n";
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
					std::cout << "======================Look up======================";
					std::cout << "\n\t1.Add new 1st year students to 1st year classes."//them sinh vien nam nhat vao lop
						<< "\n\t2.Create a course registration session."//tao phien DKHP
						<< "\n\t3.Add a course."//Them khoa hoc
						<< "\n\t4.Export the file to import the list of students in each class."//Xuat file nhap DSSV tung lop
						<< "\n\t5.Delete a course."//Xoa khoa hoc
						<< "\n\t6.Update a course."//Cap nhat khoa hoc
						<< "\n\t7.Update the marks in a course."//Cap nhat diem trong khoa hoc
						<< "\n\t0.Come back.\n";
					std::cout << "========================END========================\n\n";
					std::cin >> choose;
					std::cin.ignore();
					if (choose == 1) { //Add new 1st year students to 1st year classes

					}
					else if (choose == 2) { //Create a course registration session

					}
					else if (choose == 3) { //Add a course

					}
					else if (choose == 4) { //Export the file to import the list of students in each class
						int check;
						std::system("cls");
						std::cout << "\n\t\t\t ********************************************" << endl;
						std::cout << "\t\t\t\t      ";
						std::cout << "Enter the scoreboard of a course." << endl;
						EnterCourseScore(stu_course, course, loggedinStaff, check);
						if (check != 0) {
							Read_After_Update_Student_Course(stu_course);
							count = 7;
						}
						std::system("pause");
					}
					else if (choose == 5) { //Delete a course

					}
					else if (choose == 6) { //Update a course

					}
					else if (choose == 7) { //Update the marks in a course

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
					std::cin >> choose;
					std::cin.ignore();
					if (choose == 1) { //List of classes
						std::system("cls");
						STU_NODE* listclass = new STU_NODE;
						STU_NODE* cur_listclass = listclass, * cur_student = student;
						int i = 1;
						while (cur_student) {
							if (checkExistClassIDinDLL(listclass, cur_student->student.Classes.ClassID) == 0)
							{
								if (i != 1) {
									cur_listclass->next = new STU_NODE;
									cur_listclass = cur_listclass->next;
								}
								i++;
								cur_listclass->student = cur_student->student;
							}
							cur_student = cur_student->next;
						}
						displayLISTOFCLASS(student, listclass);
						std::cout << "\n\n";
						std::system("pause");
						deleteSTU_NODE(listclass);
					}
					else if (choose == 2) { //List of students in class

						STU_NODE* listclass = new STU_NODE;
						STU_NODE* cur_listclass = listclass, * cur_student = student;
						int i = 1;
						while (cur_student) {
							if (checkExistClassIDinDLL(listclass, cur_student->student.Classes.ClassID) == nullptr)
							{
								if (i != 1) {
									cur_listclass->next = new STU_NODE;
									cur_listclass = cur_listclass->next;
								}
								cur_listclass->student = cur_student->student;
								cur_listclass->student.No_Student = i++;
							}
							cur_student = cur_student->next;
						}
						string classID;
						while (1) {
							std::system("cls");
							displayLISTOFCLASS(student, listclass);
							std::cout << "\n\n";
							std::cout << "\tEnter class ID which you want to open: ";
							std::cin >> classID;
							if (checkExistClassIDinDLL(listclass, classID) == nullptr) {
								std::cout << "\n\tYour selection doesn't exist.\n";
								std::system("pause");
								continue;
							}
							break;
						}
						std::system("cls");
						displayListStudentsOfCourse(student, classID);
						std::system("pause");


					}
					else if (choose == 3) { //List of courses

					}
					else if (choose == 4) { //List of students in a course

					}
					else if (choose == 5) { //View a scoreboard in a course
						int check;
						std::system("cls");
						std::cout << "\n\t\t\t ********************************************" << endl;
						std::cout << "\t\t\t\t      ";
						std::cout << "Enter the scoreboard of a course." << endl;
						EnterCourseScore(stu_course, course, loggedinStaff, check);
						if (check != 0) {
							Read_After_Update_Student_Course(stu_course);
							count = 7;
						}
						std::system("pause");
					}
					else if (choose == 6) { //View a scoreboard in class

					}
					else if (choose == 7) { //Export csv file about a scoreboard of students in course to enter score

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
			else if (choose == 0) { // ++++++++++++++++++++++++++LOG OUT++++++++++++++++++++++++++
				break;
			}
			else if (choose == -1) { // ++++++++++++++++++++++++++++EXIT++++++++++++++++++++++++++++
				std::system("pause");
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
				<< "4. View your schedule.\n"
				<< "5. View your scoraboard.\n"
				<< "6. View list of student in a course.\n"
				<< "7. View of classes.\n"
				<< "8. View list of student in a class.\n"
				<< "0. Log out.\n"
				<< "-1. Exit.\n";
			std::cout << "========================END========================\n";

			std::cout << "Student.\n";
			std::cout << "Numerical order: " << loggedinStudent->student.No_Student << endl;
			std::cout << "Full name: " << loggedinStudent->student.LName << " " << loggedinStudent->student.FName << "\tStudent ID: " << loggedinStudent->student.StudentID << endl;
			std::cout << "Gender: " << loggedinStudent->student.Gender << "\tDate of birth: "
				<< loggedinStudent->student.DoB.day / 10 << loggedinStudent->student.DoB.day % 10 << "/" << loggedinStudent->student.DoB.month / 10 << loggedinStudent->student.DoB.month % 10 << "/" << loggedinStudent->student.DoB.year << endl;
			std::cout << "Class name: " << loggedinStudent->student.Classes.name << "\tClass ID: " << loggedinStudent->student.Classes.ClassID << "\n\n";

			std::cout << "Enter select the option you want to choose: ";
			int choose;
			std::cin >> choose;
			std::cin.ignore();

			if (choose == 1) {
				string oldPass;
				string newPass;
				string newPassAgain;
				do {
					std::system("cls");
					std::cout << "Enter your old password: ";
					getline(std::cin, oldPass);
					if (loggedinStudent->student.Password != oldPass) {
						std::cout << "Your old password has been entered incorrectly. Please, enter again.\n";
						std::system("pause");
						continue;
					}
					else {
						std::cout << "Enter your new password: ";
						getline(std::cin, newPass);
						std::cout << "Enter your new password again: ";
						getline(std::cin, newPassAgain);
						if (newPass != newPassAgain) {
							std::cout << "Confirmation password is not correct. Please, enter again.\n";
							std::system("pause");
							continue;
						}
						loggedinStudent->student.Password = newPass;
						Read_After_Update_Students(student);
						std::cout << "Change password successfully.\n";
						std::system("pause");
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

