#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _  %  MOD
#define __ %= MOD

#define pq(T)                  priority_queue<T, vector<T>>
#define rpq(T)                 priority_queue<T, vector<T>, greater<T>>

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v)               sort(v.begin(), v.end(), greater<auto>())

#define rep(i, n)              for(int i = 0; i < n; ++i)
#define repA(i, a, n)          for(int i = a; i < n; ++i)
#define repD(i, a, n)          for(int i = a; i > n; --i)
#define loop(i, start, end)    for(auto i = start; (start<end)?i<end:i>end; (start<end)?i++:i--)

int main() {
    int m, s;
    cin >> m >> s;
    if ((s + 9 - 1) / 9 > m || (m > 1 && s == 0)) {
        cout << -1 << " " << -1;
        return 0;
    }
    if (s == 1) {
        string ans = "1";
        rep(i, m - 1) {
            ans += "0";
        }
        cout << ans << " " << ans;
        return 0;
    }

    vi mind, maxd;
    int x = s;
    while (x > 9) {
        mind.push_back(9);
        maxd.push_back(9);
        x -= 9;
    }

    maxd.push_back(x);
    while (maxd.size() < m) {
        maxd.push_back(0);
    }

    if (mind.size() < m - 1 && x > 1) {
        mind.push_back(x - 1);
        x = 1;
    }
    while (mind.size() < m - 1) {
        mind.push_back(0);
    }
    mind.push_back(x);

    string minx, maxx;
    repD(i, m - 1, -1) {
        minx += to_string(mind[i]);
    }
    rep(i, m) {
        maxx += to_string(maxd[i]);
    }
    cout << minx << " " << maxx;
    return 0;
}