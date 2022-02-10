#include "Sysctrl.h"

/*构建顺序队列*/
Chat_queue InitChatQueue(Chat_queue CHAT_QUEUE)
{
    /*开辟空间*/
    CHAT_QUEUE.Save_address = (Bullet_chat*)malloc(MAX_bullet_chat_cnt * sizeof(Bullet_chat));

    if(CHAT_QUEUE.Save_address == NULL || CHAT_QUEUE.Save_address == 0)
    {
        printf("构建队列失败！\n");
        exit(ERROR);
    }

    CHAT_QUEUE.base_point = CHAT_QUEUE.Save_address;
    CHAT_QUEUE.top_point = CHAT_QUEUE.base_point;

    CHAT_QUEUE.bullet_chat_cnt = 0;

    return CHAT_QUEUE;
}



/*释放所有申请内存*/
void FreeMemory(Chat_queue Queue)
{
    free(Queue.Save_address);

    printf("\n释放内存成功！\n");
}



/*向队列中插入数据*/
Chat_queue InsertQueue(Chat_queue Queue, Bullet_chat MSG)
{
    if(Queue.bullet_chat_cnt == MAX_bullet_chat_cnt)
    {
        printf("\n队列已满！\n");
        return Queue;
    }

    *(Queue.top_point) = MSG;

    Queue.bullet_chat_cnt++;
    if(Queue.bullet_chat_cnt > MAX_bullet_chat_cnt)
    {
        printf("提示：队列已满！\n");
    }
    else
    {
        Queue.top_point = Queue.top_point + 1;
    }

    printf("\n当前队列内容为：\n");
    for(int Loop=0;Loop<Queue.bullet_chat_cnt;Loop++)
    {
        printf("%s：  %s\n",Queue.Save_address[Loop].chat_owner, Queue.Save_address[Loop].chat_message);
    }

    return Queue;
}



/*从队列中删除一个信息*/
Chat_queue Delete_Queue(Chat_queue Queue)
{
    if(Queue.top_point == Queue.base_point)
    {
        printf("\n队列已空！\n");
        return Queue;
    }

    Queue.top_point = Queue.top_point - 1;  //回到有数据的地方
    
    for(int Loop=0;Loop<80;Loop++)
    {
        Queue.top_point->chat_message[Loop] = 0;
    }

    for(int Loop=0;Loop<20;Loop++)
    {
        Queue.top_point->chat_owner[Loop] = 0;
    }

    Queue.bullet_chat_cnt--;

    printf("\n当前队列内容为：\n");
    for(int Loop=0;Loop<Queue.bullet_chat_cnt;Loop++)
    {
        printf("%s：  %s\n",Queue.Save_address[Loop].chat_owner, Queue.Save_address[Loop].chat_message);
    }

    return Queue;
}