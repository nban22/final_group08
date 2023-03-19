#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

//using namespace std;
//Shouldn't use namespace in a header files!

//**********************SEMESTER.h
struct DATE {
    int year, month, day;
};

struct SEMESTER {
    DATE startDate, endDate;
};

struct CLASS {
    std::string name;
    int num;
};

struct COURSE {
    std::string ID;
    std::string CName;
    std::string Class;
    int Credits;
    int Max_stdn;
    DATE startDate, endDate;
};

//*********************USERS.h
struct STUDENT {
    int No_Student;
    std::string StudentID;
    std::string Password;
    std::string FName, LName, Gender;
    std::string SocialID;
    std::string Gen;
    DATE DoB; //Date of Birth
    CLASS Classes;

    void View_Courses();
    //......add more later
};

struct STAFF {
    int No_Staff;
    std::string TeacherID;
    std::string Password;
    std::string FName, LName, Gen;
    DATE DoB; //Date of Birth
    std::string SocialID;
    std::string Faculty;
    
    void AddStudent();
    void RemoveStudent();
    //......add more later
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

//Doc thong tin cua giao vien vào DLL
void getData_A_Teacher(std::ifstream& input, STAFF& teacher);
void getDataTeachers_csv(std::ifstream& input, STFF_NODE*& head);


#endif