#include "header.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	ifstream input;
	STFF_NODE* staff = nullptr;
	getDataTeachers_csv(input, staff);
	//print_Staffs(staff);  //for testing
	//system("pause");

	//ACCOUNT TO TEST RUN: 
	//USER:   24061530
	//PASSWORD:    123456

	ifstream input_S;
	STU_NODE* student = nullptr;
	getDataStudents_csv(input_S, student);

	STAFF loggedinStaff;
	STUDENT loggedinStudent;

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
				cout << "Logged in successfully.\n";
				system("pause");
				continue;
			}
			if (check_T == -1 || check_S == -1) {
				cout << "Your password isn't correct. Please, enter again.\n";
				system("pause");
				continue;
			}
			if (check_T == 0 || check_S == 0) {
				cout << "Your account doesn't exist. Please, enter again.\n";
				system("pause");
			}
		} while (!(check_T == 1 || check_S == 1));

		//THE FUNCTIONS OF STAFF
		while (check_T == 1) {
			system("cls");

			cout << "======================TEACHER======================";
			cout << "\n\t1. Change password.\n"
				<< "\t2. Update your persinal information.\n"
				<< "\t3. Create a school year.\n"
				<< "\t4. Add new 1st year students to 1st year classes.\n"
				<< "\t5. Create a course registration session.\n"
				<< "\t6. Export list of student in a course.\n"
				<< "\t7. Enter and view the scoreboard of a course.\n"
				<< "\t8. View the scoreboard of a course.\n"
				<< "\t9. Import the scoreboard of a course.\n"
				<< "\t10. Update a student result.\n"
				<< "\t11. View the scoreboard of a class.\n"
				<< "\t0. Log out.\n"
				<< "\t-1. Exit\n";
			cout << "========================END========================\n\n";

			cout << "Teacher.\n";
			cout << "Numerical order: " << loggedinStaff.No_Staff << endl;
			cout << "Full name: " << loggedinStaff.LName << " " << loggedinStaff.FName << "\tTeacher ID: " << loggedinStaff.TeacherID << endl;
			cout << "Gender: " << loggedinStaff.Gender << "\tDate of birth: " << loggedinStaff.DoB.day << "/" << loggedinStaff.DoB.month << "/" << loggedinStaff.DoB.year << endl;
			cout << "Faculty: " << loggedinStaff.Faculty << "\n\n";

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
					if (loggedinStaff.Password != oldPass) {
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
						cout << "Change password successfully.\n";
						system("pause");
					}
				} while (loggedinStaff.Password != oldPass || newPass != newPassAgain);

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
			else if (choose == 9) {

			}
			else if (choose == 10) {

			}
			else if (choose == 11) {

			}
			else if (choose == 0) {
				break;
			}
			else if (choose == -1) {
				system("pause");
				return 0;
			}
			else {
				cout << "Invalid selection, please enter again.\n";
				system("pause");
			}
		}

		//THE FUNCTIONS OF STUDENT
		while (check_S == 1) {
			system("cls");
			cout << "======================STUDENT======================";
			cout << "\n1. Change password.\n"
				<< "2. Update your personal information.\n"
				<< "3. Register for the course.\n"
				<< "4. View your schedule.\n"
				<< "5. View your scoraboard."
				<< "6. View list of student in a course.\n"
				<< "7. View of classes.\n"
				<< "8. View list of student in a class.\n"
				<< "0. Log out.\n"
				<< "-1. Exit.\n";
			cout << "========================END========================\n";

			cout << "Student.\n";
			cout << "Numerical order: " << loggedinStudent.No_Student << endl;
			cout << "Full name: " << loggedinStudent.LName << " " << loggedinStudent.FName << "\tStudent ID: " << loggedinStudent.StudentID << endl;
			cout << "Gender: " << loggedinStudent.Gender << "\tDate of birth: " << loggedinStudent.DoB.day << "/" << loggedinStudent.DoB.month << "/" << loggedinStudent.DoB.year << endl;
			cout << "Class name: " << loggedinStudent.Classes.name << "\tClass ID: " << loggedinStudent.Classes.ClassID << "\n\n";

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
					if (loggedinStudent.Password != oldPass) {
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
						cout << "Change password successfully.\n";
						system("pause");
					}
				} while (loggedinStudent.Password != oldPass || newPass != newPassAgain);
				


				
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
				cout << "Invalid selection, please enter again.\n";
				system("pause");
			}

		}
	}
}