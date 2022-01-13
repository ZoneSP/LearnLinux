#include "main.h"

/* 函数名称：exit()
 * 函数功能：关闭所有文件，中止正在执行的进程
 * 函数作用：exit(0)，exit(1~x)
 * 0代表正常退出，1~x均表示异常退出
 */

int main(int argc, char **argv)
{
	const char path[] = "/dev/input/by-path/platform-gpio-keys-event";
	int fd;
	struct input_event event;

	
	printf("This is a input test demo.\n");

	fd = open(path, O_RDONLY);

	if(fd != 3)
	{
		printf("OPEN file error !\n");
		close(fd);
		exit(1);
	}

	for(;;)
	{
		if(read(fd, &event, sizeof(event)) == sizeof(event))
		{
			if(event.type != EV_SYN)
			{
				printf("Event: Time %ld.%ld,type %d, code %d, value %d\n",event.time.tv_sec,event.time.tv_usec,
											  event.type,
											  event.code,
											  event.value);
			}
		}
	}

	close(fd);

	return 0;
}
