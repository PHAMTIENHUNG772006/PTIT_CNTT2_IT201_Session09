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
int main() {
    int data;
    printf("Moi nhap du lieu can them : ");
    scanf("%d",&data);
    Node* head = NULL;
    head = insertHead(head,10);
    head = insertHead(head,data);
    printData(head);
}