# Design Document

Particle engine in C

## Overview

This application will print an coffee mug to the standard output and start rendering steam purely with asci characters


## Flowchart

1. Create a matrix for the coordinates of cup and the particles
    - For the particles use a number defining how likely the particle character will be a smaller looking particle
    - For the cup itself use a string
    - For the empty whitespace characters use the value -1
2. Use a function to print the assci characters to stout (Should be characters for coffee cup)
3. Use a function To render particles.
    - Create a array of characters (e.g. [#, /, *, .,])
    - Use a random value -1 - + 1 to offset the value of the particle coordinate to generate the random particle effect.
4. Done, simple right

