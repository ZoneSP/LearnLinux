#include "Sysctrl.h"

/*创建一个指针*/
Book_list *Book_point;

int main(int argc, char *argv[])
{
	Book Book_MSG;

	Book_point = Init_HeadNode();


	/*顺序尾插第一个信息*/
	strcpy(Book_MSG.Book_name, "C++");
	strcpy(Book_MSG.Book_author, "Stephen");
	Book_MSG.Book_price = 50;
	Book_point = Insert_List(Book_MSG, Book_point);

	/*选择插入第二个信息   位置：链表队首*/
	strcpy(Book_MSG.Book_name, "数据结构");
	strcpy(Book_MSG.Book_author, "严蔚敏");
	Book_MSG.Book_price = 30;
	Book_point = Insert_ChoiceLoc(Book_MSG, Book_point, 1);

	/*顺序尾插第三个信息*/
	strcpy(Book_MSG.Book_name, "TCP/IP 经典");
	strcpy(Book_MSG.Book_author, "Joe");
	Book_MSG.Book_price = 78;
	Book_point = Insert_List(Book_MSG, Book_point);

	/*选择插入第四个信息   位置：第三顺位*/
	strcpy(Book_MSG.Book_name, "走进钱学森");
	strcpy(Book_MSG.Book_author, "叶永烈");
	Book_MSG.Book_price = 68;
	Book_point = Insert_ChoiceLoc(Book_MSG, Book_point, 3);

	/*删除队首信息*/
	Book_point = DeleteChoice(Book_point, 3);

	Free_ListMalloc(Book_point);

	return 0;
}	
