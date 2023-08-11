#include <iostream>
#include <cstdlib>
#include <string>

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

using namespace std;

void printMenu(ShoppingCart &sCart) {
    char userInput;
    string inputName;
    string inputDescription;
    int inputPrice;
    int inputQuantity;
    int trash = 0;
    ItemToPurchase myVal = ItemToPurchase();
    do {
        cout << "MENU" << endl;
        cout << "a - Add item to cart" << endl;
        cout << "d - Remove item from cart" << endl;
        cout << "c - Change item quantity" << endl;
        cout << "i - Output items' descriptions" << endl;
        cout << "o - Output shopping cart" << endl;
        cout << "q - Quit" << endl << endl;
        cout << "Choose an option: ";
        cin >> userInput;
        cout << endl;
        while ( (userInput != 'a') && (userInput != 'd') && (userInput != 'c') && (userInput != 'i') && (userInput != 'o') && (userInput != 'q') ) {
            cout << "Choose an option: ";
            cin >> userInput;
            cout << endl;
        }
        if (userInput == 'q') {
            exit(1);
        }
        if (userInput == 'a') {
            cout << endl << "ADD ITEM TO CART" << endl;
            cout << "Enter the item name: ";
            getline(cin,inputName);
            getline(cin,inputName);
            myVal.setName(inputName);
            cout << endl;
            cout << "Enter the item description: ";
            getline(cin,inputDescription);
            myVal.setDescription(inputDescription);
            cout << endl;
            cout << "Enter the item price: ";
            cin >> inputPrice;
            myVal.setPrice(inputPrice);
            cout << endl;
            cout << "Enter the item quantity: ";
            cin >> inputQuantity;
            myVal.setQuantity(inputQuantity);
            cout << endl;
            sCart.addItem(myVal);
        } else if (userInput == 'd') {
            cout << endl << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove: ";
            getline(cin,inputName);
            getline(cin,inputName);
            cout << endl;
            sCart.removeItem(inputName);
        } else if (userInput == 'c') {
            cout << endl << "CHANGE ITEM QUANTITY" << endl;
            cout << "Enter the item name: ";
            getline(cin,inputName);
            getline(cin,inputName);
            cout << endl;
            cout << "Enter the new quantity: ";
            cin >> inputQuantity;
            cout << endl;
            myVal.setName(inputName);
            myVal.setQuantity(inputQuantity);
            myVal.setPrice(trash);
            sCart.modifyItem(myVal);
        } else if (userInput == 'i') {
            cout << endl << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            sCart.printDescriptions();
        } else if (userInput == 'o') {
            cout << endl << "OUTPUT SHOPPING CART" << endl;
            sCart.printTotal();
        }

    cout << endl;

    } while (userInput != 'q');

}

int main () {

    string inputName;
    string inputDate;

    cout << "Enter customer's name: ";
    getline(cin, inputName);

    cout << endl;

    cout << "Enter today's date: ";
    getline(cin, inputDate);
    cout << endl << endl;

    cout << "Customer name: " << inputName << endl;
    cout << "Today's date: " << inputDate << endl << endl;;

    ShoppingCart sCart(inputName, inputDate);

    printMenu(sCart);


    ItemToPurchase test("Bottled Water", "Deer Park, 12 oz.", 1, 10);

    return 0;

}