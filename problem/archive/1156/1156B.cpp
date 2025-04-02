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
    string s;
    cin >> s;
    vi cnt(26);
    for (auto c: s) {
        cnt[c - 'a']++;
    }

    string odd, even;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 0) {
            continue;
        }
        string cur(cnt[i], i + 'a');
        if (i & 1) {
            odd += cur;
        } else {
            even += cur;
        }
    }

    auto check = [&] (string s) -> bool {
        for (int i = 0; i < ssz(s) - 1; i++) {
            if (abs(s[i] - s[i + 1]) == 1) {
                return false;
            }
        }
        return true;
    };

    string ans = odd + even;
    if (check(ans)) {
        cout << ans << endl;
        return;
    }
    ans = even + odd;
    if (check(ans)) {
        cout << ans << endl;
        return;
    }
    cout << "No answer" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}