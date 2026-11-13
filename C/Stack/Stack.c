#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int val;
    struct Node* next;
} Node;

typedef struct Stack{
    size_t size;
    Node* head;
    Node* tail;
} Stack;

Stack* initialize_stack(){
    Stack* res = (Stack*)malloc(sizeof(Stack));
    res->size = 0;
    res->head = NULL;
    res->tail = NULL;
    return res;
}

void stack_empty(Stack* stk){
    Node* curr = stk->head;
    Node* prec = NULL;
    while(curr != NULL){
        prec = curr;
        curr = curr->next;
        free(prec);
    }
    stk->size = 0;
    stk->head = NULL;
    stk->tail = NULL;
}

size_t stack_size(Stack* stk){
    return stk->size;
}

int stack_head(Stack* stk){
    if(stk->size > 0){
        printf("Error : Stack is empty\n");
    }
    return stk->head->val;
}

void stack_push(Stack* stk, int value){
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->val = value;
    tmp->next = stk->head;
    stk->head = tmp;
    stk->size++;
}

void stack_pop(Stack* stk){
    if(stk->size == 0){
        printf("Error : Cannot pop, stack is empty\n");
    }
    Node* tmp = stk->head;
    stk->head = tmp->next;
    free(tmp);
    stk->size--;
}

int stack_is_empty(Stack* stk){
    return stk->size == 0;
}

void stack_print(Stack* stk){
    Node* curr = stk->head;
    if(curr == NULL){
        printf("{}\n");
        return;
    }
    printf("{");
    while(curr->next != NULL){
        printf("%d, ", curr->val);
        curr = curr->next;
    }
    printf("%d}\n", curr->val);
}


int main(void){
    Stack* test = initialize_stack();
    stack_push(test, 1);
    stack_push(test, 2);
    stack_push(test, 3);
    stack_push(test, 4);
    stack_push(test, 5);
    stack_pop(test);
    printf("%d\n", stack_size(test));
    stack_print(test);
    return 0;
}