#include<windows.h>
#include <stdio.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define PI 3.1416

static float cloudDownx=50,cloudUpx=50,hillx=55,hill1x=105,angle=0.0,anglex=0.0,hillsp=0.03,hill1sp=0.029999999;
static float rood1conx1=0.04,rood2conx1=0.039,dx=-30.0,cactus1x=100,cactus2x=56,cactusspeed=0.04;
static float tx=0,ty=0,dy=-33.0,i=0.04;

static int GAME_STATE = 2;
static int GAME_OVER = false;
static int SCORE = 0,highscore=0,sc=0;

static float rood11X = -39, rood11Y = -43.5, rood11Z = 1;
static float rood12X = -14, rood12Y = -43.5, rood12Z = 1;
static float rood13X = 11, rood13Y = -43.5, rood13Z = 1;
static float rood14X = 36, rood14Y = -43.5, rood14Z = 1;

static float rood21X = -26, rood21Y = -47.5, rood21Z = 1;
static float rood22X = -2, rood22Y = -47.5, rood22Z = 1;
static float rood23X = 19, rood23Y = -47.5, rood23Z = 1;
static float rood24X = 45, rood24Y = -47.5, rood24Z = 1;

void init()
{
    glClearColor (0.53, 0.807, 0.98, 0.0);
	glOrtho(-50.0, 50.0, -50.0, 50.0, -50.0, 50.0);
}

void circle(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;

	glBegin(GL_POLYGON);

		for(i = 0; i < 100; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}

	glEnd();
}

void halfcircle(float radius_x, float radius_y)
{
	int i = 0;
	float angle1 = 0.0;

	glBegin(GL_POLYGON);

		for(i = 0; i < 51; i++)
		{
			angle1 = 2 * PI * i / 100;
			glVertex3f (cos(angle1) * radius_x, sin(angle1) * radius_y, 0);
		}

	glEnd();
}

void showTextLarge(char text[], int r, int g, int b, int x, int y, int z)
{
    glColor3f(r, g, b);
    glRasterPos3f( x , y , z);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
}
void showTextSmall(char text[], float r, float g, float b, int x, int y, int z)
{
    glColor3f(r, g, b);
    glRasterPos3f( x , y , z);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}

void desert(){
    glPushMatrix();
         glColor3f(0.957f, 0.643f, 0.376f);
         glBegin(GL_QUADS);


            glColor3f(0.957f, 0.643f, 0.376f);
            glVertex2d(-50.0,-50.0);
            glColor3f(0.957f, 0.643f, 0.376f);
            glVertex2d(50.0,-50.0);

            glVertex2d(50.0,-40.0);
            glVertex2d(-50.0,-40.0);


            glEnd();
    glPopMatrix();
}

void cloudDown(){
    cloudDownx=cloudDownx-0.003;
    if(cloudDownx<-57){
        cloudDownx=57;
    }

    glPushMatrix();
        glTranslated(cloudDownx,15.0,1);
        glScaled(0.5,0.4,1);
        glColor3f(1.0f,1.0f,1.0f);

        glPushMatrix();
            glTranslated(-5.0,-3.0,1),
            circle(6,6);
        glPopMatrix();

        glPushMatrix();
            glTranslated(2.0,-5.0,1),
            circle(6,6);
        glPopMatrix();
        glPushMatrix();
            glTranslated(10.0,-3.0,1),
            circle(6,6);
        glPopMatrix();

        glPushMatrix();
            glTranslated(8.0,3.0,1),
            circle(6,6);
        glPopMatrix();

        glPushMatrix();
            glTranslated(0.0,4.0,1),
            circle(6,6);
        glPopMatrix();
    glPopMatrix();


}

void cloudUp(){
    cloudUpx=cloudUpx-0.002;
    if(cloudUpx<-54){
        cloudUpx=54;
    }

    glPushMatrix();
        glTranslated(cloudUpx,-5.0,1);
        glScaled(0.5,0.4,1);
        glColor3f(1.0f,1.0f,1.0f);

        glPushMatrix();
            glTranslated(-2.5,-2.5,1),
            circle(4,4);
        glPopMatrix();

        glPushMatrix();
            glTranslated(2.0,-4.0,1),
            circle(4,4);
        glPopMatrix();
        glPushMatrix();
            glTranslated(6.7,-2.7,1),
            circle(4,4);
        glPopMatrix();

        glPushMatrix();
            glTranslated(5.7,2.5,1),
            circle(4,4);
        glPopMatrix();

        glPushMatrix();
            glTranslated(0.0,3.0,1),
            circle(4,4);
        glPopMatrix();
    glPopMatrix();


}

