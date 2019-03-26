#include <stdlib.h>
#include <X11/Xlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>


#include "vroot.h"

int8_t ** addPentominoR(int8_t **grid, int height, int width, int y, int x){
    
    int randx = (int) (rand() / (double)RAND_MAX * 2) == 0 ? 1 : -1;
    int randy = (int) (rand() / (double)RAND_MAX * 2) == 0 ? 1 : -1;

    grid[y][x] = 1;
    grid[y][(x+1*randx)%width] = 1;
    grid[(y+1*randy)%height][(x+1*randx)%width] = 1;
    grid[(y+2*randy)%height][(x+1*randx)%width] = 1;
    grid[(y+1*randy)%height][(x+2*randx)%width] = 1;

    return grid;
}

int8_t ** addGland(int8_t **grid, int height, int width, int y, int x){

    
    int randx = (int) (rand() / (double)RAND_MAX * 2) == 0 ? 1 : -1;
    int randy = (int) (rand() / (double)RAND_MAX * 2) == 0 ? 1 : -1;

    grid[(y+2*randy)%height][(x)%width] = 1;
    grid[(y)%height][(x+1*randx)%width] = 1;
    grid[(y+2*randy)%height][(x+1*randx)%width] = 1;
    grid[(y+1*randy)%height][(x+3*randx)%width] = 1;
    grid[(y+2*randy)%height][(x+4*randx)%width] = 1;
    grid[(y+2*randy)%height][(x+5*randx)%width] = 1;
    grid[(y+2*randy)%height][(x+6*randx)%width] = 1;

    return grid;
}

int8_t ** addLapins(int8_t **grid, int height, int width, int y, int x){

    
    int randx = (int) (rand() / (double)RAND_MAX * 2) == 0 ? 1 : -1;
    int randy = (int) (rand() / (double)RAND_MAX * 2) == 0 ? 1 : -1;

    grid[(y+1*randy)%height][(x)%width] = 1;
    grid[(y+2*randy)%height][(x+1*randx)%width] = 1;
    grid[(y+3*randy)%height][(x+1*randx)%width] = 1;
    grid[(y+1*randy)%height][(x+2*randx)%width] = 1;
    grid[(y)%height][(x+4*randx)%width] = 1;
    grid[(y+1*randy)%height][(x+5*randx)%width] = 1;
    grid[(y+2*randy)%height][(x+5*randx)%width] = 1;
    grid[(y)%height][(x+6*randx)%width] = 1;
    grid[(y+3*randy)%height][(x+7*randx)%width] = 1;


    return grid;
}

int8_t ** addPuffer1(int8_t **grid, int height, int width, int y, int x){

    
    int randx = (int) (rand() / (double)RAND_MAX * 2) == 0 ? 1 : -1;
    int randy = (int) (rand() / (double)RAND_MAX * 2) == 0 ? 1 : -1;

    grid[(y+1*randy)%height][(x)%width] = 1;
    grid[(y+3*randy)%height][(x)%width] = 1;
    grid[(y)%height][(x+1*randx)%width] = 1;
    grid[(y+1*randy)%height][(x+2*randx)%width] = 1;
    grid[(y+4*randy)%height][(x+2*randx)%width] = 1;
    grid[(y+3*randy)%height][(x+3*randx)%width] = 1;
    grid[(y+4*randy)%height][(x+3*randx)%width] = 1;
    grid[(y+5*randy)%height][(x+3*randx)%width] = 1;


    return grid;
}

int8_t ** addPuffer2(int8_t **grid, int height, int width, int y, int x){

    
    int randx = (int) (rand() / (double)RAND_MAX * 2) == 0 ? 1 : -1;
    int randy = (int) (rand() / (double)RAND_MAX * 2) == 0 ? 1 : -1;

    grid[(y+5*randy)%height][(x)%width] = 1;
    grid[(y+4*randy)%height][(x+2*randx)%width] = 1;
    grid[(y+5*randy)%height][(x+2*randx)%width] = 1;
    grid[(y+1*randy)%height][(x+4*randx)%width] = 1;
    grid[(y+2*randy)%height][(x+4*randx)%width] = 1;
    grid[(y+3*randy)%height][(x+4*randx)%width] = 1;
    grid[(y)%height][(x+6*randx)%width] = 1;
    grid[(y+1*randy)%height][(x+6*randx)%width] = 1;
    grid[(y+2*randy)%height][(x+6*randx)%width] = 1;
    grid[(y+1*randy)%height][(x+7*randx)%width] = 1;



    return grid;
}

