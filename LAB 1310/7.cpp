#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TriangleCounter {
private:
    long long n; // Number of sticks
    vector<long long> lengths; // Array to hold stick lengths

public:
    TriangleCounter(long long num, const vector<long long>& ar) : n(num), lengths(ar) {}

    // Function to solve the problem and count valid combinations
    void solve() {
        sort(lengths.begin(), lengths.end()); // Sort the lengths
        long long count = 0; // Count of valid triangles

        // Iterate through the lengths to find valid triangle combinations
        for (long long i = 0; i < n - 2; i++) {
            for (long long j = i + 1; j < n - 1; j++) {
                for (long long k = j + 1; k < n; k++) {
                    // Check triangle inequality
                    if (lengths[i] + lengths[j] > lengths[k]) {
                        count++; // Found a valid triangle
                    } else {
                        break; // No point in checking further as lengths are sorted
                    }
                }
            }
        }

        cout << count << endl; // Output the count
    }
};

int main() {
    long long n;
    cin >> n;
    vector<long long> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i]; 
    }
    TriangleCounter counter(n, ar); // Create an object of TriangleCounter
    counter.solve(); // Call the solve method
    return 0;
}
