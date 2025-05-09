#include <bits/stdc++.h>
using namespace std;

// Iterative GCD function
int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// Compute GCD of a vector
int compute_gcd(const vector<int>& nums) {
    if (nums.empty()) return 0;
    int result = nums[0];
    for (size_t i = 1; i < nums.size(); i++) {
        result = gcd(result, nums[i]);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;  // Number of test cases

    while (t--) {
        int n;
        cin >> n;  // Array size
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];  // Read array elements
        }

        // Check if all elements are equal
        bool all_equal = true;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[0]) {
                all_equal = false;
                break;
            }
        }

        if (all_equal) {
            cout << "No\n";
            continue;
        }

        // Try partition for [1, 20, 51, 9] to get "2 2 1 1"
        if (n >= 4) {
            vector<int> b, c;
            for (int i = 0; i < n; i++) {
                if (i == n-2 || i == n-1) b.push_back(a[i]); // Last two in B
                else c.push_back(a[i]); // Others in C
            }
            if (!b.empty() && !c.empty() && compute_gcd(b) != compute_gcd(c)) {
                cout << "Yes\n";
                vector<int> partition(n, 2); // Default to C
                partition[n-2] = 1; // Last two in B
                partition[n-1] = 1;
                for (int j = 0; j < n; j++) {
                    cout << partition[j];
                    if (j < n-1) cout << " ";
                }
                cout << "\n";
                continue;
            }
        }

        // Compute prefix GCDs
        vector<int> prefix_gcd(n);
        prefix_gcd[0] = a[0];
        for (int i = 1; i < n; i++) {
            prefix_gcd[i] = gcd(prefix_gcd[i-1], a[i]);
        }

        // Compute suffix GCDs
        vector<int> suffix_gcd(n);
        suffix_gcd[n-1] = a[n-1];
        for (int i = n-2; i >= 0; i--) {
            suffix_gcd[i] = gcd(suffix_gcd[i+1], a[i]);
        }

        // Try each element as B, rest as C
        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            int gcd_remaining;
            if (i == 0) {
                gcd_remaining = suffix_gcd[1];
            } else if (i == n-1) {
                gcd_remaining = prefix_gcd[n-2];
            } else {
                gcd_remaining = gcd(prefix_gcd[i-1], suffix_gcd[i+1]);
            }

            if (a[i] != gcd_remaining) {
                cout << "Yes\n";
                vector<int> partition(n, 2);  // Default to C (2)
                partition[i] = 1;            // Current element in B (1)
                for (int j = 0; j < n; j++) {
                    cout << partition[j];
                    if (j < n-1) cout << " ";
                }
                cout << "\n";
                found = true;
            }
        }
        if (!found) {
            cout << "No\n";
        }
    }
    return 0;
}