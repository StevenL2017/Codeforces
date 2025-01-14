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

    if (n == 1) {
        cout << -1 << endl;
        return;
    }

    sort(begin(a), end(a));
    map<int, int> cnt;
    for (int i = 1; i < n; i++) {
        int d = a[i] - a[i - 1];
        cnt[d]++;
        if (ssz(cnt) > 2) {
            cout << 0 << endl;
            return;
        }
    }

    int d1 = -1, d2 = -1;
    for (auto [k, _]: cnt) {
        if (d1 == -1) {
            d1 = k;
        } else if (d2 == -1) {
            d2 = k;
        }
    }

    if (d2 != -1 && d1 > d2) {
        swap(d1, d2);
    }

    if (d2 != -1 && (d1 * 2 != d2 || cnt[d2] > 1)) {
        cout << 0 << endl;
        return;
    }

    if (d2 != -1) {
        for (int i = 1; i < n; i++) {
            if (a[i] - a[i - 1] == d2) {
                cout << 1 << endl;
                cout << a[i - 1] + d1 << endl;
                return;
            }
        }
    }

    if (a.front() == a.back()) {
        cout << 1 << endl;
        cout << a.front() + d1 << endl;
        return;
    }

    if (cnt[d1] == 1 && d1 % 2 == 0) {
        cout << 3 << endl;
        cout << a.front() - d1 << " " << a.front() + d1 / 2 << " " << a.back() + d1 << endl;
        return;
    }

    cout << 2 << endl;
    cout << a.front() - d1 << " " << a.back() + d1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}