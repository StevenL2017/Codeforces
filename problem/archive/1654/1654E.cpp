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

const int N = 1e5 + 3;
const int S = 70;

int bucket[N * S];

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    auto calc = [&] () -> int {
        int ans = 0;

        for (int d = 0; d < S; d++) {
            for (int i = 0; i < n; i++) {
                ans = max(ans, ++bucket[a[i] + (n - i) * d]);
            }
            for (int i = 0; i < n; i++) {
                bucket[a[i] + (n - i) * d] = 0;
            }
        }

        vector<map<int, int>> h(N);
        for (int i = 0; i < n; i++) {
            for (int j = max(0, i - N / S); j < i; j++) {
                int d = (a[i] - a[j]) / (i - j);
                int r = (a[i] - a[j]) % (i - j);
                if (d >= S && r == 0) {
                    h[i][d] = max(h[i][d], h[j][d] + 1);
                    ans = max(ans, h[i][d] + 1);
                }
            }
        }

        return n - ans;
    };

    int ans = calc();
    reverse(a.begin(), a.end());
    ans = min(ans, calc());

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}