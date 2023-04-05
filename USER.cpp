#include "header.h"

using namespace std;

//*****************LOGIN/LOGOUT*****************

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@STAFF@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//menu teacher
void printInformation_A_Staff(STFF_NODE* loggedinStaff) {
	string fullname = loggedinStaff->staff.LName + " " + loggedinStaff->staff.FName;
	string DoB = to_string(loggedinStaff->staff.DoB.day / 10) + to_string(loggedinStaff->staff.DoB.day % 10) + "/"
		+ to_string(loggedinStaff->staff.DoB.month / 10) + to_string(loggedinStaff->staff.DoB.month % 10) + "/"
		+ to_string(loggedinStaff->staff.DoB.year);

	std::cout << setw(45) << right << "Teacher's information"
		<< "\n\t" << setfill('*') << setw(55) << "*" << setfill(' ')
		<< "\n\t" << setw(15) << left << "Full name : " << setw(40) << right << fullname
		<< "\n\t" << setw(15) << left << "Teacher ID: " << setw(40) << right << loggedinStaff->staff.TeacherID
		<< "\n\t" << setw(15) << left << "Gender: " << setw(40) << right << loggedinStaff->staff.Gender
		<< "\n\t" << setw(15) << left << "Date of birth: " << setw(40) << right << DoB
		<< "\n\t" << setw(15) << left << "Faculty: " << setw(40) << right << loggedinStaff->staff.Faculty << "\n\n";
}

//2 - nter information - 1.Add new 1st year students to 1st year classes.
void addNew1styearStudent(STU_NODE*& student) {
	STU_NODE* new_student = new STU_NODE;
	bool check;
	STU_NODE* cur_student = student;
	do {
		check = 0;
		std::system("cls");
		viewListOfClasses(cur_student);
		cout << "Enter student's class id: ";
		getline(cin, new_student->student.Classes.ClassID);
		cur_student = student;
		while (cur_student) {
			if (cur_student->student.Classes.ClassID == new_student->student.Classes.ClassID)
				check = 1;
			cur_student = cur_student->next;
		}
		if (check == 0) {
			cout << "Your class ID which you entered it does not exist.\n";
			cout << "\nSearch for Course again? (y/n)";
			char ans;
			cin >> ans;
			cin.ignore();
			if (ans == 'y' || ans == 'Y') {
				addNew1styearStudent(student);
			}
			else {
				return;
			}
		}
	} while (check == 0);
	cout << "Enter student's last name: ";
	getline(cin, new_student->student.LName);
	cout << "Enter student's first name: ";
	getline(cin, new_student->student.FName);
	cout << "Enter student's gender: ";
	getline(cin, new_student->student.Gender);
	cout << "Enter student's date of birth: (dd mm yyyy): ";
	cin >> new_student->student.DoB.day >> new_student->student.DoB.month >> new_student->student.DoB.year;
	cin.ignore();
	cout << "Enter student's social ID: ";
	getline(cin, new_student->student.SocialID);

	system("cls");
	cur_student = student;
	check = 0;
	while (cur_student->next) {
		if (cur_student->student.Classes.ClassID == new_student->student.Classes.ClassID) {
			check = 1;
			new_student->student.Classes.name = cur_student->student.Classes.name;
		}
		if (check == 1 && cur_student->next->student.Classes.name != new_student->student.Classes.name)
			break;
		cur_student = cur_student->next;
	}
	new_student->student.StudentID = to_string(stoi(cur_student->student.StudentID) + 1);
	new_student->student.Password = "678910";

	system("cls");
	cout << "Information of new student is: \n";
	cout << "ID: " << new_student->student.StudentID
		<< "\nPassword: " << new_student->student.Password
		<< "\nFull name: " << new_student->student.LName << " " << new_student->student.FName
		<< "\nDate of birth: " << new_student->student.DoB.day << "/" << new_student->student.DoB.month << "/" << new_student->student.DoB.year
		<< "\nSocial ID: " << new_student->student.SocialID
		<< "\nClass name: " << new_student->student.Classes.name
		<< "\nClass ID: " << new_student->student.Classes.ClassID << endl;
	system("pause");

	new_student->next = cur_student->next;
	new_student->prev = cur_student;
	if (cur_student->next != nullptr)
		cur_student->next->prev = new_student;
	cur_student->next = new_student;


	int i = 1;
	cur_student = student;
	while (cur_student) {
		cur_student->student.No_Student = i++;
		cur_student = cur_student->next;
	}
	Read_After_Update_Students(student);
}

