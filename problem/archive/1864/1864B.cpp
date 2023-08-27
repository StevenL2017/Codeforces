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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    if (k % 2 == 0) {
        sort(s.begin(), s.end());
        cout << s << endl;
        return;
    }

    string odd, even;
    for (int i = 0; i < n; i++) {
        if ((i + 1) & 1) odd += s[i];
        else even += s[i];
    }

    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    string ans;
    for (int i = 0, j = 0, k = 0; i < n; i++) {
        if ((i + 1) & 1) ans += odd[j++];
        else ans += even[k++];
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