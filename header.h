#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

//Using namespace std;
//Shouldn't use namespace in a header files!

//**********************SEMESTER.h
struct DATE {
    int year, month, day;
};

enum WEEKDAY {
  MON, TUE, WED, THU, FRI, SAT
};

enum SESSION {
  S1,
  S2,
  S3,
  S4
};

struct CLASS {
    std::string name;
    std::string ClassID;
};

struct COURSE {
    std::string ID;
    std::string CName;
    std::string Class;
    std::string teacherName;
    int Credits;
    int Max_stdn;
    WEEKDAY *dayOfWeek;
    SESSION *session;
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

//Doc thong tin cua giao vien vao DLL

void getData_A_Teacher(STAFF staff, STFF_NODE*& head);
void getDataTeachers_csv(std::ifstream& input, STFF_NODE*& head);
void print_Staffs(STFF_NODE* head);

//Read Student's Data and create D_Linked List
void getData_A_Student(STUDENT student, STU_NODE*& head);
void getDataStudents_csv(std::ifstream& input, STU_NODE*& head);
void print_Students(STU_NODE* head);

//checkAcount
int checkExistOfStudentAccount(STU_NODE*& head, std::string user, std::string password, STU_NODE*& logged);
int checkExistOfStaffAccount(STFF_NODE*& head, std::string user, std::string password, STFF_NODE*& logged);

//TEACHER'S OPTIONAL FUNCTIONS
bool Read_After_Update_Teachers(STFF_NODE*& head);

//STUDENT'S OPTIONAL FUNCTIONS



#endif