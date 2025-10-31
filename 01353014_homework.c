//This is a data structures assignment. The goal is to multiply a matrix by its own transpose, under time and memory constraints.
//KEKW
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000
#define int long long

int max_x, max_y;

typedef struct matrix_list {
    int y;
    int z;
    struct matrix_list *next;
} matrix_list;

typedef struct {
    int y[MAX];
    int ans[MAX];
    int front_y, rear_y;
    int front_ans, rear_ans;
} Node;

matrix_list *save_box[MAX];
Node *node[MAX];

void enqueue_y(Node *n, int val) {
    n->y[n->rear_y++] = val;
}

void enqueue_ans(Node *n, int val) {
    n->ans[n->rear_ans++] = val;
}

int dequeue_y(Node *n) {
    return n->y[n->front_y++];
}

int dequeue_ans(Node *n) {
    return n->ans[n->front_ans++];
}

int empty(Node *n) {
    return n->front_y >= n->rear_y || n->front_ans >= n->rear_ans;
}

void classify(int row, int col, int val) {
    matrix_list *cls_new = (matrix_list*)malloc(sizeof(matrix_list));
    cls_new->y = col;
    cls_new->z = val;
    cls_new->next = NULL;

    matrix_list *cls_save = save_box[row];
    matrix_list *cls_last = save_box[row];

    if (cls_save == NULL) {
        save_box[row] = cls_new;
        return;
    }
    while (cls_save != NULL) {
        if (cls_save->y > col && cls_last == cls_save) {
            cls_new->next = cls_save;
            save_box[row] = cls_new;
            return;
        } else if (cls_save->y > col) {
            cls_new->next = cls_save;
            cls_last->next = cls_new;
            return;
        } else if (cls_save->next == NULL) {
            cls_save->next = cls_new;
            return;
        } else {
            cls_last = cls_save;
            cls_save = cls_save->next;
        }
    }
}

int main() {
    int sum;
    scanf("%lld", &sum);

    for (int i = 0; i < MAX; i++) {
        save_box[i] = NULL;
        node[i] = (Node*)malloc(sizeof(Node));
        node[i]->front_y = node[i]->rear_y = 0;
        node[i]->front_ans = node[i]->rear_ans = 0;
    }

    for (int i = 0; i < sum; i++) {
        char c1, c2, c3, c4;
        int u, v, w;
        scanf(" %c%lld%c%lld%c%c%lld", &c1, &u, &c2, &v, &c3, &c4, &w);
        if (max_x < u) max_x = u;
        if (max_y < v) max_y = v;
        classify(u, v, w);
    }

    int i = 0;
    while (i <= max_x) {
        matrix_list *temp = save_box[i];
        while (temp == NULL) {
            i++;
            temp = save_box[i];
        }

        int j = 1;
        while (j <= max_y) {
            temp = save_box[i];
            matrix_list *ans = save_box[j];
            int save = 0;

            while (ans != NULL && temp != NULL) {
                if (temp->y == ans->y) {
                    save += temp->z * ans->z;
                    temp = temp->next;
                    ans = ans->next;
                } else if (temp->y <= ans->y) {
                    temp = temp->next;
                } else {
                    ans = ans->next;
                }
            }
            if (save != 0) {
                enqueue_y(node[i], j);
                enqueue_ans(node[i], save);
            }

            printf("%d %d\n", (int)j, (int)i);
            j++;
        }
        i++;
    }

    i = 0;
    while (i <= max_x) {
        if (i != 0 && node[i] != NULL) {
            while (!empty(node[i])) {
                printf("%d %d %d", (int)i, (int)dequeue_y(node[i]), (int)dequeue_ans(node[i]));
                if (node[i]->front_y < node[i]->rear_y || i <= max_x - 1)
                    printf("\n");
            }
        }
        i++;
    }

    for (i = 0; i < MAX; i++) {
        free(node[i]);
    }

    return 0;
}
