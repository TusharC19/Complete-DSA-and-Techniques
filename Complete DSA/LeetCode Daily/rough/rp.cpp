// # include<bits/stdc++.h>
// using namespace std; 

// int solve(string &s){
//     int n = s.size();
//     vector<int>f(3,0);
//     int i=0;
//     int cnt = 0;
//     for(int j=i;j<n;j++){
//         char currch = s[j];
//         f[currch-'a']++;
//         while(f[0]>0 && f[1]>0 && f[2]>0){
//             char ch = s[i];
//             cnt += n-j;
//             f[ch-'a']--;
//             i++;
//         }
//     }
//     return cnt;
// }



// int main(){
    
//     string s = "aaabc";
//     int ans = solve(s);
//     cout<<ans<<endl;


//  return 0;
// }


# include<bits/stdc++.h>
using namespace std; 


int maxDistance(int n, vector<int> a) {
    int maxdis = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(a[i]<a[j]) {
                maxdis = max(maxdis,j-i);
            }
        }
    }
    return maxdis;
}

int main(){
    vector<int>nums = {5,7,3,9,1,4};
    int ans = maxDistance(6,nums);
    cout<<ans<<endl;
 return 0;
}