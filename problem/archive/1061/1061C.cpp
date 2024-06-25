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

const int MOD = 1e9 + 7;
const int N = 1e6 + 1;

int cnt[N];

int add(int x, int y) {
    x += y;
    while (x >= MOD) x -= MOD;
    while (x < 0) x += MOD;
    return x;
}

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    cnt[0] = 1;
    for (auto x : a) {
        int y = 1;
        vi d;
        while (y * y <= x) {
            if (x % y == 0) {
                d.push_back(y);
                if (y * y < x) {
                    d.push_back(x / y);
                }
            }
            y++;
        }
        sort(d.begin(), d.end());
        for (int i = ssz(d) - 1; i >= 0; i--) {
            cnt[d[i]] = add(cnt[d[i]], cnt[d[i] - 1]);
        }
    }

    int ans = 0;
    for (int i = 1; i < N; i++) {
        ans = add(ans, cnt[i]);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}