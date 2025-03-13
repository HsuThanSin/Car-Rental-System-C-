#ifndef CARCLASS_H
#define CARCLASS_H
#include<iostream>
#include<string>
using namespace std;

class CarClass
{
    private:
        string carPlateNumber;//1
        string carName;//2
        string carModel;//3
        string carCapacity;//4
        string engineCapacity;//5
        string colour;//6
        string carOwner;//7

    public:
        CarClass();
        virtual ~CarClass();
//input
    void inputCarPlateNumber_1(){
        cout<<"Enter Car Plate Number (Example format is \"SBA1234A\")\t   : ";
        getline(cin,carPlateNumber);
    }

    void inputCarName_2(){
        cout<<"Enter Car Name (Example format is \"KIA Sportage\")\t   : ";
        getline(cin,carName);
    }

    void inputCarModel_3(){
        cout<<"Enter Car Model (Example format is \"Manual or Auto\")\t   : ";
        getline(cin,carModel);
    }

    void inputCarCapacity_4(){
        cout<<"Enter Car Capacity (Example format is \"5 Seats\")\t   : ";
        getline(cin,carCapacity);
    }

    void inputEngineCapacity_5(){
        cout<<"Enter Engine Capacity (Example format is \"2.4\")\t\t   : ";
        getline(cin,engineCapacity);
    }

    void inputColour_6(){
        cout<<"Enter Car Color (Example format is \"Grey\")\t\t   : ";
        getline(cin,colour);
    }

    void inputcarOwner_7(){
        cout<<"Enter Car Owner Name (Example format is \"Land Rover\")\t   : ";
        getline(cin,carOwner);
    }

//output
   string getCarPlateNumber_1(){
        return carPlateNumber;
    }

    string getcarName_2(){
        return carName;
    }

    string getcarModel_3(){
        return carModel;
    }

    string getcarCapacity_4(){
        return carCapacity;
    }

    string getengineCapacity_5(){
        return engineCapacity;
    }

    string getcolour_6(){
        return colour;
    }

    string getcarOwner_7(){
        return carOwner;
    }
};

#endif // CARCLASS_H
