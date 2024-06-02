#include <iostream>
#include <vector>
#include <string>

class PackingChecklist {
      std::string destination;
      int duration;
      std::vector<std::string> activities;

public:
      PackingChecklist(std::string dest, int dur, std::vector<std::string> acts) 
            : destination(dest), duration(dur), activities(acts) {}

      std::vector<std::string> getPackingList() {
            std::vector<std::string> packingList;
            // Add items to packingList based on destination, duration, and activities
            // This is just a simple example, you can customize it as per your needs
            packingList.push_back("Passport");
            packingList.push_back("Tickets");
            if(destination == "Beach") {
                  packingList.push_back("Swimwear");
                  packingList.push_back("Sunscreen");
            }
            if(duration > 7) {
                  packingList.push_back("Extra clothes");
            }
            for(auto& activity : activities) {
                  if(activity == "Hiking") {
                        packingList.push_back("Hiking boots");
                        packingList.push_back("Map");
                  }
            }
            return packingList;
      }
};

int main() {
      std::vector<std::string> activities = {"Hiking", "Swimming"};
      PackingChecklist myTrip("Beach", 7, activities);
      std::vector<std::string> myPackingList = myTrip.getPackingList();

      std::cout << "Your packing list:\n";
      for(auto& item : myPackingList) {
            std::cout << "- " << item << "\n";
      }

      return 0;
}