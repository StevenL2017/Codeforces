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
    int a, b, k;
    cin >> a >> b >> k;

    if (a == 1 && b == 1) {
        cout << "NO" << endl;
        return;
    }

    int tota = 0, totb = 0;
    int x = a, y = b;
    int d = 2;
    while (d * d <= x) {
        while (x > 0 && x % d == 0) {
            tota++;
            x /= d;
        }
        d++;
    }
    if (x > 1) {
        tota++;
    }
    d = 2;
    while (d * d <= y) {
        while (y > 0 && y % d == 0) {
            totb++;
            y /= d;
        }
        d++;
    }
    if (y > 1) {
        totb++;
    }

    if (a == 1) {
        if (k <= totb) cout << "YES" << endl;
        else cout << "NO" << endl;
        return;
    }
    if (b == 1) {
        if (k <= tota) cout << "YES" << endl;
        else cout << "NO" << endl;
        return;
    }

    if (a != b && (a % b == 0 || b % a == 0)) {
        if (k <= tota + totb) cout << "YES" << endl;
        else cout << "NO" << endl;
    } else {
        if (k >= 2 && k <= tota + totb) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}