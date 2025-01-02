#pragma once
#include <GLAUX.H>
#include "Train_Carriage.h"
#include "bed.h"
#include "skybox.h"
class SleepCarriage:Train_Carriage{
	
public:
	Bed bed1,bed3;
	Bridge bridge01;
	Rail rail1;
	BlindQuad window;
	GLuint list;//

	void init(int TrainTexture,int bedTexture,int bedCover, int TopWall,int railImg,int bedCube)
	{
		Train_Carriage::Init(TrainTexture,TopWall,TrainTexture,TrainTexture);
		
		bed1.init(bedTexture,bedCover,bedCube);
		bed3.init(bedTexture,bedCover,bedCube);
		bridge01.init(TrainTexture,1);
		rail1.init(railImg);
		window.Init(24.5,6);
	    list = glGenLists(1);
	    glNewList(list, GL_COMPILE);/////// بداية كتابة التعليمات
    

    glEnd(); 
/////// نهاية كتابة التعليمات   
    glEndList();
	}
	void draw(bool isOpen)// هاد التابع كمان اساسي ولازم نحطو بكل كلاس وهو يلي منستدعي فيه الليستة يلي عملناها فوق
  {	
	  Train_Carriage::Draw(isOpen);
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

	    //bridge
	  glPushMatrix();
	glTranslatef(28.5,-2,0);
	bridge01.draw();
	glPopMatrix();

	//first_bed
	glPushMatrix();
	glScaled(1,0.75,1);
	glRotatef(180, 0.0f, 1.0f, 0.0f);
	glTranslatef(-12.5,-2.5,-0.5);
	bed1.draw();
	glPopMatrix();

	//second_bed
	glPushMatrix();
	glScaled(1,0.75,1);
	glRotatef(180, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.5,-2.5,-0.5);
	bed1.draw();
	glPopMatrix();

	//third_bed
	glPushMatrix();
	glScaled(1,0.75,1);
	glTranslatef(0.5,-2.5,-11.5);
	bed1.draw();
	glPopMatrix();
	
	//4th_bed
	glPushMatrix();
	glScaled(1,0.75,1);
	glTranslatef(-12.5,-2.5,-11.5);
	bed1.draw();
	glPopMatrix();

	//5th_bed
	glPushMatrix();
	glScaled(1,0.75,1);
	glTranslatef(-12.5,-2.5,-0.5);
	bed3.draw();
	glPopMatrix();

	//orginal
	//6th_bed
	glPushMatrix();
	glScaled(1,0.75,1);
	glTranslatef(0.5,-2.5,-0.5);
	bed3.draw();
	glPopMatrix();

	//7th_bed
	glPushMatrix();
	glScaled(1,0.75,1);
	glRotatef(180, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.5,-2.5,-11.5);
	bed3.draw();
	glPopMatrix();

	//8th
	glPushMatrix();
	glScaled(1,0.75,1);
	glRotatef(180, 0.0f, 1.0f, 0.0f);
	glTranslatef(-12.5,-2.5,-11.5);
	bed1.draw();
	glPopMatrix();
	

	//for window_3
    glPushMatrix();
    glTranslated(-12.75, 1, 7.9);
    glEnable(GL_BLEND);
    window.Draw();
    glDisable(GL_BLEND);
    glPopMatrix();

    //for window_4
    glPushMatrix();
    glTranslated(12.75, 1, 7.9);
    glEnable(GL_BLEND);
    window.Draw();
    glDisable(GL_BLEND);
    glPopMatrix();

    //for window_2
    glPushMatrix();
    glTranslated(12.75, 1, -7.9);
    glEnable(GL_BLEND);
    window.Draw();
    glDisable(GL_BLEND);
    glPopMatrix();

    //for window_1
    glPushMatrix();
    glTranslated(-12.75, 1, -7.9);
    glEnable(GL_BLEND);
    window.Draw();
    glDisable(GL_BLEND);
    glPopMatrix();


    glCallList(list);
  }


};
