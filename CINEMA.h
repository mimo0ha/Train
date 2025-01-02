#pragma once
#include <glut.h>
#include "Train_Carriage.h"
//#include "Chair.h" 
float x50=0;
float xSpeed =0.01;

float CurtainsMovment=1; 
float CurtainsSpeed =0.05 ; 
class Cinema : public Train_Carriage 
{
public:
	GLuint list;
	CHAIR chair;
	Quad q1,q2 ,q3,q4;
	Quad screen ;
	Quad curtain;
	Bridge bridgeC;
	Rail rail1;
	void Init(int TrainTexture , int TextureFloor ,int TextureScreen , int TexturFabric , int TexturCurtain, int gray) {
		list = glGenLists(1);
		Train_Carriage :: Init(TrainTexture,TrainTexture,TrainTexture,TrainTexture);
		bridgeC.init(TrainTexture,1);
		rail1.init(gray);
		chair.Init(TexturFabric);
		q1.Init(TrainTexture,26,16);
		screen.Init(TextureScreen , 15 , 10 );
		curtain.Init(TexturCurtain,15,10);
		q2.Init(TextureFloor,26,16);
		q3.Init(TrainTexture,26,16);
		glNewList(list, GL_COMPILE);
		glEndList();
	}
	void Draw(bool IsOpen,bool isOpen2) {
		Train_Carriage :: Draw(IsOpen);
		OpenTheCurtains(isOpen2);
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
		glTranslated(0, 0, +8);
		q1.Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslated(0, 0, -8);
		q3.Draw();
		glPopMatrix();

		glPushMatrix();
		glRotated(90, 1, 0, 0);
		glTranslated(0,  0,+8);
		q2.Draw();
		glPopMatrix();
		
		//ÇáÔÇÔÉ
		glPushMatrix();
		glTranslated(0, 0, 7.70);
		screen.Draw();
		glPopMatrix();
		
		//ÌáÇíá
		glPushMatrix();
		glTranslated(x50, 0, 7.70);
		glScaled(CurtainsMovment,1,1);
		curtain.Draw();
		glPopMatrix();
		
		//ÇáßäÈÇíÉ
		glPushMatrix();
		glTranslated(0,-8,-8);
		//ÇáãÓäÏ
		glPushMatrix();
		glTranslated(0,1,0.3);
		glScalef(18,2,0.5);
		chair.Draw();
		glPopMatrix();
		//ÇáÞÚÏÉ
		glPushMatrix();
		glTranslated(0,0.5,1.2);
		glScalef(18,0.9,2);
		chair.Draw();
		glPopMatrix();

		glPopMatrix();
		
		glCallList(list);
		glPopMatrix();
	}
	void OpenTheCurtains(bool isOpen2) {
		if (isOpen2 )
		{	if(CurtainsMovment > 0 && x50 <2)
			CurtainsMovment-=CurtainsSpeed;
			x50+=xSpeed;
		}
		/*else 
		{
		
		if(CurtainsMovment > 0 && x50 <2)
		{
			CurtainsMovment-=CurtainsSpeed;
			x50+=xSpeed;
		}

		}*/
	}
};



















