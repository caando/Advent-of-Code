#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
#define fi first
#define se second
#define sz(c)  ((int)(c).size())
#define all(c) (c).begin(), (c).end()
#define forn(i, m, n)  for (int i = m, nnnn = (n); i < nnnn; ++i)
#define pb  push_back
#define mp  make_pair
#define NIL 0
#define INF INT_MAX
#define int128 __int128_t
    
void debug_out() { cerr << endl; }
    
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
    
#ifdef LOCAL
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...) 42
#endif
    
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 1000000007;
const int MAXN = 200000;


ll cur = 0, cnt = 0, length = 0, v_sum = 0;

ll getNext(){
    if (cnt == 0) {
        ll temp;
        char c;
        cin >> c;
        if(c >= 'A') temp = c - 'A' + 10;
        else temp = c - '0';
        forn(i, 0, 4){
                cur <<= 1;
            if (temp&1) {
                cur++;
            }
            temp >>= 1;
        }
        cnt = 4;
    }
    ll res = cur&1;
    cur >>= 1;
    cnt--;
    length++;
    return res;
}


long long getPacket(){
    ll v=0, t=0;
    forn(i, 0, 3){
        v <<= 1;
        v += getNext();
    } 
    v_sum += v;
    forn(i, 0, 3){
        t <<= 1;
        t += getNext();
    } 
    if (t != 4){
        ll li = getNext();
        if (!li){
            ll l = 0;
            forn(i, 0, 15){
                l <<= 1;
                l += getNext();
            }
            ll ans;
            if (t == 0) ans = 0;
            if (t == 1) ans = 1;
            if (t == 2) ans = INT64_MAX;
            if (t == 3) ans = 0;
            if (t == 5) ans = -1;
            if (t == 6) ans = -1;
            if (t == 7) ans = -1;

            ll time = length;
            while(time + l > length){
                if (t == 0){
                    ans += getPacket();
                } else if (t == 1){
                    ans *= getPacket();
                } else if (t == 2){
                    ans = min(ans, getPacket());
                } else if (t == 3){
                    ans = max(ans, getPacket());
                } else if (t == 5){
                    ll temp = getPacket();
                    if (ans == -1) ans = temp;
                    else if(temp < ans){
                        ans = 1;
                    } else ans = 0;
                } else if (t == 6) {
                    ll temp = getPacket();
                    if (ans == -1) ans = temp;
                    else if(temp > ans){
                        ans = 1;
                    }else ans = 0;
                } else if (t == 7){
                    ll temp = getPacket();
                    if (ans == -1) ans = temp;
                    else if(temp == ans){
                        ans = 1;
                    } else ans = 0;
                }
            }
            return ans;
        } else{
            ll l = 0;
            forn(i, 0, 11){
                l <<= 1;
                l += getNext();
            }
            ll ans;
            if (t == 0) ans = 0;
            if (t == 1) ans = 1;
            if (t == 2) ans = INT64_MAX;
            if (t == 3) ans = 0;
            if (t == 5) ans = -1;
            if (t == 6) ans = -1;
            if (t == 7) ans = -1;
            forn(i, 0, l){
                if (t == 0){
                    ans += getPacket();
                } else if (t == 1){
                    ans *= getPacket();
                } else if (t == 2){
                    ans = min(ans, getPacket());
                } else if (t == 3){
                    ans = max(ans, getPacket());
                } else if (t == 5){
                    ll temp = getPacket();
                    if (ans == -1) ans = temp;
                    else if(temp < ans){
                        ans = 1;
                    } else ans = 0;
                } else if (t == 6) {
                    ll temp = getPacket();
                    if (ans == -1) ans = temp;
                    else if(temp > ans){
                        ans = 1;
                    }else ans = 0;
                } else if (t == 7){
                    ll temp = getPacket();
                    if (ans == -1) ans = temp;
                    else if(temp == ans){
                        ans = 1;
                    } else ans = 0;
                }
            }
            return ans;
        }
    } else {
        ll pre = 1;
        ll a = 0;
        while(pre != 0){
            pre = getNext();
            forn(i, 0, 4){
                a <<= 1;
                a += getNext();
            }
        }
        return a;
    }
}

int main(){
    cout << v_sum << ' ' << getPacket();
}
