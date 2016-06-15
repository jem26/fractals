# Report

#### User Function

For this lab, a graphics window was produced that would display various fractal shapes, determined by the user’s selection. Hitting the number keys would display that particular fractal, and pressing ‘q’would quit the program. The user is not able to change any aspect of the fractal, they just pick which one they want displayed. 

#### Internal Function

Internally, the program works by using many recursive functions. The standard gfx window is produced,  and then there is a switch statement that calls the various fractal functions based on what the user picks from. In these functions in main, an initial value is chosen for each of the functions that will center it and  make it look similar to the examples provided. To make each fractal, the function is only called once in  main. After that, the function keeps getting called within the function itself until the base case is reached. For each function, a base case was chosen that would show enough of the recursion, but not make the  fractal too repetitive. If this base case was reached, then the function would return its values and draw  the fractal. Until this base case is reached, the recursive function would keep adding to its stack of values, which would then be drawn. When the function was recursively called again each time, the function’s values would be changed based on their previous values. This is the essence of recursion. 

#### Internal Logic

To discuss a particular fractal’s internal workings, the spiral of squares fractal can be examined. In this  particular fractal, the variables of the function are the radius of the spiral and the angle that the spiral is at. The initial values in the function are a radius of 350, which is slightly less than half of the display window, and 0, which means the large end of the spiral will start on the middle right side of the screen. For this  spiral to be created, it is essentially like drawing points on a circle, but reducing the radius each time so it  gets closer to the center, and also adjusting the theta value so that it moves around clockwise or  counterclockwise. I set the base case to be 3. This means that once a square was drawn with a size length less than 3, the function would return its values. I drew the rectangles using gfx_rectangle, and using  trigonometry to find the x and y values of the upper left corner of the squares to be drawn. I also made the length and width of the squares to be 1/5 the current radius, so that the radius of the squares would also  decrease when they got closer to the center of the spiral. Then, to recursively call the function, I called the function again but with a slightly smaller radius, and adding 0.5 to the theta to advance the circular path of the spiral around. 

#### Code Verification

I verified that the output of the program was correct by comparing my drawn fractals with the examples. They all looked correct, so I knew that the correct output was being produced. Another way I understood exactly how the recursion was taking place was by adding pauses in between the drawing steps so I  could watch the fractals being drawn. Since they were being drawn in a way that suggested recursion, based on what we saw in lecture, I was again able to verify that these were the correct outputs. 
