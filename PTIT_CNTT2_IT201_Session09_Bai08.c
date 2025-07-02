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
Node* delateIndex(Node* head, int index) {
    int lenght = 0;
    Node* temp = head;
    while (temp != NULL) {
        lenght++;
        temp = temp->next;
    }
    if (index < 0 || index > lenght) {
        printf("Index khong nam trong danh sach lien ket");
        return ;
    }
    if (index == 0) {
        Node* elementNode = head;
        head = head->next;
        free(elementNode);
        return head;
    }
    Node* current = head;
    int count = 0;
    while (current != NULL && count < index -1) {
        current = current->next;
        count++;
    }
    if (current != NULL && current->next != NULL) {
        Node* toDelete = current->next;
        current->next = toDelete->next;
        free(toDelete);
    }

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
    head = insertHead(head,50);
    head = insertHead(head,40);
    head = insertHead(head,30);
    head = insertHead(head,20);
    head = insertHead(head,10);
    int index;
    printf("moi nhap vi tri can xoa : ");
    scanf("%d",&index);
    head = delateIndex(head,index);
    printData(head);
}