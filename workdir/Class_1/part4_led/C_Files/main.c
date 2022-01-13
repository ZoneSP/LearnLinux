#include "Sysctrl.h"

/* 函数名称：exit()
 * 函数功能：关闭所有文件，中止正在执行的进程
 * 函数作用：exit(0)，exit(1~x)
 * 0代表正常退出，1~x均表示异常退出
 */

int main(int argc, char **argv)
{
	int res = 0;
	int r_fd, g_fd, b_fd;

	printf("This is the led demo\n");

	/*获取红灯的设备文件描述符*/
	r_fd = open(RLED_DEV_PATH, O_WRONLY);

	if(r_fd < 0)
	{
		printf("Fail to open %s device\n", RLED_DEV_PATH);
		exit(1);
	}


	/*获取绿灯的设备文件描述符*/
	g_fd = open(GLED_DEV_PATH, O_WRONLY);

	if(g_fd < 0)
	{
		printf("Fail to open %s device\n", GLED_DEV_PATH);
		exit(1);
	}


	/*获取蓝灯的设备文件描述符*/
	b_fd = open(BLED_DEV_PATH, O_WRONLY);

	if(b_fd < 0)
	{
		printf("Fail to open %s device\n", BLED_DEV_PATH);
		exit(1);
	}



	/*进入主循环*/
	for(;;)
	{
		/*红灯亮*/
		write(r_fd, "255", 3);
		/*延时1s*/
		sleep(1);
		/*红灯灭*/
		write(r_fd, "0", 1);

		/*绿灯亮*/
		write(g_fd, "255", 3);
		/*延时1s*/
		sleep(1);
		/*绿灯灭*/
		write(g_fd, "255", 1);

		/*蓝灯亮*/
		write(b_fd, "255", 3);
		/*延时1s*/
		sleep(1);
		/*蓝灯灭*/
		write(b_fd, "0", 1);
	}

	return 0;
}
