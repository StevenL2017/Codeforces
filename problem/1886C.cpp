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
    string s; cin >> s;
    ll pos; cin >> pos;

    int n = ssz(s), cnt = 0;
    for (int i = n; i > 0; i--) {
        if (pos <= i) break;
        pos -= i;
        cnt++;
    }

    vi st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && s[st.back()] > s[i] && cnt) {
            st.pop_back();
            cnt--;
        }
        st.push_back(i);
    }

    cout << s[st[pos - 1]];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}