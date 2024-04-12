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

const long double N = 1e6;

long double dfs(int c, int m, int p, int v) {
    long double ans = p / N;
    if (c > 0) {
        if (c > v) {
            if (m > 0) {
                ans += (c / N) * (1 + dfs(c - v, m + v / 2, p + v / 2, v));
            } else {
                ans += (c / N) * (1 + dfs(c - v, 0, p + v, v));
            }
        } else {
            if (m > 0) {
                ans += (c / N) * (1 + dfs(0, m + c / 2, p + c / 2, v));
            } else {
                ans += (c / N) * (1 + dfs(0, 0, p + c, v));
            }
        }
    }
    if (m > 0) {
        if (m > v) {
            if (c > 0) {
                ans += (m / N) * (1 + dfs(c + v / 2, m - v, p + v / 2, v));
            } else {
                ans += (m / N) * (1 + dfs(0, m - v, p + v, v));
            }
        } else {
            if (c > 0) {
                ans += (m / N) * (1 + dfs(c + m / 2, 0, p + m / 2, v));
            } else {
                ans += (m / N) * (1 + dfs(0, 0, p + m, v));
            }
        }
    }
    return ans;
}

void solve() {
    long double c, m, p, v;
    cin >> c >> m >> p >> v;

    int ic = round(c * N);
    int im = round(m * N);
    int ip = round(p * N);
    int iv = round(v * N);
    auto ans = dfs(ic, im, ip, iv);

    cout.precision(12);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}