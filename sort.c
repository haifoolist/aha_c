#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bucket_sort(int arr[], size_t size);
void bubble_sort(int *arr, size_t size);
void quick_sort(int a[], int low, int high);

clock_t begin, end;
double cost;

int main()
{

    int arr[10] = {22, 1, 35, 444, 55, 66, 77, 3, 6, 7};

    size_t length = (size_t)(sizeof(arr) / sizeof(int));

    bucket_sort(arr, length);
    bubble_sort(arr, length);

    printf("bucket sort-------------start\n");
    begin = clock();
    quick_sort(arr, 0, length - 1);
    for (size_t i = 0; i < length; i++)
    {
        printf("%d\t", arr[i]);
    }
    end = clock();
    cost = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\nquick sort-------------end\tuse %lf secs\n", cost);
    return 0;
}

//  桶排序
void bucket_sort(int arr[], size_t size)
{
    printf("bucket sort-------------start\n");
    begin = clock();

    int bucket[1000] = {0};
    for (size_t i = 0; i < size; i++)
    {
        bucket[arr[i]] = arr[i];
    }
    for (int i = 0; i < 1000; i++)
    {
        if (bucket[i] != 0)
        {
            printf("%d\t", bucket[i]);
        }
    }
    end = clock();
    cost = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\nbucket sort-------------end\tuse %lf secs\n", cost);
}

//冒泡排序
void bubble_sort(int *arr, size_t size)
{
    printf("\nbubble sort-------------start\n");
    begin = clock();

    int temp = 0;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (size_t i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    end = clock();
    cost = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\nbubble sort-------------end\tuse %lf secs\n", cost);
}

/*
快速排序
a. 先从数列中取出一个数作为基准数。
b. 分区过程，将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边。 
c. 再对左右区间重复第二步，直到各区间只有一个数。
*/

void quick_sort(int a[], int low, int high)
{
    int i = low;
    int j = high;
    int temp = a[i];

    if (low > high)
    {
        return;
    }
    while (i < j)
    {
        while ((a[j] >= temp) && (i < j))
        {
            j--;
        }
        a[i] = a[j];
        while ((a[i] <= temp) && (i < j))
        {
            i++;
        }
        a[j] = a[i];
    }
    a[i] = temp;
    quick_sort(a, low, i - 1);
    quick_sort(a, j + 1, high);
}
//hhh