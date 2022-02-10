#include "Sysctrl.h"

Chat_queue * BulletChat_Queue;

int main(int argc, char *argv[])
{
	Bullet_chat   CHAT_MSG;

	/*构建头结点*/
	BulletChat_Queue = InitChatQueue();

	/*向队列中插入一条信息*/
	strcpy(CHAT_MSG.chat_message, "冰墩墩，雪融容，好耶！");
	strcpy(CHAT_MSG.chat_owner, "可莉");
	BulletChat_Queue = InsertQueue(BulletChat_Queue, CHAT_MSG);

	/*向队列中插入一条信息*/
	strcpy(CHAT_MSG.chat_message, "骑士团的大家，都有在好好工作吧！");
	strcpy(CHAT_MSG.chat_owner, "琴");
	BulletChat_Queue = InsertQueue(BulletChat_Queue, CHAT_MSG);

	/*向队列中插入一条信息*/
	strcpy(CHAT_MSG.chat_message, "年说的不错，这千秋大梦，早该醒了。");
	strcpy(CHAT_MSG.chat_owner, "令");
	BulletChat_Queue = InsertQueue(BulletChat_Queue, CHAT_MSG);

	/*删除列中的一条消息*/
	BulletChat_Queue = Delete_Queue(BulletChat_Queue);

	/*向队列中插入一条信息*/
	strcpy(CHAT_MSG.chat_message, "更快，更高，更强");
	strcpy(CHAT_MSG.chat_owner, "巴赫");
	BulletChat_Queue = InsertQueue(BulletChat_Queue, CHAT_MSG);

	/*删除列中的一条消息*/
	BulletChat_Queue = Delete_Queue(BulletChat_Queue);

	/*删除列中的一条消息*/
	BulletChat_Queue = Delete_Queue(BulletChat_Queue);

	/*删除列中的一条消息*/
	BulletChat_Queue = Delete_Queue(BulletChat_Queue);

	/*删除列中的一条消息*/
	BulletChat_Queue = Delete_Queue(BulletChat_Queue);

	/*释放内存*/
	FreeMemory(BulletChat_Queue);

	return 0;
}