void windMove(){
    /*wx=wx-0.1;
    if(wx<-360){
        wx=0;
    }
    glutPostRedisplay();*/

    if(angle<-726.5){
       // isbaby=0;
        angle=0;
        //bx=7;
        //by=0;
        glutIdleFunc(NULL);
    }
    else{
    angle=angle-0.2;
    }
   // glutPostRedisplay();

}

void hills()
{
    hillx=hillx-hillsp;
    if(hillx<-95 ){
        hillx=52;
    }

    glPushMatrix();
        glTranslated(hillx,-40.70,1);
        glScaled(0.5,1.1,0);

        glPushMatrix();                //16th hill m 4th
            glScaled(1.2,1.1,0);
            glTranslated(67,0.0,1);

            glColor3f(0.933,0.475,0.259);
            //glTranslatef(0,5,0);
            halfcircle(4,5.6);
        glPopMatrix();

        glPushMatrix();                //17tht hill means 1st
            glTranslated(85.0,0.0,1);
            glColor3f(0.804,0.522,0.247);
            //glTranslatef(0,5,0);
            halfcircle(4,5);
        glPopMatrix();
        glPushMatrix();                //15th hill m 3rd
            glScaled(1.2,1,0);
            glTranslated(61.0,0.0,1);
            glColor3f(0.627,0.322,0.176);
            halfcircle(4,5.5);
        glPopMatrix();
        glPushMatrix();                 //14th hill means 2nd
            glScaled(1,1.4,0);
            glTranslated(69.0,0.0,1);
            glColor3f(0.824,0.412,0.118);
            //glTranslatef(0,5,0);
            halfcircle(4,5.3);
        glPopMatrix();
        glPushMatrix();                //12 m4th hill
            glScaled(1.2,1.1,0);
            glTranslated(48,0.0,1);
            glColor3f(0.933,0.475,0.259);
            halfcircle(4,5.6);
        glPopMatrix();
        glPushMatrix();                //13 m 1st hill
            glTranslated(63.0,0.0,1);
            glColor3f(0.804,0.522,0.247);
            //glTranslatef(0,5,0);
            halfcircle(4,5);
        glPopMatrix();
        glPushMatrix();                //11th m 3rd hill
            glScaled(1.2,1,0);
            glTranslated(43.0,0.0,1);

            glColor3f(0.627,0.322,0.176);
            //glTranslatef(0,5,0);
            halfcircle(4,5.5);
        glPopMatrix();

        glPushMatrix();                //8th hill m 4th
            glScaled(1.2,1.1,0);
            glTranslated(31,0.0,1);

            glColor3f(0.933,0.475,0.259);
            //glTranslatef(0,5,0);
            halfcircle(4,5.6);
        glPopMatrix();


        glPushMatrix();                //9th hill m 1st
            glTranslated(43.0,0.0,1);
            glColor3f(0.804,0.522,0.247);
            //glTranslatef(0,5,0);
            halfcircle(4,5);
        glPopMatrix();
        glPushMatrix();                 //10th hill m 2nd
            glScaled(1,1.4,0);
            glTranslated(48.0,0.0,1);
            glColor3f(0.824,0.412,0.118);
            //glTranslatef(0,5,0);
            halfcircle(4,5.3);
        glPopMatrix();

        glPushMatrix();                //7th hill m 3rd
            glScaled(1.2,1,0);
            glTranslated(26.0,0.0,1);

            glColor3f(0.627,0.322,0.176);
            //glTranslatef(0,5,0);
            halfcircle(4,5.5);
        glPopMatrix();


        glPushMatrix();                 //6th hill means 2nd
            glScaled(1,1.4,0);
            glTranslated(26.0,0.0,1);
            glColor3f(0.824,0.412,0.118);
            //glTranslatef(0,5,0);
            halfcircle(4,5.3);
        glPopMatrix();

        glPushMatrix();                //4th hill
            glScaled(1.2,1.1,0);
            glTranslated(13,0.0,1);

            glColor3f(0.933,0.475,0.259);
            //glTranslatef(0,5,0);
            halfcircle(4,5.6);
        glPopMatrix();

        glPushMatrix();                //5tht hill means 1st
            glTranslated(21.0,0.0,1);
            glColor3f(0.804,0.522,0.247);
            //glTranslatef(0,5,0);
            halfcircle(4,5);
        glPopMatrix();

        glPushMatrix();                //3rd hill
            glScaled(1.2,1,0);
            glTranslated(8.0,0.0,1);

            glColor3f(0.627,0.322,0.176);
            //glTranslatef(0,5,0);
            halfcircle(4,5.5);
        glPopMatrix();

        glPushMatrix();                //1st hill
            glTranslated(0.0,0.0,1);
            glColor3f(0.804,0.522,0.247);
            //glTranslatef(0,5,0);
            halfcircle(4,5);
        glPopMatrix();
        glPushMatrix();                 //2nd hill
            glScaled(1,1.4,0);
            glTranslated(5.0,0.0,1);
            glColor3f(0.824,0.412,0.118);
            //glTranslatef(0,5,0);
            halfcircle(4,5.3);
        glPopMatrix();

    glPopMatrix();
}

