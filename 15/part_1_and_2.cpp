#include<bits/stdc++.h>
using namespace std;

int get_shortest_path(vector<vector<int>> graph){
    vector<vector<int>> shortest_path;
    for(int i = 0; i < graph.size(); i++){
        shortest_path.push_back(vector<int>(graph[graph.size()-1].size(), INT_MAX));
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push(make_pair(0, make_pair(0, 0)));
    shortest_path[0][0] = 0;
    while(!pq.empty()){
        int x = pq.top().second.first, y = pq.top().second.second, c = shortest_path[x][y];
        pq.pop();
        if (x > 0) {
            if (shortest_path[x-1][y] == INT_MAX){
                pq.push(make_pair(c + graph[x-1][y], make_pair(x-1, y)));
                shortest_path[x-1][y] = c + graph[x-1][y];
            }
        }
        if (y > 0) {
            if (shortest_path[x][y-1] == INT_MAX){
                pq.push(make_pair(c + graph[x][y-1], make_pair(x, y-1)));
                shortest_path[x][y-1] = c + graph[x][y-1];
            }
        }
        if (x < graph.size()-1) {
            if (shortest_path[x+1][y] == INT_MAX){
                pq.push(make_pair(c + graph[x+1][y], make_pair(x+1, y)));
                shortest_path[x+1][y] = c + graph[x+1][y];
            }
        }
        if (y < graph[x].size()-1) {
            if (shortest_path[x][y+1] == INT_MAX){
                pq.push(make_pair(c + graph[x][y+1], make_pair(x, y+1)));
                shortest_path[x][y+1] = c + graph[x][y+1];
            }
        }
    }
    return shortest_path[shortest_path.size()-1][shortest_path[shortest_path.size()-1].size()-1];
}

int main() {
    vector<vector<int>> graph, shortest_path;
    string line;
    int height, width;
    while(cin >> line) {
        width = line.size();
        graph.push_back(vector<int>());
        for(int i = 0; i < width; i++){
            graph[graph.size()-1].push_back((line[i%width] - '1' + i/width) % 9 + 1);
        }
    }
    height = graph.size();
    cout << get_shortest_path(graph) << ' ';
    for(int i = 0; i < graph.size(); i++){
        for(int j = width; j < width*5; j++){
            graph[i].push_back((graph[i][j-width]) % 9 + 1);
        }
    }
    for(int i = height; i < height * 5; i++){
        graph.push_back(vector<int>());
        for(int j = 0; j < graph[i-height].size(); j++){
            graph[i].push_back((graph[i-height][j]) % 9 + 1);
        }
    }
    cout << get_shortest_path(graph) << ' ';
}
