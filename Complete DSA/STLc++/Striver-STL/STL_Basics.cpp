# include<bits/stdc++.h>
using namespace std; 

void explainpair(){
    pair<int,char>pr1 = make_pair(1,'c');
    // cout<<pr1.first<<" "<<pr1.second<<"\n";

    pair<pair<int,char>,int>pr2 = {{5,'h'},8};
    // cout<<pr2.first.second<<" ";

    
}
void explainvector(){
    vector<int>v(5,0);
    vector<int>vec = {7,8,1,2,0};
    auto revbegin= vec.rbegin();
    auto revend= vec.rend();
    // for(auto i=revbegin;i<revend;i++){
    //     cout<<*i<<" ";
    // }

    // vector<int>dupVec(vec.begin()+1,vec.end()-1);
    // for(auto i:dupVec){
    //     cout<<i<<" ";
    // }
    vec.insert(vec.begin(),3);
     for(auto i:vec){
        cout<<i<<" ";
    }
}
void explainpq(){
    // min heap
    priority_queue<int,vector<int>,greater<int>>heap;
    heap.push(10);
    heap.push(7);
    heap.push(3);
    heap.push(18);

    priority_queue<int>pq;
    pq.push(10);
    pq.push(7);
    pq.push(3);
    pq.push(18);

    while(!heap.empty()){
        cout<<heap.top()<<" ";
        heap.pop();
    }

}
void explainset(){
    // store element in ascending order
    set<int>st;
    st.insert(2);
    st.insert(12);
    st.insert(28);
    st.insert(28);
    st.insert(28);

    // for(auto it: st){
    //     cout<<it<<" ";
    // }
    // auto it = st.find(12);
    // if(it != st.end()) cout<<*it<<"\n";



}

void explainmultiset(){
    multiset<int>ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    ms.insert(5);

    for(auto it: ms){
        cout<<it<<" ";
    }

}
void explainUnorederdSet(){

}

void explainMap(){
    map<int,string>mapp;
    mapp.insert({4,"ram"});
    mapp[1] = "sam";
    mapp[2] = "rick";

    auto it = mapp.find(4);
    cout<<(*it).first<<"->"<<(*it).second<<endl;
    

}
void explainMultimap(){
    multimap<int,char>mp;
    mp.insert({1,'a'});
    mp.insert({1,'a'});
    mp.insert({1,'a'});
    mp.insert({2,'b'});
    mp.insert({3,'c'});
    mp.insert({2,'h'});
    mp.insert({2,'h'});

    auto it = mp.equal_range(2);
    for(auto i = it.first;i!=it.second;i++){
        cout<<(*i).first<<"->"<<(*i).second<<endl;
    }


}

void explainfunc(){
    int arr[] = {6,2,1,7,0};
    // cout<<accumulate(arr+4,arr+5,2);
    // string s= "abc";
    // string s= "cba";
    string s = "bac";


    do{
        cout<<s<<endl;
    }
    // while(next_permutation(s.begin(),s.end()));
    while(prev_permutation(s.begin(),s.begin()+3));


}

void maxEle(){
    int arr[] = {6,2,1,7,0};
    auto it = max_element(arr,arr+5);
    cout<<*it<<endl;
}
bool comaparator(int a,int b){
    return a>b;
}
void comparatorEx(){
    int arr[] = {5,6,1,2};
    sort(arr,arr+4);
    for(int i=0;i<4;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    sort(arr,arr+4,comaparator);
    for(int i=0;i<4;i++){
        cout<<arr[i]<<" ";
    }
}
bool comapre(pair<int,int>ele1,pair<int,int>ele2){
    if(ele1.first<ele1.first) return true;
    if(ele2.second>ele2.first) return true;
    if(ele1.first<ele2.first) return false;
}
void explaincomparator(){
    pair<int,int>arr[] = {{1,6},{1,5},{2,6},{2,9},{3,9}};
    sort(arr,arr+5,comapre);
    for(auto i:arr){
        cout<<i.first<<","<<i.second<<endl;
    }
}



int main(){
    // explainpair();
    // explainvector();
    // explainpq();
    // explainset();
    // explainMap();
    // explainfunc();
    explaincomparator();

 return 0;
}