//============================ view list of class============================ 
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
void viewListOfClasses(STU_NODE* student) {
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
	deleteSTU_NODE(listclass);
}

//============================ List of students in class============================ 
void viewListStudentsOfClass(STU_NODE* student) {
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

//============================ List of courses============================ 
void viewListOfCourses(CR_NODE* course) {
	CR_NODE* cur_course = course;
	cout << "============================================LIST OF COURSES============================================\n\n";
	std::cout << setw(5) << left << " " << setw(5) << left << "No" << setw(5) << left << "|"
		<< setw(10) << left << "Course ID" << setw(5) << left << "|"
		<< setw(30) << left << "Course name" << setw(5) << left << "|"
		<< setw(25) << left << "Teacher name" << setw(5) << left << "|"
		<< setw(10) << left << "Credits" << setw(5) << left << "|"
		<< setw(10) << left << "Registered" << setw(5) << left << "|"
		<< setw(20) << left << "Calendar" << endl;
	std::cout << setfill('-') << setw(140) << left << "-" << setfill(' ') << endl;
	while (cur_course) {
		string fullname = cur_course->course.LNameTeacher + " " + cur_course->course.FNameTeacher;
		string registered = to_string(cur_course->course.Cur_stdn) + "/" + to_string(cur_course->course.Max_stdn);
		cout << setw(5) << left << " " << setw(5) << left << cur_course->course.No << setw(5) << left << "|"
			<< setw(10) << left << cur_course->course.ID << setw(5) << left << "|"
			<< setw(30) << left << cur_course->course.CName << setw(5) << left << "|"
			<< setw(25) << left << fullname << setw(5) << left << "|"
			<< setw(10) << left << cur_course->course.Credits << setw(5) << left << "|"
			<< setw(10) << left << registered << setw(5) << left << "|"
			<< ConvertStringWD(cur_course->course.dayOfWeek) << "-" << ConvertStringSS(cur_course->course.session) << endl;

		cur_course = cur_course->next;
	}
}

//============================view list of teachers============================

void ViewListOfTeachers(STFF_NODE* teacher) {
	STFF_NODE* cur = teacher;
	system("cls");
	
	cout << "============================================LIST OF TEACHERS ============================================\n\n";
	std::cout << setw(5) << left << " " << setw(5) << left << "No" << setw(5) << left << "|"
		<< setw(15) << left << "Teachers ID" << setw(5) << left << "|"
		<< setw(20) << left << "Teacher's last name" << setw(5) << left << "|"
		<< setw(20) << left << "Teacher's first name" << setw(5) << left << "|"
		<< setw(10) << left << "Gender" << setw(5) << left << "|"
		<< setw(20) << left << "Day of Birth" << setw(5) << left << "|"
		<< setw(20) << left << "Social ID" << setw(5) << left << "|"
		<< setw(40) << left << "Faculty" << setw(5) << left << "|" << endl;
	std::cout << setfill('-') << setw(190) << left << "-" << setfill(' ') << "\n";

	while (cur) {
		string birthday = to_string(cur->staff.DoB.day) + "/" + to_string(cur->staff.DoB.month) + "/" + to_string(cur->staff.DoB.year);
		cout << setw(5) << left << " " << setw(5) << left << cur->staff.No_Staff << setw(5) << left << "|"
			<< setw(15) << left << cur->staff.TeacherID << setw(5) << left << "|"
			<< setw(20) << left << cur->staff.LName << setw(5) << left << "|"
			<< setw(20) << left << cur->staff.FName << setw(5) << left << "|"
			<< setw(10) << left << cur->staff.Gender << setw(5) << left << "|"
			<< setw(20) << left << birthday << setw(5) <<  "|"
			<< setw(20) << left << cur->staff.SocialID << setw(5) << left << "|"
			<< setw(40) << left << cur->staff.Faculty << setw(5) << left << "|" << endl;
		cur = cur->next;
	}
}

//============================ List of students in course============================4 
void viewListStudentsOfCourse(STU_COURSE_NODE* stu_course, STU_NODE* student, std::string CourseID) {
	STU_COURSE_NODE* cur = stu_course;
	int i = 1;
	cout << "============================================LIST STUDENTS OF " << CourseID << "============================================\n\n";
	std::cout << setw(5) << left << " " << setw(5) << left << "No" << setw(5) << left << "|"
		<< setw(15) << left << "Student ID" << setw(5) << left << "|"
		<< setw(30) << left << "Student's name" << setw(5) << left << "|"
		<< setw(10) << left << "Gender" << setw(5) << left << "|"
		<< setw(15) << left << "Date of birth" << setw(5) << left << "|"
		<< setw(20) << left << "Social ID" << std::endl;
	std::cout << setfill('-') << setw(120) << left << "-" << setfill(' ') << "\n";
	while (cur) {
		if (cur->stu_course.CouID == CourseID) {
			STU_NODE* tmp = getInformationByStudentID(cur->stu_course.StuID, student);
			string DoB = to_string(tmp->student.DoB.day / 10) + to_string(tmp->student.DoB.day % 10) + "/"
				+ to_string(tmp->student.DoB.month / 10) + to_string(tmp->student.DoB.month % 10) + "/"
				+ to_string(tmp->student.DoB.year);
			string fullname = tmp->student.LName + " " + tmp->student.FName;
			std::cout << "\n" << setw(5) << left << " " << setw(5) << left << i++ << setw(5) << left << "|"
				<< setw(15) << left << cur->stu_course.StuID << setw(5) << left << "|"
				<< setw(30) << left << fullname << setw(5) << left << "|"
				<< setw(10) << left << tmp->student.Gender << setw(5) << left << "|"
				<< setw(15) << left << DoB << setw(5) << left << "|"
				<< setw(20) << left << tmp->student.SocialID;
		}
		cur = cur->next;
	}
	std::cout << "\n";
}

//============================view list of students in a course============================ 
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

//============================view a scoreboard in a course============================ 
void viewScoreBoard_Course(STU_COURSE_NODE* stu_course, STU_NODE* student, std::string CourseID) {
	int i = 1;
	STU_COURSE_NODE* cur = stu_course;
	cout << "============================================A SCOREBOARD IN COURSE " << CourseID << "============================================\n\n";
	std::cout << setw(5) << left << " " << setw(5) << left << "No" << setw(5) << left << "|"
		<< setw(10) << left << "Student ID" << setw(5) << left << "|"
		<< setw(25) << left << "Last name" << setw(5) << left << "|"
		<< setw(15) << left << "Firse name" << setw(5) << left << "|"
		<< setw(15) << left << "Other Mark" << setw(5) << left << "|"
		<< setw(15) << left << "Midterm Mark" << setw(5) << left << "|"
		<< setw(15) << left << "Final Mark" << setw(5) << left << "|"
		<< setw(15) << left << "Total Mark" << endl;
	std::cout << setfill('-') << setw(153) << left << "-" << setfill(' ') << endl;
	while (cur) {
		if (cur->stu_course.CouID == CourseID) {
			STU_NODE* tmp = getInformationByStudentID(cur->stu_course.StuID, student);
			std::cout << setw(5) << left << " " << setw(5) << left << i++ << setw(5) << left << "|"
				<< setw(10) << left << cur->stu_course.StuID << setw(5) << left << "|"
				<< setw(25) << left << tmp->student.LName << setw(5) << left << "|"
				<< setw(15) << left << tmp->student.FName << setw(5) << left << "|"
				<< setw(15) << left << cur->stu_course.other << setw(5) << left << "|"
				<< setw(15) << left << cur->stu_course.midterm << setw(5) << left << "|"
				<< setw(15) << left << cur->stu_course.final << setw(5) << left << "|"
				<< setw(15) << left << cur->stu_course.total << endl;
		}
		cur = cur->next;
	}
}

void viewScoreBoard_Class(STU_COURSE_NODE* stu_course, STU_NODE* student, std::string ClassID) {
	int i = 1;
	STU_NODE* cur_student = student;
	STU_COURSE_NODE* cur = stu_course;
	cout << "============================================A SCOREBOARD IN CLASS " << ClassID << "============================================\n\n";
	std::cout << setw(5) << left << " " << setw(5) << left << "No" << setw(5) << left << "|"
		<< setw(10) << left << "Student ID" << setw(5) << left << "|"
		<< setw(25) << left << "Last name" << setw(5) << left << "|"
		<< setw(15) << left << "Firse name" << setw(5) << left << "|"
		<< setw(25) << left << "Subject" << setw(5) << left << "|"
		<< setw(15) << left << "Mark" << endl;
	std::cout << setfill('-') << setw(125) << left << "-" << setfill(' ') << endl;
	while (cur_student) {
		if (cur_student->student.Classes.ClassID == ClassID) {
			float GPA = 0;
			int count = 0;
			while (cur->stu_course.StuID == cur_student->student.StudentID) {
				std::cout << setw(5) << left << " " << setw(5) << left << " " << setw(5) << left << "|"
					<< setw(10) << left << " " << setw(5) << left << "|"
					<< setw(25) << left << " " << setw(5) << left << "|"
					<< setw(15) << left << " " << setw(5) << left << "|"
					<< setw(25) << left << cur->stu_course.Cname << setw(5) << left << "|"
					<< setw(15) << left << cur->stu_course.total << endl;
				GPA += cur->stu_course.total;
				count++;
				cur = cur->next;
			}
			if (count == 0)
				std::cout << setw(5) << left << " " << setw(5) << left << i++ << setw(5) << left << "|"
				<< setw(10) << left << cur_student->student.StudentID << setw(5) << left << "|"
				<< setw(25) << left << cur_student->student.LName << setw(5) << left << "|"
				<< setw(15) << left << cur_student->student.FName << setw(5) << left << "|"
				<< setw(25) << left << "GPA of this semester" << setw(5) << left << "|"
				<< setw(15) << left << fixed << setprecision(2) << 0 << endl;
			else
				std::cout << setw(5) << left << " " << setw(5) << left << i++ << setw(5) << left << "|"
				<< setw(10) << left << cur_student->student.StudentID << setw(5) << left << "|"
				<< setw(25) << left << cur_student->student.LName << setw(5) << left << "|"
				<< setw(15) << left << cur_student->student.FName << setw(5) << left << "|"
				<< setw(25) << left << "GPA of this semester" << setw(5) << left << "|"
				<< setw(15) << left << fixed << setprecision(2) << GPA / count << endl;
			std::cout << setfill('-') << setw(125) << left << "-" << setfill(' ') << endl;
		}
		cur_student = cur_student->next;
	}
}
void View_Y_Scoraboard(STU_COURSE_NODE* stu_course, STU_NODE* loggedinStudent) {
	STU_COURSE_NODE* current = stu_course;
	while (current != nullptr) {
		if (current->stu_course.StuID == loggedinStudent->student.StudentID) {
			std::cout << "CourseID: " << current->stu_course.CouID << std::endl;
			std::cout << "CourseName: " << current->stu_course.Cname << std::endl;
			std::cout << "Mid-term Score: " << current->stu_course.midterm << std::endl;
			std::cout << "Final Score: " << current->stu_course.final << std::endl;
			std::cout << "Total Score: " << current->stu_course.total << std::endl;
		}
		current = current->next;
	}
}





void ExportScoreBoard(STU_COURSE_NODE* stu_course, CR_NODE* course, STU_NODE* student) {
Here:
	system("cls");
	viewListOfCourses(course);

	cout << "\n\n\t1. Export all the courses. ";
	cout << "\n\t2. Export only a course. ";
	cout << "\n\t0. Come back. ";
	cout << "\nEnter select the option you want to choose: ";
	int choice;
	cin >> choice;
	CR_NODE* cur_course = course;
	STU_COURSE_NODE* cur_stu_course = stu_course;
	int count = 0;
	int check = 0;
	std::string courseID = "0";

	if (choice == 1) {
		while (cur_course) {
			ofstream output;
			cur_stu_course = stu_course;
			int i = 1;

			output.open("Scoreboard_K22_2_" + cur_course->course.ID + ".csv");

			if (!output.is_open()) {
				cout << "cannot open file " << endl;
				return;
			}

			output << "No,ID,Last Name,First Name,Other Mark,Midterm Mark,Final Mark,Total Mark";

			while (cur_stu_course) {
				if (cur_stu_course->stu_course.CouID == cur_course->course.ID) {
					STU_NODE* tmp = getInformationByStudentID(cur_stu_course->stu_course.StuID, student);
					output << "\n" << i++ << ",";
					output << cur_stu_course->stu_course.StuID << ","
						<< tmp->student.LName << ","
						<< tmp->student.FName << ","
						<< cur_stu_course->stu_course.other << ","
						<< cur_stu_course->stu_course.midterm << ","
						<< cur_stu_course->stu_course.final << ","
						<< cur_stu_course->stu_course.total;
				}
				cur_stu_course = cur_stu_course->next;
			}
			output.close();
			cur_course = cur_course->next;
		}
	}
	else if (choice == 2) {
		ofstream output;
		int i = 1;
		cur_course = course;
		system("cls");
		viewListOfCourses(cur_course);
		cout << "\n\nEnter ID of the course you want to export: ";
		cin >> courseID;
		while (cur_course) {
			if (cur_course->course.ID == courseID) {
				check = 1;
				break;
			}
			cur_course = cur_course->next;
		}
		if (check == 0) {
			cout << "Your course ID which you entered does not exist.\n";
			cout << "\nSearch for Course again? (y/n)";
			char ans;
			cin >> ans;
			cin.ignore();
			if (ans == 'y' || ans == 'Y') {
				ExportScoreBoard(stu_course, course, student);
			}
			else {
				return;
			}
		}
		else {
			output.open("Scoreboard_K22_2_" + cur_course->course.ID + ".csv");
			if (!output.is_open()) {
				cout << "cannot open file " << endl;
				return;
			}
			output << "No,ID,Last Name,First Name,Other Mark,Midterm Mark,Final Mark,Total Mark";

			while (cur_stu_course) {
				if (cur_stu_course->stu_course.CouID == courseID) {
					STU_NODE* tmp = getInformationByStudentID(cur_stu_course->stu_course.StuID, student);
					output << "\n" << i++ << ",";
					output << cur_stu_course->stu_course.StuID << ","
						<< tmp->student.LName << ","
						<< tmp->student.FName << ","
						<< cur_stu_course->stu_course.other << ","
						<< cur_stu_course->stu_course.midterm << ","
						<< cur_stu_course->stu_course.final << ","
						<< cur_stu_course->stu_course.total;
				}
				cur_stu_course = cur_stu_course->next;
			}
			output.close();
		}
	}
	else if (choice == 0)
		return;
	else {
		cout << "your choice is invalid, pleasre choose again" << endl;
		system("pause");
		goto Here;
	}
	system("cls");
	cout << "Export finished" << endl;
	system("pause");
}

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
			Read_After_Update_Staffs(staff);
			cout << "Change password successfully.\n\n";
			system("pause");
			break;
		}
	} while (loggedinStaff->staff.Password != oldPass || newPass != newPassAgain);
}



