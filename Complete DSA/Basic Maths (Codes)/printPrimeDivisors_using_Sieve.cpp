#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

/* To store the smallest prime factors for 
all number with all nodes initially 
having smallest prime factor as 1 */
vector<int> SPF(MAX_N + 1, 1);

class Solution{
private:
    /* Function to precompute smallest prime 
    factor using sieve of eratosthenes */
    void sieve() {
        // Iterate on all the number
        for (int i = 2; i <= MAX_N; i++) {
            
            // If the number is a prime number 
            if (SPF[i] == 1) {
                
                /* Mark all its multiples who have not 
                received their smallest prime factor yet*/
                for (int j = i; j <= MAX_N; j += i) {
                    
                    // If smallest prime factor not received yet
                    if (SPF[j]== 1) {
                        
                        /* Store i as the smallest 
                        prime factor for its multiple */
                        SPF[j] = i;
                    }
                }
            }
        }
        
        // Return
        return;
    }

    /* Helper function to find the prime 
    factorization of a number */
    vector<int> primeFact(int n) { 
        
        // To store the result
        vector<int> ans;
        
        // Until the number is not reduced to 1
        while (n != 1) {
            
            // Add the smallest prime factor to the list
            ans.push_back(SPF[n]);
            
            // Update the number
            n = n / SPF[n];
        }
        
        // Return the result
        return ans;
    } 
    
public:

    /* Function to get the prime 
    factorization of all the number */
    vector<vector<int>> primeFactors(vector<int>& queries){
        
        /* Pre compute the smallest 
        possible factor for all numbers */
        sieve();
        
        // To store the answer
        vector<vector<int>> ans;
        
        // Iterate on each number in query
        for(int i=0; i < queries.size(); i++) {
            
            /* Function call to get the prime 
            factorization of current number */
            ans.push_back(primeFact(queries[i]));
        }
        
        // Return the answer
        return ans;
    }
};

int main() {
    vector<int> queries = {2, 3, 4, 5, 6};
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    // Function call to get all primes till N
    vector<vector<int>> ans = sol.primeFactors(queries);
    
    cout << "The prime factorization of all the numbers is: " << endl;
    for(int i=0; i < ans.size(); i++) {
        cout << "For " << queries[i] << ": "; 
        for(int j=0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}