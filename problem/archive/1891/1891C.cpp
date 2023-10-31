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
    int n; cin >> n;
    vi a(n); in(a);

    multiset<int> s;
    for (auto x: a) {
        s.insert(x);
    }

    ll ans = 0, x = 0;
    while (!s.empty()) {
        int i = *s.begin(), j = *s.rbegin();
        if (x + i < j) {
            x += i;
            ans += i;
            s.erase(s.begin());
        } else {
            if (ssz(s) == 1) {
                ans += (x + i) / 2 - x + 1 + (int)(((x + i) & 1) && x + i > 1);
            } else {
                int d = x + i - j;
                ans += i - d + 1;
                s.erase(s.begin());
                if (d) s.insert(d);
                x = 0;
            }
            s.erase(s.find(j));
        }
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