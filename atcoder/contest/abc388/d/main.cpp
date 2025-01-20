#include <iostream>
using namespace std;

const int N = 5e5 + 7;
int a[N], b[N], dp[N];
int n;

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
		dp[i] += dp[i-1];
		b[i] += i - 1 - dp[i];
		int t = b[i] + i + 1;
		if(t <= n) dp[t]++;
	}

	for(int i = n - 1, j = 1; i >= 1; i--, j++) {
		b[i] -= j;
		if(b[i] < 0) b[i] = 0;
	}
	for(int i = 1; i <= n; i++) cout << b[i] << ' ';
	return 0;
}