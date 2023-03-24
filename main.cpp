#include "header.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int count;

	ifstream input;
	STFF_NODE* staff = nullptr; 
	getDataTeachers_csv(input, staff);
	//STFF_NODE* staff2 = staff;
	//print_Staffs(staff);  //for testing
	//system("pause");

	//ACCOUNT TO TEST RUN: 
	//USER:   24061530
	//PASSWORD:    123456

	ifstream input_S;
	STU_NODE* student = nullptr;
	getDataStudents_csv(input_S, student);
	/*STU_NODE* student2 = student;*/

	ifstream input_C;
	CR_NODE* course = nullptr;
	STU_COURSE_NODE *stu_course = nullptr;
	getDataCourse_csv(input_C, course);
	WriteRegisterStuDefault(course, student, stu_course);

	STFF_NODE* loggedinStaff = new STFF_NODE;
	STU_NODE* loggedinStudent = new STU_NODE;

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
			cout << "Numerical order: " << loggedinStaff->staff.No_Staff << endl;
			cout << "Full name: " << loggedinStaff->staff.LName << " " << loggedinStaff->staff.FName << "\tTeacher ID: " << loggedinStaff->staff.TeacherID << endl;
			cout << "Gender: " << loggedinStaff->staff.Gender << "\tDate of birth: " 
				<< loggedinStaff->staff.DoB.day << "/" << loggedinStaff->staff.DoB.month << "/" << loggedinStaff->staff.DoB.year << endl;
			cout << "Faculty: " << loggedinStaff->staff.Faculty << "\n\n";

			cout << "Enter select the option you want to choose: ";
			int choose;
			cin >> choose;
			cin.ignore();

			if (choose == 1) {
				changePassWordOfStaffAccount(staff, loggedinStaff);
			}
			else if (choose == 2) {

			}
			else if (choose == 3) {

			}
			else if (choose == 4) {

			}
			else if (choose == 5) {
				DisplayMenu(choose);
			}
			else if (choose == 6) {

			}
			else if (choose == 7) {
				system("cls");
				cout << "\n\t\t\t ********************************************" << endl;
				cout << "\t\t\t\t      ";
				cout << "Enter the scoreboard of a course." << endl;
				string student_id;
				cout << "what is the id of the student?" << endl;
				cin >> student_id;
				EnterCourseScore(student_id, stu_course, course);
				Read_After_Update_CourseStudents(stu_course);
				count = 7;
				system("pause");
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
				cout << "Invalid selection, please enter again.\n\n";
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

		