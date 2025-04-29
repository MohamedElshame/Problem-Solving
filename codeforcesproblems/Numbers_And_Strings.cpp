#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

// Function to generate the sorted digit string (kept for reference, but not needed for the final calculation)
string generate_string(long long x) {
    long long next = x + 1;
    string x_str = to_string(x);
    string next_str = to_string(next);
    string combined = x_str + next_str;
    sort(combined.begin(), combined.end());
    return combined;
}

// The complex map and precomputation are no longer needed with the direct formula.

long long solve() {
    long long n;
    cin >> n;
    // The number of distinct strings is n minus the count of multiples of 10 up to n.
    return n - n / 10;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }
    return 0;
}