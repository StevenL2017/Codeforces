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

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    int n, k, l;
    cin >> n >> k >> l;
    vi d(n + 2, -k), safe(1, 0);
    rep(i, n) {
        cin >> d[i + 1];
        if (d[i + 1] + k <= l) {
            safe.push_back(i + 1);
        }
    }
    safe.push_back(n + 1);

    bool ok = true;
    for (int i = 1; i < ssz(safe) && ok; i++) {
        int tide = k; bool down = true;
        for (int j = safe[i - 1] + 1; j < safe[i]; j++) {
            tide += down ? -1 : 1;
            if (down) tide -= max(0, d[j] + tide - l);
            if (tide < 0 || d[j] + tide > l) {
                ok = false;
                break;
            }
            if (tide == 0) down = false;
        }
    }

    if (ok) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}