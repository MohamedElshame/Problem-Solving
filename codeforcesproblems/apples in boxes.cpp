#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Compute required statistics
        ll min_a = *min_element(a.begin(), a.end());
        ll max_a = *max_element(a.begin(), a.end());
        ll sum_a = accumulate(a.begin(), a.end(), 0LL);
        int p = count(a.begin(), a.end(), max_a);

        // Check if there's at least one legal move
        bool has_legal_move = (max_a - min_a <= k) || (p == 1 && max_a - min_a <= k + 1);

        if (has_legal_move) {
            // If legal move exists, winner depends on parity of total moves (sum_a)
            if (sum_a % 2 == 1) {
                cout << "Tom\n";
            } else {
                cout << "Jerry\n";
            }
        } else {
            // No legal move, Tom loses immediately
            cout << "Jerry\n";
        }
    }

    return 0;
}