#include "Sysctrl.h"

/*构建队列头节点*/
Chat_queue * InitChatQueue(void)
{
    Chat_queue * HeadNode = (Chat_queue *)malloc(sizeof(Chat_queue));

    if(HeadNode == 0 || HeadNode == NULL)
    {
        printf("申请队列失败！\n");
        exit(ERROR);
    }

    HeadNode->Save_address = NULL;

    return HeadNode;
}



/*释放所有申请内存*/
void FreeMemory(Chat_queue * Queue)
{
    Chat_queue * point_A;
    Chat_queue * point_B;

    point_A = Queue;
    point_B = point_A->Save_address;

    while(point_B != NULL)
    {
        free(point_A);
        point_A = point_B;
        point_B = point_A->Save_address;
    }
    free(point_A);

    point_A = NULL;
    point_B = NULL;

    printf("\n释放内存成功！\n");
}



/*向队列中插入数据*/
Chat_queue * InsertQueue(Chat_queue * Queue, Bullet_chat MSG)
{
    Chat_queue * Search_point;
    /*创建新节点*/
    Chat_queue * NewNode = (Chat_queue *)malloc(sizeof(Chat_queue));

    /*从头结点，找到最后一个节点*/
    Search_point = Queue;
    while(Search_point->Save_address != NULL)
    {
        Search_point = Search_point->Save_address;
    }

    NewNode->Message = MSG;
    NewNode->Save_address = NULL;
    Search_point->Save_address = NewNode;

    /*从头结点开始，展列队列*/
    Search_point = Queue->Save_address;
    printf("\n当前队列为：\n");
    while(Search_point != NULL)
    {
        printf("%s： %s\n", Search_point->Message.chat_owner, Search_point->Message.chat_message);
        Search_point = Search_point->Save_address;
    }
    printf("\n");

    return Queue;
}



/*从队列中删除一个信息*/
Chat_queue * Delete_Queue(Chat_queue * Queue)
{
    Chat_queue * Search_point;
    Chat_queue * Delete_point;

    Search_point = Queue;

    if(Search_point->Save_address == NULL)
    {
        printf("\n队列已空，无需删除！\n");
        return Queue;
    }

    Delete_point = Search_point->Save_address;
    Search_point = Search_point->Save_address->Save_address;

    free(Delete_point);
    Delete_point = NULL;

    if(Search_point == NULL)
    {
        Queue->Save_address = NULL;
    }
    else
    {
        Queue->Save_address = Search_point;
    }

    /*从头结点开始，展列队列*/
    Search_point = Queue->Save_address;

    printf("\n当前队列为：\n");
    while(Search_point != NULL)
    {
        printf("%s： %s\n", Search_point->Message.chat_owner, Search_point->Message.chat_message);
        Search_point = Search_point->Save_address;
    }
    printf("\n");

    return Queue;
}