//
// Created by Alessandro Del Vecchio on 14/01/26.
//
#include "ShoppingList.h"
#include <algorithm>

ShoppingList::ShoppingList(const std::string& n) : name(n) {}

void ShoppingList::addItem(const Item& item) {
    items.push_back(item);
    notifyObservers();
}

void ShoppingList::removeItem(size_t index) {
    if (index < items.size()) {
        items.erase(items.begin() + index);
        notifyObservers();
    }
}

void ShoppingList::attach(Observer* observer) {
    observers.push_back(observer);
}

void ShoppingList::detach(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void ShoppingList::notifyObservers() {
    for (Observer* obs : observers) {
        obs->update(name, getTotalItems(), items);
    }
}
