#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>

//Using namespace std;
//Shouldn't use namespace in a header files!

//**********************SEMESTER.h
struct DATE {
    int year, month, day;
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

struct COURSE {
    int No;
    std::string ID;
    std::string CName;
    std::string Class;
    std::string teacherName;
    std::string teacherID;
    int Credits;
    int Max_stdn;
    int Cur_stdn;
    WEEKDAY dayOfWeek; //ONLY 1 SESSION/WEEK/COURSE
    SESSION session;
    DATE startDate, endDate;

    void ViewCourses();
    void UpdateCourseInfo();
    void DeleteCourse();
};

struct STU_COURSE {
    int No;
    std::string StuID;
    std::string StudentName;
    std::string Gen;
    std::string Class;
    std::string CouID;
    std::string Cname;
    int credits;
    int Max_stdn;
    std::string Teachername;
    std::string TeacherID;
    std::string weekday;
    std::string session;
    DATE startdate;
    DATE enddate;
    float other;
    float midterm;
    float final;
    float total;
};

struct SEMESTER {
    DATE startDate, endDate;
    COURSE *courses;
};

//*********************USERS.h
struct STUDENT {
    int No_Student;
    std::string StudentID;
    std::string Password;
    std::string FName, LName, Gender;
    std::string SocialID;
    DATE DoB; //Date of Birth
    CLASS Classes;

    void ViewCourses();
    void LoginStudent();
    void LogoutStudent();
    void ChangeStudentPass();
    void UpdateStudentInfo();
    void RegisterCourse();
    void ViewSchedule();
    void ViewScore();
    void ViewStudentinCourse();
    void ViewStudentinClass();

    //......add more later (if needed, above are all of the requirements)
};

struct STAFF {
    int No_Staff;
    std::string TeacherID;
    std::string Password;
    std::string FName, LName, Gender;
    DATE DoB; //Date of Birth
    std::string SocialID;
    std::string Faculty;

    //Same funcs as students
    void LoginStaff();
    void LogoutStaff();
    void ChangeStaffPass();
    void UpdateStaffInfo();
    void CreateSchoolYear();

    //Distinct funcs
    void AddStudent();
    void RemoveStudent();
    void CreateCourseRegis();
    void ExportStudentinCourse();
    void EnterCourseScore();
    void ViewCourseScore();
    void ImportCourseScore();
    void UpdateSudentRes();
    void ViewClassScore();

    //......add more later (if needed, above are all of the requirements)
};


//********************LINKED_LIST.h

struct STU_NODE {
    STUDENT student;
    STU_NODE* next = nullptr;
    STU_NODE* prev = nullptr;
};

struct STFF_NODE {
    STAFF staff;
    STFF_NODE* next = nullptr;
    STFF_NODE* prev = nullptr;
};

struct CR_NODE {
    COURSE course;
    CR_NODE* next = nullptr;
    CR_NODE* prev = nullptr;
};

struct STU_COURSE_NODE {
    STU_COURSE stu_course;
    STU_COURSE_NODE* next;
    STU_COURSE_NODE* prev;
};

//Read Teacher's Data and create D_Linked List
void getData_A_Teacher(STAFF staff, STFF_NODE*& head);
void getDataTeachers_csv(std::ifstream& input, STFF_NODE*& head);
void print_Staffs(STFF_NODE* head); //for testing

//Read Student's Data and create D_Linked List
void getData_A_Student(STUDENT student, STU_NODE*& head);
void getDataStudents_csv(std::ifstream& input, STU_NODE*& head);
void print_Students(STU_NODE* head); //for testing

//Read Course's Data and create D_Linked List
void getDataCourse_csv(std::ifstream& input, CR_NODE *& head);
void getData_A_Course(COURSE course, CR_NODE *& head);

//checkAcount
int checkExistOfStudentAccount(STU_NODE*& head, std::string user, std::string password, STU_NODE*& logged);
int checkExistOfStaffAccount(STFF_NODE*& head, std::string user, std::string password, STFF_NODE*& logged);

//TEACHER'S OPTIONAL FUNCTIONS
bool Read_After_Update_Teachers(STFF_NODE*& head);
void changePassWordOfStaffAccount(STFF_NODE*& staff, STFF_NODE*& loggedinStaff);

//STUDENT'S OPTIONAL FUNCTIONS
bool Read_After_Update_Students(STU_NODE*& head);
void changePasswordOfStudentAccount(STU_NODE*& student, STU_NODE*& loggedinStudent);

//SEMESTER'S OPTIONAL FUNCTIONS
//COURSE
bool Read_After_Update_Course(CR_NODE*& head);
int DisplayMenu();
void getOption(int& choice, CR_NODE* head);
CR_NODE* checkExistOfCourseRecord(CR_NODE*& head, std::string ID);
void ViewCourses(CR_NODE *head);
void CreateNewCourse(CR_NODE *&head);
void UpdateCourseInfo(CR_NODE *&head);
void DeleteCourse(CR_NODE *&head);

//----Weekday----
WEEKDAY ConvertEnumWD(std::string& str);

//----Session----
SESSION ConvertEnumSS(std::string& str);

//COURSE_STUDENT
void getData_A_StuCourse(STU_COURSE studentcourse, STU_COURSE_NODE*& head);
void Get_Data_StudentCourse_csv(std::ifstream& input, STU_COURSE_NODE*& head);
bool Read_After_Update_Student_Course(STU_COURSE_NODE*& head);
void EnterCourseScore( STU_COURSE_NODE* &SC, CR_NODE* C, STFF_NODE* loggedinStaff, int &check);
void ViewScoreBoard_Course(STU_COURSE_NODE* SC, CR_NODE* C, STFF_NODE* loggedinStaff, int& check);
void ViewScoreBoard_Class(std::string classname, STU_COURSE_NODE* SC, CR_NODE* C, STFF_NODE* loggedinStaff, int& check);
void ExportScoreBoard(STU_COURSE_NODE* SC, CR_NODE* C, STFF_NODE* loggedinStaff, int& check);

//SCHOOL_YEAR
void CreateSchoolYear(int& sYEAR);

//=============view list of classes============
STU_NODE*  checkExistClassIDinDLL(STU_NODE*& listclass, std::string classID);
void deleteSTU_NODE(STU_NODE*& head);
void displayLISTOFCLASS(STU_NODE*& student, STU_NODE* listclass);

//=============view list students of class============
void displayListStudentsOfCourse(STU_NODE*& student, std::string classID);
// Update teacher
void UpdateStaffInfo(STFF_NODE* staff, STFF_NODE* loggedinStaff);
// Update student
void UpdateStudentInfo(STU_NODE* student, STU_NODE* loggedinStaff);

#endif