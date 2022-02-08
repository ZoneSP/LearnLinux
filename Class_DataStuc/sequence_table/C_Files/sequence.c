#include "Sysctrl.h"

/*小功能  清空结构体Book*/
Book Clean_BookStruct(Book Book_Msg)
{
    unsigned char Loop = 0;

    for(Loop=0;Loop<50;Loop++)
    {
        Book_Msg.Book_author[Loop] = 0;
        Book_Msg.Book_name[Loop] = 0;
    }
    Book_Msg.Book_price = 0;

    return Book_Msg;
}



/*构造  空的顺序表*/
Book_sequTable InitList(Book_sequTable Book_list)
{
    Book_list.Save_address = (Book *)malloc(MAX_Bookcnt*sizeof(Book));  //申请MAX_Bookcnt个Book大小的数组空间
    if(Book_list.Save_address == 0)
    {
        printf("错误：初始化顺序表失败！\n");
        exit(ERROR);
    }

    Book_list.Book_cnt = 0;     //初始化空表长度为0

    return Book_list;
}



/*插入  在顺序表尾*/
Book_sequTable ListInsert(Book_sequTable Book_list, Book Book_Msg)
{
    if((Book_list.Book_cnt+1) == MAX_Bookcnt)
    {
        printf("错误：顺序表已达到最大长度，插入失败！\n");
        return Book_list;
    }

    Book_list.Save_address[Book_list.Book_cnt] = Book_Msg;

    /*开始插入信息*/
    // memcpy(Book_list.Save_address[Book_list.Book_cnt].Book_author, Book_Msg.Book_author, sizeof(Book_Msg.Book_author));
    // Book_list.Save_address[Book_list.Book_cnt].Book_price = Book_Msg.Book_price;
    // memcpy(Book_list.Save_address[Book_list.Book_cnt].Book_name, Book_Msg.Book_name, sizeof(Book_Msg.Book_name));

    Book_list.Book_cnt++;
    printf("Book_list_cnt：%hd\n",Book_list.Book_cnt);

    if(Book_list.Book_cnt == (MAX_Bookcnt-1))
    {
        printf("提示：顺序表已满！\n");        
    }

    printf("展列当前顺序表：\n");
    for(int for_Loop=0;for_Loop<Book_list.Book_cnt;for_Loop++)
    {
        printf("图书名称：%s  作者：%s  售价：%hd 元\n",Book_list.Save_address[for_Loop].Book_name, Book_list.Save_address[for_Loop].Book_author, Book_list.Save_address[for_Loop].Book_price);
    }
    printf("******************************************************************\n");
    printf("\n\n");

    return Book_list;
}



/*插入  选择位置*/
Book_sequTable ListChoiceInsert(Book_sequTable Book_list, Book Book_Msg, unsigned char local)
{
    Book Middle_Msg;
    unsigned char Loop = Book_list.Book_cnt + 1;


    if((Book_list.Book_cnt + 1) == MAX_Bookcnt)
    {
        printf("错误：顺序表已达到最大长度，插入失败！\n");
        return Book_list;
    }

    if(local <= 0 || local > MAX_Bookcnt)
    {
        printf("错误：顺序表已达到最大长度，插入失败！\n");
        return Book_list;
    }

    /*开始插入信息*/
    for(Loop;Loop>=local;Loop--)
    {
        memcpy(Book_list.Save_address[Loop].Book_author, Book_list.Save_address[Loop-1].Book_author, sizeof(Book_list.Save_address[Loop-1].Book_author));
        memcpy(Book_list.Save_address[Loop].Book_name, Book_list.Save_address[Loop-1].Book_name, sizeof(Book_list.Save_address[Loop-1].Book_name));
        Book_list.Save_address[Loop].Book_price = Book_list.Save_address[Loop-1].Book_price;
    }

    memcpy(Book_list.Save_address[local-1].Book_author, Book_Msg.Book_author, sizeof(Book_Msg.Book_author));
    memcpy(Book_list.Save_address[local-1].Book_name, Book_Msg.Book_name, sizeof(Book_Msg));
    Book_list.Save_address[local-1].Book_price = Book_Msg.Book_price;

    Book_list.Book_cnt++;
    printf("Book_list_cnt：%hd\n",Book_list.Book_cnt);

    if(Book_list.Book_cnt == (MAX_Bookcnt-1))
    {
        printf("提示：顺序表已满！\n");        
    }


    printf("展列当前顺序表：\n");
    for(int for_Loop=0;for_Loop<Book_list.Book_cnt;for_Loop++)
    {
        printf("图书名称：%s  作者：%s  售价：%hd 元\n",Book_list.Save_address[for_Loop].Book_name, Book_list.Save_address[for_Loop].Book_author, Book_list.Save_address[for_Loop].Book_price);
    }
    printf("\n");

    return Book_list;
}



/*删除  选择位置*/
Book_sequTable ListChoiceDelete(Book_sequTable Book_list, unsigned char local)
{
    unsigned char Loop;

    if(local > Book_list.Book_cnt)
    {
        printf("此位置为空\n");
        return Book_list;
    }

    /*删除作业开始*/
    for(Loop=local;Loop<Book_list.Book_cnt;Loop++)
    {
        Book_list.Save_address[local-1] = Book_list.Save_address[local];
    }

    Book_list.Save_address[Book_list.Book_cnt-1] = Clean_BookStruct(Book_list.Save_address[Book_list.Book_cnt-1]);
    Book_list.Book_cnt--;

    /*打印当前顺序表*/
    printf("展列当前顺序表：\n");
    for(int for_Loop=0;for_Loop<Book_list.Book_cnt;for_Loop++)
    {
        printf("图书名称：%s  作者：%s  售价：%hd 元\n",Book_list.Save_address[for_Loop].Book_name, Book_list.Save_address[for_Loop].Book_author, Book_list.Save_address[for_Loop].Book_price);
    }
    printf("\n");
    return Book_list;
}



/*查询  选择位置*/
void ListSearch(Book_sequTable Book_list, unsigned char local)
{
    if((local-1) >= Book_list.Book_cnt || (local-1) < 0)
    {
        printf("选择位置为空！\n");
    }
    else
    {
        printf("图书名称：%s\n",Book_list.Save_address[local-1].Book_name);
        printf("作者：%s\n",Book_list.Save_address[local-1].Book_author);
        printf("售价：%hd\n\n", Book_list.Save_address[local-1].Book_price);
    }
}



/*展列  当前顺序表*/
void ListShow(Book_sequTable Book_list)
{
    for(int for_Loop=0;for_Loop<Book_list.Book_cnt;for_Loop++)
    {
        printf("图书名称：%s  作者：%s  售价：%hd 元\n",Book_list.Save_address[for_Loop].Book_name, Book_list.Save_address[for_Loop].Book_author, Book_list.Save_address[for_Loop].Book_price);
    }
    printf("\n");
}