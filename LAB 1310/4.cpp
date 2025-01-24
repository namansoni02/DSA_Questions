#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Competition {
public:
    void solveTestCases() {
        ll n;
        cin >> n;
        vector<ll> challenges(n);
        vector<ll> stamina(n);
        
        for (int i = 0; i < n; i++) {
            cin >> challenges[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> stamina[i];
        }
        
        cout << calculateMaxDays(n, challenges, stamina) << endl;
    }

private:
    ll calculateMaxDays(ll n, vector<ll>& challenges, vector<ll>& stamina) {
        vector<pair<ll, ll>> friends(n);
        for (int i = 0; i < n; i++) {
            friends[i] = {challenges[i], stamina[i]};
        }
        
        sort(friends.begin(), friends.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b) {
            return a.second < b.second;
        });

        int days = 0;
        int i = 0, j = n - 1;

        while (i < j) {
            ll totalChallenges = friends[i].first + friends[j].first;
            ll totalStamina = friends[i].second + friends[j].second;
            
            if (totalStamina >= totalChallenges) {
                days++;
                i++;
                j--;
            } else {
                i++;
            }
        }
        
        return days;
    }
};

int main() {
    Competition competition;
    competition.solveTestCases();
    return 0;
}
