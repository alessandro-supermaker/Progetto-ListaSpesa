


#ifndef ITEM_H
#define ITEM_H

#include <string>

struct Item {
    std::string name;
    std::string category;
    int quantity;

    Item(const std::string& n, const std::string& c, int q)
        : name(n), category(c), quantity(q) {}

    std::string toString() const {
        return name + " (" + category + ", q: " + std::to_string(quantity) + ")";
    }
};

#endif
