#include<iostream>
#include<chrono>
#include<random>
#include<algorithm>

using namespace std;
using namespace chrono;

template<typename T>
inline void myswap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

template<typename RandomIter>
RandomIter sorting(RandomIter pivot,RandomIter left, RandomIter right){
    while (true){
        while(left<=right && *left<*pivot) left++;
        while(left<=right && !(*right<*pivot)) right--;
        if(right<left){
            myswap(*right,*pivot);
            return right;
        }
        myswap(*right, *left);
    }
}

template<typename RandomIter>
void QuickSort(RandomIter start, RandomIter end){
    end--;
    if(start>=end){
        return;
    }
    RandomIter pivot = sorting(start,start+1,end);
    QuickSort(start,pivot);
    QuickSort(pivot+1,++end);
}

template<typename RandomIter>
void BubbleSort(RandomIter start, RandomIter end){
    for(RandomIter i=end-1; i!=start; i--){
        for(RandomIter j=start; j!=i; j++){
            if(*j > *(j+1)) swap(*j,*(j+1));
        }   
    }
}

template<typename RandomIter>
void SelectionSort(RandomIter start, RandomIter end){
    int *minPointer;
    for(RandomIter i=start; i!=end-1; i++){
        minPointer = i;
        for(RandomIter j=i+1; j!=end; j++){
            if(*minPointer > *j) minPointer = j;
        }
        swap(*i,*minPointer);
    }
}

typedef high_resolution_clock hc;

const float d=1000;
const int n=100000;
mt19937 gen(1);
uniform_int_distribution<int> uni(-n, n);

inline void Randomization(int *nums){
    for (int i = 0; i < n; i++){
        nums[i] = uni(gen);
    }
}

int main(){
    int *nums = new int[n];

    Randomization(nums);
    time_point<hc> start = hc::now();
    sort(nums,nums+n);
    time_point<hc> end = hc::now();
    cout << "STLSort: " << duration_cast<microseconds>(end - start).count()/d << "ms\n";

    Randomization(nums);
    start = hc::now();
    QuickSort(nums,nums+n);
    end = hc::now();
    cout << "QuickSort: " << duration_cast<microseconds>(end - start).count()/d << "ms\n";

    Randomization(nums);
    start = hc::now();
    BubbleSort(nums,nums+n);
    end = hc::now();
    cout << "BubbleSort: " << duration_cast<microseconds>(end - start).count()/d << "ms\n";

    Randomization(nums);
    start = hc::now();
    SelectionSort(nums,nums+n);
    end = hc::now();
    cout << "SelectionSort: " << duration_cast<microseconds>(end - start).count()/d << "ms\n";

    delete[] nums;

    system("pause");
    return 0;
}

