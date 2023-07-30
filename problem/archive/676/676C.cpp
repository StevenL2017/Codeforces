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

    auto calc = [&] (char b, int k) -> int {
        int ans = 0, cnt = 0;
        for (int i = 0, j = 0; i < n; i++) {
            if (s[i] == b) cnt++;
            while (j <= i && cnt > k) {
                if (s[j] == b) cnt--;
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    };

    cout << max(calc('a', k), calc('b', k)) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}