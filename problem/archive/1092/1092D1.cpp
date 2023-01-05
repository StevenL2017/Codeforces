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

    vi b;
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && (a[i] & 1) == (a[j] & 1)) j++;
        b.push_back(j - i);
        i = j;
    }

    bool change = true;
    while (change) {
        change = false;
        vi c;
        for (int i = 0; i < ssz(b); i++) {
            int x = b[i];
            bool flag = true;
            while (flag && x % 2 == 0) {
                flag = false;
                if (!c.empty()) {
                    x += c.back();
                    c.pop_back();
                    change = true;
                    flag = true;
                }
                if (i + 1 < ssz(b)) {
                    x += b[i + 1];
                    i++;
                    change = true;
                    flag = true;
                }
            }
            c.push_back(x);
        }
        b = c;
    }

    if (ssz(b) == 1) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}