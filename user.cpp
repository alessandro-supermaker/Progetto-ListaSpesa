//
// Created by Alessandro Del Vecchio on 14/01/26.
//


#include "User.h"
#include <iostream>

User::User(const std::string& n) : name(n) {}

void User::shareList(ShoppingList* list) {
    list->attach(this);
    sharedLists.push_back(list);
}

void User::unshareList(ShoppingList* list) {
    list->detach(this);
    sharedLists.erase(std::remove(sharedLists.begin(), sharedLists.end(), list), sharedLists.end());
    std::cout << name << " ha smesso di seguire '" << list->getName() << "'\n";
}

void User::update(const std::string& listName, int totalItems, const std::vector<Item>& items) {
    std::cout << name << ": Lista '" << listName << "' aggiornata! Totale oggetti: " << totalItems << std::endl;
    for (const Item& item : items) {
        std::cout << "  - " << item.toString() << std::endl;
    }
    std::cout << std::endl;
}