int8_t ** addPuffer3(int8_t **grid, int height, int width, int y, int x){

    
    int randx = (int) (rand() / (double)RAND_MAX * 2) == 0 ? 1 : -1;
    int randy = (int) (rand() / (double)RAND_MAX * 2) == 0 ? 1 : -1;

    grid[(y)%height][(x)%width] = 1;
    grid[(y+1*randy)%height][(x)%width] = 1;
    grid[(y+4*randy)%height][(x)%width] = 1;
    grid[(y)%height][(x+1*randx)%width] = 1;
    grid[(y+3*randy)%height][(x+1*randx)%width] = 1;
    grid[(y)%height][(x+2*randx)%width] = 1;
    grid[(y+3*randy)%height][(x+2*randx)%width] = 1;
    grid[(y+4*randy)%height][(x+2*randx)%width] = 1;
    grid[(y+2*randy)%height][(x+3*randx)%width] = 1;
    grid[(y*randy)%height][(x+4*randx)%width] = 1;
    grid[(y+2*randy)%height][(x+4*randx)%width] = 1;
    grid[(y+3*randy)%height][(x+4*randx)%width] = 1;
    grid[(y+4*randy)%height][(x+4*randx)%width] = 1;

    return grid;
}

int8_t ** addPuffer4(int8_t **grid, int height, int width, int y, int x){

    
    int randx = (int) (rand() / (double)RAND_MAX * 2) == 0 ? 1 : -1;

    grid[y][(x)%width] = 1;
    grid[y][(x+1*randx)%width] = 1;
    grid[y][(x+2*randx)%width] = 1;
    grid[y][(x+3*randx)%width] = 1;
    grid[y][(x+4*randx)%width] = 1;
    grid[y][(x+5*randx)%width] = 1;
    grid[y][(x+6*randx)%width] = 1;
    grid[y][(x+7*randx)%width] = 1;

    grid[y][(x+9*randx)%width] = 1;
    grid[y][(x+10*randx)%width] = 1;
    grid[y][(x+11*randx)%width] = 1;
    grid[y][(x+12*randx)%width] = 1;
    grid[y][(x+13*randx)%width] = 1;

    grid[y][(x+17*randx)%width] = 1;
    grid[y][(x+18*randx)%width] = 1;
    grid[y][(x+19*randx)%width] = 1;

    grid[y][(x+26*randx)%width] = 1;
    grid[y][(x+27*randx)%width] = 1;
    grid[y][(x+28*randx)%width] = 1;
    grid[y][(x+29*randx)%width] = 1;
    grid[y][(x+30*randx)%width] = 1;
    grid[y][(x+31*randx)%width] = 1;
    grid[y][(x+32*randx)%width] = 1;

    grid[y][(x+34*randx)%width] = 1;
    grid[y][(x+35*randx)%width] = 1;
    grid[y][(x+36*randx)%width] = 1;
    grid[y][(x+37*randx)%width] = 1;
    grid[y][(x+38*randx)%width] = 1;



    return grid;
}


int8_t getNumberOfNeighbors(int8_t ** grid, int height, int width, int x, int y){
    int8_t nombreDeVoisin=0;
    for(int j = y-1; j<=y + 1; j++){
        for (int i = x-1; i<=x + 1; i++){
            nombreDeVoisin+=grid[(j+height)%height][(i+width)%width];
        }
    }

    return nombreDeVoisin - grid[y%height][x%width];
}

int8_t ** updateGrid(int8_t ** grid, int16_t ** memoryGrid, int height, int width, int noise, int memorySize){
    int x, y;

    //Create a duplicated version of the grid named copy
    int8_t ** copy = malloc(sizeof(*grid) * height);
    for (y = 0; y < height; y++) {
        copy[y] = malloc(sizeof(**grid) * width);
        for (x = 0; x < width; x++) {
            copy[y][x] = grid[y][x];
        }
    }

    //Update the grid
    for(y=0; y<height; y++) {
        for(x=0; x<width; x++) {
            int8_t neighbors = getNumberOfNeighbors(copy, height, width, x, y);
            if (neighbors==3)
                grid[y][x] = 1;
            else if((neighbors>3) || (neighbors <2))
                grid[y][x] = 0;

            //Check if one block stay at the same position
            if(grid[y][x] == 1 && (copy[y][x] == 1 || memoryGrid[y][x]>=memorySize)){
                memoryGrid[y][x]++;
                if(memoryGrid[y][x]>=memorySize) grid[y][x] = 0;
            }
            else memoryGrid[y][x]=0;
        }
    }

    //Add random motif
    int randomValue = (int)(rand() / (double)RAND_MAX * (noise - 1));
    switch (randomValue)
    {
        case 1:
            addPentominoR(grid, height, width, (int) (rand() / (double)RAND_MAX * height),
                          (int) (rand() / (double)RAND_MAX * width));
            break;
        case 2:
            addGland(grid, height, width, (int) (rand() / (double)RAND_MAX * height),
                     (int) (rand() / (double)RAND_MAX * width));
            break;
        case 3:
            addLapins(grid, height, width, (int) (rand() / (double)RAND_MAX * height),
                      (int) (rand() / (double)RAND_MAX * width));
            break;
        case 4:
            addPuffer1(grid, height, width, (int) (rand() / (double)RAND_MAX * height),
                       (int) (rand() / (double)RAND_MAX * width));
            break;
        case 5:
            addPuffer2(grid, height, width, (int) (rand() / (double)RAND_MAX * height),
                       (int) (rand() / (double)RAND_MAX * width));
            break;
        case 6:
            addPuffer3(grid, height, width, (int) (rand() / (double)RAND_MAX * height),
                       (int) (rand() / (double)RAND_MAX * width));
            break;
        case 7:
            addPuffer4(grid, height, width, (int) (rand() / (double)RAND_MAX * height),
                       (int) (rand() / (double)RAND_MAX * width));
            break;
    }



    //Suppression of the duplicated version
    for (y = 0; y < height; y++) {
        free(copy[y]);
    }
    free(copy);

    return grid;
}


