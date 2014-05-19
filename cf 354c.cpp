#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 300007;

int n, k, Max;
int a[MAX_N];

bool check(int x) {
	int sum = 0;
	for (int i = 1; i * x <= Max; ++i) {
		sum += (upper_bound(a + 1, a + n + 1, i * x + k) - (a + 1)) - 
		(lower_bound(a + 1, a + n + 1, i * x) - (a + 1));
	}
	return sum == n;
}

int main() {
	scanf("%d%d", &n, &k);
	int Min = -1;
	Max = -1;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (Min == -1 || a[i] < Min) {
			Min = a[i];
		}
		if (Max == -1 || a[i] > Max) {
			Max = a[i];
		}  
	}
	if (Min <= k + 1) {
		printf("%d\n", Min);
		return 0;
	}
	sort(a + 1, a + 1 + n); 
	for (int i = Min; i > k + 1; --i) {
		if (check(i)) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("%d\n", k + 1);
    return 0;
}
