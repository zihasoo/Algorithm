#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
using ll = long long;

class segment_tree{
    int n;
    vector<ll> seg;
private:
    ll init(const vector<ll>& base, int node, int left, int right){
        if(left == right){
            return seg[node] = base[left];
        }
        int mid = (left+right)/2;
        return seg[node] = init(base, node*2, left, mid) + init(base, node*2 + 1, mid+1, right);
    }
    ll query(const int left, const int right, int node, int node_left, int node_right){
        if(left > node_right || right < node_left)
            return 0;
        if(left <= node_left && node_right <= right)
            return seg[node];
        int mid = (node_left+node_right)/2;
        return query(left,right,node*2,node_left,mid) + query(left,right,node*2+1,mid+1,node_right);
    }
    ll update(const int idx, const ll new_value, int node, int node_left, int node_right){
        if(node_left > idx || node_right < idx)
            return seg[node];
        if(node_left == node_right)
            return seg[node] = new_value;
        int mid = (node_left+node_right)/2;
        return seg[node] = update(idx, new_value,node*2, node_left, mid) + update(idx, new_value,node*2+1, mid+1, node_right);
    }
public:
    segment_tree(vector<ll>& base) {
        n = base.size();
        seg.resize(n*4);
        init(base,1, 0,n-1);
    }
    ll query(const int left, const int right){
        return query(left, right, 1, 0, n-1);
    }
    void update(const int idx, const ll new_value){
        update(idx, new_value, 1, 0, n-1);
    }
};

int n;
int main(){
    FastIO
    cin >> n;
    vector<ll> base(n);
    for (int i = 0; i < n; ++i) {
        cin >> base[i];
    }
    segment_tree my_seg(base);

    return 0;
}