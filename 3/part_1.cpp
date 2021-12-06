#include<bits/stdc++.h>
using namespace std;

int main(){
    string cur;
    vector<string> arr;
    while(cin >> cur){
        arr.push_back(cur);
    }
    int n = arr.size(), l = cur.size();
    string s;
    for(int i = 0; i < l; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            cnt+=arr[j][i] - '0';
        }
        if (cnt >= n/2+n%2) s += '1';
        else s += '0';
    }
    long long a = 0, b = 0;
    for(char c : s){
        a <<= 1;
        b <<= 1;
        a+= c-'0';
        b+= '1'-c;
    }
    cout << a * b << '\n';
}