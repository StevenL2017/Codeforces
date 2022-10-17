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
    int n;
    string s;
    cin >> n >> s;

    string ns = "";
    int first = 0;
    while (first < n && s[first] == '0') {
        first++;
    }
    repA(i, first, n) {
        ns += s[i];
    }

    int m = ns.size();
    if (m == 0) {
        cout << "0" << endl;
        return;
    }
    
    string ans1 = ns;
    string ans2 = ns;

    int cnt_ones = 0, cnt_zeros = 0;
    int i = 0;
    while (i < m && ns[i] == '1') {
        cnt_ones++;
        i++;
    }
    int start_zero = i;

    while (i < m && ns[i] == '0') {
        cnt_zeros++;
        i++;
    }
    int start_one = max(0, cnt_ones - cnt_zeros);

    int start_zero2 = start_zero;
    int start_one2 = 0;

    while (start_zero < m && start_one < m) {
        if (ns[start_one] == '1') {
            ans1[start_zero] = '1';
        }
        start_zero++;
        start_one++;
    }

    while (start_zero2 < m && start_one2 < m) {
        if (ns[start_one2] == '1') {
            ans2[start_zero2] = '1';
        }
        start_zero2++;
        start_one2++;
    }

    cout << max(ans1, ans2) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}