//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@STUDENT@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


void printInformation_A_Student(STU_NODE* loggedinStudent) {
	string fullname = loggedinStudent->student.LName + " " + loggedinStudent->student.FName;
	string DoB = to_string(loggedinStudent->student.DoB.day / 10) + to_string(loggedinStudent->student.DoB.day % 10) + "/"
		+ to_string(loggedinStudent->student.DoB.month / 10) + to_string(loggedinStudent->student.DoB.month % 10) + "/"
		+ to_string(loggedinStudent->student.DoB.year);

	std::cout << setw(45) << right << "Student's information"
		<< "\n\t" << setfill('*') << setw(55) << "*" << setfill(' ')
		<< "\n\t" << setw(15) << left << "Full name : " << setw(40) << right << fullname
		<< "\n\t" << setw(15) << left << "Teacher ID: " << setw(40) << right << loggedinStudent->student.StudentID
		<< "\n\t" << setw(15) << left << "Gender: " << setw(40) << right << loggedinStudent->student.Gender
		<< "\n\t" << setw(15) << left << "Date of birth: " << setw(40) << right << DoB
		<< "\n\t" << setw(15) << left << "Class ID: " << setw(40) << right << loggedinStudent->student.Classes.ClassID
		<< "\n\t" << setw(15) << left << "Class name: " << setw(40) << right << loggedinStudent->student.Classes.name << "\n\n";
}

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

