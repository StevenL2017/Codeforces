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

void solve() {
    int n, m; cin >> n >> m;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 == 1 && y1 == 1 || x2 == 1 && y2 == 1) {
        cout << 2 << endl;
    }
    else if (x1 == 1 && y1 == m || x2 == 1 && y2 == m) {
        cout << 2 << endl;
    }
    else if (x1 == n && y1 == 1 || x2 == n && y2 == 1) {
        cout << 2 << endl;
    }
    else if (x1 == n && y1 == m || x2 == n && y2 == m) {
        cout << 2 << endl;
    }
    else if (x1 == 1 || x1 == n || y1 == 1 || y1 == m) {
        cout << 3 << endl;
    }
    else if (x2 == 1 || x2 == n || y2 == 1 || y2 == m) {
        cout << 3 << endl;
    }
    else {
        cout << 4 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}