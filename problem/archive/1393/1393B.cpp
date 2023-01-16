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

const int N = 1e5 + 3;

int p[N];

void solve() {
    int n; cin >> n;
    int c2 = 0, c4 = 0;
    rep(i, n) {
        int x; cin >> x;

        c2 -= p[x] / 2;
        c4 -= p[x] / 4;
        p[x]++;
        c2 += p[x] / 2;
        c4 += p[x] / 4;
    }

    int q; cin >> q;
    while (q--) {
        char op; cin >> op;
        int x; cin >> x;
        
        c2 -= p[x] / 2;
        c4 -= p[x] / 4;
        if (op == '+') p[x]++;
        else p[x]--;
        c2 += p[x] / 2;
        c4 += p[x] / 4;

        if (c2 >= 4 && c4 >= 1) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}