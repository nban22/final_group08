#include "USER.cpp"
#include "SEMESTER.cpp"
#include "LINKED_LIST.cpp"

using namespace std;

int main()
{	
 	ifstream input;
	STFF_NODE *staff = nullptr;
	getData_A_Teacher(input, staff);
	print_Staff(staff);  //for testing
	system("pause");
	return 0;
}