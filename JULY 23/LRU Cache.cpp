class LRUCache {
public:
    list<pair<int, int>> dll;  // Doubly linked list to store key-value
    unordered_map<int, list<pair<int, int>>::iterator> mp; 
    int size;                 

    LRUCache(int size) :size(size) {}

    int get(int key) {
        // Check wether the key exists in the cache
        if (mp.count(key) == 0)
            return -1; // Key not found, return -1

        auto Iterator = mp[key];                           
        auto Pair = *Iterator;                     
        dll.erase(Iterator);                                
        dll.push_front(Pair);                               
        auto newIterator = dll.begin();                      
        mp[key] = newIterator;

        return Pair.second;                              
    }

    void put(int key, int value) {
        // Check wether the key is in the cache
        if (mp.count(key) > 0) {
            
            auto Iterator = mp[key];                        
            auto Pair = *Iterator;                   
            dll.erase(Iterator);                               
            dll.push_front({key, value});                             
            mp[key] = dll.begin();                                      
            return;
        }

        // check wether the cache is full
        if (dll.size() == size) {
            // Cache is full, remove the oldest used element
            auto lastElement = dll.back();                             
            mp.erase(lastElement.first);                               
            dll.pop_back();                                             
        }
   
        dll.push_front({key, value});                                  
        mp[key] = dll.begin();                                           
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */