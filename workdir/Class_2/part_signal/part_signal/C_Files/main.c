#include "Sysctrl.h"

/* 函数名称：memset()  void *memset(void *str, int c, size_t n);
 * 函数功能：复制字符C到str指向字符串前n个字符
 * 函数示例：str[] = "ABCDEFG"，memset(str, '$', 4)   ->    "$$$$EFG"
 */

#define MAX_DATA_LEN   256

void Signal_Sampling_Function(int signo);

int main(int argc, char *argv[])
{
	if(signal(SIGHUP, Signal_Sampling_Function) == SIG_ERR)
	{
		printf("SIGUSR1 error happend!\n");
	}

	if(signal(SIGUSR2, Signal_Sampling_Function) == SIG_ERR)
	{
		printf("SIGUSR2 error happend!\n");
	}

	for(;;)
	{
		pause();
	}
}



void Signal_Sampling_Function(int signo)
{
	if(signo == SIGHUP)
	{
		printf("Receive SIGHUP\n");
	}

	if(signo == SIGUSR2)
	{
		printf("Receive SIGUSR2\n");
	}
}
