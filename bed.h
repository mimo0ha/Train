#pragma once
#include <GLAUX.H>
#include "Train_Carriage.h"





class Bed{
	/*Quad q1;
	Quad q2;
	Quad q3;
	Quad q4;
	 Cube cube1;*/
public:
	Quad q1;
	Quad q2;
	Quad q3;
	Quad q4;
	 Cube cube1;
	GLuint list;//

	void init(int bedTexture,int bedCover,int bedCube)
	{
	 q1.Init(bedTexture,12,4);
	 q2.Init(bedTexture,4,2);
	   q3.Init(bedTexture,4,4);
	   q4.Init(bedTexture,12,4);
		cube1.init(bedCube,bedCube,bedCube,bedCube,bedCube,bedCube);
	 list = glGenLists(1);
	 glNewList(list, GL_COMPILE);/////// بداية كتابة التعليمات 
	 glEnable(GL_TEXTURE_2D);
	 //رسم الوجه العلوي مع اطراف و تكستشر 
	 glBindTexture(GL_TEXTURE_2D,bedCover);
	 glBegin(GL_POLYGON);
	 glColor3f(1.0f, 1.0f, 1.0f);
	 glNormal3f(0,0,1);
	 //left part
	 glTexCoord2d(0,0);			glVertex3f(-13,-5, 3.9);//E
	 glTexCoord2d(0,0.16);			glVertex3f(-13,-4, 4);//H
	 glTexCoord2d(1,0.16);			glVertex3f(-1, -4, 4);//G
	 glTexCoord2d(1,0);			glVertex3f(-1, -5, 3.9);//F
	 glEnd();

	 glBegin(GL_POLYGON);
	 glColor3f(1.0f, 1.0f, 1.0f);
	 glNormal3f(0,0,1);
	 //top part
	  glTexCoord2d(0,0.83);			glVertex3f(-13,-4, 8);//A
	  glTexCoord2d(1,0.83);			glVertex3f(-1, -4, 8);//B
	  glTexCoord2d(1,0.16);			glVertex3f(-1, -4, 4);//G
	  glTexCoord2d(0,0.16);			glVertex3f(-13,-4, 4);//H
	  glEnd();

	   glBegin(GL_POLYGON);
	 glColor3f(1.0f, 1.0f, 1.0f);
	 glNormal3f(0,0,1);
	 //right part
	  glTexCoord2d(0,0.83);			glVertex3f(-13,-4, 8);//A
	  glTexCoord2d(0,1);			glVertex3f(-13,-5, 8.1);//D
	  glTexCoord2d(1,1);			glVertex3f(-1, -5, 8.1);//C
	  glTexCoord2d(1,0.83);			glVertex3f(-1, -4, 8);//B
	  glEnd();
	  glDisable(GL_TEXTURE_2D);
/////// نهاية كتابة التعليمات   
    glEndList();
	}
	void draw()// هاد التابع كمان اساسي ولازم نحطو بكل كلاس وهو يلي منستدعي فيه الليستة يلي عملناها فوق
  {		
	 glPushMatrix(); 
	 glScaled(1.5,1,3);
	 glTranslatef(-8,-3.5,2);
	 cube1.draw();
	 glPopMatrix();

	 // الوجهين الجانبيان للسرير
	glPushMatrix();
	glTranslatef(-7,-6,8);
	q1.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-7,-6,4);
	q1.Draw();
	glPopMatrix();
	//////////////////////////////////////
	//الوجع السفلي للسرير
	glPushMatrix();
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	glTranslatef(-7,6,8);
	q4.Draw();
	glPopMatrix();
	//////////////////////////////////////
	//الوجه العلوي للسرير
	/*glPushMatrix();
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	glTranslatef(-7,6,4);
	q2.Draw();
	glPopMatrix();*/
	//رسمتو فوق بالليست وهون تحت الليست مستدعاة للرسم
	/////////////////////////////////////////
	//الوجهين الامامي و الخلفي للسرير
	glPushMatrix();
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glTranslatef(-6,-6,-13);
	q3.Draw();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glTranslatef(-6,-6,-1);
	q3.Draw();
	glPopMatrix();

	//المسند العلوي
	glPushMatrix();
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glTranslatef(-6,-2,-13);
	q3.Draw();
	glPopMatrix();

	//المسند السفلي
	glPushMatrix();
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glTranslatef(-6,-3.5,-0.99);
	q2.Draw();
	glPopMatrix();


    glCallList(list);
  }


};

