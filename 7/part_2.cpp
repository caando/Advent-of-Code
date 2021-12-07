#include<bits/stdc++.h>
using namespace std;

int main(){
    long long cur, ans = 0, ans1 = 0;
    char c;
    cin >> cur;
    vector<long long> arr;
    arr.push_back(cur);
    long long t = cur;
    while(cin >> c){
        cin >> cur;
        arr.push_back(cur);
        t += cur;
    }
    long long small = t/arr.size(), large = small + 1;
    for(int i = 0; i < arr.size(); i++) {
        ans += abs(small - arr[i]) * (abs(small - arr[i]) + 1) / 2;
        ans1 += abs(large - arr[i]) * (abs(large - arr[i]) + 1) / 2;
    }
    cout << min(ans, ans1);
}