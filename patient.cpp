class patient{
    private:
        string name;
        string address;
        int age;
        string arrival_date;
        string source;
        string destination;
        int room_no;
        string discharged_date;
        int floor_no;
        bool empty;
        bool room_alloted;
    void specify_floor_no(){
        if(age >= 60)
            floor_no = 0;
        else if(age < 60 && age > = 40)
            floor_no = 1;
        else
            floor_no = 2;
    }




    public:
        patient(){
            name = 'none';
            address ='none';
            age = -1;
            arrival_date ='none';
            source = 'none';
            destination = 'none';
            room_no = -1;
            discharged_date = 'none';
            floor_no = -1;
            empty = true;
            room_alloted = false;
        }

        void display_details(){
            cout<<"Patient's name : "<<name<<endl;
            cout<<"Address : "<<address<<endl;
            cout<<"Age : "<<age<<endl;
            cout<<"Arrival Date : "<<arrival_date<<endl;
            cout<<"Coming from : "<<source<<endl;
            cout<<"Going to : "<<destination<<endl;
            cout<<"Alloted Room no. : "<<room_no<<endl;
            cout<<"Discharged Date : "<<discharged_date<<endl;
            cout<<"Floor no. : "<<floor_no<<endl;
        }

        void input_details(){
            cout<<"Please input the Patient details"<<endl;
            cout<<"Name"<<endl;
            getline (cin, name);
            cout<<"Address"<<endl;
            getline (cin, fullName);
            cout<<"Age"<<endl;
            cin>>age;
            cout<<"Arrival Date"<<endl;
            getline (cin, arrival_date);
            cout<<"Coming from"<<endl;
            getline (cin, source);
            cout<<"Going to"<<endl;
            getline (cin, destination);

            empty = false;

        }

        int get_room_no(){
            return room_no;
        }

        void modify_room_no(int value){
            if(value == -1)
                room_alloted = false;
            else
                room_alloted = true;
            room_no = value;
        }

        int get_floor_no(){
            return floor_no;
        }

        void modify_room_no(int value){
            floor_no = value;
        }

        void modify_discharged_date(string date){
            discharged_date = date;
        }

    



};