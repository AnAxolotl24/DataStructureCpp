#include <iostream>
#include <queue>

class Node{
    private:
        int val;
        Node* left;
        Node* right;

    friend class BinaryTree;

    public:
        Node(int value){
            val = value;
            left = nullptr;
            right = nullptr;
        }
        ~Node(){
            delete left;
            delete right;
        }
};

class BinaryTree{
    private:
        Node* root;
        int height;
        int size;

        void print_n_spaces(int n){
            for(int i = 0; i < n; i++){
                std::cout << "  ";
            }
        }

    public:
        BinaryTree(){
            root = nullptr;
            height = -1;
            size = 0;
        }

        ~BinaryTree(){
            delete root;
        }

        BinaryTree(const BinaryTree& other){
            size = 0;
            height = other.height;
            root = nullptr;
            std::queue<Node*> queue;
            queue.push(other.root);
            Node* curr = nullptr;
            while(!(queue.empty())){
                curr = queue.front();
                queue.pop();
                if(curr != nullptr){
                    queue.push(curr->left);
                    queue.push(curr->right);
                    add_value(curr->val);
                    
                }
            }
        }
/*

        BinaryTree& operator=(BinaryTree&& other) noexcept {
            if(this != &other){
                clear();

                val = other.val;
                left = other.left;
                right = other.right;


                other.right = nullptr;
                other.left = nullptr;

            }
            return *this;
        }
*/

        void add_value(int value){
            Node* curr = root;
            Node* prec = nullptr;
            int curr_height = 0;
            size = size + 1;
            if(root == nullptr){
                root = new Node(value);
                height = curr_height;
                return;
            }
            while(curr != nullptr){
                curr_height++;
                prec = curr;
                if(value < curr->val){
                    curr = curr->right;
                }else{
                    curr = curr->left;
                }
            }
            if(value < prec->val){
                prec->right = new Node(value);
            }else{
                prec->left = new Node(value);
            }
            height = curr_height;
        }
    
        bool search(int value){
            Node* curr = root;
            while(curr != nullptr){
                if(curr->val == value){
                    return true;
                }
                if(value < curr->val){
                    curr = curr->right;
                }else{
                    curr = curr->left;
                }
            }
            return false;
        }

        void clear(){
            delete root;
            root = nullptr;
            height = 0;
            size = 0;
        }

        void display(){
            std::queue<Node*> queue1;
            std::queue<Node*> queue2;
            int height = 1;
            int spaces = 16;
            std::swap(queue1, queue2);
            queue1.push(root);
            Node* curr = nullptr;
            while(!(queue1.empty() && queue2.empty())){
                if(queue1.empty()){
                    std::swap(queue1, queue2);
                    height = height*2;
                    std::cout << std::endl;
                }
                curr = queue1.front();
                queue1.pop();
                if(curr != nullptr){
                    queue2.push(curr->left);
                    queue2.push(curr->right);
                    print_n_spaces(spaces/height);
                    std::cout << curr->val << " ";
                    print_n_spaces(spaces/height);
                }
            }
            std::cout << std::endl;
        }

        bool is_empty() const{
            return size == 0;
        }

        int get_height() const{
            return height;
        }

        int get_size() const{
            return size;
        }

        int get_root() const{
            if(!(is_empty())){
                return root->val;
            }
            throw std::out_of_range("Tree is empty");
        }

        int get_max() const{
            if(size == 0){
                throw std::out_of_range("Tree is empty");
            }
            Node* curr = root;
            while(curr->left != nullptr){
                curr = curr->left;
            }
            return curr->val;
        }

        int get_min() const{
            if(size == 0){
                throw std::out_of_range("Tree is empty");
            }
            Node* curr = root;
            while(curr->right != nullptr){
                curr = curr->right;
            }
            return curr->val;
        }

        int count_leaves() const{
            int res = 0;
            std::queue<Node*> q;
            Node* curr = nullptr;
            q.push(root);
            while(!(q.empty())){
                curr = q.front();
                q.pop();
                if(!(curr == nullptr)){
                    if(curr->right == nullptr && curr->left == nullptr){
                        res++;
                    }else{
                        q.push(curr->right);
                        q.push(curr->left);
                    }
                }
            }
            return res;
        }

        int count_internal_nodes() const{
            return size - count_leaves();
        }

        int count_nodes_at_level(int n){
            if(n > height){
                return 0;
            }
            int stage = 0;
            int res = 0;
            std::queue<Node*> q1;
            std::queue<Node*> q2;
            Node* curr = nullptr;
            q1.push(root);
            while(!(q1.empty() && q2.empty())){
                if(q1.empty()){
                    if(stage == n){
                        return res;
                    }
                    std::swap(q1, q2);
                    stage = stage + 1;
                }
                curr = q1.front();
                q1.pop();
                if(!(curr == nullptr)){
                    if(stage == n){
                        res++;
                    }
                    q2.push(curr->left);
                    q2.push(curr->right);
                }
            }
            return res;
        }
    
        bool is_full(){
            if(is_empty()){
                return true;
            }
            std::queue<Node*> q;
            Node* curr = nullptr;
            q.push(root);
            while(!q.empty()){
                curr = q.front();
                q.pop();
                if(curr != nullptr){
                    q.push(curr->right);
                    q.push(curr->left);
                    if((curr->left == nullptr && curr->right != nullptr)){
                        return false;
                    }else if(curr->left != nullptr && curr->right == nullptr){
                        return false;
                    }
                }
            }
            return true;
        }
    
        int get_level(int value){
            int stage = 0;
            Node* curr = root;
            while(curr != nullptr){
                if(value == curr->val){
                    return stage;
                }
                if(value < curr->val){
                    curr = curr->right;
                    stage++;
                }else{
                    curr = curr->left;
                    stage++;
                }
            }
            return -1;
        }
    };



int main(void){
    BinaryTree bin;
    bin.add_value(25);
    bin.add_value(35);
    bin.add_value(30);
    bin.add_value(50);
    bin.add_value(15);
    bin.add_value(20);
    bin.add_value(10);
    bin.display();
    std::cout << bin.get_level(10) << std::endl;
    return 0;
}