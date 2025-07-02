#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* insertHead(Node* head,int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    return  newNode;
}
void printNode(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL");
}
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
int main() {
    Node* head = NULL;

    head = insertHead(head,50);
    head = insertHead(head,40);
    head = insertHead(head,30);
    head = insertHead(head,20);
    head = insertHead(head,10);
    printNode(head);

    head = reverse(head);
    printf("\n");

    printNode(head);

}