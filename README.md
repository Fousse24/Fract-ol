# Fract-ol
###### Headache generator.

## Description
**Fractal visualizer** using a minimalistic CPU graphical library (MiniLibX)  
It supports Mandelbrot, Julia and Burning ship
  
<img alt="Mandelbrot image" src="/images/mandelbrot.png" width="200" height="200" align="left">
<img alt="Psychedelic image" src="/images/psychedelic2.png" height="200" align="left">
<img alt="Julia image" src="/images/julia.png" width="200" height="200" align="left">
<img alt="Mandelbrot image" src="/images/burning.png" width="200" height="200">
  
https://user-images.githubusercontent.com/84586535/212990072-89dd1c19-c65a-42fa-9623-ac956cf6f38c.mov
  
## What it does
- When running the program through the console, the user specifies, minimally, the fractal type he wants to print.
- The program parses and validates the arguments and print the fractal.
- You can then manipulate the fractal and change to other fractal types on the go!

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
After parsing the user input, the hook functions (keys, mouse and loop) are set up.
  
<img alt="MLX hook code image" src="/images/code_hook.png" height="300">
  
The loop function calculate the fractal depth for every pixel, clear the window and reprint the fractal on a given interval.
  
<img alt="Loop code image" src="/images/code_loop.png" height="300">





