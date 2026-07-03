# include<bits/stdc++.h>
using namespace std; 

int findlen(char arr[],int s){
    int cnt=0;
    int i=0;
    while(arr[i]!='\0'){
        cnt++;
        i++;
    }
    return cnt;
    
}

void replaceChar(char arr[],int s){
    int len = findlen(arr,s);

    for(int i=0;i<len;i++){
        if(arr[i]=='@'){
            arr[i] = '_';
        }
    }
}

void intoUpper(char arr[],int s){
    int len = findlen(arr,s);
    for(int i=0;i<len;i++){
        char ch = arr[i];
        if(ch>='a' && ch<='z'){
        ch = ch - 'a' + 'A';
        arr[i] = ch;
        }
    }
}

// upper to lower case conversion
// up to low - ch = ch - 'A' + 'a'
// low to up - ch = ch - 'a' + 'A'

void intoLower(char arr[],int s){
    int len = findlen(arr,s);
    for(int i=0;i<len;i++){
        char ch = arr[i];
        if(ch>='A' && ch<='Z' ){
        ch = ch - 'A' + 'a';
        arr[i] = ch;
        }
    }
}

void reverseArr(char arr[], int s){
    int len = findlen(arr,s);
    int i=0;
    int j=len-1;

    while(i<=j){
        swap(arr[i],arr[j]);
        i++;j--;
    }
}

bool checkPalindrome(char arr[],int s){
    int len = findlen(arr,s);
    int i=0;
    int j=len-1;

    while(i<=j){
        if(arr[i]==arr[j]){
            i++;j--;
        }
        else return false;
    }
    return true;
}


int main(){
        char arr[100];
        cout<<"Enter: "<<endl;
        cin.getline(arr,100);

        string ans = checkPalindrome(arr,100) ? "palindrome" : "Not Palindrome";
        cout<<ans<<endl;
        

        // cout<<findlen(arr,100)<<endl;
        // reverseArr(arr,100);
        // cout<<arr<<endl;

        // intoUpper(arr,100);
        // intoLower(arr,100);
        // cout<<arr<<endl;


        // cin>>arr;
        // replaceChar(arr,100);
        // cout<<arr<<endl;


        // cin>>arr;
        // cout<<findlen(arr,100);

        // cout<<"enter your name: ";
        // cin.getline(arr,100);
        // cin.getline(arr,8); // last ka char delimator hota hai
        // cin.getline(arr,100,'&');
        // Changing delimitor - jaise hi app hit krenge or find krenge toh hum input lena ruk jata hai

        // cout<<"Your name is: "<<arr<<endl;
        

        // for(int i=0;i<=4;i++){
        //     cout<<int(arr[i])<<endl;
        // }
 return 0;
}