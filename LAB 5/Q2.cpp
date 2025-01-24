#include <iostream>
#include <vector>
using namespace std;

class ArrayProcessor {
private:
    int *arr; // Vector to hold the array elements
    int n;           // Number of elements in the array
    const int MAX_ITERATIONS = 20; // Maximum number of iterations

public:
    // Constructor to initialize the array size and elements
    ArrayProcessor(int size) {
        n = size;
        arr = new int[n];    
    }

    // Function to input the elements of the array from the user
    void inputArray() {
        //cout<<n<<endl;
        for(int i=0;i<n;i++){
           int k;cin>>k;
           arr[i]=k;
        }
    }

    // Function to print reversed or original groups of 3 elements
    void printReversedGroups() {
        // for(int i=0;i<n;i++){
        //     cout<<arr[i]<<" ";
        // }
        if(n==0)return;
        if(n==1){
            for(int i=0;i<20;i++)cout<<arr[0]<<" ";
            return;
        }
        if(n==2){
            for(int i=0;i<20;i++)cout<<arr[1]<<" "<<arr[0]<<"";
            return;
        }
        int index=0,count=0;
        while(count<=MAX_ITERATIONS){
            int a=(index+2)%n;
            int b=(index+1)%n;
            int c=(index)%n;
            if(a==0 || b==0 || c==0 )count++;
            cout<<arr[a]<<" "<<arr[b]<<" "<<arr[c]<<" ";
            index+=3;
        }
    }
};

int main() {
    int n;

    // Ask the user for the number of elements in the array

    cin >> n;

    // Create an instance of ArrayProcessor
    ArrayProcessor processor(n);

    // Input the array elements
    processor.inputArray();

    // Print the reversed groups
    processor.printReversedGroups();

    return 0;
}