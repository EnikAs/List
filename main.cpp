#include "listfunc.h"

int main()
{
    
    Lists lists = {};
    int corcheck = 0;
    corcheck = ListInit (&lists, 10);
    if (corcheck == INCORRECT_CALLOC)
    {
        printf("Incorrect list init!");
        return 0;
    }
    for(int i = 0 ; i < 5 ; i++)
    {
        ListInsert(&lists, i);
    }
    ListInsert(&lists, 12, 3);
    ListInsert(&lists, 12, 2);
    ListDump(&lists);
    //system ("\"C:/Program Files/Graphviz/bin/dot.exe\" -Tpng logfile.txt -o graph.png");

    //ListCtor();



    return 0;
}
// number               0       1      2      3      4      5      6      7      8      9
// data                 0       10     20     30     40     50     60     70     80     90
// next                -1       2      3      4      5      6      7      8      9      0         
// *previous*
//
//
//
//
//
//
//
//
//
//