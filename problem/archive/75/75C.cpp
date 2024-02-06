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
    int a, b;
    cin >> a >> b;

    auto g = gcd(a, b);
    vi f;
    for (int i = 1; i * i <= g; i++) {
        if (g % i) continue;
        f.push_back(i);
        if (i * i < g) {
            f.push_back(g / i);
        }
    }
    sort(f.begin(), f.end());

    int n;
    cin >> n;
    while (n--) {
        int low, high;
        cin >> low >> high;

        auto l = lower_bound(f.begin(), f.end(), low) - f.begin();
        auto r = upper_bound(f.begin(), f.end(), high) - f.begin();
        if (l < r) {
            cout << f[r - 1] << endl;
        } else {
            cout << -1 << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}