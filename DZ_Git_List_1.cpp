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
    void add(int value) {
        Node* tmp = new Node(value);
        if (_p_head == nullptr) {
            _p_head = _p_tail = tmp;
        }
        else {
            _p_tail->next = tmp;
            _p_tail = tmp;
        }
    }
    void print_list() {
        Node* tmp_list = _p_head;
        while (tmp_list != nullptr) {
            cout << tmp_list->value << '\t';
            tmp_list = tmp_list->next;
        }
        cout << endl;
    }
    void insert(int value, int index) {
        Node* new_node = new Node(value);
        if (index == 0) {
            new_node->next = _p_head;
            _p_head = new_node;
        }
        else {
            Node* tmp = _p_head;
            for (auto i = 0; i < index - 1; i++) {
                tmp = tmp->next;
            }
            new_node->next = tmp->next;
            tmp->next = new_node;
        }
    }
    void remove_at(int index) {
        if (index == 0) {
            Node* tmp = _p_head;
            _p_head = _p_head->next;
            delete tmp;
        }
        else {
            Node* tmp = _p_head;
            for (auto i = 0; i < index - 1; i++) {
                tmp = tmp->next;
            }
            Node* tmp_remove = tmp->next;
            tmp->next = tmp_remove->next;
            delete tmp_remove;
        }
    }
    int find_index(int value) {
        Node* tmp = _p_head;
        for (auto i = 0; tmp != nullptr; i++) {
            if (tmp->value != value) {
                tmp = tmp->next;
            }
            else {
                return i;
            }
        }
        return -1;
    }
private:
    Node* _p_head;
    Node* _p_tail;
};
int main() {
    List l;
    l.add(1);
    l.add(2);
    l.add(3);
    l.add(4);
    l.add(5);
    l.print_list();

    int choice = 0;
    int insert_element = 0;
    int insert_index_element = 0;
    int remove_element = 0;
    int find_element;
    while (choice != 5)
    {
        cout << "Enter choice:\n1-Insert element\n2-Remove element\n3-Find element\n4-Show elements\n5-Stop" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter number element insert" << endl;
            cin >> insert_index_element;
            cout << "Enter element insert" << endl;
            cin >> insert_element;
            l.insert(insert_element, insert_index_element);
            break;
        case 2:
            cout << "Enter number element remove" << endl;
            cin >> remove_element;
            l.remove_at(remove_element);
            break;
        case 3:
            cout << "Enter number whant find" << endl;
            cin >> find_element;
            cout << l.find_index(find_element) << endl;
            break;
        case 4:
            l.print_list();
            cout << endl;
            break;
        case 5:default:break;
        }
    }
}

