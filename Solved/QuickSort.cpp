#include<iostream>
#include<random>

using namespace std;

template<typename T>
inline void myswap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename RandomIter>
RandomIter sorting(RandomIter pivot, RandomIter left, RandomIter right) {
    while (true) {
        while (left <= right && *left < *pivot) left++;
        while (left <= right && !(*right < *pivot)) right--;
        if (right < left) {
            myswap(*right, *pivot);
            return right;
        }
        myswap(*right, *left);
    }
}

template<typename RandomIter>
void Quick_Sort(RandomIter start, RandomIter end) {
    end--;
    if (start >= end) {
        return;
    }
    RandomIter pivot = sorting(start, start + 1, end);
    Quick_Sort(start, pivot);
    Quick_Sort(pivot + 1, ++end);
}

template<typename RandomIter, typename Compare>
RandomIter sorting(RandomIter pivot, RandomIter left, RandomIter right, Compare comp) {
    while (true) {
        while (left <= right && comp(*left, *pivot)) left++;
        while (left <= right && !comp(*right, *pivot)) right--;
        if (right < left) {
            myswap(*right, *pivot);
            return right;
        }
        myswap(*right, *left);
    }
}

template<typename RandomIter, typename Compare>
void Quick_Sort(RandomIter start, RandomIter end, Compare comp) {
    end--;
    if (start >= end) {
        return;
    }
    RandomIter pivot = sorting(start, start + 1, end, comp);
    Quick_Sort(start, pivot, comp);
    Quick_Sort(pivot + 1, ++end, comp);
}

bool c(int &a, int &b) {
    return a > b;
}

int main() {
    const int n = 100;
    int nums[n];
    mt19937 gen(1);
    uniform_int_distribution<int> uni(1, 100);
    for (int i = 0; i < n; i++) {
        nums[i] = uni(gen);
        cout << nums[i] << ' ';
    }
    cout << '\n';
    Quick_Sort(nums, nums + n, c);

    for (int i = 0; i < n; i++) {
        cout << nums[i] << ' ';
    }
    system("pause");
    return 0;
}
