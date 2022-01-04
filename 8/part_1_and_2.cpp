#include<bits/stdc++.h>
using namespace std;

int main(){
    string digits[10];
    int ans_1 = 0, ans_2;
    char c;
    while(cin >> digits[0]){
        map<set<char>, int> mapping;
        set<char> sets[10];
        for(int i = 1; i < 10; i++) cin >> digits[i];
        for(int i = 0; i < 10; i++){
            set<char> s;
            for(int j = 0; j < digits[i].size(); j++) s.insert(digits[i][j]);
            // 1, 4, 7, 8
            if (s.size() == 2) mapping[s] = 1, sets[1] = s;
            else if (s.size() == 3) mapping[s] = 7, sets[7] = s;
            else if (s.size() == 4) mapping[s] = 4, sets[4] = s;
            else if (s.size() == 7) mapping[s] = 8, sets[8] = s;
        }
        for(int i = 0; i < 10; i++){
            set<char> s;
            int one_similarity = 0, four_similarity = 0;
            for(int j = 0; j < digits[i].size(); j++) {
                s.insert(digits[i][j]);
                if (sets[1].find(digits[i][j]) != sets[1].end()) one_similarity++;
                if (sets[4].find(digits[i][j]) != sets[4].end()) four_similarity++;
            }
            // 0, 6, 9
            if (s.size() == 6){
                int digit = -1;
                if (one_similarity == 2 && four_similarity == 3) digit = 0;
                else if (one_similarity == 1 && four_similarity == 3) digit = 6;
                else if (one_similarity == 2 && four_similarity == 4) digit = 9;
                mapping[s] = digit, sets[digit] = s;
            // 2, 3, 5
            } else if (s.size() == 5){
                int digit = -1;
                if (one_similarity == 1 && four_similarity == 2) digit = 2;
                else if (one_similarity == 2 && four_similarity == 3) digit = 3;
                else if (one_similarity == 1 && four_similarity == 3) digit = 5;
                mapping[s] = digit, sets[digit] = s;
            }
        }
        cin >> c;
        for(int i = 0; i < 4; i++) {
            string num;
            cin >> num;
            if(num.size() != 5 && num.size() != 6) ans_1++;
            set<char> s;
            for(int j = 0; j < num.size(); j++) s.insert(num[j]); 
            ans_2 += mapping[s] * pow(10, 3-i);
        }
    }
    cout << ans_1 << ' ' << ans_2;
}
