/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

// @lc code=start
// #include<bits/stdc++.h>
// using namespace std;
class MyHashMap {
private:
    vector<int>table;
public:
    MyHashMap() {
        table.resize(10000001,-1);
    }
    
    void put(int key, int value) {
        table[key]=value;
    }
    
    int get(int key) {
        return table[key];
    }
    
    void remove(int key) {
        table[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

