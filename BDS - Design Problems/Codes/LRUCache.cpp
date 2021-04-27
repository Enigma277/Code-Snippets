#include<bits/stdc++.h>
using namespace std;

class LRUCache{
private:
	int capacity;
	list<int> recentList;
	unordered_map<int, list<int>::iterator> pos;  //song id -> list<int>::iterator
	unordered_map<int, int> cache;  //song id -> address
public:
	LRUCache(int K){
		capacity = K;
	}

	bool isPresent(int key){
		return cache.find(key) != cache.end();
	}

	int get(int key){
		if(isPresent(key)){
			use(key);
			return cache[key];
		}
		return -1;
	}

	void use(int key){
		if(isPresent(key)){
			recentList.erase(pos[key]);
		}else if(recentList.size() >= capacity){
			int lru = recentList.back();
			recentList.pop_back();
			cache.erase(lru);
			pos.erase(lru);
		}

		recentList.push_front(key);
		pos[key] = recentList.begin();
	}

	void update(int key, int value){
		use(key);
		cache[key] = value;
	}

	void print(){
		for(auto it:recentList){
			cout<< it<<" ";
		}
		cout<<endl;
	}

};
int main(){
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
       
    LRUCache c(3);

    c.update(1, 123);
    c.update(2, 234);
    c.update(1, 321);
    c.update(3, 111);
    c.print(); 

    c.update(4, 444);
    c.print();


    
}