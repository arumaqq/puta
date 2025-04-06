#include <iostream>
#include "libprod.h"
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cstdio>

using namespace std;

void Product::auto_code(){
    const char* frst = "460";
    int scnd = (rand() % 9 + 1) * 1000;
    int thrd = rand() % 1000000;
    sprintf(this->code, "%s%04d%06d", frst, scnd, thrd);
}

void Product::correcting(int pr, int am, double x, double y){
    if (pr<=0){
        this->price = 0;
    }
    if (am<0){
        this->amount = -1;
    }
    if (x<41 or x>82 or x==0){
        this->landlati = 0;
    }
    if (y<19 or y>169 or y==0){
        this->landlongi = 0;
    }
}
    

Product::Product(){
    auto_code();
    strcpy(this->name, "");
    this->price = 0;
    this->amount = 0;
    this->landlongi = 0;
    this->landlati = 0;
    correcting(this->price, this->amount, this->landlati, this->landlongi);
}

Product::Product(char name[50], int price, int amount, double landlongi, double landlati){
    auto_code();
    strcpy(this->name, name);
    this->price = price;
    this->amount = amount;
    this->landlongi = landlongi;
    this->landlati = landlati;
    correcting(this->price, this->amount, this->landlati, this->landlongi);
}

Product::Product(const Product &p){
    auto_code();
    strcpy(this->name, p.name);
    this->price = p.price;
    this->amount = p.amount;
    this->landlongi = p.landlongi;
    this->landlati = p.landlati;
    correcting(this->price, this->amount, this->landlati, this->landlongi);
}

Product::~Product(){}

const char *Product::get_code(){return this->code;}

void Product::set_name(const char *name) {
    strncpy(this->name, name, 49);
    this->name[49] = '\0';}
const char *Product::get_name(){return this->name;}

void Product::set_price(int price){this->price = price;}
int Product::get_price(){return this->price;}

void Product::set_amount(int amount){this->amount = amount;}
int Product::get_amount(){return this->amount;}

void Product::set_landlongi(double landlongi){this->landlongi = landlongi; correcting(this->price, this->amount, this->landlati, this->landlongi);}
double Product::get_landlongi(){return this->landlongi;}

void Product::set_landlati(double landlati){this->landlati = landlati; correcting(this->price, this->amount, this->landlati, this->landlongi);}
double Product::get_landlati(){return this->landlati;}

void Product::print(){
    cout<<"--- Product "<<get_code()<<" ---"<<endl;
    cout<<"Name: "<<get_name()<<endl;
    cout<<"Price: "<<get_price();
    if (this->price==0){
        cout<<"   /Warning: Correct price not specified";
    }
    cout<<endl;
    cout<<"Amount: "<<get_amount();
    if (this->amount==-1){
        cout<<"   /Warning: Correct quantity of product not specified";
    }
    cout<<endl;
    cout<<"Longitude: "<<get_landlongi();
    if (this->landlongi==0){
        cout<<"   /Warning: Correct longitude not specified. Longitude of Russia (19:169)";
    }
    cout<<endl;
    cout<<"Latitude: "<<get_landlati();
    if (this->landlati==0){
        cout<<"   /Warning: Correct latitude not specified. Latitude of Russia (41:82)";
    }
    cout<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
}
    