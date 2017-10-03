#include<stdio.h>
#include<GL/glut.h>
#include<time.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define ASPECT_WIDTH 16
#define ASPECT_HEIGHT 9
#define NUM_BULLETS 40
bool bulletfired=true;
bool ship1alive=false;
bool ship2alive=false;
bool firemissile1=false;
bool firemissile2=false;
bool grandmaout=false;
bool missile1collided=false;
bool missile2collided=false;
bool scene1=true;
bool scene2=false;
bool scene3=false;
bool scene4=false;
bool tankalive=true;
bool gameend=false;
bool collided=false;
bool monstercollided=false;
float life=100.0;
float ship1life=100;
float ship2life=100;
float tanklife=100;
struct bullet
{
	float x,y;
	float angle;
};

struct bullet b[NUM_BULLETS];
bool monsteralive=true;
float tankmainturretrotation = 0.0;
float shellrotation = 0.0;
float firerotation = 0.0;
float smokerotation = 0.0;
float dx,dy;
int speed=4,start=0,start1=0,boyspeed=2,shield=0,timeout=0,gameover=0,phase2=0,pspeed=2,fired=0;
void animate5(void);
void animate7(void);
int day=1;
GLuint textureID;
GLuint boyTexture,topcompTexture,gameclearedTexture,grandma2Texture,shellTexture,missile1Texture,missile2Texture,maintankTexture,gameendTexture,bconnectorTexture,mainturretTexture,topturretTexture,tankTexture,bomb3Texture,portalTexture,pskyTexture,phase1Texture,alien2Texture,fireTexture,actTexture,endTexture,House11Texture,smokeTexture,sky1Texture,sky2Texture,building1Texture,bombTexture,roadTexture,House1Texture,House2Texture,alienTexture,buildingTexture,grandmaTexture,grandma1Texture,HouseTexture,titleTexture,title2Texture,boy2Texture,boy3Texture,boy4Texture,boy5Texture,boy6Texture;
GLuint texture1[5];
GLuint texture2[5]; 
GLuint texture3[63];
GLuint texture4[29];
GLuint texture5[10];
GLuint texture6[10];
GLuint texture7[3];
GLuint texture8[15];
GLuint texture9[7];
GLuint texture10[7];
GLuint texture11[1];
GLuint texture12[6];
GLuint texture13[3];
GLuint texture14[4];

double frame,frame1,frame2,frame3,frame4=6.0,frame5=6.0,frame6,frame7,frame8,frame9,frame10=0,frame11=0,frame12=1,frame13,frame14,frame15=1,frame16=1;
float smokeX=530,smokeY=240;
float smoke2X=850,smoke2Y=240;
float numX=650,numY=600;
float num2X=750,num2Y=600;
float actX=540,actY=450;
float portalX=1000,portalY=580;
float endX=300,endY=600;
float boyX = 225, boyY = 170;
float tankX = 225, tankY = 90;
float house1X=800,house1Y=300;
float monsterX = 600, monsterY = 140;
float lifeX=600,lifeY=310;
float titleX=0,titleY=0;
float gameendX=0,gameendY=0;
float enemyX=800,enemyY=840;
float ship1X=1400,ship1Y=600;
float ship2X=1200,ship2Y=600;
float tankmainturretX = tankX+21, tankmainturretY = tankY-4;
float missile1X=1400,missile1Y=600;
float missile2X=1400,missile2Y=600;
float shellX = tankmainturretX+25, shellY = tankmainturretY+tankmainturretrotation+shellrotation;
float tankfireX = tankmainturretX+50, tankfireY =  tankY-4;
float tanksmokeX = tankmainturretX+54, tanksmokeY = tankmainturretY+tankmainturretrotation+smokerotation;
float fireX =530,fireY=220;
float fire1X =430,fire1Y=220;
float fire2X =620,fire2Y=220;
float fire3X =780,fire3Y=225;
float fire4X =940,fire4Y=225;
float fire5X =860,fire5Y=225;
float boy2X = 1250, boy2Y = 170;
float grandmaX = 900, grandmaY = 190;
float grandma1X = -150, grandma1Y = -130;
float alienX=1450,alienY=600;
float alien2X=1450,alien2Y=600;
float bombX=530,bombY=550;
float bomb2X=850,bomb2Y=550;
float bomb3X=850,bomb3Y=550;

