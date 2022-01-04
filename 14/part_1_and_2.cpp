#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    map<pair<char, char>, pair<pair<char, char>, pair<char, char>>> mapping;
    string arrow;
    char first, second, result;
    while(cin >> first >> second >> arrow >> result){
        mapping[make_pair(first, second)] = make_pair(make_pair(first, result), make_pair(result, second));
    }
    map<pair<char, char>, long long> cur;
    for(int i = 0; i < s.size()-1; i++){
        cur[make_pair(s[i], s[i+1])]++;
    }
    int steps = 40;
    for(int step = 1; step <= steps; step++){
        map<pair<char, char>, long long> nxt;
        map<char, long long> cnt;
        for(pair<pair<char, char>, long long> val : cur){
            pair<pair<char, char>, pair<char, char>> add = mapping[val.first];
            nxt[add.first] += val.second;
            cnt[add.first.first] += val.second;
            cnt[add.first.second] += val.second;
            nxt[add.second] += val.second;
            cnt[add.second.first] += val.second;
            cnt[add.second.second] += val.second;
        }
        cnt[s[0]]++;
        cnt[s[s.size()-1]]++;
        long long high = 0, low = INT64_MAX;
        for(pair<char, long long> val : cnt){
            if (val.second > high) high = val.second;
            if (val.second < low) low = val.second;
        }
        if (step == 10 || step == 40) {
            cout << high/2 - low/2 << ' ';
        }
        cur = nxt;
    }
}
