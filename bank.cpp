#include <iostream>
#include <fstream>
#include "bank.hpp"

using namespace std;

class CBN{
    virtual void own_bvn()= 0;
};

class Bank : CBN{
    private:
        long long account_number;
        string account_name;
        string bank_name;
        string email;
        long long bvn;
        long long nin;
        long balance;
        int age;
        int pin;
        string DOB;
        string address;
        long long tel;
        bool verified = false;
        bool registered = false;
    public:
        Bank(long long BVN, string Bankname){
            bvn = BVN;
            bank_name = Bankname;
        }
        void set_age(int Age){
            if (Age < 18){
                cout << "You are not eligible to own a Bank account ";
            } else{
                age = Age;
            }
        }

        void set_NIN(int NiN){
            if (NiN < 11){
                cout << "You are not eligible to own a Bank account ";
            } else{
                nin = NiN;
            }
        }

        long long get_bvn(){
            return bvn;
        }

        bool check_registration(){
            return registered;
        }

        virtual void own_bvn(){
        };

        void set_pin(int PIN){
            if (PIN >= 10000 || PIN < 999){
                cout << "Invalid pin!";
            } else {
                pin = PIN;
            }
        }

        void deposit(long deposit){
            balance = balance + deposit;
        }

        long get_balance(){
            return balance;
        }

        void save_user(){
            fstream user;
            user.open("CBN.txt", ios::out);
            if (user.is_open()){
                user << account_name << endl;
                user << account_number << endl;
                user << bvn << endl;
                user << age << endl;
                user << DOB << endl;
                user << address << endl;
            }
            user.close();
        }
};
