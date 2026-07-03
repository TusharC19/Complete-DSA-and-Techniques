# include<bits/stdc++.h>
using namespace std; 

// Comparator function: sorts in descending order
bool compareDescending(int a, int b) {
    return a > b;  // return true if a should come before b
}

int main() {
    vector<int> numbers = {5, 2, 8, 1, 3};

    // Sort using comparator function
    sort(numbers.begin(), numbers.end(), compareDescending);

    // Print sorted result
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}