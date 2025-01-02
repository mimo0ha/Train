#pragma once
#include <glut.h>
//#include "Driver.h"
#include "Train_Carriage.h"

class passenger 
{
public:
	GLuint list;
	Wall w;
	BlindQuad window;
	//Wall downW;
	Ceil_Floor cf;
	Cube c,c1,c2, col1, col2, col3, col4;
	WallWithDoor wallWithDoor;
	WallWithDoor wallWithDoor2;
	WallWithDoor wallWithDoor3;		
	Bridge bridgeC ;
	Rail rail1;
void Init(int TrainTexture ,int TextureTop , int TextureFloor,  int Texturchair , int TextureFeet,int ColumnPassenger , int gray,int top , int med , int down) {
	    
		w.Init(top,med,down);
		window.Init(24.5,6);
		cf.Init(TextureTop,TextureFloor);
		wallWithDoor.Init(top,med,down);
		wallWithDoor2.Init(top,med,down);
		wallWithDoor3.Init(top,med,down);
		c.init(TextureFeet,TextureFeet,TextureFeet,TextureFeet,TextureFeet,TextureFeet);
		c1.init(Texturchair,Texturchair,Texturchair,Texturchair,Texturchair,Texturchair);
		c2.init(Texturchair,Texturchair,Texturchair,Texturchair,Texturchair,Texturchair);
		col1.init(ColumnPassenger,ColumnPassenger,ColumnPassenger,ColumnPassenger,ColumnPassenger,ColumnPassenger);
		bridgeC.init(TrainTexture,1);
		rail1.init(gray);
		list = glGenLists(1);
		glNewList(list, GL_COMPILE);
		glEndList();
		}

void Draw(bool IsOpen) {
	float a = 27;
	float b = -5;
	float v = 5;
	float j=25;
	float m=25;
	float z = 6;
	   //bridge
		  glPushMatrix();
		  glTranslatef(28.5,-2,0);
		  bridgeC.draw();
		  glPopMatrix();
	  //rail_1
		  glPushMatrix();
		  glTranslatef(0,-9.2,2.5);
		  rail1.draw();
		  glPopMatrix();
	  //rail_2
		  glPushMatrix();
		  glTranslatef(0,-9.2,-2.5);
		  rail1.draw();
		  glPopMatrix();
		////////////////////«·ÕÌÿ «»Ê ‘»«ﬂ
		glPushMatrix();
		glTranslated(0, 0, carriageHight/2);
		w.Draw();
		glPopMatrix();
		/////////////////////”ﬁ› Ê«—÷Ì…
		glPushMatrix();
		cf.Draw();
		glPopMatrix();
		/////////////////////«·«»Ê«»
		glPushMatrix();
		glTranslated(carriageWidth/2+0.01,0,0);
		wallWithDoor.Draw(IsOpen);
		glPopMatrix();
		///
		glPushMatrix();
		glTranslated(-carriageWidth/2-0.01, 0, 0);
		wallWithDoor2.Draw(IsOpen);
		glPopMatrix();
		///
		glPushMatrix();
		glScaled(3.25,1,1);
		glRotated(90,0,-1,0);
		glTranslated(-8, 0, -carriageWidth/2+26);
		wallWithDoor3.Draw(IsOpen);
		glPopMatrix();
	////////////////////«·⁄Ê«„Ìœ 
	glPushMatrix();
	glTranslated(-10,-0.1,-4);
	glScaled(0.2,15,0.2);
	col1.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(10,-0.1,-4);
	glScaled(0.2,15,0.2);
	col1.draw();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(-10,-0.1,2);
	glScaled(0.2,15,0.2);
	col1.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(10,-0.1,2);
	glScaled(0.2,15,0.2);
	col1.draw();
	glPopMatrix();

		glPushMatrix();
		glScaled(1,1.3,1);
		
	for(float i = 0 ; i<=10 ; i++)
	  {
		j-=4;
		glPushMatrix();
		glTranslated(j,1.5,z);
		//////////////«·ﬂ—”Ì
		/////1
		glPushMatrix();
		glTranslated(0.5,-7,0.5);
		glScaled(0.1,1,0.1);
		c.draw();
		glPopMatrix();
        /////2
		glPushMatrix();
		glTranslated(0.5,-7,-0.5);
		glScaled(0.1,1,0.1);
		c.draw();
		glPopMatrix();
		/////3
		glPushMatrix();
		glTranslated(-0.5,-7,0.5);
		glScaled(0.1,1,0.1);
		c.draw();
		glPopMatrix();
		/////4
		glPushMatrix();
		glTranslated(-0.5,-7,-0.5);
		glScaled(0.1,1,0.1);
		c.draw();
		glPopMatrix();
		///////«·ﬁ⁄œ…
		glPushMatrix();
		glTranslated(0,-6.5,0);
		glScaled(1.15,0.1,1.15);
		c1.draw();
		glPopMatrix();
		///////«·„”‰œ
		glPushMatrix();
		glTranslated(-0.55,-6,0);
		glScaled(0.1,1.1,1.15);
		c2.draw();
		glPopMatrix();

		glPopMatrix();
		}
		
	for(float i = 0 ; i<=10 ; i++)
	  {
		m-=4;
		glPushMatrix();
		glTranslated(m,1.5,z-2);
		//////////////«·ﬂ—”Ì
		/////1
		glPushMatrix();
		glTranslated(0.5,-7,0.5);
		glScaled(0.1,1,0.1);
		c.draw();
		glPopMatrix();
        /////2
		glPushMatrix();
		glTranslated(0.5,-7,-0.5);
		glScaled(0.1,1,0.1);
		c.draw();
		glPopMatrix();
		/////3
		glPushMatrix();
		glTranslated(-0.5,-7,0.5);
		glScaled(0.1,1,0.1);
		c.draw();
		glPopMatrix();
		/////4
		glPushMatrix();
		glTranslated(-0.5,-7,-0.5);
		glScaled(0.1,1,0.1);
		c.draw();
		glPopMatrix();
		///////«·ﬁ⁄œ…
		glPushMatrix();
		glTranslated(0,-6.5,0);
		glScaled(1.15,0.1,1.15);
		c1.draw();
		glPopMatrix();
		///////«·„”‰œ
		glPushMatrix();
		glTranslated(-0.55,-6,0);
		glScaled(0.1,1.1,1.15);
		c2.draw();
		glPopMatrix();

		glPopMatrix();
		}
	for(float i = 0 ; i<=4 ; i++)
	{
		b-=4;
		glPushMatrix();
		glTranslated(b,1.5,-z);
		//////////////«·ﬂ—”Ì
		/////1
		glPushMatrix();
		glTranslated(0.5,-7,0.5);
		glScaled(0.1,1,0.1);
		c.draw();
		glPopMatrix();
        /////2
		glPushMatrix();
		glTranslated(0.5,-7,-0.5);
		glScaled(0.1,1,0.1);
		c.draw();
		glPopMatrix();
		/////3
		glPushMatrix();
		glTranslated(-0.5,-7,0.5);
		glScaled(0.1,1,0.1);
		c.draw();
		glPopMatrix();
		/////4
		glPushMatrix();
		glTranslated(-0.5,-7,-0.5);
		glScaled(0.1,1,0.1);
		c.draw();
		glPopMatrix();
		///////«·ﬁ⁄œ…
		glPushMatrix();
		glTranslated(0,-6.5,0);
		glScaled(1.15,0.1,1.15);
		c1.draw();
		glPopMatrix();
		///////«·„”‰œ
		glPushMatrix();
		glTranslated(-0.55,-6,0);
		glScaled(0.1,1.1,1.15);
		c2.draw();
		glPopMatrix();
		glPopMatrix();
		}
	for(float i = 0 ; i<=4 ; i++)
	{
		v+=4;
		glPushMatrix();
		glTranslated(v,1.5,-z);
		//////////////«·ﬂ—”Ì
		/////1
		glPushMatrix();
		glTranslated(0.5,-7,0.5);
		glScaled(0.1,1,0.1);
		c.draw();
		glPopMatrix();
        /////2
		glPushMatrix();
		glTranslated(0.5,-7,-0.5);
		glScaled(0.1,1,0.1);
		c.draw();
		glPopMatrix();
		/////3
		glPushMatrix();
		glTranslated(-0.5,-7,0.5);
		glScaled(0.1,1,0.1);
		c.draw();
		glPopMatrix();
		/////4
		glPushMatrix();
		glTranslated(-0.5,-7,-0.5);
		glScaled(0.1,1,0.1);
		c.draw();
		glPopMatrix();
		///////«·ﬁ⁄œ…
		glPushMatrix();
		glTranslated(0,-6.5,0);
		glScaled(1.15,0.1,1.15);
		c1.draw();
		glPopMatrix();
		///////«·„”‰œ
		glPushMatrix();
		glTranslated(-0.55,-6,0);
		glScaled(0.1,1.1,1.15);
		c2.draw();
		glPopMatrix();
		glPopMatrix();
		}
		glPopMatrix();
	///////////////‘»«»Ìﬂ
		glColor4f(1.0,1.0,1.0,0.5);
	    glPushMatrix();
		glTranslated(-12.75, 1, 7.9);
        glEnable(GL_BLEND);
		window.Draw();
		glDisable(GL_BLEND);
		glPopMatrix();

		glPushMatrix();
		glTranslated(12.75, 1, 7.9);
		glEnable(GL_BLEND);
		window.Draw();
		glDisable(GL_BLEND);
		glPopMatrix();
		glCallList(list);
		}

};




















