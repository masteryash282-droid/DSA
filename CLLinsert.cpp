#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = val;
    newNode->next = NULL;
    
    return newNode;
}
void insertAtfront(int val) {
    struct Node* newNode = createNode(val);

    if(head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }
    struct Node* temp = head;
    
    while(temp->next != head) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
    return;
}
void insertAtback(int val) {
    struct Node* newNode = createNode(val);
    
    if(head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }
    struct Node* temp = head;
    
    while(temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    
    return;
}

void insertAfter(int key, int val) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    
    struct Node* temp = head;
    
    while(temp->next != head && temp->data != key) {
        temp = temp->next;
    }
    
    if(temp->data != key) {
        cout << "Not Found\n";
        return;
    }
    
    struct Node* newNode = createNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertBefore(int key, int val) {

    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    struct Node* ptr = head;
    struct Node* preptr = NULL;
    
    if(head->data == key) {
        insertAtfront(val);
        return;
    }
    
    while(ptr->next != head && ptr->data != key) {
        preptr = ptr;
        ptr = ptr->next;
    }
    if(ptr->data != key) {
        cout << "Not found\n";
        return;
    }
    struct Node* newNode = createNode(val);
    newNode->next = ptr;
    preptr->next = newNode;
    return;
}
void display() {
    if(head == NULL) {
        cout << "Link list is empty\n";
        return;
    }
    struct Node* temp = head;
    
    do {
        cout << temp->data << "->";
        temp = temp->next;
    } while(temp != head); 
    
    cout << "NULL";
    return;
}
int main()
{
    insertAtfront(10);
    insertAtfront(20);
    insertAtfront(30);
    
    insertAtback(200);
    insertAtback(300);
    insertAtback(400);
    
    insertAfter(400, 50);
    insertBefore(30, 100);
    
    display();
    return 0;
}
