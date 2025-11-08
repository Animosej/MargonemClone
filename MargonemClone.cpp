// MargonemClone.cpp - SZKIELET GRY (C++17 + SFML 2.6)
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <memory>
#include <string>
#include <unordered_map>
#include <thread>
#include <mutex>

constexpr int TILE_SIZE = 32;
constexpr int WORLD_WIDTH = 200;
constexpr int WORLD_HEIGHT = 150;

enum class Profession { WARRIOR, MAGE, HUNTER, TRACKER, BLADE_DANCER, PALADIN };

struct Entity {
    sf::Vector2f pos;
    sf::Sprite sprite;
    Profession prof;
    int hp, maxHp, level;
    std::string name;
};

class Game {
private:
    sf::RenderWindow window;
    sf::View camera;
    sf::Texture tileset;
    sf::Font font;
    std::vector<std::vector<int>> map;
    std::vector<std::unique_ptr<Entity>> entities;
    Entity* player;
    std::mutex entityMutex;

public:
    Game() : window(sf::VideoMode(1024, 768), "Margonem Clone", sf::Style::Default) {
        window.setFramerateLimit(60);
        camera.setSize(1024, 768);
        loadAssets();
        generateWorld();
        spawnPlayer();
    }

    void loadAssets() {
        tileset.loadFromFile("assets/tileset.png");
        font.loadFromFile("assets/font.ttf");
    }

    void generateWorld() {
        map.resize(WORLD_HEIGHT, std::vector<int>(WORLD_WIDTH, 0));
        // Procedural generation (Perlin noise via Python → C++ import)
        for (int y = 0; y < WORLD_HEIGHT; ++y)
            for (int x = 0; x < WORLD_WIDTH; ++x)
                map[y][x] = (x + y) % 5; // placeholder
    }

    void spawnPlayer() {
        auto p = std::make_unique<Entity>();
        p->pos = sf::Vector2f(100 * TILE_SIZE, 100 * TILE_SIZE);
        p->prof = Profession::WARRIOR;
        p->hp = p->maxHp = 100;
        p->level = 1;
        p->name = "Gracz";
        p->sprite.setTexture(tileset);
        p->sprite.setTextureRect(sf::IntRect(0, 0, TILE_SIZE, TILE_SIZE));
        player = p.get();
        entities.push_back(std::move(p));
    }

    void update(float dt) {
        handleInput();
        updateEntities(dt);
        camera.setCenter(player->pos);
    }

    void handleInput() {
        sf::Vector2f dir(0, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) dir.y -= 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) dir.y += 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) dir.x -= 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) dir.x += 1;
        if (dir.x || dir.y) {
            dir = sf::Vector2f(dir.x ? dir.x / std::abs(dir.x) : 0, dir.y ? dir.y / std::abs(dir.y) : 0);
            player->pos += dir * 150.f * 0.016f;
        }
    }

    void updateEntities(float dt) {
        // AI, PvE, combat loop
    }

    void render() {
        window.clear(sf::Color(40, 40, 60));
        window.setView(camera);

        // Draw map
        for (int y = 0; y < WORLD_HEIGHT; ++y)
            for (int x = 0; x < WORLD_WIDTH; ++x) {
                sf::Sprite tile(tileset, sf::IntRect((map[y][x] % 8) * TILE_SIZE, (map[y][x] / 8) * TILE_SIZE, TILE_SIZE, TILE_SIZE));
                tile.setPosition(x * TILE_SIZE, y * TILE_SIZE);
                window.draw(tile);
            }

        // Draw entities
        for (auto& e : entities)
            window.draw(e->sprite);

        window.display();
    }

    void run() {
        sf::Clock clock;
        while (window.isOpen()) {
            sf::Event e;
            while (window.pollEvent(e)) {
                if (e.type == sf::Event::Closed) window.close();
                if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape) window.close();
            }
            float dt = clock.restart().asSeconds();
            update(dt);
            render();
        }
    }
};

int main() {
    Game game;
    game.run();
    return 0;
}