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

            schedule["S8"]={{"SAI GON","15:40"}, {"MUONG MAN","19:53"}, {"THAP CHAM","22:47"}, {"NHA TRANG","00:47"},
                            {"TUY HOA","03:39"}, {"DIEU TRI","05:46"}, {"QUANG NGAI","09:24"}, {"TAM KY","10:39"},
                            {"DA NANG","12:20"}, {"HUE","15:47"}, {"DONG HA","17:12"}, {"DONG HOI","19:46"},
                            {"VINH","01:08"}, {"THANH HOA","04:33"}, {"NINH BINH","05:54"}, {"NAM DINH","06:26"},
                            {"PHU LY","07:08"}, {"HA NOI","08:30"}};

            schedule["S10"]={{"SAI GON","10:00"}, {"MUONG MAN","14:07"}, {"THAP CHAM","16:43"}, {"NHA TRANG","18:50"},
                            {"TUY HOA","21:53"}, {"DIEU TRI","00:00"}, {"QUANG NGAI","03:24"}, {"TAM KY","04:38"},
                            {"DA NANG","06:19"}, {"HUE","11:12"}, {"DONG HA","12:42"}, {"DONG HOI","14:41"},
                            {"VINH","20:12"}, {"THANH HOA","23:09"}, {"NINH BINH","00:31"}, {"NAM DINH","01:24"},
                            {"PHU LY","02:02"}, {"HA NOI","03:15"}};

            schedule["S12"]={{"SAI GON","12:30"}, {"MUONG MAN","16:41"}, {"THAP CHAM","19:19"}, {"NHA TRANG","21:10"},
                            {"TUY HOA","00:19"}, {"DIEU TRI","02:30"}, {"QUANG NGAI","05:55"}, {"TAM KY","07:10"},
                            {"DA NANG","09:26"}, {"HUE","14:32"}, {"DONG HA","16:05"}, {"DONG HOI","17:59"},
                            {"VINH","23:50"}, {"THANH HOA","03:33"}, {"NINH BINH","04:50"}, {"NAM DINH","05:22"},
                            {"PHU LY","06:00"}, {"HA NOI","07:10"}};

            schedule["S14"]={{"SAI GON","17:00"}, {"MUONG MAN","21:04"}, {"THAP CHAM","00:08"}, {"NHA TRANG","01:57"},
                            {"TUY HOA","05:11"}, {"DIEU TRI","07:09"}, {"QUANG NGAI","11:21"}, {"TAM KY","12:40"},
                            {"DA NANG","14:41"}, {"HUE","18:13"}, {"DONG HA","19:38"}, {"DONG HOI","21:38"},
                            {"VINH","02:59"}, {"THANH HOA","06:39"}, {"NINH BINH","07:57"}, {"NAM DINH","08:29"},
                            {"PHU LY","09:09"}, {"HA NOI","10:25"}};

            schedule["S16"]={{"SAI GON","20:00"}, {"MUONG MAN","01:15"}, {"THAP CHAM","04:05"}, {"NHA TRANG","05:42"},
                            {"TUY HOA","08:36"}, {"DIEU TRI","10:42"}, {"QUANG NGAI","14:35"}, {"TAM KY","16:08"},
                            {"DA NANG","17:43"}, {"HUE","21:14"}, {"DONG HA","22:39"}, {"DONG HOI","00:52"},
                            {"VINH","07:07"}, {"THANH HOA","09:59"}, {"NINH BINH","11:12"}, {"NAM DINH","11:44"},
                            {"PHU LY","12:23"}, {"HA NOI","13:45"}};

            schedule["S18"]={{"SAI GON","22:20"}, {"MUONG MAN","03:16"}, {"THAP CHAM","06:03"}, {"NHA TRANG","08:06"},
                            {"TUY HOA","10:50"}, {"DIEU TRI","13:00"}, {"QUANG NGAI","17:04"}, {"TAM KY","18:21"},
                            {"DA NANG","20:17"}, {"HUE","23:50"}, {"DONG HA","01:25"}, {"DONG HOI","03:28"},
                            {"VINH","09:20"}, {"THANH HOA","12:20"}, {"NINH BINH","13:51"}, {"NAM DINH","14:25"},
                            {"PHU LY","15:06"}, {"HA NOI","16:20"}};
            
            schedule["LH2"]={{"SAI GON","15:40"}, {"MUONG MAN","19:53"}, {"THAP CHAM","22:47"}, {"NHA TRANG","00:47"},
                            {"TUY HOA","23:09"}, {"DIEU TRI","01:20"}, {"QUANG NGAI","04:55"}, {"TAM KY","06:11"},
                            {"DA NANG","08:29"}, {"HUE","12:29"}, {"DONG HA","13:52"}, {"DONG HOI","15:52"},
                            {"VINH","21:00"}, {"THANH HOA","00:01"}, {"NINH BINH","01:28"}, {"NAM DINH","02:01"},
                            {"PHU LY","02:42"}, {"HA NOI","04:00"}};

            schedule["SN2"]={{"SAI GON","15:40"}, {"MUONG MAN","19:53"}, {"THAP CHAM","22:47"}, {"NHA TRANG","00:47"},
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
}