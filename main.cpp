#include "header.h"

using namespace std;

int main()
{
	ifstream input;
	STFF_NODE* staff = nullptr;
	getDataTeachers_csv(input, staff);
	print_Staffs(staff);  //for testing

	ifstream input_S;
	STU_NODE* student = nullptr;
	getDataStudents_csv(input_S, student);

	int check_T, check_S;
	do {
		string user, pass;
		cout << "ID of Your User: ";
		getline(cin, user);
		cout << "Password: ";
		getline(cin, pass);

		check_T = checkExistOfStaffAccount(staff, user, pass);
		check_S = checkExistOfStudentAccount(student, user, pass);

		if (check_T == 1 || check_S == 1) {
			cout << "Logged in successfully.\n";
			break;
		}

		if (check_T == -1 || check_S == -1) {
			cout << "Your password isn't correct. Please, enter again.\n";
			break;
		}
		if (check_T == 0 || check_S == 0) {
			cout << "Your account doesn't exist. Please, enter again.\n";
		}
	} while (!(check_T == 1 || check_S == 1));

	//THE FUNCTIONS OF STAFF
	if (check_T == 1) {
		cout << "\n1. Change password.\n"
			<< "2. Update your persinal information.\n"
			<< "3. Create a school year."
			<< "4. Add new 1st year students to 1st year classes.\n"
			<< "5. Create a course registration session.\n"
			<< "6. Export list of student in a course.\n"
			<< "7. Enter and view the scoreboard of a course.\n"
			<< "8. View the scoreboard of a course.\n"
			<< "9. Import the scoreboard of a course.\n"
			<< "10. Update a student result.\n"
			<< "11. View the scoreboard of a class.\n"
			<< "0. Log out.\n"
			<< "-1. Exit\n";
		cout << "Enter your choose: ";
		int choose;
		cin >> choose;
		switch (choose) {
		case 1:
			break;
		case 2:
			break;
		default:
			break;
		}
	}

	//THE FUNCTIONS OF STUDENT
	if (check_S == 1) {
		cout << "\n1. Change password.\n"
			<< "2. Update your personal information.\n"
			<< "3. Register for the course.\n"
			<< "4. View your schedule.\n"
			<< "5. View your scoraboard."
			<< "6. View list of student in a course.\n"
			<< "7. View of classes.\n"
			<< "8. View list of student in a class.\n"
			<< "0. Log out.\n"
			<< "-1. Exit.\n";
		cout << "Enter your choose: ";
		int choose;
		cin >> choose;
		switch (choose) {
		case 1:
			break;
		case 2:
			break;
		default:
			break;
		}
	}


	system("pause");
	return 0;
}