float boyVerts[4][2] = {{-20, -40}, {-20, 40}, {20, 40}, {20, -40}};
float boyUV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float missile1Verts[4][2] = {{-20, -9.5}, {-20, 9.5}, {20, 9.5}, {20, -9.5}};
float missile1UV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float missile2Verts[4][2] = {{-20, -9.5}, {-20, 9.5}, {20, 9.5}, {20, -9.5}};
float missile2UV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float lifeVerts[4][2] = {{-32, -40}, {-32, 40}, {32, 40}, {32, -40}};
float lifeUV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float enemyVerts[4][2] = {{-20, -40}, {-20, 40}, {20, 40}, {20, -40}};
float enemyUV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float ship1Verts[4][2] = {{-75, -45}, {-75, 45}, {75, 45}, {75, -45}};
float ship1UV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float ship2Verts[4][2] = {{-75, -45}, {-75, 45}, {75, 45}, {75, -45}};
float ship2UV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float monsterVerts[4][2] = {{-96.458333333, -111.041666667}, {-96.458333333, 111.041666667}, {96.458333333, 111.041666667}, {96.458333333, -111.041666667}};
float monsterUV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float tankVerts[4][2] = {{-73, -50}, {-73, 50}, {73,50}, {73, -50}};
float tankUV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float tankfireVerts[4][2] = {{-15, -14}, {-15, 14}, {15,14}, {15, -14}};
float tankfireUV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float tanksmokeVerts[4][2] = {{-21, -50}, {-21, 50}, {21,50}, {21, -50}};
float tanksmokeUV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float shellVerts[4][2] = {{-8, -4}, {-8, 4}, {8,4}, {8, -4}};
float shellUV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float tankmainturretVerts[4][2] = {{-21+21, -5}, {-21+21, 5}, {21+21, 5}, {21+21, -5}};
float tankmainturretUV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float numVerts[4][2] = {{-25, -40}, {-25, 40}, {25, 40}, {25, -40}};
float numUV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float actVerts[4][2] = {{-200, -40}, {-200, 40}, {200, 40}, {200, -40}};
float actUV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float endVerts[4][2] = {{-284, -46}, {-284, 46}, {284, 46}, {284, -46}};
float endUV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float fireVerts[4][2] = {{-80, -60}, {-80, 60}, {80, 60}, {80, -60}};
float fireUV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float smokeVerts[4][2] = {{-150, -100}, {-150, 100}, {150, 100}, {150, -100}};
float smokeUV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float portalVerts[4][2] = {{-200, -100}, {-200, 100}, {200, 100}, {200, -100}};
float portalUV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float bombVerts[4][2] = {{-25, -40}, {-25, 40}, {25, 40}, {25, -40}};
float bombUV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float bomb3Verts[4][2] = {{-25, -40}, {-25, 40}, {25, 40}, {25, -40}};
float bomb3UV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float boy2Verts[4][2] = {{-25, -40}, {-25, 40}, {25, 40}, {25, -40}};
float boy2UV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float buildingVerts[4][2] = {{70, 170}, {70, 600}, {400, 600}, {400, 170}};
float buildingUV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float building1Verts[4][2] = {{70, 170}, {70, 600}, {400, 600}, {400, 170}};
float building1UV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float alienshipVerts[4][2] = {{-100, -50}, {-100, 50}, {100, 50}, {100, -50}};
float alienshipUV[4][2] ={{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float alienship2Verts[4][2] = {{-150, -50}, {-150, 50}, {150, 50}, {150, -50}};
float alienship2UV[4][2] ={{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float grandmaVerts[4][2] = {{860, 165}, {860, 262}, {950, 262}, {950, 165}};
float grandmaUV[4][2] ={{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float grandma1Verts[4][2] = {{-60, -50}, {-60, 50}, {60, 50}, {60, -50}};
float grandma1UV[4][2] ={{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float roadVerts[4][2] = {{0, 0}, {0, 170}, {1000, 170}, {1000, 0}};
float roadUV[4][2] ={{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float sky1Verts[4][2] = {{0, 170}, {0, 700}, {1000, 700}, {1000, 170}};
float sky1UV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float sky2Verts[4][2] = {{0, 170}, {0, 700}, {1000, 700}, {1000, 170}};
float sky2UV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float pskyVerts[4][2] = {{0, 0}, {0, 700}, {1000, 700}, {1000, 0}};
float pskyUV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float titleVerts[4][2] = {{0, 0}, {0, 700}, {1000, 700}, {1000, 0}};
float titleUV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float gameendVerts[4][2] = {{0, 0}, {0, 700}, {1000, 700}, {1000, 0}};
float gameendUV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float title2Verts[4][2] = {{0, 0}, {0, 700}, {1000, 700}, {1000, 0}};
float title2UV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float HouseVerts[4][2] = {{700, 159}, {700, 400}, {1020, 400}, {1020, 159}};
float HouseUV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float House1Verts[4][2] = {{700, 159}, {700, 400}, {1020, 400}, {1020, 159}};
float House1UV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

float House2Verts[4][2] = {{375, 140}, {375, 400}, {675, 400}, {675, 140}};
float House2UV[4][2] = {{0.0, 1.0}, {0.0, 0.0},{1.0, 0.0}, {1.0, 1.0}};

bool moveToDestination(float destX, float destY, float* posX, float* posY, float speed)
{
    float x, y;
    x = destX - *posX;
    y = destY - *posY;
    
    float magnitude = sqrt(x*x + y*y);
    if(magnitude <= speed && magnitude >= -speed)
    {
        *posX = destX;
        *posY = destY;
        return true;
    }
    
    float xNorm = x / magnitude;
    float yNorm = y / magnitude;
    
    float xVel = xNorm * speed;
    float yVel = yNorm * speed;
    
    *posX += xVel;
    *posY += yVel;
    
    return false;
}

void delay(float secs)
{
	float end = clock()/CLOCKS_PER_SEC + secs;
	while((clock()/CLOCKS_PER_SEC) < end);
}


void DrawTexturedRectangle(float vertices[4][2], float uv[4][2], GLuint textureID, float posX, float posY, float angle =0.0)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1.0, 1.0, 1.0);

    glTranslatef(posX, posY, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0);
    glScalef(1.0, 1.0, 1.0);

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBindTexture(GL_TEXTURE_2D, textureID);
    glBegin(GL_POLYGON);
        glTexCoord2fv(uv[0]);
        glVertex2fv(vertices[0]);
        glTexCoord2fv(uv[1]);
        glVertex2fv(vertices[1]);
        glTexCoord2fv(uv[2]);
        glVertex2fv(vertices[2]);
        glTexCoord2fv(uv[3]);
        glVertex2fv(vertices[3]);
    glEnd();
	glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);
}

void InitBullets()
{
    for(int i = 0; i < NUM_BULLETS; i++)
    {
        // Set all bullets to "not fired" state
        // If x and y are -1, then the bullet is not fired.
        b[i].x = -1;
        b[i].y = -1;
        b[i].angle = 0;
    }
}

void DrawBullets()
{
    for(int i = 0; i < NUM_BULLETS; i++)
    {
        if(b[i].x > -1 && b[i].y > -1)
        {
            DrawTexturedRectangle(shellVerts, shellUV, shellTexture, b[i].x, b[i].y,b[i].angle);
            DrawTexturedRectangle(tankfireVerts, tankfireUV,texture9[(int)frame8], tankfireX+b[i].angle, tankfireY-b[i].angle,0);
			DrawTexturedRectangle(tanksmokeVerts, tanksmokeUV,texture10[(int)frame9], tanksmokeX, tanksmokeY,b[i].angle);
			if(bulletfired)
			{
				frame8+=0.13333333;
				if (frame8 > 7)
	    		{
					frame8 = 1;
	    			tankfireX=2000;
	    		}
	    		frame9+=0.1333333;
	    		if (frame9 > 7)
	    		{
	    			frame9 = 1;
    				tanksmokeX=2000;
    			}
    		}
        }
    }
}

void UpdateBullets()
{
    for(int i = 0; i < NUM_BULLETS; i++)
    {
        if(b[i].x > -1 && b[i].y > -1)
        {
            // Move the bullet and do collision detection.

            // Calculating the destination
            /*
            Rotating a vector formula
            return new Vector2(
			point.x*cosT - point.y*sinT,
			point.x*sinT + point.y*cosT
			);*/
			float rad = b[i].angle * 3.1415 / 180;
            float sinT = sin(rad);
            float cosT = cos(rad);

            // Rotating unit vector (1, 0) by b[i].angle degrees
            // We will use dirX and dirY as destination of the bullet
            // which will be somewhere out of bounds of the screen.
            float dirX = cosT; // 1 * cosT - 0 * sinT
            float dirY = sinT; // 1 * sinT + 0 * cosT

            // Scaling the vector to make it go out of bounds of the screen
            // (To place the firing animation at the tip of the turrent, same calculation
            // except scale by the length of the turret instead of 1000 and give dirX,Y as
            // the position of the firing animation)
            dirX = dirX * 1000;
            dirY = dirY * 1000;

            // Translating the vector to the turret
            dirX += tankmainturretX;
            dirY += tankmainturretY;

            bool outOfScreen = moveToDestination(dirX, dirY, &b[i].x, &b[i].y, 5);
            bool collided = false;
            bool ship1collided = false;
            bool ship2collided = false;
            // Do collision detection (Search bounding box collision detection on the internet)
            // set collided to true if there is collision.
            if(b[i].x >= monsterX - 96 && b[i].x <= monsterX + 96 && b[i].y >=monsterY-110 && b[i].y <= monsterY + 110 )
            {
            	collided=true;
            	//printf("hit");
            	if(life==0)
            	{
            		monsteralive=false;
            		ship1alive=true;
            		monsterX=2000;
            	}
            	//monsterX=2000;
            }
            if(b[i].x >= ship1X - 75 && b[i].x <= ship1X + 75 && b[i].y >=ship1Y-45 && b[i].y <= ship1Y + 45 )
            {
            	ship1collided=true;
            	//printf("hit");
            	if(ship1life==0)
            	{
            		ship1alive=false;
            		ship1X=2000;
            		ship2alive=true;

            	}
            	//monsterX=2000;
            }
            
            if(b[i].x >= ship2X - 75 && b[i].x <= ship2X + 75 && b[i].y >=ship2Y-45 && b[i].y <= ship2Y + 45 )
            {
            	ship2collided=true;
            	if(ship2life==0)
            	{
            		ship2X=2000;
            		grandmaout=true;
            	}
            }
            if(collided)
            {
                // Collided with monster.
                // Maybe call a function here to decrease its health??
                
                b[i].x = -1;
                b[i].y = -1;
                b[i].angle = 0;
                life-=25;
                frame12+=1;
            }
            if(ship1collided)
            {
                b[i].x = -1;
                b[i].y = -1;
                b[i].angle = 0;
                ship1life-=25;
            }
            if(ship2collided)
            {
                
                b[i].x = -1;
                b[i].y = -1;
                b[i].angle = 0;
                ship2life-=25;
            }
            // out of screen can properly be calculated by detecting collision with the bounds of the screen
            if(outOfScreen)
            {
                b[i].x = -1;
                b[i].y = -1;
                b[i].angle = 0;
            }
        }
    }
}

void FireBullet()
{
    for(int i = 0; i < NUM_BULLETS; i++)
    {
        bulletfired=true;
        // Find a bullet which has not been fired yet
        if(b[i].x < 0 && b[i].y < 0)
        {
            // Fire the bullet and return
            b[i].x = tankmainturretX;
            b[i].y = tankmainturretY;
            b[i].angle = tankmainturretrotation;
            return;
        }
    }
}

void monster()
{
	if(monsterX >= tankX - 73 && monsterX <= tankX + 73 && monsterY >=tankY-50 && monsterY <= tankY + 50 )
    {	
		monstercollided=true;
        if(tanklife==0)
		{
            tankalive=false;
            gameend=true;
            tankmainturretX;
            tankX=2000;
            scene1=false;
            scene2=false;
            scene3=true;
		}
	}	
    if(monstercollided)
    {
		if(monsteralive)
        {
			tanklife-=25;
        }
    }
            									
}	
void movemonster()
{
	if(tankalive)
	{
		moveToDestination(600, 0, &monsterX, &monsterX, 0.5);
		moveToDestination(600, 0, &lifeX, &lifeX, 0.5);
		frame7+=0.25;
		if (frame7 > 15)
    	{
    		frame7 = 1;
    	}
    				}
}

void ship1()
{
	if(missile1X >= tankX - 73 && missile1X <= tankX + 73 && missile1Y >=tankY-50 && missile1Y <= tankY + 50 )
	{
		missile1collided=true;
            	if(tanklife==0)
            	{
            		tankalive=false;
            		gameend=true;
            		tankmainturretX;
            		tankX=2000;
            		scene1=false;
            		scene2=false;
            		scene3=true;
            	}
            }	
            if(missile1collided)
            {
                tanklife-=10;
            }				
	
}	
void ship2()
{
	if(missile2X >= tankX - 73 && missile2X <= tankX + 73 && missile2Y >=tankY-50 && missile2Y <= tankY + 50 )
	{
		missile2collided=true;
            	if(tanklife==0)
            	{
            		tankalive=false;
            		gameend=true;
            		tankmainturretX;
            		tankX=2000;
            		scene1=false;
            		scene2=false;
            		scene3=true;
            	}
            }	
            if(missile2collided)
            {
                tanklife-=10;
            }				
}	

void moveship1()
{
	if(ship1alive)
	{
		if(tankalive)
		{
			moveToDestination(700, 200, &ship1X, &ship1X, 1.0);
			frame13+=0.066666667;
			if (frame13 > 4)
			{
				frame13 = 1;
			}
		}
		if(ship1X > 300)
		{
			firemissile1=true;
		}
		if(firemissile1)
		{
			moveToDestination(-20, -20, &missile1X, &missile1Y, 1.5);
			DrawTexturedRectangle(missile1Verts, missile1UV,missile1Texture, missile1X, missile1Y);
		}
	}
}	

void moveship2()
{
	if(ship2alive)		          
	{
		if(tankalive)
		{
			moveToDestination(800, 300, &ship2X, &ship2X, 0.5);
			frame14+=0.083333333;
			if (frame14 > 5)
			{
				frame14 = 1;
			}
		}
		if(ship2X > 300)
		{
			firemissile2=true;
		}
		if(firemissile2&&ship2alive)
		{
			moveToDestination(-20, -20, &missile2X, &missile2Y, 1.0);
			DrawTexturedRectangle(missile2Verts, missile2UV,missile2Texture, missile2X, missile2Y);
		}
	}
}					

void grandma()
{
	DrawTexturedRectangle(grandmaVerts, grandmaUV, grandmaTexture, 0, 0);
}

void road()
{
	DrawTexturedRectangle(roadVerts, roadUV, roadTexture, 0, 0);
}

void building()
{
	if(day==1)
	{
		DrawTexturedRectangle(building1Verts, building1UV, building1Texture, 0, 0);
	}
	else
	{
		DrawTexturedRectangle(buildingVerts, buildingUV, buildingTexture, 0, 0);
	}
}

void title2()
{
	if(timeout==1&&gameover==1)
		{
			DrawTexturedRectangle(titleVerts,titleUV,phase1Texture, 0, 0);
		}
}

void EarlyGameOver()
{
	if (alien2X <=1460 && alien2X > 830)
	{		
		alien2X -=speed;
	}
}

void animate()
{
	if(start==1)
	{
		if(moveToDestination(225, 830, &boyX, &boyX, 1.0))
		{
			day=true;
		}
		if(boyX >= 830 && boyX < 1000)
		{
			day = 0;
			frame=2;
			boyX = 2000;
			grandmaX=2000;
		}
	}	
}

void panimate()
{
	if(tankX >= 225 && tankX < 830 && phase2==1)
		{
			tankX += pspeed;
		}
			if(tankX >= 830 && tankX < 1000)
			{
				frame6=2;
			}
}


void animate2()
{
	if(boy2X <= 1260 && boy2X > 150 && start==1 && boyX>=830&& day==0 && grandmaX>=900)
		{
			boyX==1200;
			boy2X -= boyspeed;
		}
		else
		{
				frame1=2;
		}
}

void animate3()
{
	if (boy2X < 900 && alienX <=1460 && alienX > 530)
	{		
		alienX -=speed;
	}
}	

void animate4()
{
	if(alienX == 530 && bombY>=230)
	{
		DrawTexturedRectangle(bombVerts, bombUV, bombTexture, bombX, bombY);
		bombY-=2;
	}
}

void animate6()
{
	if(alien2X == 830 && bomb2Y>=230&&shield==0)
	{
		DrawTexturedRectangle(bombVerts, bombUV, bombTexture, bomb2X, bomb2Y);
		bomb2Y-=2;
	}
}


void animate11()
{
frame11+=0.00555555;

    	if (frame11 > 1)
    	{
    		frame11 = 1;
		}
}

void animate7()
{
	frame5+=0.016666667;
	boyX+=1;
    if (frame5>= 10&&shield==0)
    {
    	frame5 = 0;
    	num2X+=0.7;
    }	
}

void animate5()
{
	frame4+=0.016666667;
	boyX+=1;
    if (frame4 >= 10&&shield==0)
    {
    	frame4 = 0;
    	numX+=0.7;
    }	
    if(numX>=652)
    {
		timeout=1;
    	EarlyGameOver();
    }	
}

void animate10()
{
	frame10+=0.00555555;
	if (frame10 > 1)
    	{
	  		frame10 = 1;
  			animate();
    	}
}



void animate8()
{
		if(shellX >= 225 && shellX < 830 && fired==1)
		{
			DrawTexturedRectangle(shellVerts, shellUV, shellTexture, shellX, shellY,shellrotation);
			DrawTexturedRectangle(tankfireVerts, tankfireUV,texture9[(int)frame8], tankfireX, tankfireY,firerotation);
			DrawTexturedRectangle(tanksmokeVerts, tanksmokeUV,texture10[(int)frame9], tanksmokeX, tanksmokeY,smokerotation);
			shellX += 1;
		}
		frame8+=0.13333333;
		if (frame8 > 7)
    	{
    		frame8 = 1;
    		tankfireX=2000;
    	}
    	frame9+=0.1333333;
		if (frame9 > 7)
    	{
    		frame9 = 1;
    		tanksmokeX=2000;
    	}
}
void Key(int key,int x,int y)
{
	switch(key)
	{
		case GLUT_KEY_UP:
				boyY++;
				boy2Y++;
				alienY++;
				grandmaY++;
				bombY++;
				if(phase2==1)
				{
    				tankmainturretrotation += 5.0;
    				dx+=5.0;
    				smokerotation += 5.0;
    				firerotation += 5.0;
    				shellrotation += 5.0;
    			}	
		break;
		
		case GLUT_KEY_INSERT:
					if(tankalive)
					{
						FireBullet();
					}
		break;			
			
		case GLUT_KEY_DOWN:
				boyY--;
				boy2Y--;
				alienY--;
				grandmaY--;
				bombY--;
				
				if(phase2==1)
				{
    				tankmainturretrotation -= 5.0;
    				dx-=5;
    				smokerotation -= 5.0;
    				firerotation -= 5.0;
    				shellrotation -= 5.0;
    			}
		break;
		case GLUT_KEY_LEFT:
				boyX-=2;
				boy2X+=2;
				alienX+=2;
				grandmaX--;
				bombX--;
				tankX--;
				tankmainturretX--;
				tanksmokeX--;
				tankfireX--;
				frame6+=0.1;
    			if (frame6 > 3)
    			{
    				frame6 = 1;
    			}
		break;
		
		case GLUT_KEY_RIGHT:
				frame6+=0.1;
    			if (frame6 > 3)
    			{
    				frame6 = 1;
    			}
				if(tankX>790)
				{
					grandma1X=2000;
				}
				if(tankX>1150)
				{
					scene1=false;
					scene2=false;
					scene3=false;
					scene4=true;
				}
				boyX+=2;
				boy2X-=2;
				alienX-=2;
				grandmaX++;
				bombX++;
				tankX++;
				tankmainturretX++;
				tankfireX++;
				tanksmokeX++;
		break;
	}
}


void mouse(int btn,int state,int x,int y)
{
	if(phase2==1)
	{
		if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
		{
			if(tankalive)
			{
				FireBullet();
			}    	
		}
	}
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
		start=1;
		scene1=false;
	}
	if(start==0)
	{
		if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
		{
			phase2=1;
			scene1=false;
			scene2=true;
		}
	}
	if(scene3)
	{
		if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
		{
			scene1=true;
			scene2=false;
			scene3=false;
			start=0;
			phase2=0;
			
		}
	}
	if(numX<2000&&actX<2000&&timeout==0&&phase2==0)
	{
		if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
    	{
			shield=1;
		}
	}
}

void house()
{	if(day==1&&shield==0)
	{
		DrawTexturedRectangle(HouseVerts, HouseUV, HouseTexture, 0, 0);
	}
	if(day==0&&shield==0)
	{
		DrawTexturedRectangle(House1Verts, House1UV, House1Texture, 0, 0);
	}
	if(shield==1)
	{
		DrawTexturedRectangle(House1Verts, House1UV, House11Texture, 0, 0);
		if (alien2X <=1460 && alien2X > 830)
		{		
			alien2X -=speed;
		}
		if(alien2X == 830 && bomb3Y>=438)
		{
			DrawTexturedRectangle(bomb3Verts, bomb3UV, bomb3Texture, bomb3X, bomb3Y);
			bomb3Y-=2;
		}
	}
}

void house2()
{
	DrawTexturedRectangle(House2Verts, House2UV, House2Texture, 0, 0);
}

void sky()
{
	if(day==1)
	{
		DrawTexturedRectangle(sky1Verts, sky1UV, sky1Texture, 0, 0);
	}
	else
	{
		DrawTexturedRectangle(sky2Verts, sky2UV, sky2Texture, 0, 0);
	}
}

void psky()
{
	DrawTexturedRectangle(pskyVerts, pskyUV, pskyTexture, 0, 0);
}

bool loadTexture(const char* filename, GLuint* textureID)
{
    int channels, width, height;
    unsigned char* texels = stbi_load(filename, &width, &height, &channels, 4);

    if(texels == NULL)
    {
        printf("stb_image could not load image\n");
        return false;
    }

   glGenTextures(1, textureID);
    glBindTexture(GL_TEXTURE_2D, *textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texels);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	 glBindTexture( GL_TEXTURE_2D, texture1[(int)frame] );

    if(glGetError() != GL_NO_ERROR)
    {
        printf("Could not load texture\n");
        return false;
    }
    STBI_FREE(texels);

    return true;
}

void init()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
   	glClearColor(0,0,0,0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,1000.0,0.0,700.0);//LRTB
	loadTexture("1.png",&texture1[0]);
    loadTexture("2.png",&texture1[1]);
    loadTexture("3.png",&texture1[2]);
    loadTexture("4.png",&texture1[3]);
    loadTexture("5.png",&texture1[4]);
    loadTexture("6.png",&texture1[5]);
    
	loadTexture("monster2/1.png",&texture8[0]);
    loadTexture("monster2/2.png",&texture8[1]);
    loadTexture("monster2/3.png",&texture8[2]);
    loadTexture("monster2/4.png",&texture8[3]);
    loadTexture("monster2/5.png",&texture8[4]);
    loadTexture("monster2/6.png",&texture8[5]);
    loadTexture("monster2/7.png",&texture8[6]);
    loadTexture("monster2/8.png",&texture8[7]);
    loadTexture("monster2/9.png",&texture8[8]);
    loadTexture("monster2/10.png",&texture8[9]);
    loadTexture("monster2/11.png",&texture8[10]);
    loadTexture("monster2/12.png",&texture8[11]);
    loadTexture("monster2/13.png",&texture8[12]);
    loadTexture("monster2/14.png",&texture8[13]);
    loadTexture("monster2/15.png",&texture8[14]);
    loadTexture("monster2/16.png",&texture8[15]);
    
    loadTexture("tankfire/1.png",&texture9[0]);
    loadTexture("tankfire/2.png",&texture9[1]);
    loadTexture("tankfire/3.png",&texture9[2]);
    loadTexture("tankfire/4.png",&texture9[3]);
    loadTexture("tankfire/5.png",&texture9[4]);
    loadTexture("tankfire/6.png",&texture9[5]);
    loadTexture("tankfire/7.png",&texture9[6]);
    loadTexture("tankfire/8.png",&texture9[7]);
    
    loadTexture("tanksmoke/1.png",&texture10[0]);
    loadTexture("tanksmoke/2.png",&texture10[1]);
    loadTexture("tanksmoke/3.png",&texture10[2]);
    loadTexture("tanksmoke/4.png",&texture10[3]);
    loadTexture("tanksmoke/5.png",&texture10[4]);
    loadTexture("tanksmoke/6.png",&texture10[5]);
    loadTexture("tanksmoke/7.png",&texture10[6]);
    loadTexture("tanksmoke/8.png",&texture10[7]);
    
    loadTexture("tankfinal1.png",&texture7[0]);
    loadTexture("tankfinal2.png",&texture7[1]);
    loadTexture("tankfinal3.png",&texture7[2]);
    loadTexture("tankfinal4.png",&texture7[3]);
    loadTexture("tank3.png",&mainturretTexture);
    
    loadTexture("life/100.png",&texture12[0]);
    loadTexture("life/100.png",&texture12[1]);
    loadTexture("life/75.png",&texture12[2]);
    loadTexture("life/50.png",&texture12[3]);
    loadTexture("life/25.png",&texture12[4]);
    loadTexture("life/0.png",&texture12[5]);
    
    loadTexture("Enemy3/Fly/f1.png",&texture13[0]);
    loadTexture("Enemy3/Fly/f2.png",&texture13[1]);
    loadTexture("Enemy3/Fly/f3.png",&texture13[2]);
    loadTexture("Enemy3/Fly/f4.png",&texture13[3]);
    
    loadTexture("Enemy4/Fly/f1.png",&texture14[0]);
    loadTexture("Enemy4/Fly/f2.png",&texture14[1]);
    loadTexture("Enemy4/Fly/f3.png",&texture14[2]);
    loadTexture("Enemy4/Fly/f4.png",&texture14[3]);
    loadTexture("Enemy4/Fly/f5.png",&texture14[4]);
    
    loadTexture("11.png",&texture2[0]);
    loadTexture("22.png",&texture2[1]);
    loadTexture("33.png",&texture2[2]);
    loadTexture("44.png",&texture2[3]);
    loadTexture("55.png",&texture2[4]);
    loadTexture("66.png",&texture2[5]);
    loadTexture("g3.png", &gameendTexture);
    loadTexture("final.png", &gameclearedTexture);
    loadTexture("sm1.png", &missile1Texture);
    loadTexture("sm2.png", &missile2Texture);
   
    loadTexture("title.png",&texture11[0]);
    loadTexture("t1.png",&texture11[1]);
    loadTexture("N0.png",&texture5[9]);
    loadTexture("N1.png",&texture5[8]);
    loadTexture("N2.png",&texture5[7]);
    loadTexture("N3.png",&texture5[6]);
    loadTexture("N4.png",&texture5[5]);
    loadTexture("N5.png",&texture5[4]);
    loadTexture("N6.png",&texture5[3]);
    loadTexture("N7.png",&texture5[2]);
    loadTexture("N8.png",&texture5[1]);
    loadTexture("N9.png",&texture5[0]);
    
    loadTexture("num/N0.png",&texture6[9]);
    loadTexture("num/N1.png",&texture6[8]);
    loadTexture("num/N2.png",&texture6[7]);
    loadTexture("num/N3.png",&texture6[6]);
    loadTexture("num/N4.png",&texture6[5]);
    loadTexture("num/N5.png",&texture6[4]);
    loadTexture("num/N6.png",&texture6[3]);
    loadTexture("num/N7.png",&texture6[2]);
    loadTexture("num/N8.png",&texture6[1]);
    loadTexture("num/N9.png",&texture6[0]);
    
    for(int i = 0; i < 64; i++)
    {
        char filename[25] = "fireimages/f";
        const char *png = ".png";
        char num[3];
        sprintf(num, "%d", i+1);
        strcat(filename, num);
        strcat(filename, png);
        loadTexture(filename,&texture3[i]);
    }
    
    for(int i = 0; i < 30; i++)
    {
        char filename[25] = "smokeimages/s";
        const char *png = ".png";
        char num[3];
        sprintf(num, "%d", i+1);
        strcat(filename, num);
        strcat(filename, png);
        loadTexture(filename,&texture4[i]);
    } 
 
    loadTexture("house.png", &HouseTexture);
	loadTexture("house1.png", &House1Texture);
	loadTexture("h1234.png", &House11Texture);
	loadTexture("h12.png", &House2Texture);
	loadTexture("sky1.png", &sky1Texture);
	loadTexture("n31.jpg", &sky2Texture);
	loadTexture("grandma.png", &grandmaTexture);
	loadTexture("grandma1.png", &grandma2Texture);
	loadTexture("ship2.png", &alienTexture);
	loadTexture("ship3.png", &alien2Texture);
	loadTexture("h10.png", &buildingTexture);
	loadTexture("h11.png", &building1Texture);
	loadTexture("r3.jpg", &roadTexture);
	loadTexture("bomb1.png", &bombTexture);
	loadTexture("bomb2.png", &bomb3Texture);
	loadTexture("shields.png", &actTexture);
	loadTexture("end1.png", &endTexture);
	loadTexture("p1.png", &portalTexture);
	loadTexture("b.png", &pskyTexture);
	loadTexture("shell.png", &shellTexture);
	InitBullets();
}	

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	 if(scene4&&tankalive==true)
            {
            			glClear(GL_COLOR_BUFFER_BIT);
            			DrawTexturedRectangle(gameendVerts, gameendUV, gameclearedTexture, gameendX, gameendY);
            }
	
	if(scene3)
            {
            			glClear(GL_COLOR_BUFFER_BIT);
            			DrawTexturedRectangle(gameendVerts, gameendUV, gameendTexture, gameendX, gameendY);
            }
	if(phase2==1)
	{
		if(scene2)
		{
		psky();
		UpdateBullets();
		DrawBullets();
		monster();
		movemonster();
		if(ship1alive)
		{
		ship1();
		moveship1();
		}
		if(ship2alive)
		{
		ship2();
		moveship2();
		}
		if(tankalive)
            		{
            		DrawTexturedRectangle(endVerts, endUV, endTexture, endX, endY);	
            		}
		if(fired==1)
		{
		animate8();
		}
		if(monsteralive&&life>=0)
		{
			DrawTexturedRectangle(monsterVerts, monsterUV,texture8[(int)frame7], monsterX, monsterY);
			DrawTexturedRectangle(lifeVerts, lifeUV,texture12[(int)frame12], lifeX, lifeY);
		}
		
		if(ship1alive&&ship1life>=0)
		{
			DrawTexturedRectangle(ship1Verts, ship1UV,texture13[(int)frame13], ship1X, ship1Y);
		}
		
		if(ship2alive&&ship2life>=0)
		{
			DrawTexturedRectangle(ship2Verts, ship2UV,texture14[(int)frame14], ship2X, ship2Y);
		}
		DrawTexturedRectangle(House1Verts, House1UV, House11Texture, 0, -120);
			DrawTexturedRectangle(grandmaVerts, grandmaUV, grandma2Texture, grandma1X, grandma1Y);
			
		if(tankalive&&tanklife>0)
		{
    		DrawTexturedRectangle(tankmainturretVerts, tankmainturretUV,mainturretTexture, tankmainturretX, tankmainturretY,tankmainturretrotation);
			DrawTexturedRectangle(tankVerts, tankUV,texture7[(int)frame6], tankX, tankY);
		}
	}
	}
	if(start==0&&phase2==0)
	{
		if(scene1)
		{
		DrawTexturedRectangle(titleVerts, titleUV,texture11[(int)frame10], titleX, titleY);
		}
		
	}
	if(start==1&&phase2==0)
	{
		sky();
		road();
		house();
		animate2();
		animate3();
		building();
		house2();
		animate4();
		animate6();
		DrawTexturedRectangle(boyVerts, boyUV,texture1[(int)frame], boyX, boyY);
		DrawTexturedRectangle(boy2Verts, boy2UV,texture2[(int)frame1], boy2X, boy2Y);
		
		if(alienX == 530&&bombY<=231)
		{
		
		DrawTexturedRectangle(fireVerts, fireUV,texture3[(int)frame2], fireX, fireY);
		DrawTexturedRectangle(fireVerts, fireUV,texture3[(int)frame2], fire1X, fire1Y);
		DrawTexturedRectangle(fireVerts, fireUV,texture3[(int)frame2], fire2X, fire2Y);
		DrawTexturedRectangle(smokeVerts, smokeUV,texture4[(int)frame3], smokeX, smokeY);
		}
		
		if(alien2X == 830&&bomb2Y<=231&&shield==0)
		{
		DrawTexturedRectangle(fireVerts, fireUV,texture3[(int)frame2], fire3X, fire3Y);
		DrawTexturedRectangle(fireVerts, fireUV,texture3[(int)frame2], fire4X, fire4Y);
		DrawTexturedRectangle(fireVerts, fireUV,texture3[(int)frame2], fire5X, fire5Y);
		DrawTexturedRectangle(smokeVerts, smokeUV,texture4[(int)frame3], smoke2X, smoke2Y);
		
		}
		
		if(alienX<=1300)
		{
		DrawTexturedRectangle(portalVerts, portalUV, portalTexture, portalX, portalY);
		}
		
		if(shield==0&&bombY<=231&&timeout==1)
		{
			DrawTexturedRectangle(numVerts, numUV,texture6[(int)frame5], num2X, num2Y);
		}
		
		if(shield==0&&bombY<=231&&timeout==0)
		{
			DrawTexturedRectangle(numVerts, numUV,texture5[(int)frame4], numX, numY);
			DrawTexturedRectangle(actVerts, actUV, actTexture, actX, actY);	
		}
			
		else
			{
				numX==2000;
				actX==2000;
			}
		if(shield==0&&timeout==1)
		{
			DrawTexturedRectangle(numVerts, numUV,texture5[(int)frame5], num2X, num2Y);	
		}
		DrawTexturedRectangle(alienshipVerts, alienshipUV, alienTexture, alienX, alienY);
		DrawTexturedRectangle(alienship2Verts, alienship2UV, alien2Texture, alien2X, alienY);
		DrawTexturedRectangle(grandma1Verts, grandma1UV, grandmaTexture, grandmaX, grandmaY);
		frame+=0.08333;
    	if (frame > 5)
    	{
    		frame = 1;
    	}
    	
    	frame1+=0.08333;
    	if (frame1 > 5)
    	{
    		frame1 = 1;
    	}

    	frame2+=1.05;
    	if (frame2 > 63)
    	{
    		frame2 = 1;
    	}
    	frame3+=0.483333;
    	if (frame3 > 29)
    	{
    		frame3 = 1;
    	}
  		animate5();
  		animate7();
    	
   	}
	
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

void ResizeScreen(int w, int h)
{
    
    float aspectRatio = (float)ASPECT_WIDTH / ASPECT_HEIGHT;
    float screenAR = (float)w / h;
    int viewportHeight = (1/aspectRatio) * w;
    int viewportWidth = aspectRatio * h;

    if(screenAR < aspectRatio)
        //Reduce height .. black horizontal bars
        glViewport(0, (h - viewportHeight) / 2.0, w, viewportHeight);
    else
        glViewport((w - viewportWidth) / 2.0, 0, viewportWidth, h);
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(1000.0,700.0);
	glutInitWindowPosition(0,0);
	glutCreateWindow("AFY");
	glutDisplayFunc(display);
	glutReshapeFunc(ResizeScreen);
	init();
	if(start==1&&phase2==1)
	{
	glutIdleFunc(panimate);	
	}
	if(fired==1)
	{
		glutIdleFunc(animate8);
	}
	if(start==0&&phase2==0)
	{
		glutIdleFunc(animate10);
	}
	glutMouseFunc(mouse);
	
	glutSpecialFunc(Key);
	glutMainLoop();
	return 0;
}