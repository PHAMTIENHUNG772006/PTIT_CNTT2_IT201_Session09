#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;
Node* insertHead(Node* head,int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    return  newNode;
}
void printData(Node* head) {
    while (head != NULL) {
        printf("%d ->",head->data);
        head = head->next;
    }
    printf("NULL");
}
void finData(Node* head, int x) {
    int flag = 0;
    while (head != NULL) {
        if (head->data == x) {
            flag = 1;
            printf("True");
            return ;
        }
        head = head->next;
    }
    if (flag == 0) {
        printf("false");
        return ;
    }
}
int main() {
    Node* head = NULL;

    head = insertHead(head,10);
    head = insertHead(head,20);
    head = insertHead(head,30);
    head = insertHead(head,40);
    head = insertHead(head,50);
    finData(head,50);
}