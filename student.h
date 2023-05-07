#pragma once
#ifndef STUDENT_H_
#define STUDENT_H_

#include "baseStructure.h"
#include "myGraphicsLib.h"
#include "getDataAndSynch.h"
#include "staff.h"
#include <iomanip>


void change_password_of_student_account(STU_NODE*& student, STU_NODE*& loggedinStudent);

void update_student_information(STU_NODE*& student, STU_NODE*& loggedinStaff);

void register_for_course(STU_NODE*& student, STFF_NODE*& teacher, CR_NODE*& course, STU_COURSE_NODE*& stu_course, STU_NODE* loggedinStudent);

void result_registration(STU_COURSE_NODE* stu_course, STU_NODE* loggedinStudent);

void delete_registered_course(STU_COURSE_NODE*& stu_course, STU_NODE* loggedinStudent, CR_NODE* course, STU_NODE* student, STFF_NODE* teacher);

void view_academic_result(STU_COURSE_NODE* stu_course, STU_NODE* loggedinStudent);

#endif // !STUDENT_H_


