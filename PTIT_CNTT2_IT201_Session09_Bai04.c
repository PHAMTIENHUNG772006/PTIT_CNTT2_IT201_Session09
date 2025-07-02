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
void leghtList(Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    printf("Danh sach co do dai la %d", length);
}
int main() {
    Node* head = NULL;
    head = insertHead(head,10);
    head = insertHead(head,20);
    head = insertHead(head,30);
    head = insertHead(head,40);
    head = insertHead(head,50);
    leghtList(head);
}