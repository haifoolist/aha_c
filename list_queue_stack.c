#include <stdio.h>

void pwd_crack();

int main()
{
    int q[100] = {6, 3, 1, 7, 5, 8, 9, 2, 4};
    pwd_crack(q, 8);

    struct queue que;
    que.head = 0;
    que.size = 8;
    for (size_t i = 0; i < 8; i++)
    {
        que.data[i] = q[i];
    }

    return 0;
}

/*
queue - FIFO
*/

void pwd_crack(int *arr, size_t size)
{
    int head = 0;
    int tail = size;
    while (head < tail)
    {
        //remove the first element
        printf("%d", arr[head]);
        head++;

        //move current head to tail
        arr[tail] = arr[head];
        tail++;
        head++;
    }
}

struct queue
{
    int data[100];
    int head;
    int size;
};

void pwd_crack_struct(struct queue q)
{
}