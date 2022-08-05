<h1>Console ASCII "game" demo</h1>

There is the Wolf and it can move and jump under the starry sky in Linux termial.
The program uses `gcc` and `ncurses`, so make shure you have them on your system.
After installing all dependencies simply launch make in repository root:

        make
        cd build/
        ./main

Resize your terminal if you see only stars.

Future plans:
- Implement feature of raw input from keyboard to overcome delay in repeated key presses
- Screen moving instead of Wolf moving
- Move to SDL
