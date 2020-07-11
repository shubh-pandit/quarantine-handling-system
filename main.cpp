const int TOTAL_ROOMS = 500;
const int GROUND_ROOMS = 200;
const int FIRST_ROOMS = 150;
const int SECOND_ROOMS = 150; //The values of these constants can be changed as it seems fit

using namespace std; 

#include<iostream> 
#include<string> 
#include<bits/stdc++.h> 
#include<vector>
#include<ctype.h>
#include<ctime>
#include<random> 
#include <iomanip> 
#include <sstream> 
#include<algorithm>
#include"patient.cpp" //contains the patient class
#include"quarantine.cpp" //contains the quarantine class

int main(){
    srand((unsigned) time(0)); //seeding the rand function
    quarantine facility; 
    char choice ='y';
    int option = -1, n = -1;
    bool flag = false, flag2 = true; //these variables are used in getting the input from the user
    string s; 
    
    do{
        
        if(flag2)
            cout<<endl<<endl<<"*****************Welcome to the quarantine facility management system of NIT SILCHAR**************"<<endl<<endl;
        cout<<"What do you want to do?"<<endl;
        cout<<"Please input the number corresponding to your choice:"<<endl;
        cout<<"1. Fill the registry with random names for testing"<<endl;
        cout<<"2. Add new patients"<<endl;
        cout<<"3. Allocate all the vacant rooms to the new patients"<<endl;
        cout<<"4. Allocate a vacant room to a specific patient"<<endl;
        cout<<"5. Display the details of all the patients"<<endl;
        cout<<"6. Search for the details of a specific patient"<<endl;
        cout<<"7. Query the status of a room"<<endl;
        cout<<"8. Display all vacant rooms"<<endl;
        cout<<"9. Display all occupied rooms"<<endl;
        cout<<"10. Discharge a specific patient"<<endl;
        cout<<"11. Complete statistics of the quarantine facility"<<endl;
        cout<<"12. Discharge all patients"<<endl;
        cout<<"13. Sort the patient's list by their respective room numbers"<<endl;
        cout<<"14. Exit"<<endl;
        cin>>option;
        switch(option){
            case 1: 
                do{
                    flag = false;
                    cout<<endl;
                    cout<<"The registry will be filled with random data for your convenience"<<endl;
                    cout<<"Please input the number of patients you want to be added (should not be greater than 500)"<<endl;
                    cin>>n;
                    if(n > 500 || n <= 0){ //if entered value is out of bounds, user is asked to try again
                        flag = true;
                        cout<<"Incorrect input, please try again."<<endl;
                    }
                    else
                        facility.fill_patients_test(n);
                }while(flag);
                break;
            
            case 2:
                do{
                    flag = false;
                    cout<<endl;
                    cout<<"Please input the number of patients you want to add (should not be greater than 500)"<<endl;
                    cin>>n;
                    if(n > 500 || n <= 0){
                        flag = true;
                        cout<<"Incorrect input, please try again."<<endl;
                    }
                    else
                        facility.add_patients(n);
                }while(flag);
                break;
            
            case 3:
                cout<<endl;
                cout<<"All the vacant rooms will be allotted to the new patients"<<endl;
                n = facility.allottment_all();
                if(n == -1)
                    cout<<"There are no vacant rooms, so no new rooms were allotted."<<endl;
                else{
                    cout<<"The total number of allotted rooms is now "<<n<<endl;
                }
                break;

            case 4:
                cout<<endl;
                cout<<"Please enter the name of the patient (case insensitive)"<<endl;
                getline(cin >> ws, s);
                n = facility.allott_patient(s);
                if(n!=-1){
                    cout<<"The patient's record was found and he was allotted in "<<endl;
                    cout<<"Room no: "<<facility.calc_serial_room_no(n)<<endl;
                    cout<<"Floor no: "<<facility.calc_floor_no(n)<<endl;
                }
                else
                    cout<<"Either the patient is already allotted in a room or the patient's record do not exist"<<endl;
                break;
            
            case 5:
                cout<<endl;
                cout<<"All available patient records will be displayed."<<endl;
                facility.display_all_patients();
                break;
            
            case 6:
                cout<<endl;
                n = -1;
                cout<<"Do you want to search through:"<<endl;
                cout<<"1. Patient's name"<<endl;
                cout<<"2. Patient's Room no and Floor no"<<endl;
                cin>>n;
                if(n==1){
                    cout<<"Please enter the patient's name (case insensitive)"<<endl;
                    getline(cin >> ws, s);
                    flag = facility.search_patient(s);
                }
                else{
                    int serial_room_no, floor_no;
                    cout<<"Please enter the patient's serial room no"<<endl;
                    cin>>serial_room_no;
                    cout<<"Please enter the patient's floor no (0 for Ground, 1 for First, 2 for Second)"<<endl;
                    cin>>floor_no;
                    flag = facility.search_patient("none", serial_room_no,floor_no);
                }
                if(!flag)
                        cout<<"Patient's record was not found"<<endl;
                break;
            
            case 7:
                do{
                    flag = false;
                    int serial_room_no, floor_no;
                    cout<<"Please enter the room no"<<endl;
                    cin>>serial_room_no;
                    cout<<"Please enter the floor no (0 for Ground, 1 for First, 2 for Second)"<<endl;
                    cin>>floor_no;
                    if(floor_no > 2 || floor_no < 0 || serial_room_no > 200 || serial_room_no <= 0)
                        flag = true;
                    if((floor_no == 1 || floor_no == 2)  && (serial_room_no > 150))
                        flag = true;
                    if(!flag){
                        facility.room_details(floor_no, serial_room_no);
                    }
                    else{
                        cout<<"Incorrect details, please try again"<<endl;
                    }
                }while(flag);

                break;

            
            case 8:
                cout<<"Displaying vacant rooms"<<endl;
                flag = facility.display_vacant_rooms();
                if(!flag)
                    cout<<"No vacant rooms were found"<<endl;
                
                break;

            case 9:
                cout<<"Displaying occupied rooms"<<endl;
                flag = facility.display_occupied_rooms();
                if(!flag)
                    cout<<"No occupied rooms were found"<<endl;
                break;

            case 10:
                cout<<endl;
                cout<<"Please enter the name of the patient you want to discharge (case insensitive)"<<endl;
                getline(cin >> ws, s);
                flag = facility.discharge_specific_patient(s);
                if(!flag){
                    cout<<"The patient's record were not found"<<endl;
                }
                break;
            
            case 11:
                facility.facility_details();
                break;
            
            case 12:
                facility.discharge_all_patients();
                break;

            case 13:
                facility.sort_by_room_no();
                cout<<"The list has been sorted"<<endl;
                facility.display_all_patients();
                break;
            
            case 14:
                cout<<"Are you sure you want to exit? (y/n)"<<endl;
                cin>>choice;
                if(choice=='y'||choice=='Y')
                    return 0;
                
                break;
                

            default:
                cout<<"Incorrect input, please try again"<<endl;                
            }
        flag2 = false;
        cout<<"Continue? (y/n)"<<endl;
        cin>>choice;
    }while(choice == 'y' || choice == 'Y');
    return 0;

}
