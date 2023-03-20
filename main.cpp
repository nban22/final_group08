#include "header.h"

using namespace std;

int main()
{	
 	ifstream input;
	STFF_NODE *staff = nullptr;
	getData_A_Teacher(input, staff);
	print_Staffs(staff);  //for testing
	system("pause");
	return 0;
}