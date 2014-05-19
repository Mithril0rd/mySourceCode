#include <cstdio>
#include <cstring>

const int MAX_N = 107;

char a[MAX_N], c[MAX_N];
int b, d;
int next[MAX_N], cnt[MAX_N];

int main() {
	scanf("%d%d", &b, &d);
	scanf("%s%s", &a, &c);
	int la = strlen(a), lc = strlen(c);
	for (int i = 0; i < lc; ++i) {
		int p = i;
		for (int j = 0; j < la; ++j) {
			if (a[j] == c[p]) {
				if (++p == lc) {
					++cnt[i], p = 0;
				} 
			}
		}
		next[i] = p;
	}
	for (int i = 0; i < lc; ++i) {
		printf("%d %d %d\n", i, next[i], cnt[i]);
	}
	int cur = 0, p = 0;
	for (int i = 0; i < b; ++i) {
		cur += cnt[p];
		p = next[p];
	}
	int ans = cur / d;
	printf("%d\n", ans);
	return 0;
} 
