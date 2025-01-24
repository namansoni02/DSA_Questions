#include <bits/stdc++.h>

using namespace std;

class Solution{
public:

    //Function to eliminate the player
    int pop_player(int index, int move_count, vector<int> &player_status){
        //Declaring varibles to traverse and maintain the 
        int current_index = 0, i = 0, count = move_count;
        int size = player_status.size();
        
        //Traversing while we dont move move_count valid steps (Elminated player is not counted)
        while(count >= 0){
            current_index = (index + i) % size;
            if(player_status[current_index] == -1){  // Skip eliminated player_status
                count++;
            }
            i++; 
            count--;
        }
        //Eliminating the person
        current_index = (index + i - 1) % size;  
        player_status[current_index] = -1;    //Updating the eliminated player status
        cout<<current_index+1<<endl;          //Printing the player eliminated
 
        current_index++;   //Now finding the next active player
        while(player_status[current_index % size] == -1){
            current_index++;
        }
        //Returning the index of the next active player
        return current_index % size;  
    }

    void RollingDice(int n, vector<int> diceRolls){
        //Decalring variablles to store the current player index and the count of remaining players
        int index = 0, active_players = n;  

        //Declaring an array to check  the status of the player
        // 0 for active && -1 for eliminated
        vector<int> players(n, 0); 

        //Traversing the diceRolls
        for(auto i : diceRolls){
            int pop_count = i%active_players ;   //Calculating after how many index we have to eliminate
            cout<< i << " ";                     // Prinitng the diceRoll value
            int next_index = pop_player(index, pop_count, players); 
            index = next_index;                  //Updating the index of next active player after each elimination
            active_players--;                    //Updating the active players count
        }

        //Prining the WINNER !!
        cout <<index + 1 << endl;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> diceRolls(n - 1);  // We have n-1 dice rolls

    // Input dice rolls
    for (int i = 0; i < n - 1; i++) {
        cin >> diceRolls[i];
    }

    Solution s;
    s.RollingDice(n, diceRolls);

    return 0;
}
