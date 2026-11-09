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

        int get_height(){
            return height;
        }

        int get_size(){
            return size;
        }

        int get_max(){
            if(size == 0){
                throw std::out_of_range("Tree is empty");
            }
            Node* curr = root;
            while(curr->left != nullptr){
                curr = curr->left;
            }
            return curr->val;
        }

        int get_min(){
            if(size == 0){
                throw std::out_of_range("Tree is empty");
            }
            Node* curr = root;
            while(curr->right != nullptr){
                curr = curr->right;
            }
            return curr->val;
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
    std::cout << bin.get_max() << std::endl;
    std::cout << bin.get_min() << std::endl;
    return 0;
}