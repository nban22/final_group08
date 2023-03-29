#include "header.h"

using namespace std;

//*****************LOGIN/LOGOUT*****************

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@STAFF@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
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

//============================view list of class============================
STU_NODE* checkExistClassIDinDLL(STU_NODE*& listclass, std::string classID) {
	STU_NODE* cur = listclass;
	while (cur) {
		if (cur->student.Classes.ClassID == classID)
			return cur;
		cur = cur->next;
	}
	return nullptr;
}
void deleteSTU_NODE(STU_NODE*& head) {
	STU_NODE* tmp = head;
	while (head) {
		tmp = head;
		head = head->next;
		delete tmp;
	}
}
void displayLISTOFCLASS(STU_NODE*& student, STU_NODE* listclass) {
	STU_NODE* cur_listclass = listclass;
	int i = 1;
	cout << "======================LIST OF CLASSES======================\n\n";
	cout << "\t" << setw(10) << left << "No" << setw(5) << left << "|"
		<< setw(20) << left << "Class ID" << setw(5) << left << "|"
		<< setw(50) << left << "Class name" << endl;
	cout << setfill('-') << setw(80) << "-" << setfill(' ') << endl;
	while (cur_listclass) {
		cout << "\t" << setw(10) << left << i++ << setw(5) << left << "|"
			<< setw(20) << left << cur_listclass->student.Classes.ClassID << setw(5) << left << "|"
			<< setw(50) << left << cur_listclass->student.Classes.name << endl;
		cur_listclass = cur_listclass->next;
	}
}

//============================view list of class============================ 
void displayListStudentsOfCourse(STU_NODE*& student, std::string classID) {
	STU_NODE* cur_student = student;
	int i = 1;
	cout << "============================================LIST STUDENTS OF CLASS============================================\n\n";
	cout << "     " << setw(5) << left << "No" << setw(5) << left << "|"
		<< setw(15) << left << "Student ID" << setw(5) << left << "|"
		<< setw(20) << left << "Last name" << setw(5) << left << "|"
		<< setw(10) << left << "First name" << setw(5) << left << "|"
		<< setw(10) << left << "Gender" << setw(5) << left << "|"
		<< setw(15) << left << "Date of birth" << setw(5) << left << "|"
		<< setw(30) << left << "social ID" << endl;
	cout << setfill('-') << setw(125) << "-" << setfill(' ') << endl;
	while (cur_student) {
		if (cur_student->student.Classes.ClassID == classID) {
			cout << "     " << setw(5) << left << i++ << setw(5) << left << "|"
				<< setw(15) << left << cur_student->student.StudentID << setw(5) << left << "|"
				<< setw(20) << left << cur_student->student.LName << setw(5) << left << "|"
				<< setw(10) << left << cur_student->student.FName << setw(5) << left << "|"
				<< setw(10) << left << cur_student->student.Gender << setw(5) << left << "|"
				<< cur_student->student.DoB.day / 10 << cur_student->student.DoB.day % 10 << "/"
				<< cur_student->student.DoB.month / 10 << cur_student->student.DoB.month % 10 << "/"
				<< setw(9) << left << cur_student->student.DoB.year << setw(5) << left << "|"
				<< setw(20) << left << cur_student->student.SocialID << endl;
		}
		cur_student = cur_student->next;
	}
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@STUDENT@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
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
