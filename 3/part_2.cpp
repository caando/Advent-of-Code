#include<bits/stdc++.h>
using namespace std;

int main(){
    string cur;
    vector<string> arr;
    while(cin >> cur){
        arr.push_back(cur);
    }
    int n = arr.size(), l = cur.size();
    vector<bool> present(n, true);
    string oxy, co;
    for(int i = 0; i < l; i++){
        int m = 0, cnt = 0;
        for(int j = 0; j < n; j++) {
            if (present[j]) {
                m++;
                cnt+=arr[j][i] - '0';
            }
        }
        if (cnt >= m/2+m%2){
            oxy += '1';
            for(int j = 0; j < n; j++) present[j] = present[j] && (arr[j][i] !='0');
        } else {
            oxy += '0';
            for(int j = 0; j < n; j++) present[j] = present[j] && (arr[j][i] !='1');
        }
    }
    present = vector<bool>(n, true);
    for(int i = 0; i < l; i++){
        int cnt = 0, m = 0;
        for(int j = 0; j < n; j++) {
            if (present[j]) {
                m++;
                cnt+=arr[j][i] - '0';
            }
        }
        if (m == 1){
            if (cnt == 1) co+='1';
            else co+='0';
        } else if (cnt >= m/2+m%2){
            co += '0';
            for(int j = 0; j < n; j++) present[j] = present[j] && (arr[j][i] !='1');
        } else {
            co += '1';
            for(int j = 0; j < n; j++) present[j] = present[j] && (arr[j][i] !='0');
        }
    }
    long long a = 0, b = 0;
    for(char c : oxy){
        a <<= 1;
        a+= c-'0';
    }
    for(char c : co){
        b <<= 1;
        b+= c-'0';
    }
    cout << a * b << '\n';
}