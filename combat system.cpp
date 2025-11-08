#include <iostream>
#include <random>

struct Entity; // Forward declaration

void turnBasedCombat(Entity* player, Entity* enemy) {
    std::random_device rd;
    std::mt19937 gen(rd());
    
    std::cout << "=== WALKA ROZPOCZĘTA ===" << std::endl;
    
    while (player && enemy) {
        // Player turn
        std::cout << "Tura gracza - naciśnij Enter aby atakować..." << std::endl;
        std::cin.get();
        
        int damage = std::uniform_int_distribution<int>(10, 20)(gen);
        std::cout << "Zadałeś " << damage << " obrażeń!" << std::endl;
        
        // Check victory
        std::cout << "Wróg został pokonany!" << std::endl;
        break;
    }
}