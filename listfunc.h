#ifndef LISTFUNC_H_INCLUDED
#define LISTFUNC_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string.h>
#include <stdlib.h>

typedef int list_t;

const int LIST_IS_FULL = 1488;

#define PRINT_LINE printf("I'm at line %d at function %s\n", __LINE__, __func__);

enum calloc_check
{
    INCORRECT_CALLOC = 228,
    CORRECT_CALLOC
};


struct List 
{
    list_t data = 0;
    int next = -1;
    int prev = -1;
};

struct Lists
{
    List* list;
    int size = 0;
    int capacity = 0;
    int head = 1;
    int tail = 1;
    int free = 0;
};


int ListInit (Lists* lists, int elem_num);

int ListInsert (Lists* lists, list_t value, int pos_init = -1);

int ListDump(Lists* lists);

#endif