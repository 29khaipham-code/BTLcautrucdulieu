#include "dictionary.hpp"
#include <fstream>
#include <sstream>


Dictionary::Dictionary(const string& filePath)
    : dataFilePath(filePath) {
}

void Dictionary::loadFromFile() {
    ifstream inFile(dataFilePath);
    if (!inFile.is_open()) {
        cerr << "Khong the mo file: " << dataFilePath << ". Tao file moi khi luu." << endl;
        return;
    }

    string line;
    int count = 0;
    while (getline(inFile, line)) {
        if( line.empty()) continue;
        stringstream ss(line);
        string Aeng;
        Meaning meaning;
        getline(ss , Aeng , ',');
        getline(ss , meaning.type,',');
        getline( ss , meaning.meaning );
        myTable.insert(Aeng , meaning);
        count++;
        
    }

    cout << "Da nap thanh cong " << count << " tu vao tu dien." << endl;
    inFile.close();
}

void Dictionary::saveToFile() {
    std::ofstream outFile(dataFilePath);
    if (!outFile.is_open()) {
        cerr << "Loi: Khong thể ghi ra file: " << dataFilePath << endl;
        return;
    }
    myTable.saveToFile(outFile); 

    outFile.close();
    cout << "Da luu tu dien vao file: " << dataFilePath << endl;
}


string Dictionary::lookupWord( string& eng) {
    Meaning* resultPtr = myTable.search(eng); // ham search tra ve con tro kieu Meaning
    if (resultPtr != nullptr) {
        // Định dạng chuỗi trả về
        return ": (" + resultPtr->type + "): " + resultPtr->meaning;
    } else {
        return "[Khong tim thay tu nay]";
    }
}

void Dictionary::addWord( string& eng,  string& type,  string& meaning) {
    if (myTable.search(eng) != nullptr) {
        cout << "Tu '" << eng << "' da ton tai." << endl;
        return ;
    } else {
        Meaning newMeaning(type, meaning);
        myTable.insert(eng, newMeaning); // Dùng hàm insert của HashTable
        cout << "Da them tu: " << eng << endl;
    }
}

void Dictionary::modifyWord( string& eng,  string& newType,  string& newMeaning) {
    
    Meaning newMean(newType, newMeaning);
    bool success = myTable.update(eng, newMean); 

    if (success) {
        cout << "Da cap nhat nghia/loai tu cua '" << eng << "'." << endl;
    } else {
        cout << "Loi: Khong tim thay tu '" << eng << "' de sua." << endl;
    }
}

void Dictionary::deleteWord( string& eng) {
    bool success = myTable.remove(eng); 

    if (success) {
        cout << "Da xoa tu '" << eng << "'." << endl;
    } else {
        cout << "Loi: Khong tim thay tu '" << eng << "' de xoa." << endl;
    }
}

void Dictionary::menu(){
    cout << "\n--- TU DIEN ANH-VIET (HASH TABLE) ---\n";
    cout << "1. Tra tu\n";
    cout << "2. Them tu moi\n";
    cout << "3. Sua tu\n";
    cout << "4. Xoa tu\n";
    cout << "0. Luu va Thoat\n";
    cout << "=======================================\n";
    cout << ">>Nhap lua chon: ";
}
void Dictionary::process(int selection){
    switch( selection){
        case 1: {
            string word;
            cout <<">> Nhap tu ban muon tra: "; getline( cin >> ws , word);
            cout <<endl<<word ; lookupWord(word);
            break;
        }
        case 2: {
            cout <<"Them tu moi"<<endl;
            string eng ,type ,vie;
            cout << "Nhap tu tieng anh: " ; getline( cin >> ws , eng);
            cout << "Nhap tu loai: " ; getline ( cin >> ws , type);
            cout << "Nhap nghia tieng viet: " ; getline ( cin >> ws , vie);
            addWord(eng, type ,vie);
            break;
        }
        case 3: {
            cout << "Sua tu dien"<< endl;
            string word;
            cout <<"Nhap tu tieng anh muon sua doi"; getline ( cin >>ws ,word);
            Meaning* ptr =  myTable.search(word);
            if( ptr != nullptr){
                string type ,vie;
                cout << "Nhap tu loai moi: "; getline ( cin >> ws , type);
                cout << "Nhap nghia tieng viet moi: "; getline ( cin >> ws , vie);
                modifyWord(word , type , vie);
            }
            else{
                cout <<"Loi ko tim thay tu";
            }
            break;
        }
        case 4: {
            cout <<"Xoa tu:"<<endl;
            string word;
            cout << "Nhap tu tieng anh muon xoa: "; getline ( cin >> ws , word);
            deleteWord(word);
            break;
        }
        case 0:{
            saveToFile();
            selection = 0;
            break;
        }
    }
}
void Dictionary::run(){
    int selection;
    do {
        break;
        menu();
        cout << ">> Nhap Lua chon: "; cin >> selection;
        if (cin.fail()) {
           cout << "[ERROR] Vui long nhap mot so."<< endl;
           cin.clear();
           cin.ignore();
        selection = -1;
        } else {
            cin.ignore();
            process(selection);
        }
    }
    while ( selection != 0);
}