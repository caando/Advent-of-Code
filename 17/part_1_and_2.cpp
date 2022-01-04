#include<bits/stdc++.h>
using namespace std;

bool check(int vx, int vy, int up, int down, int left, int right) {
    int x = 0, y = 0;
    while(vy >= -max(abs(down), up)){
        x += vx;
        y += vy;
        if (x >= left && x <= right && y >= down && y <= up) return true;
        vy--;
        if (vx > 0) vx--;
    }
    return false;
}

int main() {
    int left = 111, right = 161, down = -154, up = -101;
    if(abs(down) > up + 1) {
        cout << abs(down) * (abs(down) - 1) / 2 << ' ';
    } else {
        cout << up * (up+1) / 2 << ' ';
    }
    int cnt = 0;
    for(int vx = 0; vx <= right; vx++){
        for(int vy = -abs(down); vy <= max(abs(down), up + 1); vy++){
            cnt += check(vx, vy, up, down, left, right);
        }
    }
    cout << cnt;
}