void ViewSchedule(STU_COURSE_NODE* stu_course, STU_NODE* loggedinStudent, CR_NODE* course) {
	STU_COURSE_NODE* cur_stu_course = stu_course;
	CR_NODE* cur_course = course;
	int count = 0;

	system("cls");

	cout << "============================================YOUR COURSES============================================\n\n";
	std::cout << setw(5) << left << " " << setw(5) << left << "No" << setw(5) << left << "|"
		<< setw(10) << left << "Course ID" << setw(5) << left << "|"
		<< setw(30) << left << "Course name" << setw(5) << left << "|"
		<< setw(25) << left << "Teacher name" << setw(5) << left << "|"
		<< setw(10) << left << "Credits" << setw(5) << left << "|"
		<< setw(10) << left << "Registered" << setw(5) << left << "|"
		<< setw(20) << left << "Calendar" << endl;
	std::cout << setfill('-') << setw(140) << left << "-" << setfill(' ') << endl;

	while (cur_stu_course) {
		if (cur_stu_course->stu_course.StuID == loggedinStudent->student.StudentID) {

			string registered = to_string(cur_course->course.Cur_stdn) + "/" + to_string(cur_course->course.Max_stdn);
			string fullname = cur_course->course.LNameTeacher + " " + cur_course->course.FNameTeacher;

			cout << setw(5) << left << " " << setw(5) << left << cur_course->course.No << setw(5) << left << "|"
				<< setw(10) << left << cur_course->course.ID << setw(5) << left << "|"
				<< setw(30) << left << cur_course->course.CName << setw(5) << left << "|"
				<< setw(25) << left << fullname << setw(5) << left << "|"
				<< setw(10) << left << cur_course->course.Credits << setw(5) << left << "|"
				<< setw(10) << left << registered << setw(5) << left << "|"
				<< ConvertStringWD(cur_course->course.dayOfWeek) << "-" << ConvertStringSS(cur_course->course.session) << endl;
			count++;
		}
		cur_course = cur_course->next;
		cur_stu_course = cur_stu_course->next;
	}
	if (count == 0) {
		cout << "You haven't registered any course " << endl;
	}
	system("pause");
	return;
}

