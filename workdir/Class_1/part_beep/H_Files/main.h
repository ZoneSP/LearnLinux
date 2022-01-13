#ifndef __MAIN_H
#define __MAIN_H

/*包含文件控制所需相关头文件*/
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/stat.h"
#include "sys/types.h"
#include "fcntl.h"


/*ARM开发板beep引脚相关define*/
#define Beep_GPIO_Pin   "19"

#define All_GPIO_API_DEV   "/sys/class/gpio/export"

#define Beep_GPIO_MODE_DEV  "/sys/class/gpio/gpio19/direction"

#define Beep_GPIO_voltage_DEV   "/sys/class/gpio/gpio19/value"


void Beep_init_Function(void);

void Beep_on(void);

void Beep_off(void);




#endif


