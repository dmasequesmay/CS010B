#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <iostream>
#include <vector>
#include <string>

#include "ItemToPurchase.h"

using namespace std;

class ShoppingCart {
    public:
        ShoppingCart();
        ShoppingCart(string name, string date);
        string customerName();
        string date();
        void addItem(ItemToPurchase myVal);
        void removeItem(string item);
        void modifyItem(ItemToPurchase item);
        int numItemsInCart();
        int costOfCart();
        void printTotal();
        void printDescriptions();
    private:
        string _customerName;
        string _currentDate;
        vector<ItemToPurchase> _cartItems;
};

#endif