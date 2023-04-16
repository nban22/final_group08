#include "header.h"

void DeleteSTU_NODE(STU_NODE*& student)
{
	while (student != nullptr)
	{
		STU_NODE* tmp = student;
		student = student->next;
		delete tmp;
	}
}
void DeleteSTFF_NODE(STFF_NODE*& staff)
{
	while (staff != nullptr)
	{
		STFF_NODE* tmp = staff;
		staff = staff->next;
		delete tmp;
	}
}
void DeleteCR_NODE(CR_NODE*& course)
{
	while (course != nullptr)
	{
		CR_NODE* tmp = course;
		course = course->next;
		delete tmp;
	}
}
void DeleteSTU_COURSE_NODE(STU_COURSE_NODE*& stu_course)
{
	while (stu_course != nullptr)
	{
		STU_COURSE_NODE* tmp = stu_course;
		stu_course = stu_course->next;
		delete tmp;
	}
}
void DeleteCLASS_NODE(CLASS_NODE*& listclass)
{
	while (listclass != nullptr)
	{
		CLASS_NODE* tmp = listclass;
		listclass = listclass->next;
		delete tmp;
	}
}
void DeleteALLLinkList(STU_NODE*& student, STFF_NODE*& staff, STFF_NODE*& teacher, CR_NODE*& course, STU_COURSE_NODE*& stu_course, CLASS_NODE*& listclass)
{
	DeleteSTU_NODE(student);
	DeleteSTFF_NODE(staff);
	DeleteSTFF_NODE(teacher);
	DeleteCR_NODE(course);
	DeleteSTU_COURSE_NODE(stu_course);
	DeleteCLASS_NODE(listclass);
}
