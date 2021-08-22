#include <list>
using namespace std;
class LRUCache {
    map<int, list<pair<int, int>>::iterator> hash;
    int m_MaxCapacity;
    list<pair<int, int>> cache;
public:
    LRUCache(int capacity) {
        m_MaxCapacity = capacity;
    }

    int get(int key) {
        if(hash.find(key) != hash.end()){
            auto it = hash.find(key);
            cache.splice(cache.begin(), cache, it->second);
            return it->second->second;
        }
        return -1;
    }

    void put(int key, int value) {
        auto it = hash.find(key);
        if(it != hash.end()){
          it->second->second = value;
          cache.splice(cache.begin(), cache, it->second);
        } else {
            cache.push_front({key,value});
            hash[key] = cache.begin();
            if(hash.size() > m_MaxCapacity){
                hash.erase(cache.back().first);
                cache.pop_back();
            }
        }
    }
};