void hills1()
{
    hill1x=hill1x-hill1sp;
    if(hill1x<-95 ){
        hill1x=52;
    }

    glPushMatrix();
        glTranslated(hill1x,-40.10,1);
        glScaled(0.5,1.1,0);

        glPushMatrix();                //16th hill m 4th
            glScaled(1.2,1.1,0);
            glTranslated(67,0.0,1);

            glColor3f(0.933,0.475,0.259);
            //glTranslatef(0,5,0);
            halfcircle(4,5.6);
        glPopMatrix();

        glPushMatrix();                //17tht hill means 1st
            glTranslated(85.0,0.0,1);
            glColor3f(0.804,0.522,0.247);
            //glTranslatef(0,5,0);
            halfcircle(4,5);
        glPopMatrix();
        glPushMatrix();                //15th hill m 3rd
            glScaled(1.2,1,0);
            glTranslated(61.0,0.0,1);
            glColor3f(0.627,0.322,0.176);
            halfcircle(4,5.5);
        glPopMatrix();
        glPushMatrix();                 //14th hill means 2nd
            glScaled(1,1.4,0);
            glTranslated(69.0,0.0,1);
            glColor3f(0.824,0.412,0.118);
            //glTranslatef(0,5,0);
            halfcircle(4,5.3);
        glPopMatrix();
        glPushMatrix();                //12 m4th hill
            glScaled(1.2,1.1,0);
            glTranslated(48,0.0,1);
            glColor3f(0.933,0.475,0.259);
            halfcircle(4,5.6);
        glPopMatrix();
        glPushMatrix();                //13 m 1st hill
            glTranslated(63.0,0.0,1);
            glColor3f(0.804,0.522,0.247);
            //glTranslatef(0,5,0);
            halfcircle(4,5);
        glPopMatrix();
        glPushMatrix();                //11th m 3rd hill
            glScaled(1.2,1,0);
            glTranslated(43.0,0.0,1);

            glColor3f(0.627,0.322,0.176);
            //glTranslatef(0,5,0);
            halfcircle(4,5.5);
        glPopMatrix();

        glPushMatrix();                //8th hill m 4th
            glScaled(1.2,1.1,0);
            glTranslated(31,0.0,1);

            glColor3f(0.933,0.475,0.259);
            //glTranslatef(0,5,0);
            halfcircle(4,5.6);
        glPopMatrix();


        glPushMatrix();                //9th hill m 1st
            glTranslated(43.0,0.0,1);
            glColor3f(0.804,0.522,0.247);
            //glTranslatef(0,5,0);
            halfcircle(4,5);
        glPopMatrix();
        glPushMatrix();                 //10th hill m 2nd
            glScaled(1,1.4,0);
            glTranslated(48.0,0.0,1);
            glColor3f(0.824,0.412,0.118);
            //glTranslatef(0,5,0);
            halfcircle(4,5.3);
        glPopMatrix();

        glPushMatrix();                //7th hill m 3rd
            glScaled(1.2,1,0);
            glTranslated(26.0,0.0,1);

            glColor3f(0.627,0.322,0.176);
            //glTranslatef(0,5,0);
            halfcircle(4,5.5);
        glPopMatrix();


        glPushMatrix();                 //6th hill means 2nd
            glScaled(1,1.4,0);
            glTranslated(26.0,0.0,1);
            glColor3f(0.824,0.412,0.118);
            //glTranslatef(0,5,0);
            halfcircle(4,5.3);
        glPopMatrix();

        glPushMatrix();                //4th hill
            glScaled(1.2,1.1,0);
            glTranslated(13,0.0,1);

            glColor3f(0.933,0.475,0.259);
            //glTranslatef(0,5,0);
            halfcircle(4,5.6);
        glPopMatrix();

        glPushMatrix();                //5tht hill means 1st
            glTranslated(21.0,0.0,1);
            glColor3f(0.804,0.522,0.247);
            //glTranslatef(0,5,0);
            halfcircle(4,5);
        glPopMatrix();

        glPushMatrix();                //3rd hill
            glScaled(1.2,1,0);
            glTranslated(8.0,0.0,1);

            glColor3f(0.627,0.322,0.176);
            //glTranslatef(0,5,0);
            halfcircle(4,5.5);
        glPopMatrix();

        glPushMatrix();                //1st hill
            glTranslated(0.0,0.0,1);
            glColor3f(0.804,0.522,0.247);
            //glTranslatef(0,5,0);
            halfcircle(4,5);
        glPopMatrix();
        glPushMatrix();                 //2nd hill
            glScaled(1,1.4,0);
            glTranslated(5.0,0.0,1);
            glColor3f(0.824,0.412,0.118);
            //glTranslatef(0,5,0);
            halfcircle(4,5.3);
        glPopMatrix();

    glPopMatrix();
}

