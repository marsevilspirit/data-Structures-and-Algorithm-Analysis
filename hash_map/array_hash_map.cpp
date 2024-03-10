#include <string>
#include <vector>
#include <iostream>

struct Pair{
public:
    int key;
    std::string val;

    Pair(int key, std::string val):key(key),val(val){}
};

class AssayHashMap{
private:
    std::vector<Pair*> buckets;

public:
    AssayHashMap()
    {
        buckets = std::vector<Pair*>(100);
    }

    ~AssayHashMap()
    {
        for(const auto & bucket: buckets)
        {
            delete bucket;
        }
        buckets.clear();
    }

    int hashFunc(int key)
    {
        int index = key % 100;
        return index;
    } 

    std::string get(int key)
    {
        int index = hashFunc(key);
        Pair * pair = buckets[index];
        if(pair == nullptr)
            return "";
        return pair->val;
    }

    void put(int key, std::string val)
    {
        Pair* pair = new Pair(key, val);
        int index = hashFunc(key);
        buckets[index] = pair;
    }

    void remove(int key)
    {
        int index = hashFunc(key);

        delete buckets[index];
        buckets[index] = nullptr;
    }
    
    std::vector<Pair*> pairSet()
    {
        std::vector<Pair*> pairSet;
        for(Pair* pair: buckets)
        {
            if(pair != nullptr)
                pairSet.emplace_back(pair);
        }

        return pairSet;
    }

    std::vector<int> keySet()
    {
        std::vector<int> keySet;
        for(Pair* pair: buckets)
        {
            if(pair != nullptr)
            {
                keySet.emplace_back(pair->key);
            }
        }

        return keySet;
    }

        std::vector<std::string> valSet()
    {
        std::vector<std::string> valSet;
        for(Pair* pair: buckets)
        {
            if(pair != nullptr)
            {
                valSet.emplace_back(pair->val);
            }
        }

        return valSet;
    }

        void print()
        {
            for(Pair* kv: buckets)
                std::cout << kv->key << " -> " << kv->val << '\n';
        }

};
