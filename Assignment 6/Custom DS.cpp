#include<bits/stdc++.h>
using namespace std;

class DataStructure{
    vector<int> arr;
    map<int, int> mp;

    public:
    void add(int data){
        if(mp.find(data) != mp.end()){
            return;
        }
        int index = arr.size();
        arr.push_back(data);
        mp.insert(pair<int, int>(data, index));
    }

    void remove(int data){
        if(mp.find(data) == mp.end()){
            return;
        }
        int index = mp.at(data);
        mp.erase(data);
        int last = arr.size()-1;
        swap(arr[last], arr[index]);
        arr.pop_back();
        mp.at(arr[index]) = index;
    }
    int search(int data){
        if(mp.find(data) != mp.end()){
            return mp.at(data);
        }
        return -1;
    }
    int getRandom(){
        srand(time(NULL)); 
        int randomIndex = rand() % arr.size()-1;
        return mp.at(randomIndex);
    }
};

int main(){
    DataStructure ds;
    ds.add(1);
    ds.add(2);
    ds.add(3);
    ds.add(4);
    ds.add(5);
    cout<<ds.search(3)<<endl;
    ds.remove(3);
    cout<<ds.search(4)<<endl;
    cout<<ds.getRandom()<<endl;
    return 0;

}
