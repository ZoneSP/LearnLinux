#include "Sysctrl.h"

/*散列查找  哈希查找*/
Hash_map HashTable[100];

/*构造原始数据集合*/
char Data_base[][10] = {"struct", "String", "int", "char", "short", "long", "float", "const", "double"};


int main(int argc, char *argv[])
{
	Hash_map * Hash_Node;
	int result;

	Hash_Node = HashTable;

	Hash_Node = Hash_mapping(Hash_Node, Data_base, 9);
	

	return 0;
}
