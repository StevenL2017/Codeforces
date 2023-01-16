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
    vector<vi> a(1001);
    rep(i, n) {
        int r, c; cin >> r >> c;
        a[r].push_back(c);
    }

    string s;
    int c = 0, cnt = 0;
    rep(r, 1001) {
        if (!a[r].empty()) {
            sorta(a[r]);
            if (c > a[r].front()) {
                cout << "NO\n";
                return;
            }
            while (c < a[r].back()) {
                s += 'U';
                c++;
            }
            cnt += ssz(a[r]);
            if (cnt == n) break;
        }
        s += 'R';
    }

    cout << "YES\n" << s << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}