#pragma once
#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "windows.h"
#include <conio.h>
#include <Sstream>

//**********************SEMESTER.h
struct Date {
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
	int schoolYear;
};
#pragma once
struct COURSE {
	int No{};
	std::string Schoolyear; //bool checkExistOfSchoolyear(int year) (Ctrl+F to find)
	int Semester{}; //1 or 2 or 3  
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
	Date startDate, endDate;
};

struct STU_COURSE {
	std::string Schoolyear; //bool checkExistOfSchoolyear(int year) (Ctrl+F to find)
	int Semester{}; //1 or 2 or 3 
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
	Date startdate;
	Date enddate;
	float other{};
	float midterm{};
	float final{};
	float total{};
};

struct SEMESTER {
	Date startDate, endDate;
	std::string schoolyear;
};

//*********************USERS.h
struct STUDENT {
	int No_Student{};
	std::string StudentID;
	std::string Password;
	std::string FName, LName, Gender;
	std::string SocialID;
	Date DoB; //Date of Birth
	CLASS Classes;
};

struct STAFF {
	int No_Staff{};
	std::string TeacherID;
	std::string Password;
	std::string FName, LName, Gender;
	Date DoB; //Date of Birth
	std::string SocialID;
	std::string Faculty;
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
struct CLASS_NODE {
	CLASS listclass{};
	CLASS_NODE* next = nullptr;
	CLASS_NODE* prev = nullptr;
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
//COURSE //roke
CR_NODE* checkExistOfCourseRecord(CR_NODE*& head, std::string ID);
void CreateNewCourse(STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE*& head);
void UpdateCourseInfo(STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE*& head);
void DeleteCourse(STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE*& head);
void createNewSem(SEMESTER semester[], int& count);

//----Weekday----
WEEKDAY ConvertEnumWD(std::string str);
std::string ConvertStringWD(WEEKDAY& wd);

//----Session----
SESSION ConvertEnumSS(std::string str);
std::string ConvertStringSS(SESSION& ss);
std::string ConvertStringonlySS(SESSION& ss);


//COURSE_STUDENT
int countTheNumberOfStudentsInEachCourse(std::string CourseID, STU_COURSE_NODE* head);
void updateCur_stdnInCourse(CR_NODE*& course, STU_COURSE_NODE* head);
void updateListClass(CLASS_NODE*& listclass, STU_NODE* student);
void EnterCourseScore(STU_COURSE_NODE*& SC, CR_NODE* C, STFF_NODE* loggedinStaff, int& check);
void ExportScoreBoard(STU_COURSE_NODE* SC, CR_NODE* C, STU_NODE* S);
void UpdateMarksInfo(STU_NODE* student, STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE*& head); 
STU_COURSE* checkExistOfStudentCourseRecord(STU_COURSE_NODE*& head, std::string ID); 

//SCHOOL_YEAR
bool checkExistOfSchoolyear(std::string year);
void CreateSchoolYear(int& sYEAR);

//Add new 1st year students to 1st year classes
void addNew1styearStudent(STU_NODE*& student, CLASS_NODE* listclass);

//=============view list of classes============
CLASS_NODE* checkExistClassNODEIDinDLL(CLASS_NODE* listclass, std::string classID);
STU_NODE* checkExistClassIDinDLL(STU_NODE*& listclass, std::string classID);
void deleteSTU_NODE(STU_NODE*& head);
void displayLISTOFCLASS(CLASS_NODE* listclass);
void viewListOfClasses(CLASS_NODE*& listclass, STU_NODE* student);


//=============view list of courses============
void viewListOfCourses(CR_NODE* course);

//=============view list students of course============
void displayLISTSTUDENTOFCOURSE(STU_COURSE_NODE* stu_course, STU_NODE* student, std::string CourseID);
void viewListStudentsOfCourse(STU_COURSE_NODE* stu_course, STU_NODE* student, CR_NODE* course);
//=============view list students of class============
void viewListStudentsOfClass(STU_NODE* student, CLASS_NODE* listclass);

//=============view scoreboard in a course============
void displayScoreBoard_Course(STU_COURSE_NODE* stu_course, STU_NODE* student, std::string CourseID);
void viewScoreboardInCourse(CR_NODE* course, STU_COURSE_NODE* stu_course, STU_NODE* student);
//=============view scoreboard in a class============\n m 
void displayScoreBoard_Class(STU_COURSE_NODE* stu_course, STU_NODE* student, std::string ClassID);
void viewScoreBoard_Class(STU_COURSE_NODE* stu_course, STU_NODE* student, CLASS_NODE* listclass);

void displayListStudentsOfCourse(STU_NODE*& student, std::string classID);
// Modify teacher
void UpdateStaffInfo(STFF_NODE* staff, STFF_NODE* loggedinStaff);
void Create_newStaff(STFF_NODE* staff);

STU_NODE* getInformationByStudentID(std::string StuID, STU_NODE* student);
CR_NODE* getInformationByCourseID(std::string CourseID, CR_NODE* course);
STFF_NODE* getInformationByTeacherID(std::string TeacherID, STFF_NODE* teacher);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@STAFF@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void printInformation_A_Staff(STFF_NODE* loggedinStaff);
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@STUDENT@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void printInformation_A_Student(STU_NODE* loggedinStudent);

// Update student
void UpdateStudentInfo(STU_NODE*& student, STU_NODE*& loggedinStaff);

void RegisterForCourse(STU_NODE* student, STFF_NODE* teacher, CR_NODE* course, STU_COURSE_NODE* stu_course, STU_NODE *loggedinStudent); //new

bool ViewSchedule(STU_COURSE_NODE* stu_course, STU_NODE* loggedinStudent, CR_NODE* course);

void DeleteRegisteredCourse(STU_COURSE_NODE*& stu_course, STU_NODE* loggedinStudent, CR_NODE* course, STU_NODE* student, STFF_NODE* teacher);

void ResultRegistration(STU_COURSE_NODE* stu_course, STU_NODE* loggedinStudent, CR_NODE* course);
//
char GetRanking(float Grade); 
void View_Y_Scoreboard(STU_COURSE_NODE* stu_course, STU_NODE* loggedinStudent);

void ViewListOfTeachers(STFF_NODE* teacher);

void UpdateTeacherInfor(std::string teacherID, STFF_NODE*& teacher);

void UpdateYourInfor(STFF_NODE* loggedinStaff, STFF_NODE*& teacher);

STU_NODE* importClassFromCSV(std::string ClassID);



#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_AQUA 11
#define LIGHT_RED 12
#define LIGHT_PURPLE 13
#define LIGHT_YELLOW 14
#define BRIGHT_WHITE 15

#define KEY_NONE	-1
int whereX();
//========= lấy tọa độ y của con trỏ hiện tại =======
int whereY();
//============== dịch con trỏ hiện tại đến điểm có tọa độ (x,y) ==========
void gotoXY(int x, int y);
//============= đặt màu cho chữ =========
void SetColor(WORD color);
void SetColor2(int backgound_color, int text_color);
//============== làm ẩn trỏ chuột ===========
void ShowCur(bool CursorVisibility);
//======= trả về mã phím người dùng bấm =========
int inputKey();
// Hàm tô màu.
void textcolor(int x);
// Hàm thay đổi kích cỡ của khung cmd với tham số truyền vào là chiều cao, chiều rộng.
void resizeConsole(int width, int height);
// Hàm xóa màn hình.
void XoaManHinh();
// Hàm tự viết
void my_print(int x, int y, int t_color, std::string content);
// Tạo box
void box(int x, int y, int width, int height, int t_color);
// Tạo nhiều box
void n_box(int x, int y, int width, int height, int amount, int t_color);
//Menu của staff
int menu(int x, int y, int width, int height, int amount, std::string option[], int box_color, int text_color, int b_color_light);
void menu_Staff(int x, int y, int width, int height, int amount, std::string option[], int box_color, int text_color, int b_color_light, int option_num);
// Hàm nhập tối đa số lượng cho trước, và "chỉ nhận chữ cái và kí tự @ và dấu chấm "."
std::string my_getline(int max);
// Hàm nhập tối đa số lượng cho trước, và chỉ nhận số"
std::string my_getline_onlyNumber(int max);
// Hàm nhập tối đa số lượng cho trước, và "chỉ nhận chữ cái và kí tự @ và dấu chấm "." và space
std::string my_getline_addSpace(int max);

#endif