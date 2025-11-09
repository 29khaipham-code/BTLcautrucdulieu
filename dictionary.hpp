#ifndef dictionary_hpp_
#define dictionary_hpp_
#include "HashTable.hpp" 

class Dictionary {
    private:
        HashTable myTable;
        string dataFilePath;
   
        void loadFromFile();
        void addWord( string& eng,  string& type,  string& meaning);
        string lookupWord( string& eng);
        void modifyWord( string& eng,  string& newType,  string& newMeaning);
        void deleteWord( string& eng);
        void saveToFile();
        void menu();
        void process(int selection);
    public:
        Dictionary(const string& filePath);
        void run();

};

#endif 