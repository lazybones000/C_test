#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main() {
    int queue[MAX];
    int size;
    int front = 0, rear = 0;
    int cmd, x;

    scanf("%d", &size); 

    while (1) {
        scanf("%d", &cmd);
        if (cmd == -1)
            break;

        if (cmd == 1) { 
            scanf("%d", &x);
            if ((rear + 1) % size == front) {
                printf("FULL\n");
            } else {
                queue[rear] = x;
                rear = (rear + 1) % size;
            }
        } else if (cmd == 0) {
            if (front == rear) {
                printf("EMPTY\n");
            } else {
                printf("%d\n", queue[front]);
                front = (front + 1) % size;
            }
        }
    }

    return 0;
}
