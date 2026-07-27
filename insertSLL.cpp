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

//Insert a node at the beginning.
void front(int val) {
    struct Node* newNode = creatNode(val);

    newNode->next = head;
    head = newNode;
}

//Insert a node at the end.
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

// Insert a node after a given value.
void after(int key, int val) {
    struct Node* newNode = creatNode(val);
    struct Node* temp = head;
    
    while(temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    
    if(temp == NULL) {
        cout << "Not found\n";
        return;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}

// Insert a node before a given value.
void before(int key, int val) {
    struct Node* newNode = creatNode(val);
    struct Node* ptr = head;
    struct Node* preptr = NULL;
    
    while(ptr->next != NULL && ptr->data != key) {
        ptr = ptr->next;
        preptr = ptr;
    }
    
    if(ptr->next == NULL) {
        front(val);
        return;
    }
    newNode->next = preptr->next;
    ptr->next = newNode;
    
}

void display() {
    struct Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << "NULL";
}

int main() {
    
    int n;
    
    do {
        cout << "\n0.Exit\n";
        cout << "1.insert into fron\n";
        cout << "2.insert into back\n";
        cout << "3.insert into after\n";
        cout << "4.intser into before\n";
        cout << "5.display all linklist\n";
        cout << "Enter number as above mention : ";
        cin >> n;
        switch(n) {
            case 1: {
                int m;
                cout << "Enter value : ";
                cin >> m;
                front(m);
                break;
            }
            
            case 2: {
                int m;
                cout << "Enter value : ";
                cin >> m;
                back(m);
                break;
            }
            
            case 3: {
                int key, val;
                cout << "Enter reference value & value : ";
                cin >> key >> val;
                after(key, val);
                break;
            }
            case 4: {
                int key, val;
                cout << "Enter reference value & value : ";
                cin >> key >> val;
                before(key, val);
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
