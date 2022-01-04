#include<bits/stdc++.h>
using namespace std;

int main() {
    map<char, char> matching = {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'},
        {'<', '>'}
    };
    map<char, long long> scoring_part1 = {
        {')', 3}, 
        {']', 57}, 
        {'}', 1197}, 
        {'>', 25137}
    }, scoring_part2 = {
        {')', 1}, 
        {']', 2}, 
        {'}', 3}, 
        {'>', 4}
    };
    long long part1 = 0;
    vector<long long> part2;
    string sequence;
    while(cin >> sequence){
        stack<char> s;
        bool corrupted = false;
        for(int i = 0; i < sequence.size(); i++){
            if (matching[sequence[i]]){
                s.push(matching[sequence[i]]);
            } else if (s.top() == sequence[i]) {
                s.pop();
            } else {
                part1 += scoring_part1[sequence[i]];
                corrupted = true;
                break;
            }
        }
        if (!corrupted){
            long long score = 0;
            while(!s.empty()){
                score *= 5;
                score += scoring_part2[s.top()];
                s.pop();
            }
            if (score > 0) part2.push_back(score);
        }
    }
    sort(part2.begin(), part2.end());
    cout << part1 << ' ' << part2[part2.size()/2];
}
