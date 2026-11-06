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

        void add_value(int value){
            if(value > val){
                if(left == nullptr){
                    left = new BinaryTree(value);
                }else{
                    left->add_value(value);
                }
            
            }else{
                if(right == nullptr){
                    right = new BinaryTree(value);
                }else{
                    right->add_value(value);
                }
            }
        }
    
};

int main(void){
    BinaryTree tree(10);
    return 0;
}