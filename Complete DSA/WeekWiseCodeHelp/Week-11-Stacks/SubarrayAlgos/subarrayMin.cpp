// CPP implementation of above approach
#include <bits/stdc++.h>
using namespace std;

// Function to return required minimum sum
int sumSubarrayMins(int A[], int n)
{
	// To store answer
	int ans = 0;
	for (int i = 0; i < n; i++) {
		// To store minimum element
		int min_ele = A[i];
		for (int j = i; j < n; j++) {
			// Finding minimum element of subarray
			min_ele = min(min_ele, A[j]);
			// Adding that minimum element of subarray in
			// answer
			ans += min_ele;
		}
	}
	return ans;
}

// Driver program
int main()
{
	int A[] = { 3, 1, 2, 4 };
	int n = sizeof(A) / sizeof(A[0]);
	// function call to get required result
	cout << sumSubarrayMins(A, n);

	return 0;
}
