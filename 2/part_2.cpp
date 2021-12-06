#include<bits/stdc++.h>
using namespace std;

int main(){
    long long h = 0, d = 0, a = 0, v;
	string s;
	while(cin >> s >> v){
		if (s == "forward"){
			h+=v;
			d += a * v;
		} else if (s == "up"){
			a -= v;
		} else {
			a += v;
		}
	}
	cout << d * h;
}
