#include<iostream>
#include<string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;


template<typename T>
class Stack {
private:
    T *data;
    int capacity = 16;
    int m_size = 0;
public:
    Stack() {
        data = new T[capacity];
    }

    ~Stack() {
        delete[] data;
    }

    void push(const T &d) {
        if (m_size == capacity) {
            capacity *= 2;
            T *temp = new T[capacity];
            copy(data, data + m_size, temp);
            delete[] data;
            data = temp;
        }
        data[m_size++] = d;
    }

    void pop() {
        m_size--;
    }

    T& top() {
        return data[m_size - 1];
    }

    bool empty() const {
        return m_size == 0;
    }

    int size() const {
        return m_size;
    }
};

int main() {
    //FastIO;
    string command;
    Stack<int> s;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "pop") {
            if (s.empty()) cout << -1 << '\n';
            else {
                cout << s.top() << '\n';
                s.pop();
            }
        } else if (command == "size") {
            cout << s.size() << '\n';
        } else if (command == "empty") {
            cout << s.empty() << '\n';
        } else if (command == "top") {
            if (s.empty()) cout << -1 << '\n';
            else {
                cout << s.top() << '\n';
            }
        } else {
            cin >> x;
            s.push(x);
        }
    }
    return 0;
}