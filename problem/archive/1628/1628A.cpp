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

    vi cnt(n + 1, 0);
    rep(i, n) {
        cnt[a[i]]++;
    }

    int mx = -1;
    rep(i, n + 1) {
        if (cnt[i]) {
            mx++;
        } else {
            break;
        }
    }

    vi ans;
    set<int> s;
    int nxt = mx;
    rep(i, n) {
        cnt[a[i]]--;
        if (cnt[a[i]] == 0) {
            nxt = min(nxt, a[i] - 1);
        }
        if (a[i] <= mx) {
            s.insert(a[i]);
        }
        if (ssz(s) == mx + 1) {
            ans.push_back(mx + 1);
            s.clear();
            mx = nxt;
        }
    }

    cout << ssz(ans) << endl;
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}