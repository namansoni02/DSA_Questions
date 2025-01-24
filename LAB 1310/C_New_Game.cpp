//NAMAN SONI CP TEMPLATE
#include <bits/stdc++.h>
using namespace std;

#define CODE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

// Function to read card values
void readCards(vector<int>& cards, int n) {
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }
}

// Function to compute the maximum number of cards Monocarp can take
int computeMaxCards(const vector<int>& cards, int k) {
    unordered_map<int, int> freq;
    int maxCards = 0, distinct = 0, left = 0;

    for (int right = 0; right < cards.size(); right++) {
        if (freq[cards[right]] == 0) {
            distinct++;
        }
        freq[cards[right]]++;

        // Adjust the left pointer to maintain at most k distinct numbers
        while (distinct > k) {
            freq[cards[left]]--;
            if (freq[cards[left]] == 0) {
                distinct--;
            }
            left++;
        }

        // Check if the current card can be part of the sequence
        if (right == 0 || (cards[right] == cards[right - 1] || cards[right] == cards[right - 1] + 1)) {
            maxCards = max(maxCards, right - left + 1);
        }
    }

    return maxCards;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> cards(n);
        readCards(cards, n);  // Read card values
        sort(cards.begin(), cards.end());  // Sort the cards
        
        int maxCards = computeMaxCards(cards, k);  // Compute max cards
        cout << maxCards << endl;  // Output the result
    }

    return 0;
}
