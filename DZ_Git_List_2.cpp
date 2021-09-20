// DZ_Git_List_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    void add(int value) {            //добавление элемента в очередь
        Node* tmp = new Node(value);
        if (_p_head == nullptr) {
            _p_head = _p_tail = tmp;
        }
        else {
            _p_tail->next = tmp;
            _p_tail = tmp;
        }
    }
    void print_list() {  //вывод элементов
        Node* tmp_list = _p_head;
        while (tmp_list != nullptr) {
            cout << tmp_list->value << '\t';
            tmp_list = tmp_list->next;
        }
        cout << endl;
    }

    void remove_at() { //удаление элемента из очереди

        Node* tmp = _p_head;
        _p_head = _p_head->next;
        delete tmp;

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
    while (choice != 4)
    {
        cout << "Enter choice:\n1-Insert element in queue \n2-Remove element in queue\n3-Show elements\n4-Stop" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter element insert queue" << endl;
            cin >> insert_element;
            l.add(insert_element);
            break;
        case 2:
            l.remove_at();
            break;

        case 3:
            l.print_list();
            cout << endl;
            break;
        case 4:default:break;
        }
    }
}
