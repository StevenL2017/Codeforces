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
    string s;
    cin >> n >> s;

    vi ans;
    bool b = 0;
    for (int i = 0; i < 2 * n; i += 2) {
        if (s[i] != s[i + 1]) {
            if (b ^ (s[i] == '0')) {
                ans.push_back(i);
            } else {
                ans.push_back(i + 1);
            }
            b ^= 1;
        }
    }

    if (ans.size() % 2 != 0) {
        cout << -1 << endl;
        return;
    }

    cout << ans.size();
    for (auto& x: ans) cout << " " << x + 1;
    cout << endl;
    for (int i = 1; i < 2 * n; i += 2) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}