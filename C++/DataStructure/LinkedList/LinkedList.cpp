#include <iostream>
#include <utility>
#include "LinkedList.hpp"

Node::Node(int value){
            val = value;
            next = nullptr;
}

int& LinkedList::get_at(int k){
    if(k < 0 || k >= length){
        throw std::out_of_range("Index out range");
    }
    if(k == length - 1){
        return tail->val;
    }
    Node* curr = head;
    for(int i = 0; i < k; i++){
        curr = curr->next;
    }
    return curr->val;
}

const int& LinkedList::get_at(int k) const{
    if(k < 0 || k >= length){
        throw std::out_of_range("Index out range");
    }
    if(k == length - 1){
        return tail->val;
    }
    Node* curr = head;
    for(int i = 0; i < k; i++){
        curr = curr->next;
    }
    return curr->val;
}

LinkedList LinkedList::fusion(const LinkedList& other) const{
    LinkedList res;
    Node* curr = head;
    while(curr != nullptr){
        res.addlast(curr->val);
        curr = curr->next;
    }
    curr = other.head;
    while(curr != nullptr){
        res.addlast(curr->val);
        curr = curr->next;
    }
    return res;
}

LinkedList LinkedList::merge(const LinkedList& other) const{
    LinkedList res;
    Node* currThis = head;
    Node* currOther = other.head;
    while(currThis != nullptr && currOther != nullptr){
        if(currThis->val > currOther->val){
            res.addlast(currOther->val);
            currOther = currOther->next;
        }else{
            res.addlast(currThis->val);
            currThis = currThis->next;
        }
    }
    if(currThis == nullptr){
        currThis = currOther;
    }
    while(currThis != nullptr){
        res.addlast(currThis->val);
        currThis = currThis->next;
    }
    return res;
}

std::pair<LinkedList, LinkedList> LinkedList::split(){
    LinkedList left;
    LinkedList right;
    if (length == 0) {
        return {left, right};
    }
    int mid = length / 2;
    left.head = head;
    left.length = mid;
    Node* current = head;
    for (int i = 0; i < mid - 1; i++){
        current = current->next;
    }
    right.head = current->next;
    current->next = nullptr;
    left.tail = current;
    right.length = length - mid;
    right.tail = tail;
    while (right.tail != nullptr && right.tail->next != nullptr){
        right.tail = right.tail->next;
    }
    head = nullptr;
    tail = nullptr;
    length = 0;
    return {left, right};
}

void LinkedList::merge_sort() {
    if (length <= 1) {
        return;
    }

    auto [left, right] = split();

    left.merge_sort();
    right.merge_sort();

    *this = left.merge(right);
}

LinkedList::LinkedList(){
    head = nullptr;
    tail = nullptr;
    length = 0;
}

LinkedList::~LinkedList(){
    clear();
}

LinkedList::LinkedList(const LinkedList& other){
/*Function called when making a copy :
Linkedlist list1 = list2*/
    head = nullptr;
    tail = nullptr;
    length = 0;

    Node* curr = other.head;
    while(curr != nullptr){
        addlast(curr->val);
        curr = curr->next;
    }
}

LinkedList& LinkedList::operator=(const LinkedList& other){
/*Fonction appelé quand on fait l'opération list1 = list2 avec list1 et list2 des 
Linkdlist, fontion aussi avec plusieurs affectations : list1 = list2 = list3*/
    if(this == &other){
        return *this;
    }

    clear();

    Node* curr = other.head;

    while(curr != nullptr){
        addlast(curr->val);
        curr = curr->next;
    }

    return *this;
}

LinkedList::LinkedList(LinkedList&& other) noexcept {
    /*Equivalent de la copie constructeur mais en déplacement (std::move)*/
    head = other.head;
    tail = other.tail;
    length = other.length;

    other.head = nullptr;
    other.tail = nullptr;
    other.length = 0;
}

LinkedList& LinkedList::operator=(LinkedList&& other) noexcept {
    /*Fonction de déplacement list2 = std::move(list1), la liste 1 est effacé
    La liste2 est écrasé par les données de la liste1*/
    if(this != &other){
        clear();

        head = other.head;
        tail = other.tail;
        length = other.length;

        other.head = nullptr;
        other.tail = nullptr;
        other.length = 0;
    }
    return *this;
}

const int& LinkedList::operator[](int index) const {
    return get_at(index);
}

bool LinkedList::operator==(const LinkedList& other) const {
    if(length != other.length){
        return false;
    }
    Node* currThis = head;
    Node* currOther = other.head;
    while(currThis != nullptr){
        if(currThis->val != currOther->val){
            return false;
        }
        currThis = currThis->next;
        currOther = currOther->next;
    }
    return true;
}

