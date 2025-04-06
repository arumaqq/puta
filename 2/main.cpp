#include <iostream>
#include "libprod.h"
#include "libwareh.h"
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
    srand(time(0));
    int n;
    Product A("Banana", 30, 800, 44, 47);
    A.print();
    cout<<"-----------------------------------------------------------------------"<<endl;
    Product B = A;
    B.set_name("Orange");
    B.set_landlati(3); //->0 (outside Russia)
    B.print();


    cout<<endl<<"-------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------LIST OF WAREHOUSES---------------------------------------------"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
    int k,opc;
    Warehouse W1(centre, 58, 60, 60, 5);
    Warehouse W2(west, 45, 40, 90, 5);
    Warehouse W3 = W2;
    W3.set_type(east);
    W3.set_longi(81);
    W3.set_max(120);
    Warehouse warehs[3] = {W1, W2, W3};
    cout<<endl<<"||||||||||||||||||||||||||||||||||||#1||||||||||||||||||||||||||||||||||||"<<endl;
    W1.printw();
    cout<<endl<<"||||||||||||||||||||||||||||||||||||#2||||||||||||||||||||||||||||||||||||"<<endl;
    W2.printw();
    cout<<endl<<"||||||||||||||||||||||||||||||||||||#3||||||||||||||||||||||||||||||||||||"<<endl;
    W3.printw();
    cout<<"Choice a Warehouse (enter a number from 1 to 3): ";
    cin>>k;
    Warehouse W = warehs[k-1];
    cout<<W.calc_Manh(A.get_landlongi(), A.get_landlati())<<endl;

    do{
        W.menu(opc);        

        switch(opc){
            case 1:
                W.insert_product();
                break;
            case 2:
                W.print_products();
                break;
            case 3:
                int pos;
                pos = W.search_by_name();
                if(pos != -1){
                    W.get_product(pos).print();
                }else{
                    cout<<"Product not found!"<<endl;
                }
                break;
            case 4:
                W.delete_product();
                break;
            case 5:
                cout<<"Exit from program!"<<endl;
                break;
            default:
                cout<<"Invalid option!"<<endl;
        }
    }while(opc!=5);

    return 0;
}
