#include <iostream>

class BinaryTree{
    private:
        int val;
        BinaryTree* left;
        BinaryTree* right;

    public:
        BinaryTree(int value){
            val = value;
            left = nullptr;
            right = nullptr;
        }
        ~BinaryTree(){
            delete left;
            delete right;
        }

        int get_val(){
            return val;
        }
        void set_right_node(int value){
            right = new BinaryTree(value);
        }

        void set_left_node(int value){
            left = new BinaryTree(value);
        }
};

int main(void){
    BinaryTree* tree = new BinaryTree(10);
    tree->set_left_node(5);
    std::cout << tree->get_val() << std::endl;

    delete tree;
    return 0;
}