#pragma once

#ifndef _ALPHA
#define _ALPHA
#include <iostream>
using namespace std;
class CBN{
    virtual void own_bvn()= 0;
};

class Bank : CBN{
    private:
    //     long long account_number;
    //     string account_name;
    //     string bank_name;
    //     string email;
    //     long long bvn;
    //     long long nin;
    //     long balance;
    //     int age;
    //     int pin;
    //     string DOB;
    //     string address;
    //     long long tel;
    //     bool verified = false;
    //     bool registered = false;
    public:
        Bank(long long BVN, string Bankname){};
        void set_age(int Age){};

        void set_NIN(int NiN){};

        long long get_bvn(){};

        bool Bank::check_registration(){};

        virtual void own_bvn(){};

        void set_pin(int PIN){};

        void deposit(long deposit){};

        long get_balance(){};

        void save_user(){};
};



#endif