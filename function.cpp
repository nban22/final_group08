#include "header.h"

using namespace std;

void getData_A_Teacher(ifstream& input, STAFF& teacher)
{
	input >> teacher.No_Staff;
	input.seekg(1);
	getline(input, teacher.TeacherID, ',');
	getline(input, teacher.Password, ',');
	getline(input, teacher.LName, ',');
	getline(input, teacher.FName, ',');
	getline(input, teacher.Gen, ',');
	input >> teacher.DoB.day;
	input.seekg(1);
	input >> teacher.DoB.month;
	input.seekg(1);
	input >> teacher.DoB.year;
	input.seekg(1);
	getline(input, teacher.SocialID, ',');
	getline(input, teacher.Faculty, ',');
}

void getDataTeachers_csv(ifstream& input, STFF_NODE*& head)
{
	

}