#include "listfunc.h"

int ListInit (Lists* lists, int elem_num)
{
    lists->list = (List*) calloc(elem_num, sizeof(List)); 
    if (lists->list == NULL)
        return INCORRECT_CALLOC;
    else 
    {
        lists->capacity = elem_num;

        for (int i = 1 ; i < elem_num ; i++)
        {
            lists->list[i].next = i + 1;
            lists->list[i].prev = -1;
        }
        lists->list[0].prev = -1;
        lists->list[0].next = 0;
        lists->list[0].data = 0;

        //lists->list[1].prev = 0;

        lists->head = 1;
        lists->tail = 1;
        lists->size = 1;
        lists->free = 1;

        return CORRECT_CALLOC;
    }
}

int ListInsert (Lists* lists, list_t value, int pos_init)// pos_init - элемент, после которого мы добавляем новый
{
    int tmp_elem_number = lists->free; 
    lists->free = lists->list[tmp_elem_number].next;
    lists->size += 1;

    if (pos_init == -1)
    {
        pos_init = lists->tail; // увеличивается tail, так как элемент добавляется в конец
        lists->list[pos_init].next = 0;
        lists->tail = tmp_elem_number;
    }

    lists->list[tmp_elem_number].data = value;
    lists->list[tmp_elem_number].next = lists->list[pos_init].next;
    lists->list[tmp_elem_number].prev = pos_init;

    printf("%d|", pos_init);
    lists->list[pos_init].next = tmp_elem_number;
    lists->list[lists->list[tmp_elem_number].next].prev = tmp_elem_number;

    return 0;
}

int ListDelete (Lists* lists, int pos_init)
{
    int tmp_next = lists->list[pos_init].next;
    int tmp_prev = lists->list[pos_init].prev;
    
    lists->list[tmp_prev].next = tmp_next;
    lists->list[tmp_next].prev = tmp_prev;

    lists->list[pos_init].next = lists->free;
    lists->free = pos_init;
}

int ListDump(Lists* lists)
{
    FILE* log_file = fopen("logfile.txt", "w");
    fprintf(log_file, "digraph G{\n");
    fprintf(log_file, "rankdir=LR;\n");// LR, UD
    for (int i = 0 ; i < lists->capacity ; i++)
    {
        fprintf(log_file, "%d [label =\" %d\\nvalue %d, next %d, prev %d\",shape = \"octagon\"];\n", i, i, lists->list[i].data, lists->list[i].next, lists->list[i].prev);
    }
    int tmp_pos = lists->head;
    printf("\n%d", lists->head);
    for (int i = 1 ; i < lists->size ; i++)
    {
        fprintf(log_file, "%d -> %d;\n", tmp_pos, lists->list[tmp_pos].next);
        tmp_pos = lists->list[tmp_pos].next;
    }
        tmp_pos = lists->free;
    for (int i = 0 ; i < lists->capacity - lists->size ; i++)
    {
        if (lists->list[tmp_pos].next == lists->capacity)
            break;
        fprintf(log_file, "%d -> %d;\n", tmp_pos, lists->list[tmp_pos].next);
        tmp_pos = lists->list[tmp_pos].next;
    }

    fprintf(log_file, "}");
    fclose(log_file);

    system ("\"C:/Program Files/Graphviz/bin/dot.exe\" -Tpng logfile.txt -o graph.png");

    return 0;
}