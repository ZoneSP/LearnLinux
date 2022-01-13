#include "Sysctrl.h"

/* 函数名称：memset()  void *memset(void *str, int c, size_t n);
 * 函数功能：复制字符C到str指向字符串前n个字符
 * 函数示例：str[] = "ABCDEFG"，memset(str, '$', 4)   ->    "$$$$EFG"
 */

#define MAX_DATA_LEN   512

struct message
{
	long msg_type;
	char msg_list[MAX_DATA_LEN];
};


int main(int argc, char *argv[])
{
	int qid;
	key_t key;
	struct message msg;

	/*根据不同的路径和关键字产生的key*/
	/*路径和数字随意*/
	if((key = ftok("/home/zoey",66)) == -1)
	{
		printf("ftok函数创建key失败！\n");
		exit(1);
	}

	
	/*创建消息队列*/
	if((qid = msgget(key, IPC_CREAT|0666)) == -1)
	{
		printf("创建消息队列失败！\n");
		exit(1);
	}

	printf("当前消息队列的ID是：%d\n",qid);
	
	for(;;)
	{
		printf("请阁下输入随意信息：\n");
		if((fgets(msg.msg_list, MAX_DATA_LEN, stdin)) == NULL)
		{
			fputs("No message！\n",stdout);
			exit(1);
		}

		msg.msg_type = getpid();

		/*添加消息到消息队列，阻塞发送*/
		if((msgsnd(qid, &msg, strlen(msg.msg_list), 0)) < 0)
		{
			printf("message posted！\n");
			exit(1);
		}

		if(strncmp(msg.msg_list, "quit",4) == 0)
		{
			break;
		}
	}

	exit(0);
}








