class patient{
    private:
        string name;
        string address;
        int age;
        string arrival_date;
        string source;
        string destination;
        int room_serial_no;
        int room_no;
        string discharged_date;
        int floor_no;
        int id;
        bool empty;
        bool room_allotted;

    string random_string(size_t length){ //generates a random string of size length
        auto randchar = []() -> char
        {
            const char charset[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
            const size_t max_index = (sizeof(charset) - 1);
            return charset[ rand() % max_index ];
        };
        string str(length,0);
        generate_n( str.begin(), length, randchar);
        return str;
    }

    int random_number(int low, int high){ //generates a random number bw a given range
        return low + (rand() % high);
    }

    string convert_date_to_string(){ //returns the current time in string format
        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);
        std::ostringstream oss;
        oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
        auto str = oss.str();
        return str;
    }




    public:
        patient(int i, bool value=false){  
            if(value){ //used for generating random entries for testing
                name = random_string(10);
                address = random_string(15);
                age = random_number(12,70);
                arrival_date = convert_date_to_string();
                source = random_string(10);
                destination = random_string(10);
                empty = false;
                room_allotted = false;
                discharged_date = "none";
                room_serial_no = -1;
                room_no = -1;
                floor_no = -1;
            }

            else{
                name = "none";
                address = "none";
                age = -1;
                arrival_date = convert_date_to_string();
                source = "none";
                destination = "none";
                room_serial_no = -1;
                room_no = -1;
                discharged_date = "none";
                floor_no = -1;
                empty = true;
                room_allotted = false;
            }
            id = i+1;
        }

        void display_details(){ //displays the details of the patient
            cout<<endl;
            cout<<"Patient Number #"<<id<<endl;
            cout<<"Patient's name : "<<name<<endl;
            cout<<"Address : "<<address<<endl;
            cout<<"Age : "<<age<<endl;
            cout<<"Arrival Date : "<<arrival_date<<endl;
            cout<<"Coming from : "<<source<<endl;
            cout<<"Going to : "<<destination<<endl;
            cout<<"Discharged Date : "<<discharged_date<<endl;
            if(room_allotted){
                cout<<"Allotted Room no. : "<<room_serial_no<<endl;
                cout<<"Floor no. : "<<floor_no<<endl;
            }
            cout<<endl<<endl;
        }

        void input_details(){ //takes input from the user for the details of the patient
            cout<<"Patient Number #"<<id<<endl;
            cout<<"Please input the Patient details"<<endl;
            cout<<"Name"<<endl;
            getline(cin >> ws, name);
            cout<<"Address"<<endl;
            getline(cin >> ws, address);
            cout<<"Age"<<endl;
            cin>>age;
            cout<<"Coming from"<<endl;
            getline(cin >> ws, source);
            cout<<"Going to"<<endl;
            getline (cin >> ws, destination);

            empty = false;

        }

        int get_room_no(){ //returns the room number of the patient
            return room_no;
        }

        int get_room_serial_no(){ //returns the serial room no of the patient
            return room_serial_no;
        }

        void modify_room_no(int value){ //modifies the room number, floor number and room_allotted according to the passed value
            if(value == -1){
                room_allotted = false;
                room_serial_no = -1;
                room_no = -1;
            }
            else{
                room_allotted = true;
                room_no = value;
                if(value <= GROUND_ROOMS){
                    floor_no = 0;
                    room_serial_no = room_no;
                }
                else if(value > GROUND_ROOMS && value <= GROUND_ROOMS + FIRST_ROOMS){
                    floor_no = 1;
                    room_serial_no = room_no - GROUND_ROOMS;
                }
                else{
                    floor_no = 2;
                    room_serial_no = room_no - GROUND_ROOMS - FIRST_ROOMS;
                }
            }
        }

        int get_floor_no(){ //returns the floor number of the patient
            return floor_no;
        }

        void modify_floor_no(int value){ //modifies the floor number of the patient
            floor_no = value;
        }

        void modify_discharged_date(bool a = false){ //modifies the discharge date to either none or the current time depending on the passed value
            if(a)
                discharged_date = "none";
            else
                discharged_date = convert_date_to_string();
        }

        string get_discharged_date(){ //returns the discharged date of the patient
            return discharged_date;
        }

        bool get_room_allotted(){ //returns true if the patient has been allotted a room, otherwise false
            return room_allotted;
        }

        int get_age(){ //returns the age of the patient
            return age;
        }

        bool get_empty(){ //returns false if the patient's details haven't been filled yet (used as a failsafe)
            return empty;
        }

        int get_id(){ //returns the id of the patient
            return id;
        }

        string get_patient_name(){ //returns the name of the patient
            return name;
        }

    



};