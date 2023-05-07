#pragma once
#ifndef STAFF_H_
#define STAFF_H_

#include "baseStructure.h"
#include "myGraphicsLib.h"
#include "baseStructure.h"
#include "getDataAndSynch.h"
#include <string>
#include <fstream>
#include <iomanip>

//1
void create_a_new_school_year();

void create_semester();

void create_a_new_class(CLASS_NODE*& listclass);

void display_list_of_teachers(STFF_NODE* teacher);
void update_information_of_teacher(STFF_NODE*& teacher);

void Create_newStaff(STFF_NODE* staff);

//2
void add_new_first_year_student(STU_NODE*& student, CLASS_NODE* listclass);

void set_time_course_regis();

void create_new_course(STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE*& head);

void delete_course(STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE*& head);

void update_course_information(STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE*& head);

void update_mark_information(STU_NODE* student, STU_COURSE_NODE*& stu_course, STFF_NODE* teacher, CR_NODE*& course);

//3
void display_list_of_classes(CLASS_NODE* listclass);
void view_list_of_classes(CLASS_NODE*& listclass, STU_NODE* student);

void display_list_students_of_class(STU_NODE*& student, std::string classID);
void view_list_students_of_class(STU_NODE* student, CLASS_NODE* listclass);

void view_list_of_courses(CR_NODE* course);

void display_list_students_of_course(STU_COURSE_NODE* stu_course, STU_NODE* student, std::string CourseID);
void view_list_students_of_course(STU_COURSE_NODE* stu_course, STU_NODE* student, CR_NODE* course);

void display_scoreboard_in_course(STU_COURSE_NODE* stu_course, STU_NODE* student, std::string CourseID);
void view_scoreboard_in_course(CR_NODE* course, STU_COURSE_NODE* stu_course, STU_NODE* student);

void display_scoreboard_in_class(STU_COURSE_NODE* stu_course, STU_NODE* student, std::string ClassID);
void view_scoreboard_in_class(STU_COURSE_NODE* stu_course, STU_NODE* student, CLASS_NODE* listclass);

void export_scoreboard(STU_COURSE_NODE* SC, CR_NODE* C, STU_NODE* S);

//4
void change_password_of_staff_account(STFF_NODE* loggedinStaff, STFF_NODE* staff);

//5
void update_your_information(STFF_NODE*& loggedinStaff, STFF_NODE*& teacher, STFF_NODE*& staff);

#endif // !STAFF_H_

