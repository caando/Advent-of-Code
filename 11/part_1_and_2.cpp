#include<bits/stdc++.h>
using namespace std;

int main() {
    int steps = 100, flashes = 0;
    vector<vector<int>> graph;
    string s;
    while(cin >> s){
        vector<int> line;
        for(int i = 0; i < s.size(); i++){
            line.push_back(s[i] - '0');
        }
        graph.push_back(line);
    }
    int step = 0;
    bool sync = false;
    while(!sync){
        sync = true;
        for(int i = 0; i < graph.size(); i++){
            for(int j = 0; j < graph[i].size(); j++){
                graph[i][j]++;
            }
        }
        bool check = true;
        while(check){
            check = false;
            for(int i = 0; i < graph.size(); i++){
                for(int j = 0; j < graph[i].size(); j++){
                    if (graph[i][j] > 9) {
                        graph[i][j] = INT_MIN;
                        check = true;
                        if (i > 0) graph[i-1][j]++;
                        if (j > 0) graph[i][j-1]++;
                        if (i < graph.size()-1) graph[i+1][j]++;
                        if (j < graph[i].size()-1) graph[i][j+1]++;
                        if (i > 0 && j > 0) graph[i-1][j-1]++;
                        if (i > 0 && j < graph[i].size()-1) graph[i-1][j+1]++;
                        if (i < graph.size()-1 && j > 0) graph[i+1][j-1]++;
                        if (i < graph.size()-1 && j < graph[i].size()-1) graph[i+1][j+1]++;
                    }
                }
            }
        }
        for(int i = 0; i < graph.size(); i++){
            for(int j = 0; j < graph[i].size(); j++){
                if (graph[i][j] < 0) graph[i][j] = 0, flashes++;
                else sync = false;
            }
        }
        if (++step == 100) cout << flashes << ' ';
        if (sync) cout << step;
    }
}
