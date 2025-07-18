#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

#define ll long long
#define vi vector<int>
#define ssz(a) (int)((a).size())

#define endl '\n'
template <class T> void in(vector<T>& a) { for (int i = 0; i < ssz(a); i++) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < ssz(a); i++) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    int x, y, k;
    cin >> x >> y >> k;

    auto calc = [&] (int target) -> int {
        if (target == 1) {
            return 0;
        }
        vi d;
        for (int i = 1; i * i <= target; i++) {
            if (target % i == 0) {
                d.push_back(i);
                d.push_back(target / i);
            }
        }
        sort(begin(d), end(d));
        int n = ssz(d);
        vi f(n, 100);
        f[0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (d[i] % d[j] == 0 && d[i] / d[j] <= k) {
                    f[i] = min(f[i], f[j] + 1);
                }
            }
        }
        return f[n - 1] < 100 ? f[n - 1] : -1;
    };

    int g = gcd(x, y);
    int xa = calc(x / g);
    int ya = calc(y / g);

    if (xa == -1 || ya == -1) {
        cout << -1 << endl;
        return;
    }
    cout << xa + ya << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}