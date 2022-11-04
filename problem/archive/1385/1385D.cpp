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
    int n; string s;
    cin >> n >> s;

    function<int(int, int, char)> dfs = [&] (int left, int right, char c) -> int {
        if (left > right) return 0;
        if (left == right) return (int)(s[left] != c);
        auto mid = left + (right - left + 1) / 2;
        int pre = 0, suf = 0;
        repa(i, left, mid) {
            if (s[i] != c) pre++;
        }
        repa(i, mid, right + 1) {
            if (s[i] != c) suf++;
        }
        return min(pre + dfs(mid, right, c + 1), suf + dfs(left, mid - 1, c + 1));
    };
    
    cout << dfs(0, n - 1, 'a') << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}