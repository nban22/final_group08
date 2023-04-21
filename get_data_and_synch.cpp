#include "header.h"

//Read Teacher's Data and create D_Linked List
void getData_A_Teacher(STAFF teacher, STFF_NODE*& head) {
	STFF_NODE* tmp = new STFF_NODE;
	tmp->staff = teacher;
	tmp->next = nullptr;

	if (!head) {
		head = tmp;
		head->prev = nullptr;
	}
	else {
		STFF_NODE* cur = head;
		while (cur->next) {
			cur = cur->next;
		}
		cur->next = tmp;
		tmp->prev = cur;
	}
}
void getDataTeacher_csv(std::ifstream& input, STFF_NODE*& head) {
	input.open("teachers.csv");
	STAFF teacher;

	std::getline(input, teacher.TeacherID);
	while (!input.eof())
	{
		std::string tmp;
		std::getline(input, tmp, ',');
		teacher.No_Staff = stoi(tmp);
		std::getline(input, teacher.TeacherID, ',');
		std::getline(input, teacher.LName, ',');
		std::getline(input, teacher.FName, ',');
		std::getline(input, teacher.Gender, ',');
		std::getline(input, tmp, '/');

		teacher.DoB.month = stoi(tmp);
		std::getline(input, tmp, '/');
		teacher.DoB.day = stoi(tmp);
		std::getline(input, tmp, ',');
		teacher.DoB.year = stoi(tmp);
		std::getline(input, teacher.SocialID, ',');
		std::getline(input, teacher.Faculty);

		getData_A_Staff(teacher, head);
	}
	input.close();
}
//Read Staff's Data and create D_Linked List
void getData_A_Staff(STAFF staff, STFF_NODE*& head) {
	STFF_NODE* tmp = new STFF_NODE;
	tmp->staff = staff;
	tmp->next = nullptr;

	if (!head) {
		head = tmp;
		head->prev = nullptr;
	}
	else {
		STFF_NODE* cur = head;
		while (cur->next) {
			cur = cur->next;
		}
		cur->next = tmp;
		tmp->prev = cur;
	}
}
void getDataStaff_csv(std::ifstream& input, STFF_NODE*& head) {
	input.open("staffs.csv");
	STAFF teacher;

	std::getline(input, teacher.TeacherID);
	while (!input.eof())
	{
		std::string tmp;
		std::getline(input, tmp, ',');
		teacher.No_Staff = stoi(tmp);
		std::getline(input, teacher.TeacherID, ',');
		std::getline(input, teacher.Password, ',');
		std::getline(input, teacher.LName, ',');
		std::getline(input, teacher.FName, ',');
		std::getline(input, teacher.Gender, ',');
		std::getline(input, tmp, '/');

		teacher.DoB.month = stoi(tmp);
		std::getline(input, tmp, '/');
		teacher.DoB.day = stoi(tmp);
		std::getline(input, tmp, ',');
		teacher.DoB.year = stoi(tmp);
		std::getline(input, teacher.SocialID, ',');
		std::getline(input, teacher.Faculty);

		getData_A_Staff(teacher, head);
	}
	input.close();
}
//Read Student's Data and create D_Linked List
void getData_A_Student(STUDENT student, STU_NODE*& head) {
	STU_NODE* tmp = new STU_NODE;
	tmp->student = student;
	tmp->next = nullptr;

	if (!head) {
		head = tmp;
		head->prev = nullptr;
	}
	else {
		STU_NODE* cur = head;
		while (cur->next) {
			cur = cur->next;
		}
		cur->next = tmp;
		tmp->prev = cur;
	}
}
void getDataStudents_csv(std::ifstream& input, STU_NODE*& head) {
	input.open("students.csv");

	STUDENT student;

	std::getline(input, student.StudentID);
	while (!input.eof()) {
		std::string tmp;
		std::getline(input, tmp, ',');
		student.No_Student = stoi(tmp);
		std::getline(input, student.StudentID, ',');
		std::getline(input, student.Password, ',');
		std::getline(input, student.LName, ',');
		std::getline(input, student.FName, ',');
		std::getline(input, student.Gender, ',');
		std::getline(input, tmp, '/');
		student.DoB.month = stoi(tmp);
		std::getline(input, tmp, '/');
		student.DoB.day = stoi(tmp);
		std::getline(input, tmp, ',');
		student.DoB.year = stoi(tmp);
		std::getline(input, student.SocialID, ',');
		std::getline(input, student.Classes.name, ',');
		std::getline(input, student.Classes.ClassID, ',');
		std::getline(input, tmp);
		student.Classes.schoolYear = stoi(tmp);
		getData_A_Student(student, head);
	}

	input.close();
}
//Read Course'getDataCourse_csvs Data and create D_Linked List
void getDataCourse_csv(std::ifstream& input, CR_NODE*& head) {
	input.open("courses.csv");
	if (input.is_open() == false) return;
	std::string tem;
	std::getline(input, tem);
	CR_NODE* cur = head;
	while (input.eof() != true) {
		if (head == nullptr) {
			head = new CR_NODE;
			cur = head;
			getData_A_Course(input, cur->course);
			head->next = nullptr;
			head->prev = nullptr;
		}
		else {
			cur->next = new CR_NODE;
			cur->next->prev = cur;
			cur = cur->next;
			cur->next = nullptr;
			getData_A_Course(input, cur->course);
		}
	}
	input.close();
	return;
}
void getData_A_Course(std::ifstream& input, COURSE& course) {
	std::string tmp;
	std::getline(input, tmp, ',');
	course.No = stoi(tmp);
	std::getline(input, course.Schoolyear, ','); //new
	std::getline(input, tmp, ',');
	course.Semester = stoi(tmp); //end new
	std::getline(input, course.ID, ',');
	std::getline(input, course.CName, ',');
	std::getline(input, course.LNameTeacher, ',');
	std::getline(input, course.FNameTeacher, ',');
	std::getline(input, course.teacherID, ',');
	std::getline(input, tmp, ',');
	course.Credits = stoi(tmp);
	std::getline(input, tmp, ',');
	course.Cur_stdn = stoi(tmp);
	std::getline(input, tmp, ',');
	course.Max_stdn = stoi(tmp);

	std::string weekday;
	std::getline(input, weekday, ',');
	course.dayOfWeek = ConvertEnumWD(weekday);
	std::string session;
	std::getline(input, session, ',');
	course.session = ConvertEnumSS(session);;

	std::getline(input, tmp, '/');
	course.startDate.month = stoi(tmp);
	std::getline(input, tmp, '/');
	course.startDate.day = stoi(tmp);
	std::getline(input, tmp, ',');
	course.startDate.year = stoi(tmp);

	std::getline(input, tmp, '/');
	course.endDate.month = stoi(tmp);
	std::getline(input, tmp, '/');
	course.endDate.day = stoi(tmp);
	std::getline(input, tmp);
	course.endDate.year = stoi(tmp);
}
//Read Course'getDataStu_Course_csvs Data and create D_Linked List
void Get_Data_StudentCourse_csv(std::ifstream& input, STU_COURSE_NODE*& head) {
	input.open("student_course.csv"); //put this in main.cpp
	STU_COURSE studentcourse;

	std::string tem;
	std::getline(input, tem);
	while (!input.eof())
	{
		std::string tmp;
		std::getline(input, tmp, ',');
		if (tmp == "") {
			input.close();
			break;
		}
		studentcourse.No = stoi(tmp);
		std::getline(input, studentcourse.Schoolyear, ',');
		std::getline(input, tmp, ',');
		studentcourse.Semester = stoi(tmp);
		std::getline(input, studentcourse.StuID, ',');
		std::getline(input, studentcourse.StudentName, ',');
		std::getline(input, studentcourse.Gen, ',');
		std::getline(input, studentcourse.Class, ',');
		std::getline(input, studentcourse.CouID, ',');
		std::getline(input, studentcourse.Cname, ',');
		std::getline(input, tmp, ',');
		studentcourse.credits = stoi(tmp);
		std::getline(input, tmp, ',');
		studentcourse.Max_stdn = stoi(tmp);
		std::getline(input, studentcourse.Teachername, ',');
		std::getline(input, studentcourse.TeacherID, ',');
		std::getline(input, studentcourse.weekday, ',');
		std::getline(input, studentcourse.session, ',');
		std::getline(input, tmp, ',');
		studentcourse.startdate.day = stoi(tmp);
		std::getline(input, tmp, ',');
		studentcourse.startdate.month = stoi(tmp);
		std::getline(input, tmp, ',');
		studentcourse.enddate.day = stoi(tmp);
		std::getline(input, tmp, ',');
		studentcourse.enddate.month = stoi(tmp);
		std::getline(input, tmp, ',');
		studentcourse.midterm = stof(tmp);
		std::getline(input, tmp, ',');
		studentcourse.final = stof(tmp);
		std::getline(input, tmp, ',');
		studentcourse.other = stof(tmp);
		std::getline(input, tmp);
		studentcourse.total = stof(tmp);

		getData_A_StuCourse(studentcourse, head);
	}
	input.close();
	return;
}
void getData_A_StuCourse(STU_COURSE studentcourse, STU_COURSE_NODE*& head) {
	STU_COURSE_NODE* tmp = new STU_COURSE_NODE;
	tmp->stu_course = studentcourse;
	tmp->next = nullptr;

	if (!head) {
		head = tmp;
		head->prev = nullptr;
	}
	else {
		STU_COURSE_NODE* cur = head;
		while (cur->next) {
			cur = cur->next;
		}
		cur->next = tmp;
		tmp->prev = cur;
	}
}

