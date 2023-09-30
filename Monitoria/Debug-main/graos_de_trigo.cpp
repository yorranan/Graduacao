#include <iostream>

using namespace std;

int main() {
    int graos = 1;
    int i = 0;
    cout << "casa " << i << ": " << graos << endl;
    while(i < 63) {
        graos =  graos * 2;
        cout << "casa " << i + 1 << ": " << graos << endl;
        i++;
    }
    return 0;
}