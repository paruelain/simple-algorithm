#include <bits/stdc++.h>
using namespace std;

map<int, vector<vector<int>>> mp;
int N, W;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> W;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end(), greater<>());
    for (int i : v) {
        auto it = mp.lower_bound(i);
        if (it == mp.end()) {
            mp[W - i].push_back(vector<int>{i});
            continue;
        }
        (it -> second).back().push_back(i);
        mp[it -> first - i].push_back((it -> second).back());
        (it -> second).pop_back();
        if ((it -> second).size() == 0) {
            mp.erase(it);
        }
    }
    int total = 0, cnt = 0;
    for (auto &p : mp) {
        total += p.second.size();
    }
    cout << "total: " << total << " of " << W << '\n';
    for (auto &p : mp) {
        for (auto &v: p.second) {
            cout << "num: " << cnt ++ << '\n';
            for (int &i : v) {
                cout << i << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}

