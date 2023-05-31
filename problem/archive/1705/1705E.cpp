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
    vi a(n); in(a);

    set<int, greater<int>> pos, neg;

    function<void(int)> add = [&] (int x) {
        if (neg.count(x)) {
            neg.erase(x);
            return;
        }
        if (pos.count(x)) {
            pos.erase(x);
            add(x + 1);
            return;
        }
        pos.insert(x);
    };

    function<void(int)> remove = [&] (int x) {
        if (pos.count(x)) {
            pos.erase(x);
            return;
        }
        if (neg.count(x)) {
            neg.erase(x);
            remove(x + 1);
            return;
        }
        neg.insert(x);
    };

    for (auto x : a) {
        add(x);
    }

    while (q--) {
        int k, l; cin >> k >> l;
        k--;

        remove(a[k]);
        a[k] = l;
        add(a[k]);

        while (!neg.empty() && *neg.begin() == *pos.begin() - 1) {
            int x = *neg.begin();
            remove(x + 1);
            add(x);
            add(x);
        }

        int ans = *pos.begin();
        if (ssz(pos) == 1 && !neg.empty()) {
            ans--;
        }
        else if (ssz(pos) > 1 && !neg.empty() && *neg.begin() > *next(pos.begin())) {
            ans--;
        }
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}