#ifndef SYSCTRL_H
#define SYSCTRL_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX_plate_cnt   255
#define ERROR   1

typedef struct 
{
    u_int16_t plate_size;
    char plate_color[50];
}plate;


typedef struct 
{
    plate * base;
    plate * top;
    plate * Save_address;

    u_int16_t stacksize;
    u_int16_t plates_cnt; 
}Plate_stack;

extern Plate_stack Plates_Satck;



Plate_stack InitStack(Plate_stack Plate_stacklist);
void FreeStackMemory(Plate_stack Plate_stacklist);
Plate_stack Insert_plate(Plate_stack Plate_stacklist, plate Plate_msg);
Plate_stack Delete_plate(Plate_stack Plate_stacklist);


#endif


