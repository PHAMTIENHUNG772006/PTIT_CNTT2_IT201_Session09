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
Node* deleteHead(Node* head) {
    if (head == NULL) {
        printf("danh sach rong");
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
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
    printf("truoc khi xoa : ");
    printData(head);
    printf("\n");
    head = deleteHead(head);
    printf("sau khi xoa : ");
    printData(head);

}