/*TODO :
 * - Finir de trouver tous les hyperparamètres
 * - Trouver la bonne taille de block pour qu'il n'y ait pas un ligne noir en bas et à droite
 * - Créer un .xml pour le xscreensaver
 * - Push sur mon git perso
 */


int main (int argc, char *argv[]) {

    srand((unsigned int) time(NULL)); // initialisation de rand

    /** HYPERPARAMETERS **/
#define ZOOM 1 //assert ZOOM != 0
#define NCOLORS 2
#define NOISE 250//10 //assert NOISE != -1
#define MEMORY 800
#define HALF_STEP 0

    /*** INITIALIZATION ***/
    int screenWidth = 850;
    int screenHeight = 650;

    Display *dpy;
    Window window;
    GC gColors[NCOLORS];
    Pixmap double_buffer;
    XEvent e, xev;
    XWindowAttributes wa;
    char *colors[NCOLORS] = {"black", "white"};
    XColor xColors[NCOLORS];
    XColor xc, sc;
    int c, x, y;
    dpy = XOpenDisplay(getenv("DISPLAY"));

    for (c = 0; c < NCOLORS; c++) {
        XAllocNamedColor(dpy, DefaultColormapOfScreen(DefaultScreenOfDisplay(dpy)), colors[c], &sc, &xc);
        xColors[c] = sc;
    }

    if (argc == 1) {
        /* get caracteristics of root window */
        XWindowAttributes wa2;
        Window window2 = DefaultRootWindow (dpy);
        XGetWindowAttributes(dpy, window2, &wa2);
        screenWidth = wa2.width;
        screenHeight = wa2.height;
        printf("%d %d\n", screenHeight, screenWidth);
    }

    /* create, name, and map window */
    window = XCreateSimpleWindow(dpy, DefaultRootWindow (dpy), 0, 0, (unsigned int) screenWidth,
                                 (unsigned int) screenHeight, 1,
                                 BlackPixel (dpy, DefaultScreen(dpy)), WhitePixel (dpy, DefaultScreen(dpy)));
    XSelectInput (dpy, window, StructureNotifyMask);
    XMapRaised (dpy, window);
    do {
        XWindowEvent (dpy, window, StructureNotifyMask, &e);
    } while( e.type != MapNotify );


    //Get window attribut
    XGetWindowAttributes(dpy, window, &wa);


    int height = wa.height/ZOOM, width = wa.width/ZOOM;

    //Création dynamique de la grille
    int8_t ** grid = malloc(sizeof(*grid) * height);
    for (c = 0; c < height; c++) {
        grid[c] = malloc(sizeof(**grid) * width);
        int c2;
        for (c2=0; c2<width; c2++){
            grid[c][c2]=0;
        }
    }

    //Création dynamique de la grille
    int16_t ** memoryGrid = malloc(sizeof(*memoryGrid) * height);
    for (c = 0; c < height; c++) {
        memoryGrid[c] = malloc(sizeof(**memoryGrid) * width);
        int c2;
        for (c2=0; c2<width; c2++){
            memoryGrid[c][c2]=0;
        }
    }

    //Add starting motif
    //addPuffer4(grid, height, width, height/2, width/2);


    for(c=0; c<NCOLORS; c++) {
        //create GC for drawing in the window
        gColors[c] = XCreateGC (dpy, window, 0, NULL);
        XSetForeground(dpy, gColors[c], xColors[c].pixel);
    }

    /* create and clear the double buffer */
    double_buffer = XCreatePixmap(dpy, window, (unsigned int) wa.width, (unsigned int) wa.height, (unsigned int) wa.depth);


    addPentominoR(grid, height, width, 300, 400);

    while(1){
        for(y=0; y<height; y++) {
            for(x=0; x<width; x++) {
                XDrawPoint(dpy, double_buffer, gColors[(int)grid[y][x]], x, y);
            }
        }

        grid = updateGrid(grid, memoryGrid, height, width, NOISE, MEMORY);

        /* copy the buffer to the window */
        XCopyArea(dpy, double_buffer, window, gColors[1],0, 0, (unsigned int) wa.width, (unsigned int) wa.height, 0, 0);



        //Memory overflow is not comment
        /*if( XCheckWindowEvent(dpy, window, ExposureMask, &e) ) {
            while( XCheckWindowEvent(dpy, window, ExposureMask, &e) );

            XGetWindowAttributes (dpy, window, &wa);
            double_buffer = XCreatePixmap(dpy, window, (unsigned int) wa.width, (unsigned int) wa.height, (unsigned int) wa.depth);
        }*/
    }

    //Suppression dynamique de la grille
    for (c = 0; c < height; c++) {
        free(grid[c]);
    }
    free(grid);


    XCloseDisplay (dpy);
    return 0;
}
