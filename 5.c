/*Assignment no 5
Title: Write a program to implement circular queue using arrays.*/
#include <stdio.h>
#define MAX_SIZE 5
struct CircularQueue {
 int items[MAX_SIZE];
 int front, rear;
};
void initializeQueue(struct CircularQueue* queue) {
 queue->front = -1;
 queue->rear = -1;
}
int isEmpty(struct CircularQueue* queue) {
 return (queue->front == -1 && queue->rear == -1);
}
int isFull(struct CircularQueue* queue) {
 return (queue->front == (queue->rear + 1) % MAX_SIZE);
}
void enqueue(struct CircularQueue* queue, int value) {
 if (isFull(queue)) {
 printf("Queue is full. Cannot enqueue %d\n", value);
 return;
 }
 if (isEmpty(queue)) {
 queue->front = queue->rear = 0;
 } else {
 queue->rear = (queue->rear + 1) % MAX_SIZE;
 }
 queue->items[queue->rear] = value;
 printf("%d enqueued to the queue\n", value);
}
void dequeue(struct CircularQueue* queue) {
 if (isEmpty(queue)) {
 printf("Queue is empty. Cannot dequeue\n");
 return;
 }
 printf("%d dequeued from the queue\n", queue->items[queue->front]);
 if (queue->front == queue->rear) {
 // Queue has only one element, reset front and rear
 initializeQueue(queue);
 } else {
 queue->front = (queue->front + 1) % MAX_SIZE;
 }
}
void display(struct CircularQueue* queue) {
 if (isEmpty(queue)) {
 printf("Queue is empty\n");
 return;
 }
 printf("Queue elements: ");
 int i = queue->front;
 do {
 printf("%d ", queue->items[i]);
 i = (i + 1) % MAX_SIZE;
 } while (i != (queue->rear + 1) % MAX_SIZE);
 printf("\n");
}
int main() {
 struct CircularQueue queue;
 initializeQueue(&queue);
 enqueue(&queue, 1);
 enqueue(&queue, 2);
 enqueue(&queue, 3);
 enqueue(&queue, 4);
 display(&queue);
 dequeue(&queue);
 display(&queue);
 enqueue(&queue, 5);
 enqueue(&queue, 6);
 display(&queue);
 return 0;
}
