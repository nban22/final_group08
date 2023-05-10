#pragma once
#ifndef GET_DATA_AND_SYNCH_H_
#define GET_DATA_AND_SYNCH_H_

#include "baseStructure.h"
#include <fstream>

//Read Teacher's Data and create D_Linked List
void getData_A_Teacher(STAFF teacher, STFF_NODE*& head);
void getDataTeacher_csv(std::ifstream& input, STFF_NODE*& head);
//Read Staff's Data and create D_Linked List  
void getData_A_Staff(STAFF staff, STFF_NODE*& head);
void getDataStaff_csv(std::ifstream& input, STFF_NODE*& head);
//Read Student's Data and create D_Linked List
void getData_A_Student(STUDENT student, STU_NODE*& head);
void getDataStudents_csv(std::ifstream& input, STU_NODE*& head);
//Read Course'getDataCourse_csvs Data and create D_Linked List
void getDataCourse_csv(std::ifstream& input, CR_NODE*& head);
void getData_A_Course(std::ifstream& input, COURSE& course);
////Read Course'getDataCourse_csvs Data and create D_Linked List
void getData_A_StuCourse(STU_COURSE studentcourse, STU_COURSE_NODE*& head);
void Get_Data_StudentCourse_csv(std::ifstream& input, STU_COURSE_NODE*& head);

// ===============Doc lai file sau khi da cap nhat=============
bool reread_after_update_staff(STFF_NODE* head);
bool reread_after_update_teacher(STFF_NODE* teacher);
bool reread_after_update_student(STU_NODE* head);
bool reread_after_update_course(STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE* course);
bool reread_after_update_student_course(STU_NODE* student, CR_NODE* course, STFF_NODE* teacher, STU_COURSE_NODE* stu_course);

void update_cur_stdn_in_course(CR_NODE*& course, STU_COURSE_NODE* head);
void update_list_of_classes(CLASS_NODE*& listclass, STU_NODE* student);

bool get_data_to_import_list_students_to_class(std::string fileName, STU_NODE*& student, CLASS_NODE* listclass, std::string classID, std::string className, std::string schoolYear);

void Update_from_enrolled_students_file(STU_COURSE_NODE*& stu_course, std::string course_id, std::string filename, CR_NODE* course, STU_NODE* student);

#endif // !GET_DATA_AND_SYNCH_H_