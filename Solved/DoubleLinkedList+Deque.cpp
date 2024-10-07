#include<iostream>
#include<string>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

template<typename Data>
class DoubleLinkedList{
private:
    class Node{
    public:
        Data data=0;
        Node* next = nullptr;
        Node* prev = nullptr;
        Node(Data x):data(x){}
    };
    Node* head = new Node((Data)0);
    Node* first = head;
    Node* last = head;
    int s=0;
public:
    class iterator{
    private:
        Node* cur = nullptr;
        void operator++(){
            cur = cur->next;
        }
        void operator--(){
            cur = cur->prev;
        }
    };
    iterator begin(){
        return first;
    }
    iterator end(){
        return head;
    }
    void push_front(Data x){
        first->prev = new Node(x);
        first->prev->next = first;
        first = first->prev;
        if(s==0) last = last->prev;
        s++;
    }

    void push_back(Data x){
        if(s==0) push_front(x);
        else{
            Node* newNode =  new Node(x);
            newNode->next = head;
            head->prev = newNode;
            newNode->prev = last;
            last->next = newNode;
            last = newNode;
            s++;
        }
    }
    void pop_front(){
        Node* temp = first->next;
        delete first;
        first = temp;
        s--;
    }
    void pop_back(){
        Node* temp = last->prev;
        delete last;
        last = temp;
        s--;
    }

    int size(){
        return s;
    }

    bool empty(){
        if(s==0){
            return true;
        }
        else{
            return false;
        }
    }

    Data front(){
        return first->data;
    }

    Data back(){
        return last->data;
    }
};


int main(){
    //FastIO;
    int n,x;
    DoubleLinkedList<int> deque;
    string a;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a;
        if(a=="push_front"){
            cin >> x;
            deque.push_front(x);
        }
        else if(a=="push_back"){
            cin >> x;
            deque.push_back(x);
        }
        else if (a=="pop_front"){
            if(deque.empty()){
                cout << -1 << "\n";
            }
            else{
                cout << deque.front() << "\n";
                deque.pop_front();
            }
        }
        else if (a=="pop_back"){
            if(deque.empty()){
                cout << -1 << "\n";
            }
            else{
                cout << deque.back() << "\n";
                deque.pop_back();
            }
        }
        else if (a=="size"){
            cout << deque.size() << "\n";
        }
        else if (a=="empty"){
            if (deque.empty())cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if (a=="front"){
            if(deque.empty()) cout << -1 << "\n";
            else cout << deque.front() << "\n";
        }
        else{
            if(deque.empty()) cout << -1 << "\n";
            else cout << deque.back() << "\n";
        }
    }

    system("pause");
    return 0;
}