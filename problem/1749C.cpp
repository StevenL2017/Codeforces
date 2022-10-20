#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
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
#include <utility>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int MAXN = 1e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 2e9 + 7; // const ll INF = 9e18 + 7;

#define _  %  MOD
#define __ %= MOD

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v)               sort(v.rbegin(), v.rend())

#define rep(i, n)              for (int i = 0; i < n; ++i)
#define repA(i, a, n)          for (int i = a; i < n; ++i)
#define repD(i, a, n)          for (int i = a; i > n; --i)

void solve() {
    int n; cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    sortA(a);
    int ans = 0;
    repA(i, 1, (n + 1) / 2 + 1) {
        int idx = upper_bound(a.begin(), a.end(), i) - a.begin();
        if (idx == 0) {
            continue;
        }
        int k = i, left = 0, right = idx - 1;
        bool valid = true;
        while (k) {
            if (left <= right && a[right] <= k) {
                right--;
                while (right >= 0 && a[right] == k) right--;
                left++;
                k--;
            } else {
                valid = false;
                break;
            }
        }
        if (valid) ans = i;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}