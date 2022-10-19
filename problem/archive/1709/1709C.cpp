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
    string s;
    cin >> s;

    int n = s.size();
    int open = n / 2, close = n / 2;
    vi q;
    rep(i, n) {
        if (s[i] == '(') open--;
        else if (s[i] == ')') close--;
        else q.push_back(i);
    }

    if (open == 0 || close == 0) {
        cout << "YES\n";
        return;
    }

    rep(i, q.size()) {
        if (i < open) s[q[i]] = '(';
        else s[q[i]] = ')';
    }

    swap(s[q[open - 1]], s[q[open]]);
    int cnt = 0;
    rep(i, n) {
        if (s[i] == '(') cnt++;
        else cnt--;
        if (cnt < 0) {
            cout << "YES\n";
            return;
        }
    }
    if (cnt != 0) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}