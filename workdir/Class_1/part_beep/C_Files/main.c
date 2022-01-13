#include "main.h"

/* 函数名称：exit()
 * 函数功能：关闭所有文件，中止正在执行的进程
 * 函数作用：exit(0)，exit(1~x)
 * 0代表正常退出，1~x均表示异常退出
 */

int main(int argc, char **argv)
{
	int order;

	Beep_init_Function();

	for(;;)
	{
		printf("Please input your order: \n");

		scanf("%d",&order);

		switch(order)
		{
			case 0:
				Beep_off();
				break;
			case 1:
				Beep_on();
				break;
			default:
				break;
		}

		if(order == 3)
		{
			break;
		}
	}

	printf("Program dead ! \n");

	return 0;
}




void Beep_on(void)
{
	int fd;

	fd = open(Beep_GPIO_voltage_DEV, O_WRONLY);

	if(fd != 3)
	{
		printf("Open value file error! \n");
		close(fd);
		exit(1);
	}
	
	write(fd, "1", 1);

	close(fd);
}




void Beep_off(void)
{
        int fd;

        fd = open(Beep_GPIO_voltage_DEV, O_WRONLY);

        if(fd != 3)     
        {
                printf("Open value file error! \n");
                close(fd);
                exit(1);
        }       

        write(fd, "0", 1);

        close(fd);
}




void Beep_init_Function(void)
{
	/*1.从export文件里将gpio硬件外设文件导出来*/
	/*2.将GPIO配置成输出模式*/
	/*3. export和unexort都是只允许写入，不可读取*/

	/*~~~~~~~~~~~~~~~~~~~export文件部分~~~~~~~~~~~~~~~~~~~~*/
	int fd;

	fd = open(All_GPIO_API_DEV, O_WRONLY);  //只写模式

	if(fd != 3)
	{
		printf("Fail to open file !\n");
		close(fd);
		exit(1);
	}

	
	write(fd, Beep_GPIO_Pin, 2);	

	close(fd);  //关闭export文件

	/*~~~~~~~~~~~~~~~~~~~export文件部分~~~~~~~~~~~~~~~~~~~~*/



	/*-------------------direction文件部分--------------------*/
	fd = open(Beep_GPIO_MODE_DEV,O_RDWR);  //读写模式

	if(fd != 3)
	{
		printf("Fail to open direction file !\n");
		close(fd);
		exit(1);
	}

	write(fd, "out", 3);

	close(fd);

	/*-------------------direction文件部分--------------------*/
}
