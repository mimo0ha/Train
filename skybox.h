#pragma once
#include <GLAUX.H>
#include "Train_Carriage.h"
class Skybox01{
public:
	Quad q1;
	Quad q2;
	Quad22 q3;
	Quad q4;
	Quad q5;
	Quad q6;
	GLuint list;
	void init(int front,int back,int right,int left,int top,int base ,int width1,int hight1)
	{
		q1.Init(front,width1,hight1);
		q2.Init(back,width1,hight1);
		q3.Init(base,width1,hight1,4);
		q4.Init(top,width1,hight1);
		q5.Init(right,hight1,hight1);
		q6.Init(left,hight1,hight1);
        list = glGenLists(1);
/////// نهاية كتابة التعليمات   
    glEndList();
	}
	void draw(int width1,int hight1)// هاد التابع كمان اساسي ولازم نحطو بكل كلاس وهو يلي منستدعي فيه الليستة يلي عملناها فوق
  {
	  //امامي
    glPushMatrix();
    glTranslated(0,0,hight1/2);
    q1.Draw();
    glPopMatrix();

	  //خلفي
    glPushMatrix();
    glTranslated(0,0,-hight1/2);
    q2.Draw();
    glPopMatrix();

	 //base
    glPushMatrix();
	glRotated(90,1,0,0);
    glTranslated(0,0,hight1/2);
    q3.Draw();
    glPopMatrix();

	// top
    glPushMatrix();
	glRotated(90,1,0,0);
    glTranslated(0,0,-hight1/2);
    q4.Draw();
    glPopMatrix();

	 //يمين
    glPushMatrix();
	glRotated(90,0,1,0);
    glTranslated(0,0,width1/2);
    q5.Draw();
    glPopMatrix();

	 //يسار
    glPushMatrix();
	glRotated(90,0,1,0);
    glTranslated(0,0,-width1/2);
    q6.Draw();
    glPopMatrix();

    glCallList(list);
  }
};


