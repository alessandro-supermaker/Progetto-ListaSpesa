//
// Created by Alessandro Del Vecchio on 17/01/26.
//
#include <gtest/gtest.h>
#include "Item.h"
#include "ShoppingList.h"
#include "User.h"

TEST(ItemTest, Constructor) {
    Item item("Latte", "Latticini", 2);
    EXPECT_EQ(item.name, "Latte");
}

TEST(ShoppingListTest, AddRemove) {
    ShoppingList lista("Test");
    Item latte("Latte", "Latticini", 2);
    lista.addItem(latte);
    EXPECT_EQ(lista.getItems().size(), 1);
    lista.removeItem(0);
    EXPECT_EQ(lista.getItems().size(), 0);
}

TEST(UserTest, Share) {
    ShoppingList lista("Test");
    User alice("Alice");
    alice.shareList(&lista);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
