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
    
    int mx = 0, cnt = 1, pre = 0;
    vi st(1, pre);
    map<int, int> mp;
    for (int x = -ssz(s); x <= ssz(s); x++) {
        mp[x] = -2;
    }
    mp[pre] = -1;
    for (int i = 0; i < ssz(s); i++) {
        if (s[i] == '(') pre++;
        else pre--;
        while (!st.empty() && st.back() > pre) {
            mp[st.back()] = -2;
            st.pop_back();
        }
        if (mp[pre] != -2) {
            int len = i - mp[pre];
            if (len > mx) {
                mx = len;
                cnt = 1;
            }
            else if (len == mx) {
                cnt++;
            }
        } else {
            mp[pre] = i;
        }
        st.push_back(pre);
    }

    cout << mx << " " << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}