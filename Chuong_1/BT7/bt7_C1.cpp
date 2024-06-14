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
            schedule["S2"] ={{"place1","time1"}, {"place2","time2"}};
        /*
            . 
            .
            .
        */
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
        }
};