#include "Sysctrl.h"

/* 函数名称：memset()  void *memset(void *str, int c, size_t n);
 * 函数功能：复制字符C到str指向字符串前n个字符
 * 函数示例：str[] = "ABCDEFG"，memset(str, '$', 4)   ->    "$$$$EFG"
 */

#define MAX_DATA_LEN   256

void Signal_call_Function(int signo);

int main(int argc, char *argv[])
{
	if(signal(SIGINT,Signal_call_Function) == SIG_ERR)
	{
		printf("调用Signal函数错误！\n");
	}

	for(;;);

	exit(0);
}


void Signal_call_Function(int signo)
{
	sigset_t set;  /*创建信号集set*/

	sigemptyset(&set); /*将信号集合初始化为0*/

	sigaddset(&set, SIGINT); /*将SIGINT添加进信号集*/

	sigprocmask(SIG_UNBLOCK,&set, NULL);  /*解除SIGINT的屏蔽*/
	
	printf("Hello \n");

	sleep(5);

	printf("World!\n");
}
