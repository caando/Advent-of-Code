#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    vector<string> v;
    while(cin >> s) v.push_back(s);
    bool running = true;
    int cnt = 1;
    while(running){
        bool stop = true;
        vector<string> nx = v;
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v[i].size(); j++){
                if (v[i][j] == '>'){
                    if (j < v[i].size()-1){
                        if (v[i][j+1] == '.'){
                            nx[i][j] = '.';
                            nx[i][j+1] = '>';
                            stop = false;
                        }
                    } else {
                        if (v[i][0] == '.'){
                            nx[i][j] = '.';
                            nx[i][0] = '>';
                            stop = false;
                        }
                    }
                }
            }
        }
        v = nx;
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v[i].size(); j++){
                if (v[i][j] == 'v'){
                    if (i < v.size()-1){
                        if (v[i+1][j] == '.'){
                            nx[i][j] = '.';
                            nx[i+1][j] = 'v';
                            stop = false;
                        }
                    } else {
                        if (v[0][j] == '.'){
                            nx[i][j] = '.';
                            nx[0][j] = 'v';
                            stop = false;
                        }
                    }
                }
            }
        }
        if (stop){
            running = false;
        } else {
            cnt++;
        }
        v = nx;
    }
    cout << cnt;
}
