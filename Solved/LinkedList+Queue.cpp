#include<iostream>
#include<string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

template<typename T>
struct Node {
    T data;
    Node *next = NULL;

    Node(T x) : data(x) {}
};

template<typename T>
class LinkedList {
private:
    Node<T> *first = NULL;
    Node<T> *last = NULL;
    int s = 0;
public:
    void push_back(T x) {
        if (first == NULL) {
            first = new Node<T>(x);
            last = first;
        } else {
            Node<T> *temp = new Node<T>(x);
            last->next = temp;
            last = temp;
        }
        s++;
    }

    void pop_front() {
        Node<T> *temp = first->next;
        delete first;
        first = temp;
        s--;
    }

    int size() {
        return s;
    }

    bool empty() {
        if (first == NULL) {
            return true;
        } else {
            return false;
        }
    }

    T front() const {
        return first->data;
    }

    T back() const {
        return last->data;
    }
};

template<typename T>
struct Queue {
    LinkedList<T> Q;

    void push(T x) {
        Q.push_back(x);
    }

    int pop() {
        if (Q.empty()) {
            return -1;
        }
        int temp = Q.front();
        Q.pop_front();
        return temp;
    }

    int size() {
        return Q.size();
    }

    bool empty() {
        return Q.empty();
    }

    T front() {
        if (Q.empty()) {
            return -1;
        }
        return Q.front();
    }

    T back() {
        if (Q.empty()) {
            return -1;
        }
        return Q.back();
    }
};


int main() {
    //FastIO
    int n, x;
    Queue<int> queue;
    string a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == "push") {
            cin >> x;
            queue.push(x);
        } else if (a == "pop") {
            cout << queue.pop() << "\n";
        } else if (a == "size") {
            cout << queue.size() << "\n";
        } else if (a == "empty") {
            cout << queue.empty() << "\n";
        } else if (a == "front") {
            cout << queue.front() << "\n";
        } else {
            cout << queue.back() << "\n";
        }
    }

    system("pause");
    return 0;
}