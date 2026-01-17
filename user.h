//
// Created by Alessandro Del Vecchio on 14/01/26.
//

#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Observer.h"
#include "ShoppingList.h"

class User : public Observer {
private:
    std::string name;
    std::vector<ShoppingList*> sharedLists;

public:
    explicit User(const std::string& n);
    void shareList(ShoppingList* list);
    void unshareList(ShoppingList* list);
    void update(const std::string& listName, int totalItems, const std::vector<Item>& items) override;
    const std::string& getName() const { return name; }
};

#endif
