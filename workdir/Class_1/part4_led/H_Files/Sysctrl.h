#ifndef __SYSCTRL_H
#define __SYSCTRL_H

/*包含文件控制所需相关头文件*/
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/stat.h"
#include "sys/types.h"
#include "fcntl.h"


/*ARM开发板LED灯设备的路径*/
#define RLED_DEV_PATH   "/sys/class/leds/red/brightness"
#define GLED_DEV_PATH   "/sys/class/leds/green/brightness"
#define BLED_DEV_PATH   "/sys/class/leds/blue/brightness"



#endif


