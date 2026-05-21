INSERTI0N SORT

#include <iostream>
using namespace std;

int main() {

    int n;

    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int comparisons = 0;
    int shifts = 0;

    for(int i = 1; i < n; i++) {

        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {

            comparisons++;

            arr[j + 1] = arr[j];

            shifts++;

            j--;
        }

        if(j >= 0)
            comparisons++;

        arr[j + 1] = key;
    }

    cout << "Sorted Array:\n";

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\ncomparisons = " << comparisons;
    cout << "\nshifts = " << shifts;

    return 0;
}

SELECTION SORT
#include <iostream>
using namespace std;

int main() {

    int n;

    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int comparisons = 0;
    int swaps = 0;

    for(int i = 0; i < n - 1; i++) {

        int minIndex = i;

        for(int j = i + 1; j < n; j++) {

            comparisons++;

            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if(minIndex != i) {

            swap(arr[i], arr[minIndex]);

            swaps++;
        }
    }

    cout << "Sorted Array:\n";

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\ncomparisons = " << comparisons;
    cout << "\nswaps = " << swaps;

    return 0;
}

Find Duplicate Elements using Sorting
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n;

    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    bool duplicate = false;

    for(int i = 1; i < n; i++) {

        if(arr[i] == arr[i - 1]) {

            duplicate = true;
            break;
        }
    }

    if(duplicate)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}