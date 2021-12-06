#include<bits/stdc++.h>
using namespace std;

vector<vector<long long>> mul(vector<vector<long long>> &a, vector<vector<long long>> &b){
    vector<vector<long long>> result(a.size(), vector<long long>(b.size(), 0));
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++) {
            for(int k = 0; k < a[i].size(); k++){
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

int main(){
    long long cur, ans = 0, n = 256;
    char c;
    vector<long long> cnt(9, 0);
    cin >> cur;
    cnt[cur]++;
    while(cin >> c) cin >> cur, cnt[cur]++;
    vector<vector<long long>> final = {
        {1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1},
    };
    vector<vector<long long>> change = {
        {0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0},
    };
    while(n){
        if (n&1){
            final = mul(final, change);
        }
        n >>= 1;
        change = mul(change, change);
    }
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++) ans += final[i][j] * cnt[i];
    }
    cout << ans << '\n';
}