void rood1(float tx,float ty,float tz){
    glPushMatrix();
        glTranslated(tx,ty,tz);
        glBegin(GL_LINES);
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex2d(0.0,0.0);
            glVertex2d(1.5,0.0);
        glEnd();
    glPopMatrix();
}

void rood1cons(){

    rood1(rood11X,rood11Y,rood11Z);
    rood1(rood12X,rood12Y,rood12Z);
    rood1(rood13X,rood13Y,rood13Z);
    rood1(rood14X,rood14Y,rood14Z);

    rood11X=rood11X-rood1conx1;
    if(rood11X<-56){
        rood11X=56;
    }
    rood12X=rood12X-rood1conx1;
    if(rood12X<-56){
        rood12X=56;
    }
    rood13X=rood13X-rood1conx1;
    if(rood13X<-56){
        rood13X=56;
    }
    rood14X=rood14X-rood1conx1;
    if(rood14X<-56){
        rood14X=56;
    }
}

void rood2(float tx,float ty,float tz){
    glPushMatrix();
        glTranslated(tx,ty,tz);
        glBegin(GL_LINES);
            glColor3f(0.0, 0.0, 0.0);
            glVertex2d(0.0f,0.0f);
            glVertex2d(1.5f,0.0f);
        glEnd();
    glPopMatrix();
}

void rood2cons(){

    rood2(rood21X,rood21Y,rood21Z);
    rood2(rood22X,rood22Y,rood22Z);
    rood2(rood23X,rood23Y,rood23Z);
    rood2(rood24X,rood24Y,rood24Z);

    rood21X=rood21X-rood2conx1;
    if(rood21X<-56){
        rood21X=56;
    }
    rood22X=rood22X-rood2conx1;
    if(rood12X<-56){
        rood12X=56;
    }
    rood23X=rood23X-rood2conx1;
    if(rood23X<-56){
        rood23X=56;
    }
    rood24X=rood24X-rood2conx1;
    if(rood24X<-56){
        rood24X=56;
    }
}


