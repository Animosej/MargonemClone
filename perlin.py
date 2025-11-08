# perlin.py → export to C++ header
import noise
import numpy as np
world = np.zeros((150,200))
for y in range(150):
    for x in range(200):
        world[y][x] = int(noise.pnoise2(x/50.0, y/50.0, octaves=6) * 10) % 5
np.savetxt("world_map.h", world, fmt="%d", header="// AUTO-GENERATED WORLD")