#include "header.h"

using namespace std;

//COURSE
//-------Support functions------
CR_NODE* checkExistOfCourseRecord(CR_NODE*& head, std::string ID) {
	CR_NODE* current = head;
    CR_NODE* DelNode = nullptr;
	while (current) {
		if (ID == current->course.ID) {
			return DelNode = current;
		}
		else {
			current = current->next;
        }
    }
	return nullptr;
}
//--------Main functions---------
void ViewCourses(CR_NODE *head) {
    system("cls");

    cout << " ID  | Course name\t | Teacher\t | Credits | Max Student | Current Student | Session\t | Start Date\t | End Date";
    CR_NODE* cur = head;
    while (cur) {
        cout << cur->course.No << " " << cur->course.ID << " " << cur->course.CName << " " << cur->course.teacherName << " " << cur->course.Credits<< " "
        << cur->course.Max_stdn << " " << cur->course.Cur_stdn << " " << cur->course.session 
        << cur->course.startDate.day / 10 << cur->course.startDate.day % 10 << "/" << cur->course.startDate.month / 10 << cur->course.startDate.month % 10 << "/" << cur->course.startDate.year << " "
		<< cur->course.endDate.day / 10 << cur->course.endDate.day % 10 << "/" << cur->course.endDate.month / 10 << cur->course.endDate.month % 10 << "/" << cur->course.endDate.year;
        cur = cur->next;
    }
    delete cur;
}

void CreateNewCourse(CR_NODE *&head) {
    CR_NODE* NewCourse = new CR_NODE;
    CR_NODE* cur = head;
    while (cur) {
        cur = cur->next;
    }
    //create new course
    string NewCName;
    cout << "Enter Course Name: ";
    cin >> NewCName;
    NewCourse->course.CName = NewCName;
    string NewID;
    cout << "Enter Course ID: ";
    cin >> NewID;
    NewCourse->course.ID = NewID;
    if (!cur->prev) {
        NewCourse->course.No = 1;
    }
    else {
        NewCourse->course.No = cur->prev->course.No++;
    }
    string NewTeacher;
    cout << "Enter Teacher name: ";
    cin >> NewTeacher;
    NewCourse->course.teacherName = NewTeacher;
    srand(time(0));
    int NewTeacherID = rand();
    NewCourse->course.teacherID = to_string(NewTeacherID);
    int NewCredits;
    cin >> NewCredits;
    NewCourse->course.Credits = NewCredits;
    string NewSession;
    cout << "Enter Session(S1->S4): ";
    cin >> NewSession;
    NewCourse->course.session = ConvertEnumSS(NewSession);
    string NewWeekday;
    cout << "Enter Weekday(MON->SAT): ";
    cin >> NewWeekday;
    NewCourse->course.dayOfWeek = ConvertEnumWD(NewWeekday);
    cout << "Enter Start date (Please seperate with spaces)";
    cin >> NewCourse->course.startDate.day >> NewCourse->course.startDate.month >> NewCourse->course.startDate.year;
    cout << "Enter End date (Please seperate with spaces)";
    cin >> NewCourse->course.endDate.day >> NewCourse->course.endDate.month >> NewCourse->course.endDate.year;
    cur->next = NewCourse;
    system("cls");
    cout << "Added Course Successfully\n";
    Read_After_Update_Course(*&head);
    return;
}

void UpdateCourseInfo(CR_NODE *&head) {
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
            << "\t4. Course Teacher ID.\n"
            << "\t5. Course Credits.\n"
            << "\t6. Course Max Students.\n"
            << "\t7. Course Weekday.\n"
            << "\t8. Course Session.\n"
            << "\t9. Course Start Date.\n"
            << "\t10. Course End Date.\n";
        cout << "========================END========================\n\n";
        cout << "What would you like to update?: ";

        system("pause");

        int choice;
        cin >> choice;
        switch(choice) {
            case 1: {
                cout << "Enter Course ID: ";
                cin >> UpNode->course.ID;
            } break;
            case 2: {
                cout << "Enter Course Name: ";
                cin >> UpNode->course.CName;
            } break;
            case 3: {
                cout << "Enter Course Teacher name: ";
                cin >> UpNode->course.teacherName;
            } break;
            case 4: {
                cout << "Enter Course Teacher ID: ";
                cin >> UpNode->course.teacherID;
            } break;
            case 5: {
                cout << "Enter Course Credits: ";
                cin >> UpNode->course.Credits;
            } break;
            case 6: { 
                cout << "Enter Course Max Students: ";
                cin >> UpNode->course.Max_stdn;
            } break;
            case 7: {
                cout << "Enter Course Weekday: ";
                string wd;
                cin >> wd;
                UpNode->course.dayOfWeek = ConvertEnumWD(wd);
            } break;
            case 8: {
                cout << "Enter Course Session: ";
                string ss;
                cin >> ss;
                UpNode->course.session = ConvertEnumSS(ss);
            } break;
            case 9: {
                cout << "Enter Start Date (Please seperate with spaces)";
                cin >> UpNode->course.startDate.day >> UpNode->course.startDate.month >> UpNode->course.startDate.year;
            } break;
            case 10: {
                cout << "Enter End date (Please seperate with spaces)";
                cin >> UpNode->course.endDate.day >> UpNode->course.endDate.month >> UpNode->course.endDate.year;
            } break;
            default: {
                cout << "Invalid selection, please enter again.\n\n";
                //system("pause");
            } break;
        }

        system("cls");
        cout << "Update Course Successfully\n";
        Read_After_Update_Course(*&head);
        return;
    }
    else {
        cout << "No Course Founded!";
        cout << "\nSearch for Course again? (y/n)";
        //system("pause");
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
    string DelID;
    cin >> DelID;
    CR_NODE *DelNode = checkExistOfCourseRecord(head, DelID);
    if(DelNode) {    
        CR_NODE *tmp = DelNode;
        (DelNode->next)->prev = tmp->prev;
        (DelNode->prev)->next = tmp->next;
        delete tmp;

        system("cls");
        cout << "Delete Course Successfully";
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

int DisplayMenu() {
    system("cls");

    cout << "======================COURSE======================";
    cout << "\n\t1. View list of course.\n"
        << "\t2. Create a new course.\n"
        << "\t3. Update course's information.\n"
        << "\t4. Delete a course.\n"
        << "\t0. Back forward.\n"
        << "\t-1. Exit\n";
    cout << "========================END========================\n\n";

    cout << "Enter select the option you want to choice: ";
    int choice;
    cin >> choice;
    cin.ignore();
    return choice;
}

void getOption(int &choice, CR_NODE *head) {
    switch (choice) {
        case 1: {
            ViewCourses(head);
            system("pause");
            DisplayMenu();
        } break;

        case 2: {
            CreateNewCourse(*&head);
            DisplayMenu();
        } break;

        case 3: {
            UpdateCourseInfo(*&head); 
            DisplayMenu();
        } break;

        case 4: {
            DeleteCourse(*&head);
            DisplayMenu();
        } break;

        case 0: {
        } break;

        case -1: {
            return;
        } break;

        default: {
            cout << "Invalid selection, please enter again.\n\n";
        } break;
    }
}
 