#include <cassert>
#include "LinkedList.hpp"

void test_bool_equal(){
    LinkedList lst1;
    LinkedList lst2;
    
    lst1.addfirst(45);
    lst1.addfirst(90);

    assert(!(lst1 == lst2));
    assert(!(lst2 == lst1));

    lst2.addfirst(45);

    assert(!(lst2 == lst1));
    assert(!(lst1 == lst2));

    lst2.addfirst(90);
    assert(lst1 == lst2);
    assert(lst2 == lst1);
}

void test_fusion(){
    LinkedList lst1;
    LinkedList lst2;
    LinkedList res;

    lst1.addfirst(5);
    lst1.addfirst(4);
    lst1.addfirst(3);
    lst2.addfirst(6);
    res.addfirst(6);
    res.addlast(3);
    res.addlast(4);
    res.addlast(5);
    assert((lst2 + lst1) == res);

    res.clear();

    res.addfirst(5);
    res.addfirst(4);
    res.addfirst(3);
    res.addlast(6);
    assert((lst1 + lst2) == res);

    lst1.clear();
    lst2.clear();
    res.clear();

    lst1.addfirst(1);
    res.addfirst(1);
    assert(((lst1 + lst2) == res) && ((lst2 + lst1) == res));
}

void test_get_at(){
    LinkedList lst1;
    LinkedList lst2;
    
    lst1.addfirst(45);
    lst1.addfirst(90);
    lst1.addfirst(180);
    assert(lst1[0] == 180);
    //assert(lst1[2] == 45);
    lst2.addlast(0);
    assert(lst2[0] == 0);
}

void test_sort(){
    LinkedList lst;
    LinkedList res;
    lst.addfirst(10);
    res.addfirst(10);
    lst.sort();
    assert(lst == res);
    lst.addfirst(40);
    lst.addfirst(32);
    lst.addlast(45);
    lst.addlast(15);
    res.addlast(15);
    res.addlast(32);
    res.addlast(40);
    res.addlast(45);
    lst.sort();
    assert(lst == res);
    lst.clear();
    res.clear();
    lst.sort();
    assert(lst == res);
}

int main(void){
    test_fusion();
    test_bool_equal();
    test_get_at();
    test_sort();
    return 0;
}