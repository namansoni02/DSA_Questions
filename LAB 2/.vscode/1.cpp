#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

typedef struct node{
    int id; node* next;

    node(int ai){
        id = ai; next = NULL;
    }
} node;

class LinkedList{
public:
    node* head; node* last;

    LinkedList(node* h){
        head = h;
        last = h;
    }

    void insert(node* ln){
        last->next = ln;
        last = last->next;
    }

    void DisplayList(){
        for(node* c=head;c;c=c->next) cout << c->id << ' ';
        cout << '\n';
    }

    bool find(node* n) const{
        for(node* c=head;c;c=c->next)
            if(c==n) return true;
        return false;
    }
};


void printHitForkApart(const vector<LinkedList>& L) {
   
}

int main(){
    int n; cin >> n;

    vector<LinkedList> LL;
    map<int,node*> mp;

    for(int i=0;i<n;i++){
        int m; cin >> m;
        int hid; cin >> hid; m--;
 
        if(mp.find(hid)==mp.end()) mp[hid] = new node(hid);
            LL.push_back(LinkedList(mp[hid]));
    
        while(m--){
            int ai; cin >> ai;
            if(mp.find(ai)==mp.end()) mp[ai] = new node(ai);
            LL[i].insert(mp[ai]);
        }
    }

    printHitForkApart(LL);
    return 0;
}