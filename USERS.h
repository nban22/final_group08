#ifndef USERS_H_
#define USERS_H_

#include <string>
#include <cstring>
#include "SEMESTER.h"

//using namespace std;
//Shouldn't use namespace in a header files!

struct STUDENT {
    std::string No_Student;
    std::string First_name, Last_name, Gender;
    std::string StudentID;
    std::string SocialID;
    std::string Gen;
    DATE DoB; //Date of Birth
    CLASS Classes;
    std::string User_name, Pass;

    void View_Courses();
    //......add more later
};

struct STAFF {
    std::string No_Student;
    std::string First_name, Last_name, Gender;
    std::string Teacher_ID;
    std::string SocialID;
    std::string Faculty;
    DATE DoB; //Date of Birth

    void AddStudent();
    void RemoveStudent();
    //......add more later
};



#endif