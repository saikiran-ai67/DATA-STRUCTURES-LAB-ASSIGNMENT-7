#include <stdio.h>

#define MAX 100

int queue[MAX], stack[MAX];
int front = 0, rear = -1;
int top = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

void printQueue() {
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int capacity, x;

    scanf("%d", &capacity);

    for (int i = 0; i < capacity; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    printf("Original queue: ");
    printQueue();

    while (front <= rear) {
        push(dequeue());
    }

    front = 0;
    rear = -1;

    while (top != -1) {
        enqueue(pop());
    }

    printf("Reversed queue: ");
    printQueue();

    return 0;
}
