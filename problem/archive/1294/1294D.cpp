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
    int q, x; cin >> q >> x;

    set<int> s;
    for (int i = 0; i <= q; i++) {
        s.insert(i);
    }

    vi a(x, 0);
    for (int i = 0; i < x; i++) {
        a[i] = i;
    }

    while (q--) {
        int y; cin >> y;
        
        int mod = y % x;
        if (s.count(a[mod])) {
            s.erase(a[mod]);
            a[mod] += x;
        }

        cout << *s.begin() << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}