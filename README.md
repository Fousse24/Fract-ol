# Fract-ol
###### Headache generator.

## Description
**Fractal visualizer** using a minimalistic CPU graphical library (MiniLibX)  
You can **move** the fractal using your keyboard and **zoom** via the mouse wheel (almost infinitely)
  
<img alt="Mandelbrot image" src="/images/mandelbrot.png" width="200" height="200" align="left">
<img alt="Mandelbrot image" src="/images/psychedelic2.png" height="200" align="left">
<img alt="Mandelbrot image" src="/images/julia.png" width="200" height="200" align="left">
<img alt="Mandelbrot image" src="/images/burning.png" width="200" height="200">
![julia animation video](/videos/julia_anim.mov)  
  
## What it does
- When running the program through the console, the user specifies, minimally, the fractal type he wants to print.
- The program parses and validates the arguments and print the fractal.
- You can then move with the arrows and zoom with the mouse

## Controls
escape : quit  
  
c : toggle color animation  
a : toggle Julia animation  
p : toggle psychedelic mode  
r : reset fractal  
  
arrows : move fractal  
mouse wheel : zoom in/out  
  
m j b : print Mandelbrot, Julia or "Burning ship" respectively  
1 to 9 : change Julia's parameter (when printing a Julia fractal)

## How it works
- After parsing the user input, the loop function is passed to the MiniLibX's loop hook
- The program parses and validates the arguments and print the fractal.
- You can then move with the arrows and zoom with the mouse



