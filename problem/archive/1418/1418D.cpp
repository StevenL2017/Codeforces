#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
#include <random>
using namespace std;

#define ll long long
#define vi vector<int>

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; ++i)
#define repa(i, a, n)       for (int i = a; i < n; ++i)
#define repd(i, a, n)       for (int i = a; i > n; --i)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

int calc(const set<int>& p, const multiset<int>& d) {
    if (d.empty()) return 0;
    return *p.rbegin() - *p.begin() - *d.rbegin();
}

void add(int x, set<int>& p, multiset<int>& d) {
    int pre = -1, nxt = -1;
    p.insert(x);
    auto it = p.find(x);
    if (it != p.begin()) {
        it--;
        pre = *it;
        d.insert(x - pre);
        it++;
    }
    it++;
    if (it != p.end()) {
        nxt = *it;
        d.insert(nxt - x);
    }
    if (pre != -1 && nxt != -1) {
        d.erase(d.find(nxt - pre));
    }
}

void remove(int x, set<int>& p, multiset<int>& d) {
    int pre = -1, nxt = -1;
    auto it = p.find(x);
    if (it != p.begin()) {
        it--;
        pre = *it;
        d.erase(d.find(x - pre));
        it++;
    }
    it++;
    if (it != p.end()) {
        nxt = *it;
        d.erase(d.find(nxt - x));
    }
    p.erase(x);
    if (pre != -1 && nxt != -1) {
        d.insert(nxt - pre);
    }
}

void solve() {
    int n, q; cin >> n >> q;
    set<int> p;
    multiset<int> d;
    rep(i, n) {
        int x; cin >> x;
        add(x, p, d);
    }

    cout << calc(p, d) << endl;
    while (q--) {
        int t, x; cin >> t >> x;
        if (t) {
            add(x, p, d);
        } else {
            remove(x, p, d);
        }
        cout << calc(p, d) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}