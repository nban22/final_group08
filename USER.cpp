
#include "header.h"

//void printInformation_A_Staff(STFF_NODE* loggedinStaff) {
//	std::string fullname = loggedinStaff->staff.LName + " " + loggedinStaff->staff.FName;
//	std::string DoB = std::to_string(loggedinStaff->staff.DoB.day / 10) + std::to_string(loggedinStaff->staff.DoB.day % 10) + "/"
//		+ std::to_string(loggedinStaff->staff.DoB.month / 10) + std::to_string(loggedinStaff->staff.DoB.month % 10) + "/"
//		+ std::to_string(loggedinStaff->staff.DoB.year);
//	std::cout << std::setw(45) << std::right << "Teacher's information"
//		<< "\n\t" << std::setfill('*') << std::setw(55) << "*" << std::setfill(' ')
//		<< "\n\t" << std::setw(15) << std::left << "Full name : " << std::setw(40) << std::right << fullname
//		<< "\n\t" << std::setw(15) << std::left << "Teacher ID: " << std::setw(40) << std::right << loggedinStaff->staff.TeacherID
//		<< "\n\t" << std::setw(15) << std::left << "Gender: " << std::setw(40) << std::right << loggedinStaff->staff.Gender
//		<< "\n\t" << std::setw(15) << std::left << "Date of birth: " << std::setw(40) << std::right << DoB
//		<< "\n\t" << std::setw(15) << std::left << "Faculty: " << std::setw(40) << std::right << loggedinStaff->staff.Faculty << "\n\n";
//}
//
//
//void printInformation_A_Student(STU_NODE* loggedinStudent) {
//	std::string fullname = loggedinStudent->student.LName + " " + loggedinStudent->student.FName;
//	std::string DoB = std::to_string(loggedinStudent->student.DoB.day / 10) + std::to_string(loggedinStudent->student.DoB.day % 10) + "/"
//		+ std::to_string(loggedinStudent->student.DoB.month / 10) + std::to_string(loggedinStudent->student.DoB.month % 10) + "/"
//		+ std::to_string(loggedinStudent->student.DoB.year);
//
//	std::cout << std::setw(45) << std::right << "Student's information"
//		<< "\n\t" << std::setfill('*') << std::setw(55) << "*" << std::setfill(' ')
//		<< "\n\t" << std::setw(15) << std::left << "Full name : " << std::setw(40) << std::right << fullname
//		<< "\n\t" << std::setw(15) << std::left << "Teacher ID: " << std::setw(40) << std::right << loggedinStudent->student.StudentID
//		<< "\n\t" << std::setw(15) << std::left << "Gender: " << std::setw(40) << std::right << loggedinStudent->student.Gender
//		<< "\n\t" << std::setw(15) << std::left << "Date of birth: " << std::setw(40) << std::right << DoB
//		<< "\n\t" << std::setw(15) << std::left << "Class ID: " << std::setw(40) << std::right << loggedinStudent->student.Classes.ClassID
//		<< "\n\t" << std::setw(15) << std::left << "Class name: " << std::setw(40) << std::right << loggedinStudent->student.Classes.name << "\n\n";
//}
//
//char GetRanking(float Grade) {
//	if (Grade >= 90 && Grade <= 100)
//		return 'A';
//	else if (Grade >= 80 && Grade <= 89)
//		return 'B';
//	else if (Grade >= 70 && Grade <= 79)
//		return 'C';
//	else if (Grade >= 60 && Grade <= 69)
//		return 'D';
//	else if (Grade >= 0 && Grade <= 59)
//		return 'F';
//	else
//		return 'E';
//}