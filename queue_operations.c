#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100
struct Queue {
    int items[MAX_SIZE];
    int front, rear;
};
void initialize(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}
bool isFull(struct Queue* queue) {
    return (queue->rear == MAX_SIZE - 1 && queue->front == 0) || (queue->rear + 1 == queue->front);
}
bool isEmpty(struct Queue* queue) {
    return queue->front == -1;
}
void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = value;
}
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int value = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return value;
}
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->items[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue->items[i]);
}
int main() {
    struct Queue queue;
    initialize(&queue);
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    printf("Queue: ");
    display(&queue);
    int dequeued = dequeue(&queue);
    printf("Dequeued: %d\n", dequeued);
    printf("Queue after dequeue: ");
    display(&queue);
    return 0;
}