void DeleteRegisteredCourse(STU_COURSE_NODE*& stu_course, STU_NODE* loggedinStudent, CR_NODE* course) {
	system("cls");
	char check;
	string courseID;
	STU_COURSE_NODE* cur_stu_node = stu_course;
	CR_NODE* cur_course = course;
	ViewSchedule(stu_course, loggedinStudent, course);
	cout << "\n\n";
	cout << "Enter the ID of the course you want to delete: ";
	cin >> courseID;

	while (cur_stu_node) {
		if (cur_stu_node->stu_course.CouID == courseID && cur_stu_node->stu_course.StuID == loggedinStudent->student.StudentID) {
			cout << "Are you sure you want to delete this course? (y/n): ";
			cin >> check;
			if (check == 'y' || check == 'Y') {
				STU_COURSE_NODE* tmp = new STU_COURSE_NODE;
				tmp = cur_stu_node;
				if (tmp == stu_course) {
					stu_course = stu_course->next;
					stu_course->prev = nullptr;
					delete tmp;
				}
				else {
					tmp->prev->next = tmp->next;
					tmp->next->prev = tmp->prev;
					cur_stu_node = cur_stu_node->prev;
					delete tmp;
				}
				system("cls");
				cout << "Delete successfully" << endl;
				system("pause");
				return;
			}
			else
				return;
		}
		else
			cur_stu_node = cur_stu_node->next;
	}
	cout << "The course ID you entered is incorrect" << endl;
	system("pause");
	return;
}


