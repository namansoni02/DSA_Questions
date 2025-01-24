#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

class VolumeCalculator {
private:
    float get_vol(float r, float h) {
        const float pi = 3.14f;  
        return pi * r * r * h;
    }

public:
    void volume_calculator(int n, int l, int u) {
        float diff = static_cast<float>(u - l) / (n - 1);
        vector<float> dimensions;
        dimensions.push_back(static_cast<float>(l));

        for (int i = 1; i < n; i++) {
            dimensions.push_back(l + (diff * i));
        }

        float maxVolume = 0.0f, minVolume = 1e9f, sumVolume = 0.0f;

        for (int i = 0; i < n; i += 2) {
            float volume = get_vol(dimensions[i], dimensions[i + 1]);
            cout << fixed << setprecision(2) << volume << " ";
            sumVolume += volume;
            if (volume > maxVolume) maxVolume = volume;
            if (volume < minVolume) minVolume = volume;
        }















        cout << endl << fixed << setprecision(2) << sumVolume << endl;
        cout << fixed << setprecision(2) << minVolume << endl;
        cout << fixed << setprecision(2) << maxVolume << endl;
    }
};

int main() {
    int n, l, u;
    cin >> n >> l >> u;

    VolumeCalculator vc;
    vc.volume_calculator(n, l, u);

    return 0;
}
