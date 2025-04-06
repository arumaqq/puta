#include <iostream>
#include "libwareh.h"
#include <cstring>
#include <cmath>

using namespace std;

int Warehouse::h = 100;

void Warehouse::auto_id(){
    sprintf(id, "W%03d", h);
    h++;
}

void Warehouse::rulongilati(double x, double y){
    if (x<41 || x>82){
        this->longi = 0;
    }
    if (y<19 || y>169){
        this->lati = 0;
    }
}

Warehouse::Warehouse(){
    auto_id();
    this->type = none;
    this->longi = 0;
    this->lati = 0;
    this->max_p = 0;
    this->all_p = 0;
    this->curr_p = 0;
    this->max_unic_prod = 0;
    this->list = nullptr;
    rulongilati(this->lati, this->longi);
}

Warehouse::Warehouse(type_warehouse type, double longi, double lati, int max_p, int max_unic_prod){
    auto_id();
    this->type = type;
    this->longi = longi;
    this->lati = lati;
    this->max_p = max_p; 
    this->all_p = 0;
    this->curr_p = 0;
    this->max_unic_prod = max_unic_prod;
    this->list = new Product[max_unic_prod];
    rulongilati(this->lati, this->longi);
}

Warehouse::Warehouse(const Warehouse &w){
    auto_id();
    this->type = w.type;
    this->longi = w.longi;
    this->lati = w.lati;
    this->max_p = w.max_p;
    this->all_p = w.all_p;
    this->curr_p = w.curr_p;
    this->max_unic_prod = w.max_unic_prod;
    this->list = new Product[w.max_unic_prod];
    rulongilati(this->longi, this->lati);

    for (int i=0; i<w.curr_p; i++){
        this->list[i] = w.list[i];
    }
}

Warehouse::~Warehouse(){
    delete[] this->list;
    this->list[this->curr_p] = Product();
}

void Warehouse::set_type(type_warehouse type){this->type = type;}
void Warehouse::set_longi(double longi){this->longi = longi;}
void Warehouse::set_lati(double lati){this->lati = lati;}
void Warehouse::set_max(int max_p){this->max_p = max_p;}
void Warehouse::set_all(int all_p){this->all_p = all_p;}
void Warehouse::set_curr(int curr_p){this->curr_p = curr_p;}
void Warehouse::set_max_unic(int max_unic_prod){this->max_unic_prod = max_unic_prod;}

const char *Warehouse::get_id(){return this->id;}
type_warehouse Warehouse::get_type(){return this->type;}
double Warehouse::get_longi(){return this->longi;}
double Warehouse::get_lati(){return this->lati;}
int Warehouse::get_max(){return this->max_p;}
int Warehouse::get_all(){return this->all_p;}
int Warehouse::get_curr(){return this->curr_p;}
int Warehouse::get_max_unic(){return this->max_unic_prod;}
Product Warehouse::get_product(int pos){return this->list[pos];}

void Warehouse::printw(){
    cout<<"--- Warehouse "<<get_id()<<" ---"<<endl;
    cout<<"Type: "<<get_type();
    if (this->type==none){
        cout<<"   /Warning: Correct type not specified";
    }
    cout<<endl;
    cout<<"Longitude: "<<get_longi();
    if (this->longi==0){
        cout<<"   /Warning: Correct longitude not specified. Longitude of Russia (41:82)";
    }
    cout<<endl;
    cout<<"Latitude: "<<get_lati();
    if (this->lati==0){
        cout<<"   /Warning: Correct latitude not specified. Latitude of Russia (19:169)";
    }
    cout<<endl;
    cout<<"Max of ALL products: "<<get_max()<<endl;
    cout<<"Max of UNIC products: "<<get_max_unic()<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
}


double Warehouse::calc_Manh(double landlongi, double landlati) {
    cout << "Warehouse coordinates: (" << this->longi << ", " << this->lati << ")" << endl;
    cout << "Product coordinates: (" << landlongi << ", " << landlati << ")" << endl;
    if(landlongi == 0 || landlati == 0 || this->longi == 0 || this->lati == 0){
        cout << "The coordinates are set incorrectly (outside Russia) - please double check the coordinates!"<<endl;
        cout << "Manhatten distance: ";
        return 0;
    }
    else{
        cout << "Manhatten distance: ";
        return (abs(this->longi - landlongi) + abs(this->lati - landlati));
    }
}

