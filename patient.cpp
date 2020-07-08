using namespace std;
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

    string random_string(size_t length){
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

    int random_number(int low, int high){
        return low + (rand() % high);
    }

    string convert_date_to_string(){
        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);
        std::ostringstream oss;
        oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
        auto str = oss.str();
        return str;
    }




    public:
        patient(int i, bool value=false){
            if(value){
                name = random_string(10);
                address = random_string(15);
                age = random_number(12,70);
                arrival_date = convert_date_to_string();
                source = random_string(10);
                destination = random_string(10);
                empty = false;
                room_allotted = false;
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

        void display_details(){
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

        void input_details(){
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

        int get_room_no(){
            return room_no;
        }

        int get_room_serial_no(){
            return room_serial_no;
        }

        void modify_room_no(int value){
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

        int get_floor_no(){
            return floor_no;
        }

        void modify_floor_no(int value){
            floor_no = value;
        }

        void modify_discharged_date(){
            discharged_date = convert_date_to_string();
        }

        bool get_room_allotted(){
            return room_allotted;
        }

        int get_age(){
            return age;
        }

        bool get_empty(){
            return empty;
        }

        string get_patient_name(){
            return name;
        }

    



};