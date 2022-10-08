#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<int, int> ii;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _  %  MOD
#define __ %= MOD

#define pq(T)                  priority_queue<T, vector<T>>
#define rpq(T)                 priority_queue<T, vector<T>, greater<T>>

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v)               sort(v.rbegin(), v.rend())

#define rep(i, n)              for(int i = 0; i < n; ++i)
#define repA(i, a, n)          for(int i = a; i < n; ++i)
#define repD(i, a, n)          for(int i = a; i > n; --i)
#define loop(i, start, end)    for(auto i = start; (start<end)?i<end:i>end; (start<end)?i++:i--)

void solve() {
    int n, k;
    cin >> n >> k;
    vi nums(n);
    for (auto& x: nums) cin >> x;

    int left = 0;
    int cnt = 0;
    repA(i, 1, k - 1) {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
            cnt++;
        }
    }

    int ans = left;
    int mc = cnt;
    repA(i, k - 1, n - 1) {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
            cnt++;
        }
        if (nums[left + 1] > nums[left] && nums[left + 1] > nums[left + 2]) {
            cnt--;
        }
        left++;
        if (cnt > mc) {
            mc = cnt;
            ans = left;
        }
    }
    cout << mc + 1 << " " << ans + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}