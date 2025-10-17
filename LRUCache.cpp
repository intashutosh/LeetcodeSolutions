struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

void deleteNode(Node*& node, Node*& first, Node*& last){
    if(last == nullptr){
    }
    else if(node->prev == nullptr && node->next == nullptr){
        last = nullptr;
        first = nullptr;
    }
    else if(node->next == nullptr){
        node->prev->next = nullptr;
        last = node->prev;
    }
    else if(node->prev == nullptr){
        node->next->prev = nullptr;
        first = node->next;
    }
    else{
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    node->prev = nullptr;
    node->next = nullptr;

}

class LRUCache {
public:
    int n;
    Node* first;
    Node* last;
    unordered_map<int, pair<int, Node*>> mpp;
    LRUCache(int capacity) {
        n = capacity;
        last = nullptr;
        first = nullptr;
    }
    int get(int key) {
        if(mpp.count(key)){
            Node* node = mpp[key].second;
            deleteNode(node, first, last);
            node->data = key;
            if(last != nullptr){
                last->next = node;
                node->prev = last;
                last = node;
            }
            else{
                last = node;
                first = node;
            }
            return mpp[key].first;
        }
        else{
            return -1;
        }
    }
    void put(int key, int value) {
        if(mpp.count(key)){
            Node* node = mpp[key].second;
            deleteNode(node, first, last);
            node->data = key;
            mpp[key] = {value, node};
            if(last != nullptr){
                node->prev = last;
                last->next = node;
                last = node;
            }
            if(last == nullptr){
                last = node;
                first = node;
            }
        }
        else if(mpp.size() <= (n-1)){
            Node* nn = new Node(key);
            mpp[key] = {value, nn};
            if(last != nullptr){
                nn->prev = last;
                last->next = nn;
                last = nn;
            }
            else{
                last = nn;
                first = nn;
            }
        }
        else{
            mpp.erase(first->data);
            Node* node = first;
            deleteNode(node, first, last);
            Node* nn = new Node(key);
            mpp[key] = {value, nn};
            if(last != nullptr){
                last->next = nn;
                nn->prev = last;
                last = nn;
            }
            else{
                last = nn;
                first = nn;
            }

        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */