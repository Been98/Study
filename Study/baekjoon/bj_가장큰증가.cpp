#include <iostream>
#include <algorithm>
using namespace std;

int a[1000], d[1000];

int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++) {
		d[i] = a[i];
		for (int j = 0; j < i; j++) {
			if(a[i] > a[j])
				d[i] = max(d[i], d[j] + a[i]);
		}
	}
	for (int i = 0; i < n; i++)
		ans = max(ans, d[i]);
	cout << ans;
}