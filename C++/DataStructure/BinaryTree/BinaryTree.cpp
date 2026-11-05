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
        int get_val(){
            return val;
        }
};

int main(void){
    BinaryTree tree(1);
    std::cout << tree.get_val() << std::endl;
    return 0;
}