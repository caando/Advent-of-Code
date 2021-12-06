#include<bits/stdc++.h>
using namespace std;

int main(){
    int cur, prev = INT_MAX, ans = 0;
    while(cin >> cur){
        if (cur > prev) ans++;
        prev = cur;
    }
    cout << ans;
}