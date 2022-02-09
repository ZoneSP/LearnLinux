#include "Sysctrl.h"

/*构造一个空栈*/
Plate_stack InitStack(Plate_stack Plate_stacklist)
{
    Plate_stacklist.Save_address = (plate *)malloc(MAX_plate_cnt * sizeof(plate));  //申请MAX_plate_cnt个空间的数组

    if(Plate_stacklist.Save_address == 0)
    {
        exit(ERROR);
    }

    Plate_stacklist.base = Plate_stacklist.Save_address;
    Plate_stacklist.top = Plate_stacklist.base;
    Plate_stacklist.stacksize = MAX_plate_cnt;
    Plate_stacklist.plates_cnt = 0;

    return Plate_stacklist;
}



/*向栈中压入数据*/
Plate_stack Insert_plate(Plate_stack Plate_stacklist, plate Plate_msg)
{
    plate * Search_point;

    if(Plate_stacklist.plates_cnt == MAX_plate_cnt)
    {
        printf("\n顺序栈已满！\n");
        return Plate_stacklist;
    }

    /*数据插入*/
    *(Plate_stacklist.top) = Plate_msg;

    /*更新栈中数据个数*/
    Plate_stacklist.plates_cnt++;

    /*是否满栈，未满top指针后移*/
    if(Plate_stacklist.plates_cnt != MAX_plate_cnt)
    {
        Plate_stacklist.top = Plate_stacklist.top + 1;
    }

    /*展列当前顺序栈*/
    Search_point = Plate_stacklist.base;
    while(Plate_stacklist.top != Search_point)
    {
        printf("盘子大小：%hd   盘子颜色：%s\n",Search_point->plate_size, Search_point->plate_color);
        Search_point = Search_point + 1;
    }

    printf("\n");

    return Plate_stacklist;
}



/*向栈中摘出数据*/
Plate_stack Delete_plate(Plate_stack Plate_stacklist)
{
    u_int16_t Loop = 0;
    plate * Search_point;

    /*判断是否空栈*/
    if(Plate_stacklist.base == Plate_stacklist.top)
    {
        printf("\n栈已空！\n");
        return Plate_stacklist;
    }

    /*删除栈顶*/
    Plate_stacklist.top = Plate_stacklist.top - 1;  /*回到有数据的位置*/
    Plate_stacklist.top->plate_size = 10;
    for(Loop=0;Loop<50;Loop++)
    {
        Plate_stacklist.top->plate_color[Loop] = 0;
    }

    /*展列当前顺序栈*/
    printf("\n数据删除成功！\n\n");
    if(Plate_stacklist.top != Plate_stacklist.base)
    {
        Search_point = Plate_stacklist.base;
        while(Plate_stacklist.top != Search_point)
        {
            printf("盘子大小：%hd   盘子颜色：%s\n",Search_point->plate_size, Search_point->plate_color);
            Search_point = Search_point + 1;
        }
    }
    else
    {
        printf("此刻栈为空！\n\n");
    }

    return Plate_stacklist;
}




/*释放开辟的内存*/
/*一个malloc申请的空间，一个free就能消掉*/
void FreeStackMemory(Plate_stack Plate_stacklist)
{
    free(Plate_stacklist.Save_address);
    printf("\n内存释放完毕！\n");
}

