#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Competition {
public:
    void executeTestCases() {
        ll numFriends;
        cin >> numFriends; 
        vector<ll> challengeCounts(numFriends);
        vector<ll> staminaLevels(numFriends);
        
        for (int i = 0; i < numFriends; ++i) {
            cin >> challengeCounts[i];
        }
        for (int i = 0; i < numFriends; ++i) {
            cin >> staminaLevels[i];
        }
        
        cout << determineMaxDays(numFriends, challengeCounts, staminaLevels) << endl;
    }

private:
    ll determineMaxDays(ll numFriends, vector<ll>& challengeCounts, vector<ll>& staminaLevels) {
        vector<ll> netStamina(numFriends);
        
        for (ll i = 0; i < numFriends; ++i) {
            netStamina[i] = staminaLevels[idx] - challengeCounts[idx];
        }

        sort(netStamina.begin(), netStamina.end());

        ll maxDays = 0;
        ll left = 0, right = numFriends - 1;

        while (left < right) {
            if (netStamina[left] + netStamina[right] >= 0) {
                maxDays++;
                right--;
            }
            left++;
        }

        return maxDays;
    }
};

int main() {
    Competition competition;
    competition.executeTestCases();
    return 0;
}
