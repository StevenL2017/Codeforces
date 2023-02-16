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
    string a, b; cin >> a >> b;

    vi cnt_a(26, 0), cnt_b(26, 0);
    rep(i, n) {
        cnt_a[a[i] - 'a']++;
        cnt_b[b[i] - 'a']++;
    }

    int d = 0;
    for (int i = 25; i >= 0; i--) {
        if (cnt_a[i] == cnt_b[i]) {
            continue;
        }
        auto cur = abs(cnt_a[i] - cnt_b[i]);
        if (cur % k != 0) {
            cout << "No\n";
            return;
        }
        if (cnt_a[i] > cnt_b[i]) {
            if (cur > d) {
                cout << "No\n";
                return;
            }
            d -= cur;
        } else {
            d += cur;
        }
    }

    if (d == 0) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}