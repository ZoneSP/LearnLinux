#------------------------------编译器选择Start------------------------------
ARCH?=arm

ifeq ($(ARCH),arm)
	Gcc_Compiler=arm-linux-gnueabihf-gcc
else
	Gcc_Compiler=gcc
endif
#------------------------------编译器选择-END-------------------------------


#可以通过改变Target来切换目标
Target=execlp


#通过BUILD来确定编译后，生成的文件夹
BUILD_DIR=build


#获取源文件文件夹名称
SRC_DIR=C_Files


#获取头文件文件夹名称
INC_DIR=H_Files


#变量CFLAGS是GCC编译器的选择内容，GCC添加头文件的格式：gcc -I +"头文件路径"
CFLAGS=$(patsubst %,-I %,$(INC_DIR))


#创建新变量INCLUDES
INCLUDES=$(foreach Hfile_dir,$(INC_DIR),$(wildcard $(Hfile_dir)/*.h))


#使用SOURCES，便利寻找模块下所有文件
SOURCES=$(foreach cfile_dir,$(SRC_DIR),$(wildcard $(cfile_dir)/*.c))
OBJS=$(patsubst %.c,$(BUILD_DIR)/%.o,$(notdir $(SOURCES)))


#VPATH是系统变量，系统会从这个路径中寻找源文件所在路径
VPATH=$(SRC_DIR)


#使用%匹配字符，优化编译过程
$(BUILD_DIR)/%.o:%.c $(INCLUDES) | create_build
	$(Gcc_Compiler) -c $< -o $@ $(CFLAGS)


#最终生成文件出现在BUILD_DIR文件夹中
$(BUILD_DIR)/$(Target):$(OBJS)
	$(Gcc_Compiler) $^ -o $@


.PHONY:clean create_build


create_build:
	sudo mkdir -p $(BUILD_DIR)


clean:
	sudo rm led *.o
