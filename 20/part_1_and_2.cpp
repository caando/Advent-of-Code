#include<bits/stdc++.h>
using namespace std;

int main(){
    string m, s, padding_row, padding_col;
    cin >> m;
    vector<string> v;
    int n = 50;
    for(int i = 0; i < 2*n; i++){
        padding_col += '.';
    }
    while(cin >> s) {
        if (v.empty()){
            padding_row += padding_col;
            for(int i = 0; i < s.size(); i++) padding_row += '.';
            padding_row += padding_col;
            for(int i = 0; i < 2*n; i++){
                v.push_back(padding_row);
            }
        }
        v.push_back(padding_col + s + padding_col);
    }
    for(int i = 0; i < 2*n; i++){
        v.push_back(padding_row);
    }
    for(int t = 0; t < n; t++){
        vector<string> nxt = v;
        for(int i = 1; i < v.size()-1; i++){
            for(int j = 1; j < v[i].size()-1; j++){
                int pos = 0;
                for(int k = 0; k < 9; k++){
                    if (v[i-1+k/3][j-1+k%3] == '#') pos |= (1 << (8-k));
                }
                nxt[i][j] = m[pos];
            }
        }
        v = nxt;
    }
    int ans = 0;
    for(int i = n; i < v.size()-n; i++){
        for(int j = n; j < v[i].size()-n; j++){
            if (v[i][j] == '#') ans++;
        }
    }
    cout << ans;
}
