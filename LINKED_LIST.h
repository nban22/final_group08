#pragma once
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <string>
#include <cstring>
#include "USERS.h"

struct STU_NODE {
    STUDENT student;
    STU_NODE* next;
    STU_NODE* prev;
};

struct STFF_NODE {
    STAFF staff;
    STFF_NODE* next;
    STFF_NODE* prev;
};

#endif