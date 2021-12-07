#include<bits/stdc++.h>
using namespace std;

int main(){
    long long cur, ans = 0;
    char c;
    cin >> cur;
    vector<long long> arr;
    arr.push_back(cur);
    while(cin >> c){
        cin >> cur;
        arr.push_back(cur);
    }
    sort(arr.begin(), arr.end());
    long long medium = arr[arr.size()/2];
    for(int i = 0; i < arr.size(); i++) {
        ans += abs(medium - arr[i]);
    }
    cout << ans;
}