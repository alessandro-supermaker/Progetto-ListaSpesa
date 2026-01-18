//
// Created by Alessandro Del Vecchio on 14/01/26.
//
#include <iostream>
#include "User.h"
#include "ShoppingList.h"
#include "Item.h"

int main() {
    std::cout << "Progetto Laboratorio: Lista della Spesa con Observer" << std::endl;

    ShoppingList listaCasa("Lista Casa");
    ShoppingList listaSupermercato("Lista Supermercato");

    User alice("Alice");
    User bob("Bob");

    // Condividono liste
    alice.shareList(&listaCasa);
    bob.shareList(&listaCasa);
    alice.shareList(&listaSupermercato);
    bob.shareList(&listaSupermercato);

    // Aggiungi item
    listaCasa.addItem({"Latte", "Latticini", 2});
    listaCasa.addItem({"Pane", "Forno", 1});

    listaSupermercato.addItem({"Mele", "Frutta", 5});

    // Rimuovi
    listaCasa.removeItem(0);  // Rimuove Latte

    // Bob smette di seguire Supermercato
    bob.unshareList(&listaSupermercato);
    listaSupermercato.addItem({"Arance", "Frutta", 3});  // Solo Alice notificata

    return 0;
}
