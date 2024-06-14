#include <iostream>
#include <map>          // save the schedule of the train
#include <string>

class TrainStation {
    // create a schedule for the train with the train number, time, and station
    private:
        // <train_number, <time, station>>
        std::map<std::string, std::map<std::string, std::string>> schedule; 

    // create a data schedule for the train
    public:
        TrainStation() {
            // create a schedule for the train
            schedule["S2"]={{"SAI GON","21:00"}, {"MUONG MAN","NONE"}, {"THAP CHAM","NONE"}, {"NHA TRANG","04:10"},
                            {"TUY HOA","NONE"}, {"DIEU TRI","08:12"}, {"QUANG NGAI","NONE"}, {"TAM KY","NONE"},
                            {"DA NANG","13:27"}, {"HUE","16:21"}, {"DONG HA","NONE"}, {"DONG HOI","19:15"},
                            {"VINH","23:21"}, {"THANH HOA","NONE"}, {"NINH BINH","NONE"}, {"NAM DINH","NONE"},
                            {"PHU LY","NONE"}, {"HA NOI","05:00"}};
                        
            schedule["S4"]={{"SAI GON","21:50"}, {"MUONG MAN","02:10"}, {"THAP CHAM","05:01"}, {"NHA TRANG","06:47"},
                            {"TUY HOA","09:43"}, {"DIEU TRI","11:49"}, {"QUANG NGAI","15:41"}, {"TAM KY","NONE"},
                            {"DA NANG","19:04"}, {"HUE","22:42"}, {"DONG HA","00:14"}, {"DONG HOI","02:27"},
                            {"VINH","07:45"}, {"THANH HOA","10:44"}, {"NINH BINH","12:04"}, {"NAM DINH","12:37"},
                            {"PHU LY","13:23"}, {"HA NOI","14:40"}};
            
            schedule["S6"]={{"SAI GON","11:10"}, {"MUONG MAN","15:21"}, {"THAP CHAM","18:06"}, {"NHA TRANG","20:00"},
                            {"TUY HOA","23:09"}, {"DIEU TRI","01:20"}, {"QUANG NGAI","04:55"}, {"TAM KY","06:11"},
                            {"DA NANG","08:29"}, {"HUE","12:29"}, {"DONG HA","13:52"}, {"DONG HOI","15:52"},
                            {"VINH","21:00"}, {"THANH HOA","00:01"}, {"NINH BINH","01:28"}, {"NAM DINH","02:01"},
                            {"PHU LY","02:42"}, {"HA NOI","04:00"}};    
        }

        // add a new schedule for the train
        void addSchedule(std::string train_number, std::string time, std::string station) {
            schedule[train_number][time] = station;
        }

        // remove a schedule for the train
        void removeSchedule(std::string train_number, std::string time) {
            schedule[train_number].erase(time);
        }

        // // show the schedule of the train
        // void showSchedule(std::string train_number) {
        //     std::cout << "Train number: " << train_number << std::endl;
        //     for (auto it = schedule[train_number].begin(); it != schedule[train_number].end(); it++) {
        //         std::cout << "Time: " << it->first << " - Station: " << it->second << std::endl;
        //     }
        // }

        // // show the schedule of all the train
        // void showAllSchedule() {
        //     for (auto it = schedule.begin(); it != schedule.end(); it++) {
        //         std::cout << "Train number: " << it->first << std::endl;
        //         for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
        //             std::cout << "Time: " << it2->first << " - Station: " << it2->second << std::endl;
        //         }
        //     }
        // }


        // get arrival time of the train
        std::string getArrivalTime(const std::string& train, const std::string&station) {
            if(schedule.find(train))
                printf("Train number %s is not found\n", train.c_str());
        }
};