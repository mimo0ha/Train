#pragma once
#include <glut.h>
//#include "Model.h"
double DoorMovment=0; 
double DoorSpeed =0.01 ;
double carriageWidth=26.0*2, carriageHight=16;
 
class Quad
{
public:
	GLuint list;
	void Init(int texture , double width , double hight )
	{
		list = glGenLists(1);
		glNewList(list, GL_COMPILE);
		glEnable(GL_TEXTURE_2D);
		
		glBindTexture(GL_TEXTURE_2D, texture);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(-width/2,-hight/2, 0);
		glTexCoord2d(1, 0);
		glVertex3d(width/2, -hight/2, 0);
		glTexCoord2d(1, 1);
		glVertex3d(width / 2, hight / 2, 0);
		glTexCoord2d(0, 1);
		glVertex3d(-width / 2, hight / 2, 0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glEndList();
	}
	void Draw()
	{
		glCallList(list);
	}
};
class BlindQuad 
{
public:
	GLuint list;
	void Init( double width , double hight)
	{
		list = glGenLists(1);
		glNewList(list, GL_COMPILE);
		glBegin(GL_QUADS);
		glColor4f(1.0f, 1.0f, 1.0f,0.5);
		glVertex3d(-width/2,-hight/2, 0);
		glVertex3d(width/2, -hight/2, 0);
		glVertex3d(width / 2, hight / 2, 0);
		glVertex3d(-width / 2, hight / 2, 0);
		glEnd();
		glEndList();
	}
	void Draw()
	{
		glCallList(list);
	}
};
class Column
{
public:
	Quad q;
	GLuint list;
	void Init(int texture)
	{
		q.Init(texture , 1 , carriageHight* 0.375);
		list = glGenLists(1);
		glNewList(list, GL_COMPILE);
		
		glEndList();
	}
	void Draw()
	{
		q.Draw();
		glCallList(list);
	}
};
class Wall {
public : 
	GLuint list; 
	Column c; 
	Quad q1;
	Quad q2;
	void Init( int top ,int med ,int down )
	{
		c.Init(med);
		q1.Init(top, carriageWidth, carriageHight * 0.25);
		q2.Init(down, carriageWidth, carriageHight * 0.375);
		
		list = glGenLists(1);
		glNewList(list,GL_COMPILE);
	
		glEndList(); 
	}
	 
	void Draw()
	{ 
		// —”„ «·œ—«»“Ì‰  »⁄ «·‘»«ﬂ
		glPushMatrix();
		glTranslated(0, 1, 0);
		c.Draw();
		glTranslated(carriageWidth/2 - 0.5, 0, 0);
		c.Draw(); 
		glTranslated(-carriageWidth+1, 0, 0);
		c.Draw();
		glPopMatrix(); 
		 // «·ÕÌÿ «·›Êﬁ«‰Ì
		glPushMatrix();
		glTranslated(0, carriageHight* 0.375, 0);
		q1.Draw();
		glPopMatrix();
		// «·ÕÌÿ «· Õ «‰Ì 
		glPushMatrix();
		glTranslated(0, -carriageHight * 0.3125, 0);
		q2.Draw();
		glPopMatrix();

		glCallList(list);
	}

};
class Ceil_Floor
{
public:
	GLuint list;
	Quad ceil;
	Quad floor;

	void Init(int top , int down)
	{
		ceil.Init(top, carriageWidth, carriageHight);
		floor.Init(down, carriageWidth, carriageHight);
		list = glGenLists(1);
		glNewList(list, GL_COMPILE);
		glEndList();
	}
	void Draw() {
		glPushMatrix();
		glRotated(90, 1, 0, 0);
		glTranslated(0,  0,-carriageHight/2);
		ceil.Draw();
		glPopMatrix();

		glPushMatrix();
		glRotated(90, 1, 0, 0);
		glTranslated(0, 0, carriageHight/2);
		floor.Draw();
		glPopMatrix();
	}
};
class WallWithDoor {
public : 
	GLuint list; 
	Quad up;
	Quad left; 
	Quad leftDown;
	Quad right;
	Quad rightDown;

	Quad door;
	Quad downDoor;

