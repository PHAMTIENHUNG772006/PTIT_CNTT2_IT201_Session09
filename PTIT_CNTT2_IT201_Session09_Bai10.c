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
    printf("NULL \n");
}
Node* swap(Node* head) {
    if (head == NULL || head->next == NULL) return head;
    Node* current = head;
    Node* newHead = head->next;
    Node* pre = NULL;

    while (current != NULL && current->next != NULL) {
        Node* second = current->next;
        Node* nextPair = second->next;

        second->next = current;
        current->next = nextPair;
        if (pre != NULL) {
            pre->next = second;
        }
        pre = current;
        current = nextPair;
    }
    return newHead;
}
int main() {
    Node* head = NULL;
    head = insertHead(head,50);
    head = insertHead(head,40);
    head = insertHead(head,30);
    head = insertHead(head,20);
    head = insertHead(head,10);
    printNode(head);
    head = swap(head);
    printNode(head);
}