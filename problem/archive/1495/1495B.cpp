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
    int n; cin >> n;
    vi a(n); in(a);

    int mx = 2;
    set<int> peak;
    for (int i = 0, j = 0; i < n - 1; ) {
        while (j + 1 < n && a[j + 1] < a[j]) {
            j++;
        }
        if (j - i + 1 > mx) {
            mx = j - i + 1;
            peak.clear();
            peak.insert(i);
        }
        else if (j - i + 1 == mx) {
            peak.insert(i);
        }
        i = j;
        while (j + 1 < n && a[j + 1] > a[j]) {
            j++;
        }
        if (j - i + 1 > mx) {
            mx = j - i + 1;
            peak.clear();
            peak.insert(j);
        }
        else if (j - i + 1 == mx) {
            peak.insert(j);
        }
        i = j;
    }

    if (ssz(peak) > 1) {
        cout << 0 << endl;
        return;
    }

    int i = *peak.begin(), j = i, k = i;
    while (j - 1 >= 0 && a[j - 1] < a[j]) {
        j--;
    }
    while (k + 1 < n && a[k + 1] < a[k]) {
        k++;
    }
    int mn = min(i - j + 1, k - i + 1);
    if (mx % 2 == 0 || mx - 1 >= mn) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}