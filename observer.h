//
// Created by Alessandro Del Vecchio on 14/01/26.
//

#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include <vector>
#include "Item.h"

class Observer {
public:
    virtual void update(const std::string& listName, int totalItems, const std::vector<Item>& items) = 0;
    virtual ~Observer() = default;
};

#endif
