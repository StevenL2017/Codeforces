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
    string l, r;
    cin >> l >> r;

    int n = ssz(r);
    if (l == r) {
        cout << n * 2 << endl;
        return;
    }

    int p = 0;
    while (p < n && l[p] == r[p]) {
        p++;
    }

    if (l[p] + 1 < r[p]) {
        cout << p * 2 << endl;
        return;
    }

    int ans = p * 2 + 1;
    p++;
    while (p < n && l[p] == '9' && r[p] == '0') {
        ans++;
        p++;
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