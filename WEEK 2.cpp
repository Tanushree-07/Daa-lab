Count Occurrences of Key using Binary Search
#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int key) {

    int low = 0;
    int high = n - 1;

    int ans = -1;

    while(low <= high) {

        int mid = (low + high) / 2;

        if(arr[mid] == key) {
            ans = mid;
            high = mid - 1;
        }

        else if(arr[mid] < key) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    return ans;
}

int lastOccurrence(int arr[], int n, int key) {

    int low = 0;
    int high = n - 1;

    int ans = -1;

    while(low <= high) {

        int mid = (low + high) / 2;

        if(arr[mid] == key) {
            ans = mid;
            low = mid + 1;
        }

        else if(arr[mid] < key) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {

    int n;

    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cin >> key;

    int first = firstOccurrence(arr, n, key);

    if(first == -1) {
        cout << "Key not present";
    }

    else {

        int last = lastOccurrence(arr, n, key);

        cout << key << "-" << last - first + 1;
    }

    return 0;
}


Find i, j, k such that
arr[i]+arr[j]=arr[k]
#include <iostream>
using namespace std;

int main() {

    int n;

    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool found = false;

    for(int k = 0; k < n; k++) {

        int i = 0;
        int j = n - 1;

        while(i < j) {

            if(i == k) {
                i++;
                continue;
            }

            if(j == k) {
                j--;
                continue;
            }

            int sum = arr[i] + arr[j];

            if(sum == arr[k]) {

                cout << i << "," << j << "," << k;

                found = true;
                break;
            }

            else if(sum < arr[k]) {
                i++;
            }

            else {
                j--;
            }
        }

        if(found)
            break;
    }

    if(!found)
        cout << "No sequence found";

    return 0;
}

Count Pairs with Difference K
Problem
Count pairs such that:
∣arr[i]−arr[j]∣=K

#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int n;

    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    int count = 0;

    for(int i = 0; i < n; i++) {

        for(int j = i + 1; j < n; j++) {

            if(abs(arr[i] - arr[j]) == k) {
                count++;
            }
        }
    }

    cout << count;

    return 0;
}