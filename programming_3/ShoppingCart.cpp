#include <iostream>
#include <vector>
#include <string>

#include "ShoppingCart.h"
#include "ItemToPurchase.h"

using namespace std;

ShoppingCart::ShoppingCart() {
    _customerName = "none";
    _currentDate = "January 1, 2016";
}
ShoppingCart::ShoppingCart(string name, string date) {
    _customerName = name;
    _currentDate = date;
}

string ShoppingCart::customerName() {
    return _customerName;
}
string ShoppingCart::date() {
    return _currentDate;
}

void ShoppingCart::addItem(ItemToPurchase myVal) {
    _cartItems.push_back(myVal);
}

void ShoppingCart::removeItem(string item) {
    int index = -1;
    for (unsigned int i = 0; i < _cartItems.size(); ++i) {
        if (item == _cartItems.at(i).name()) {
            index = i;
        }
    }
    for (unsigned int i = index; i < _cartItems.size() - 1; ++i) {
        _cartItems.at(i) = _cartItems.at(i + 1);
    }
    _cartItems.pop_back();
    if (index == -1) {
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}

void ShoppingCart::modifyItem(ItemToPurchase item) {
    int index = -1;
    string tempDescription;
    int temp;
    for (unsigned int i = 0; i < _cartItems.size(); ++i) {
        if (item.name() == _cartItems.at(i).name()) {
            index = i;
        }
    }

    if (index == -1) {
        cout << "Item not found in cart. Nothing modified." << endl;
    }
    else {
        if (item.description() != "none") {
            tempDescription = item.description();
            _cartItems.at(index).setDescription(tempDescription);
        }
        if (item.price() != 0) {
            temp = item.price();
            _cartItems.at(index).setPrice(temp);
        }
        if (item.quantity() != 0) {
            temp = item.quantity();
            _cartItems.at(index).setQuantity(temp);
        }
    }   

}

int ShoppingCart::numItemsInCart() {
    int sum = 0;
    for (unsigned int i = 0; i < _cartItems.size(); ++i) {
        sum += _cartItems.at(i).quantity();
    }
return sum;
}

int ShoppingCart::costOfCart() {
    int totalCost = 0;
    for (unsigned int i = 0; i < _cartItems.size(); ++i) {
        totalCost += _cartItems.at(i).quantity() * _cartItems.at(i).price();
    }
    return totalCost;
}

void ShoppingCart::printTotal() {
    cout << customerName() << "'s Shopping Cart - " << date() << endl;
    
    if (_cartItems.size() == 0) {
        cout << "Number of Items: 0" << endl << endl;
        cout << "SHOPPING CART IS EMPTY" << endl << endl;
    }
    else {
        cout << "Number of Items: " << numItemsInCart() << endl;
        cout << endl;
        for (unsigned int i = 0; i < _cartItems.size(); ++i) {
            _cartItems.at(i).printItemCost();
        }
        cout << endl;
    }

    cout << "Total: $" << costOfCart() << endl;
}

void ShoppingCart::printDescriptions() {
    if (_cartItems.size() == 0) {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    else {
        cout << customerName() << "'s Shopping Cart - " << date() << endl << endl;
        cout << "Item Descriptions" << endl;
        for (unsigned int i = 0; i < _cartItems.size(); ++i) {
            _cartItems.at(i).printItemDescription();
        }
    }
    
}
