#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
#include <random>
using namespace std;

#define ll long long
#define vi vector<int>

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; ++i)
#define repa(i, a, n)       for (int i = a; i < n; ++i)
#define repd(i, a, n)       for (int i = a; i > n; --i)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

void solve() {
    ll k; cin >> k;

    auto check = [&] (int n) -> bool {
        auto c = n / 10;
        auto res = n % 10;
        ll tot = 1;
        rep(i, 10) {
            tot *= c + (res > 0 ? 1 : 0);
            if (tot >= k) return true;
            res--;
        }
        return false;
    };

    int left = 1e1, right = 1e9, ans = right;
    while (left <= right) {
        auto mid = left + (right - left) / 2;
        if (check(mid)) {
            right = mid - 1;
            ans = mid;
        } else {
            left = mid + 1;
        }
    }

    auto c = ans / 10;
    auto res = ans % 10;
    string s, temp = "codeforces";
    rep(i, 10) {
        string cur(c + (res > 0 ? 1 : 0), temp[i]);
        s += cur;
        res--;
    }
    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}