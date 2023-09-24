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

const int N = 2e5;

int vis[N];

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    sort(a.begin(), a.end());
    for (auto x: a) {
        if (x - 1 > 0 && !vis[x - 1]) {
            vis[x - 1] = 1;
        } else if (!vis[x]) {
            vis[x] = 1;
        } else if (!vis[x + 1]) {
            vis[x + 1] = 1;
        }
    }

    int ans = 0;
    for (auto x: vis) {
        ans += x;
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