void dinosaur(float dx,float dy){
    glPushMatrix();
        glTranslated(dx,dy,1);
        glScaled(0.4,0.4,1);
        glPushMatrix();
            glBegin(GL_POLYGON);                        //front leg
                //glScaled(1,dsy1,1);
                glColor3f(0.196f, 0.804f, 0.196f);

                glVertex2f(-5.5,-22.5);
                glVertex2f(-2.5,-27.5);
                glVertex2f(0.0,-30.0);
                glVertex2f(0.0,-32.5);
                glVertex2f(-7.5,-32.5);
                glVertex2f(-7.5,-27.5);
                glVertex2f(-10.0,-22.5);
                glVertex2f(-10.0,-15.0);
                glVertex2f(-2.5,-15.0);
            glEnd();
        glPopMatrix();

        glPushMatrix();                                //back leg
            glBegin(GL_POLYGON);
                //glScaled(4,4,1);
                glColor3f(0.196f, 0.804f, 0.196f);

                glVertex2d(4.5,-20);
                glVertex2d(7.5,-27.5);
                glVertex2d(10.0,-30);
                glVertex2d(10,-32.5);
                glVertex2d(2.5,-30);
                glVertex2d(2.5,-27.5);
                glVertex2d(0.0,-20);
                glVertex2d(0.0,-12.5);
                glVertex2d(5,-10);
            glEnd();
        glPopMatrix();

        glPushMatrix();                                //back hand
            glBegin(GL_POLYGON);
                glScaled(4,4,1);
                glColor3f(0.196f, 0.804f, 0.196f);

                glVertex2d(12.5,7.5);
                glVertex2d(17.5,7.5);
                glVertex2d(17.5,5);
                glVertex2d(10.0,5);

            glEnd();
        glPopMatrix();

        glPushMatrix();                                         //body:tailend
            glBegin(GL_POLYGON);
                glColor3f(0.133f, 0.545f, 0.133f);
                glVertex2d(-20,-27.5);
                glVertex2d(-20.0,-30.0);
                glVertex2d(-10.0,-32.5);
                glVertex2d(-25.0,-32.5);
                glVertex2d(-25.0,-27.5);

            glEnd();
        glPopMatrix();

        glPushMatrix();                                         //body:tailfront
            glBegin(GL_POLYGON);
                glColor3f(0.133f, 0.545f, 0.133f);
                glVertex2d(-10,-15);
                glVertex2d(-15.0,-22.5);
                glVertex2d(-20.0,-27.5);
                glVertex2d(-25.0,-27.5);
                glVertex2d(-20.0,-22.5);
                glVertex2d(-15.0,-7.5);
            glEnd();
        glPopMatrix();

        glPushMatrix();                                         //body:belly
            glBegin(GL_POLYGON);
                glColor3f(0.133f, 0.545f, 0.133f);
                glVertex2d(5,-10);
                glVertex2d(0.0,-12.5);
                glVertex2d(-2.5,-15.0);
                glVertex2d(-10.0,-15.0);
                glVertex2d(-15.0,-7.5);
                glVertex2d(-12.5,2.5);
                glVertex2d(-7.5,7.5);
                glVertex2d(5,15);
                glVertex2d(12.5,15);
                glVertex2d(15,10);
            glEnd();
        glPopMatrix();

        glPushMatrix();                                         //body:head
            glBegin(GL_POLYGON);
                glColor3f(0.133f, 0.545f, 0.133f);
                //glVertex2d(5,15);
                glVertex2d(5,25);
                glVertex2d(7.5,27.5);
                glVertex2d(12.5,30);
                glVertex2d(22.5,25);
                glVertex2d(22.5,22.5);
                glVertex2d(15,22.5);

            glEnd();
        glPopMatrix();

        glPushMatrix();                                         //body:nick
            glBegin(GL_POLYGON);
                glColor3f(0.133f, 0.545f, 0.133f);
                //glVertex2d(5,15);
                glVertex2d(15,22.5);
                glVertex2d(22.5,20);
                glVertex2d(20,17.5);
                glVertex2d(15,20);
            glEnd();
        glPopMatrix();

        glPushMatrix();                                         //body:head
            glBegin(GL_POLYGON);
                glColor3f(0.133f, 0.545f, 0.133f);
                //glVertex2d(5,15);
                glVertex2d(5,15);
                glVertex2d(5,25);
                glVertex2d(15,22.5);
                glVertex2d(15,20);
                glVertex2d(12.5,15);
            glEnd();
        glPopMatrix();

        glPushMatrix();                                //front nick
            glBegin(GL_POLYGON);
                glScaled(4,4,1);
                glColor3f(0.196f, 0.804f, 0.196f);

                glVertex2d(12.5,2.5);
                glVertex2d(17.5,2.5);
                glVertex2d(17.5,0.0);
                glVertex2d(10.0,0.0);
                glVertex2d(5.0,5.0);
                glVertex2d(7.5,7.5);

            glEnd();
        glPopMatrix();
        glPushMatrix();                                //eye
            //glBegin(GL_POLYGON);
                glTranslated(10.75,25,1);
                glColor3f(1.0f, 1.0f, 1.0f);
                circle(1,1);
            //glEnd();
        glPopMatrix();

    glPopMatrix();
}

