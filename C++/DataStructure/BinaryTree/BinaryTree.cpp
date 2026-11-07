#include <iostream>

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

    public:
        BinaryTree(){
            root = nullptr;
            height = 0;
            size = 0;
        }

        ~BinaryTree(){
            delete root;
        }
/*
        BinaryTree(const BinaryTree& other){
            
        }

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
            while(curr != nullptr){
                prec = curr;
                if(value < curr->val){
                    curr = curr->right;
                }else{
                    curr = curr->left;
                }
            }
            if(value < curr->val){
                prec->right = new Node(value);
            }else{
                prec->left = new Node(value);
            }
        }
    
        void clear(){
            delete root;
            root = nullptr;
        }
};



int main(void){
    return 0;
}