# include<bits/stdc++.h>
using namespace std;

bool cmp(const tuple<int,int,int>& a, const tuple<int,int,int>& b) {
    if (get<1>(a) == get<1>(b)) 
        return get<0>(a) < get<0>(b);
    return get<1>(a) < get<1>(b);
}

int main() {
    vector<tuple<int,int,int>> v = {
        {3, 2, 10},
        {1, 2, 20},
        {4, 1, 30}
    };

    sort(v.begin(), v.end(), cmp);

    for (auto &t : v) {
        cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << "\n";
    }
}
