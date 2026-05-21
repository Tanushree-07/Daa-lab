MERGE SORT 
#include <iostream>
using namespace std;

int comparisons = 0;
int inversions = 0;

void merge(int arr[], int low, int mid, int high) {

    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[low + i];

    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;

    while(i < n1 && j < n2) {

        comparisons++;

        if(L[i] <= R[j]) {
            arr[k++] = L[i++];
        }

        else {

            arr[k++] = R[j++];

            inversions += (n1 - i);
        }
    }

    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int low, int high) {

    if(low < high) {

        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);

        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main() {

    int n;

    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr, 0, n - 1);

    cout << "Sorted Array:\n";

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\ncomparisons = " << comparisons;

    cout << "\ninversions = " << inversions;

    return 0;
}

QUICK SORT
#include <iostream>
using namespace std;

int comparisons = 0;
int swaps = 0;

int partition(int arr[], int low, int high) {

    int pivot = arr[high];

    int i = low - 1;

    for(int j = low; j < high; j++) {

        comparisons++;

        if(arr[j] < pivot) {

            i++;

            swap(arr[i], arr[j]);

            swaps++;
        }
    }

    swap(arr[i + 1], arr[high]);

    swaps++;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {

    if(low < high) {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);

        quickSort(arr, pi + 1, high);
    }
}

int main() {

    int n;

    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n - 1);

    cout << "Sorted Array:\n";

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\ncomparisons = " << comparisons;

    cout << "\nswaps = " << swaps;

    return 0;
}
KTH SMALLEST ELEMENT 

#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n;

    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cin >> k;

    sort(arr, arr + n);

    if(k > 0 && k <= n)
        cout << arr[k - 1];

    else
        cout << "not present";

    return 0;
}