#include "hashtable.hpp"

void HashTable::insert(K& key , Meaning& value){
    unsigned long  index = hashFunction(key);
    Meaning* exitValue = table[index].search(key);
    if( exitValue != nullptr){
        *exitValue = value;
    }
    else{
        table[index].push_front(key, value);
    }
}
Meaning* HashTable::search(K& key){
        unsigned long index = hashFunction(key);
        Meaning* exitValue = table[index].search(key);
        if( exitValue != nullptr){
            return  table[index].search(key);
        }
        else {
            return nullptr;
        }
            
}
bool HashTable::remove(K& key){
    unsigned long index = hashFunction(key);
        return table[index].eraseNode(key);
}

bool HashTable::update(K& key , Meaning& newValue){
    Meaning* ValuePtr = search(key); // goi luon ham search cua Hashtable

    if ( ValuePtr != nullptr){
        *ValuePtr = newValue;
        return true;
    }else return false;
}
int HashTable::getCapicity(){
    return M;
}
void HashTable::saveToFile(ofstream& outFile) {
    for (int i = 0; i < M; i++) {
        Node<K, Meaning>* currentNode = table[i].getHead();
        while (currentNode != nullptr) {
            outFile << currentNode->key << "," 
                    << currentNode->value.type << "," 
                    << currentNode->value.meaning << "\n";
            
            currentNode = currentNode->next;
        }
    }
}