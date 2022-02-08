#include "Sysctrl.h"

Book_Doulist *Book_point;

int main(int argc, char *argv[])
{
	Book Book_MSG;

	/*初始化链表*/
	Book_point = Init_HeadNode();

	/*尾插  第一条Message*/
	strcpy(Book_MSG.Book_name, "C++");
	strcpy(Book_MSG.Book_author, "Stephen");
	Book_MSG.Book_price = 50;
	Book_point = Insert_List(Book_MSG,Book_point);

	/*尾插  第二条Message*/
	strcpy(Book_MSG.Book_name, "TCP/IP");
	strcpy(Book_MSG.Book_author, "Joe");
	Book_MSG.Book_price = 70;
	Book_point = Insert_List(Book_MSG,Book_point);

	/*位插  第三条Message  位置1*/
	strcpy(Book_MSG.Book_name, "插画集");
	strcpy(Book_MSG.Book_author, "若干爪");
	Book_MSG.Book_price = 180;
	Book_point = Insert_ChoiceLoc(Book_MSG, Book_point, 1);

	/*位插  第四条Message  位置2*/
	strcpy(Book_MSG.Book_name, "QT");
	strcpy(Book_MSG.Book_author, "QT Author");
	Book_MSG.Book_price = 101;
	Book_point = Insert_ChoiceLoc(Book_MSG, Book_point, 2);

	/*位删  第一条Message  位置1*/
	Book_point = DeleteChoice(Book_point, 1);

	/*位删  第二条Message  位置2*/
	Book_point = DeleteChoice(Book_point, 2);

	/*释放内存*/
	Free_ListMalloc(Book_point);
	return 0;
}
