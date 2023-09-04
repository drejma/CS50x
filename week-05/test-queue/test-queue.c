// (no link)
// Testing queues in arrays

#include <stdio.h>

const int CAPACITY = 10;

typedef struct queue
{
	int array[CAPACITY];
	int front;
	int size;
}
queue;

void enqueue(queue *q, int value);
int dequeue(queue *q);

int main(void)
{
	queue q;
	q.front = 0;
	q.size = 0;

    enqueue(&q, 10);
    int value = dequeue(&q);
    printf("Dequeued value: %i\n", value);
}

void enqueue(queue *q, int value)
{
    q->array[q->front + q->size] = value;
	q->size++;
}

int dequeue(queue *q)
{
    int i = q->array[q->front];
    q->front++;
    q->size--;
    return i;
}