# generate_assets.py - AI-GENERATED 2D PIXEL ART (32x32)
from PIL import Image, ImageDraw
import numpy as np
import os

os.makedirs("assets", exist_ok=True)

# Tileset: trawa, ziemia, kamień, woda, las
def generate_tileset():
    tiles = []
    colors = [(34,139,34), (139,90,43), (128,128,128), (30,144,255), (0,100,0)]
    for i, color in enumerate(colors):
        img = Image.new("RGB", (32,32), (50,50,70))
        draw = ImageDraw.Draw(img)
        for x in range(0,32,4):
            for y in range(0,32,4):
                if (x//4 + y//4) % 2 == i%2:
                    draw.rectangle([x,y,x+3,y+3], fill=color)
        img.save(f"assets/tile_{i}.png")
    # Stitch into tileset
    tileset = Image.new("RGB", (256, 32))
    for i in range(5):
        tile = Image.open(f"assets/tile_{i}.png")
        tileset.paste(tile, (i*32, 0))
    tileset.save("assets/tileset.png")

# Player sprites (6 profesji)
def generate_characters():
    professions = ["warrior", "mage", "hunter", "tracker", "bladedancer", "paladin"]
    base_colors = [(200,50,50), (50,50,200), (50,200,50), (180,120,50), (150,50,200), (200,200,50)]
    for i, (name, color) in enumerate(zip(professions, base_colors)):
        img = Image.new("RGBA", (32,32), (0,0,0,0))
        draw = ImageDraw.Draw(img)
        draw.ellipse([8,4,24,20], fill=color)  # głowa
        draw.rectangle([12,20,20,30], fill=(100,100,100))  # korpus
        img.save(f"assets/char_{name}.png")

generate_tileset()
generate_characters()
print("ASSETY WYGENEROWANE: tileset.png + 6x char_*.png")