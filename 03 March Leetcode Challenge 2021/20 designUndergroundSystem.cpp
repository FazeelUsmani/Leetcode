class UndergroundSystem {
    // id => entryStation
    string checkInName[1000001];
    // id => entryTime
    int checkInTime[1000001];
    // id => {numberOfTravels, overallTime}
    unordered_map<string, pair<int, int>> avgTimesMap;
public:
    UndergroundSystem() {
        // cout << "I am a constructor and I am as useless as \"ueue\" in \"queue\"\n";
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInName[id] = stationName;
        checkInTime[id] = -t;
    }
    
    void checkOut(int id, string stationName, int t) {
        // retrieving matching checkin data
        int travelTime = checkInTime[id] + t;
        // computing travelName id
        string travelName = checkInName[id] + stationName;
        // updating data on the current travel
        auto currTravel = avgTimesMap.find(travelName);
        if (currTravel == end(avgTimesMap)) avgTimesMap[travelName] = {1, travelTime};
        else {
            currTravel->second.first++;
            currTravel->second.second += travelTime;
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        // computing travelName id
        string travelName = startStation + endStation;
        // retrieving data on current travel
        auto currTravel = avgTimesMap[travelName];
        // returning the average time
        return currTravel.second / (double)currTravel.first;
    }
};
