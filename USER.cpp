#include "header.h"

using namespace std;

//****************LOGIN/LOGOUT*****************

//STAFF
void LoginStaff(std::string Username, std::string Pass, STFF_NODE* head) {
	STFF_NODE* cur = head;
	while (cur) {
		if ((Username.compare(cur->staff.TeacherID) == 0) && (Pass.compare(cur->staff.Password) == 0)) {
			cout << "LOGIN SUCCESS";
			//********RUN THE PROGRAM*********
		} 
		cur = cur->next;
	}
}

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




//STUDENT
void LoginStudent(std::string Username, std::string Pass, STU_NODE* head) {
	STU_NODE* cur = head;
	while (cur) {
		if ((Username.compare(cur->student.StudentID) == 0) && (Pass.compare(cur->student.Password) == 0)) {
			cout << "LOGIN SUCCESS";
			//********RUN THE PROGRAM*********
		} 
		cur = cur->next;
	}
}
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


