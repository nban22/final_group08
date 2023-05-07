#include "header.h"
#include "baseStructure.h"
#include "getDataAndSynch.h"
#include "myGraphicsLib.h"
#include "staff.h"
#include "student.h"



//STU_NODE* importClassFromCSV(std::string ClassID) {
//	//Kiểm tra sự tồn tại của file csv
//	std::string filename = ClassID + ".csv";
//	std::ifstream file(filename);
//
//	if (!file) {
//		std::cout << "File not found!";
//		return nullptr;
//	}
//
//	//Đọc thông tin học sinh từ file csv và lưu vào danh sách liên kết
//	STU_NODE* head = nullptr;
//	STU_NODE* tail = nullptr;
//	std::string line;
//	std::getline(file, line); //Bỏ qua dòng đầu tiên của file csv
//	while (std::getline(file, line)) {
//		STUDENT student;
//		std::stringstream ss(line);
//		std::string field;
//		std::getline(ss, field, ',');
//		student.No_Student = stoi(field);
//		std::getline(ss, field, ',');
//		student.StudentID = field;
//		std::getline(ss, field, ',');
//		student.Password = field;
//		std::getline(ss, field, ',');
//		student.FName = field;
//		std::getline(ss, field, ',');
//		student.LName = field;
//		std::getline(ss, field, ',');
//		student.Gender = field;
//		std::getline(ss, field, ',');
//		student.SocialID = field;
//		std::getline(ss, field, ',');
//		student.DoB.day = stoi(field);
//		std::getline(ss, field, ',');
//		student.DoB.month = stoi(field);
//		std::getline(ss, field, ',');
//		student.DoB.year = stoi(field);
//		std::getline(ss, field, ',');
//		student.Classes.name = field;
//		std::getline(ss, field, ',');
//		student.Classes.ClassID = field;
//
//		STU_NODE* node = new STU_NODE;
//		node->student = student;
//		node->next = nullptr;
//		node->prev = tail;
//		if (head == nullptr) {
//			head = node;
//		}
//		if (tail != nullptr) {
//			tail->next = node;
//		}
//		tail = node;
//	}
//
//	file.close();
//	return head;
//}


