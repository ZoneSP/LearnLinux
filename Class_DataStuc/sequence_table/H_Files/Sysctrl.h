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


/*创建  书籍结构体*/
typedef struct 
{
    char Book_name[50]; 
    __uint16_t Book_price;
    char Book_author[50];      
}Book;



/*创建  顺序表结构体*/
typedef struct
{
    Book *Save_address;
    int Book_cnt;
}Book_sequTable;


extern Book_sequTable   Books;



Book Clean_BookStruct(Book Book_Msg);
Book_sequTable InitList(Book_sequTable Book_list);
Book_sequTable ListInsert(Book_sequTable Book_list, Book Book_Msg);
Book_sequTable ListChoiceInsert(Book_sequTable Book_list, Book Book_Msg, unsigned char local);
Book_sequTable ListChoiceDelete(Book_sequTable Book_list, unsigned char local);
void ListSearch(Book_sequTable Book_list, unsigned char local);
void ListShow(Book_sequTable Book_list);


#endif


