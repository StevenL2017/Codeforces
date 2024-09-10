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
    int n, l, r, s;
    cin >> n >> l >> r >> s;

    vi ans(r - l + 1);
    set<int> ss;
    for (int i = 0; i < r - l + 1; i++) {
        s -= i + 1;
        ans[i] = i + 1;
        ss.insert(i + 1);
    }

    if (s < 0) {
        cout << -1 << endl;
        return;
    }

    for (int i = r - l; i >= 0; i--) {
        int j = n - (r - l - i);
        int d = min(s, j - ans[i]);
        ss.erase(ans[i]);
        ans[i] += d;
        ss.insert(ans[i]);
        s -= d;
        if (s == 0) break;
    }

    if (s > 0) {
        cout << -1 << endl;
        return;
    }

    vi rem;
    for (int i = 0; i < n; i++) {
        if (ss.count(i + 1)) continue;
        rem.push_back(i + 1);
    }

    int j = 0;
    for (int i = 0; i < l - 1; i++) {
        cout << rem[j++] << " ";
    }
    for (auto x: ans) {
        cout << x << " ";
    }
    for (int i = r; i < n; i++) {
        cout << rem[j++] << " ";
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