class UndergroundSystem {
public:
    
    unordered_map<int,pair<string,int>> checkInMap;
    unordered_map<string,pair<int,int>> checkOutMap;
    
    UndergroundSystem() {

    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto checkInPair = checkInMap[id];
        string src = checkInPair.first;
        int srcTime = checkInPair.second;
        string route = src+"_"+stationName;
        checkOutMap[route].first += t-srcTime;
        checkOutMap[route].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation+"_"+endStation;
        auto checkOutPair = checkOutMap[route];
        int totalTime = checkOutPair.first;
        int count = checkOutPair.second;
        return (double)totalTime/count;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
