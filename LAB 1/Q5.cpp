    #include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    void solve(vector<int> &A,vector<int> &B){
    set<int> setA(A.begin(), A.end());
    set<int> setB(B.begin(), B.end());

    set<int> result;

    for (int num : setA) {
        if (setB.find(num) == setB.end()) {
            result.insert(num);
        }
    }

    for (int num : setB) {
        if (setA.find(num) == setA.end()) {
            result.insert(num);
        }
    }

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    }
};

int main() {
    int size1;
    cin >> size1;
    int size2 = size1;
    vector<int> A(size1);
    vector<int> B(size2);
    
    for (int i = 0; i < size1; i++) cin >> A[i];
    for (int i = 0; i < size2; i++) cin >> B[i];
    
    solution s;
    s.solve(A,B);
    

    return 0;
}