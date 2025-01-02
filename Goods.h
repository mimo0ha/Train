#pragma once
#include <glut.h>
#include "Train_Carriage.h"

class goods : public Train_Carriage 
{
public:
	GLuint list;
	Quad q1 , q2;
	Cube c;		
	Bridge bridgeC ;
	Rail rail1;
void Init(int TrainTexture ,int TextureBridg , int TextureFloor,  int TextureWood , int WoodGood , int gray) {
		list = glGenLists(1);
		Train_Carriage :: Init(TrainTexture,TrainTexture,TrainTexture,TrainTexture);
		q1.Init(TrainTexture,26,16);
		q2.Init(TrainTexture,26,16);
		c.init(WoodGood,WoodGood,WoodGood,WoodGood,WoodGood,WoodGood);
		bridgeC.init(TextureBridg,1);
		rail1.init(gray);
		glNewList(list, GL_COMPILE);
		glEndList();
		}

void Draw(bool IsOpen) {
		Train_Carriage :: Draw(IsOpen);
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

		glPushMatrix();
		glScaled(2,1,1);

		glPushMatrix();
		glTranslated(0,0,+8);
		q1.Draw();
		glPopMatrix();
		
		glPushMatrix();
		glTranslated(0,0,-8);
		q2.Draw();
		glPopMatrix();
		 
		glPushMatrix();
		glScaled(2,4,4);
		glTranslated(-5.8,-1.48,-1.4);
		c.draw();
		glPopMatrix();
		for(float i =0 ;i<=5 ; i++)
		{
		glPushMatrix();
		glScaled(2,4,4);
		glTranslated(i*1.2,-1.48,-1.4);
		c.draw();
		glPopMatrix();
		}

		for(float i =-2 ;i<=5 ; i++)
		{
		glPushMatrix();
		glScaled(2,4,4);
		glTranslated(i*1.2-1.1,-0.5,-1.4);
		c.draw();
		glPopMatrix();
		}
		float scl=1.5;
		for(float i =0 ;i<=7 ; i++)
		{
		glPushMatrix();
		glScaled(2*scl,5*scl,3*scl);
		glTranslated(i*0.4,-0.55,1.1);
		c.draw();
		glPopMatrix();
		}

		///////////
		for(float i = 0 ;i<3 ; i+=1.2)
		{
		glPushMatrix();
		glScaled(2*scl,2*scl,3*scl);
		glTranslated(i*1.2,0.4,1.1);
		c.draw();
		glPopMatrix();
		}

		glPushMatrix();
		glScaled(2,4,4);
		glTranslated(-3.5*1.2,-1.48,-1.4);
		c.draw();
		glPopMatrix();
		
		
		glPushMatrix();
		glScaled(2,4,4);
		glTranslated(-5,-0.5,-1.4);
		c.draw();
		glPopMatrix();
		

		glPushMatrix();
		glScaled(8,4,4);
		glTranslated(-0.3,-1.48,-1.4);
		c.draw();
		glPopMatrix();
		

		glPopMatrix();
		glCallList(list);
		}

};




















