class Node {
public:
    string key;
    Node* prev;
    Node* next;

    Node(const string& k) : key(k), prev(nullptr), next(nullptr) {}
};

class Container {
public:
    int val;

    Container* next;
    Container* prev;
    Node* child;

    Container(Node* c = nullptr) : child(c), prev(nullptr), next(nullptr) {}

    bool empty(){
        if(child == nullptr) return true;
        else return false;
    }

    bool oneChild(){
        if(!empty() && child->next == nullptr) return true;
        return false;
    }

    void removeChild(Node* node){

        // if first
        if(node->prev == nullptr){
            child = node->next;
            node->next = nullptr;

            if(child != nullptr) child->prev = nullptr;
            return;
        }

        node->prev->next = node->next;
        if(node->next != nullptr) node->next->prev = node->prev;

        node->prev = nullptr;
        node->next = nullptr;
        return;
    }

    void insertChild(Node* node){
        if(child == nullptr){
            child = node;
            return;
        }

        Node* temp = child;
        child = node;

        node->next = nullptr;
        node->prev = nullptr;

        node->next = temp;
        if(temp!= nullptr) temp->prev = node;
    }

    void incVal(){
        val = val + 1;
    }

    void decVal(){
        val = val - 1;
    }

    void insertNextContainer(Node* node = nullptr){
        Container* temp = next;
        next = new Container(node);
        next->next = temp;
        if(temp != nullptr) temp->prev = next;
        next->prev = this;

        next->val = val + 1;

    }

     void insertPrevContainer(Node* node = nullptr){
        Container* temp = prev;
        prev = new Container(node);
        prev->prev = temp;
        if(temp != nullptr) temp->next = prev;
        prev->next = this;

        prev->val = val - 1;

    }

    string getKey(){
        if(child == nullptr) return "";
        return child->key;
    }

    void deleteContainer(){
        if(prev != nullptr) prev->next = next;
        if(next != nullptr) next->prev = prev;

        delete this;
    }


};



class AllOne {
public:
        unordered_map<string,pair<Container*,Node*> >mp;
        Container* head;
        Container* tail;

    AllOne() {
        head = nullptr;
        tail = nullptr;
    }

    void inc(string key) {

        auto [container,node] = mp[key];

        
        if(container == nullptr){
            insertNewNode(key);
            return;
        }
        

        if(container == tail || (container != tail && container->next->val > container->val + 1)){

            if(container->oneChild()){
                container->incVal();
                return;
            }

            container->removeChild(node);
            container->insertNextContainer(node);

            if(container == tail) tail = container->next;

            mp[key] = make_pair(container->next,node);

            if(container->empty()){
                if(container == head) head = container->next;
                container->deleteContainer();
            }

            return;
        }


        // container + 1 exist
        container->removeChild(node);
        container->next->insertChild(node);


        mp[key] = make_pair(container->next,node);

        if(container->empty()){
                if(container == head) head = container->next;
                container->deleteContainer();
        }

        return;

    }
    
    void dec(string key) {


        auto [container,node] = mp[key];

        if(container->val == 1){
            
            if(container->oneChild()){
                if(container == tail){
                    mp[key] = make_pair(nullptr,nullptr);
                    tail = nullptr;
                    head = nullptr;
                    container->deleteContainer();
                    return;
                }

                mp[key] = make_pair(nullptr,nullptr);
                head = container->next;
                container->deleteContainer();
                return;

            }

            // we only remove node
            container->removeChild(node);
            mp[key] = make_pair(nullptr,nullptr);


            return;
        }


        if(container == head || (container != head && container->prev->val < container->val - 1)){

            if(container->oneChild()){
                container->decVal();
                return;
            }

            container->removeChild(node);
            container->insertPrevContainer(node);

            if(container == head) head = container->prev;

            mp[key] = make_pair(container->prev,node);

            if(container->empty()){
                if(container == tail) tail = container->prev;
                container->deleteContainer();
            }
            return;
        }

        // container - 1 exist
        container->removeChild(node);
        container->prev->insertChild(node);

        mp[key] = make_pair(container->prev,node);

        if(container->empty()){
                if(container == tail) tail = container->prev;
                container->deleteContainer();
        }
        return;
    }
    
    string getMaxKey() {
        if(tail == nullptr) return "";
        else return tail->getKey();
    }
    
    string getMinKey() {
        if(head == nullptr) return "";
        else return head->getKey();
    }


    // helper functions
    bool listEmpty(){
        if(head == nullptr) return true;
        else return false;
    }

    bool listOneContainer(){
        if(head == tail && head != nullptr) return true;
        else return false;
    }

    void insertNewNode(string key){
        Node* newNode = new Node(key);


        if(!listEmpty()){

            if(head->val == 1){
                head->insertChild(newNode);
                mp[key] = make_pair(head,newNode);

                return;
            }

            Container* newContainer = new Container(newNode);
            newContainer->val = 1;

            newContainer->next = head;
            head->prev = newContainer;
            head = newContainer;

            mp[key] = make_pair(head,newNode);

        return;
            
        }

        // list is empty
        Container* newContainer = new Container(newNode);
        newContainer->val = 1;

        head = newContainer;
        tail = newContainer;

        mp[key] = make_pair(head,newNode);
    }

    void printList(){
        Container* temp = head;
        while(temp!= nullptr){
            cout<<"Contaienr val: "<<temp->val<<"\n";

            Node* temp2 = temp->child;
            while(temp2 != nullptr){
                cout<<temp2->key<<", ";

                temp2 = temp2->next;
            }


            temp = temp->next;
            cout<<"\n";
        }

        cout<<"reverse chek \n";
        temp = tail;
        while(temp!= nullptr){
            cout<<"Contaienr val: "<<temp->val<<"\n";

            Node* temp2 = temp->child;
            while(temp2 != nullptr){
                cout<<temp2->key<<", ";

                temp2 = temp2->next;
            }


            temp = temp->prev;
            cout<<"\n";
        }
    }

};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */