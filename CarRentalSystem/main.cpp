#include <iostream>
#include <string>
#include <cctype> //for tolower func
#include <fstream>
#include <vector>
#include <sstream>

#include "CarClass.h"
#include "Customer.h"
#include "RentCar.h"
using namespace std;

//function declaration part
void writeRentDataToFile();
void showRentList();
void rentCarByCustomer();

void showCarList();
void showCustomerList();

void writeCustomerToFile();
void showCustomerInformation();
void addNewCustomer();

void writeCarToFile();
void showCarInformation();
void addNewCar(); // if the user chose the number "2", this function will be called

void goodbyeMsg();
int serviceMenu(); // when the program start, this function will be worked first
void titleSystemName();

string wantToContinue();
string tolower(string str);

Customer cust1;
CarClass c1;
RentCar rc;


int main()
{
    titleSystemName();
    string continueYesNo="yes";
    int answer; // variable for choosing the number form menu

    while(continueYesNo=="yes"){
        answer=serviceMenu(); // assign the return value form the serviceMenu() function
        switch(answer)
        {

            case 1: //Add a new car
                    addNewCar();
                    showCarInformation(); //show the recently added one
                    writeCarToFile();
                    continueYesNo=tolower(wantToContinue());
                    break;
            case 2: //Add a new customer
                    addNewCustomer();
                    showCustomerInformation(); //show the recently added one
                    writeCustomerToFile();
                    continueYesNo=tolower(wantToContinue());
                    break;
            case 3: //Rent a car
                    rentCarByCustomer();
                    continueYesNo=tolower(wantToContinue());
                    break;
            case 4: //Show Car list
                    showCarList();
                    continueYesNo=tolower(wantToContinue());
                    break;
            case 5: //Show Customer list
                    showCustomerList();
                    continueYesNo=tolower(wantToContinue());
                    break;
            case 6: //Show Rent list
                    showRentList();
                    continueYesNo=tolower(wantToContinue());
                    break;
            case 7: //4 Do you want to exit from the system?
                    goodbyeMsg();
                    return 0;
                    break;
            default:
                    cout<<"INVALID NUMBER!!\n";
                    cout<<"Choose the number from the Menu.\n";
        }
    }
    goodbyeMsg();
    return 0;
}

//function definition part
void writeRentDataToFile(){
    ifstream MyReadFile("rent.txt");   //open file to read
    string arrlines[10];
    int i=0;
    while(getline(MyReadFile,arrlines[i])){// Read the file line by line and put into string array
        if(arrlines[0]!=""){
            i++;
        }
    }
    MyReadFile.close();//Close the file

    //-----------------------------------------------------------------

    ofstream MyWriteFile("rent.txt"); // open/create file to write
    if(arrlines[0]!=""){ //if there is data in string array
        for(string arrline:arrlines){ // taking old records from file
                if(arrline!=""){ //if there is data in the variable
                    MyWriteFile<<arrline<<"\n"; // re-write the old records into file from the beginning
                }
        }
        /*
            write new line after re-write the upper lines
        */
        MyWriteFile<<rc.getCarPlateNumber_1()<<",";
        MyWriteFile<<rc.getNRC_2()<<",";
        MyWriteFile<<rc.getStartDate_3()<<",";
        MyWriteFile<<rc.getTotalDays_4()<<",";
        MyWriteFile<<rc.gettRentalPricePerDay_5()<<",";
        MyWriteFile<<rc.getTotalPrice_6()<<",";
        MyWriteFile<<rc.getOrderNumber_7()<<"\n";
        cout<<"File input successful (old and new)!\n";
    }else{
        /*
            if there is NO data in string array
            write new line as the very first line in the file
        */
        MyWriteFile<<rc.getCarPlateNumber_1()<<",";
        MyWriteFile<<rc.getNRC_2()<<",";
        MyWriteFile<<rc.getStartDate_3()<<",";
        MyWriteFile<<rc.getTotalDays_4()<<",";
        MyWriteFile<<rc.gettRentalPricePerDay_5()<<",";
        MyWriteFile<<rc.getTotalPrice_6()<<",";
        MyWriteFile<<rc.getOrderNumber_7()<<"\n";
        cout<<"File input successful!! (1st line in file)\n";
    }
    MyWriteFile.close();
}

