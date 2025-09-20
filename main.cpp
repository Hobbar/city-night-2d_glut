#include<windows.h>
#ifdef __APPLE__
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif
#include<stdlib.h>
#include<math.h>

float p = 140;      // for cars right to left
float p1 = 0;       // for cars left to right
float w = 0;        // for water line
float c = 0;        // for cloud
float c1 = 0;       // for cloud
float b = 50;       // for ship
float b1 = 0;       // for airplane

void DrawCircle(float cx, float cy, float rx,float ry, int num_segments)
{
	glBegin(GL_TRIANGLE_FAN);
	for(int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

		float x = rx * cosf(theta);//calculate the x component
		float y = ry * sinf(theta);//calculate the y component

		glVertex2f(x + cx, y + cy);//output vertex

	}
	glEnd();
}

void display(void)
{

if(p>=-145)                  // for cars right to left
p = p-0.05;
else
p = 145;

if(p1<=+260)                  // for cars left to right
p1 = p1+0.05;
else
p1=-95;

if(w>=-1440)                   // for water line
w = w-0.002;
else
w=+145;

if(c>= -640)                   // for cloud
c = c-0.005;
else
c = +145;

if(c1>= -157)                   // for cloud
c1 = c1-0.005;
else
c1 = +7;

if(b>= -16)                    // for ship
b = b-0.009;
else
b = 137;

if(b1>= -132)                  // for airplane
b1 = b1-0.02;
else
b1 = 20;


glClear(GL_COLOR_BUFFER_BIT);
glutPostRedisplay();
glPushMatrix();

    glColor3ub(61, 119,200);
    glBegin(GL_QUADS);       //........ water
         glVertex2f(00,20);
         glVertex2f(140,20);
    glColor3f(0,0,.4);
         glVertex2f(140,00);
         glVertex2f(0,0);
    glEnd();

    glColor3f(0,0,.3);   //.......... sky
    glBegin(GL_QUADS);
         glVertex2f(0,80);
         glVertex2f(140,80);
        glColor3ub(61, 119,200);
         glVertex2f(140,60);
         glVertex2f(0,60);
    glEnd();

//.................moon......................
	 glColor3f(01, 01, 01);
     DrawCircle(108,72,5,5,200);

//...........cloud..........................

     glColor3f(0.9, 0.9, 0.9);
     DrawCircle(c/10+ 8,72,5,4,200);    // cloud 1
     DrawCircle(c/10+ 12,70,5,4,200);
     DrawCircle(c/10+ 18,70,5,4,200);
     DrawCircle(c/10+ 22,72,5,4,200);
     DrawCircle(c/10+ 12,74,6,4,200);
     DrawCircle(c/10+ 18,74,5,4,200);

     DrawCircle(c/3+ 8+60,72,5,4,200);    // cloud 2
     DrawCircle(c/3+ 12+60,70,5,4,200);
     DrawCircle(c/3+ 18+60,70,5,4,200);
     DrawCircle(c/3+ 22+60,72,5,4,200);
     DrawCircle(c/3+ 12+60,74,6,4,200);
     DrawCircle(c/3+ 18+60,74,5,4,200);

     DrawCircle(c1/10+ 8+130,72,5,4,200);    // cloud 3
     DrawCircle(c1/10+ 12+130,70,5,4,200);
     DrawCircle(c1/10+ 18+130,70,5,4,200);
     DrawCircle(c1/10+ 22+130,72,5,4,200);
     DrawCircle(c1/10+ 12+130,74,6,4,200);
     DrawCircle(c1/10+ 18+130,74,5,4,200);


glColor3f(.4,.4,.4);      // bridge
glBegin(GL_QUADS);
     glVertex2f(0,26);
     glVertex2f(140,26);
         glColor3f(.3,.3,.3);
     glVertex2f(140,20);
     glVertex2f(0,20);
glEnd();

glColor3f(0,0,0);               // bridge line
glBegin(GL_LINES);
     glVertex2f(0,20);
     glVertex2f(140,20);
glEnd();

//...................water line..........................

     glColor3f(1,1,1);
for(int x=0; x<400; x++)        // 1st water line
{
    glBegin(GL_LINES);
        glVertex2f(w/1.5 +x*10+0, 2);
        glVertex2f(w/1.5 +x*10+1, 2);
    glEnd();
}

for(int x=0; x<4000; x++)             //2nd water line
{
    glBegin(GL_LINES);
        glVertex2f(w/2+x*9+0, 4);
        glVertex2f(w/2+x*9+.9, 4);
    glEnd();
}

for(int x=0; x<4000; x++)        // 3rd water line
{
    glBegin(GL_LINES);
        glVertex2f(w/2.5+ x*8+0, 6);
        glVertex2f(w/2.5+ x*8+.8, 6);
    glEnd();
}

for(int x=0; x<4000; x++)        // 4th water line
{
    glBegin(GL_LINES);
        glVertex2f(w/3+ x*7+0, 8);
        glVertex2f(w/3+ x*7+.8, 8);
    glEnd();
}

for(int x=0; x<4000; x++)        // 5th water line
{
    glBegin(GL_LINES);
        glVertex2f(w/3.5+ x*6+0, 10);
        glVertex2f(w/3.5+ x*6+.7, 10);
    glEnd();
}
for(int x=0; x<4000; x++)        // 6th water line
{
    glBegin(GL_LINES);
        glVertex2f(w/4+ x*5+0, 12);
        glVertex2f(w/4+ x*5+.7, 12);
    glEnd();
}
for(int x=0; x<4000; x++)        // 7th water line
{
    glBegin(GL_LINES);
        glVertex2f(w/4.7+ x*5+0, 14);
        glVertex2f(w/4.7+ x*5+.7, 14);
    glEnd();
}
for(int x=0; x<4000; x++)        // 8th water line
{
    glBegin(GL_LINES);
        glVertex2f(w/4.4+ x*4+0, 15);
        glVertex2f(w/4.4+ x*4+.7, 15);
    glEnd();
}
for(int x=0; x<4000; x++)        // 9th water line
{
    glBegin(GL_LINES);
        glVertex2f(w/5+ x*2.6+0, 16);
        glVertex2f(w/5+ x*2.6+.6, 16);
    glEnd();
}
for(int x=0; x<4000; x++)        // 10th water line
{
    glBegin(GL_LINES);
        glVertex2f(w/6+ x*2.4+0, 17);
        glVertex2f(w/6+ x*2.4+0.5, 17);
    glEnd();
}
for(int x=0; x<4000; x++)        // 11th water line
{
    glBegin(GL_LINES);
        glVertex2f(w/6+ x*2.2+0, 18);
        glVertex2f(w/6+ x*2.2+.4, 18);
    glEnd();
}
for(int x=0; x<4000; x++)        // 12th water line
{
    glBegin(GL_LINES);
        glVertex2f(w/7+ x*2+0,19);
        glVertex2f(w/7+ x*2+.3,19);
    glEnd();
}
//.........................ship....................

glColor3f(0,0,.6);
glBegin(GL_POLYGON);

    glVertex2f(b+ 3,7+3);
    glVertex2f(b+ 16,7+3);
    glColor3f(.73,.73,.73);
    glVertex2f(b+ 16,9+3);
    glVertex2f(b+ 1,9+3);

glEnd();
glColor3f(.73,.73,.73);
glBegin(GL_POLYGON);          //up
    glVertex2f(b+ 4,12);
    glVertex2f(b+ 14,12);
glColor3ub(178, 97, 105);
    glVertex2f(b +14,14);
    glVertex2f(b+ 4,14);
glEnd();

//....................... pillar......................
for(int x=0; x<6; x++)
    {
glBegin(GL_QUADS);
     glColor3f(.2,.2,.2);
     glVertex2f(x*28-10,20);
     glVertex2f(x*28+6,20);
     glColor3f(.3,.3,.3);
     glVertex2f(x*28+6,16);
     glVertex2f(x*28-10,16);
glEnd();
    }

    for(int x=0; x<6; x++)
    {
glBegin(GL_QUADS);
     glColor3f(.4,.4,.4);
     glVertex2f(x*28-6,16);
     glVertex2f(x*28+2,16);
     glColor3f(0,0,0);
     glVertex2f(x*28+2,8);
     glVertex2f(x*28-6,8);
glEnd();
    }
//....................building.................

glColor3ub(143, 38, 158);        // 2nd     building
     glRectf(6, 68, 20, 28);
glColor3f(0,0,0);
glBegin(GL_LINES);
     glVertex2f(6,60);
     glVertex2f(6,68);
glEnd();
glBegin(GL_LINES);
     glVertex2f(6,68);
     glVertex2f(20,68);
glEnd();
glBegin(GL_LINES);
     glVertex2f(20,68);
     glVertex2f(20,60);
glEnd();

     glColor3f(1,1,0);          // window
     for(int x=0; x<9; x++)
{
    glRectf(8, 32+4*x, 11, 34+4*x);
}
     glColor3f(1,1,0);          // window
     for(int x=0; x<9; x++)
{
    glRectf(15, 32+4*x, 18, 34+4*x);
}

glColor3ub(224, 63, 199);               // 1st  building
     glRectf(0, 60, 8, 28);
glColor3f(0,0,0);           //1st line
glBegin(GL_LINES);
     glVertex2f(0,60);
     glVertex2f(8,60);
glEnd();
glBegin(GL_LINES);
     glVertex2f(8,60);
     glVertex2f(8,28);
glEnd();

glColor3f(1,1,0);                // window
     glRectf(2, 32, 5, 34);
     glRectf(2, 32+4, 5, 34+4);
     glRectf(2, 32+8, 5, 34+8);
     glRectf(2, 32+12, 5, 34+12);
     glRectf(2, 32+16, 5, 34+16);
     glRectf(2, 32+20, 5, 34+20);
     glRectf(2, 32+24, 5, 34+24);

glColor3f(0,0,1);               // 5th  building
     glRectf(34, 70, 52, 28);
glColor3f(0,0,0);
glBegin(GL_LINES);
     glVertex2f(34,66);
     glVertex2f(34,70);
glEnd();
glBegin(GL_LINES);
     glVertex2f(34,70);
     glVertex2f(52,70);
glEnd();
glBegin(GL_LINES);
     glVertex2f(52,70);
     glVertex2f(52,60);
glEnd();

     glColor3f(1,1,0);       // window
     for(int x=0; x<10; x++)
{
    glRectf(37, 31+4*x, 40, 33+4*x);
}
     glColor3f(1,1,0);       // window
     for(int x=0; x<10; x++)
{
    glRectf(46, 31+4*x, 49, 33+4*x);
}
     glColor3f(1,1,0);       // window
     for(int x=1; x<10; x++)
{
    glRectf(42.5, 31+4*x, 43.5, 33+4*x);
}
    glRectf(41.5, 28, 44.5, 33);

glColor3ub(143, 38, 158);           // 4th  building
     glRectf(28, 66, 38, 28);
glColor3f(0,0,0);
glBegin(GL_LINES);
     glVertex2f(28,60);
     glVertex2f(28,66);
glEnd();
glBegin(GL_LINES);
     glVertex2f(28,66);
     glVertex2f(38,66);
glEnd();
glBegin(GL_LINES);
     glVertex2f(38,66);
     glVertex2f(38,28);
glEnd();
     glColor3f(1,1,0);          //window
     for(int x=0; x<9; x++)
{
    glRectf(31, 31+4*x, 35, 33+4*x);
}

glColor3f(1,0,0);              //3rd  building
     glRectf(18, 60, 30, 28);
glColor3f(0,0,0);
glBegin(GL_LINES);
     glVertex2f(18,28);
     glVertex2f(18,60);
glEnd();
glBegin(GL_LINES);
     glVertex2f(18,60);
     glVertex2f(30,60);
glEnd();
glBegin(GL_LINES);
     glVertex2f(30,60);
     glVertex2f(30,28);
glEnd();

     glColor3f(1,1,0);       // window
     for(int x=0; x<7; x++)
{
    glRectf(20, 32+4*x, 23, 34+4*x);
}
     glColor3f(1,1,0);       // window
     for(int x=0; x<7; x++)
{
    glRectf(26, 32+4*x, 28, 34+4*x);
}

glColor3ub(158, 61, 38);   //..........7th  building
     glRectf(56, 70, 72, 28);
glColor3f(0,0,0);
glBegin(GL_LINES);
     glVertex2f(56,60);
     glVertex2f(56,70);
glEnd();
glBegin(GL_LINES);
     glVertex2f(56,70);
     glVertex2f(72,70);
glEnd();
glBegin(GL_LINES);
     glVertex2f(72,70);
     glVertex2f(72,68);
glEnd();
     glColor3f(1,1,0);       //window
     for(int x=0; x<10; x++)
{
    glRectf(60, 31+4*x, 63, 33+4*x);
}
    glRectf(66,65,69,69);

glColor3ub(85, 0, 156);          //6th  building
     glRectf(48, 60, 60, 28);
glColor3f(0,0,0);
glBegin(GL_LINES);
     glVertex2f(48,28);
     glVertex2f(48,60);
glEnd();
glBegin(GL_LINES);
     glVertex2f(48,60);
     glVertex2f(60,60);
glEnd();
glBegin(GL_LINES);
     glVertex2f(60,60);
     glVertex2f(60,28);
glEnd();
     glColor3f(1,1,0);       //window
     for(int x=0; x<7; x++)
{
    glRectf(52.5, 31+4*x,55.5, 33+4*x);
}

glColor3ub(85, 0, 156);             //9th  building
     glRectf(76, 66, 90, 28);
glColor3f(0,0,0);
glBegin(GL_LINES);
     glVertex2f(78,66);
     glVertex2f(90,66);
glEnd();
glBegin(GL_LINES);
     glVertex2f(90,66);
     glVertex2f(90,62);
glEnd();
     glColor3f(1,1,0);       //window
     for(int x=0; x<9; x++)
{
    glRectf(82, 31+4*x,86, 33+4*x);
}

glColor3f(0,0,1);          //8th  building
     glRectf(64, 68, 78, 28);
glColor3f(0,0,0);
glBegin(GL_LINES);
     glVertex2f(64,28);
     glVertex2f(64,68);
glEnd();
glBegin(GL_LINES);
     glVertex2f(64,68);
     glVertex2f(78,68);
glEnd();
glBegin(GL_LINES);
     glVertex2f(78,68);
     glVertex2f(78,28);
glEnd();

     glColor3f(1,1,0);         //window
     for(int x=0; x<9; x++)
{
    glRectf(69, 31+4*x, 73, 33+4*x);
}

glColor3ub(222, 47, 47);            // 11th  building
     glRectf(100, 66, 116, 28);
glColor3f(0,0,0);
glBegin(GL_LINES);
     glVertex2f(100,60);
     glVertex2f(100,66);
glEnd();
glBegin(GL_LINES);
     glVertex2f(100,66);
     glVertex2f(116,66);
glEnd();
glBegin(GL_LINES);
     glVertex2f(116,66);
     glVertex2f(116,60);
glEnd();

     glColor3f(1,1,0);             //window
     for(int x=0; x<9; x++)
{
    glRectf(102, 31+4*x, 104, 33+4*x);
}
     glColor3f(1,1,0);             //window
     for(int x=0; x<9; x++)
{
    glRectf(105.5, 31+4*x, 109, 33+4*x);
}
     glColor3f(1,1,0);           //window
     for(int x=0; x<9; x++)
{
    glRectf(111, 31+4*x, 114, 33+4*x);
}

glColor3ub(143, 38, 158);             //10th  building
     glRectf(88, 62, 102, 28);
glColor3f(0,0,0);
glBegin(GL_LINES);
     glVertex2f(88,28);
     glVertex2f(88,62);
glEnd();
glBegin(GL_LINES);
     glVertex2f(88,62);
     glVertex2f(102,62);
glEnd();
glBegin(GL_LINES);
     glVertex2f(102,62);
     glVertex2f(102,28);
glEnd();
     glColor3f(1,1,0);               //window
     for(int x=0; x<8; x++)
{
    glRectf(90, 31+4*x,93, 33+4*x);
}
     glColor3f(1,1,0);                //window
     for(int x=0; x<8; x++)
{
    glRectf(97, 31+4*x, 99, 33+4*x);
}

glColor3f(0,0,1);                    //13th  building
     glRectf(126, 63, 140, 28);
glColor3f(0,0,0);
glBegin(GL_LINES);
     glVertex2f(126,60);
     glVertex2f(126,63);
glEnd();
glBegin(GL_LINES);
     glVertex2f(126,63);
     glVertex2f(140,63);
glEnd();
glBegin(GL_LINES);
     glVertex2f(140,63);
     glVertex2f(140,28);
glEnd();
     glColor3f(1,1,0);                //window
     for(int x=0; x<8; x++)
{
    glRectf(136, 31+4*x, 138, 33+4*x);
}
     glColor3f(1,1,0);               //window
     for(int x=0; x<8; x++)
{
    glRectf(128, 31+4*x, 132, 33+4*x);
}


glColor3ub(143, 38, 158);          //12th  building
     glRectf(114, 60, 130, 28);
glColor3f(0,0,0);
glBegin(GL_LINES);
     glVertex2f(114,28);
     glVertex2f(114,60);
glEnd();
glBegin(GL_LINES);
     glVertex2f(114,60);
     glVertex2f(130,60);
glEnd();
glBegin(GL_LINES);
     glVertex2f(130,60);
     glVertex2f(130,28);
glEnd();
     glColor3f(1,1,0);                //window
     for(int x=0; x<7; x++)
{
    glRectf(117, 32+4*x, 120, 34+4*x);
}
     glColor3f(1,1,0);                //window
     for(int x=0; x<7; x++)
{
    glRectf(124, 32+4*x, 127, 34+4*x);
}

//........................tree........................

for(int x=0; x<16; x++)//.............tree
{
    glColor3f(0,0,0);
         glRectf(x*10+3,36,x*10+4,28);
    glColor3f(0,.4,0);
    glBegin(GL_POLYGON);
         glVertex2f(x*10+1,32);
         glVertex2f(x*10+2,40);
         glVertex2f(x*10+3,36);
         glVertex2f(x*10+4,46);
         glVertex2f(x*10+6,32);
    glEnd();
}

//.....................road ...................

for(int x=0; x<16; x++)//............road light
{
    glColor3f(0.7,0.7,0.7);
         glRectf(x*10+ 3.5,36,x*10+ 3.7,28);
    glColor3f(01,01,0);
    DrawCircle(x*10+ 3.5,36,.5,.4,200);
}

glColor3f(.8,.8,0); //................road line
glBegin(GL_LINES);
     glVertex2f(0,26);
     glVertex2f(140,26);
glEnd();

glColor3f(.8,.7,0);  //..................road line
glBegin(GL_LINES);
     glVertex2f(0,27);
     glVertex2f(140,27);
glEnd();

glColor3f(.8,.5,0);  //..................road line
glBegin(GL_LINES);
     glVertex2f(0,28);
     glVertex2f(140,28);
glEnd();

//.................cars start.......................................

     glColor3ub(174, 30, 255);       //1st car

glBegin(GL_POLYGON);                 //body
          glVertex2f(p+25,30);
          glVertex2f(p+13,30);
          glColor3ub(0,0,0);
          glVertex2f(p+13,28);
          glVertex2f(p+25,28);

glEnd();

     glColor3ub(174, 30, 255);
glBegin(GL_POLYGON);
         glVertex2f(p+14,30);
         glVertex2f(p+24,30);
         glColor3ub(200,200,200);
         glVertex2f(p+22.5,32);
         glVertex2f(p+16,32);


glEnd();

     glColor3ub(130, 82, 6);        //door handle
     glRectf(p+17,30,p+18,29.5);
     glRectf(p+21,30,p+22,29.5);

glColor3ub(255, 255, 0);            //wheel
DrawCircle(p+16,28,1,1,200);
DrawCircle(p+22,28,1,1,200);

glColor3ub(0,0,0);                  //wheel
DrawCircle(p+16,28,.5,.5,200);
DrawCircle(p+22,28,.5,.5,200);

//.................................2nd car
     glColor3ub(200, 200, 0);
glBegin(GL_POLYGON);
         glVertex2f(p*1+ 82,28);       //body
         glVertex2f(p*1+ 80,28.5);
         glVertex2f(p*1+ 80,32);
    glColor3ub(200, 225, 50);
         glVertex2f(p*1+ 82,35);
         glVertex2f(p*1+ 96,35);
         glVertex2f(p*1+ 96,28);
glEnd();
     glColor3ub(130, 82, 6);        //window
glRectf(p*1+ 84,33,p*1+ 96,35);

     glColor3ub(130, 82, 6);        //door
glRectf(p*1+ 84,32,p*1+ 86,28);

glColor3ub(255, 255,0);               //wheel
DrawCircle(p*1+ 83,28,1,1,200);
DrawCircle(p*1+ 93,28,1,1,200);

glColor3ub(0,0,0);                    //wheel
DrawCircle(p*1+ 83,28,.5,.5,200);
DrawCircle(p*1+ 93,28,.5,.5,200);


//.............................3rd car
     glColor3ub(232, 24, 112);
glBegin(GL_POLYGON);                 //body
         glVertex2f(p+ 120+13,28);
         glVertex2f(p+ 120+13,30);
    glColor3ub(161, 26, 22);
         glVertex2f(p+ 120+25,30);
         glVertex2f(p+ 120+25,28);
glEnd();

     glColor3ub(161, 26, 222);
glBegin(GL_POLYGON);
         glVertex2f(p+ 120+14,30);
         glVertex2f(p+ 120+16,32);
    glColor3ub(232, 24, 112);
         glVertex2f(p+ 120+22.5,32);
         glVertex2f(p+ 120+24,30);
glEnd();

     glColor3ub(130, 82, 6);        //door handle
     glRectf(p+ 120+17,30,p+ 120+18,29.5);
     glRectf(p+ 120+21,30,p+ 120+22,29.5);

glColor3ub(255, 255, 0);             //wheel
DrawCircle(p+ 120+16,28,1,1,200);
DrawCircle(p+ 120+22,28,1,1,200);

glColor3ub(0,0,0);                   //wheel
DrawCircle(p+ 120+16,28,.5,.5,200);
DrawCircle(p+ 120+22,28,.5,.5,200);


//...................................................
//.................move left to right 1st car
     glColor3ub(116, 255, 0);

glBegin(GL_POLYGON);                 //body

         glVertex2f(p1/2+ 13,29.5);
         glVertex2f(p1/2+ 25,29.5);
         glColor3ub(0,0,0);
         glVertex2f(p1/2+ 25,27.5);
         glVertex2f(p1/2+ 13,27.5);
glEnd();

     glColor3ub(255, 105, 48);
glBegin(GL_POLYGON);

         glVertex2f(p1/2+ 16,31.5);
         glVertex2f(p1/2+ 22.5,31.5);
         glColor3ub(116, 255, 0);
         glVertex2f(p1/2+ 24,29.5);
         glVertex2f(p1/2+ 14,29.5);
glEnd();

     glColor3ub(130, 82, 6);          //door handle
     glRectf(p1/2+ 17,29.5,p1/2+ 18,29);
     glRectf(p1/2+ 21,29.5,p1/2+ 22,29);

glColor3ub(255, 255, 0);              //wheel
DrawCircle(p1/2+16,27.5,1,1,200);
DrawCircle(p1/2+22,27.5,1,1,200);

glColor3ub(0,0,0);                    //wheel
DrawCircle(p1/2+16,27.5,.5,.5,200);
DrawCircle(p1/2+22,27.5,.5,.5,200);

//............................
//....................move left to right 2nd car
     glColor3ub(225, 50, 50);

glBegin(GL_POLYGON);                 //body down

         glVertex2f(p1+83,29.5);
         glVertex2f(p1+95,29.5);
         glColor3ub(0,0,0);
         glVertex2f(p1+95,27.5);
         glVertex2f(p1+83,27.5);
glEnd();

     glColor3ub(255, 22, 131);
glBegin(GL_POLYGON);

         glVertex2f(p1+86,31.5);          // up
         glVertex2f(p1+92.5,31.5);
      glColor3ub(255, 105, 48);
         glVertex2f(p1+94,29.5);
         glVertex2f(p1+84,29.5);
glEnd();

     glColor3ub(130, 82, 6);         //door handle
     glRectf(p1+87,29.5,p1+88,29);
     glRectf(p1+91,29.5,p1+92,29);

glColor3ub(255, 255, 0);             //wheel
DrawCircle(p1+86,27.5,1,1,200);
DrawCircle(p1+92,27.5,1,1,200);

glColor3ub(0,0,0);                  //wheel
DrawCircle(p1+86,27.5,.5,.5,200);
DrawCircle(p1+92,27.5,.5,.5,200);

//..............road light........................
for(int x=0; x<16; x++)
{
    glColor3f(0.7,0.7,0.7);        //road light
         glRectf(x*10+ 5.5,34,x*10+ 5.7,26);
    glColor3f(01,01,0);
    DrawCircle(x*10+ 5.5,34,.5,.4,200);
}

//................airplain.........................
glColor3ub(25, 105, 176);
glBegin(GL_POLYGON);                 //body
         glVertex2f(b1+120,76);
         glVertex2f(b1+128,75);
    //glColor3ub(255, 105, 48);
         glVertex2f(b1+130,75);
         glVertex2f(b1+132,76);
         glVertex2f(b1+130,76);
         glVertex2f(b1+124,77);
glEnd();

glBegin(GL_POLYGON);                 //body
         glVertex2f(b1+130,76);
         glVertex2f(b1+132,76);
         glColor3ub(72, 75, 75);
         glVertex2f(b1+132,78);
         glVertex2f(b1+131,78);
glEnd();
         glColor3ub(72, 75, 75);
glBegin(GL_POLYGON);                 //body
         glVertex2f(b1+120,76);
         glVertex2f(b1+123,76);
         glVertex2f(b1+124,77);
glEnd();

glPopMatrix();
glFlush();
}

void init(void)
{
glClearColor(0.0,0.0,0.0,0.0);
glOrtho(-0.0, 140.0, -0.0, 80.0, -1.0, 1.0);
}
int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1800,950);
    glutInitWindowPosition(50,50);
    glutCreateWindow("hobbar");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
