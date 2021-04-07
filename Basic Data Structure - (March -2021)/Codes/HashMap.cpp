#include<bits/stdc++.h>
using namespace std;
class HashMap{
private:
    int B;
    vector< pair<int, string> > v[20]; //phone number -> name
    int size;
public:
    HashMap(){
        size = 0;
        B = 20;
    }

    int hash(int key){
        return key%B;
    }

    void insert(int phone, string name){
        int index = hash(phone);
        v[index].push_back({phone, name});
    }

    void remove(int phone){
        int index = hash(phone);
        for(int i = 0; i<v[index].size(); i++ ){
            if(v[index][i].first == phone){
                swap(v[index][i], v[index][v[index].size()-1]);
                v[index].pop_back();
                cout<<"Value found and deleted successfully!!!\n";
                return;
            }
        }
        cout<<"No value found corresponding to this key :(\n";
    }

    string search(int phone){
        int index = hash(phone);
        for(auto &entry: v[index]){
            if(entry.first == phone){
                return entry.second;
            }
        }
        return "NIL";
    }

    void print(){
        for(int i=0;i<B;i++){
            cout<<"Bucket #"<<i<<": ";
            for(auto entry:v[i]){
                cout<<"{"<<entry.first<<", "<<entry.second<<"}, ";
            }
            cout<<endl;
        }
    }
};

class HashMapProbing{
private:
    int B;
    pair<int, string> v[7]; //phone number -> name
    bool isFresh[7];
    int size;
public:
    HashMapProbing(){
        size = 0;
        B = 7;
        for(int i=0;i<B;i++){
            isFresh[i] = true;
        }
    }

    int hash(int key){ // hash0 -> hash1 -> hash2
        return key%B;
    }

    void insert(int phone, string name){
        for(int i=0;i<B;i++){
             int index = hash(phone + i);
             if(isFresh[index] == true){
                v[index] = make_pair(phone, name);
                isFresh[index] = false;
                break;
             }
        }
    }

    void remove(int phone){
        for(int i=0;i<B;i++){
             int index = hash(phone + i*i);
             if(isFresh[index] == true){
                return;
             }else if(v[index].first == phone){
                v[index].second = "NIL";
                return;
             }
        }
    }

    string search(int phone){
        for(int i=0;i<B;i++){
             int index = hash(phone + i);
             if(isFresh[index] == true){
                return "NIL";
             }else if(v[index].first == phone){
                return v[index].second;
             }
        }
        return "NIL";
    }

    void print(){
        for(int i=0;i<B;i++){
            cout<<"Bucket #"<<i<<": ";
            cout<<"{"<<v[i].first<<", "<<v[i].second<<"}\n";

        }
    }
};
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
        
    HashMapProbing m;

    m.insert(35, "Ram");
    m.insert(36, "shyam");
    m.insert(7, "Gyan");
    m.insert(14, "A");

    m.print();
    return 0;
}