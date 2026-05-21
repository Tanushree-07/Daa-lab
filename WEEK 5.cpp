Maximum Occurring Alphabet

#include <iostream>
using namespace std;

int main() {

    int n;

    cin >> n;

    char arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int freq[26] = {0};

    for(int i = 0; i < n; i++) {

        freq[arr[i] - 'a']++;
    }

    int maxFreq = 0;

    char ans;

    for(int i = 0; i < 26; i++) {

        if(freq[i] > maxFreq) {

            maxFreq = freq[i];

            ans = char(i + 'a');
        }
    }

    if(maxFreq == 1)
        cout << "No Duplicates Present";

    else
        cout << ans << "-" << maxFreq;

    return 0;
}

Two Elements with Given Sum
Problem
Find two elements such that:
arr[i]+arr[j]=key

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

    int key;

    cin >> key;

    sort(arr, arr + n);

    int i = 0;
    int j = n - 1;

    bool found = false;

    while(i < j) {

        int sum = arr[i] + arr[j];

        if(sum == key) {

            cout << arr[i] << " " << arr[j];

            found = true;

            break;
        }

        else if(sum < key)
            i++;

        else
            j--;
    }

    if(!found)
        cout << "No Such Element Exist";

    return 0;
}

Common Elements in Two Sorted Arrays
#include <iostream>
using namespace std;

int main() {

    int m, n;

    cin >> m;

    int a[m];

    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }

    cin >> n;

    int b[n];

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int i = 0;
    int j = 0;

    while(i < m && j < n) {

        if(a[i] == b[j]) {

            cout << a[i] << " ";

            i++;
            j++;
        }

        else if(a[i] < b[j]) {

            i++;
        }

        else {

            j++;
        }
    }

    return 0;
}
