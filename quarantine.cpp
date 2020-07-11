class quarantine{
    private:
        int occ_ground;
        int occ_first;
        int occ_second;
        int count;
        int allotted_count;
        bool ground[GROUND_ROOMS]; 
        bool first[FIRST_ROOMS];
        bool second[SECOND_ROOMS];
        vector <patient> p; 
    
    bool string_compare(string s1, string s2){ //compares two strings by converting them both into lowercase and returns true if they're equal
        if(s1.length()!=s2.length())
            return false;
        
        else{
            int n = s1.length() - 1;
            transform(s1.begin(), s1.end(), s1.begin(), ::tolower); 
            transform(s2.begin(), s2.end(), s2.begin(), ::tolower); 
            while(n--){
                if(s1[n]!=s2[n])
                    return false;
            }

            return true;
        }
        
    }

    int allott_room(int age){ //allotts rooms according to the patients age and the vacancy of the rooms
        if(age >= 60&&occ_ground!=GROUND_ROOMS){
            occ_ground++;
            for(int i = 0; i < GROUND_ROOMS; i++){
                if(ground[i] == false){
                    ground[i] = true;
                    return i + 1;
                }
            }
        }
        else if(age < 60 && age >= 40 && occ_first<FIRST_ROOMS - 1){
            occ_first++;
            for(int i = 0; i < FIRST_ROOMS; i++){
                if(first[i] == false){
                    first[i] = true;
                    return i + GROUND_ROOMS + 1;
                }
            }
        }
        else if(age < 40 && occ_second<SECOND_ROOMS - 1){
            occ_second++;
            for(int i = 0; i < SECOND_ROOMS; i++){
                if(second[i] == false){
                    second[i] = true;
                    return i + GROUND_ROOMS + FIRST_ROOMS + 1;
                }
            }
        }
        return -1;
    }

    void discharge_room(int floor_no, int serial_room_no){ //discharges patients from the rooms
        if(floor_no == 0){
            occ_ground--;
            ground[serial_room_no-1] = false;
        }
        else if(floor_no == 1){
            occ_first--;
            first[serial_room_no-1] = false;
        }
        else{
            occ_second--;
            second[serial_room_no-1] = false;
        }
        allotted_count--;
    }

    int calc_room_no(int floor, int serial_room_no){ //calculates room no from serial and floor no
        if(floor == 0)
            return serial_room_no;
        else if(floor == 1)
            return serial_room_no + GROUND_ROOMS;
        else
            return serial_room_no + GROUND_ROOMS + FIRST_ROOMS;
    }



    bool check_occupancy(int floor, int serial_room_no){ //checks if a particular room is occupied or not
        if(floor == 0)
            return ground[serial_room_no-1];
        else if(floor == 1)
            return first[serial_room_no-1];
        else
            return second[serial_room_no-1];
    }

    bool search(int room_no){ //searches for a room's details
        for(auto& it : p){
            if(it.get_room_no() == room_no){
                it.display_details();
                return true;
            }
        }

        return false;
    }

    static bool comp_room_no(patient &A, patient &B){ //used for sorting the records of the patients by their respective room numbers
        return (A.get_room_no() < B.get_room_no());
    }

    public:
        quarantine(){
            occ_ground = -1;
            occ_first = -1;
            occ_second = -1;
            count = -1;
            allotted_count = 0;
            for(int i = 0; i < GROUND_ROOMS; i++)
                ground[i] = false; //false meaning the room is vacant

            for(int i = 0; i < FIRST_ROOMS; i++)
                first[i] = false;
            
            for(int i = 0; i < SECOND_ROOMS; i++)
                second[i] = false;
        }

        int calc_floor_no(int room_no){ //calculates the floor number by the given room number
            if(room_no <= GROUND_ROOMS)
                return 0;
            else if(room_no > GROUND_ROOMS && room_no <= GROUND_ROOMS + FIRST_ROOMS)
                return 1;
            else if(room_no > GROUND_ROOMS + FIRST_ROOMS && room_no <= GROUND_ROOMS + FIRST_ROOMS + SECOND_ROOMS)
                return 2;
            else 
                return -1;
        }

        int calc_serial_room_no(int room_no){ //calculates the serial number by the given room number
            if(room_no <= GROUND_ROOMS)
                return room_no;
            else if(room_no > GROUND_ROOMS && room_no <= GROUND_ROOMS + FIRST_ROOMS)
                return room_no - GROUND_ROOMS;
            else if(room_no > GROUND_ROOMS + FIRST_ROOMS && room_no <= GROUND_ROOMS + FIRST_ROOMS + SECOND_ROOMS)
                return room_no - GROUND_ROOMS - FIRST_ROOMS;
            else 
                return -1;
        }

        void add_patients(int n){ //adds new patients to the records
            while(n--){
                count++;
                p.push_back(patient(count));
                p[count].input_details();
            }
        }
        void fill_patients_test(int i=30){ //fills the records with random entries for testing
            while(i--){
                count++;
                p.push_back(patient(count, true));
            }
        }

        int allottment_all(){ //allotts all the new patients to the vacant rooms
            if(allotted_count == 500)
                return -1;
            else{
                for(auto& it : p){
                    if(allotted_count == 500)
                        break;
                    if((!it.get_room_allotted()) && (string_compare(it.get_discharged_date(),"none"))){
                        int room_no = allott_room(it.get_age());
                        if(room_no!=-1){
                            allotted_count++;
                            it.modify_discharged_date(true);
                        }
                        it.modify_room_no(room_no);
                        }
                    }
                return allotted_count;
            }
        }

        void display_all_patients(){ //displays the data of all patients

            for(auto& it : p){
                if(!(it.get_empty()))
                    it.display_details();
            }
        }


        int allott_patient(string patient_name){ //allotts a particular patient a vacant room

            for(auto& it : p){
                if(string_compare(it.get_patient_name(), patient_name)){
                    if(!it.get_room_allotted()){
                        int room_no = allott_room(it.get_age());
                        if(room_no!=-1){
                            allotted_count++;
                            it.modify_discharged_date(true);
                        }
                        it.modify_room_no(room_no);

                        return room_no;
                        }
                    }

            }
            return -1;
        }

        void room_details(int floor, int room){ //displays the details of a room
            
            if(check_occupancy(floor, room)){
                cout<<"This room is occupied"<<endl;
                cout<<"The patient details are as follows"<<endl;
                int room_no = calc_room_no(floor,room);
                for(auto& it : p){
                    if(it.get_room_no() == room_no){
                        it.display_details();
                    }
                }
            }
            else{
                cout<<"The room is vacant."<<endl;
            }
        }

        void sort_by_room_no(){ //sorts the records of that patients
            sort(p.begin(), p.end(), comp_room_no);
        }

        bool search_patient(string patient_name, int serial_room_no = -1, int floor_no = -1){ //searches for the records of a patient either by their name 
            if(serial_room_no == -1){                                                           //or their room number
                for(auto& it : p){
                    if(string_compare(it.get_patient_name(), patient_name)){
                        it.display_details();
                        return true;
                    }
                }
                return false;
            }
            else{
                int room_no = calc_room_no(floor_no, serial_room_no);
                return search(room_no);
            }
        }

        bool display_vacant_rooms(){ //displays all vacant rooms
            int room_no = 500;
            bool flag = false;
            while(room_no){
                if(!check_occupancy(calc_floor_no(room_no), calc_serial_room_no(room_no))){
                    cout<<"Room no: "<<calc_serial_room_no(room_no)<<endl;
                    cout<<"Floor no: "<<calc_floor_no(room_no)<<endl<<endl;
                    flag = true;
                }
                room_no--;
            }

            return flag;
        }


        bool display_occupied_rooms(){ //displays all occupied rooms
            int room_no = 500;
            bool flag = false;
            while(room_no){
                if(check_occupancy(calc_floor_no(room_no), calc_serial_room_no(room_no))){
                    cout<<"Room no: "<<calc_serial_room_no(room_no)<<endl;
                    cout<<"Floor no: "<<calc_floor_no(room_no)<<endl<<endl;
                    flag = true;
                }
                room_no--;
            }

            return flag;
        }

        bool discharge_specific_patient(string patient_name){ //discharges a specific patient
            for(auto& it : p){
                    if(string_compare(it.get_patient_name(), patient_name)){
                        if(it.get_room_allotted()){
                            discharge_room(it.get_floor_no(), it.get_room_serial_no());
                            cout<<"This patient is being discharged"<<endl;
                            it.modify_room_no(-1);
                            it.modify_discharged_date();
                            it.display_details();
                        }

                        else{
                            cout<<"The patient hasn't been allotted a room"<<endl;
                        }
                        return true;
                    }
            }
            return false;
        }


        void discharge_all_patients(){ //discharges all patients available in the records
            for(auto& it : p){
                    if(it.get_room_allotted()){
                        discharge_room(it.get_floor_no(), it.get_room_serial_no());
                        cout<<"This patient is being discharged"<<endl;
                        it.modify_room_no(-1);
                        it.modify_discharged_date();
                        it.display_details();
                    }
            }
        }

        void facility_details(){ //displays all the details of the facility
            cout<<"Total rooms occupied: "<<allotted_count<<endl;
            cout<<"Total rooms vacant: "<<500-allotted_count<<endl;
            cout<<"Rooms occupied on ground floor: "<<occ_ground+1<<endl;
            cout<<"Rooms occupied on first floor: "<<occ_first+1<<endl;
            cout<<"Rooms occupied on second floor: "<<occ_second+1<<endl;
            cout<<"Total patients in the record: "<<count+1<<endl;
        }




};