
using namespace std;

class LRUCache {
    const int capacity_;
    typedef list<pair<int,int>> List;
    List list_;
    typedef unordered_map<int, list<pair<int,int>>::iterator> KeyNodeMap;
    KeyNodeMap key_to_node_map_;
    // number of elements present in the list
    int num_elements_;
public:
    LRUCache(int capacity) : capacity_(capacity), num_elements_(0) {
    }

    int get(int key) {
        KeyNodeMap::iterator result = key_to_node_map_.find(key);
        // cout << "SERACH: Key: " << key;
        if (result != key_to_node_map_.end()) {
            // cout << " found ! It is being";
            int value = (result->second)->second;
            // delete the entery from the linked list.
            list_.erase(result->second);
            list_.emplace_front(key, value);
            key_to_node_map_[key] = list_.begin();            
            // cout << " inserted at the front and deleted from the middle\n";
            return value;
        } else {
            // cout << " not found\n";
            return -1;
        }
    }

    void put(int key, int value) {
        KeyNodeMap::iterator result = key_to_node_map_.find(key);
        if (result != key_to_node_map_.end()) {
            // delete the entry from the map.
            key_to_node_map_.erase(key_to_node_map_.find(key));
            // delete the entery from the linked list.
            list_.erase(result->second);
            num_elements_--;
            // cout << "INSERT: Key: " << key << " already found !" << "deleting it" << endl;
        }

        if (num_elements_ >= capacity_) {
            list<pair<int,int>>::iterator last_item = list_.end();
            if (capacity_) {
                last_item--;
                int del_key = last_item->first;
                 // delete the entery from the linked list.
                list_.erase(last_item);

                // delete the entry from the map.
                key_to_node_map_.erase(key_to_node_map_.find(del_key));
                num_elements_--;
            }   
            // cout << "INSERT: Capacity full, Key: " << last_item->first << " is being deleted " << endl;
        }
        
        if (num_elements_ < capacity_) {
            list_.emplace_front(key, value);
            key_to_node_map_[key] = list_.begin();
            num_elements_++;
        }
        // cout << "INSERT: Key: " << key << " inserted to the front" << endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
	