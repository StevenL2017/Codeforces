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

    vector<pair<int, int>> ans;
    string s = to_string(n);
    for (int a = 1; a <= 10000; a++) {
        int l = a * ssz(s);
        string t;
        while (ssz(t) <= 6) {
            t += s;
        }
        for (int b = max(1, l - 6); b <= min(l - 1, 10000); b++) {
            int x = n * a - b;
            if (to_string(x) == t.substr(0, l - b)) {
                ans.emplace_back(a, b);
            }
        }
    }

    cout << ssz(ans) << endl;
    for (auto [a, b]: ans) {
        cout << a << " " << b << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}