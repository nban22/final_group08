#ifndef SEMESTER_H_
#define SEMESTER_H_

#include <string>
#include <cstring>

//using namespace std;
//Shouldn't use namespace in a header files!

struct DATE {
    int year, month, day;
};

struct SEMESTER {
    DATE startDate, endDate;
};

struct CLASS {
	std::string name;
	int num;
};

struct COURSE {
	std::string ID;
	std::string CName;
    std::string Class;
	int Credits;
	int Max_stdn;
    DATE startDate, endDate;
};

#endif