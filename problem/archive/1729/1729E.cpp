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

ll query(ll a, ll b) {
    cout << "? " << a << " " << b << endl;
    cout.flush();
    ll x; cin >> x;
    return x;
}

void solve() {
    int x = 2, cnt = 50;
    while (cnt--) {
        ll q1 = query(1, x);
        ll q2 = query(x, 1);
        if (q1 == -1 || q2 == -1) {
            cout << "! " << x - 1 << endl;
            cout.flush();
            return;
        }
        if (q1 != q2) {
            cout << "! " << q1 + q2 << endl;
            cout.flush();
            return;
        }
        x++;
        cnt -= 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}