# 🎮 MargonemClone - C++ Game Project

## 📝 Opis projektu
Zaawansowany projekt gry w stylu MMORPG inspirowany Margonem, napisany w C++ z użyciem biblioteki SFML 2.6.

## 🛠️ Technologie
- **C++17** - Główny język programowania
- **SFML 2.6** - Grafika, audio, sieć
- **CMake** - System budowania
- **Python** - Generatory assetów
- **JSON** - Konfiguracja questów

## 📁 Struktura projektu
```
MargonemClone/
├── MargonemClone.cpp      # Główny plik gry
├── inventory.cpp          # System ekwipunku
├── combat system.cpp      # System walki
├── server.cpp            # Serwer sieciowy
├── CMakeLists.txt        # Konfiguracja CMake
├── generate_assets.py    # Generator grafik
├── font_generator.py     # Generator fontów
├── perlin.py            # Generator terenu
├── quests.json          # Konfiguracja questów
└── assets/              # Assety gry
    ├── tileset.png
    ├── char_*.png
    └── font.ttf
```

## 🚀 Jak zbudować projekt

### Wymagania
- CMake 3.16+
- Visual Studio 2022 (Windows)
- Python 3.7+ z bibliotekami: Pillow, numpy, noise

### Kroki budowania
```bash
# 1. Sklonuj repozytorium
git clone <url>
cd MargonemClone

# 2. Wygeneruj assety
python generate_assets.py

# 3. Zbuduj projekt
mkdir build && cd build
cmake ..
cmake --build . --config Release

# 4. Uruchom grę
cd Release
./game.exe
```

## 🎯 Funkcje gry
- ✅ **Renderowanie mapy** - Tilemap z proceduralnym generowaniem
- ✅ **System postaci** - 6 profesji (Warrior, Mage, Hunter, Tracker, Blade Dancer, Paladin)
- ✅ **Ruch gracza** - Płynny ruch z kamerą
- ✅ **System walki** - Turn-based combat
- ✅ **Inwentarz** - Zarządzanie przedmiotami
- ✅ **Questy** - System zadań z JSON
- ✅ **Sieć** - Multiplayer server
- ✅ **Assety** - Automatyczne generowanie grafik

## 🔧 Rozszerzenia
Projekt jest modularny i łatwy do rozszerzania:
- Dodaj nowe profesje w `MargonemClone.cpp`
- Rozszerz system walki w `combat system.cpp`
- Dodaj nowe przedmioty w `inventory.cpp`
- Stwórz nowe questy w `quests.json`

## 📊 Status kompilacji
- ✅ **C++ Build**: 0 błędów, 0 ostrzeżeń
- ✅ **Python Scripts**: Wszystkie działają
- ✅ **SFML Integration**: Automatyczne pobieranie
- ✅ **Asset Generation**: Kompletne

## 🎮 Sterowanie
- **WASD** - Ruch postaci
- **ESC** - Wyjście z gry
- **Fullscreen** - 1024x768

## 🌟 Screenshots
Gra renderuje:
- Proceduralne mapy z różnymi biomes
- Animowane postacie dla każdej profesji
- Interfejs użytkownika z HP/MP

## 📄 Licencja
Projekt edukacyjny - MIT License

## 👥 Autorzy
- **AI Assistant** - Główny developer
- **arusa** - Project owner

---
🚀 **Gotowy do gry! Miłej zabawy w MargonemClone!** 🎮