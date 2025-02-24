struct Node {
    int val;
    int pre;
    vector<int> next;
    int bobPassingTime;

    Node(int val) {
        this->val = val;
        pre = -1;
        bobPassingTime = -1;
    }
};

class Solution {
public:
    void initPres(int current, unordered_map<int, Node*>& nodes) {
        for (int neighbor : nodes[current]->next) {
            if (neighbor == nodes[current]->pre)
                continue;
            nodes[neighbor]->pre = current;
            initPres(neighbor, nodes);
        }
    }

    void bobTraverse(int time, int current, unordered_map<int, Node*>& nodes) {
        if (current == -1)
            return;
        nodes[current]->bobPassingTime = time;
        bobTraverse(time + 1, nodes[current]->pre, nodes);
    }

    int recSearch(int current, int time, unordered_map<int, Node*>& nodes) {
        int maxVal = INT_MIN;
        for (int neighbor : nodes[current]->next) {
            if (neighbor == nodes[current]->pre)
                continue;
            maxVal = max(maxVal, recSearch(neighbor, time + 1, nodes));
        }

        int nodeVal = nodes[current]->val;
        int bobPasses = nodes[current]->bobPassingTime;
        if (bobPasses == time)
            nodeVal = nodeVal / 2;
        else if (bobPasses != -1 && bobPasses < time)
            nodeVal = 0;

        cout << "current node : " << current << " : " << nodeVal << " , "
             << maxVal << "\n";
        if (maxVal == INT_MIN)
            return nodeVal;
        return nodeVal + maxVal;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {

        unordered_map<int, Node*> nodes;

        for (auto edge : edges) {
            int a = edge[0];
            int b = edge[1];

            if (nodes[a] == nullptr) {
                Node* tempNode = new Node(amount[a]);
                nodes[a] = tempNode;
            }

            if (nodes[b] == nullptr) {
                Node* tempNode = new Node(amount[b]);
                nodes[b] = tempNode;
            }

            nodes[a]->next.push_back(b);
            nodes[b]->next.push_back(a);
        }

        initPres(0, nodes);
        bobTraverse(0, bob, nodes);

        return recSearch(0, 0, nodes);
    }
};