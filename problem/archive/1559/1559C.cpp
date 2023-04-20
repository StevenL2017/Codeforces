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

    if (a.front() == 1) {
        vi ans(1, n + 1);
        repa(i, 1, n + 1) {
            ans.push_back(i);
        }
        out(ans);
    }
    else if (a.back() == 0) {
        vi ans(n + 1);
        iota(ans.begin(), ans.end(), 1);
        out(ans);
    }
    else {
        vi ans;
        bool vis = false;
        rep(i, n) {
            ans.push_back(i + 1);
            if (i < n - 1 && a[i] == 0 && a[i + 1] == 1 && !vis) {
                ans.push_back(n + 1);
                vis = true;
            }
        }
        out(ans);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}