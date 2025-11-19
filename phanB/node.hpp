#ifndef LinkedList_hpp
#define LinkedList_hpp

template <class K ,class V>
struct Node{
    K key;
    V value;
    Node *next;

    Node(K key , V value) : key(key) , value(value) , next(nullptr){}
};
template <class K ,class V>
class Linked_list {
    Node<K ,V>* head;
    public:
        Node<K, V>* getHead() const {
            return head;
        }
        Linked_list() : head(nullptr){}
        ~Linked_list();
        void push_front( K& key , V& value);
        bool eraseNode(K& key);
        V* search(K& key);
        
};

template <class K ,class V>
Linked_list<K ,V>::~Linked_list(){
    Node<K ,V>* current = head;
    while ( current != nullptr){
        Node<K ,V>* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

template<class K ,class V> 
void Linked_list<K ,V>::push_front(K& key , V& value){
    Node<K, V>* newNode = new Node(key , value);
    newNode->next = head;
    head = newNode;
}

template<class K ,class V>
bool Linked_list<K, V>::eraseNode(K& key){
    if ( head == nullptr){
        return false;
    }

    if( head->key == key ){
        Node<K ,V>* nodeDelete = head;
        head = head->next;
        delete nodeDelete;
        return true;
    }
    Node<K ,V>* prev = head;
    // tim con tro prev trc key
    while ( prev->next != nullptr && prev->next->key != key){
        prev = prev->next;
    }
    if ( prev->next == nullptr){
        return false;
    }
    Node<K, V>* nodeDelete = prev->next;
    prev->next = nodeDelete->next;
    delete nodeDelete;
    return true;
}

template<class K, class V>
V* Linked_list<K, V>::search(K& key){
    if(head == nullptr){
        return nullptr;
    }
    Node<K,V>* current = head;
    while ( current != nullptr){
        if ( current->key == key){
            return &(current->value);
        }
        current = current->next;
    }
    return nullptr;
}


#endif