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

void lay_vao_file_newclass(CLASS_NODE* listclass, std::string Inputfile) {
	int width_tmp1 = 50;
	int height_tmp1 = 10;

	std::ifstream Input;
	Input.open(Inputfile);
	if (!Input.is_open()) {
		system("cls");
		my_print(width_tmp1, height_tmp1, RED, "File not found!");
		system("pause");
		return;
	}
	STU_NODE *student = new STU_NODE;

	std::string title;
	std::getline(Input, title);
	while (!Input.eof()) {
		std::string tmp;
		std::getline(Input, tmp, ',');
		student->student.No_Student = stoi(tmp);
		std::getline(Input, student->student.StudentID, ',');
		std::getline(Input, student->student.Password, ',');
		std::getline(Input, student->student.LName, ',');
		std::getline(Input, student->student.FName, ',');
		std::getline(Input, student->student.Gender, ',');
		std::getline(Input, tmp, '/');
		student->student.DoB.month = stoi(tmp);
		std::getline(Input, tmp, '/');
		student->student.DoB.day = stoi(tmp);
		std::getline(Input, tmp, ',');
		student->student.DoB.year = stoi(tmp);
		std::getline(Input, student->student.SocialID, ',');
		std::getline(Input, student->student.Classes.name, ',');
		std::getline(Input, tmp);
		std::getline(Input, tmp); // skip 2 line
		student->student.Classes.ClassID = listclass->listclass.ClassID;
		student->student.Classes.schoolYear = listclass->listclass.schoolYear;
		updateListClass(listclass, student);
		tach_ra_tung_file_class(student, listclass);
	}
	Input.close();

	delete student;
	return;
}

void lay_vao_file_oldclass(CLASS_NODE* listclass, std::string Inputfile) {
	int width_tmp1 = 50;
	int height_tmp1 = 10;

	std::ifstream Input;
	Input.open(Inputfile);
	if (!Input.is_open()) {
		system("cls");
		my_print(width_tmp1, height_tmp1, RED, "File not found!");
		system("pause");
		return;
	}
	STU_NODE* student = new STU_NODE;

	std::string title;
	std::getline(Input, title);
	while (!Input.eof()) {
		std::string tmp;
		std::getline(Input, tmp, ',');
		student->student.No_Student = stoi(tmp);
		std::getline(Input, student->student.StudentID, ',');
		std::getline(Input, student->student.Password, ',');
		std::getline(Input, student->student.LName, ',');
		std::getline(Input, student->student.FName, ',');
		std::getline(Input, student->student.Gender, ',');
		std::getline(Input, tmp, '/');
		student->student.DoB.month = stoi(tmp);
		std::getline(Input, tmp, '/');
		student->student.DoB.day = stoi(tmp);
		std::getline(Input, tmp, ',');
		student->student.DoB.year = stoi(tmp);
		std::getline(Input, student->student.SocialID, ',');
		std::getline(Input, student->student.Classes.name, ',');
		std::getline(Input, student->student.Classes.ClassID, ',');
		std::getline(Input, tmp);
		student->student.Classes.schoolYear = stoi(tmp);
		updateListClass(listclass, student);
	}
	Input.close();

	delete student;
	return;
}