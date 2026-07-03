# include<bits/stdc++.h>
using namespace std; 


string FirstNonRepeating(string &s) {
               
        // TLE aaa rh hai
        // unordered_map<char,int>m;
        // int n = s.length();
        // string result = "";
        // for(int i=0;i<n;i++){
        //     char ch = s[i];
        //     m[ch]++;
        //     char ans = '#';
        //     for(int k=0;k<=i;k++){
        //         char c = s[k];
        //         if(m[c]==1){
        //             ans = c;
        //             break; // for not seeing forward we use this
        //         }
        //     }
        //     // warna ans is not #
        //     result.push_back(ans);
        // }
        // return result;
        
        int n = s.length();
        unordered_map<char,int>m;
        string ans = "";
        deque<char>q;
        
        for(int i=0;i<n;i++){
            char ch = s[i];
            m[ch]++;
            // initial state so push first element
            q.push_back(ch);
            // finding ans now
            while(!q.empty()){
                char frontele = q.front();
                // check whether front element is ans or not
                if(m[frontele]==1){
                    ans.push_back(frontele);
                    break;
                }
                else{
                    q.pop_front();
                }
            }
            if(q.empty()){
                ans.push_back('#');
            }
            
        }
        return ans;    
        
    }


int main(){
    string s = "abaccd";
    auto ans = FirstNonRepeating(s);
    for(auto i: ans){
        cout<<i<<" ";
    }
    
 return 0;
}


