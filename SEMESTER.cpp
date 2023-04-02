#include "header.h"

using namespace std;

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@COURSE@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//-------Support functions------
CR_NODE* checkExistOfCourseRecord(CR_NODE*& head, string ID) {
	CR_NODE* current = head;
    CR_NODE* FoundNode = nullptr;
	while (current) {
		if (ID == current->course.ID) {
			return FoundNode = current;
		}
		else {
			current = current->next;
        }
    }
	return FoundNode;
}

string ConvertStringWD(WEEKDAY& wd) {
	if (wd == MON) return "MON";
	else if (wd == TUE) return "TUE";
	else if (wd == WED) return "WED";
	else if (wd == THU) return "THU";
	else if (wd == FRI) return "FRI";
	else return "SAT";
}

string ConvertStringSS(SESSION& ss) {
	if (ss == S1) return "S1(07:30)";
	else if (ss == S2) return "S2(09:30)";
	else if (ss == S3) return "S3(13:30)";
	else return "S4(15:30)";
}

//--------Main functions---------

void CreateNewCourse(CR_NODE *&head) {
    std::system("cls");
    CR_NODE* NewCourse = new CR_NODE;
    CR_NODE* cur = head;
    while (cur->next) {
        cur = cur->next;
    }
    //create new course

    if (!cur) {
        NewCourse->course.No = 1;
    }
    else {
        int NewNo = cur->course.No;
        NewNo++;
        NewCourse->course.No = NewNo;
    }
    string NewCName;
    cout << "Enter Course Name: ";
    getline(cin, NewCName);
    NewCourse->course.CName = NewCName;
    string NewID;
    cout << "Enter Course ID: ";
    getline(cin, NewID);
    NewCourse->course.ID = NewID;
    string LName;
    cout << "Enter Teacher's last name: ";
    getline(cin, LName);
    NewCourse->course.LNameTeacher = LName;
    string FName;
    cout << "Enter Teacher's first name: ";
    getline(cin, FName);
    NewCourse->course.FNameTeacher = FName;
    int NewCredits;
    cout << "Enter Credits: ";
    cin >> NewCredits;
    NewCourse->course.Credits = NewCredits;
    int NewMax_stdn;
    cout << "Enter Max Students: ";
    cin >> NewMax_stdn;
    NewCourse->course.Max_stdn = NewMax_stdn;
    NewCourse->course.Cur_stdn = 0; //default
    string NewSession;
    cout << "Enter Session(S1->S4): ";
    cin >> NewSession;
    NewCourse->course.session = ConvertEnumSS(NewSession);
    string NewWeekday;
    cout << "Enter Weekday(MON->SAT): ";
    cin >> NewWeekday;
    NewCourse->course.dayOfWeek = ConvertEnumWD(NewWeekday);
    cout << "Enter Start date (Please seperate with spaces) (dd mm yyy)";
    cin >> NewCourse->course.startDate.day >> NewCourse->course.startDate.month >> NewCourse->course.startDate.year;
    cout << "Enter End date (Please seperate with spaces) (dd mm yyy)";
    cin >> NewCourse->course.endDate.day >> NewCourse->course.endDate.month >> NewCourse->course.endDate.year;

    //Add course at the end
    cur->next = NewCourse;
    NewCourse->prev = cur;
    
    system("cls");
    cout << "Added Course Successfully\n";
    Read_After_Update_Course(*&head);
    system("pause");
    return;
}

