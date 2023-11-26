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

