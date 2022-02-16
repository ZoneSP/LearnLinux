#include "Sysctrl.h"

/*time33算法*/
unsigned long time33(const char * key)
{
    unsigned long hash_value = 0;
    for(int i=0;i<strlen(key);i++)
    {
        hash_value = hash_value*33 + key[i];
    }

    return (hash_value % Hashmap_length);
}



/*构造哈希表*/
Hash_map *Hash_mapping(Hash_map *Hash_TABLE, char **DataBase, int DataBase_length)
{
    Hash_map *point;
    int Loop = 0;
    unsigned long Hash_local = 0;
    Hash_map *New_Node;

    point = Hash_TABLE;

    for(Loop=0;Loop<DataBase_length;Loop++)
    {
        Hash_local = time33((DataBase + Loop));

        if((point + Hash_local)->IsFull != 1)
        {
            //此处为空
            (point + Hash_local)->IsFull = 1;

            strcpy((point + Hash_local)->value, (DataBase + Loop));

            (point + Hash_local)->Save_address = NULL;
        }
        else
        {
            //此处有数据，展开链表
            point = (point + Hash_local);
            while(point->Save_address != NULL)
            {
                point = point->Save_address;
            }

            New_Node->Save_address = NULL;
            New_Node->IsFull = 1;
            strcpy(New_Node->value, (DataBase + Loop));

            point->Save_address = New_Node;

            point = Hash_TABLE;
        }
    }

    return point;
}
