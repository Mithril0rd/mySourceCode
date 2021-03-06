#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 307;
typedef long long ll;
const ll INF = 1LL<<61;

int n, m, k;
ll w[MAX_N][MAX_N], dp[MAX_N][MAX_N];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			dp[i][j] = w[i][j] = INF;
		}
	}
	for (int i = 1; i <= m; ++i) {
		int l, r;
		ll c;
		scanf("%d%d%I64d", &l, &r, &c);
		for (int j = l; j <= r; ++j) {
			w[l][j] = min(w[l][j], c);
		}
	}
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= i; ++j) {
			dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			for (int k = 1; k <= j; ++k) 
				dp[i][j] = min(dp[i][j], dp[i - k][j - k] + w[i - k + 1][i]);
		}
	}
	if (dp[n][k] == INF) puts("-1");
	else printf("%I64d\n", dp[n][k]);
	return 0;
}