//Update student
void UpdateStudentInfo(STU_NODE*& student, STU_NODE*& loggedinStudent) {
	system("cls");
	cout << "\tUpdate your personal information."
		<< "\n\t1. Update your gender."
		<< "\n\t2. Update your date of birth."
		<< "\n\t3. Update your social ID."
		<< "\n\t0. Come back.";
	cout << "\n\nEnter select the option you want to choose: ";
	int choose;
	std::cin >> choose;
	std::cin.ignore();

	if (choose == 1) {
		cout << "\nEnter gender which you want to update: ";
		cin.ignore();
		getline(cin, loggedinStudent->student.Gender);
		Read_After_Update_Students(student);
		UpdateStudentInfo(student, loggedinStudent);
	}
	else if (choose == 2) {
		cout << "\nEnter date of birth which you want to update (dd mm yyyy): ";
		cin >> loggedinStudent->student.DoB.day >> loggedinStudent->student.DoB.month >> loggedinStudent->student.DoB.year;
		Read_After_Update_Students(student);
		UpdateStudentInfo(student, loggedinStudent);
	}
	else if (choose == 3) {
		cout << "\nEnter social ID which you want to update: ";
		cin.ignore();
		getline(cin, loggedinStudent->student.SocialID);
		Read_After_Update_Students(student);
		UpdateStudentInfo(student, loggedinStudent);
	}
	else if (choose == 0) {
		return;
	}
	else {
		std::cout << "Invalid selection, please enter again.\n\n";
		std::system("pause");
		UpdateStudentInfo(student, loggedinStudent);
	}
}

