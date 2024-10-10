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

const string s = "narek";

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    in(a);

    int ans = 0;
    vi f(5, -1e9);
    f[0] = 0;
    for (int i = 0; i < n; i++) {
        vi g = f;
        for (int j = 0; j < 5; j++) {
            if (f[j] == -1e9) continue;
            int pos = j, cnt = 0;
            for (int k = 0; k < m; k++) {
                if (a[i][k] == s[pos]) {
                    pos++;
                    pos %= 5;
                    cnt++;
                } else if (s.find(a[i][k]) < 5) {
                    cnt--;
                }
            }
            g[pos] = max(g[pos], f[j] + cnt);
        }
        f = g;
        for (int j = 0; j < 5; j++) {
            ans = max(ans, f[j] - 2 * j);
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}