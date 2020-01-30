#include <stdio.h>

int get_size(int *arr)
{
    return sizeof(arr) / sizeof(arr[0]);
}

void main()
{

    int arr[100] = {0};
    printf("%d", sizeof(arr) / sizeof(arr[0]));
    printf("%d", get_size(arr));
}

void aaa()
{
    printf("%d", 2);
}