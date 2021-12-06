#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<vector<int>>> boards;
    int cur;
    cin >> cur;
    bool running = true;
    while(running){
        vector<vector<int>> board(5, vector<int>(5));
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                board[i][j] = cur;
                running = (bool)(cin >> cur);
            }
        }
        boards.push_back(board);
    }
    cur = 0;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        if (s[i] == ','){
            nums.push_back(cur);
            cur = 0;
        } else {
            cur *= 10;
            cur += s[i] - '0';
        }
    }
    nums.push_back(cur);
    n = nums.size();
    int m = boards.size();
    bool done = false;
    for(int c = 0; c < n && done == false; c++){
        int num = nums[c];
        for(int i = 0; i < m && done == false; i++){
            int x = -1, y = -1;
            for(int j = 0; j < 5; j++){
                for(int k = 0; k < 5; k++){
                    if (boards[i][j][k] == num) {
                        x = j, y = k;
                    }
                }
            }
            if (x != -1 && y != -1){
                boards[i][x][y] = -1;
                bool check = true;
                for(int j = 0; j < 5; j++){
                    if (boards[i][j][y] != -1) check = false;
                }
                done |= check;
                check = true;
                for(int k = 0; k < 5; k++){
                    if (boards[i][x][k] != -1) check = false;
                }
                done |= check;
                if (done) {
                    long long t = 0;
                    for(int j = 0; j < 5; j++){
                        for(int k = 0; k < 5; k++){
                            if (boards[i][j][k] != -1) {
                                t += boards[i][j][k];
                            }
                        }
                    }
                    cout << t * num << '\n';
                }
            }
        }
    }
}
