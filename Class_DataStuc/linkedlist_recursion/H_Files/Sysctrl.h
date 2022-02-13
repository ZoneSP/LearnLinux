#ifndef SYSCTRL_H
#define SYSCTRL_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX_Bookcnt   255

#define OK           0
#define ERROR        1
#define OVERQFLOW    2
#define List_Full    3
#define List_Empty   4


typedef struct
{
    char Book_name[50];
    char Book_author[50];
    u_int16_t Book_price;
}Book;


typedef struct LNode
{
    Book Book_msg;

    u_int16_t Book_local;

    u_int16_t Book_cnt;  /*只在头结点起作用，但后续各个节点与头结点保持一致*/

    struct LNode * Save_address;
}Book_list;




Book_list * Init_HeadNode(void);
Book_list * Insert_List(Book Book_Msg, Book_list *p);
void Free_ListMalloc(Book_list *pointer);
Book_list *Insert_ChoiceLoc(Book Book_Msg, Book_list *p ,u_int16_t local);
Book_list *DeleteChoice(Book_list *p, u_int16_t local);
Book_list * Find_FinNode(Book_list * Booklist_HeadNode);
#endif


