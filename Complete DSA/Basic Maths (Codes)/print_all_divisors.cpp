#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<int> better(int n) {
        
        // To store the divisors;
        vector<int> ans;
        
        int sqrtN = sqrt(n);
        
        // Iterate from 1 to sqrtN
        for(int i=1; i <= sqrtN; i++) {
            
            // If a divisor is found
            if(n % i == 0) {
                //Add it to the answer
                ans.push_back(i);
                
                /* Add the counterpart divisor
                 if it's different from i */
                if(i != n / i) {
                    ans.push_back(n/i);
                }
            }
        }
        
        // Sorting the result 
        sort(ans.begin(), ans.end());
        
        // Return the result
        return ans;
    }


    vector<int> optimal(int n) {
        // Stores smaller divisors in increasing order
        vector<int> smallDivisors;

        // Stores larger divisors in decreasing order
        vector<int> largeDivisors;

        // Iterate only till square root of n
        for (int i = 1; i * i <= n; i++) {
            // Check if i is a divisor of n
            if (n % i == 0) {
                smallDivisors.push_back(i);

                // Add counterpart divisor if it is different
                if (i != n / i) {
                    largeDivisors.push_back(n / i);
                }
            }
        }

        // Add larger divisors in reverse order
        for (int i = largeDivisors.size() - 1; i >= 0; i--) {
            smallDivisors.push_back(largeDivisors[i]);
        }

        return smallDivisors;
    }
};

int main()
{
    int n = 6;
    
    // Creating and instance of Solution class
    Solution sol; 
    
    // Function call to find all divisors of n
    vector<int> ans = sol.optimal(n);
    
    cout << "The divisors of " << n << " are: ";
    for(int i=0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}