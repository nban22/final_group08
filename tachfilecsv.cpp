#include "header.h"

void tach_ra_tung_file_class(STU_NODE* student, CLASS_NODE* listclass) {
	STU_NODE* cur = student;
	CLASS_NODE* cur1 = listclass;
	int i = 1;
	while (cur1 != nullptr) {
		std::ofstream outfile("listclass/" + cur1->listclass.ClassID + ".csv");
		outfile << "No,Student ID,Last Name,First Name,Gender,Date Of Birth,Social ID";
		cur = student;
		i = 1;
		while (cur != nullptr) {
			if (cur->student.Classes.ClassID == cur1->listclass.ClassID) {
				outfile << "\n" << i++ << ","
					<< cur->student.StudentID << ","
					<< cur->student.LName << ","
					<< cur->student.FName << ","
					<< cur->student.Gender << ","
					<< cur->student.DoB.month << "/"
					<< cur->student.DoB.day << "/"
					<< cur->student.DoB.year << ","
					<< cur->student.SocialID;
			}
				cur = cur->next;
		}
		outfile.close();
		cur1 = cur1->next;
	}
}