void UpdateTeacherInfor(std::string teacherID, STFF_NODE*& teacher) {
	STFF_NODE* cur = teacher;
	int check = 0;
	system("cls");

	while (cur) {
		if (cur->staff.TeacherID == teacherID) {
			check = 1;
			break;
		}
		cur = cur->next;
	}
	
	if (check == 0) {
		cout << "Your ID is invalid, please type again" << endl;
		return;
	}

	printInformation_A_Staff(cur);
	cout << "\n\nWhat do you want to update? " << endl;

	int choice;
	cout << "\n\t1. Update gender."
		<< "\n\t2. Update date of birth."
		<< "\n\t3. Update social ID."
		<< "\n\t4. Update Faculty."
		<< "\n\t0. Come back.";
	cout << "\n\nEnter select the option you want to choose: ";
	cin >> choice;

	if (choice == 1) {
		cout << "\nEnter gender which you want to update: ";
		cin.ignore();
		getline(cin, cur->staff.Gender);
		Read_After_Update_Teachers(teacher);
		UpdateTeacherInfor(teacherID, teacher);
	}
	else if (choice == 2) {
		cout << "\nEnter date of birth which you want to update (dd mm yyyy): ";
		cin >> cur->staff.DoB.day >> cur->staff.DoB.month >> cur->staff.DoB.year;
		Read_After_Update_Teachers(teacher);
		UpdateTeacherInfor(teacherID, teacher);
	}
	else if (choice == 3) {
		cout << "\nEnter social ID which you want to update: ";
		cin.ignore();
		getline(cin,cur->staff.SocialID);
		Read_After_Update_Teachers(teacher);
		UpdateTeacherInfor(teacherID, teacher);
	}
	else if (choice == 4) {
		cout << "\nEnter your new faculty: ";
		cin.ignore();
		getline(cin, cur->staff.Faculty);
		Read_After_Update_Teachers(teacher);
		UpdateTeacherInfor(teacherID, teacher);
	}
	else if (choice == 0) {
		return;
	}
	else {
		std::cout << "Invalid selection, please enter again.\n\n";
		std::system("pause");
		UpdateTeacherInfor(teacherID, teacher);
	}

}

