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

int nC2(int n) {
    return (n * (n - 1)) / 2;
}

void printHitForkApart(const vector<LinkedList>& L) {
    int n = L.size();
    if (n == 0) {
        return;
    }
    
    int a = 0, b = 0, c = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool ij = false;
            bool ji = false;
            bool check_fork = false;
            
            node* temp = L[i].head->next;
            while (temp != nullptr) {
                if (temp == L[j].head) {
                    ij = true;
                    break;
                }
                temp = temp->next;
            }
            
            temp = L[j].head->next;
            while (temp != nullptr) {
                if (temp == L[i].head) {
                    ji = true;
                    break;
                }
                temp = temp->next;
            }
            
            if (!ij && !ji) {
                temp = L[i].head->next;
                while (temp != nullptr && !check_fork) {
                    if (L[j].find(temp)) {
                        check_fork = true;
                    }
                    temp = temp->next;
                }
            }
            
            if (ij || ji) {
                a++;
            } else if (check_fork) {
                b++;
            } else {
                c++;
            }
        }
    }
    
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
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