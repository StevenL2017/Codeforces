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
    int n; cin >> n;
    vi a(n); in(a);

    int a1 = -1, a2 = -1;
    rep(i, n) {
        if (a1 == -1) {
            a1 = i;
        }
        else if (a2 == -1 && a[i] != a[a1]) {
            a2 = i;
            break;
        }
    }

    if (a2 == -1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    rep(i, n) {
        if (a[i] == a[a1]) {
            cout << i + 1 << " " << a2 + 1 << endl;
        }
        if (a[i] != a[a1] && i != a2) {
            cout << i + 1 << " " << a1 + 1 << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}