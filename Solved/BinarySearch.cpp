#include<iostream>
#include<algorithm>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int n,m,temp;
int arr[100000];
namespace my{
    template<typename RandomIter, typename Num>
    bool binary_search(RandomIter start, RandomIter end, Num num){
        RandomIter mid;
        while(start <= end){
            mid = start + (end - start)/2;
            if(num == *mid) return true;
            else if(num > *mid) start = mid + 1;
            else end = mid - 1;
        }
        return false;
    }
}

int main(){
    //FastIO;
    cin >> n;
    for (int i = 0; i < n; i++)
    cin >> arr[i];
    sort(arr,arr+n);
    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> temp;
        cout << my::binary_search(&arr[0], &arr[n-1], temp) << '\n';
    }

    system("pause");
    return 0;
}