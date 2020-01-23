#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bucket_sort(int arr[], size_t size);
void bubble_sort(int *arr, size_t size);
void quick_sort(int arr[], int low, int high);
void uniq_sort(int *arr,unsigned size);
void bubble_uniq(int *arr,unsigned size);

clock_t begin, end;
double cost;

int main()
{

    int arr[10] = {22, 1, 35, 444, 55, 66, 77, 55, 6, 7};

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
    uniq_sort(arr, length);
    bubble_uniq(arr, length);
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
        bucket[arr[i]]++;
    }
    for (int i = 0; i < 1000; i++)
    {
        if (bucket[i] != 0)
        {
            for (int j = 0; j < bucket[i]; j++)
            {
                printf("%d\t", bucket[i]);
            }
        }
    }
    end = clock();
    cost = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\nbucket sort-------------end\tuse %lf secs\n", cost);
}

//冒泡排序
void bubble_sort(int arr[], size_t size)
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

void quick_sort(int arr[], int low, int high)
{
    int i = low;
    int j = high;
    int temp = arr[i];

    if (low > high)
    {
        return;
    }
    while (i < j)
    {
        while ((arr[j] >= temp) && (i < j))
        {
            j--;
        }
        arr[i] = arr[j];
        while ((arr[i] <= temp) && (i < j))
        {
            i++;
        }
        arr[j] = arr[i];
    }
    arr[i] = temp;
    quick_sort(arr, low, i - 1);
    quick_sort(arr, j + 1, high);
}

void uniq_sort(int *arr,unsigned size)
{
    printf("uniq sort-------------start\n");

    int uniqs[1000] = {0};

    for (size_t i = 0; i < size; i++)
    {
        uniqs[arr[i]] = arr[i];
    }
    for (int i = 0; i < 1000; i++)
    {
        if (uniqs[i] != 0)
        {
                printf("%d\t", uniqs[i]);
        }
    }

    printf("\nuniq sort-------------end.\n");
}

void bubble_uniq(int *arr,unsigned size)
{
    printf("\nbubble uniq sort-------------start\n");
    int prev_num = -1;
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
        if (prev_num == -1)
        {
            printf("%d\t", arr[i]);
        }
        else
        {
            if (arr[i] != prev_num)
            {
                printf("%d\t", arr[i]);
            }
            
        }
        prev_num = arr[i];
        
    }

    printf("\nbubble uniq sort-------------end.\n");
}