	void Init (int top ,int med , int down){
		up.Init(top ,16 ,4 );

		left.Init(med,5.5 ,6 );
		leftDown.Init(down, 5.5, 6);

		right.Init(med,5.5 ,6 );
		rightDown.Init(down, 5.5, 6);

		door.Init(med, 5, 6);
		downDoor.Init(down, 5, 6);

		list = glGenLists(1);
		glNewList(list, GL_COMPILE);
		glEndList();
	}
	void Draw(bool isOpen){
		OpenTheDoor(isOpen);

		glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslated(0, 6, 0);
		up.Draw();
		glPopMatrix();

		glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslated(5.25, 1, 0);
		right.Draw();
		glPopMatrix();

		glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslated(5.25, -5, 0);
		rightDown.Draw();
		glPopMatrix();


		glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslated(-5.25, 1, 0);
		left.Draw();
		glPopMatrix();

		glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslated(-5.25, -5, 0);
		leftDown.Draw();
		glPopMatrix();
		
		glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslated(DoorMovment, 1, 0.2);
		door.Draw();
		glPopMatrix();

		glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslated(DoorMovment, -5, 0.2);
		downDoor.Draw();
		glPopMatrix();
	}
	void OpenTheDoor(bool isOpen) {
		if (isOpen )
		{	if(DoorMovment < 5)
			DoorMovment+=DoorSpeed;
		}
		else 
		{
			if(DoorMovment > 0)
			DoorMovment-= DoorSpeed;
		}
	}
};
class Train_Carriage {


public:	
//	Model table;
	GLuint list;
	Wall w; 
	Wall downW;
	Ceil_Floor cf;
	WallWithDoor wallWithDoor;
	WallWithDoor wallWithDoor2;
	void Init(int ceil_floor ,int top , int med , int down ) {

		w.Init(top,med,down);	
		
		cf.Init(ceil_floor,ceil_floor);
		wallWithDoor.Init(top,med,down);
		wallWithDoor2.Init(top,med,down);

		//table.Load("C:\\Users\\hp\\Desktop\\legacyOpenGlProjects\\Project1\\Debug\\TableAndChairs.obj");

		list = glGenLists(1);
		glNewList(list, GL_COMPILE);
//		table.Draw();
		glEndList();

	}

