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
    int n, k;
    cin >> n >> k;
    vi a(n);
    in(a);

    vi pos(n + 1), pre(n + 1), suf(n + 1);
    set<int> s;
    for (int i = 0; i < n; i++) {
        pos[a[i]] = i;
        if (i > 0) pre[a[i]] = a[i - 1];
        if (i < n - 1) suf[a[i]] = a[i + 1];
        s.insert(a[i]);
    }

    string ans(n, '0');
    int t = 1;
    while (!s.empty()) {
        int mx = *s.rbegin();
        ans[pos[mx]] = t + '0';
        s.erase(mx);
        int p1 = pre[mx], c1 = k;
        while (p1 && c1) {
            ans[pos[p1]] = t + '0';
            s.erase(p1);
            p1 = pre[p1];
            c1--;
        }
        int p2 = suf[mx], c2 = k;
        while (p2 && c2) {
            ans[pos[p2]] = t + '0';
            s.erase(p2);
            p2 = suf[p2];
            c2--;
        }
        if (p1) suf[p1] = p2;
        if (p2) pre[p2] = p1;
        t ^= 3;
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