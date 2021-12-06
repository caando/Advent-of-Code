#include<bits/stdc++.h>
using namespace std;

int main(){
    long long h = 0, d = 0, v;
	string s;
	while(cin >> s >> v){
		if (s == "forward"){
			h+=v;
		} else if (s == "up"){
			d -= v;
		} else {
			d += v;
		}
	}
	cout << d * h;
}
