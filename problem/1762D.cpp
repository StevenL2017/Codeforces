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

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

int query(int i, int j) {
    cout << "? " << i << " " << j << endl;
    cout.flush();
    int g; cin >> g;
    return g;
}

void output(int i, int j) {
    cout << "! " << i << " " << j << endl;
    cout.flush();
    int r; cin >> r;
}

void solve() {
    int n; cin >> n;

    int x = 1, y = 2;
    int g = query(x, y);
    repa(i, 3, n + 1) {
        int gx = query(x, i);
        int gy = query(y, i);
        if (gx >= max(gy, g)) {
            y = i;
            g = gx;
        }
        else if (gy >= max(gx, g)) {
            x = i;
            g = gy;
        }
    }

    output(x, y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}