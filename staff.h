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

void Create_newStaff(STFF_NODE* staff);

//2
void add_new_first_year_student(STU_NODE*& student, CLASS_NODE* listclass);

void set_time_course_regis();

void import_students_from_file(STU_NODE* student, CLASS_NODE* listclass);

void display_list_of_teachers(STFF_NODE* teacher);
void update_information_of_teacher(STFF_NODE*& teacher);



//3
void create_new_course(STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE*& head);

void Add_Student_To_Course(STU_COURSE_NODE* stu_course, STU_NODE* student, STFF_NODE* teacher, CR_NODE* course);

void Remove_Student_From_Course(STU_COURSE_NODE*& stu_course, STU_NODE* student, STFF_NODE* teacher, CR_NODE* course);

void delete_course(STU_COURSE_NODE*& stu_course, STFF_NODE* teacher, CR_NODE*& head);

void update_course_information(STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE*& head);

bool Update_from_enrolled_students_file(STU_COURSE_NODE*& stu_course, std::string courseID, std::string fileName, CR_NODE* course, STU_NODE* student, STFF_NODE* teacher);
void upload_CSV_of_enrolled_students(STU_COURSE_NODE* stu_course, CR_NODE* course, STU_NODE* student, STFF_NODE* teacher);


void update_mark_information(STU_NODE* student, STU_COURSE_NODE*& stu_course, STFF_NODE* teacher, CR_NODE*& course);

void import_file_to_update_mark(STU_NODE* student, STU_COURSE_NODE*& stu_course, STFF_NODE* teacher, CR_NODE*& course);


//4
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

void export_course_students_to_csv(STU_COURSE_NODE* stu_course, CR_NODE* course, STU_NODE* student);

void export_scoreboard(STU_COURSE_NODE* stu_course, CR_NODE* course, STU_NODE* student);

//4
void change_password_of_staff_account(STFF_NODE* loggedinStaff, STFF_NODE* staff);

//5
void update_your_information(STFF_NODE*& loggedinStaff, STFF_NODE*& teacher, STFF_NODE*& staff);

#endif // !STAFF_H_

