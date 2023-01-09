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
    int k, n; cin >> k >> n;

    auto calc = [&] (int x) -> vi {
        vi ans;
        for (int i = 0; i < k - 1; i++) {
            if (i < x - 1) ans.push_back(i + 2);
            else ans.push_back(1);
        }
        return ans;
    };

    int mx = 1;
    for (int x = 1; x < k; x++) {
        auto d = calc(x);
        int s = 0;
        for(auto& y: d) s += y;
        if (s < n) mx = x;
    }

    vi ans(1, 1), d = calc(mx);
    for(auto& y: d) ans.push_back(ans.back() + y);
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}