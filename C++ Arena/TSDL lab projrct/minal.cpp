#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PackingChecklist {
private:
    string destination;
    int duration;
    vector<string> activities;
    vector<string> packingList; // Added to store the packing list

public:
    // Constructor to initialize checklist details
    PackingChecklist(string dest, int dur, const vector<string>& act) : destination(dest), duration(dur), activities(act) {
        generateChecklist(); // Call the generateChecklist method in the constructor
    }

    // Method to generate and display the personalized packing checklist
    void generateChecklist() {
        // Add essential items to the packing list
        packingList.push_back("Passport and travel documents");
        packingList.push_back("Cash and/or credit cards");
        packingList.push_back("Clothing for " + to_string(duration) + " days");
        packingList.push_back("Toiletries and personal care items");

        // Add destination-specific items to the packing list
        if (destination == "Beach") {
            packingList.push_back("Swimsuit");
            packingList.push_back("Sunscreen");
            packingList.push_back("Hat");
            packingList.push_back("Sunglasses");
            packingList.push_back("Sandals");
        } else if (destination == "City") {
            packingList.push_back("Comfortable shoes");
            packingList.push_back("Umbrella");
            packingList.push_back("Daypack");
            packingList.push_back("Camera");
            packingList.push_back("Guidebook");
        } else if (destination == "Mountains") {
            packingList.push_back("Hiking boots");
            packingList.push_back("Raincoat");
            packingList.push_back("Backpack");
            packingList.push_back("Water bottle");
            packingList.push_back("Snacks");
        }

        // Add activity-specific items to the packing list
        for (const string& activity : activities) {
            if (activity == "Hiking") {
                packingList.push_back("Hiking boots");
                packingList.push_back("Raincoat");
                packingList.push_back("Backpack");
                packingList.push_back("Water bottle");
                packingList.push_back("Snacks");
            } else if (activity == "Swimming") {
                packingList.push_back("Swimsuit");
                packingList.push_back("Sunscreen");
                packingList.push_back("Hat");
                packingList.push_back("Sunglasses");
                packingList.push_back("Sandals");
            } else if (activity == "Sightseeing") {
                packingList.push_back("Comfortable shoes");
                packingList.push_back("Umbrella");
                packingList.push_back("Daypack");
                packingList.push_back("Camera");
                packingList.push_back("Guidebook");
            }
        }

        // Display the packing checklist
        cout << "Packing Checklist for " << destination << " (" << duration << " days)" << endl;
        cout << " " << endl;
        cout << "Essentials:" << endl;
        for (const string& item : packingList) {
            cout << "- " << item << endl;
        }
        cout << " " << endl;
    }
};

}

int main() {
  // Example usage:
  vector<string> activities = {"Swimming", "Sightseeing"};
  PackingListGenerator myTrip("Beach", 7, activities);
  vector<string> myPackingList = myTrip.getPackingList();

  // Print the packing list
  for (const string& item : myPackingList) {
    cout << item << endl;
  }

  return 0;
}