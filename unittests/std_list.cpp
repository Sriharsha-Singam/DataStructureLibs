//
// Created by Sriharsha Singam on 10/22/21.
//

#include <list>
#include <string>
#include <iostream>
#include <vector>

#define TEST_SIZE 10
std::string list_of_pointer[TEST_SIZE];
//doubly_linked_list * list_of_ddl_pointer[TEST_SIZE];

void create_list() {
    char test[] = "123456789101112";
    for (int i = 0; i < TEST_SIZE; i++) {
        list_of_pointer[i] = std::string("Hello World");
    }
}

void free_list() {
    for (int i = 0; i < TEST_SIZE; i++) {
        list_of_pointer[i].clear();
    }
}

int main() {

    create_list();

    std::vector<std::string> linked_list;
    for (auto item : linked_list)
        std::cout << item << std::endl;

    for (int i = 0; i < TEST_SIZE; i++) {
        linked_list.push_back(list_of_pointer[i]);
    }
//    std::list<std::string>::iterator ptr1 = linked_list.begin();
//    std::advance(ptr1, 2);
    std::cout << linked_list[2] << std::endl;

    for (auto item : linked_list)
        std::cout << item << std::endl;

//    linked_list.pop_front();

    for (auto item : linked_list)
        std::cout << item << std::endl;

    linked_list.clear();

    for (auto item : linked_list)
        std::cout << item << std::endl;

    return 0;
}