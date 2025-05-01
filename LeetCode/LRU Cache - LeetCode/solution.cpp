class Node {
public:
    Node* next;
    Node* pre;
    int val;
    int key;
    Node(int _key,int _val){
        key = _key;
        val = _val;
        next = nullptr;
        pre = nullptr;
    }
};

class LinkList{
public:
    Node* head;
    Node* tail;
    unordered_map<int,Node*> mp;

    LinkList(int capacity){
        int temp_key = -1;
        head = new Node(temp_key,-1);
        mp[temp_key] = head;
        Node* temp = head;
        Node* pre = nullptr;
        while(--capacity){
            temp->next = new Node(--temp_key,-1);
            mp[temp_key] = temp->next;
            temp->pre = pre;
            pre = temp;
            temp = temp->next;
        }
        tail = temp;
    }

    void moveNodeToEnd(Node* node){
        if(node == tail) return;
        if(node == head){
            head = node->next;
            head->pre = nullptr;
            node->next = nullptr;
            node->pre = tail;
            tail->next = node;
            tail = node;
            return;
        }

        //between
        node->pre->next = node->next;
        node->next->pre = node->pre;
        node->next = nullptr;
        node->pre = tail;
        tail->next = node;
        tail = node;
        return;
    }

    int get_update(int key){
        if(mp[key] == nullptr) return -1;
        moveNodeToEnd(mp[key]);
        return mp[key]->val;
    }

    void put_update(int key,int val){
        if(mp[key] == nullptr){
            mp[key] = head;
            mp[head->key] = nullptr;
            head->key = key;
            head->val = val;
        }
        else mp[key]->val = val;

        moveNodeToEnd(mp[key]);
    }

    void printList(){
        Node* temp = head;
        cout<<"\n-----------\n";
        while(temp != nullptr){
            cout<<"temp->key : " <<temp->key<<"\n";
            cout<<"mp[temp->key]->key : " <<mp[temp->key]->key<<"\n";
            cout<<"temp->val : " <<temp->val<<"\n";
            temp = temp->next;
            cout<<"\n";
        }
        cout<<"-----------------\n\n";
    }
};

class LRUCache {
public:
    LinkList* LL;

    LRUCache(int capacity) {
        LL = new LinkList(capacity);
        //LL->printList();
    }
    
    int get(int key) {
        //cout<<"get : "<<key<<"\n";
        return LL -> get_update(key);
        //LL->printList();
    }
    
    void put(int key, int value) {
        //cout<<"put : "<<key<<" , "<<value<<"\n";
        LL -> put_update(key,value);
        //LL->printList();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/*
5 - k3 -> z
6 - k2 -> y
7 - k4 -> a
8 - k1 -> x
*/