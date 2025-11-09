#ifndef HASHTABLE_HPP_
#define HASHTABLE_HPP_

#include "node.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
// Key là string (English), Value là string (Vietnamese)
using K = string;

struct Meaning{
    string type;
    string meaning;

    Meaning(string t = "", string m = "") : type(t), meaning(m) {}
};
class HashTable {
private:
    int M; 
    Linked_list<K ,Meaning>* table;
    unsigned long hashFunction(string& word){
        unsigned long h = 5381;
        for ( char c : word){
            h += (h * 33) + tolower(c);
        }
        return h % M;
    }

public:
   
    HashTable(int size = 10007) : M(size) {
        table = new Linked_list<K , Meaning>[M];
    }  
    ~HashTable() {
        delete[] table; 
    } 
    void insert(K& key , Meaning& value);
    Meaning* search(K& key);
    bool remove(K& key);
    bool update(K& key , Meaning& newValue);
    int getCapicity();
    void saveToFile(std::ofstream& outFile);
};
#endif