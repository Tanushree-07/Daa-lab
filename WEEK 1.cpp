LINEAR SEARCH
#include <iostream>
using namespace std;

int main() {
    int n, key, comp = 0;

    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> key;

    bool found = false;

    for(int i = 0; i < n; i++) {
        comp++;

        if(arr[i] == key) {
            found = true;
            break;
        }
    }

    if(found)
        cout << "Present " << comp;
    else
        cout << "Not Present " << comp;

    return 0;
}
BINARY SEARCH
#include <iostream>
using namespace std;

int main() {

    int n, key;

    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> key;

    int low = 0;
    int high = n - 1;

    int comp = 0;

    bool found = false;

    while(low <= high) {

        int mid = (low + high) / 2;

        comp++;

        if(arr[mid] == key) {
            found = true;
            break;
        }

        else if(arr[mid] < key) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    if(found)
        cout << "Present " << comp;
    else
        cout << "Not Present " << comp;

    return 0;
}
JUMP SEARCH
#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int n, key;

    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> key;

    int step = sqrt(n);
    int prev = 0;

    int comp = 0;

    while(arr[min(step, n) - 1] < key) {

        comp++;

        prev = step;
        step += sqrt(n);

        if(prev >= n) {
            cout << "Not Present " << comp;
            return 0;
        }
    }

    while(arr[prev] < key) {

        comp++;

        prev++;

        if(prev == min(step, n)) {
            cout << "Not Present " << comp;
            return 0;
        }
    }

    comp++;

    if(arr[prev] == key)
        cout << "Present " << comp;
    else
        cout << "Not Present " << comp;

    return 0;
}