#include<bits/stdc++.h>

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int n;
int arr[102];
int cache[102];

int DP(int idx) {
    if (idx == n) return 0;
    int &ret = cache[idx];
    if (ret != -1) return ret;

    return ret;
}

int main() {
    fio;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    memset(cache, -1, sizeof(cache));

    cout << DP(0);
    return 0;
}