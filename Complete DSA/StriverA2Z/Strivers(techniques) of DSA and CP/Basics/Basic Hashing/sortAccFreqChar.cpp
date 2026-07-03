# include<bits/stdc++.h>
using namespace std; 


bool cmpnum(int a,int b){
        return a>b;
}

bool cmp(pair<int,char>a,pair<int,char>b){
    
    if(a.first == b.first) return a.second<b.second;
    return a.first>b.first;
}

int main(){

            string s = "tree";
    
			vector<char>ans;
			vector<pair<int,char>>hash(26);

            for(int i=0;i<26;i++){
                char ch = s[i];
                hash[i] = make_pair<int ,char>(0,i+'a');
				
            }

            for(int i=0;i<s.length();i++){
                hash[s[i]-'a'].first++;
            }

            // for(auto i: hash){
            //     cout<<i.first<<" "<<i.second<<endl;
            // }

            sort(hash.begin(),hash.end(),cmp);
            cout<<endl;

            // for(auto i: hash){
            //     cout<<i.first<<" "<<i.second<<endl;
            // }

            
            for(int i=0;i<s.size();i++){
                if(hash[i].first == 0) break;
                else{
                    while(hash[i].first != 0){
                    ans.push_back(hash[i].second);
                    hash[i].first--;
                    }
                }
            }
            string st = "";
            for(int i=0;i<s.size();i++){
                if(hash[i].first == 0) break;
                else{
                    while(hash[i].first != 0){
                    st.push_back(hash[i].second);
                    hash[i].first--;
                    }
                }
            }

            // for(auto i: ans) cout<<i<<" ";

            cout<<st<<endl;

            


 return 0;
}