// ===============Doc lai file sau khi da cap nhat=============
bool Read_After_Update_Staffs(STFF_NODE* staff) {
	std::ofstream outfile;
	outfile.open("staffs_test.csv");
	if (!outfile.is_open()) {
		return 0;
	}
	outfile << "No,Teacher ID,Password,Last Name,First Name,Gender,Date Of Birth,Social ID,Faculty";
	STFF_NODE* cur_staff = staff;
	int i = 1;
	while (cur_staff) {
		outfile << "\n" << i++ << ","
			<< cur_staff->staff.TeacherID << ","
			<< cur_staff->staff.Password << ","
			<< cur_staff->staff.LName << ","
			<< cur_staff->staff.FName << ","
			<< cur_staff->staff.Gender << ","
			<< cur_staff->staff.DoB.month / 10
			<< cur_staff->staff.DoB.month % 10 << "/"
			<< cur_staff->staff.DoB.day / 10
			<< cur_staff->staff.DoB.day % 10 << "/"
			<< cur_staff->staff.DoB.year << ","
			<< cur_staff->staff.SocialID << ","
			<< cur_staff->staff.Faculty;
		cur_staff = cur_staff->next;
	}
	outfile.close();
	return 1;
}
bool Read_After_Update_Teachers(STFF_NODE* teacher) {
	std::ofstream outfile;
	outfile.open("teachers_test.csv");
	if (!outfile.is_open()) {
		return 0;
	}
	outfile << "No,Teacher ID,Last Name,First Name,Gender,Date Of Birth,Social ID,Faculty";
	STFF_NODE* cur_teacher = teacher;
	int i = 1;
	while (cur_teacher) {
		outfile << "\n" << i++ << ","
			<< cur_teacher->staff.TeacherID << ","
			<< cur_teacher->staff.LName << ","
			<< cur_teacher->staff.FName << ","
			<< cur_teacher->staff.Gender << ","
			<< cur_teacher->staff.DoB.month / 10
			<< cur_teacher->staff.DoB.month % 10 << "/"
			<< cur_teacher->staff.DoB.day / 10
			<< cur_teacher->staff.DoB.day % 10 << "/"
			<< cur_teacher->staff.DoB.year << ","
			<< cur_teacher->staff.SocialID << ","
			<< cur_teacher->staff.Faculty;
		cur_teacher = cur_teacher->next;
	}
	outfile.close();
	return 1;
}
bool Read_After_Update_Students(STU_NODE* student) {
	std::ofstream outfile;
	outfile.open("students_TEST.csv");
	if (!outfile.is_open()) {
		return 0;
	}
	outfile << "No,Student ID,Password,Last Name,First Name,Gender,Date Of Birth,Social ID,Classes,Class ID,School year";
	STU_NODE* cur_student = student;
	int i = 1;
	while (cur_student) {
		outfile << "\n" << i++ << ","
			<< cur_student->student.StudentID << ","
			<< cur_student->student.Password << ","
			<< cur_student->student.LName << ","
			<< cur_student->student.FName << ","
			<< cur_student->student.Gender << ","
			<< cur_student->student.DoB.month / 10
			<< cur_student->student.DoB.month % 10 << "/"
			<< cur_student->student.DoB.day / 10
			<< cur_student->student.DoB.day % 10 << "/"
			<< cur_student->student.DoB.year << ","
			<< cur_student->student.SocialID << ","
			<< cur_student->student.Classes.name << ","
			<< cur_student->student.Classes.ClassID << ","
			<< "2022";
		cur_student = cur_student->next;
	}
	outfile.close();
	return 1;
}
bool Read_After_Update_Course(STU_COURSE_NODE* stu_course, STFF_NODE* teacher, CR_NODE* course) {
	std::ofstream outfile;
	outfile.open("coursestest.csv");
	if (!outfile.is_open()) {
		return 0;
	}
	updateCur_stdnInCourse(course, stu_course);
	int i = 1;
	CR_NODE* cur_course = course;

	outfile << "No,School Year,Semester,ID,Cname,Last Name,First Name,Teacher ID,Credits,Cur_stdn,Max_stdn,Weekday,Session,Start Date,End Date";
	while (cur_course) {
		STFF_NODE* tmp_teacher = getInformationByTeacherID(cur_course->course.teacherID, teacher);
		if (!tmp_teacher) {
			//i++;
			cur_course = cur_course->next;
			continue;
		}
		std::string session = ConvertStringonlySS(cur_course->course.session);
		std::string week = ConvertStringWD(cur_course->course.dayOfWeek);
		outfile << "\n" << i++ << ","
			<< cur_course->course.Schoolyear << ","
			<< cur_course->course.Semester << ","
			<< cur_course->course.ID << ","
			<< cur_course->course.CName << ","
			<< tmp_teacher->staff.LName << ","
			<< tmp_teacher->staff.FName << ","
			<< cur_course->course.teacherID << ","
			<< cur_course->course.Credits << ","
			<< cur_course->course.Cur_stdn << ","
			<< cur_course->course.Max_stdn << ","
			<< week << ","
			<< session << ","
			<< cur_course->course.startDate.month / 10
			<< cur_course->course.startDate.month % 10 << "/"
			<< cur_course->course.startDate.day / 10
			<< cur_course->course.startDate.day % 10 << "/"
			<< cur_course->course.startDate.year << ","
			<< cur_course->course.endDate.month << "/"
			<< cur_course->course.endDate.day << "/"
			<< cur_course->course.endDate.year;
		cur_course = cur_course->next;
	}

	outfile.close();

	return 1;
}
bool Read_After_Update_Student_Course(STU_NODE* student, CR_NODE* course, STFF_NODE* teacher, STU_COURSE_NODE* stu_course) {
	std::ofstream outfile;
	outfile.open("Student_Course_test.csv");
	if (!outfile.is_open()) {
		return 0;
	}
	int i = 1;
	STU_COURSE_NODE* cur_stu_course = stu_course;
	outfile << "No,School Year,Sem,Student ID,Student Name,Gender,Class ID,Course ID,Course Name,Credits,Max_stdn,Teacher Name,Teacher ID,Week day,session,day start,month start,day end,month end,Midterm Mark,Final Mark,Other Mark,Total Mark";
	while (cur_stu_course) {
		STU_NODE* tmp_student = getInformationByStudentID(cur_stu_course->stu_course.StuID, student);
		CR_NODE* tmp_course = getInformationByCourseID(cur_stu_course->stu_course.CouID, course);
		STFF_NODE* tmp_teacher = getInformationByTeacherID(cur_stu_course->stu_course.TeacherID, teacher);
		if (!tmp_student || !tmp_course || !tmp_teacher) {
			i++;
			cur_stu_course = cur_stu_course->next;
			continue;
		}
		std::string student_name = tmp_student->student.LName + " " + tmp_student->student.FName;
		std::string teacher_name = tmp_teacher->staff.LName + " " + tmp_teacher->staff.FName;
		std::string session = ConvertStringonlySS(tmp_course->course.session);
		std::string week = ConvertStringWD(tmp_course->course.dayOfWeek);
		outfile << "\n" << i++ << ","
			<< cur_stu_course->stu_course.Schoolyear << "," //new
			<< cur_stu_course->stu_course.Semester << "," //new
			<< cur_stu_course->stu_course.StuID << ","
			<< student_name << ","
			<< tmp_student->student.Gender << ","
			<< tmp_student->student.Classes.ClassID << ","
			<< cur_stu_course->stu_course.CouID << ","
			<< tmp_course->course.CName << ","
			<< tmp_course->course.Credits << ","
			<< tmp_course->course.Max_stdn << ","
			<< teacher_name << ","
			<< cur_stu_course->stu_course.TeacherID << ","
			<< week << ","
			<< session << ","
			<< tmp_course->course.startDate.day << ","
			<< tmp_course->course.startDate.month << ","
			<< tmp_course->course.endDate.day << ","
			<< tmp_course->course.endDate.month << ","
			<< cur_stu_course->stu_course.midterm << ","
			<< cur_stu_course->stu_course.final << ","
			<< cur_stu_course->stu_course.other << ","
			<< cur_stu_course->stu_course.total;
		cur_stu_course = cur_stu_course->next;
	}
	outfile.close();
	/*updateCur_stdnInCourse(course, stu_course);*/
	return 1;
}

void updateCur_stdnInCourse(CR_NODE*& course, STU_COURSE_NODE* head) {
	CR_NODE* cur_course = course;
	while (cur_course) {
		cur_course->course.Cur_stdn = countTheNumberOfStudentsInEachCourse(cur_course->course.ID, head);
		cur_course = cur_course->next;
	}
}
void updateListClass(CLASS_NODE*& listclass, STU_NODE* student) {
	CLASS_NODE* cur_listclass = listclass;
	STU_NODE* cur1_student = student;
	int i = 1;
	while (cur1_student) {
		if (checkExistClassNODEIDinDLL(listclass, cur1_student->student.Classes.ClassID) == 0)
		{
			if (i != 1) {
				cur_listclass->next = new CLASS_NODE;
				cur_listclass = cur_listclass->next;
			}
			i++;
			cur_listclass->listclass = cur1_student->student.Classes;
		}
		cur1_student = cur1_student->next;
	}
}