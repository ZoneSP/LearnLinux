#ifndef SYSCTRL_H
#define SYSCTRL_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX_bullet_chat_cnt   4
#define ERROR   1


/*bullet chat*/
typedef struct 
{
    char chat_message[80];
    char chat_owner[20];
}Bullet_chat;


/*bullet_queue*/
typedef struct 
{
    Bullet_chat * Save_address;
    Bullet_chat * top_point;
    Bullet_chat * base_point;

    u_int8_t bullet_chat_cnt;
}Chat_queue;

extern Chat_queue BulletChat_Queue;


Chat_queue InitChatQueue(Chat_queue CHAT_QUEUE);
Chat_queue InsertQueue(Chat_queue Queue, Bullet_chat MSG);
void FreeMemory(Chat_queue Queue);
Chat_queue Delete_Queue(Chat_queue Queue);


#endif


