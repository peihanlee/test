/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (30.36%)
 * Likes:    4824
 * Dislikes: 215
 * Total Accepted:    454.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * 
 * The cache is initialized with a positive capacity.
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * 
 * 
 * LRUCache cache = new LRUCache( 2 /* capacity */ );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 * 
 * 
 * 
 * 
 */

// @lc code=start
class LRUCache {
public:
    LRUCache(int capacity) {
      cap = capacity;        
    }
    
    int get(int key) {
      if(data_map.count(key)>0){
        cacheData.splice(cacheData.begin(), cacheData , data_map[key]);
        return data_map[key]->val;
      }
      else{
        return -1;
      }        
    }
    
    void put(int key, int value) {
      if(data_map.count(key)>0){
        data_map[key]->val = value;
        cacheData.splice(cacheData.begin(), cacheData , data_map[key]);
        data_map[key]=cacheData.begin();
      }else{
        if(cacheData.size()>=cap){
          data_map.erase(cacheData.back().key);
          cacheData.pop_back();
        }
        cacheData.push_front(dataNode(key,value));
        data_map[key]=cacheData.begin();
      }
        
    }
private:
    struct dataNode{
    public:
      int key;
      int val;
      dataNode(int k, int v):key(k),val(v){}
    };
    int cap;
    list<dataNode> cacheData;
    unordered_map<int, list<dataNode>::iterator> data_map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
