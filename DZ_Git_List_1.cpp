// DZ_Git_List_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct Node {
    Node* next = nullptr;
    int value;
    Node(int value = 0) : value(value) {}
};
class List {
public:
    List() : _p_head(nullptr), _p_tail(nullptr) {}
    ~List() {
        while (_p_head != nullptr) {
            Node* tmp = _p_head;
            _p_head = _p_head->next;
            delete tmp;
        }
    }
