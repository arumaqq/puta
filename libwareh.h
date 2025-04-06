#pragma once
#include "libprod.h"

enum type_warehouse{
    none = 0,
    centre = 1,
    west = 2,
    east = 3,
};

class Warehouse{
    private:
        static int h;
        char id[5];
        type_warehouse type;
        double longi;
        double lati;
        int max_p; //max of ALL products
        int all_p; //ALL products now
        int curr_p; //Unic products now
        int max_unic_prod; //max of unic products
        Product *list;
    public:
        void auto_id();
        void rulongilati(double x, double y);
        Warehouse();
        Warehouse(type_warehouse type, double longi, double lati, int max, int max_unic_prod);
        Warehouse(const Warehouse &w);
        ~Warehouse();

        void set_type(type_warehouse type);
        void set_longi(double longi);
        void set_lati(double lati);
        void set_max(int max_p);
        void set_all(int all_p);
        void set_curr(int curr_p);
        void set_max_unic(int max_unic_prod);

        const char *get_id();
        type_warehouse get_type();
        double get_longi();
        double get_lati();
        int get_max();
        int get_all();
        int get_curr();
        int get_max_unic();
        Product get_product(int pos);

        void printw();
        double calc_Manh(double landlongi, double landlati);

        void menu(int &opc);
        void insert_product();
        void print_products();
        int search_by_name();
        void delete_product();
};