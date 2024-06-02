#include <iostream>
#include <string>
#include <vector>

class TravelPackage {
public:
    // Constructor to initialize package details
    TravelPackage(const std::string& destination,
                  const std::string& airline,
                  const std::string& hotel, 
                  const std::vector<std::string>& activities,
                  double price) :
        destination_(destination),
        airline_(airline),
        hotel_(hotel),
        activities_(activities),
        price_(price) {}

    // Getter methods for package details
    const std::string& getDestination() const { return destination_; }
    const std::string& getAirline() const { return airline_; }
    const std::string& getHotel() const { return hotel_; }
    const std::vector<std::string>& getActivities() const { return activities_; }
    double getPrice() const { return price_; }

    // Function to display package information
    void displayDetails() const {
        std::cout << "Destination: " << destination_ << std::endl;
        std::cout << "Airline: " << airline_ << std::endl;
        std::cout << "Hotel: " << hotel_ << std::endl;
        std::cout << "Activities:" << std::endl;
        for (const std::string& activity : activities_) {
            std::cout << " - " << activity << std::endl;
        }
        std::cout << "Price: $" << price_ << std::endl;
    }

private:
    std::string destination_; // Destination city/location
    std::string airline_; // Airline for the flight
    std::string hotel_; // Hotel for accommodation
    std::vector<std::string> activities_; // List of included activities
    double price_; // Total package price
};

int main() {
    std::string destination, airline, hotel;
    std::vector<std::string> activities;
    double price;

    // Get user input for package details
    std::cout << "Enter Destination: ";
    std::getline(std::cin, destination);
    std::cout << "Enter Airline: ";
    std::getline(std::cin, airline);
    std::cout << "Enter Hotel: ";
    std::getline(std::cin, hotel);

    // Get user input for activities (loop until user enters "done")
    std::string activity;
    do {
        std::cout << "Enter activity (or 'done' to finish): ";
        std::getline(std::cin, activity);
        if (activity != "done") {
            activities.push_back(activity);
        }
    } while (activity != "done");

    // Get user input for price
    std::cout << "Enter Price: ";
    std::cin >> price;

    // Create TravelPackage object based on user input
    TravelPackage myPackage(destination, airline, hotel, activities, price);

    // Display package details
    std::cout << "\n** Your Travel Package Details **" << std::endl;
    myPackage.displayDetails();

    return 0;
}