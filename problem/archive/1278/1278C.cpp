#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

#define ll long long
#define vi vector<int>
#define ssz(a) (int)((a).size())

#define endl '\n'
template <class T> void in(vector<T>& a) { for (int i = 0; i < ssz(a); i++) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < ssz(a); i++) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    int n;
    cin >> n;
    vi a(2 * n);
    in(a);

    map<int, int> left;
    int cur = 0;
    left[cur] = n;
    for (int i = 2 * n - 1; i >= n; i--) {
        if (a[i] == 1) {
            cur++;
        } else {
            cur--;
        }
        left[cur] = i - n;
    }

    int ans = 2 * n;
    cur = 0;
    ans = min(ans, n + left[cur]);
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            cur++;
        } else {
            cur--;
        }
        if (left.find(-cur) == left.end()) {
            continue;
        }
        ans = min(ans, n - i - 1 + left[-cur]);
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