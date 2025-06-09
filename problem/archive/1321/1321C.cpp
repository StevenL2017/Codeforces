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
    string s;
    cin >> s;

    vi a(n);
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - 'a';
    }
    for (int c = 25; c > 0; c--) {
        vi st;
        for (int i = 0; i < ssz(a); i++) {
            if (a[i] == c && !st.empty() && st.back() == c - 1) {
                continue;
            }
            while (!st.empty() && st.back() == c && a[i] == c - 1) {
                st.pop_back();
            }
            st.push_back(a[i]);
        }
        a = st;
    }
    cout << n - ssz(a) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}