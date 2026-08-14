class LRUCache {
public:

    list<int> dll;
    map<int, pair<list<int>::iterator, int>> mp;   //map with 3 things. one int. and the other part as pair. Address of node and its value.
    int n;

    LRUCache(int capacity) {
        n = capacity;
    }
    
    void makeRecentlyUsed(int key) {
        dll.erase(mp[key].first);  // mp[key] se pair mil jaayega. and pair ke first se address

        dll.push_front(key);
        mp[key].first = dll.begin();  //hashmap me ye deleted node ka address change karo.
    }

    int get(int key) {
        if(!mp.count(key)) return -1;

        makeRecentlyUsed(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        
        if(mp.count(key)) {  //already exist karta hai ye key toh uska value change krdo(avoid diff values for same key)
            mp[key].second = value;
            makeRecentlyUsed(key);
        }
        else{
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            makeRecentlyUsed(key);
            n--;
        }

        if(n < 0) {  //agar put karna hai. par capacity khtm hai.
            int delete_oldest = dll.back();  //last node 
            mp.erase(delete_oldest);         //map se delete.
            dll.pop_back();                   //dll se delete.

            n++;  //capacity badha do (delete kiye).
        }
    }
};