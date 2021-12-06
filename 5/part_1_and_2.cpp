#include<bits/stdc++.h>
using namespace std;

const int n = 1000;

int g[n][n];

int main(){
    memset(g, 0, sizeof g);
    int x1, y1, x2, y2, ans = 0;
    char c;
    string s;
    while (cin >> x1 >> c >> y1 >> s >> x2 >> c >> y2){
        for(int i = x1, j = y1; i != x2 || j != y2; i += (x2-x1)/max(1, abs(x2-x1)), j += (y2-y1)/max(1, abs(y2-y1)) ){
            g[i][j]++;
        }
        g[x2][y2]++;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (g[i][j] > 1) ans++;
        }
    }
    cout << ans;
}