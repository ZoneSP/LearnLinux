#include "Sysctrl.h"

/* 函数名称：memset()  void *memset(void *str, int c, size_t n);
 * 函数功能：复制字符C到str指向字符串前n个字符
 * 函数示例：str[] = "ABCDEFG"，memset(str, '$', 4)   ->    "$$$$EFG"
 */

#define MAX_DATA_LEN   512

/*创建一个消息类型结构体*/
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
	
	/*获取管道的key值*/
	/*注意与发送端路径，数字一致，以获取相同的key*/

	if((key = ftok("/home/zoey",66)) == -1)
	{
		printf("获取key失败！\n");
		exit(1);
	}

	/*获取消息队列ID*/
	if((qid = msgget(key, IPC_CREAT|0666)) == -1)
	{
		printf("获取消息队列ID失败！\n");
		exit(1);
	}


	do
	{
		/*读取消息队列*/
		/*将接收队列清0*/
		memset(msg.msg_list, 0, MAX_DATA_LEN);

		/*从消息队列中获取信息*/
		if(msgrcv(qid, &msg, MAX_DATA_LEN, 0, 0) < 0)
		{
			printf("从消息队列中读取消息失败！\n");
			exit(1);
		}

		printf("The message fron message id: %s\n",msg.msg_list);



	}while(strncmp(msg.msg_list, "quit", 4));

	/*从系统内核中移走消息队列*/
	if(msgctl(qid, IPC_RMID, NULL) < 0)
	{
		fputs("将消息队列移出内核失败！\n", stdout);
		exit(1);
	}

	exit(0);
}








