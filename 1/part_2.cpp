#include<bits/stdc++.h>
using namespace std;

int main(){
    int cur, prev = INT_MAX, a=-1, b=-1, c=-1, ans = 0;
    while(cin >> cur){
        a = b, b=c, c = cur;
        if (a != -1){
            if (a+b+c > prev) ans++;
            prev = a+b+c;
        }
    }
    cout << ans;
}