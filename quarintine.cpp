class quarintine{
    private:
        const TOTAL_ROOMS = 500;
        const GROUND_ROOMS = 200;
        const FIRST_ROOMS = 150;
        const SECOND_ROOMS = 150;
        int vacancy;
        int count;
        int alloted_count;
        bool ground[GROUND_ROOMS];
        bool first[FIRST_ROOMS];
        bool second[SECOND_ROOMS];
        vector <patient> p(500);
    
    public:
        quarintine(){
            vacancy = -1;
            count = -1;
            alloted_count = -1;
        }

        void add_patients(int n){
            while(n--){
                count++;
                p.push_back(patient);
                p[count].input_details();
            }
        }

        int allotment_all(){
            if(alloted_count == 500)
                return -1;
            else{
                for(auto i = p.begin(); i != g.end(); i++){
                    *i.
                }

            }
        }


}