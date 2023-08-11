#include <iostream>

#include "ItemToPurchase.h"
#include <string>

using namespace std;

ItemToPurchase::ItemToPurchase() {
    _name = "none";
    _description = "none";
    _price = 0;
    _quantity = 0;
}

ItemToPurchase::ItemToPurchase(const string n, const string d, const int p, const int q) {
    _name = n;
    _description = d;
    _price = p;
    _quantity = q;
}

void ItemToPurchase::setName(string s) {
    _name = s;
}
string ItemToPurchase::name() {
    return _name;
}
void ItemToPurchase::setPrice(int p) {
    _price = p;
}
int ItemToPurchase::price() {
    return _price;
}
void ItemToPurchase::setQuantity(int q) {
    _quantity = q;
}
int ItemToPurchase::quantity() {
    return _quantity;
}
void ItemToPurchase::setDescription(string s) {
    _description = s;
}
string ItemToPurchase::description() {
    return _description;
}

void ItemToPurchase::printItemCost() {
    cout << name() << " " << quantity() << " @ $" << price() << " = $" << quantity() * price() << endl;
}

void ItemToPurchase::printItemDescription() {
    cout << name() << ": " << description() << endl;
}
