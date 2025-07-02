//
// Created by ACER on 02/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

// một NOTE gồm hai thành phần : data và con trỏ next
// tạo ra một node
typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node* insertHead(Node* head,int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}
void printList(Node* head){
    while(head  != NULL ){
        printf("%d \n", head->data);
        head = head->next;
    }
}

void updateByData(Node* head,int data,int newData) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            printf("cap nhat data thanh cong \n");
            current->data = newData;
            return ;
        }
        current = current->next;
    }
    printf("khong tim thay data co gia tri %d",data);
}
void updateByIndex(Node*head,int index,int newData) {
    Node* current = head;
    int count = 0;
    while (current != NULL) {
        if (count == index) {
            printf("cap nhat data thanh cong \n");
            current->data = newData;
            return ;
        }
        current = current->next;
        count++;
    }
}
// xoá bằng giá trị
Node* deleteNode(Node* head, int data) {
    Node* current = head;
    Node* prev = NULL;
    while (current != NULL) {
        if (current->data == data) {
            prev->next = current->next;
            return head;
        }
        prev = current;
        current = current->next;
    }
}
int main(){
    Node* head = NULL;

    head = insertHead(head,10);

    head = insertHead(head,20);

    head = insertHead(head,30);

    printList(head);
    printf("truoc khi update \n");
    printList(head);
    printf("sau khi update \n");
    updateByIndex(head,0,45);
    printList(head);
    printf("Xoa theo gia tri \n");
    deleteNode(head,10);
    printList(head);
}