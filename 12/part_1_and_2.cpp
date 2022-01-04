#include<bits/stdc++.h>
using namespace std;

map<string, vector<string>> edges;

set<string> path;

int dfs(string cur, bool extra){
    if (cur == "end") return 1;
    if (cur[0] <= 'Z'){
        int res = 0;
        for(string edge : edges[cur]){
            if (edge != "start"){
                res += dfs(edge, extra);
            }
        }
        return res;
    }
    if (path.find(cur) != path.end() && !extra) return 0;
    else if (path.find(cur) != path.end()) {
        int res = 0;
        for(string edge : edges[cur]){
            if (edge != "start"){
                res += dfs(edge, false);
            }
        }
        return res;
    } else {
        int res = 0;
        path.insert(cur);
        for(string edge : edges[cur]){
            if (edge != "start"){
                res += dfs(edge, extra);
            }
        }
        path.erase(cur);
        return res;
    }
}

int main() {
    string line;
    while (cin >> line){
        string first, second;
        int i = 0;
        for(; line[i] != '-'; i++){
            first += line[i];
        }
        i++;
        for(; i < line.size(); i++){
            second += line[i];
        }
        edges[first].push_back(second);
        edges[second].push_back(first);
    }
    cout << dfs("start", false) << ' ' << dfs("start", true);
}
