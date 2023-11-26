#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

class EventLocation {
private:
    int maxSeats;
    int numRows;
    int numZones;
    int seatsPerRow;
    char* locationName;

public:

    EventLocation()
        : maxSeats(0), numRows(0), numZones(0), seatsPerRow(0), locationName(nullptr) {}

    EventLocation(int maxSeats, int numRows, int numZones, int seatsPerRow, const char* name)
        : maxSeats(maxSeats), numRows(numRows), numZones(numZones), seatsPerRow(seatsPerRow) {
        locationName = new char[strlen(name) + 1];
        strcpy(locationName, name);
    }


    EventLocation(const EventLocation& other)
        : maxSeats(other.maxSeats),
        numRows(other.numRows),
        numZones(other.numZones),
        seatsPerRow(other.seatsPerRow) {
        locationName = new char[strlen(other.locationName) + 1];
        strcpy(locationName, other.locationName);
    }

    ~EventLocation() {
        delete[] locationName;
    }


    EventLocation& operator=(const EventLocation& other) {
        if (this != &other) {
            maxSeats = other.maxSeats;
            numRows = other.numRows;
            numZones = other.numZones;
            seatsPerRow = other.seatsPerRow;

            delete[] locationName;
            locationName = new char[strlen(other.locationName) + 1];
            strcpy(locationName, other.locationName);
        }
        return *this;
    }


    int getMaxSeats() const { return maxSeats; }
    int getNumRows() const { return numRows; }
    int getNumZones() const { return numZones; }
    int getSeatsPerRow() const { return seatsPerRow; }
    const char* getLocationName() const { return locationName; }

    void displayInfo() const {
        std::cout << "Location: " << locationName << "\nMax Seats: " << maxSeats << "\nNum Rows: " << numRows
            << "\nNum Zones: " << numZones << "\nSeats Per Row: " << seatsPerRow << std::endl;
    }

    void processInfo() {

    }
};

class Event {
private:
    std::string eventName;
    std::string eventDate;
    std::string eventTime;
    static const int maxEventNameLength = 50;

public:

    Event() : eventName(""), eventDate(""), eventTime("") {}

    Event(const std::string& eventName, const std::string& eventDate, const std::string& eventTime)
        : eventName(eventName), eventDate(eventDate), eventTime(eventTime) {}


    Event(const Event& other)
        : eventName(other.eventName), eventDate(other.eventDate), eventTime(other.eventTime) {}


    ~Event() {}


    Event& operator=(const Event& other) {
        if (this != &other) {
            eventName = other.eventName;
            eventDate = other.eventDate;
            eventTime = other.eventTime;
        }
        return *this;
    }


    std::string getEventName() const { return eventName; }
    std::string getEventDate() const { return eventDate; }
    std::string getEventTime() const { return eventTime; }


    void displayInfo() const {
        std::cout << "Event Name: " << eventName << "\nEvent Date: " << eventDate
            << "\nEvent Time: " << eventTime << std::endl;
    }

    void processInfo() {

    }


    bool operator==(const Event& other) const {
        return eventName == other.eventName && eventDate == other.eventDate && eventTime == other.eventTime;
    }

    bool operator<(const Event& other) const {

        return false;
    }
};

