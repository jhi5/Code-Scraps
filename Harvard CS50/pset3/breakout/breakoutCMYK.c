//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// height and width of paddle in pixels
#define PHEIGHT 50
#define PWIDTH 20

// height and width of bricks
#define BHEIGHT 25
#define BWIDTH 10

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    //instantiate timer
    GLabel timer = initScoreboard(window);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);
    
    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
    
    waitForClick();
    
    // establish velocity
    double vx = 2.0 + drand48();
    double vy = 2.0 + drand48();
      
    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        updateScoreboard(window, label, points);       
        GObject object = detectCollision(window, ball);
        GEvent event = getNextEvent(MOUSE_EVENT);
        move(ball, vx, vy);
        pause(10);
           
        if (event != NULL)
        {
            // if the event was movement
            if (getEventType(event) == MOUSE_MOVED)
            {
                // ensure circle follows top cursor
                double x = getX(event);
                setLocation(paddle, x, 500);
            }
        }
        
        if (object != NULL)
        {
            if (object == paddle)
            {
                vy = -vy;
            }
            else if (strcmp(getType(object), "GRect") == 0)
            {
                vy = -vy;
                removeGWindow(window, object);
                points++;
            }
        }

     
        if (getY(ball) + getWidth(ball) >= getHeight(window))
        {
            vy = -vy;
        }
            
        if (getY(ball) + getWidth(ball) <= 0)
        {
            vy = -vy;
        }

        // bounce off right edge of window
        if (getX(ball) + getWidth(ball) >= getWidth(window))
        {
            vx = -vx;
        }

        // bounce off left edge of window
        if (getX(ball) + getWidth(ball) <= 0)
        {
            vx = -vx;
        }

            
    }
    
    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    int bx = 8;
    int by = 10;
    int i = 0;
    int j = 0;
    
    for (j = 0; j < 5; j++)
    {
        i = 0;
        bx = 10;
        by = 20 + (30 * j);
    
        do
        {    
        // ROWS and COLS are dimensions, 2 for loops, create grect & color
            GRect Bricks = newGRect(bx, by, BHEIGHT, BWIDTH);
            
            int r = rand() % 10;
            
            if (r == 1 || r == 5 || r == 9)
            {   
                setColor(Bricks, "CYAN");
            }
            
            if (r == 0 || r == 2 || r == 4 || r == 6 || r == 8 || r == 10)
            { 
            setColor(Bricks, "MAGENTA");
            }
            
            if (r == 7)
            {
                setColor(Bricks, "BLACK");
            }
            
            setFilled(Bricks, true);
            add(window, Bricks);
            bx = bx + 35;
            i = i + 1;
        } 
        while (i < 11);
        
    }

}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    // center of window
    GOval circle = newGOval(200, 300, 20, 20);
    setColor(circle, "LIGHT_GRAY");
    setFilled(circle, true);
    add(window, circle);
    return circle;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    GRect paddle = newGRect(200, 500, PHEIGHT, PWIDTH);
    setColor(paddle, "YELLOW");
    setFilled(paddle, true);
    add(window, paddle);
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    GLabel label = newGLabel("");
    setFont(label, "SansSerif-50");
    setColor(label, "GRAY");
    add(window, label);
    setLocation(label, 50, 570);
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i bricks", points);
    setLabel(label, s);

    // center label in window
    double x = 50;
    double y = 570;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
