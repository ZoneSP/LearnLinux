#include "Sysctrl.h"

/*小功能函数  释放链表内存*/
void Free_ListMalloc(Book_list *pointer)
{
    Book_list *pointer_A;
    Book_list *pointer_B;

    pointer_A = pointer;

    while(pointer_A->Save_address != NULL)
    {
        pointer_B = pointer_A->Save_address;

        if(pointer_B == NULL || pointer_B == 0)
        {
            free(pointer_A);
        }
        else
        {
            free(pointer_A);
            pointer_A = pointer_B;
        }
    }

    printf("内存释放完毕！\n");
}



/*创建  头结点*/
Book_list * Init_HeadNode(void)
{
    /*创建一个头结点*/
    Book_list * p = (Book_list*)malloc(sizeof(Book_list));

    if(p == 0)
    {
        printf("构造链表失败！\n\n");
        exit(ERROR);
    }
    else
    {
        printf("构造单链表成功！\n\n");
    }

    return p;
}



/*插入  链表尾插*/
Book_list * Insert_List(Book Book_Msg, Book_list *p)
{
    Book_list *point;

    /*创建一个新的节点*/
    Book_list * New_Node = (Book_list*)malloc(sizeof(Book_list));

    /*走到最后的节点*/
    point = p;
    while(point->Save_address != NULL)
    {
        point = point->Save_address;
        New_Node->Book_local++;
    }

    if(point->Save_address == NULL)
    {
        New_Node->Book_local++;
    }

    point->Save_address = New_Node;

    New_Node->Book_msg = Book_Msg;

    New_Node->Save_address = NULL;

    p->Book_cnt++;
    New_Node->Book_cnt++;  //与头结点保持一致    

    printf("\n展列当前链表：\n");

    point = p;

    while(point->Save_address != NULL || point->Save_address != 0)
    {
        printf("书名：%s   作者：%s   价格：%hd   所处位置：%hd\n",point->Save_address->Book_msg.Book_name, 
                                                              point->Save_address->Book_msg.Book_author, 
                                                              point->Save_address->Book_msg.Book_price,
                                                              point->Save_address->Book_local);
        point = point->Save_address;
    }

    printf("\n当前链表中书籍个数：%hd\n",p->Book_cnt);

    printf("\n*****************************************************************\n\n");

    return p;
}



/*插入  选择位置*/
Book_list *Insert_ChoiceLoc(Book Book_Msg, Book_list *p ,u_int16_t local)
{
    /*创建一个查找性指针*/
    Book_list * Book_point;
    Book_list * Bref_point;

    if(local > (p->Book_cnt))
    {
        printf("\n选择位置超出链表当前上限！\n");
        Free_ListMalloc(p);
        exit(ERROR);
    }

    /*创建一个新的节点*/
    Book_list * New_Node = (Book_list *)malloc(sizeof(Book_list));

    /*找到local位置*/
    Bref_point = p;
    Book_point = Bref_point->Save_address;  //头结点下第一个节点

    while(Book_point->Book_local < local)
    {
        Bref_point = Book_point;
        Book_point = Book_point->Save_address;
    }

    /*开始转换*/
    New_Node->Save_address = Book_point;
    Bref_point->Save_address = New_Node;

    New_Node->Book_msg = Book_Msg;

    /*修改Book_local*/
    New_Node->Book_local = local;

    while(New_Node->Save_address != NULL)
    {
        New_Node = New_Node->Save_address;    
        New_Node->Book_local++;    
    }

    p->Book_cnt++;
    New_Node->Book_cnt++;  //与头结点保持一致

    /*展列当前链表*/
    printf("\n展列当前链表：\n");

    Book_point = p;  //回到头结点
    while(Book_point->Save_address != NULL || Book_point->Save_address != 0)
    {
        printf("书名：%s   作者：%s   价格：%hd   所处位置：%hd\n",Book_point->Save_address->Book_msg.Book_name, 
                                                              Book_point->Save_address->Book_msg.Book_author, 
                                                              Book_point->Save_address->Book_msg.Book_price,
                                                              Book_point->Save_address->Book_local);
        Book_point = Book_point->Save_address;
    }

    printf("\n当前链表中书籍个数：%hd\n",p->Book_cnt);

    printf("\n*****************************************************************\n\n");

    return p;
}



/*删除  选择位置*/
Book_list *DeleteChoice(Book_list *p, u_int16_t local)
{
    Book_list * Delete_point;
    Book_list * Bref_Dele_point;
    Book_list * Aftr_Dele_point;
    Book_list * Book_point;

    if(local > p->Book_cnt)
    {
        printf("\n选择删除的位置不存在！\n");
        return p;
    }

    Delete_point = p;

    Delete_point = Delete_point->Save_address;  //移动至头结点下第一个节点

    Bref_Dele_point = p;  //删除节点的，前一个节点

    Aftr_Dele_point = Delete_point->Save_address;  //删除节点的，后一个节点

    while(Delete_point->Book_local < local)
    {
        Bref_Dele_point = Delete_point;
        Delete_point = Delete_point->Save_address;
        Aftr_Dele_point = Delete_point->Save_address;
    }

    Bref_Dele_point->Save_address = Aftr_Dele_point;
    Delete_point->Save_address = NULL;

    free(Delete_point);

    Delete_point = NULL;

    /*校正Book_local*/
    Aftr_Dele_point->Book_local--;
    while(Aftr_Dele_point->Save_address != NULL)
    {
        Aftr_Dele_point = Aftr_Dele_point->Save_address;
        Aftr_Dele_point->Book_local--;
    }


    /*展列当前链表*/
    printf("\n展列当前链表：\n");

    Book_point = p;  //回到头结点
    while(Book_point->Save_address != NULL || Book_point->Save_address != 0)
    {
        printf("书名：%s   作者：%s   价格：%hd   所处位置：%hd\n",Book_point->Save_address->Book_msg.Book_name, 
                                                              Book_point->Save_address->Book_msg.Book_author, 
                                                              Book_point->Save_address->Book_msg.Book_price,
                                                              Book_point->Save_address->Book_local);
        Book_point = Book_point->Save_address;
    }

    printf("\n当前链表中书籍个数：%hd\n",p->Book_cnt);

    printf("\n*****************************************************************\n\n");

    return p;
}