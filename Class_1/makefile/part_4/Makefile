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
Target=mp3



#可以通过OBJS来更改可重定位文件
OBJS=main.o mp3.o



$(Target):$(OBJS)
	$(Gcc_Compiler) $^ -o $@


#使用%匹配字符，优化编译过程
%.o:%.c
	$(Gcc_Compiler) -c $< -o $@




.PHONY:clean

clean_mp3:
	rm mp3 *.o
