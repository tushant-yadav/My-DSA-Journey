/*
981. Time Based Key-Value Store
https://leetcode.com/problems/time-based-key-value-store
Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".*/

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> keyTimeMap;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        // Push '(timestamp, value)' pair in 'key' bucket.
        keyTimeMap[key].push_back({ timestamp, value });
    }
    
    string get(string key, int timestamp) {
        // If the 'key' does not exist in map we will return empty string.
        if (keyTimeMap.find(key) == keyTimeMap.end()) {
            return "";
        }
        
        if (timestamp < keyTimeMap[key][0].first) {
            return "";
        }
        
        // Using binary search on the array of pairs.
        int left = 0;
        int right = keyTimeMap[key].size();
        
        while (left < right) {
            int mid = (left + right) / 2;
            if (keyTimeMap[key][mid].first <= timestamp) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        // If iterator points to first element it means, no time <= timestamp exists.
        if (right == 0) {
            return "";
        }
                
        return keyTimeMap[key][right - 1].second;
    }
};
