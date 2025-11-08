# font_generator.py
from PIL import Image, ImageDraw
font_img = Image.new("RGBA", (256, 8), (0,0,0,0))
draw = ImageDraw.Draw(font_img)
chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!?-+*/=<>[]{} "
for i, c in enumerate(chars):
    x = i * 8
    if c == 'A': draw.text((x+1,0), c, fill=(255,255,100), font=None)
    # ... (pełny font w 2 minuty)
font_img.save("assets/font.png")