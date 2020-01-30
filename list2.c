#include <stdio.h>

#define SIZE 100

/*
Queue
*/

typedef struct
{
    int arr[SIZE];
    int head;
    int tail;
} Queue;

void queue_init(Queue q)
{
    for (size_t i = 0; i < SIZE; i++)
    {
        q.arr[i] = 0;
    }

    q.head = 0;
    q.tail = 0;
}

int queue_size(Queue q)
{
    return (q.tail - q.head);
}
int queue_is_empty(Queue q)
{
    return !(q.tail - q.head);
}
int queue_is_full(Queue q)
{
    return q.tail >= SIZE;
}
int queue_push(Queue q, int val)
{
    if (queue_is_full(q))
    {
        return 0;
    }
    q.arr[q.tail] = val;
    q.tail++;
    return 1;
}
int queue_pop(Queue q)
{
    if (queue_is_empty(q))
    {
        return 0;
    }
    return q.arr[q.head++];
}

/*
Stack
*/
typedef struct
{
    int arr[SIZE];
    int head;
    int tail;
} Stack;

int main()
{
    Queue qu;

    queue_init(qu);
    queue_push(qu, 1);

    printf(">>>\t%d\n", queue_pop(qu));
}