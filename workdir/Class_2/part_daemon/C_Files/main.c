#include "Sysctrl.h"

/* 函数名称：exit()
 * 函数功能：关闭所有文件，中止正在执行的进程
 * 函数作用：exit(0)，exit(1~x)
 * 0代表正常退出，1~x均表示异常退出
 */

#define MAXFILE   3

int main(void)
{
	pid_t pid;
	int fd,len,i,num;
	char *buf = "The daemon is running!\n";

	len = strlen(buf) + 1;
	printf("len: %d\n",len);

	/*1. 创建子进程，销毁父进程*/
	pid = fork();
	
	if(pid < 0)
	{
		printf("创建子进程失败！\n");
		exit(1);  //异常退出
	}
	else if(pid > 0)
	{
		printf("父进程即将被销毁！\n");
		exit(0);  //正常退出
	}
	else
	{
		printf("进入子进程！\n");
		/*2. 创建新会话，摆脱终端影响*/
		setsid();

		/*3. 改变当前文件目录*/
		chdir("/");
		
		/*4. 重设权限掩码*/
		umask(0);  //不关闭任何权限

		/*5. 关闭默认的文件描述符，即系统创建的0，1，2*/
		for(i=0;i<MAXFILE;i++)
		{
			close(i);
		}	

		/*6. 实现守护进程的功能*/
		for(;;)
		{
			fd = open("/var/log/daemon.log", O_CREAT | O_WRONLY | O_APPEND, 0666);
			write(fd, buf, len);
			close(fd);
			sleep(5);
		}
	}


}
