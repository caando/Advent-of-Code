#include<bits/stdc++.h>
using namespace std;

int main() {
    set<pair<int, int>> xy, yx;
    while(cin.peek() != '\n'){
        int x, y;
        char comma;
        cin >> x >> comma >> y;
        cin.get();
        xy.insert(make_pair(x, y));
        yx.insert(make_pair(y, x));
    }
    string words;
    cin.get();
    char d, eq;
    int v;
    int maxx = 100, maxy = 100;
    bool first = true;
    while(cin >> words >> words >> d >> eq >> v){
        if (d == 'x'){
            while((*xy.rbegin()).first > v){
                int x = (*xy.rbegin()).first, y = (*xy.rbegin()).second;
                xy.erase(make_pair(x, y));
                yx.erase(make_pair(y, x));
                if (2*v - x >= 0){
                    xy.insert(make_pair(2*v-x, y));
                    yx.insert(make_pair(y, 2*v-x));
                }
            }
            maxx = min(maxx, v);
        } else if (d == 'y'){
            while((*yx.rbegin()).first > v){
                int y = (*yx.rbegin()).first, x = (*yx.rbegin()).second;
                xy.erase(make_pair(x, y));
                yx.erase(make_pair(y, x));
                if (2*v - y >= 0){
                    xy.insert(make_pair(x, 2*v-y));
                    yx.insert(make_pair(2*v-y, x));
                }
            }
            maxy = min(maxy, v);
        }
        if (first){
            cout << xy.size() << '\n';
            first = false;
        }
    }
    int count = 0;
    for(int y = 0; y <= maxy; y++){
        for(int x = 0; x <= maxx; x++){
            if (xy.find(make_pair(x, y)) == xy.end()) cout << ' ';
            else cout << '#', count++;
        }
        cout << '\n';
    }
}
