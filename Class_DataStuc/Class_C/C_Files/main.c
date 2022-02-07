#include "Sysctrl.h"

typedef struct Struct_B
{
	int b;
	struct Struct_B * Node;
}B;

B   List_B;

int main(int argc,char *argv[])
{
	List_B.b = 10;
	return 0;
}
