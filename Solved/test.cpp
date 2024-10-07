#include<iostream>
#include<random>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

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

int main(){
    //FastIO;
    const int n=10000;
    int *nums = new int[n];
    mt19937 gen(1);
    uniform_int_distribution<int> uni(-n, n);

    for (int i = 0; i < n; i++){
        nums[i] = uni(gen);
        cout << nums[i] << ' ';
    }
    cout << '\n';
    SelectionSort(nums,nums+n);
    for (int i = 0; i < n; i++){
        cout << nums[i] << ' ';
    }

    return 0;
}