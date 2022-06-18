#include <iostream>
#include <Array.h>

int main()
{
    {
        //dynamic array
        zasty::TArray<int> arr;
        arr.Append(1);
        assert(arr[0] == 1);
        assert(arr.Num() == 1);

        arr.Append(10);
        assert(arr[1] == 10);
        assert(arr.Num() == 2);

        arr[0] = 5;
        assert(arr[0] == 5);

        arr.Append(90);

        arr.Remove(1);
        assert(arr.Num() == 2);
        assert(arr[1] == 90);
    }
    
    {
        //static array
        zasty::TArray<int> arr;
        arr.SetAutoAllocation(false);

        arr.Reserve(5);
        assert(arr.Num() == 0);

        arr.Append(0);
        assert(arr[0] == 0);

        arr.Append(10);
        arr.Append(4);
        arr.Append(7);
        arr.Append(6);
        //cannot add more
        assert(arr[1] == 10);
        assert(arr[2] == 4);
        assert(arr[3] == 7);
        assert(arr[4] == 6);
        assert(arr.Num() == 5);

        arr.Remove(2);
        assert(arr[2] ==7);
        assert(arr.Num() == 4);
    }

}