void cactus1(float cactusx){
    glPushMatrix();
        glTranslated(cactus1x,-42.0,1);
        glScaled(0.12,0.12,1);
        glPushMatrix();
            glBegin(GL_POLYGON);                        //1st hand
               // glScaled(4,4,1);
                glColor3f(0.42f, 0.557f, 0.137f);

                glVertex2f(-8,12);
                glVertex2f(-8,28);
                glVertex2f(-10,30);
                glVertex2f(-12,28);
                glVertex2f(-12,10);
                glVertex2f(-4,-2);
                glVertex2f(-4.0,6);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glBegin(GL_POLYGON);                        //2nd hand
               // glScaled(4,4,1);
               glColor3f(0.42f, 0.557f, 0.137f);

                glVertex2f(8,8);
                glVertex2f(8,20);
                glVertex2f(10,22);
                glVertex2f(12,20);
                glVertex2f(12,4);
                glVertex2f(4,-10);
                glVertex2f(4.0,0.0);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glBegin(GL_POLYGON);                        //body
               // glScaled(4,4,1);
                glColor3f(0.42f, 0.557f, 0.137f);

                glVertex2f(0,40);
                glVertex2f(-4,34);
                glVertex2f(-4,-25);
                glVertex2f(4,-25);
                glVertex2f(4,34);
               // glVertex2f(4,-10);
                //glVertex2f(4.0,0.0);
            glEnd();
        glPopMatrix();
        glPushMatrix();
            glBegin(GL_POLYGON);                        //2nd cactus:1st hand
                glTranslated(25,0,1);
                glColor3f(0.42f, 0.557f, 0.137f);

                glVertex2f(10,12);
                glVertex2f(10,28);
                glVertex2f(8,30);
                glVertex2f(6,28);
                glVertex2f(6,10);
                glVertex2f(14,-2);
                glVertex2f(14.0,6);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glBegin(GL_POLYGON);                        //2nd cactus:2nd hand
               // glScaled(4,4,1);
                glColor3f(0.42f, 0.557f, 0.137f);

                glVertex2f(26,8);
                glVertex2f(26,20);
                glVertex2f(28,22);
                glVertex2f(30,20);
                glVertex2f(30,4);
                glVertex2f(22,-10);
                glVertex2f(22.0,0.0);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glBegin(GL_POLYGON);                        //body
               // glScaled(4,4,1);
                glColor3f(0.42f, 0.557f, 0.137f);

                glVertex2f(18,30);
                glVertex2f(14,24);
                glVertex2f(14,-20);
                glVertex2f(22,-20);
                glVertex2f(22,24);
            glEnd();
        glPopMatrix();


    glPopMatrix();
}

void cactus2(float cactus2x){
    glPushMatrix();
        glTranslated(cactus2x,-42.0,1);
        glScaled(0.12,0.12,1);
        glPushMatrix();
            glBegin(GL_POLYGON);                        //1st hand
               // glScaled(4,4,1);
                glColor3f(0.42f, 0.557f, 0.137f);

                glVertex2f(-8,12);
                glVertex2f(-8,28);
                glVertex2f(-10,30);
                glVertex2f(-12,28);
                glVertex2f(-12,10);
                glVertex2f(-4,-2);
                glVertex2f(-4.0,6);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glBegin(GL_POLYGON);                        //2nd hand
               // glScaled(4,4,1);
               glColor3f(0.42f, 0.557f, 0.137f);

                glVertex2f(8,8);
                glVertex2f(8,20);
                glVertex2f(10,22);
                glVertex2f(12,20);
                glVertex2f(12,4);
                glVertex2f(4,-10);
                glVertex2f(4.0,0.0);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glBegin(GL_POLYGON);                        //body
               // glScaled(4,4,1);
                glColor3f(0.42f, 0.557f, 0.137f);

                glVertex2f(0,40);
                glVertex2f(-4,34);
                glVertex2f(-4,-40);
                glVertex2f(4,-40);
                glVertex2f(4,34);
               // glVertex2f(4,-10);
                //glVertex2f(4.0,0.0);
            glEnd();
        glPopMatrix();

    glPopMatrix();
}

