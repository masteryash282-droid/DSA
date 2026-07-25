#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* CreateNode(int val) {                                      
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    
    return newNode;
}

void push(int val) {
    struct Node* newNode = CreateNode(val);
    
    newNode->next = head;
    head = newNode;
    
    return;   
}

// pop = remove from top of stack
void pop() {
    if (head == NULL) {
        cout << "Stack is empty!\n";
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return;
}

// peep = view value at given index (1 = top)
void peep(int index) {
    struct Node* ptr = head;
    int count = 1;

    if (head == NULL) {
        cout << "Stack is empty!\n";
        return;
    }

    while (ptr != NULL && count != index) {
        ptr = ptr->next;
        count++;
    }

    if (ptr == NULL) {
        cout << "Invalid index!\n";
        return;
    }

    cout << "index " << index << ",  value : " << ptr->data << "\n";
    return;
}

void change(int index, int val) {
    struct Node* ptr = head;
    int count=1;
    
    while(ptr != NULL && count != index) {
        ptr = ptr->next;
    }
    
    if(head == NULL) {
        cout << "The stack in empty\n";
        return;
    }
    
    ptr->data = val;
    return;
}

void display() {
    struct Node* ptr = head;

    while(ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
    return;
}

int main() {
    int n;
    
    do {
        cout << "Enter the number(1-5) : ";
        cin >> n;
        
        switch(n) {
            case 1:
                int a;
                cout << "Enter value : ";
                cin >> a;
                push(a);
                break;
            
            case 2:
                pop();
                break;
                
            case 3:
                int ind;
                cout << "Enter index to show : ";
                cin >> ind;
                peep(ind);
                break;
                
            case 4:
                int index, val;
                cout << "index & value : ";
                cin >> index >> val;
                change(index, val);
                break;
                
            case 5:
                display();
                break;
            
            default: 
                cout << "Enter (1-4) \n";
                break;
        }
    } while(0 != n);
    
    return 0;
}
