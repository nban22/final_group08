#ifndef _HEADER_H_
#define _HEADER_H_
#pragma once

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>

//using namespace std;
//Shouldn't use namespace in a header files!

//**********************SEMESTER.h
struct DATE {
	int year{}, month{}, day{};
};

enum WEEKDAY {
	MON, TUE, WED, THU, FRI, SAT
	//convert function below
};

enum SESSION {
	S1, S2, S3, S4
	//convert function below
};

struct CLASS {
	std::string name;
	std::string ClassID;
};
#pragma once
struct COURSE {
	int No{};
	std::string ID;
	std::string CName;
	std::string Class;
	std::string LNameTeacher;
	std::string FNameTeacher;
	std::string teacherID;
	int Credits{};
	int Max_stdn{};
	int Cur_stdn{};
	WEEKDAY dayOfWeek; //ONLY 1 SESSION/WEEK/COURSE
	SESSION session;
	DATE startDate, endDate;
};

struct STU_COURSE {
	int No{};
	std::string StuID;
	std::string StudentName;
	std::string Gen;
	std::string Class;
	std::string CouID;
	std::string Cname;
	int credits{};
	int Max_stdn{};
	std::string Teachername;
	std::string TeacherID;
	std::string weekday;
	std::string session;
	DATE startdate;
	DATE enddate;
	float other{};
	float midterm{};
	float final{};
	float total{};
};

struct SEMESTER {
	DATE startDate, endDate;
	COURSE* courses;
};

//*********************USERS.h
struct STUDENT {
	int No_Student{};
	std::string StudentID;
	std::string Password;
	std::string FName, LName, Gender;
	std::string SocialID;
	DATE DoB; //Date of Birth
	CLASS Classes;

	//void ViewCourses();
	//void LoginStudent();
	//void LogoutStudent();
	//void ChangeStudentPass();
	//void UpdateStudentInfo();
	//void RegisterCourse();
	//void ViewSchedule();
	//void ViewScore();
	//void ViewStudentinCourse();
	//void ViewStudentinClass();

	//......add more later (if needed, above are all of the requirements)
};

struct STAFF {
	int No_Staff{};
	std::string TeacherID;
	std::string Password;
	std::string FName, LName, Gender;
	DATE DoB; //Date of Birth
	std::string SocialID;
	std::string Faculty;

	////Same funcs as students
	//void LoginStaff();
	//void LogoutStaff();
	//void ChangeStaffPass();
	//void UpdateStaffInfo();
	//void CreateSchoolYear();

	////Distinct funcs
	//void AddStudent();
	//void RemoveStudent();
	//void CreateCourseRegis();
	//void ExportStudentinCourse();
	//void EnterCourseScore();
	//void ViewCourseScore();
	//void ImportCourseScore();
	//void UpdateSudentRes();
	//void ViewClassScore();

	//......add more later (if needed, above are all of the requirements)
};


//********************LINKED_LIST.h
struct STU_NODE {
	STUDENT student{};
	STU_NODE* next = nullptr;
	STU_NODE* prev = nullptr;
};

struct STFF_NODE {
	STAFF staff{};
	STFF_NODE* next = nullptr;
	STFF_NODE* prev = nullptr;
};

struct CR_NODE {
	COURSE course{};
	CR_NODE* next = nullptr;
	CR_NODE* prev = nullptr;
};

struct STU_COURSE_NODE {
	STU_COURSE stu_course{};
	STU_COURSE_NODE* next = nullptr;
	STU_COURSE_NODE* prev = nullptr;
};
//%%%%%%%%%%%%%%    HAM DOC DU LIEU TU FILE CSV VAO DLL     %%%%%%%%%%%%%
//Read Teacher's Data and create D_Linked List
void getData_A_Teacher(STAFF teacher, STFF_NODE*& head);
void getDataTeacher_csv(std::ifstream& input, STFF_NODE*& head);
//Read Staff's Data and create D_Linked List  
void getData_A_Staff(STAFF staff, STFF_NODE*& head);
void getDataStaff_csv(std::ifstream& input, STFF_NODE*& head);
//Read Student's Data and create D_Linked List
void getData_A_Student(STUDENT student, STU_NODE*& head);
void getDataStudents_csv(std::ifstream& input, STU_NODE*& head);
//Read Course'getDataCourse_csvs Data and create D_Linked List
void getDataCourse_csv(std::ifstream& input, CR_NODE*& head);
void getData_A_Course(std::ifstream& input, COURSE& course);
////Read Course'getDataCourse_csvs Data and create D_Linked List
void getData_A_StuCourse(STU_COURSE studentcourse, STU_COURSE_NODE*& head);
void Get_Data_StudentCourse_csv(std::ifstream& input, STU_COURSE_NODE*& head);
//checkAcount
int checkExistOfStudentAccount(STU_NODE*& head, std::string user, std::string password, STU_NODE*& logged);
int checkExistOfStaffAccount(STFF_NODE*& head, std::string user, std::string password, STFF_NODE*& logged);

