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
    int n;
    cin >> n;
    vi a(n + 2), d(n + 2, INT_MAX);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }

    set<int> left, s;
    for (int i = 0; i < n + 2; i++) {
        left.insert(i);
        s.insert(i);
    }

    while (n--) {
        set<int> tbd, ns;
        for (auto x: s) {
            auto it = left.find(x);
            if (it == left.end()) continue;
            int pre = *prev(it);
            int nxt = *next(it);
            if (a[pre] + a[nxt] > d[x]) {
                tbd.insert(x);
                ns.insert(pre);
                ns.insert(nxt);
            }
        }
        cout << ssz(tbd) << " ";
        for (auto x: tbd) {
            left.erase(x);
        }
        s = ns;
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