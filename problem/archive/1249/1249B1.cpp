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

    vi vis(n, 0), fa(n, -1), cnt(n, 0);
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        int f = i;
        vis[i] = 1;
        fa[i] = f;
        int nxt = a[i] - 1, c = 1;
        while (nxt != f) {
            vis[nxt] = 1;
            fa[nxt] = f;
            c++;
            nxt = a[nxt] - 1;
        }
        cnt[f] = c;
    }

    for (int i = 0; i < n; i++) {
        cout << cnt[fa[i]] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}