// #include <graphics.h>
// #include <stdio.h>
// #include <math.h>
// #include <stdlib.h>
// #include <time.h>

// #define PI 3.14159265358979323846

// int main()
// {
//     int gd = DETECT, gm;
//     int i, j;
//     double angle, x, y;
//     int colors[] = {
//         RED, BLUE, GREEN, YELLOW,
//         CYAN, MAGENTA, LIGHTRED, LIGHTMAGENTA
//     };

//     initgraph(&gd, &gm, "");

//     setbkcolor(BLACK);
//     cleardevice();

//     srand(time(NULL));

//     for (i = 0; i < 120; i++)
//     {
//         angle = i * (PI * 2) / 120;

//         /* Heart equation */
//         x = 16 * pow(sin(angle), 3) * 12;

//         y = (
//             13 * cos(angle)
//             - 5 * cos(2 * angle)
//             - 2 * cos(3 * angle)
//             - cos(4 * angle)
//         ) * 12;

//         /* Screen center */
//         int startX = getmaxx() / 2;
//         int startY = getmaxy() / 2;

//         int endX = startX + (int)x;
//         int endY = startY - (int)y;

//         /* Random color */
//         setcolor(colors[rand() % 8]);

//         /* Draw line from center to heart */
//         line(startX, startY, endX, endY);

//         /* Small star effect */
//         for (j = 0; j < 8; j++)
//         {
//             double a = j * PI / 4;

//             int sx = endX + (int)(6 * cos(a));
//             int sy = endY + (int)(6 * sin(a));

//             line(endX, endY, sx, sy);
//         }
//     }

//     getch();
//     closegraph();

//     return 0;
// }