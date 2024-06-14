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
    int n; cin >> n;
    vi a(n); in(a);

    vi cnt(n + 2), ans(2);
    for (auto x: a) {
        cnt[x]++;
    }

    int i = 1;
    while (i <= n) {
        if (!cnt[i]) {
            i++;
            continue;
        }
        ans[0]++;
        i += 3;
    }

    vi vis(n + 2);
    for (int i = 1; i <= n; i++) {
        if (!cnt[i]) continue;
        if (cnt[i] && !vis[i - 1]) {
            vis[i - 1] = 1;
            cnt[i]--;
        }
        if (cnt[i] && !vis[i]) {
            vis[i] = 1;
            cnt[i]--;
        }
        if (cnt[i] && !vis[i + 1]) {
            vis[i + 1] = 1;
            cnt[i]--;
        }
    }
    for (int i = 0; i < n + 2; i++) {
        ans[1] += vis[i];
    }

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}