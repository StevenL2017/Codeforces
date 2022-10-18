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
#include <tuple>
#include <numeric>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int MAXN = 1e6 + 3;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

#define _  %  MOD
#define __ %= MOD

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v)               sort(v.rbegin(), v.rend())

#define rep(i, n)              for (int i = 0; i < n; ++i)
#define repA(i, a, n)          for (int i = a; i < n; ++i)
#define repD(i, a, n)          for (int i = a; i > n; --i)
#define loop(i, start, end)    for (auto i = start; (start<end)?i<end:i>end; (start<end)?i++:i--)

void solve() {
    int n;
    cin >> n;
    vi a(n);
    ll s = 0LL;
    rep(i, n) {
        cin >> a[i];
        s += a[i];
    }

    int ans = n;
    ll tot = 0LL;
    rep(i, n) {
        tot += a[i];
        if (s % tot != 0) continue;
        int length = i + 1, pre = i;
        ll temp = 0LL;
        bool valid = true;
        repA(j, i + 1, n){
            temp += a[j];
            if (temp == tot) {
                length = max(length, j - pre);
                pre = j;
                temp = 0LL;
            } else if (temp > tot) {
                valid = false;
                break;
            }
        }
        if (valid) {
            ans = min(ans, length);
        }
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