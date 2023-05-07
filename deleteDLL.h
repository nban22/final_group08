#pragma once
#ifndef DELETE_DLL_H_
#define DELETE_DLL_H_

#include "baseStructure.h"

void delete_DLL_of_student(STU_NODE*& student);
void delete_DLL_of_staff(STFF_NODE*& staff);
void delete_DLL_of_course(CR_NODE*& course);
void delete_DLL_of_student_course(STU_COURSE_NODE*& stu_course);
void delete_DLL_of_class(CLASS_NODE*& listclass);
void delete_all_DLL(STU_NODE*& student, STFF_NODE*& staff, STFF_NODE*& teacher, CR_NODE*& course, STU_COURSE_NODE*& stu_course, CLASS_NODE*& listclass);

#endif // !DELETE_DLL_H_


