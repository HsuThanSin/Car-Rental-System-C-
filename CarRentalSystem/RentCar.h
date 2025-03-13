#ifndef RENTCAR_H
#define RENTCAR_H
#include<iostream>
#include <cstdlib> // Needed for rand() and srand()
#include <ctime>   // Needed for time()
#include<string>
using namespace std;
class RentCar
{
    private:
        string carPlateNumber;//1
        string nrc;//2
        string startDate;//3
        string strTotalDays;//4
        int totalDays;//4
        string strRentalPricePerDay;//5
        int rentalPricePerDay;//5
        int totalPrice;//6
        string orderNumber;//7


    public:
        RentCar();
        virtual ~RentCar();

    void inputCarPlateNumber_1(){
        cout<<"Enter Car Plate Number (Example format is \"SBA1234A\")       : ";
        getline(cin,carPlateNumber);
    }

    void inputNRC_2(){
        cout<<"Enter NRC(Example  \"9/MYT(N)123456\")                        : ";
        getline(cin,nrc);
    }

    void inputStartDate_3(){
        cout<<"Enter Start Date(Example  \"DD-MM-YYYY\")                     : ";
        getline(cin,startDate);
    }

    void inputTotalDays_4(){
        cout<<"Enter Total Days(Example  \"3\")                              : ";
        getline(cin,strTotalDays);
        try{
            totalDays=stoi(strTotalDays);
        }catch(...){
            cout << "You must input the Number only!\nTRY AGAIN!!\n";
            cout<<"Enter Total Days(Example  \"3\")                          : ";
            getline(cin,strTotalDays);
            totalDays=stoi(strTotalDays);
        }
    }

    void inputRentalPricePerDay_5(){
        cout<<"Enter Rental Price Per Day (Example format is \"100000\")     : ";
        getline(cin,strRentalPricePerDay);
        try{
            rentalPricePerDay=stoi(strRentalPricePerDay);
        }catch(...){
            cout << "You must input the Number only!\nTRY AGAIN!!\n";
            cout<<"Enter Rental Price Per Day (Example format is \"100000\") : ";
            getline(cin,strRentalPricePerDay);
            rentalPricePerDay=stoi(strRentalPricePerDay);
        }
    }

    void inputTotalPrice_6(){
        totalPrice=totalDays*rentalPricePerDay;
    }

    void inputOrderNumber_7(){
        orderNumber=randomNumber();
    }

    string randomNumber(){
        // Get a different random number each time the program runs
        srand(time(0));
        string s;
        // Generate a random number between 1 and 6
        for(int i=1;i<=6;i++){
            int randomNum = (rand() % 6)+1;
            s=s+to_string(randomNum);
        }
        s="R"+s;
        return s;
    }

    string getCarPlateNumber_1(){
        return carPlateNumber;
    }

    string getNRC_2(){
        return nrc;
    }

    string getStartDate_3(){
        return startDate;
    }

    int getTotalDays_4(){
        return totalDays;
    }

    int gettRentalPricePerDay_5(){
        return rentalPricePerDay;
    }

    int getTotalPrice_6(){
        return totalPrice;
    }

    string getOrderNumber_7(){
        return orderNumber;
    }
};

#endif // RENTCAR_H
