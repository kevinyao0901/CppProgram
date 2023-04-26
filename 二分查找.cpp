#include<stdio.h>
#include<string.h>

int binary_search(int* list, int listSize, int target)
{
    int left = 0, right = listSize - 1;
    while (left <= right)
    {
        int key = (left + right) / 2;
        if (list[key] > target)
        {
            right = key - 1;
        }
        if (list[key] < target)
        {
            left = key + 1;
        }
        if (list[key] == target)
        {
            return key;
        }
    }
    /*if(left>right)
    {
        return 1;
    }*/

}

int main()
{
    int a[5] = { 1,2,3,4,5 };
    int b = binary_search(a, 5, 3);
    printf("%d", b);
}