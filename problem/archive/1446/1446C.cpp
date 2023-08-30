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

int calc(const vi& a) {
    if (ssz(a) == 1) return 1;
    int k = 0, num = a.front() ^ a.back();
    for (int i = 30; i >= 0; i--) {
        if (num >> i & 1) {
            k = 1 << i;
            break;
        }
    }
    auto it = partition_point(a.begin(), a.end(), [&] (int x) { return (x & k) == 0; });
    return 1 + max(calc(vi(a.begin(), it)), calc(vi(it, a.end())));
}

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    sort(a.begin(), a.end());
    cout << n - calc(a) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}