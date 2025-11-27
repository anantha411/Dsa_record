#include <stdio.h>
#include <string.h>

#define MAX 10

char queue[MAX][10];
int front = 0, rear = -1;

void enqueue(char req[]) {
    rear++;
    strcpy(queue[rear], req);
}

char* dequeue() {
    return queue[front++];
}

void displayQueue() {
    printf("[");
    for (int i = front; i <= rear; i++) {
        printf("%s", queue[i]);
        if (i < rear) printf(", ");
    }
    printf("]");
}

int main() {
    // Sample requests
    enqueue("C101");
    enqueue("C102");
    enqueue("C103");
    enqueue("C104");

    // Serve first request
    char *served = dequeue();
    printf("Serving: %s\n", served);

    printf("Queue after service: ");
    displayQueue();
    printf("\n");

    return 0;
}
