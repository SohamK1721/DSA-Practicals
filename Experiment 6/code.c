#include <stdio.h> 
#include <stdlib.h> 
 
struct node { 
    int data; 
    struct node *next; 
}; 
 
struct node *top = NULL; 
 
void push(int value) { 
    struct node *newNode; 
    newNode = (struct node *)malloc(sizeof(struct node)); 
    newNode->data = value; 
     
    if (top == NULL) { 
        newNode->next = NULL; 
        top = newNode; 
    } else { 
        newNode->next = top; 
        top = newNode; 
    } 
} 
 
void pop() { 
    if (top == NULL) { 
        printf("Stack Underflow\n"); 
    } else { 
        struct node *temp = top; 
        printf("Popped element: %d\n", temp->data); 
        top = top->next; 
        free(temp); 
    } 
} 
 
void printList() { 
    struct node *temp = top; 
    while (temp != NULL) { 
        printf("%d -> ", temp->data); 
        temp = temp->next; 
    } 
    printf("NULL\n"); 
} 
int main() { 
push(10); 
push(20); 
push(30); 
printf("Linked list elements:\n"); 
printList(); 
pop(); 
printf("After the pop, new linked list:\n"); 
printList(); 
return 0; 
}
