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
    int n, k; cin >> n >> k;

    if (k == n - 1) {
        if (n == 4) {
            cout << -1 << endl;
        } else {
            cout << 1 << " " << n - 3 << endl;
            cout << n - 2 << " " << n - 1 << endl;
            cout << 0 << " " << 2 << endl;
            repa(i, 3, n / 2) {
                cout << i << " " << ((n - 1) ^ i) << endl;
            }
        }
        return;
    }

    cout << k << " " << n - 1 << endl;
    if (k) cout << 0 << " " << ((n - 1) ^ k) << endl;
    repa(i, 1, n / 2) {
        if (i == 0 || i == k || ((n - 1) ^ i) == k) continue;
        cout << i << " " << ((n - 1) ^ i) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}