void showRentList(){//Rent List
    ifstream MyReadFile("rent.txt");   //Read from the text file
    string arrlines[10];
    int i=0;
    bool status=true;
    if (!MyReadFile.is_open()) {
        // print error message and return
        cout<< "\tThere is no data in the system.\n\tYou need to input the data first!"<< endl;
    }
    while(getline(MyReadFile,arrlines[i])){// Read the file line by line into a string
            if(arrlines[0]!="" && status){
                cout<<"Rent Information ::\n";
                cout<<"============================================================================================================================\n";
                cout<<"Plate No.\tNRC\t\t\tStart Date\t\tTotal Days\tPrice/Day\tTotal Price\tOrder Number\n";
                cout<<"============================================================================================================================\n";
                status=false;
            }
            if(arrlines[0]!=""){
                //cout<<"\t"<<i+1<<". "<<arrlines[i]<<endl;

                vector<string> result;//~
                stringstream s_stream(arrlines[i]); //create string stream from the string ~
                while(s_stream.good()) {//~
                    string substr;//~
                    getline(s_stream, substr, ','); //get first string delimited by comma ~
                    result.push_back(substr);//~
                }//~
                for(int i = 0; i<result.size(); i++) {    //print all splitted strings ~
                    cout << result.at(i) << "\t\t";//~
                }//~
                cout<<endl;
                i++;
            }
        }
    MyReadFile.close();//Close the file
}

void rentCarByCustomer(){
    showCarList();
    cout<<endl<<endl;
    showCustomerList();
    cout<<endl<<endl;

    cin.ignore();
    rc.inputCarPlateNumber_1();
    rc.inputNRC_2();
    rc.inputStartDate_3();
    rc.inputTotalDays_4();
    rc.inputRentalPricePerDay_5();
    rc.inputTotalPrice_6();
    rc.inputOrderNumber_7();

    cout<<endl<<endl;
    cout<<"\tThe renting car data is that you recently added!\n";
    cout<<"\t _______________________________________________\n";
    cout<<"\t   Car Plate Number   :  "<<rc.getCarPlateNumber_1()<<"\n";
    cout<<"\t   NRC                :  "<<rc.getNRC_2()<<"\n";
    cout<<"\t   Start Date         :  "<<rc.getStartDate_3()<<"\n";
    cout<<"\t   Total Days         :  "<<rc.getTotalDays_4()<<"\n";
    cout<<"\t   Rent Price per day :  "<<rc.gettRentalPricePerDay_5()<<"\n";
    cout<<"\t   Total Price        :  "<<rc.getTotalPrice_6()<<"\n";
    cout<<"\t   Order Number       :  "<<rc.getOrderNumber_7()<<"\n";
    cout<<"\t _______________________________________________\n";

    writeRentDataToFile();
}

//Show
void showCarList(){ //CAR LIST
    ifstream MyReadFile("car.txt");   //Read from the text file
    string arrlines[10];
    int i=0;
    bool status=true;
    if (!MyReadFile.is_open()) {
        // print error message and return
        cout<< "\tThere is no data in the system.\n\tYou need to input the data first!"<< endl;
    }
    while(getline(MyReadFile,arrlines[i])){// Read the file line by line into a string
            if(arrlines[0]!="" && status){
                cout<<"Car Information ::\n";
                cout<<"================================================================================================================\n";
                cout<<"Plate No.\tName\t\t\tModel\t\tCapacity\tEngine\t\tColor\t\tOwner\n";
                cout<<"================================================================================================================\n";
                status=false;
            }
            if(arrlines[0]!=""){
                //cout<<"\t"<<i+1<<". "<<arrlines[i]<<endl;

                vector<string> result;//~
                stringstream s_stream(arrlines[i]); //create string stream from the string ~
                while(s_stream.good()) {//~
                    string substr;//~
                    getline(s_stream, substr, ','); //get first string delimited by comma ~
                    result.push_back(substr);//~
                }//~
                for(int i = 0; i<result.size(); i++) {    //print all splitted strings ~
                    cout << result.at(i) << "\t\t";//~
                }//~
                cout<<endl;
                i++;
            }
        }
    MyReadFile.close();//Close the file
}

