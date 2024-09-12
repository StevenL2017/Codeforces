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
    int n, x;
    cin >> n >> x;
    vi a(n);
    in(a);

    vi vis(x + 1);
    int y = 1;
    while (y * y <= x) {
        if (x % y == 0) {
            vis[y] = vis[x / y] = 1;
        }
        y++;
    }

    int ans = 1;
    set<int> s;
    for (auto z: a) {
        if (z > x || !vis[z]) continue;
        int inc = 0;
        set<int> ns = s;
        for (auto pre: s) {
            if (z > x / pre) continue;
            int nxt = z * pre;
            if (nxt == x) {
                ans++;
                inc = 1;
                break;
            }
            if (x % nxt == 0) {
                ns.insert(nxt);
            }
        }
        if (inc) {
            s.clear();
        } else {
            s = ns;
        }
        s.insert(z);
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