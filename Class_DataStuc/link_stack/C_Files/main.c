#include "Sysctrl.h"

Plate_stack *Plates_Satck;

int main(int argc, char *argv[])
{
	plate Plate_Msg;

	/*开辟一个空栈*/
	Plates_Satck = InitStack();
	
	/*向栈中添加信息*/
	Plate_Msg.plate_size = 14;
	strcpy(Plate_Msg.plate_color, "红色");
	Plates_Satck = Insert_plate(Plates_Satck, Plate_Msg);

	/*向栈中添加信息*/
	Plate_Msg.plate_size = 25;
	strcpy(Plate_Msg.plate_color, "蓝色");
	Plates_Satck = Insert_plate(Plates_Satck, Plate_Msg);

	/*向栈中添加信息*/
	Plate_Msg.plate_size = 17;
	strcpy(Plate_Msg.plate_color, "白色");
	Plates_Satck = Insert_plate(Plates_Satck, Plate_Msg);

	/*删除一个信息*/
	Plates_Satck = Delete_plate(Plates_Satck);

	/*删除一个信息*/
	Plates_Satck = Delete_plate(Plates_Satck);

	/*删除一个信息*/
	Plates_Satck = Delete_plate(Plates_Satck);

	/*释放内存*/
	FreeStackMemory(Plates_Satck);

	return 0;
}
