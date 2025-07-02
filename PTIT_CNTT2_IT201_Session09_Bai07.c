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
Node* insertIndex(Node* head, int index,int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (index < 0) {
        printf("Index khong hop le.\n");
        free(newNode);
        return head;
    }

    if (index == 0) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    int count = 0;
    while (current != NULL && count < index - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("index khong hop le\n");
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}
void printData(Node* head) {
    while (head != NULL) {
        printf("%d ->",head->data);
        head = head->next;
    }
    printf("NULL");
}
int main() {
    Node* head = NULL;
    head = insertHead(head,10);
    head = insertHead(head,20);
    head = insertHead(head,30);
    head = insertHead(head,40);
    head = insertHead(head,50);
    int newData,index;
    printf("Moi nhap gia tri moi ");
    scanf("%d",&newData);
    printf("Moi nhap vi tri ");
    scanf("%d",&index);

    head = insertIndex(head,index,newData);

    printData(head);
}