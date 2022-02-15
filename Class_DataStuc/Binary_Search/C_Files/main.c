#include "Sysctrl.h"

/*二分查找*/

int main(int argc, char *argv[])
{
	int Array_list[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

	int result = Binary_Search(Array_list, 15, 1);

	if(result)
	{
		printf("存在于列表之中!\n\n");
	}
	else
	{
		printf("列表中不存在！\n\n");
	}

	return 0;
}
