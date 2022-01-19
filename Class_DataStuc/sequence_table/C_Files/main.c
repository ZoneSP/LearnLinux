#include "Sysctrl.h"

Book_sequTable   Books;

int main(int argc, char *argv[])
{
	char input_word;
	Book Book_Msg;
	char local;
	char ch;
	char Loop = 0;


	for(;;)
	{	
		Book_Msg = Clean_BookStruct(Book_Msg);  //清空Book_Msg
		printf("请按照下列指示操作：\n");
		printf("a. 初始化顺序表\n");
		printf("b. 向顺序表尾添加一组信息\n");
		printf("c. 向顺序表特定位置添加一组信息\n");
		printf("d. 删除顺序表特定位置的信息\n");
		printf("e. 查询顺序表特定位置的信息\n");
		printf("f. 展列当前顺序表\n");
		printf("\n");

		scanf("%c",&input_word);

		switch (input_word)
		{
			case 'a':
				Books = InitList(Books);
				while((ch = getchar()) != '\n');  /*清空缓冲区*/
				break;

			case 'b':
				while((ch = getchar()) != '\n');  /*清空缓冲区*/
				printf("书籍名称：\n");
				Loop = 0;
				while((ch = getchar()) != '\n')
				{
					Book_Msg.Book_name[Loop] = ch;
					Loop++;
				}

				printf("\n作者：\n");
				Loop = 0;
				while((ch = getchar()) != '\n')
				{
					Book_Msg.Book_author[Loop] = ch;
					Loop++;
				}
				
				printf("\n售价：\n");
				scanf("%hd",&Book_Msg.Book_price);
				while((ch = getchar()) != '\n');  /*清空缓冲区*/
				Books = ListInsert(Books, Book_Msg);
				break;
			
			case 'c':
				while((ch = getchar()) != '\n');  /*清空缓冲区*/
				printf("书籍名称：\n");
				Loop = 0;
				while((ch = getchar()) != '\n')
				{
					Book_Msg.Book_name[Loop] = ch;
					Loop++;
				}

				printf("\n作者：\n");
				Loop = 0;
				while((ch = getchar()) != '\n')
				{
					Book_Msg.Book_author[Loop] = ch;
					Loop++;
				}
				
				printf("\n售价：\n");
				scanf("%hd",&Book_Msg.Book_price);
				while((ch = getchar()) != '\n');  /*清空缓冲区*/

				printf("\n插入位置：\n");
				scanf("%hhd",&local);
				while((ch = getchar()) != '\n');  /*清空缓冲区*/
				Books = ListChoiceInsert(Books, Book_Msg, local);
				break;
			
			case 'd':
				while((ch = getchar()) != '\n');  /*清空缓冲区*/
				printf("请选择删除编号：\n");
				scanf("%hhd",&local);
				while((ch = getchar()) != '\n');  /*清空缓冲区*/
				Books = ListChoiceDelete(Books, local);
				break;
			
			case 'e':
				while((ch = getchar()) != '\n');  /*清空缓冲区*/
				printf("请选择查询编号：\n");
				scanf("%hhd",&local);
				while((ch = getchar()) != '\n');  /*清空缓冲区*/
				ListSearch(Books, local);
				break;

			case 'f':
				while((ch = getchar()) != '\n');  /*清空缓冲区*/
				ListShow(Books);
				break;
			default:
				break;
		}

		if(input_word == 'z')
		{
			break;
		}
	}

	free(Books.Save_address);
	return 0;
}	
