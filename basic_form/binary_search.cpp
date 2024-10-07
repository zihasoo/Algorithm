#include<bits/stdc++.h>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
using ll = long long;
int n, m;
vector<int> arr;

bool is_possible(ll k) {
    ll sum = 0, c = 0;
    for (int x: arr) {
        c += x / k;
        c += (x % k != 0);
    }
    return (c <= m);
}

ll bs() {
    ll st = 1, ed = 1'000'000'002, ret = 0, mid;
    while (st <= ed) {
        mid = (ed + st) / 2;
        if (is_possible(mid)) {
            ret = mid;
            ed = mid - 1;
        } else st = mid + 1;
    }
    return ret;
}

int main() {
    FastIO
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << bs();
    return 0;
}
