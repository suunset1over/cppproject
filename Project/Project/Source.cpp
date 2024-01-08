#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

class EventLocation {
private:
    int maxSeats;
    int numRows;
    int numZones;
    int seatsPerRow;
    std::string locationName;

public:
    EventLocation()
        : maxSeats(0), numRows(0), numZones(0), seatsPerRow(0), locationName("") {}

    EventLocation(int maxSeats, int numRows, int numZones, int seatsPerRow, const std::string& name)
        : maxSeats(maxSeats), numRows(numRows), numZones(numZones), seatsPerRow(seatsPerRow), locationName(name) {}

    EventLocation(const EventLocation& other)
        : maxSeats(other.maxSeats),
          numRows(other.numRows),
          numZones(other.numZones),
          seatsPerRow(other.seatsPerRow),
          locationName(other.locationName) {}

    ~EventLocation() {}

    EventLocation& operator=(const EventLocation& other) {
        if (this != &other) {
            maxSeats = other.maxSeats;
            numRows = other.numRows;
            numZones = other.numZones;
            seatsPerRow = other.seatsPerRow;
            locationName = other.locationName;
        }
        return *this;
    }

    int getMaxSeats() const { return maxSeats; }
    int getNumRows() const { return numRows; }
    int getNumZones() const { return numZones; }
    int getSeatsPerRow() const { return seatsPerRow; }
    const std::string& getLocationName() const { return locationName; }

    void displayInfo() const {
        std::cout << "Location: " << locationName << "\nMax Seats: " << maxSeats << "\nNum Rows: " << numRows
                  << "\nNum Zones: " << numZones << "\nSeats Per Row: " << seatsPerRow << std::endl;
    }

    void processInfo() {
        // Placeholder for processing information
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

    const std::string& getEventName() const { return eventName; }
    const std::string& getEventDate() const { return eventDate; }
    const std::string& getEventTime() const { return eventTime; }

    void displayInfo() const {
        std::cout << "Event Name: " << eventName << "\nEvent Date: " << eventDate << "\nEvent Time: " << eventTime
                  << std::endl;
    }

    void processInfo() {
        // Placeholder for processing information
    }

    bool operator==(const Event& other) const {
        return eventName == other.eventName && eventDate == other.eventDate && eventTime == other.eventTime;
    }

    bool operator<(const Event& other) const {
        // Placeholder comparison
        return false;
    }
};

class Ticket {
private:
    std::string ticketType;
    int uniqueID;
    static int uniqueIDCounter;

public:
    Ticket() : ticketType(""), uniqueID(++uniqueIDCounter) {}

    Ticket(const std::string& ticketType) : ticketType(ticketType), uniqueID(++uniqueIDCounter) {}

    Ticket(const Ticket& other) : ticketType(other.ticketType), uniqueID(++uniqueIDCounter) {}

    ~Ticket() {}

    Ticket& operator=(const Ticket& other) {
        if (this != &other) {
            ticketType = other.ticketType;
            uniqueID = ++uniqueIDCounter;
        }
        return *this;
    }

    const std::string& getTicketType() const { return ticketType; }
    int getUniqueID() const { return uniqueID; }

    void displayInfo() const {
        std::cout << "Ticket Type: " << ticketType << "\nUnique ID: " << uniqueID << std::endl;
    }

    void processInfo() {
        // Placeholder for processing information
    }

    bool operator==(const Ticket& other) const {
        return ticketType == other.ticketType && uniqueID == other.uniqueID;
    }

    bool operator>(const Ticket& other) const {
        // Placeholder comparison
        return false;
    }

    static int generateUniqueID() { return ++uniqueIDCounter; }
};

int Ticket::uniqueIDCounter = 0;

class AbstractTicketManager {
public:
    virtual ~AbstractTicketManager() = default;
    virtual void AddTicket(const Ticket& ticket) = 0;
    virtual void SaveTickets() const = 0;
    virtual void LoadTickets() = 0;
    virtual void DisplayTickets() const = 0;
};

class TicketManager : public AbstractTicketManager {
public:
    static const int maxTickets = 100; // Maximum number of tickets

    TicketManager() : numTickets(0) {}

    void AddTicket(const Ticket& ticket) override {
        if (numTickets < maxTickets) {
            tickets[numTickets++] = ticket;
        } else {
            std::cout << "Maximum number of tickets reached.\n";
        }
    }

    void SaveTickets() const override {
        for (int i = 0; i < numTickets; ++i) {
            std::cout << tickets[i].getTicketType().size() << ' ' << tickets[i].getTicketType() << ' '
                      << tickets[i].getUniqueID() << '\n';
        }
    }

    void LoadTickets() override {
        size_t ticketTypeSize;
        int uniqueID;
        while (std::cin >> ticketTypeSize) {
            std::string ticketType(ticketTypeSize, '\0');
            for (size_t i = 0; i < ticketTypeSize; ++i) {
                std::cin >> ticketType[i];
            }

            std::cin >> uniqueID;

            tickets[numTickets++] = Ticket(ticketType);
        }
    }

    void DisplayTickets() const override {
        for (int i = 0; i < numTickets; ++i) {
            std::cout << "Ticket Type: " << tickets[i].getTicketType() << ", Unique ID: " << tickets[i].getUniqueID()
                      << '\n';
        }
    }

private:
    Ticket tickets[maxTickets];
    int numTickets;
};

class Menu {
public:
    static void display() {
        std::cout << "1. Add Ticket\n"
                  << "2. Display Tickets\n"
                  << "3. Save Tickets\n"
                  << "4. Load Tickets\n"
                  << "5. Quit\n";
    }

    static int getUserChoice() {
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        return choice;
    }
};

int main() {
    int maxSeats, numRows, numZones, seatsPerRow;
    std::string locationName;

    std::cout << "Enter Location Information:\n";
    std::cout << "Max Seats: ";
    std::cin >> maxSeats;
    std::cout << "Num Rows: ";
    std::cin >> numRows;
    std::cout << "Num Zones: ";
    std::cin >> numZones;
    std::cout << "Seats Per Row: ";
    std::cin >> seatsPerRow;
    std::cout << "Location Name: ";
    std::cin.ignore();
    std::getline(std::cin, locationName);
    EventLocation location(maxSeats, numRows, numZones, seatsPerRow, locationName);
    location.displayInfo();

    std::string eventName, eventDate, eventTime;

    std::cout << "\nEnter Event Information:\n";
    std::cout << "Event Name: ";
    std::cin.ignore();
    std::getline(std::cin, eventName);
    std::cout << "Event Date: ";
    std::cin >> eventDate;
    std::cout << "Event Time: ";
    std::cin >> eventTime;

    Event myEvent(eventName, eventDate, eventTime);
    myEvent.displayInfo();
//part2
AbstractTicketManager* ticketManager = new TicketManager();

    int choice;
    do {
        Menu::display();
        choice = Menu::getUserChoice();
 switch (choice) {
        case 1: {
            std::string ticketType;
            std::cout << "Enter ticket type: ";
            std::cin.ignore();
            std::getline(std::cin, ticketType);
            ticketManager->AddTicket(Ticket(ticketType));
            break;
        }
        case 2:
            ticketManager->DisplayTickets();
            break;
        case 3:
            ticketManager->SaveTickets();
            break;
        case 4:
            ticketManager->LoadTickets();
            break;
        case 5:
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
