#include "deleteDLL.h"

void delete_DLL_of_student(STU_NODE*& student)
{
	while (student != nullptr)
	{
		STU_NODE* tmp = student;
		student = student->next;
		delete tmp;
	}
}
void delete_DLL_of_staff(STFF_NODE*& staff)
{
	while (staff != nullptr)
	{
		STFF_NODE* tmp = staff;
		staff = staff->next;
		delete tmp;
	}
}
void delete_DLL_of_course(CR_NODE*& course)
{
	while (course != nullptr)
	{
		CR_NODE* tmp = course;
		course = course->next;
		delete tmp;
	}
}
void delete_DLL_of_student_course(STU_COURSE_NODE*& stu_course)
{
	while (stu_course != nullptr)
	{
		STU_COURSE_NODE* tmp = stu_course;
		stu_course = stu_course->next;
		delete tmp;
	}
}
void delete_DLL_of_class(CLASS_NODE*& listclass)
{
	while (listclass != nullptr)
	{
		CLASS_NODE* tmp = listclass;
		listclass = listclass->next;
		delete tmp;
	}
}
void delete_all_DLL(STU_NODE*& student, STFF_NODE*& staff, STFF_NODE*& teacher, CR_NODE*& course, STU_COURSE_NODE*& stu_course, CLASS_NODE*& listclass)
{
	delete_DLL_of_student(student);
	delete_DLL_of_staff(staff);
	delete_DLL_of_staff(teacher);
	delete_DLL_of_course(course);
	delete_DLL_of_student_course(stu_course);
	delete_DLL_of_class(listclass);
}
