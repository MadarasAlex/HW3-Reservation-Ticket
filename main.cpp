#include <iostream>
#include <bits/stdc++.h>
#include "SkipList.h"
#include "Node.h"
using namespace std;
int main() {

    int selection=1,k=0;
    char current_name[20] = "";
    SkipList reservations(3, 0.5);
    while(selection)
        {
        std::cout << "\n_____________Menu_____________\n";
        std::cout << "\nSelect an option from below\n";
        std::cout << "\n> 1 : reserve a ticket";
        std::cout << "\n> 2 : cancel reservation";
        std::cout << "\n> 3 : check reservation";
        std::cout << "\n> 4 : display reservations";
        std::cout << "\n______________________________\n";

        std::cout << "\nYour selection :  ";
        std::cin>>selection;

        switch(selection){
            case 1:
                std::cout << "\nOption 1 : reserve a ticket\n";
                std::cout << "\nPlease input your name : ";
                std::cin>>current_name;
                reservations.insertElement(current_name);
                reservations.displayList();
                k++;
                break;

            case 2:
                std::cout << "\nOption 2 : cancel reservation\n";
                std::cout << "\nDelete the input name : ";
                std::cin>>current_name;
                reservations.deleteElement(current_name);
                reservations.displayList();


                break;

            case 3:
                std::cout << "\nOption 3 : check reservation\n";
                std::cout << "\nSearch : ";
                std::cin>>current_name;
                reservations.searchElement(current_name);
                break;

            case 4:
                std::cout << "\nOption 4 : display reservations\n";
                reservations.displayList();
                break;

            default:
                std::cout << "\nYour option is not on the list\nPlease try again\n";
                break;
            }
        }

    return 0;
}

