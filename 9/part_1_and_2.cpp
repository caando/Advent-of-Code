#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    vector<string> graph;
    string padding = "";
    while(cin >> s) {
        if (graph.empty()){
            for(int i = 0; i < s.size()+2; i++) padding += '9';
            graph.push_back(padding);
        }
        graph.push_back('9' + s + '9');
    }
    graph.push_back(padding);
    vector<vector<bool>> visited(graph.size(), vector<bool>(graph[0].size(), false));

    long long low_points = 0;
    vector<long long> basins;
    for(int i = 1; i < graph.size()-1; i++){
        for(int j = 1; j < graph[i].size()-1; j++){
            if (graph[i][j] >= graph[i+1][j]) continue;
            if (graph[i][j] >= graph[i-1][j]) continue;
            if (graph[i][j] >= graph[i][j+1]) continue;
            if (graph[i][j] >= graph[i][j-1]) continue;
            low_points += graph[i][j] - '0' + 1;
            if (!visited[i][j]) {
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                long long s = 0;
                while(!q.empty()){
                    int x = q.front().first, y = q.front().second;
                    q.pop();
                    if (graph[x][y] == '9' || visited[x][y]) continue;
                    s++;
                    visited[x][y] = true;
                    q.push(make_pair(x+1, y));
                    q.push(make_pair(x-1, y));
                    q.push(make_pair(x, y+1));
                    q.push(make_pair(x, y-1));
                }
                basins.push_back(s);
            }
        }
    }
    sort(basins.begin(), basins.end(), greater<long long>());
    cout << low_points << ' ' << basins[0] * basins[1] * basins[2];
}
