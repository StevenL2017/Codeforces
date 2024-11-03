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
    ll n;
    cin >> n;

    n *= n;
    ll x = 1;
    while (x * x <= n) {
        if (n % x == 0) {
            // a + b = n / x
            // a - b = x
            auto y = n / x;
            if ((x + y) % 2 == 0) {
                ll a = (x + y) / 2, b = a - x;
                if (b > 0 && n + b * b == a * a) {
                    cout << b << " " << a << endl;
                    return;
                }
            }
        }
        x++;
    }
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}