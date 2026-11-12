#include <cassert>
#include <iostream>
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

void test_get_size(){
    LinkedList lst;
    lst.addlast(100);
    lst.addfirst(50);
    lst.addfirst(25);
    assert(lst.get_size() == 3);
    lst.insert_at(2, 15);
    lst.insert_at(2, 10);
    assert(lst.get_size() == 5);
    lst.remove_at(2);
    lst.remove_at(0);
    lst.remove_at(1);
    assert(lst.get_size() == 2);
    lst.remove_at(0);
    lst.remove_at(0);
    assert(lst.get_size() == 0);
    lst.clear();
    assert(lst.get_size() == 0);
}

void test_get_at(){
    LinkedList lst1;
    LinkedList lst2;
    
    lst1.addfirst(45);
    lst1.addfirst(90);
    lst1.addfirst(180);
    assert(lst1[1] == 90);
    lst2.addlast(0);
    assert(lst2[0] == 0);
}

void test_remove_at(){
    LinkedList lst1;
    LinkedList lst2;
    LinkedList res;
    res.addfirst(180);
    res.addlast(45);
    
    lst1.addfirst(45);
    lst1.addfirst(90);
    lst1.addfirst(180);
    lst1.remove_at(1);
    assert(lst1 == res);
    lst2.addlast(0);
    lst2.remove_at(0);
    res.clear();
    assert(lst2 == res);
}

void test_insert_at(){
    LinkedList lst1;
    LinkedList lst2;
    LinkedList res;
    res.addfirst(180);
    res.addlast(45);
    res.addfirst(90);
    lst1.addfirst(45);
    lst1.addfirst(90);
    lst1.insert_at(1, 180);
    assert(lst1 == res);
    lst2.insert_at(0, 10);
    res.clear();
    res.addfirst(10);
    assert(lst2 == res);
}

void test_remove(){
    LinkedList lst1;
    LinkedList lst2;
    LinkedList res;
    res.addfirst(180);
    res.addlast(45);
    lst1.addfirst(180);
    lst1.addfirst(45);
    lst1.addfirst(90);
    lst1.remove(90);
    assert(lst1 == res);
    lst2.addfirst(10);
    lst2.addfirst(20);
    lst2.addlast(14);
    lst2.remove(25);
    res.clear();
    res.addfirst(10);
    res.addfirst(20);
    res.addlast(14);
    assert(lst2 == res);
}

void test_count(){
    LinkedList lst;
    lst.addfirst(25);
    lst.addfirst(20);
    lst.addlast(10);
    lst.addfirst(35);
    lst.addfirst(5);
    lst.addlast(10);
    lst.addfirst(35);
    lst.addlast(35);
    assert(lst.count(10) == 2);
    assert(lst.count(35) == 3);
    lst.clear();
    assert(lst.count(20) == 0);
    assert(lst.count(1) == 0);
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
    test_bool_equal();
    test_get_size();
    test_get_at();    
    test_remove_at();
    test_insert_at();
    test_count();
    test_fusion();
    test_sort();
    std::cout << "Tous les tests ont reussis" << std::endl;
    return 0;
}