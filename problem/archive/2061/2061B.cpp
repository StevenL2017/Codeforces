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
    vi a(n);
    in(a);

    int d = 0;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        cnt[x]++;
        if (cnt[x] == 2) {
            if (d == 0) {
                d = x;
            } else {
                cout << d << " " << d << " " << x << " " << x << endl;
                return;
            }
        }
        if (cnt[x] == 4) {
            cout << x << " " << x << " " << x << " " << x << endl;
            return;
        }
    }

    if (d == 0) {
        cout << -1 << endl;
        return;
    }

    if (cnt[d] == 2) {
        cnt.erase(cnt.find(d));
    }

    int pre = 0;
    for (auto [k, _]: cnt) {
        if (pre == 0) {
            pre = k;
            continue;
        }
        if (d * 2 + pre > k) {
            cout << d << " " << d << " " << pre << " " << k << endl;
            return;
        }
        pre = k;
    }
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}