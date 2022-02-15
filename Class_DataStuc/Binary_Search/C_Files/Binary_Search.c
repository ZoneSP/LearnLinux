#include "Sysctrl.h"

int Binary_Search(int *Search_Array, int Array_length, int Search_num)
{
    int low = 1;
    int high = Array_length;
    int mid = ((low + high) / 2);

    while(low != high)
    {
        if(Search_num > *(Search_Array + (mid-1)))
        {
            low = mid + 1;
            mid = ((low + high) / 2);
        }
        else if(Search_num < *(Search_Array + (mid-1)))
        {
            high = mid - 1;
            mid = ((low + high) / 2);
        }
        else
        {
            return 1;
        }
    }


    if(*(Search_Array + (low-1)) == Search_num || *(Search_Array + (high-1)) == Search_num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

