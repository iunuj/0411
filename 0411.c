#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 5

typedef int element;
typedef struct Stacktype {
    element* data;
    int capacity;
    int top;
} StackType;

void init(StackType* sptr, int ofs) {
    sptr->data = (element*)malloc(sizeof(element) * ofs);
    sptr->top = -1;
    sptr->capacity = ofs;
}

int isFull(StackType* sptr) {
    return (sptr->top == sptr->capacity - 1);
}

int isEmpty(StackType* sptr) {
    return (sptr->top == -1);
}

void push(StackType* sptr, element item) {
    if (isFull(sptr)) {
        sptr->capacity *= 2;
        sptr->data = (element*)realloc(sptr->data, sptr->capacity * sizeof(element));
    }
    sptr->top++;
    sptr->data[sptr->top] = item;
}

element pop(StackType* sptr) {
    if (isEmpty(sptr)) {
        fprintf(stderr, "stack is empty\n");
        exit(1);
    }
    return sptr->data[sptr->top--];
}

element peek(StackType* sptr) {
    if (isEmpty(sptr)) {
        fprintf(stderr, "stack is empty\n");
        exit(1);
    }
    return sptr->data[sptr->top];
}

void print_stack(StackType* sptr) {
    if (isEmpty(sptr)) {
        printf("stack is empty\n");
    }
    else {
        printf("stack: ");
        for (int i = 0; i <= sptr->top; i++) {
            printf("%d ", sptr->data[i]);
        }
        printf("\n");
    }
}

int main() {

    StackType s;
    init(&s, MAX_STACK_SIZE);

    srand(time(NULL));
    int i;

    for (i = 0; i < 30; i++) {
        int rand_num = rand() % 100 + 1;
        printf("current rand_num : %d | %s\n", rand_num, (rand_num % 2 == 0) ? "even" : "odd");
        if (rand_num % 2 == 0) {
            push(&s, rand_num);
            printf("push : %d\n", rand_num);
            print_stack(&s);
        }
        else {
            if (!isEmpty(&s)) {
                int pop_item = pop(&s);
                printf("pop : %d\n", pop_item);
                print_stack(&s);
            }
            else {
                printf("stack is empty\n\n");
            }
        }
    }

    free(s.data);
    return 0;
}