void showCustomerList(){//CUSTOMER LIST
    ifstream MyReadFile("customer.txt");   //Read from the text file
    string arrlines[10];
    int i=0;
    bool status=true;
    if (!MyReadFile.is_open()) {
        // print error message and return
        cout<< "\tThere is no data in the system.\n\tYou need to input the data first!"<< endl;
    }
    while(getline(MyReadFile,arrlines[i])){// Read the file line by line into a string
            if(arrlines[0]!="" && status){
                cout<<"Customer Information ::\n";
                cout<<"====================================================================================================\n";
                cout<<"Customer Name\t\tNRC number\t\tEmail address\t\t\tPhone Number\n";
                cout<<"====================================================================================================\n";
                status=false;
            }
            if(arrlines[0]!=""){
                //cout<<"\t"<<i+1<<". "<<arrlines[i]<<endl;

                vector<string> result;//~
                stringstream s_stream(arrlines[i]); //create string stream from the string ~
                while(s_stream.good()) {//~
                    string substr;//~
                    getline(s_stream, substr, ','); //get first string delimited by comma ~
                    result.push_back(substr);//~
                }//~
                for(int i = 0; i<result.size(); i++) {    //print all splitted strings ~
                    cout << result.at(i) << "\t\t";//~
                }//~
                cout<<endl;
                i++;
            }
        }
    MyReadFile.close();//Close the file
}

//Add new CUSTOMER
void writeCustomerToFile(){
    ifstream MyReadFile("customer.txt");   //open file to read
    string arrlines[10];
    int i=0;
    while(getline(MyReadFile,arrlines[i])){// Read the file line by line and put into string array
        if(arrlines[0]!=""){
            i++;
        }
    }
    MyReadFile.close();//Close the file

    //-----------------------------------------------------------------

    ofstream MyWriteFile("customer.txt"); // open/create file to write
    if(arrlines[0]!=""){ //if there is data in string array
        for(string arrline:arrlines){ // taking old records from file
                if(arrline!=""){ //if there is data in the variable
                    MyWriteFile<<arrline<<"\n"; // re-write the old records into file from the beginning
                }
        }
        /*
            write new line after re-write the upper lines
        */
        MyWriteFile<<cust1.getUserName_1()<<",";
        MyWriteFile<<cust1.getNRC_2()<<",";
        MyWriteFile<<cust1.getEmail_3()<<",";
        MyWriteFile<<cust1.getPhoneNumber_4()<<"\n";
        cout<<"File input successful (old and new)!\n";
    }else{
        /*
            if there is NO data in string array
            write new line as the very first line in the file
        */
        MyWriteFile<<cust1.getUserName_1()<<",";
        MyWriteFile<<cust1.getNRC_2()<<",";
        MyWriteFile<<cust1.getEmail_3()<<",";
        MyWriteFile<<cust1.getPhoneNumber_4()<<"\n";
        cout<<"File input successful!! (1st line in file)\n";
    }
    MyWriteFile.close();
}

void showCustomerInformation(){
    cout<<endl<<endl;
    cout<<"\tThe following car data is that you recently added!\n";
    cout<<"\t _______________________________________________\n";
    cout<<"\t   Customer Name:  "<<cust1.getUserName_1()<<"\n";
    cout<<"\t   NRC  \t:  "<<cust1.getNRC_2()<<"\n";
    cout<<"\t   Email\t:  "<<cust1.getEmail_3()<<"\n";
    cout<<"\t   Phone Number\t:  "<<cust1.getPhoneNumber_4()<<"\n";
    cout<<"\t _______________________________________________\n";
}

void addNewCustomer(){
    cin.ignore();
    cust1.inputUserName_1();
    cust1.inputNRC_2();
    cust1.inputEmail_3();
    cust1.inputPhoneNumber_4();
}

//Add new CAR
void writeCarToFile(){
    ifstream MyReadFile("car.txt");   //open file to read
    string arrlines[10];
    int i=0;
    while(getline(MyReadFile,arrlines[i])){// Read the file line by line and put into string array
        if(arrlines[0]!=""){
            i++;
        }
    }
    MyReadFile.close();//Close the file

    //-----------------------------------------------------------------

    ofstream MyWriteFile("car.txt"); // open/create file to write
    if(arrlines[0]!=""){ //if there is data in string array
        for(string arrline:arrlines){ // taking old records from file
                if(arrline!=""){ //if there is data in the variable
                    MyWriteFile<<arrline<<"\n"; // re-write the old records into file from the beginning
                }
        }
        //write new line after re-write the upper lines
        MyWriteFile<<c1.getCarPlateNumber_1()<<",";
        MyWriteFile<<c1.getcarName_2()<<",";
        MyWriteFile<<c1.getcarModel_3()<<",";
        MyWriteFile<<c1.getcarCapacity_4()<<",";
        MyWriteFile<<c1.getengineCapacity_5()<<",";
        MyWriteFile<<c1.getcolour_6()<<",";
        MyWriteFile<<c1.getcarOwner_7()<<"\n";
        cout<<"File input successful (old and new)!\n";
    }else{ //if there is NO data in string array
        //write new line as the very first line in the file
       MyWriteFile<<c1.getCarPlateNumber_1()<<",";
        MyWriteFile<<c1.getcarName_2()<<",";
        MyWriteFile<<c1.getcarModel_3()<<",";
        MyWriteFile<<c1.getcarCapacity_4()<<",";
        MyWriteFile<<c1.getengineCapacity_5()<<",";
        MyWriteFile<<c1.getcolour_6()<<",";
        MyWriteFile<<c1.getcarOwner_7()<<"\n";
        cout<<"File input successful!! (1st line in file)\n";
    }
    MyWriteFile.close();
}

