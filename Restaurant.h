#pragma once
#include"Train_Carriage.h"
#include"Model.h"
class Restaurant : public Train_Carriage
{
public:
	GLuint list;
	Model table;
	Quad q;
	Bridge bridgeC ;
	Rail rail1;
	BlindQuad window;

	void Init(int ceil_floor, int top, int med, int down , int chair , int gray)
	{
		Train_Carriage::Init(ceil_floor, top, med, down);
        q.Init(chair,10,10);
		bridgeC.init(med,1);
		rail1.init(gray);
		window.Init(24.5,6);
		table.Load("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\graf0\\Debug\\vippp.obj");
		list = glGenLists(1);
		glNewList(list, GL_COMPILE);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, chair);
		
		glPushMatrix();
		table.Draw();
		glPopMatrix();	
		
		glDisable(GL_TEXTURE_2D);
		glEndList();
	}
	void Draw(bool isOpen)
	{
		Train_Carriage::Draw(isOpen);
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
		
		for (float i = -1; i < 2; i++)
		{
			glPushMatrix();
			
			glTranslated(i*18-8, -8, 5);
			glCallList(list);
			glPopMatrix();
		}
		for (float i = -1; i < 2; i++)
		{
			glPushMatrix();

			glTranslated(i * 18 - 8, -8, -5);
			glCallList(list);
			glPopMatrix();
		}
		///////////////ÔÈÇÈíß
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

		///////////////ÔÈÇÈíß
		glColor4f(1.0,1.0,1.0,0.5);
	    glPushMatrix();
		glTranslated(-12.75, 1, -7.9);
        glEnable(GL_BLEND);
		window.Draw();
		glDisable(GL_BLEND);
		glPopMatrix();

		glPushMatrix();
		glTranslated(12.75, 1, -7.9);
		glEnable(GL_BLEND);
		window.Draw();
		glDisable(GL_BLEND);
		glPopMatrix();

		//glCallList(list);
	}
};