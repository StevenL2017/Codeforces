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
    string s; cin >> s;

    int n = s.size();
    if (n < 4) {
        cout << "NO\n";
        return;
    }

    vi pre_ab(n, 0), pre_ba(n, 0);
    for (int i = 1; i < n; i++) {
        pre_ab[i] = max(pre_ab[i], pre_ab[i - 1]);
        pre_ba[i] = max(pre_ba[i], pre_ba[i - 1]);
        if (s[i - 1] == 'A' && s[i] == 'B') pre_ab[i] = 1;
        else if (s[i - 1] == 'B' && s[i] == 'A') pre_ba[i] = 1;
    }
    vi suf_ab(n, 0), suf_ba(n, 0);
    for (int i = n - 2; i >= 0; i--) {
        suf_ab[i] = max(suf_ab[i], suf_ab[i + 1]);
        suf_ba[i] = max(suf_ba[i], suf_ba[i + 1]);
        if (s[i] == 'A' && s[i + 1] == 'B') suf_ab[i] = 1;
        else if (s[i] == 'B' && s[i + 1] == 'A') suf_ba[i] = 1;
    }

    for (int i = 1; i < n - 2; i++) {
        if (pre_ab[i] && suf_ba[i + 1] || pre_ba[i] && suf_ab[i + 1]) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}