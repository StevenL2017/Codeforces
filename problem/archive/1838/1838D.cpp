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
    int n, q; cin >> n >> q;
    string s; cin >> s;

    set<int> a;
    for (int i = 1; i <= n; i++) {
        if ((i & 1) != (s[i - 1] == '(')) {
            a.insert(i);
        }
    }

    while (q--) {
        int idx; cin >> idx;

        if (n & 1) {
            cout << "NO\n";
            continue;
        }

        if (a.count(idx)) a.erase(idx);
        else a.insert(idx);

        if (ssz(a) && (*a.begin() & 1 || *a.rbegin() % 2 == 0)) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}