void showCarInformation(){
    cout<<endl<<endl;
    cout<<"\tThe following car data is that you recently added!\n";
    cout<<"\t _______________________________________________\n";
    cout<<"\t   Car Plate Number\t:  "<<c1.getCarPlateNumber_1()<<"\n";
    cout<<"\t   Car Name\t\t:  "<<c1.getcarName_2()<<"\n";
    cout<<"\t   Car Model\t\t:  "<<c1.getcarModel_3()<<"\n";
    cout<<"\t   Car Capacity\t\t:  "<<c1.getcarCapacity_4()<<"\n";
    cout<<"\t   Engine Capacity\t:  "<<c1.getengineCapacity_5()<<"\n";
    cout<<"\t   Colour\t\t:  "<<c1.getcolour_6()<<"\n";
    cout<<"\t   Car Owner\t\t:  "<<c1.getcarOwner_7()<<"\n";
    cout<<"\t _______________________________________________\n";
}

void addNewCar(){
    //accept user input
    cin.ignore();
    c1.inputCarPlateNumber_1();
    c1.inputCarName_2();
    c1.inputCarModel_3();
    c1.inputCarCapacity_4();
    c1.inputEngineCapacity_5();
    c1.inputColour_6();
    c1.inputcarOwner_7();
}


void goodbyeMsg(){
    cout<<"\n\n";
    cout<<"\t\t\t------------------------------------\n";
    cout<<"\t\t\t  Thank You for using our system.\n";
    cout<<"\t\t\t\tSee you next time (:\n";
    cout<<"\t\t\t------------------------------------\n";
}

int serviceMenu(){
    int ans;
    cout<<endl<<endl;
    cout<<"\tChoose the number from the menu :\n";
    cout<<"\t+-------------------------------------+\n";
    cout<<"\t| Entry |                             |\n";
    cout<<"\t|     1 | Add new car                 |\n";
    cout<<"\t|     2 | Add new customer            |\n";
    cout<<"\t|       |                             |\n";
    cout<<"\t| Rent  |                             |\n";
    cout<<"\t|     3 | Rent a car                  |\n";
    cout<<"\t|       |                             |\n";
    cout<<"\t| Show  |                             |\n";
    cout<<"\t|     4 | Show Car list               |\n";
    cout<<"\t|     5 | Show Customer list          |\n";
    cout<<"\t|     6 | Show Rent list              |\n";
    cout<<"\t|       |                             |\n";
    cout<<"\t| Exit  |                             |\n";
    cout<<"\t|     7 | Exit from the system        |\n";
    cout<<"\t+-------------------------------------+\n\n";
    cout<<"\tPlease choose the number: ";

    cin>>ans;
    cout<<"\n\n";
    return ans;
}

void titleSystemName(){
    cout<<"\t========================================================="<<endl;
    cout<<"\t*                                                       *"<<endl;
    cout<<"\t*                                                       *"<<endl;
    cout<<"\t*     Welcome to our Junior Coder car rental center     *"<<endl;
    cout<<"\t*                                                       *"<<endl;
    cout<<"\t*                                                       *"<<endl;
    cout<<"\t========================================================="<<endl;
}


string wantToContinue(){
    string yn;
    cout<<"\nDo you want to continue (yes or no)? ";
    cin>>yn;
    cout<<"\n";
    return yn;
}

string tolower(string str){ //only int and char have built in tolower(), not for string
    string mixedCase = str;
    string lowerCase="";

    for(char c:mixedCase){ //put character by character from the string
        lowerCase+=tolower(c); // convert the character into lower case letter by using char tolower() function
    }
    return lowerCase;
}





