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
    vi b(n); in(b);

    bool ok = true;
    set<int> s;
    s.insert(b[0]);
    repa(i, 1, n) {
        if (b[i] == b[i - 1]) continue;
        if (b[i] < b[i - 1]) {
            auto it = s.upper_bound(b[i]);
            if (it != s.end() && *it < b[i - 1]) {
                ok = false;
                break;
            }
        } else {
            auto it = s.lower_bound(b[i]);
            if (it != s.begin() && *(--it) > b[i - 1]) {
                ok = false;
                break;
            }
        }
        s.insert(b[i]);
    }

    if (ok) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}