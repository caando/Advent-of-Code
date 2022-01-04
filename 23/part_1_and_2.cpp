#include<bits/stdc++.h>
using namespace std;

map<pair<vector<vector<char>>, vector<char>>, int> dp;

vector<vector<char>> rooms(4);

vector<char> holding(7, '.');

int dfs(vector<vector<char>> rooms, vector<char> holding){
    bool big_check = true;
    for(int i = 0; i < rooms.size(); i++){
        bool check = true;
        for(int j = 0; j < rooms[i].size(); j++){
            if (rooms[i][j] != 'A' + i){
                check = false;
            }
        }
        if (!check) big_check = false;
    }
    if (big_check) return 0;
    if (dp.find(make_pair(rooms, holding)) != dp.end()) return dp[make_pair(rooms, holding)];
    int low = 10000000;
    for(int i = 0; i < rooms.size(); i++){
        bool check = true;
        for(int j = 0; j < rooms[i].size(); j++){
            if (rooms[i][j] != '.' && rooms[i][j] != 'A' + i){
                check = false;
            }
        }
        int index;
        for(index = 0; index < rooms[i].size(); index++) if (rooms[i][index] != '.') break;
        int left = i +1, right = i + 2;
        while(left >= 0){
            if (holding[left] !='.') break;
            if (!check){
                holding[left] = rooms[i][index];
                rooms[i][index] = '.';
                int cost = 0;
                if (left == 0) cost = i * 2 + 2;
                else cost = (i-left+1)*2+1;
                cost += index + 1;
                for(int j = 0; j < holding[left] - 'A'; j++) cost *= 10;
                low = min(low, dfs(rooms, holding) + cost);
                rooms[i][index] = holding[left];
                holding[left] = '.';
            }
            left--;
        }
        while(right < 7){
            if (holding[right] !='.') break;
            if (!check){
                holding[right] = rooms[i][index];
                rooms[i][index] = '.';
                int cost = 0;
                if (right == 6) cost = (3-i) * 2+2;
                else cost = (right-i-2)*2+1;
                cost += index + 1;
                for(int j = 0; j < holding[right] - 'A'; j++) cost *= 10;
                low = min(low, dfs(rooms, holding) + cost);
                rooms[i][index] = holding[right];
                holding[right] = '.';
            }
            right++;
        }
        index --;
        if (index >= 0){
            bool check = true;
            for(int j = 0; j < rooms[i].size(); j++){
                if (rooms[i][j] != '.' && rooms[i][j] != 'A' + i){
                    check = false;
                }
            }
            if (check){
                if (left >= 0){
                    if (holding[left] == 'A' + i){
                        rooms[i][index] = holding[left];
                        holding[left] = '.';
                        int cost = 0;
                        if (left == 0) cost = i * 2 + 2;
                        else cost = (i-left+1)*2+1;
                        cost += index + 1;
                        for(int j = 0; j < rooms[i][index] - 'A'; j++) cost *= 10;
                        low = min(low, dfs(rooms, holding) + cost);
                        holding[left] = rooms[i][index];
                        rooms[i][index] = '.';
                    }
                }
                if (right < 7){
                    if (holding[right] == 'A' + i){
                        rooms[i][index] = holding[right];
                        holding[right] = '.';
                        int cost = 0;
                        if (right == 6) cost = (3-i) * 2+2;
                        else cost = (right-i-2)*2+1;
                        cost += index + 1;
                        for(int j = 0; j < rooms[i][index] - 'A'; j++) cost *= 10;
                        low = min(low, dfs(rooms, holding) + cost);
                        holding[right] = rooms[i][index];
                        rooms[i][index] = '.';
                    }

                }
            }
        }
    }
    dp[make_pair(rooms, holding)] = low;
    return low;
}

int main(){
    string s;
    getline(cin, s);
    getline(cin, s);
    while(getline(cin, s)){
        if (s[3] != '#'){
            rooms[0].push_back(s[3]);
            rooms[1].push_back(s[5]);
            rooms[2].push_back(s[7]);
            rooms[3].push_back(s[9]);
        }
    }
    cout << dfs(rooms, holding) << '\n';
}
