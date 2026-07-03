#include<bits/stdc++.h>
using namespace std;

void printSubsequences(string str, int i, string output,vector<string> &ans) {
  //base case
  if(i == str.length()) {
    // cout << output << endl;
    ans.push_back(output);
    return;
  }
  //1 case khud solve karunga
  char ch = str[i];
  //include ch 
  printSubsequences(str,i+1,output + ch,ans);
  //exclude ch
  printSubsequences(str,i+1,output,ans);
}

void printSubseq(string str, int i, string output) {
  //base case
  if(i == str.length()) {
    cout << output << endl;
    return;
  }
  //1 case khud solve karunga
  char ch = str[i];
  //include ch 
  printSubseq(str,i+1,output + ch);
  //exclude ch
  printSubseq(str,i+1,output);
}

int main() {  
  string str = "abc";
  string output = "";
  int index=0;

  vector<string> ans;
  printSubsequences(str,index,output,ans);
  cout << ans.size() << endl;
  cout<<endl;
  for(auto i: ans)  cout << i << endl;



  return 0;
}