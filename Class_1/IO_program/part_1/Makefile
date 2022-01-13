#--------------------------编译器选择Start----------------------------

#可以通过改变Gcc_Compiler来决定，是使用GCC还是ARM-GCC
#part_4更新，使用ifeq来判断当前是x86架构还是ARM架构

ARCH?=x86

ifeq ($(ARCH),x86)
	Gcc_Compiler=gcc
else
	Gcc_Compiler=arm-linux-gnueabihf-gcc
#	Gcc_Compiler=gcc
endif

#---------------------------编译器选择End-----------------------------



#可以通过改变Target来切换目标
Target=open_close



#可以通过OBJS来更改可重定位文件
#OBJS=main.o mp3.o



#通过BUILD来确定编译后，生成的文件夹
BUILD_DIR=build



#将mp3.c这类资源C文件放入moudle1，main.c这类C文件放入moudle2，获取这两个模块的路径
SRC_DIR=C_Files



#INC_DIR用来记录头文件所在的文件夹
INC_DIR=include_files



#变量CFLAGS是GCC编译器的选择内容，GCC添加头文件格式为：gcc -I +"头文件路径"
#CFLAGS记得添加进模式规则中
CFLAGS=$(patsubst %,-I %,$(INC_DIR))



#创建新变量INCLUDES，用于遍历更新头文件
INCLUDES=$(foreach include_dir,$(INC_DIR),$(wildcard $(include_dir)/*.h))



#使用SOURCES，便利寻找模块下所有文件
SOURCES=$(foreach dir,$(SRC_DIR),$(wildcard $(dir)/*.c))
OBJS=$(patsubst %.c,$(BUILD_DIR)/%.o,$(notdir $(SOURCES)))

#VPATH是系统变量，系统会从这个路径中寻找源文件的所在路径
VPATH=$(SRC_DIR)



#使用%匹配字符，优化编译过程
#%.o:%.c
$(BUILD_DIR)/%.o:%.c $(INCLUDES) | create_build
	$(Gcc_Compiler) -c $< -o $@ $(CFLAGS)



#最终生成文件出现在BUILD_DIR文件夹中
$(BUILD_DIR)/$(Target):$(OBJS)
	$(Gcc_Compiler) $^ -o $@



.PHONY:clean create_build


create_build:
	sudo mkdir -p $(BUILD_DIR)

clean_mp3:
	sudo rm mp3 *.o