	void Draw(bool isOpen) {

		//////////////—”„ «·ÕÌÿ«‰ Ì·Ì ›ÌÂ‰ ‘»«»Ìﬂ 
		glPushMatrix();
		glTranslated(0, 0, -carriageHight/2);
		w.Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslated(0, 0, carriageHight/2);
		w.Draw();
		glPopMatrix();
		////////////////////////////////////////////

		/// <—”„ «·”ﬁ› Ê«·√—÷Ì…>
		glPushMatrix();
		cf.Draw();
		glPopMatrix();
		/// </—”„ «·”ﬁ› Ê«·√—÷Ì…>
		
		/// <—”„ «·ÕÌÿ«‰  Ì·Ì ›ÌÂ‰ »«» >
		glPushMatrix();
		glTranslated(carriageWidth/2+0.01,0,0);
		wallWithDoor.Draw(isOpen);
		glPopMatrix();
		///
		glPushMatrix();
		glTranslated(-carriageWidth/2-0.01, 0, 0);
		wallWithDoor2.Draw(isOpen);
		glPopMatrix();
		/// </—”„ «·ÕÌÿ«‰  Ì·Ì ›ÌÂ‰ »«»>
	
		glCallList(list);
		
	}
};
class Quad22
{
public:
	GLuint list;
	void Init(int texture, double width, double hight , int x)
	{
		list = glGenLists(1);
		glNewList(list, GL_COMPILE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(-width / 2, -hight / 2, 0);
		glTexCoord2d(x, 0);
		glVertex3d(width / 2, -hight / 2, 0);
		glTexCoord2d(x, x);
		glVertex3d(width / 2, hight / 2, 0);
		glTexCoord2d(0, x);
		glVertex3d(-width / 2, hight / 2, 0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glEndList();
	}
	void Draw()
	{
		glCallList(list);
	}
};
class Cube {
public:
	GLuint list;//
	Quad q10, q20, q30, q40, q50, q60;
	void init(int front, int back, int up, int down, int right, int left)
	{
		q10.Init(front, 1, 1);
		q20.Init(back, 1, 1);
		q30.Init(down, 1, 1);
		q40.Init(up, 1, 1);
		q50.Init(right, 1, 1);
		q60.Init(left, 1, 1);
		list = glGenLists(1);
		glNewList(list, GL_COMPILE);/////// »œ«Ì… ﬂ «»… «· ⁄·Ì„« 
		glEndList();
	}
	void draw()// Â«œ «· «»⁄ ﬂ„«‰ «”«”Ì Ê·«“„ ‰ÕÿÊ »ﬂ· ﬂ·«” ÊÂÊ Ì·Ì „‰” œ⁄Ì ›ÌÂ «··Ì” … Ì·Ì ⁄„·‰«Â« ›Êﬁ
	{
		//«„«„Ì
		glPushMatrix();
		glTranslated(0, 0, 0.5);
		q10.Draw();
		glPopMatrix();

		//Œ·›Ì
		glPushMatrix();
		glTranslated(0, 0, -0.5);
		q20.Draw();
		glPopMatrix();

		//Ì„Ì‰Ì
		glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslated(0, 0, 0.5);
		q50.Draw();
		glPopMatrix();

		//Ì”«—Ì
		glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslated(0, 0, -0.5);
		q60.Draw();
		glPopMatrix();

		// Õ 
		glPushMatrix();
		glRotated(90, 1, 0, 0);
		glTranslated(0, 0, 0.5);
		q30.Draw();
		glPopMatrix();

		//›Êﬁ 
		glPushMatrix();
		glRotated(90, 1, 0, 0);
		glTranslated(0, 0, -0.5);
		q40.Draw();
		glPopMatrix();
		glCallList(list);
	}
};
class Bridge{
	
public:
	Quad22 q1;
	Quad22 q2;
	Quad22 q3; 
	Quad22 q4;
	
	GLuint list;//

	void init(int trainTexture ,int x )
	{
		q1.Init(trainTexture,5,12,x);
		q2.Init(trainTexture,5,12,x);
		q3.Init(trainTexture,5,5,x);
		q4.Init(trainTexture,5,5,x);
		


		list = glGenLists(1);

	

/////// ‰Â«Ì… ﬂ «»… «· ⁄·Ì„«    
    glEndList();
	}
	void draw()// Â«œ «· «»⁄ ﬂ„«‰ «”«”Ì Ê·«“„ ‰ÕÿÊ »ﬂ· ﬂ·«” ÊÂÊ Ì·Ì „‰” œ⁄Ì ›ÌÂ «··Ì” … Ì·Ì ⁄„·‰«Â« ›Êﬁ
  {
	  //«„«„Ì
    glPushMatrix();
    glTranslated(0,0,2.5);
    q1.Draw();
    glPopMatrix();

	  //Œ·›Ì
    glPushMatrix();
    glTranslated(0,0,-2.5);
    q2.Draw();
    glPopMatrix();

	 //base
    glPushMatrix();
	glRotated(90,1,0,0);
    glTranslated(0,0,6);
    q3.Draw();
    glPopMatrix();

	// top
    glPushMatrix();
	glRotated(90,1,0,0);
    glTranslated(0,0,-6);
    q4.Draw();
    glPopMatrix();

    glCallList(list);
  }


};
class Rail{
	
public:
	Quad q1;
	Quad q2;
	
	GLuint list;//

	void init(int trainTexture)
	{
		q1.Init(trainTexture,52,2);
		q2.Init(trainTexture,1,2);
	
		list = glGenLists(1);

	

/////// ‰Â«Ì… ﬂ «»… «· ⁄·Ì„«    
    glEndList();
	}
	void draw()// Â«œ «· «»⁄ ﬂ„«‰ «”«”Ì Ê·«“„ ‰ÕÿÊ »ﬂ· ﬂ·«” ÊÂÊ Ì·Ì „‰” œ⁄Ì ›ÌÂ «··Ì” … Ì·Ì ⁄„·‰«Â« ›Êﬁ
  {
	//«„«„Ì
    glPushMatrix();
    glTranslated(0,0,0.5);
    q1.Draw();
    glPopMatrix();

	//Œ·›Ì
    glPushMatrix();
    glTranslated(0,0,-0.5);
    q1.Draw();
    glPopMatrix();

	 //Ì„Ì‰
    glPushMatrix();
	glRotated(90,0,1,0);
    glTranslated(0,0,26);
    q2.Draw();
    glPopMatrix();

	 //Ì”«—
    glPushMatrix();
	glRotated(90,0,1,0);
    glTranslated(0,0,-26);
    q2.Draw();
    glPopMatrix();

    glCallList(list);
  }


};