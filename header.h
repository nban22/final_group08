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

struct CLASS {
    std::string name;
    std::string ClassID;
};

struct COURSE {
    std::string ID;
    std::string CName;
    std::string Class;
    string teacherName;
    int Credits;
    int Max_stdn;
    WEEKDAY *dayOfWeek;
    SESSION *session;
};

struct SEMESTER {
    DATE startDate, endDate;
    COURSE *courses;
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
    STU_NODE* next;
    STU_NODE* prev;
};

struct STFF_NODE {
    STAFF staff;
    STFF_NODE* next;
    STFF_NODE* prev;
};

//Doc thong tin cua giao vien v�o DLL
void getData_A_Teacher(std::ifstream& input, STAFF& teacher);
void getDataTeachers_csv(std::ifstream& input, STFF_NODE*& head);
//Read Student's Data and create D_Linked List
void getData_A_Student(std::ifstream& input, STU_NODE*& head);
void getDataStudents_csv(STUDENT student, STU_NODE*& head);
void print_Students(STU_NODE* head);

#endif