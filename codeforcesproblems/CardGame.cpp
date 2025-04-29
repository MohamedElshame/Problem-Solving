#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <limits> // مطلوبة عشان numeric_limits

using namespace std;
// بنشوف لو كارت a بيكسب كارت b
bool does_a_beat_b(int card_a, int card_b, int n) {
    if (card_a == 1 && card_b == n) return true;  // قاعدة: 1 بيكسب n
    if (card_b == 1 && card_a == n) return false; // قاعدة: 1 بيكسب n (بوب كسب)
    return card_a > card_b; // القاعدة العادية: الكارت الأعلى بيكسب
}

string solveGame(int n, const string& distribution) {
    multiset<int> aliceCards, bobCards;

    // بنوزع الكروت في الأول
    for (int i = 0; i < n; ++i) {
        if (distribution[i] == 'A') {
            aliceCards.insert(i + 1);
        } else {
            bobCards.insert(i + 1);
        }
    }

    bool alice_can_force_win_on_first_turn = false;

    // بنشوف كل كارت ممكن أليس تلعبه
    for (int aliceCard : aliceCards) {
        // بنحدد أفضل رد لبوب على كارت أليس
        int bobResponse = -1;
        int lowest_winning_card = numeric_limits<int>::max();
        bool bob_can_win = false;

        for (int b_card : bobCards) {
            // بنشوف لو كارت بوب b_card بيكسب كارت أليس aliceCard
            if (does_a_beat_b(b_card, aliceCard, n)) {
                 bob_can_win = true;
                 lowest_winning_card = min(lowest_winning_card, b_card);
            }
        }

        if (bob_can_win) {
            // بوب بيلعب أقل كارت عنده بيكسب
            bobResponse = lowest_winning_card;
        } else {
            // بوب مش هيقدر يكسب، فهيلعب أقل كارت عنده عشان يقلل الخسارة
            bobResponse = *bobCards.begin();
        }

        // بنشوف لو أليس كسبت الدور ضد أفضل رد لبوب
        if (does_a_beat_b(aliceCard, bobResponse, n)) {
            alice_can_force_win_on_first_turn = true;
            break; // لقينا حركة تخلي أليس تكسب
        }
    }

    return alice_can_force_win_on_first_turn ? "Alice" : "Bob";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);                   

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string distribution;
        cin >> distribution;

        cout << solveGame(n, distribution) << "\n"; 
    }

    return 0;
}