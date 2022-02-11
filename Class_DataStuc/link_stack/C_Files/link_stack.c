#include "Sysctrl.h"

/*构造一个空栈*/
Plate_stack *InitStack(void)
{
    /*开辟头结点*/
    Plate_stack * HeadNode = (Plate_stack*)malloc(sizeof(Plate_stack));

    HeadNode->plates_cnt = 0;

    HeadNode->Saveaddress = NULL;

    return HeadNode;
}



/*向栈中压入数据*/
Plate_stack *Insert_plate(Plate_stack *Plate_stacklist, plate Plate_msg)
{
    /*创建一个新节点*/
    Plate_stack * Search_point;
    Plate_stack * NewNode = (Plate_stack *)malloc(sizeof(Plate_stack));

    NewNode->Plate_MSG = Plate_msg;

    /*移动到最后一个节点*/
    Search_point = Plate_stacklist;
    while(Search_point->Saveaddress != NULL)
    {
        Search_point = Search_point->Saveaddress;
    }

    Search_point->Saveaddress = NewNode;
    NewNode->Saveaddress = NULL;


    Plate_stacklist->plates_cnt++;

    /*展列当前链栈*/
    Search_point = Plate_stacklist;  //回到头节点
    Search_point = Search_point->Saveaddress;
    
    
    printf("\n");
    while(Search_point != NULL)
    {
        printf("尺寸：%hd   颜色：%s\n",Search_point->Plate_MSG.plate_size, Search_point->Plate_MSG.plate_color);
        Search_point = Search_point->Saveaddress;
    }
    printf("\n");

    return Plate_stacklist;
}



/*向栈中摘出数据*/
Plate_stack *Delete_plate(Plate_stack *Plate_stacklist)
{
    Plate_stack * Search_point;
    Plate_stack * Search_point_A;

    Search_point = Plate_stacklist;

    while(Search_point->Saveaddress->Saveaddress != NULL)
    {
        Search_point = Search_point->Saveaddress;
    }

    Search_point_A = Search_point->Saveaddress;

    free(Search_point_A);
    Search_point_A = NULL;

    Search_point->Saveaddress = NULL;

    Plate_stacklist->plates_cnt--;

    /*展列当前链栈*/
    Search_point = Plate_stacklist;  //回到头节点
    Search_point = Search_point->Saveaddress;

    printf("\n");
    while(Search_point != NULL)
    {
        printf("尺寸：%hd   颜色：%s\n",Search_point->Plate_MSG.plate_size, Search_point->Plate_MSG.plate_color);
        Search_point = Search_point->Saveaddress;
    }
    printf("\n");

    return Plate_stacklist;
}




/*释放开辟的内存*/
/*一个malloc申请的空间，一个free就能消掉*/
void FreeStackMemory(Plate_stack *Plate_stacklist)
{
    Plate_stack * point_A;
    Plate_stack * point_B;

    point_A = Plate_stacklist;
    point_B = point_A->Saveaddress;

    while(point_B != NULL)
    {
        free(point_A);
        point_A = point_B;
        point_B = point_A->Saveaddress;
    }
    free(point_A);

    point_A = NULL;
    point_B = NULL;

    printf("\n内存释放完毕！\n");
}

