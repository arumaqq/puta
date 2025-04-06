#pragma once

class Product{
    private:
        char code[14];
        char name[50];
        int price;
        int amount;
        double landlongi;
        double landlati;
    public:
        void auto_code();
        void correcting(int pr, int am, double x, double y);
        Product();
        Product(char name[50], int price, int amount, double landlongi, double landlati);
        Product(const Product &p);
        ~Product();
        const char *get_code();
        void set_name(const char *name);
        const char* get_name();
        void set_price(int price);
        int get_price();
        void set_amount(int amount);
        int get_amount();
        void set_landlongi(double landlongi);
        double get_landlongi();
        void set_landlati(double landlati);
        double get_landlati();
        void print();
};