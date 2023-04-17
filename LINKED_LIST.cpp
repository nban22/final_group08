#include "header.h"

//***********GET DATA AND BUILD LINKED LISTS**********

//STAFF

//%%%%%%%%%%%%%%    HAM DOC DU LIEU TU FILE CSV VÀO DLL     %%%%%%%%%%%%%

//checkAcount
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


//COURSE
//Weekday
WEEKDAY ConvertEnumWD(std::string str) {
	if (str.compare("MON") == 0 || str.compare("mon") == 0 || str.compare("Mon") == 0) return MON;
	else if (str.compare("TUE") == 0 || str.compare("tue") == 0 || str.compare("Tue") == 0) return TUE;
	else if (str.compare("WED") == 0 || str.compare("wed") == 0 || str.compare("Wed") == 0) return WED;
	else if (str.compare("THU") == 0 || str.compare("thu") == 0 || str.compare("Thu") == 0) return THU;
	else if (str.compare("FRI") == 0 || str.compare("fri") == 0 || str.compare("Fri") == 0) return FRI;
	else return SAT;
}
//Session
SESSION ConvertEnumSS(std::string str) {
	if (str.compare("S1") == 0 || str.compare("s1") == 0) return S1;
	else if (str.compare("S2") == 0 || str.compare("s2") == 0) return S2;
	else if (str.compare("S3") == 0 || str.compare("s3") == 0) return S3;
	else return S4;
}
std::string ConvertStringonlySS(SESSION ss) {
	if (ss == S1) return "S1";
	else if (ss == S2) return "S2";
	else if (ss == S3) return "S3";
	else return "S4";
}


void EnterCourseScore(STU_COURSE_NODE*& SC, CR_NODE* C, STFF_NODE* loggedinStaff, int& check) {

	STU_COURSE_NODE* cur1 = SC;
	CR_NODE* cur2 = C;
	int choice;
	int count = 0;
	std::string courseID = "0";

	std::cout << "choose a course" << std::endl;
	while (cur2) {
		if (cur2->course.teacherID == loggedinStaff->staff.TeacherID) {
			std::cout << cur2->course.No << "  " << cur2->course.ID << "  " << cur2->course.CName << std::endl;
			count++;
		}
		cur2 = cur2->next;
	}
	if (count == 0) {
		std::cout << "you have not attend any course" << std::endl;
		check = 0;
		return;
	}
	std::cout << "your choice: ";
	std::cin >> choice;
	while (cur1) {
		if (cur1->stu_course.No == choice) {
			courseID = cur1->stu_course.CouID;
			break;
		}
		else
			cur1 = cur1->next;
	}

	if (courseID == "0") {
		std::cout << "Invalid selection, please enter again.\n\n";
		check = 0;
		system("pause");
		return;
	}

	cur1 = SC;
	std::cout << "\n\n";

	while (cur1) {
		if (courseID == cur1->stu_course.CouID) {
			std::cout << "\t\tEnter Score for student:" << std::endl;
			std::cout << cur1->stu_course.StudentName << "  " << cur1->stu_course.StuID << "  " << std::endl;
			std::cout << "Midterm mark: ";
			std::cin >> cur1->stu_course.midterm;
			std::cout << "Final mark: ";
			std::cin >> cur1->stu_course.final;
			std::cout << "Other mark: ";
			std::cin >> cur1->stu_course.other;
			cur1->stu_course.total = (cur1->stu_course.other + cur1->stu_course.midterm + 2 * cur1->stu_course.final) / 4;
			system("cls");
		}
		cur1 = cur1->next;
	}
	check = 1;
}




//========================STUDENT============================

int countTheNumberOfStudentsInEachCourse(std::string CourseID, STU_COURSE_NODE* head) {
	STU_COURSE_NODE* cur = head;
	int count = 0;
	while (cur) {
		if (cur->stu_course.CouID == CourseID)
			count++;
		cur = cur->next;
	}
	return count;
}

bool checkExistOfSchoolyear(std::string year) {
	std::ifstream infile;
	infile.open("NewSchoolYear.csv");
	if (!infile.is_open()) {
		std::cout << "No file founded";
		return 0;
	}

	std::string tmp;
	std::getline(infile, tmp);

	while (!infile.eof()) {
		std::string line;
		std::getline(infile, line, '\n');
		if (line == "") {
			return 0;
		}
		if (line.compare(year) == 0) {
			return 1;
		}
	}
	return 0;
}

