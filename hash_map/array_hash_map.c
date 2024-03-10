#include <stdlib.h>
#include <string.h>

#define HASHTALBLE_CAPACITY 100

typedef struct{
    int key;
    char *val;
}Pair;

typedef struct{
    Pair *buckets[HASHTALBLE_CAPACITY];
}ArrayHashMap;

ArrayHashMap *newArrayHashMap()
{
    ArrayHashMap *hmap = malloc(sizeof(ArrayHashMap));
    return hmap;
}

void delArrayHashMap(ArrayHashMap *hmap)
{
    for(int i = 0; i < HASHTALBLE_CAPACITY; i++)
    {
        if(hmap->buckets[i] != NULL)
        {
            free(hmap->buckets[i]->val);
            free(hmap->buckets[i]);
        }
    }
}

void put(ArrayHashMap* hmap, const int key, const char *val)
{
    Pair* pair = malloc(sizeof(Pair));
    pair->key = key;
    pair->val = malloc(strlen(val)+1);
    strcpy(pair->val, val);

    int index = hashFunc(key);
    hmap->buckets[index] = pair;
}

void removeItem(ArrayHashMap* hmap, const int key)
{
    int index = hashFunc(key);
    free(hmap->buckets[index]->val);
    free(hmap->buckets[index]);
    hmap->buckets[index] = NULL;
}

void pairSet(ArrayHashMap* hmap, MapSet* set)
{
    Pair *entries;
    int i = 0, index = 0;
    int total = 0;

    for(i = 0; i < HASHTALBLE_CAPACITY; i++)
    {
        if(hmap->buckets[i] != NULL)
        {
            total++;
        }
    }

    entries = malloc(sizeof(Pair)*total);
    for(i = 0; i < HASHTALBLE_CAPACITY; i++)
    {
        if(hmap->buckets[i] != NULL)
        {
            entries[index].key = hmap->buckets[i]->key;
            entries[index].val = malloc(strlen(hmap->buckets[i]->val)+1);
            strcpy(entries[index].val, hmap->buckets[i]->val);
            index++;
        }
    }

    set->set = entries;
    set->len = total;
}
