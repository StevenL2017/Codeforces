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
    int n, x0, y0;
    cin >> n >> x0 >> y0;
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x == x0) {
            s.emplace(0, 1);
        } else if (y == y0) {
            s.emplace(1, 0);
        } else {
            int d1 = abs(x - x0), d2 = abs(y - y0);
            int g = gcd(d1, d2);
            d1 /= g;
            d2 /= g;
            if ((x - x0) * (y - y0) > 0) {
                s.emplace(d1, d2);
            } else {
                s.emplace(d1, -d2);
            }
        }
    }
    cout << ssz(s) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}