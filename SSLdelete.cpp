#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;

struct Node* creatNode(int val) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

// void front(int val) {
//     struct Node* newNode = creatNode(val);

//     newNode->next = head;
//     head = newNode;
// }

void back(int val) {
    struct Node* newNode = creatNode(val);

    if (head == NULL) {           
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void display() {
    struct Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << "NULL";
}

void dltFirstNode() {
    struct Node* temp = head;
    
    head = head->next;
    
    free(temp);
}

void dltEndNode() {
    struct Node* ptr = head;
    struct Node* preptr = NULL;
    
    while(ptr->next != NULL) {
        preptr = ptr;
        ptr = ptr->next;
    }
    
    preptr->next = NULL;
    free(ptr);
}

void dltAfter(int val) {
    struct Node* ptr = head;
    
    while(ptr->next != NULL && ptr->data != val) {
        ptr = ptr->next;
    }
    if(ptr->next == NULL) {
        cout << "Not value found after " << ptr->data;
        return;
    }
    ptr->next = ptr->next->next;
}

void dltbefore(int val) {
    if(head == NULL || head->next == NULL)
    {
        printf("Deletion Not Possible\n");
        return;
    }
     if (head->data == val) {
        printf("No node exists before the head\n");
        return;
    }
    struct Node* ptr = head;
    struct Node* preptr = NULL;
    
    
    while(ptr->next != NULL && ptr->next->data != val) {
        preptr = ptr;
        ptr = ptr->next;
    }
    
    if(ptr->next == NULL) {
        cout << "Not found\n";
        return;
    }
    
    //if the Node is second
    if(ptr->next->data == val) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return;
    }
    preptr->next = ptr->next;
    free(ptr);
}
int main() {

    back(10);
    back(20);
    back(30);
    back(40);
    back(50);
    
    cout << "The link list is : ";
    display();
    
        int n;
    do {
        cout << "\n0.Exit\n";
        cout << "1.Delete first Node\n";
        cout << "2.Delete last Node\n";
        cout << "3.Delete After Value Node\n";
        cout << "4.Delete Before value Node\n";
        cout << "5.display all linklist\n";
        cout << "Enter number as above mention : ";
        cin >> n;
        switch(n) {
            case 1: {
                dltFirstNode();
                break;
            }
            
            case 2: { 
                dltEndNode();
                break;
            }
            
            case 3: {
                int key;
                cout << "Enter reference value for after delete : ";
                cin >> key;
                dltAfter(key);
                break;
            }
            case 4: {
                int key;
                cout << "Enter reference value for before delete : ";
                cin >> key;
                dltbefore(key);
                break;
            }
            case 5: {
                cout << "Link list : ";
                display();
                break;
            }
            case 0:
                cout << "---------------End---------------";
                break;
            default:
                cout << "Enter valide Number from (0-5) \n";
        }
    }while(n != 0);

    
    return 0;
}

