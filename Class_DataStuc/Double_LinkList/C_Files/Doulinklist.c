#include "Sysctrl.h"

/*小功能函数  释放链表内存*/
void Free_ListMalloc(Book_Doulist *pointer)
{
    Book_Doulist * point_A;
    Book_Doulist * point_B;

    point_A = pointer;

    if(point_A->next_SaveAddress == NULL)
    {
        free(point_A);
        point_A = NULL;
    }
    else
    {
        while(point_A->Book_local >= 0)
        {
            point_B = point_A->next_SaveAddress;
            free(point_A);

            if(point_B->Book_local <= point_A->Book_local)
            {
                break;
            }
            point_A = point_B;
        }
    }

    printf("\n*************************************************\n");
    printf("\n内存释放完毕！\n");
}



/*创建  头结点*/
Book_Doulist * Init_HeadNode(void)
{
    /*创建一个头结点*/
    Book_Doulist * p = (Book_Doulist*)malloc(sizeof(Book_Doulist));

    if(p == 0)
    {
        printf("\n构造双向链表失败！\n");
        exit(ERROR);
    }

    p->Book_cnt = 0;  //当前链表中书籍个数为0
    p->Book_local = 0;  //头结点不进入位置排序，记为0
    p->prior_SaveAddress = NULL;  
    p->next_SaveAddress = NULL;

    return p;
}



/*插入  链表尾插*/
Book_Doulist * Insert_List(Book Book_Msg, Book_Doulist *p)
{
    Book_Doulist *point;

    Book_Doulist * Msg_point = (Book_Doulist*)malloc(sizeof(Book_Doulist));

    point = p;

    Msg_point->Book_msg = Book_Msg;

    if(point->next_SaveAddress == NULL)
    {
        /*只有头结点*/
        point->next_SaveAddress = Msg_point;
        Msg_point->Book_local++;
        Msg_point->prior_SaveAddress = Msg_point;
        Msg_point->next_SaveAddress = Msg_point;  
    }
    else
    {
        /*从头结点访问到最后一个节点*/
        Msg_point->next_SaveAddress = point->next_SaveAddress;
        Msg_point->prior_SaveAddress = point->next_SaveAddress->prior_SaveAddress;
        point->next_SaveAddress->prior_SaveAddress->next_SaveAddress = Msg_point;
        point->next_SaveAddress->prior_SaveAddress = Msg_point;
        Msg_point->Book_local = Msg_point->prior_SaveAddress->Book_local + 1;
    }


    /*展列当前链表*/
    p->Book_cnt++;
    point = p;
    point = point->next_SaveAddress;
    printf("\n");
    while(point->Book_local != 0)
    {
        point->Book_cnt = p->Book_cnt;
        printf("书籍名称：%s  作者：%s  售价：%hd  位置：%hd\n",point->Book_msg.Book_name,
                                                 point->Book_msg.Book_author,
                                                 point->Book_msg.Book_price,
                                                 point->Book_local);
        
        if(point->next_SaveAddress->Book_local <= point->Book_local)
        {
            break;
        }

        point = point->next_SaveAddress;
    }

    printf("\n*************************************************\n");
    return p;
}



/*插入  选择位置*/
Book_Doulist *Insert_ChoiceLoc(Book Book_Msg, Book_Doulist *p ,u_int16_t local)
{
    Book_Doulist * Bref_point;
    Book_Doulist * point;
    Book_Doulist * Insert_point;

    if(local > p->Book_cnt)
    {
        printf("\n所选位置不存在，插入失败！\n");
        return p;
    }

    Book_Doulist * Msg_point = (Book_Doulist*)malloc(sizeof(Book_Doulist));

    Msg_point->Book_msg = Book_Msg;

    Insert_point = p;
    Insert_point = Insert_point->next_SaveAddress;
    
    Bref_point = Insert_point->prior_SaveAddress;

    while(Insert_point->Book_local != local)
    {
        Insert_point = Insert_point->next_SaveAddress;
        Bref_point = Insert_point->prior_SaveAddress;
    }

    Bref_point->next_SaveAddress = Msg_point;
    Msg_point->prior_SaveAddress = Bref_point;
    Msg_point->next_SaveAddress = Insert_point;
    Insert_point->prior_SaveAddress = Msg_point;


    /*修正Book_local  头结点指向*/
    Msg_point->Book_local = Msg_point->next_SaveAddress->Book_local;

    if(Msg_point->Book_local == 1)
    {
        p->next_SaveAddress = Msg_point;
    }

    while(Msg_point->Book_local == Msg_point->next_SaveAddress->Book_local)
    {
        Msg_point->next_SaveAddress->Book_local++;
        Msg_point = Msg_point->next_SaveAddress;
    }


    /*展列当前链表*/
    p->Book_cnt++;
    point = p;
    point = point->next_SaveAddress;
    printf("\n");
    while(point->Book_local != 0)
    {
        point->Book_cnt = p->Book_cnt;
        printf("书籍名称：%s  作者：%s  售价：%hd  位置：%hd\n",point->Book_msg.Book_name,
                                                 point->Book_msg.Book_author,
                                                 point->Book_msg.Book_price,
                                                 point->Book_local);
        
        if(point->next_SaveAddress->Book_local <= point->Book_local)
        {
            break;
        }

        point = point->next_SaveAddress;
    }

    printf("\n*************************************************\n");
    return p;
}



/*删除  选择位置*/
Book_Doulist *DeleteChoice(Book_Doulist *p, u_int16_t local)
{
    Book_Doulist * Delete_point;
    Book_Doulist * Bref_point;
    Book_Doulist * Aftr_point;

    Book_Doulist * point;

    Delete_point = p;
    Delete_point = Delete_point->next_SaveAddress;
    Aftr_point = Delete_point->next_SaveAddress;
    Bref_point = Delete_point->prior_SaveAddress;

    while(Delete_point->Book_local != local)
    {
        Delete_point = Aftr_point;
        Aftr_point = Delete_point->next_SaveAddress;
        Bref_point = Delete_point->prior_SaveAddress;
    }

    Bref_point->next_SaveAddress = Aftr_point;
    Aftr_point->prior_SaveAddress = Bref_point;

    free(Delete_point);
    Delete_point = NULL;


    /*修正Book_local  和头指针指向*/
    Aftr_point->Book_local--;

    if(Aftr_point->Book_local == 1)
    {
        p->next_SaveAddress = Aftr_point;
    }

    while(Aftr_point->Book_local+1 < Aftr_point->next_SaveAddress->Book_local)
    {
        Aftr_point->next_SaveAddress->Book_local--;
        Aftr_point = Aftr_point->next_SaveAddress;
    }


    /*展列当前链表*/
    p->Book_cnt--;
    point = p;
    point = point->next_SaveAddress;
    printf("\n");
    while(point->Book_local != 0)
    {
        point->Book_cnt = p->Book_cnt;
        printf("书籍名称：%s  作者：%s  售价：%hd  位置：%hd\n",point->Book_msg.Book_name,
                                                 point->Book_msg.Book_author,
                                                 point->Book_msg.Book_price,
                                                 point->Book_local);
        
        if(point->next_SaveAddress->Book_local <= point->Book_local)
        {
            break;
        }

        point = point->next_SaveAddress;
    }

    printf("\n*************************************************\n");
    return p;
}