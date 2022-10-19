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
#define loop(i, start, end)    for (auto i = start; (start<end)?i<end:i>end; (start<end)?i++:i--)

void solve() {
    string t;
    cin >> t;

    map<char, int> cnt;
    for (auto& c: t) cnt[c]++;

    int m = cnt.size(), i = t.size() - 1, d = 0, end = i;
    set<char> order;
    while (i >= 0) {
        int j = i;
        while (j >= 0 && order.count(t[j])) {
            j--;
        }
        if (j < 0) {
            cout << -1 << endl;
            return;
        }

        char c = t[j];
        order.insert(c);
        if (cnt[c] % m) {
            cout << -1 << endl;
            return;
        }
        d += cnt[c] / m;
        if (i - d >= 0) end = i;
        i -= d;
        m--;
    }

    if (i < -1) {
        cout << -1 << endl;
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}