void UpdateCourseInfo(CR_NODE *&head) {
    std::system("cls");
    cout << "Enter Course ID: ";
    string UpID;
    cin >> UpID;
    CR_NODE *UpNode = checkExistOfCourseRecord(head, UpID);
    if(UpNode) {
        system("cls");

        cout << "======================COURSE======================";
        cout << "\n\t1. Course ID.\n"
            << "\t2. Course Name.\n"
            << "\t3. Course Teacher name.\n"
            << "\t4. Course Credits.\n"
            << "\t5. Course Max Students.\n"
            << "\t6. Course Weekday.\n"
            << "\t7. Course Session.\n"
            << "\t8. Course Start Date.\n"
            << "\t9. Course End Date.\n";
        cout << "========================END========================\n\n";
        cout << "What would you like to update?: ";

        //system("pause");

        int choice;
        cin >> choice;
        switch(choice) {
            case 1: {
                cout << "Enter Course ID: ";
                cin.ignore();
                getline(cin, UpNode->course.ID);
            } break;
            case 2: {
                cout << "Enter Course Name: ";
                cin.ignore();
                getline(cin, UpNode->course.CName);
            } break;
            case 3: {
                cout << "Enter Course Teacher Last name: ";
                cin.ignore();
                getline(cin, UpNode->course.LNameTeacher);
                cout << "Enter Course Teacher First name: ";
                getline(cin, UpNode->course.LNameTeacher);
            } break;
/*             case 4: {
                cout << "Enter Course Teacher ID: ";
                cin >> UpNode->course.teacherID;
            } break; */
            case 4: {
                cout << "Enter Course Credits: ";
                cin >> UpNode->course.Credits;
            } break;
            case 5: { 
                cout << "Enter Course Max Students: ";
                cin >> UpNode->course.Max_stdn;
            } break;
            case 6: {
                cout << "Enter Course Weekday: ";
                string wd;
                cin >> wd;
                UpNode->course.dayOfWeek = ConvertEnumWD(wd);
            } break;
            case 7: {
                cout << "Enter Course Session: ";
                string ss;
                cin >> ss;
                UpNode->course.session = ConvertEnumSS(ss);
            } break;
            case 8: {
                cout << "Enter Start Date (Please seperate with spaces)";
                cin >> UpNode->course.startDate.day >> UpNode->course.startDate.month >> UpNode->course.startDate.year;
            } break;
            case 9: {
                cout << "Enter End date (Please seperate with spaces)";
                cin >> UpNode->course.endDate.day >> UpNode->course.endDate.month >> UpNode->course.endDate.year;
            } break;
            default: {
                cout << "Invalid selection, please enter again.\n\n";
            } break;
        }

        system("cls");
        cout << "Update Course Successfully\n";
        Read_After_Update_Course(*&head);
        system("pause");
        return;
    }
    else {
        cout << "No Course Founded!";
        cout << "\nSearch for Course again? (y/n)";
        char ans;
        cin >> ans;
        if(ans == 'y' || ans == 'Y') {
            UpdateCourseInfo(head);
        }
        else {
            return;
        }
    }
}

void DeleteCourse(CR_NODE *&head) {
    std::system("cls");
    cout << "Enter Course ID: ";
    string DelID;
    cin >> DelID;
    CR_NODE *DelNode = checkExistOfCourseRecord(head, DelID);
    if(DelNode) {    
        CR_NODE *tmp = DelNode;
        (DelNode->next)->prev = tmp->prev;
        if (!DelNode->prev) {
            DelNode->prev = nullptr;
        }
        else {
            (DelNode->prev)->next = tmp->next;
            delete tmp;
        }

        system("cls");
        cout << "Delete Course Successfully\n";
        Read_After_Update_Course(*&head);
        system("pause");
        return;
    }
    else {
        cout << "No Course Founded!";
        cout << "\nSearch for Course again? (y/n)";
        //system("pause");
        char ans;
        cin >> ans;
        if(ans == 'y' || ans == 'Y') {
            DeleteCourse(head);
        }
        else {
            return;
        }
    }
}

/*int DisplayMenu() {
    system("cls");

    cout << "======================COURSE======================";
    cout << "\n\t1. View list of course.\n"
        << "\t2. Create a new course.\n"
        << "\t3. Update course's information.\n"
        << "\t4. Delete a course.\n"
        << "\t0. Back forward.\n";
    cout << "========================END========================\n\n";

    cout << "Enter select the option you want to choice: ";
    int choice;
    cin >> choice;
    cin.ignore();
    return choice;
}

void getOption(int &choice, CR_NODE *&head) {
    switch (choice) {
        case 1: {
            ViewCourses(head);
            system("pause");
        } DisplayMenu();
        break;

        case 2: {
            CreateNewCourse(head);
        } DisplayMenu();
        break;

        case 3: {
            UpdateCourseInfo(head); 
        }  DisplayMenu();
        break;

        case 4: {
            DeleteCourse(head);
        }  DisplayMenu();
        break;

        case 0: {
            return;
        } break;

        default: {
            cout << "Invalid selection, please enter again.\n\n";
        } DisplayMenu();
    }
} */
 