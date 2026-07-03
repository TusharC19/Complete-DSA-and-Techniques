// Multiple childs 
// each child have multiple childs
// ex: search suggestions
// Tries - (for pattern matching)
// Segment Trees - cp (for range queries)
// Fenwick Trees - cp(for intervals)
// Advance Maths - so must do in future as you grow

/*---------------------------------------------------------------------------------------------------
1. insert
2. Search
3. Remove

// points:
root can't be null
--------------------------------------------------------------------------------*/

# include<bits/stdc++.h>
using namespace std; 

class TrieNode{
    public:
        char val;
        unordered_map<int,TrieNode*>children;
        bool isterminal;

        TrieNode(char val){
            this->val = val;
            isterminal = false;
        }

};

void insertIntoTrie(TrieNode* root, string word){
    // base case-ek time aisa ayega jab string empty ho jayegi
    if(word.length()==0){
        root->isterminal = true;
        return;
    }

    // 1 case solve
    // 1 char ko insert
    char ch = word[0];
    TrieNode* child;

    if(root->children.count(ch)==1){
        child = root->children[ch];
    }
    else{
        // absent
        child = new TrieNode(ch);
        // link
        root->children[ch] = child;
    }

    // baki recusrsion 
    insertIntoTrie(child,word.substr(1));

}
// both in O(l) - string length
bool searchTrie(TrieNode* root,string word){
    // base case
    // check last char is terminal or not
    if(word.length()==0){
        // 
        if(root->isterminal==true){
            return true;
        }
        else return false;
    }

    // 1 char only mein search
    char ch = word[0];
    TrieNode* child;

    if(root->children.find(ch)!=root->children.end()){
        // present
        child = root->children[ch];
    }
    else{
        // absent
       return false;
        
    }

    bool recursionAns = searchTrie(child,word.substr(1));
    return recursionAns;
}

// terminal node ko true se false kardo 
// i.e last char of string ko false mark kardo
// generally n>>>l in ,n-no.of word ,l-average length

void deleteWord(TrieNode* root,string word){
    // base case 
    if(word.length()==0){
        root->isterminal=false;
        return;
    }

    // 1 case mein solve karunga
    char ch = word[0];
    TrieNode* child;

    if(root->children.find(ch) != root->children.end()){
        // present
        child = root->children[ch];
    }
    else{
        // absent
        return;
    }

    // baaki recusion
    deleteWord(child,word.substr(1));



}


int main(){
    TrieNode* root = new TrieNode('-');
    insertIntoTrie(root,"cover"); 
    insertIntoTrie(root,"car"); 
    insertIntoTrie(root,"care"); 
    insertIntoTrie(root,"cater"); 
    insertIntoTrie(root,"snake"); 
    insertIntoTrie(root,"snack"); 
 
    bool ans = searchTrie(root,"cover");
    string answer1 = ans ? "present" : "absent";
    cout<<answer1<<endl;

    deleteWord(root,"cover");
    bool ans2 = searchTrie(root,"cover");

    string answer2 = ans2 ? "present" : "absent";
    cout<<answer2<<endl;
 return 0;
}