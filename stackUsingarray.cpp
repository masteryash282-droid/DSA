#include <iostream>
using namespace std;

class Stack {
private:
    int *arr;
    int top;
    int capacity;
public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }
    ~Stack {
        delete[] arr;
    }        
    void push(int val) {
        if(top == capacity - 1) {
            cout << "Over flow\n";
            return;
        }
        
        top++;
        arr[top] = val;
        return;
    }
    
    void pop() {
        if(top == -1) {
            cout << "Under flow\n";
            return;
        }
        cout << arr[top] << " deleted\n";
        top--;
        return;
    }
    
    void peep(int position) {
        int index = top - position + 1;
        
        if(index < 0 || index > top) {
            cout << "Not Found\n";
            return;
        }
        
        cout << arr[index] << endl;
    }
    
    void change(int position, int val) {
        int index = top - position + 1;
        if(index < 0 || index > top) {
            cout << "Not found\n";
            return;
        }
        
        arr[index] = val;
        return;
    }
    
    void display() {
        int index = top;
        
        if(top==-1)
        {
            cout<<"Stack Empty\n";
            return;
        }
        for(int i=index; i>=0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{   
    Stack s(5);
    int n;
    
    do {
        cout << "Enter the number(1-5) : ";
        cin >> n;
        
        switch(n) {
            case 1:
                int a;
                cout << "Enter value : ";
                cin >> a;
                s.push(a);
                break;
            
            case 2:
                s.pop();
                break;
                
            case 3:
                int ind;
                cout << "Enter index to show : ";
                cin >> ind;
                s.peep(ind);
                break;
                
            case 4:
                int index, val;
                cout << "index & value : ";
                cin >> index >> val;
                s.change(index, val);
                break;
                
            case 5:
                s.display();
                break;
            
            default: 
                cout << "Enter (1-4) \n";
                break;
        }
    } while(0 != n);
    return 0;
}
