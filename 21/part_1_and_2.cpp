#include<bits/stdc++.h>
using namespace std;

const long long winning_score = 21;

unordered_map<long long, long long> combi;

pair<long long, long long> dp[2][10][10][winning_score][winning_score] = { make_pair(0ll, 0ll) };

void get_dice_roll(long long rolls, long long total){
    if (rolls == 3){
        combi[total]++;
    } else {
        get_dice_roll(rolls+1, total+1);
        get_dice_roll(rolls+1, total+2);
        get_dice_roll(rolls+1, total+3);
    }
}

pair<long long, long long> dfs(long long first_loc, long long second_loc, long long first_score, long long second_score, long long turn){
    if (first_score >= winning_score) return make_pair(1, 0);
    if (second_score >= winning_score) return make_pair(0, 1);
    if (dp[turn][first_loc][second_loc][first_score][second_score] != make_pair(0ll, 0ll)) return dp[turn][first_loc][second_loc][first_score][second_score];
    if (turn&1){
        pair<long long, long long> poss = make_pair(0, 0);
        for(int i = 3; i <= 9; i++){
            pair<long long, long long> res = dfs(first_loc, (second_loc+i)%10, first_score, second_score + (second_loc+i)%10+1, turn^1);
            poss.first += combi[i] * res.first;
            poss.second += combi[i] * res.second;
        }
        dp[turn][first_loc][second_loc][first_score][second_score] = poss;
        return poss;
    } else {
        pair<long long, long long> poss = make_pair(0, 0);
        for(int i = 3; i <= 9; i++){
            pair<long long, long long> res = dfs((first_loc+i)%10, second_loc, first_score + (first_loc+i)%10+1, second_score, turn^1);
            poss.first += combi[i] * res.first;
            poss.second += combi[i] * res.second;
        }
        dp[turn][first_loc][second_loc][first_score][second_score] = poss;
        return poss;
    }
}

int main(){
    long long first_loc, second_loc;
    cin >> first_loc >> second_loc;
    first_loc--, second_loc--;
    get_dice_roll(0, 0);
    pair<long long, long long> res = dfs(first_loc, second_loc, 0, 0, 0);
    cout << res.first << ' ' << res.second << '\n';
}
