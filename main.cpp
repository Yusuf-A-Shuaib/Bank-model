#include <iostream>
#include <fstream>

using namespace std;


class CBN{
    virtual void own_bvn()= 0;
};

class Bank : CBN{
    private:
        long account_number;
        string account_name;
        string bank_name;
        string email;
        string DOB;
        string address;
        int age;
        long bvn;
        long nin;
        long balance;
        int pin;
        long tel;
        bool verified = false;
        bool registered = false;
    public:
        Bank(long BVN, string Bankname){
            bvn = BVN;
            bank_name = Bankname;
        }
        void generate_account_number(){
            long generated;
            account_number = generated;
        }
        void set_name(string _name){
            account_name = _name;
        }
        void set_email(string _email){
            email = _email;
        }
        void set_dob(string _name){
            DOB = _name;
        }
        void set_address(string _address){
            address = _address;
        }
        void set_tel(long _tel){
            tel = _tel;
        }
        void set_age(int Age){
            if (Age < 18){
                cout << "You are not eligible to own a Bank account ";
            } else{
                age = Age;
            }
        }

        void assign_registration(){
            registered = true;
        }

        void set_NIN(int NiN){
            if (NiN < 11){
                cout << "You are not eligible to own a Bank account ";
            } else{
                nin = NiN;
            }
        }

        long get_bvn(){
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
                user << "Bank Name:-> " << bank_name << endl;
                user << "Account Name:-> " << account_name << endl;
                user << "Account Number:-> " << account_number << endl;
                user << "User Bvn:-> " << bvn << endl;
                user << "User Age:-> " << age << endl;
                user << "User D.O.B:-> " << DOB << endl;
                user << "User address:-> " << address << endl;
            }
            user.close();
        }
};

void account_form(Bank alpha){
    int form_age = 0;
    string form_name;
    string form_email;
    string form_dob;
    string form_address;
    long form_number;
    long form_NIN;

    if (alpha.check_registration()){
        cout << "You are already registered";
        return;
    }

    cout << "Enter your fullname:-> ";
    cin >> form_name;
    alpha.set_name(form_name);
    cout << "Successful!" << endl;
    system("cls");

    cout << "Enter a valid email address:-> ";
    cin >> form_email;
    alpha.set_email(form_email);
    cout << "Successful!" << endl;
    system("cls");

    cout << "Enter your date_of_birth:-> ";
    cin >> form_dob;
    alpha.set_dob(form_dob);
    cout << "Successful!" << endl;
    system("cls");

    cout << "Enter residential address:-> ";
    cin >> form_address;
    alpha.set_address(form_address);
    cout << "Successful!" << endl;
    system("cls");

    cout << "Enter telephone number:-> ";
    cin >> form_number;
    alpha.set_tel(form_number);
    cout << "Successful!" << endl;
    system("cls");

    cout << "Enter age:-> ";
    cin >> form_age;
    alpha.set_age(form_age);
    cout << "Successful!" << endl;
    system("cls");


    cout << "Enter your National identity number:-> ";
    cin >> form_NIN;
    alpha.set_NIN(form_NIN);
    cout << "Successful!" << endl;
    system("cls");

    alpha.generate_account_number();
    alpha.assign_registration();
    alpha.save_user();

    cout << "Your account have been registered successful!" << endl;

}

int main(){
    long bbv;
    Bank first(bbv, "First bank");

    account_form(first);
    return 0;
}