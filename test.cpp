#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> appan = {1,2,3,4,5};
    reverse(appan.begin(), appan.end());
    for (int i = 0; i < appan.size(); i++) {
        cout << appan[i] << " ";
    }
    cout << endl;
    return 0;
}