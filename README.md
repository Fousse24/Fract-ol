# Fract-ol
###### Headache generator.


## Description
**Fractal visualizer** using a minimalistic CPU graphical library (MiniLibX)  
It supports Mandelbrot, Julia and Burning ship.  
I might revisit this project considering I was quite limited by the subject's restrictions.
  
<img alt="Mandelbrot image" src="/images/mandelbrot.png" width="200" height="200" align="left">
<img alt="Psychedelic image" src="/images/psychedelic2.png" height="200" align="left">
<img alt="Julia image" src="/images/julia.png" width="200" height="200" align="left">
<img alt="Mandelbrot image" src="/images/burning.png" width="200" height="200">
  
https://user-images.githubusercontent.com/84586535/212990072-89dd1c19-c65a-42fa-9623-ac956cf6f38c.mov
  
## What it does
- When running the program through the console, the user specifies, minimally, the fractal type they wants to print.
- The program parses and validates the arguments and print the fractal.
- You can then manipulate the fractal and change to other fractal types on the go!

## Personal thoughts
I had a **lot** of fun, but I am a bit disappointed that I'm still not confortable enough with complex numbers after all of this.  
  
If I was to work on it again, I would:
- Have it work on Windows and Linux too;
- Add the <a href="https://en.wikipedia.org/wiki/Newton_fractal">Newton fractal</a>;
- Create an UI system with the MiniLibX with a homemade event subscription system for the UI;
- Implements threads and smoother rendering;
- Make it render at 30 FPS or 60 FPS using system time to calculate frame duration (which I couldn't use at the time).

  
## How it works (roughly)
After parsing the user input, the hook functions (keys, mouse and loop) are set up.  
  
<img alt="MLX hook code image" src="/images/code_hook.png" height="215">
  
  
The loop function calculates the fractal depth for every pixel, clear the window and reprint the fractal on a given interval.  
  
<img alt="Loop code image" src="/images/code_loop.png" height="190">  
  
  
  
To calculate the depths, the plotting function will execute the corresponding fractal math function for every pixel.  
That function is saved in the active fractal structure as a function pointer taking a <a href="https://en.wikipedia.org/wiki/Complex_number">complex number</a> as argument. In my case, the number is a struct that contains the real and imaginary part of the number.  
  
The deeper it is, the stronger the color will be shifted towards the floor's color.  
  
<img alt="Plotting code image" src="/images/code_plot.png" height="420">  
  
  
Mandelbrot, Julia and Burning Ship' formulas resolve around iterating constantly using the previous iteration's result.  
My Mandelbrot and Burning Ship implementations look like this:  
  
<img alt="Mandelbrot math image" src="/images/code_mandelbrot.png" height="270">
<img alt="Burning Ship math image" src="/images/code_burningship.png" height="55">  
  
## How to run (MacOS only)
- Clone the repository;
- run "make" on the console in the root directory;
- run "./fractol [fractal_type]". The types are m, j or b.

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


  




