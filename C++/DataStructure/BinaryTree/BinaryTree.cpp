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

        int calculate_height(Node* element){
            if(element == nullptr){
                return -1;
            }
            int a = calculate_height(element->left);
            int b = calculate_height(element->right);
            if(a > b){
                return a + 1;
            }else{
                return b + 1;
            }
        }

    public:
        BinaryTree(){
            root = nullptr;
            height = 0;
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
            size = size + 1;
            if(root == nullptr){
                root = new Node(value);
                return;
            }
            while(curr != nullptr){
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
            height = calculate_height(root);
        }
    
        void clear(){
            delete root;
            root = nullptr;
            height = 0;
            size = 0;
        }

        void display(){
            std::queue<Node*> queue;
            queue.push(root);
            Node* curr = nullptr;
            while(!(queue.empty())){
                curr = queue.front();
                queue.pop();
                if(curr != nullptr){
                    queue.push(curr->left);
                    queue.push(curr->right);
                    std::cout << curr->val << " ";
                }
            }
            std::cout << std::endl;
        }

        int get_height(){
            return height;
        }
    };



int main(void){
    BinaryTree bin;
    bin.add_value(15);
    std::cout << bin.get_height() << std::endl;
    return 0;
}