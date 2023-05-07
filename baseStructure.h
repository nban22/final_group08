#pragma once
#ifndef BASE_STRUCTURE_H_
#define BASE_STRUCTURE_H_

#include "myGraphicsLib.h"
#include <string>
#include <fstream>

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

struct Date {
	int year{}, month{}, day{};
};

struct Time {
	Time() { hour = 0; minute = 0; second = 0; }
	int hour, minute, second;
};

enum WEEKDAY {
	MON, TUE, WED, THU, FRI, SAT
};

enum SESSION {
	S1, S2, S3, S4
};

struct SEMESTER {
	Date startDate, endDate;
	std::string schoolyear;
	int semester;
};

struct CLASS {
	CLASS() {
		name = "Unknow";
		ClassID = "Unknow";
		schoolYear = 0;
	}
	std::string name;
	std::string ClassID;
	int schoolYear;
};

struct CLASS_NODE {
	CLASS listclass{};
	CLASS_NODE* next = nullptr;
	CLASS_NODE* prev = nullptr;
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

struct STFF_NODE {
	STAFF staff{};
	STFF_NODE* next = nullptr;
	STFF_NODE* prev = nullptr;
};

struct STUDENT {
	int No_Student{};
	std::string StudentID;
	std::string Password;
	std::string FName, LName, Gender;
	std::string SocialID;
	Date DoB; //Date of Birth
	CLASS Classes;
};

struct STU_NODE {
	STUDENT student{};
	STU_NODE* next = nullptr;
	STU_NODE* prev = nullptr;
};

struct STU_COURSE {
	std::string Schoolyear;
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

struct STU_COURSE_NODE {
	STU_COURSE stu_course{};
	STU_COURSE_NODE* next = nullptr;
	STU_COURSE_NODE* prev = nullptr;
};

struct COURSE {
	int No{};
	std::string Schoolyear;
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

struct CR_NODE {
	COURSE course{};
	CR_NODE* next = nullptr;
	CR_NODE* prev = nullptr;
};

//----Weekday----
WEEKDAY ConvertEnumWD(std::string str);
std::string ConvertStringWD(WEEKDAY wd);

//----Session----
SESSION ConvertEnumSS(std::string str);
std::string ConvertStringSS(SESSION ss);
std::string ConvertStringonlySS(SESSION ss);

STU_NODE* getInformationByStudentID(std::string StuID, STU_NODE* student);
CR_NODE* getInformationByCourseID(std::string CourseID, CR_NODE* course);
STFF_NODE* getInformationByTeacherID(std::string TeacherID, STFF_NODE* teacher);

CLASS_NODE* check_exist_class_node_in_DLL(CLASS_NODE* listclass, std::string classID);
STU_NODE* check_exist_classID_in_DLL(STU_NODE* listclass, std::string classID);

bool check_exist_of_schoolyear(std::string year);
CR_NODE* check_exist_of_course_record(CR_NODE*& head, std::string ID);
STU_COURSE_NODE* check_exist_of_student_course_record(STU_COURSE_NODE*& stu_course, std::string courseID);

void get_current_schoolYear_semester(int coordinate_x, int coordinate_y, std::string& cur_year, std::string& cur_semester);

int check_exist_of_student_account(STU_NODE*& head, std::string user, std::string password, STU_NODE*& logged);
int check_exist_of_staff_account(STFF_NODE*& head, std::string user, std::string password, STFF_NODE*& logged);

bool check_time(Time start_time, Date start_date, Time end_time, Date end_date);
#endif // !BASE_STRUCTURE_H_

/*
	  194
218	┌  ┬  ┐ 191         197 ┼

195 ├  ┼  ┤ 180			179 │

192 └  ┴  ┘ 217			196 ─
	  193
*/