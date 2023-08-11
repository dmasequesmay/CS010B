#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <iostream>
#include <string>
using namespace std;

class ItemToPurchase {
    public:
        ItemToPurchase();
        ItemToPurchase(const string n, const string d, const int p, const int q);
        void setName(string s);
        string name();
        void setPrice(int p);
        int price();
        void setQuantity(int q);
        int quantity();

        void setDescription(string s);
        string description();
        void printItemCost();
        void printItemDescription();
    private:
        string _name;
        int _price;
        int _quantity;
        string _description;
};

#endif