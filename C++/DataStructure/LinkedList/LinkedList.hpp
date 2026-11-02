#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <utility>

class Node{
    private:
        int val;
        Node* next;
    
    friend class LinkedList;

    public:
        Node(int value);
};

class LinkedList{
    private:
        Node* head;
        Node* tail;
        int length;

        int& get_at(int k);
        const int& get_at(int k) const;
        LinkedList fusion(const LinkedList& other) const;

        LinkedList merge(const LinkedList& other) const;
        std::pair<LinkedList, LinkedList> split();
        void merge_sort();
    
    public:
        LinkedList();
        ~LinkedList();

        LinkedList(const LinkedList& other);
        LinkedList& operator=(const LinkedList& other);

        LinkedList(LinkedList&& other) noexcept;
        LinkedList& operator=(LinkedList&& other) noexcept;

        const int& operator[](int index) const;
        bool operator==(const LinkedList& other) const;
        bool operator!=(const LinkedList& other) const;
        LinkedList operator+(const LinkedList& other) const;

        void addfirst(int val);
        void addlast(int val);
        void clear();
        void reverse();

        void remove_at(int k);
        void insert_at(int k, int value);
        void set_at(int index, int value);

        bool contains(int value) const;
        int index_of(int value) const;

        void remove(int value);
        int count(int value) const;

        int get_head();
        int get_tail();
        int get_size();
        bool is_empty();
        void print();

        int pop_front();
        int pop_back();
        

        void sort();
    };

#endif