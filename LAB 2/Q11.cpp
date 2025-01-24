// 7. This is new year and there is a special game being played at IITJ.                		
// These are the ways how the game is played. 
// 1) There are say  ‘x’ students in the class. Each student is labeled from 1 (first student) to x (last student).
// 2) A paper is given to n-th student.
// 3) The next p-th student who gets the paper quits the game.
// 4) The paper is passed until there is one last student who hasn't left the game.
// 5) The student becomes the class leader.
// Now, your task is to find the number of last student.

// Input
// The first line contains a number T (0 <= T <= 106).
// Each of the next T lines contains 3 integers which are x (0 < x<= 103), n, p (0 < n, p <= x) and are separated by a single space.

// Output
// For each test case, print the required answer.


#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int v = 0, Node* n = nullptr) {
        data = v;
        next = n;
    }
};

class Game {
private:
    int x; // Number of students
    int n; // Initial student who gets the paper
    int p; // Steps to pass the paper

public:

    Game(int x, int n, int p) : x(x), n(n), p(p) {}

    int findwinner() {
        if(x==0)return 0;
        if(x==1)return 1;

        int n=1;
        int count=x;
        bool check=true;

        Node*head=new Node(1);
        Node*temp=head;
        for(int i=1;i<x;i++){
            temp->next=new Node(i+1);
            temp=temp->next;
        }
        temp->next=head;
        temp=head;
        // for(int i=0;i<x;i++){
        //     cout<<temp->data<<" ";
        //     temp=temp->next;
        // }
        //cout<<endl;

        Node* universal=head;

        for(int i=0;i<n;i++){
            head=head->next;
        }
        Node*prev=nullptr;
        temp=head;

        while(prev!=head){
            if(check){
                for(int i=0;i<p;i++){
                    prev=head;
                    head=head->next;
                }
                prev->next=head->next;
                head=head->next;
                count--;
            }
            else{
                for(int i=0;i<p-1;i++){
                    prev=head;
                    head=head->next;
                }
                prev->next=head->next;
                head=head->next;
                count--;
            }
            temp=universal;
            cout<<"step:: "<<x-count<<"->>";
            for(int i=0;i<count;i++){
            cout<<" "<<temp->data<<" ";
            temp=temp->next;
            }
            cout<<endl;
        }
        cout<<temp->data<<endl;
        return head->data;

    }

};

int main() {
    int T;
    cin >> T; 

    while (T--) {
        int x, n, p;
        cin >> x >> n >> p;
        Game s(x,n,p);
        s.findwinner();
    }

    return 0;
}