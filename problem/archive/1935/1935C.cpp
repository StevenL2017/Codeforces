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
    int n, l;
    cin >> n >> l;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].second >> a[i].first;
    }

    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        multiset<int> s;
        int cur = 0;
        for (int j = i; j < n; j++) {
            s.insert(a[j].second);
            cur += a[j].second;
            while (!s.empty() && a[j].first - a[i].first + cur > l) {
                int mx = *s.rbegin();
                cur -= mx;
                s.extract(mx);
            }
            ans = max(ans, ssz(s));
        }
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