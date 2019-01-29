#include <stdlib.h>
#include <X11/Xlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>


#include "vroot.h"

#define NCOLORS 2
//#define TIME 100
#define NOISE 10 //assert NOISE != -1
#define ZOOM 1 //assert ZOOM != 0

void my_sleep(int milliseconds){
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
}

int8_t ** addPentominoR(int8_t **grid, int height, int width, int y, int x){

    grid[y][x] = 1;
    grid[y][(x+1)%width] = 1;
    grid[(y+1)%height][(x+1)%width] = 1;
    grid[(y+2)%height][(x+1)%width] = 1;
    grid[(y+1)%height][(x+2)%width] = 1;

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

int8_t ** updateGrid(int8_t ** grid, int height, int width){
    int x, y;

    //Create a duplicated version of the grid named matrix
    int8_t ** matrix = malloc(sizeof(*grid) * height);
    for (y = 0; y < height; y++) {
        matrix[y] = malloc(sizeof(**grid) * width);
        for (x = 0; x < width; x++) {
            matrix[y][x] = grid[y][x];
        }
    }

    //Update the grid
    for(y=0; y<height; y++) {
        for(x=0; x<width; x++) {
            int8_t neighbors = getNumberOfNeighbors(matrix, height, width, x, y);
            if (neighbors==3)
                grid[y][x] = 1;
            else if((neighbors>3) || (neighbors <2))
                grid[y][x] = 0;
        }
    }

    //Add random pentomino
    if(1 == (int)(rand() / (double)RAND_MAX * (NOISE - 1)))
        addPentominoR(grid, height, width, (int) (rand() / (double)RAND_MAX * height),
                      (int) (rand() / (double)RAND_MAX * width));


    //Suppression of the duplicated version
    for (y = 0; y < height; y++) {
        free(matrix[y]);
    }
    free(matrix);

    return grid;
}

/*TODO :
 * - Finir de trouver tous les hyperparamètres
 * - Trouver la bonne taille de block pour qu'il n'y ait pas un ligne noir en bas et à droite
 * - Créer un .xml pour le xscreensaver
 * - Push sur mon git perso
 */


int main (int argc, char *argv[]) {
    
    /*** INITIALIZATION ***/
    int screenWidth = 850;
    int screenHeight = 650;

    int widthOffset = (screenWidth%ZOOM)/2;
    int heightOffset = (screenHeight%ZOOM)/2;

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


    for(c=0; c<NCOLORS; c++) {
        //create GC for drawing in the window
        gColors[c] = XCreateGC (dpy, window, 0, NULL);
        XSetForeground(dpy, gColors[c], xColors[c].pixel);
    }

    /* create and clear the double buffer */
    double_buffer = XCreatePixmap(dpy, window, (unsigned int) wa.width, (unsigned int) wa.height, (unsigned int) wa.depth);


    while(1){
        for(y=0; y<height; y++) {
            for(x=0; x<width; x++) {
                int y2, x2;
                for(y2=y*ZOOM+heightOffset; y2<(y + 1)*ZOOM+heightOffset; y2++){
                    for(x2=x*ZOOM+widthOffset; x2<(x + 1)*ZOOM+widthOffset; x2++){
                        XDrawPoint(dpy, double_buffer, gColors[(int)grid[y][x]], x2, y2);
                    }
                }
            }
        }

        grid = updateGrid(grid, height, width);
//        my_sleep(TIME);

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
