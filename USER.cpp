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
