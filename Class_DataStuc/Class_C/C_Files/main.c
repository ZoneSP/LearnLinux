#include "Sysctrl.h"

int main(int argc,char *argv[])
{
	char ch;
	
	char Book_name[50] = {0};

	char Loop = 0;

	while((ch = getchar()) != '\n')
	{
		Book_name[Loop] = ch;
		Loop++;
	}

	printf("书籍名称：%s\n",Book_name);

	Loop = 0;
	
	while((ch = getchar()) != '\n')
	{
		Book_name[Loop] = ch;
		Loop++;
	}


	printf("书籍名称：%s\n",Book_name);


	

	return 0;
}
