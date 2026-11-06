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

        BinaryTree(const BinaryTree& other){
            val = other.get_val();
            if(other.left){
                left = new BinaryTree(*other.left);
            }else{
                left = nullptr;
            }
            if(other.right){
                right = new BinaryTree(*other.right);
            }else{
                right = nullptr;
            }
        }

        int get_val() const {
            return val;
        }

        void add_value(int value){
            if(value < val){
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