bool LinkedList::operator!=(const LinkedList& other) const {
    return !(*this == other);
}

LinkedList LinkedList::operator+(const LinkedList& other) const{
    return this->fusion(other);
}

void LinkedList::addfirst(int val){
    Node* newNode = new Node(val);
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }
    length++;
}

void LinkedList::addlast(int val){
    Node* newNode = new Node(val);
    if(tail == nullptr){
        head = newNode;
        tail = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

void LinkedList::clear(){
            Node* curr = head;
            Node* tmp = nullptr;
            while(curr != nullptr){
                tmp = curr;
                curr = curr->next;
                delete tmp;
            }
            head = nullptr;
            tail = nullptr;
            length = 0;
        }

void LinkedList::reverse(){
    Node* prev = nullptr;
    Node* curr = head;
    Node* tmp = nullptr;
    tail = head;
    while(curr != nullptr){
        tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    head = prev;
}

void LinkedList::remove_at(int k){
    if(k < 0 || k >= length){
        throw std::out_of_range("Index out range");
    }
    if(k == 0){
        Node* tmp = head;
        head = head->next;
        delete tmp;
        return;
    }

    Node* prec = nullptr;
    Node* curr = head;

    for(int i = 0; i < k; i++){
        prec = curr;
        curr = curr->next;
    }
    prec->next = curr->next;
    delete curr;
    if(k == length - 1){
        tail = prec;
    }
    length--;
}

void LinkedList::insert_at(int k, int value){
    if(k < 0 || k > length){
        throw std::out_of_range("Index out range");
    }
    if(k == 0){
        addfirst(value);
        return;
    }
    Node* curr = head;
    k--;
    while(k > 0){
        curr = curr->next;
        k--;
    }
    Node* tmp = curr->next;
    Node* nouv = new Node(value);
    curr->next = nouv;
    nouv->next = tmp;
}

void LinkedList::set_at(int k, int value){
    if(k < 0 || k >= length){
        std::cout << "Index out of range" << std::endl;
        return;
    }
    Node* curr = head;
    while(k > 0){
        curr = curr->next;
        k--;
    }
    curr->val = value;
}

bool LinkedList::contains(int value) const{
    Node* curr = head;
    while(curr != nullptr){
        if(curr->val == value){
            return true;
        }
        curr = curr->next;
    }
    return false;
}

int LinkedList::index_of(int value) const{
    Node* curr = head;
    int index = 0;
    while(curr != nullptr){
        if(curr->val == value){
            return index;
        }
        curr = curr->next;
    }
    return -1;
}

void LinkedList::remove(int value){
    if(length == 0){
        std::cout << "Error : list is empty" << std::endl;
    }
    if(tail->val == value){
        pop_back();
        return;
    }else if(head->val == value){
        pop_front();
        return;
    }
    Node* prec = head;
    Node* curr = head->next;
    while(curr != nullptr){
        if(curr->val == value){
            prec->next = curr->next;
            delete curr;
            return;
        }
        prec = curr;
        curr = curr->next;
    }
    std::cout << "Error : element " << value << " is not in list" << std::endl;
}

int LinkedList::count(int value) const{
    int acc = 0;
    Node* curr = head;
    while(curr != nullptr){
        if(curr->val == value){
            acc += 1;
        }
        curr = curr->next;
    }
    return acc;
}

int LinkedList::get_head(){
    if(length > 0){
        return head->val;
    }else{
        std::cout << "Erreur, liste vide" << std::endl;
        return -1;
    }
}

int LinkedList::get_tail(){
    if(length > 0){
        return tail->val;
    }else{
        std::cout << "Erreur, liste vide" << std::endl;
        return -1;
    }
}

int LinkedList::get_size(){
    return length;
}

bool LinkedList::is_empty(){
    return length == 0;
}

void LinkedList::print(){
    Node* curr = head;
    while(curr != nullptr){
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int LinkedList::pop_front(){
    if(is_empty()){
       throw std::out_of_range("List is empty"); 
    }
    int res = head->val;
    Node* tmp = head;
    head = head->next;
    delete tmp;
    length--;
    return res;
}

int LinkedList::pop_back(){
    if(is_empty()){
        throw std::out_of_range("List is empty");
    }
    int res = tail->val;
    Node* curr = head;
    if(curr == tail){
        delete tail;
        delete head;
        head = nullptr;
        tail = nullptr;
        length--;
        return res;
    }
    while(curr->next != tail){
        curr = curr->next;
    }
    tail = curr;
    delete curr->next;
    curr->next = nullptr;
    length--;
    return res;
}

void LinkedList::sort(){
    merge_sort();
}
