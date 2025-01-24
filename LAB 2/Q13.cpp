
#include<iostream>
#include<vector>
#include <algorithm>
#include<map>
using namespace std;


class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int v = 0, Node* p = nullptr, Node* n = nullptr) {
        data = v;
        prev = p;
        next = n;
    }
};

struct sort_pred {
    bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return left.second < right.second;
    }
};


class DoubleLinkedList {
public:
    Node* head;
    DoubleLinkedList(Node* h = nullptr) {
        head = h;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->prev = curr;
    }

    void printLinkedList() {
        if (head == nullptr) {
            cout<< "\n";
            return;
        }

        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << ' ';
            curr = curr->next;
        }
        cout << "\n";
    }

    


};


DoubleLinkedList concatenate(DoubleLinkedList& old,DoubleLinkedList& other) {
    Node*temp=old.head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=other.head;
    return old;
}


DoubleLinkedList sortedConcatenate(DoubleLinkedList& l1, DoubleLinkedList& l2) {
    Node *temp1=l1.head,*temp2=l2.head;
    if(temp1==nullptr){
        return l2;
    }
    while(temp1->next!=nullptr){
        if(temp2==nullptr){
            return l1;
        }
        if(temp1->data>temp2->data){
            Node*newnode=temp2;
            temp2=temp2->next;
            newnode->next=temp1;
            temp1->prev=newnode;
            temp1=newnode;
            l1.head=newnode;
        }
        else if(temp1->data <=temp2->data && temp1->next->data>=temp2->data){
            Node*newnode=temp2;
            temp2=temp2->next;
            Node *forward=temp1->next;
            temp1->next=newnode;
            newnode->next=forward;
            forward->prev=newnode;
            newnode->prev=temp1;
        }
        temp1=temp1->next;
    }
    if(temp1->next==nullptr && temp2!=nullptr){
            temp1->next=temp2;
            temp2->prev=temp1;      
    }
    return l1;
}


DoubleLinkedList insertSorted(DoubleLinkedList& l, int val) {
    Node*temp=l.head;
    Node *newnode=new Node(val);
    if(temp->data>val){
        newnode->next=temp;
        temp->prev=newnode;
        l.head=newnode;
        return l;
    }
    while(temp->next!=nullptr){
        if(temp->data <=val && temp->next->data>=val){
            Node *forward=temp->next;
            temp->next=newnode;
            newnode->next=forward;
            forward->prev=newnode;
            newnode->prev=temp;
            return l;
        }
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    return l;
}

int secondHighest(DoubleLinkedList& l) {
    Node *temp1=l.head;
    if(temp1->next==nullptr){
        return temp1->data;
    }
    int max=-1,second_max=-1;
    while(temp1!=nullptr){
        if(temp1->data>max){
            second_max=max;
            max=temp1->data;
        }
        else{
            if(temp1->data>second_max){
                second_max=temp1->data;
            }
        }
        temp1=temp1->next;
    }
    return second_max;
}



void pairSumGreaterThanX(DoubleLinkedList& l, int x) {
    if (l.head == nullptr || l.head->next == nullptr) {
        cout << "-1";
        return;
    }

    Node* temp1 = l.head;
    int count = 0;
    vector<pair<int, int>> ans;
    map<pair<int, int>, bool> checkit;  

    while (temp1 != nullptr && temp1->next != nullptr) {
        Node* temp2 = temp1->next;
        while (temp2 != nullptr) {
            if ((temp1->data) + (temp2->data) > x) {
                pair<int, int> a = {temp1->data, temp2->data};
                //pair<int, int> b = {temp2->data, temp1->data};
                if (checkit[a] == false) {
                    ans.push_back(a);
                    checkit[a] = true;
                    count++;
                }
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    for(auto i:ans){
        int x=i.first;
        int y=i.second;
        pair<int,int> p=make_pair(y,x);
        if(checkit[p]==false){
            ans.push_back(p);
        }

    }
    sort(ans.begin(), ans.end());
    if (count == 0) {
        cout << "-1";
    } else {
        for (const auto& i : ans) {
            cout << i.first << " " << i.second<<" "<< endl;
        }
    }
}
int main(){

    int queryType;
    cin>>queryType;
    if(queryType==1){
        int n,m;
        cin>>n>>m;
        DoubleLinkedList list1;
        DoubleLinkedList list2;
        int x;
        while (n--)
        {
            cin>>x;
            list1.insert(x);
        }
        while (m--)
        {
            cin>>x;
            list2.insert(x);
        }
        concatenate(list1,list2).printLinkedList();
        
    }

    else if (queryType==2)
    {
        int n,m;
        cin>>n>>m;
        DoubleLinkedList list1;
        DoubleLinkedList list2;
        int x;
        while (n--)
        {
            cin>>x;
            list1.insert(x);
        }
        while (m--)
        {
            cin>>x;
            list2.insert(x);
        }
        sortedConcatenate(list1,list2).printLinkedList();
    }
    else if (queryType==3)
    {
        int n;
        cin>>n;
        int x;
        DoubleLinkedList list1;
        while (n--)
        {
            cin>>x;
            list1.insert(x);
        }
        int k;
        cin>>k;
        insertSorted(list1,k).printLinkedList();
    }
    
    else if (queryType==4)
    {
        int n;
        cin>>n;
        DoubleLinkedList list1;
        int x;
        while (n--)
        {
            cin>>x;
            list1.insert(x);
        }
        cout << secondHighest(list1) << endl;
        
    }
    else if (queryType==5)
    {
        int n,k;
        cin>>n>>k;
        DoubleLinkedList list1;
        int x;
        while (n--)
        {
            cin>>x;
            list1.insert(x);
        }
        pairSumGreaterThanX(list1,k);
    }
    
    
    

    return 0;
}