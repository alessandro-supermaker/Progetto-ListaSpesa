//
// Created by Alessandro Del Vecchio on 14/01/26.
//

#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H

#include <vector>
#include <string>
#include "Observer.h"
#include "Item.h"

class ShoppingList {
private:
    std::string name;
    std::vector<Item> items;
    std::vector<Observer*> observers;

    int getTotalItems() const { return static_cast<int>(items.size()); }

public:

    explicit ShoppingList(const std::string& n);
    void addItem(const Item& item);
    void removeItem(size_t index);
    void attach(Observer* observer);
    void detach(Observer* observer);
    void notifyObservers();
    const std::vector<Item>& getItems() const { return items; }
    const std::string& getName() const { return name; }
};

#endif
