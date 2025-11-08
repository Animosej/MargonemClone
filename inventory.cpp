#include <unordered_map>
#include <string>

struct Item {
    std::string name;
    int dmg;
    int rarity;
};

std::unordered_map<std::string, Item> itemDB;

void initializeItems() {
    itemDB["miecz_zelazny"] = { "Miecz Żelazny", 15, 1 };
}