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
    int n, m; cin >> n >> m;
    vector<vi> a(n, vi(m));
    rep(i, n) in(a[i]);

    auto check = [&] (int x) -> pair<int, int> {
        map<int, int> mp;
        rep(i, n) {
            int mask = 0;
            rep(j, m) {
                if (a[i][j] >= x) mask |= 1 << j;
            }
            mp[mask] = i;
        }

        for (auto& [mask1, i]: mp) {
            for (auto& [mask2, j]: mp) {
                if ((mask1 | mask2) == ((1 << m) - 1)) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    };

    int left = 0, right = 1e9;
    int i = -1, j = -1;
    while (left <= right) {
        auto mid = left + (right - left) / 2;
        auto temp = check(mid);
        if (temp.first != -1 && temp.second != -1) {
            left = mid + 1;
            i = temp.first;
            j = temp.second;
        } else {
            right = mid - 1;
        }
    }
    cout << i + 1 << " " << j + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}