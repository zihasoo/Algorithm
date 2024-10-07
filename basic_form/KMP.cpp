#include <bits/stdc++.h>

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

vector<int> fail(const string& P){
    int n = P.length(), j = 0;
    vector<int> ret(n);
    for (int i = 1; i < n; ++i) {
        while (j > 0 && P[i] != P[j]) j = ret[j-1];
        if(P[i] == P[j]) ret[i] = ++j;
    }
    return ret;
}

void KMP(const string& T, const string& P, const vector<int>& F){
    int j = 0, cnt = 0;
    for (int i = 0; i < T.length(); ++i) {
        while (j > 0 && T[i] != P[j]) j = F[j-1];
        if(T[i] == P[j]) ++j;

        if(j == P.length()) {
            cnt++;
            j =  F[j-1];
        }
    }
}

vector<int> F;
string a,b;

int main() {
    fastIO
    getline(cin, a);
    getline(cin, b);

    F = fail(b);
    KMP(a,b,F);

    return 0;
}