//%%%%%%%%%%%%%%    HAM CAP NHAT DU LIEU TU DLL VAO FILE CSV     %%%%%%%%%%%%%
bool Read_After_Update_Staffs(STFF_NODE* head);
bool Read_After_Update_Teachers(STFF_NODE* teacher);
bool Read_After_Update_Students(STU_NODE* head);
bool Read_After_Update_Course(STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE* course);
bool Read_After_Update_Student_Course(STU_NODE* student, CR_NODE* course, STFF_NODE* teacher, STU_COURSE_NODE* stu_course);


void changePassWordOfStaffAccount(STFF_NODE*& staff, STFF_NODE*& loggedinStaff);
void changePasswordOfStudentAccount(STU_NODE*& student, STU_NODE*& loggedinStudent);

//SEMESTER'S OPTIONAL FUNCTIONS
//COURSE

CR_NODE* checkExistOfCourseRecord(CR_NODE*& head, std::string ID);
void CreateNewCourse(STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE*& head);
void UpdateCourseInfo(STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE*& head);
void DeleteCourse(STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE*& head);

//----Weekday----
WEEKDAY ConvertEnumWD(std::string& str);
std::string ConvertStringWD(WEEKDAY& wd);

//----Session----
SESSION ConvertEnumSS(std::string& str);
std::string ConvertStringSS(SESSION& ss);
std::string ConvertStringonlySS(SESSION& ss);


//COURSE_STUDENT

int countTheNumberOfStudentsInEachCourse(std::string CourseID, STU_COURSE_NODE* head);
void updateCur_stdnInCourse(CR_NODE*& course, STU_COURSE_NODE* head);
void EnterCourseScore(STU_COURSE_NODE*& SC, CR_NODE* C, STFF_NODE* loggedinStaff, int& check);
void ViewScoreBoard_Course(STU_COURSE_NODE* SC, CR_NODE* C, STFF_NODE* loggedinStaff, int& check);
void ViewScoreBoard_Class(STU_COURSE_NODE* SC, CR_NODE* C, STFF_NODE* loggedinStaff, int& check);
void ExportScoreBoard(STU_COURSE_NODE* SC, CR_NODE* C, STU_NODE* S);
void UpdateMarksInfo(STU_NODE* student, STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE*& head); //roke
STU_COURSE* checkExistOfStudentCourseRecord(STU_COURSE_NODE *&head, std::string ID); //roke

//SCHOOL_YEAR
void CreateSchoolYear(int& sYEAR);

//Add new 1st year students to 1st year classes
void addNew1styearStudent(STU_NODE*& student);

//=============view list of classes============
STU_NODE* checkExistClassIDinDLL(STU_NODE*& listclass, std::string classID);
void deleteSTU_NODE(STU_NODE*& head);
void displayLISTOFCLASS(STU_NODE*& student, STU_NODE* listclass);
void viewListOfClasses(STU_NODE* student);


//=============view list of courses============
void viewListOfCourses(CR_NODE* course);

//=============view list students of course============
void viewListStudentsOfCourse(STU_COURSE_NODE* stu_course, STU_NODE* student, std::string CourseID);

//=============view list students of class============
void viewListStudentsOfClass(STU_NODE* student);

//=============view scoreboard in a course============
void viewScoreBoard_Course(STU_COURSE_NODE* stu_course, STU_NODE* student, std::string CourseID);

//=============view scoreboard in a class============
void viewScoreBoard_Class(STU_COURSE_NODE* stu_course, STU_NODE* student, std::string ClassID);


void displayListStudentsOfCourse(STU_NODE*& student, std::string classID);
// Update teacher
void UpdateStaffInfo(STFF_NODE* staff, STFF_NODE* loggedinStaff);
// add student
void AddStudent(STU_NODE*& head);

STU_NODE* getInformationByStudentID(std::string StuID, STU_NODE* student);
CR_NODE* getInformationByCourseID(std::string CourseID, CR_NODE* course);
STFF_NODE* getInformationByTeacherID(std::string TeacherID, STFF_NODE* teacher);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@STAFF@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void printInformation_A_Staff(STFF_NODE* loggedinStaff);
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@STUDENT@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void printInformation_A_Student(STU_NODE* loggedinStudent);

// Update student
void UpdateStudentInfo(STU_NODE*& student, STU_NODE*& loggedinStaff);

void ViewSchedule(STU_COURSE_NODE* stu_course, STU_NODE* loggedinStudent, CR_NODE* course);

void DeleteRegisteredCourse(STU_COURSE_NODE*& stu_course, STU_NODE* loggedinStudent, CR_NODE* course);
//
void View_Y_Scoraboard(STU_COURSE_NODE* stu_course, STU_NODE* loggedinStudent);

void ViewListOfTeachers(STFF_NODE* teacher);

void UpdateTeacherInfor(std::string teacherID, STFF_NODE*& teacher);

#endif