void CreateSchoolYear(int& sYEAR) {
	std::cout << "Input the starting year of the school year: ";
	std::cin >> sYEAR;

	std::ofstream outfile("NewSchoolYear.csv");
	if (!outfile.is_open()) {
		std::cout << "Failed to create file." << std::endl;
		return;
	}
	outfile << "School Year" << std::endl;
	outfile << sYEAR << "-" << sYEAR + 1 << std::endl;
	outfile.close();

	std::cout << "New school year created: " << sYEAR << "-" << sYEAR + 1 << std::endl;
}

void UpdateStaffInfo(STFF_NODE* staff, STFF_NODE* loggedinStaff) {
	std::cout << "Enter new information:" << std::endl;
	std::cout << "Teacher ID: ";
	std::cin >> loggedinStaff->staff.TeacherID;
	std::cout << "Password: ";
	std::cin >> loggedinStaff->staff.Password;
	std::cout << "First Name: ";
	std::cin >> loggedinStaff->staff.FName;
	std::cout << "Last Name: ";
	std::cin >> loggedinStaff->staff.LName;
	std::cout << "Gender: ";
	std::cin >> loggedinStaff->staff.Gender;
	std::cout << "Date of Birth (DD MM YYYY): ";
	std::cin >> loggedinStaff->staff.DoB.day >> loggedinStaff->staff.DoB.month >> loggedinStaff->staff.DoB.year;
	std::cout << "Social ID: ";
	std::cin >> loggedinStaff->staff.SocialID;
	std::cout << "Faculty: ";
	std::cin >> loggedinStaff->staff.Faculty;
}

STU_NODE* getInformationByStudentID(std::string StuID, STU_NODE* student) {
	STU_NODE* cur = student;
	while (cur) {
		if (cur->student.StudentID == StuID)
			return cur;
		cur = cur->next;
	}
	return nullptr;
}
CR_NODE* getInformationByCourseID(std::string CourseID, CR_NODE* course) {
	CR_NODE* cur = course;
	while (cur) {
		if (cur->course.ID == CourseID)
			return cur;
		cur = cur->next;
	}
	return nullptr;
}
STFF_NODE* getInformationByTeacherID(std::string TeacherID, STFF_NODE* teacher) {
	STFF_NODE* cur = teacher;
	while (cur) {
		if (cur->staff.TeacherID == TeacherID)
			return cur;
		cur = cur->next;
	}
	return nullptr;
}
STU_NODE* importClassFromCSV(std::string ClassID) {
	//Kiểm tra sự tồn tại của file csv
	std::string filename = ClassID + ".csv";
	std::ifstream file(filename);

	if (!file) {
		std::cout << "File not found!";
		return nullptr;
	}

	//Đọc thông tin học sinh từ file csv và lưu vào danh sách liên kết
	STU_NODE* head = nullptr;
	STU_NODE* tail = nullptr;
	std::string line;
	std::getline(file, line); //Bỏ qua dòng đầu tiên của file csv
	while (std::getline(file, line)) {
		STUDENT student;
		std::stringstream ss(line);
		std::string field;
		std::getline(ss, field, ',');
		student.No_Student = stoi(field);
		std::getline(ss, field, ',');
		student.StudentID = field;
		std::getline(ss, field, ',');
		student.Password = field;
		std::getline(ss, field, ',');
		student.FName = field;
		std::getline(ss, field, ',');
		student.LName = field;
		std::getline(ss, field, ',');
		student.Gender = field;
		std::getline(ss, field, ',');
		student.SocialID = field;
		std::getline(ss, field, ',');
		student.DoB.day = stoi(field);
		std::getline(ss, field, ',');
		student.DoB.month = stoi(field);
		std::getline(ss, field, ',');
		student.DoB.year = stoi(field);
		std::getline(ss, field, ',');
		student.Classes.name = field;
		std::getline(ss, field, ',');
		student.Classes.ClassID = field;

		STU_NODE* node = new STU_NODE;
		node->student = student;
		node->next = nullptr;
		node->prev = tail;
		if (head == nullptr) {
			head = node;
		}
		if (tail != nullptr) {
			tail->next = node;
		}
		tail = node;
	}

	file.close();
	return head;
}