void cactusbuild(){
    cactus1(cactus1x);
    cactus2(cactus2x);

    cactus1x-=cactusspeed;
    cactus2x-=cactusspeed;
    if(cactus1x <= -60.0) {
        //pipeDistance1 = 130;
       // cactus1x = (rand() % 101) - 50;
       cactus1x=57;
       // lock1 = 0;
    }
    if(cactus2x <= -60.0) {
        //pipeDistance1 = 130;
        //cactus2x= (rand() % 101) - 50;
        cactus2x=57;
       // lock1 = 0;
    }
}
void dinosaurbuild(){
    dinosaur(dx,dy);
    if(dy>=-33.0){
              dy=dy-i;
              //i=i+i;
		    }
}

void conflict()
{
    if((dx>= -40 && dx<=-26)&& (dy>=-46.0 && dy<=-25.8) &&  ((cactus2x>= -40 && cactus2x<=-26)||(cactus1x>= -40 && cactus1x<=-26))) {
          GAME_OVER=true;
          sc=SCORE;
          if(SCORE>highscore){
            highscore=SCORE;
    }
    }
    else{
        SCORE=SCORE+1;
    }


    char score1[100];
    char score2[100];
    itoa(SCORE, score2, 10);

    showTextLarge(score2, 0, 0, 0.545, 40, 40, 0);

    showTextSmall("HI", 0, 0, 0.545, 25, 40, 0);
    itoa(highscore, score1, 10);

    showTextLarge(score1, 0, 0, 0.545, 30, 40, 0);
}
void reset()
{
    cactusspeed=0.04;
    i=0.04;
    SCORE=0;
    cactus1x=100;
    cactus2x=56;
    angle=0.0;
    anglex=0.0;
    dx=-30.0;
    dy=-33.0;
    rood1conx1=0.04;
    rood2conx1=0.039;
    hillsp=0.03;
    hill1sp=0.029999999;

}
void my_keyboard(unsigned char key, int x, int y)
{
	switch (key) {
		case ' ':
		    dy=-5;
		    i=i+0.0005;
		    rood1conx1+=0.0005;
		    rood2conx1+=0.0005;
		    cactusspeed=cactusspeed+0.0005;

			break;
        case 'w':
            GAME_OVER=false;
            break;

	  default:
			break;
	}
}
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT); //clear buffer, buffer_bit indicates the buffers currently enabled for color writing


    if(GAME_OVER==false){
        desert();

        cloudDown();
        cloudUp();
        windMove();


        hills1();
        hills();
        rood1cons();
        cactusbuild();
        rood2cons();

        dinosaurbuild();
        conflict();



    }
   else if(GAME_OVER==true){
        desert();
        cloudDown();
        cloudUp();
        windMove();

        hill1sp=0;
        hillsp=0;
        hills1();
        hills();

        rood1conx1=0;
        rood2conx1=0;

        rood1cons();
        rood2cons();
        //cactusspeed=0;
        cactusbuild();


        char score1[100];
        char score2[100];
        itoa(sc, score2, 10);

        showTextLarge(score2, 0, 0, .545, 40, 40, 0);

        showTextSmall("HI", 0, 0, 0.545, 25, 40, 0);
        itoa(highscore, score1, 10);

        showTextLarge(score1, 0, 0, 0.545, 30, 40, 0);

        showTextLarge("G A M E   O V E R", 0, 0, .545, -12, 0, 0);

        showTextSmall("Press 'w' To Restart", 0, 0, .545, -10, -5, 0);
        reset();
    }
    glutPostRedisplay();

    glFlush(); //force execution of Gl commands
}
int main()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500); // Size of the window
    glutInitWindowPosition(10, 10); // location of the window
    glutCreateWindow("Dinosaur Game"); // Create window with this name
    init(); // call initialize function
    glutKeyboardFunc(my_keyboard);
    glutDisplayFunc(myDisplay); // call display function
    glutMainLoop();
    return 0;
}

