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

    int mx = *max_element(a.begin(), a.end());
    bool ok = false;
    for (auto x : a) {
        if (x < mx) {
            ok = true;
            break;
        }
    }

    if (!ok) {
        cout << -1 << endl;
        return;
    }

    vi b, c;
    for (auto x : a) {
        if (x < mx) b.push_back(x);
        else c.push_back(mx);
    }

    cout << ssz(b) << " " << ssz(c) << endl;
    out(b);
    out(c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}