void Warehouse::menu(int &opc){
    cout<<left;
    cout<<"-|--------------------|-"<<endl;
    cout<<" |  MENU OF PRODUCTS  | "<<endl;
    cout<<"-|--------------------|-"<<endl;
    cout<<"[1]. Insert product"<<endl;
    cout<<"[2]. Print list of products"<<endl;
    cout<<"[3]. Search product by name"<<endl;
    cout<<"[4]. Delete product"<<endl;
    cout<<"[5]. Exit"<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"Enter option: "; cin>>opc;
}

void Warehouse::insert_product(){
    if (curr_p >= max_unic_prod) {
        cout << "Error: Warehouse is full (no space for new types of products)! Max: " <<get_max_unic()<< endl;
        return;
    }
    cout<<"Insert new product..."<<endl;
    this->list[this->curr_p].auto_code();
    cout<<"Name: ";
        char name[50];
        cin >> name;
        this->list[this->curr_p].set_name(name);
    
    do
    {cout<<"Price: "; 
        int price;
        cin >> price;
        this->list[this->curr_p].set_price(price);

        if(this->list[this->curr_p].get_price()<=0)
        {cout<<"Correct price not specified"<<endl;}
    }
    while(this->list[this->curr_p].get_price()<=0);



    do
    {cout<<"Amount: ";
        int amount;
        cin >> amount;
        this->list[this->curr_p].set_amount(amount);
        if (this->list[this->curr_p].get_amount()<0)
        {cout<<"Correct quantity of product not specified"<<endl;}
        if ((this->all_p + this->list[this->curr_p].get_amount()) > this->max_p)
        {cout<<"The warehouse can't hold that much. Max products: "<<this->max_p<<". Current number of products: "<<this->all_p<<endl;}
    }
    while((this->list[this->curr_p].get_amount()<0) || ((this->all_p + this->list[this->curr_p].get_amount()) > this->max_p));
    

    do
    {cout<<"Longitude: "; 
        double longi;
        cin >> longi;
        this->list[this->curr_p].set_landlongi(longi);
        if((this->list[this->curr_p].get_landlongi()<19) || (this->list[this->curr_p].get_landlongi()>169))
        {cout<<"Correct longitude not specified. Longitude of Russia (19:169)"<<endl;}
    }
    while((this->list[this->curr_p].get_landlongi()<19) || (this->list[this->curr_p].get_landlongi()>169));
        

    do
    {cout<<"Latitude: "; 
        double lati;
        cin >> lati;
        this->list[this->curr_p].set_landlati(lati);
        if((this->list[this->curr_p].get_landlati()<41) || (this->list[this->curr_p].get_landlati()>82))
        {cout<<"Correct latitude not specified. Latitude of Russia (41:82)"<<endl;}
    }
    while((this->list[this->curr_p].get_landlati()<41) || (this->list[this->curr_p].get_landlati()>82));

    this->all_p += this->list[this->curr_p].get_amount();
    this->set_all(this->all_p);
    this->curr_p++;
    this->set_curr(this->curr_p);


    cout<<"Success! Product added!"<<endl;
}

void Warehouse::print_products(){
    cout<<"-----------------------------------------------------------------------"<<endl;
    for(int i=0; i<get_curr(); i++){
        this->list[i].print();
    }
}

int Warehouse::search_by_name(){
    int pos;
    char name[50];
    cout<<"Search Name: "; cin>>name;

    for(int i=0; i<get_curr(); i++){
        if(strcmp(this->list[i].get_name(), name) == 0){
            pos = i;
            return pos;
        }
    }

    return -1;
}

void Warehouse::delete_product(){
    int pos;
    pos = this->search_by_name();

    if(pos!= -1)
    {
        this->all_p -= this->list[pos].get_amount();
        this->set_all(this->all_p);

        for(int i=pos; i<this->curr_p-1; i++)
            this->list[i] = this->list[i+1];  
        
        this->curr_p--;
        this->set_curr(this->curr_p);
        cout<<"Product deleted!"<<endl;
    }
    else
    {cout<<"Product not found!"<<endl;}
}