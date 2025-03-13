#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<iostream>
#include<string>

using namespace std;

class Customer
{
    private:
        string userName;//1
        string nrc;//2
        string email;//3
        string phoneNumber;//4

    public:
        Customer();
        virtual ~Customer();
//input
        void inputUserName_1(){
            cout<<"Enter User Name (Example : \"Ellie Stone\")\t   : ";
            getline(cin,userName);
        }

        void inputNRC_2(){
            cout<<"Enter NRC(Example : \"9/MYT(N)123456\")\t\t   : ";
            getline(cin,nrc);
        }

        void inputEmail_3(){
            cout<<"Enter email (Example : \"ellieStone@gmail.com\")\t   : ";
            getline(cin,email);
        }

        void inputPhoneNumber_4(){
            cout<<"Enter Phone Number (Example : \"234560987\")\t   : ";
            getline(cin,phoneNumber);
        }

//output
        string getUserName_1(){
            return userName;
        }

        string getNRC_2(){
            return nrc;
        }

        string getEmail_3(){
            return email;
        }

        string getPhoneNumber_4(){
            return phoneNumber;
        }
};

#endif // CUSTOMER_H
