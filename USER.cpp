#include "header.h"

using namespace std;

//*****************LOGIN/LOGOUT*****************

//STAFF
int checkExistOfStaffAccount(STFF_NODE*& head, std::string user, std::string password, STFF_NODE*& logged) {

	STFF_NODE* current = head;

	while (current) {
		if (user == current->staff.TeacherID && password == current->staff.Password) {
			logged = current;
			return 1;
		}
		else if (user == current->staff.TeacherID && password != current->staff.Password)
			return -1;
		else
			current = current->next;
	}
	return 0;
}

void print_Staffs(STFF_NODE* head) {
	STFF_NODE* cur = head;
	while (cur) {
		cout << cur->staff.No_Staff << " " << cur->staff.TeacherID << " " << cur->staff.LName << " " << cur->staff.FName << " " << cur->staff.Gender << " " << cur->staff.SocialID << " " << cur->staff.Faculty << "\n";
		cur = cur->next;
	}
} //for testing

void changePassWordOfStaffAccount(STFF_NODE*& staff, STFF_NODE*& loggedinStaff) {
	string oldPass;
	string newPass;
	string newPassAgain;
	do {
		system("cls");
		cout << "Enter your old password: ";
		getline(cin, oldPass);
		if (loggedinStaff->staff.Password != oldPass) {
			cout << "Your old password has been entered incorrectly. Please, enter again.\n\n";
			system("pause");
			continue;
		}
		else {
			cout << "Enter your new password: ";
			getline(cin, newPass);
			cout << "Enter your new password again: ";
			getline(cin, newPassAgain);
			if (newPass != newPassAgain) {
				cout << "Confirmation password is not correct. Please, enter again.\n\n";
				system("pause");
				continue;
			}
			loggedinStaff->staff.Password = newPass;
			Read_After_Update_Teachers(staff);
			cout << "Change password successfully.\n\n";
			system("pause");
			break;
		}
	} while (loggedinStaff->staff.Password != oldPass || newPass != newPassAgain);
}



//STUDENT
int checkExistOfStudentAccount(STU_NODE*& head, std::string user, std::string password, STU_NODE*& logged) {
	STU_NODE* current = head;

	while (current) {
		if (user == current->student.StudentID && password == current->student.Password) {
			logged = current;
			return 1;
		}
		else if (user == current->student.StudentID && password != current->student.Password)
			return -1;
		else
			current = current->next;
	}
	return 0;
}

void print_Students(STU_NODE* head) {
        STU_NODE* cur = head;
	while (cur) {
		cout << cur->student.No_Student << " " << cur->student.StudentID << " " << cur->student.LName << " " << cur->student.FName << " " << cur->student.Gender << " " << cur->student.SocialID <<  " " << cur->student.Classes.ClassID << " " << cur->student.Classes.name << "\n";
		cur = cur->next;
	}
} //for testing

void changePasswordOfStudentAccount(STU_NODE*& student, STU_NODE*& loggedinStudent) {
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
