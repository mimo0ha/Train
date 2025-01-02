#pragma once
#include <glut.h>
#include "Train_Carriage.h"
class Driver 
{
public :
    GLuint list;
	Ceil_Floor cf;
	Quad wall,wall2;
	Quad q1,q3,q5;
	BlindQuad q2,q4,q6;
	Cube cu ,c1 , c2 , c3 , c4 , c5 , c6 , c7;
	WallWithDoor wallWithDoor2;
	Rail rail1;
	void Init(int texture ,int blue , int textureControl ,int textureWood , int gray)
	{
		wall.Init(texture,44,16);
		wall2.Init(texture,44,16);
		q1.Init(texture,8,4);
		q2.Init(8,12);
		q3.Init(texture,16,4);
		q4.Init(8,12);
		q5.Init(texture,8,4);
		q6.Init(16,12);
		cf.Init(texture,texture);
		cu.init(blue ,blue ,textureControl,blue,blue,blue);
		c1.init(gray,gray,gray,gray,gray,gray);
		c2.init(gray,gray,gray,gray,gray,gray);
		c3.init(gray,gray,gray,gray,gray,gray);
		c4.init(gray,gray,gray,gray,gray,gray);
		c5.init(gray,gray,gray,gray,gray,gray);
		c6.init(gray,gray,gray,gray,gray,gray);
		c7.init(textureWood,textureWood,textureWood,textureWood,textureWood,textureWood);
		wallWithDoor2.Init(texture,texture,texture);
		rail1.init(gray);
		list = glGenLists(1);
		glNewList(list, GL_COMPILE);
		glEndList();
	}
	void Draw(bool isOpen) {
          //rail_1
		  glPushMatrix();
		  glScaled(0.5,1,1);
		  glTranslatef(0,-9.2,2.5);
		  rail1.draw();
		  glPopMatrix();
		  //rail_2
		  glPushMatrix();
		  glScaled(0.5,1,1);
		  glTranslatef(0,-9.2,-2.5);
		  rail1.draw();
		  glPopMatrix();

		glPushMatrix();
		glScaled(0.5,1,1);
		
		glPushMatrix();
		glScaled(4,4,4);
		glTranslated(1,5.6,1);
	    ////////////////////////////////////////////////ﬂ—”Ì «·”«∆ﬁ
	    glPushMatrix();
		glScaled(0.3,0.8,0.1);
		glTranslated(1.5,-9,1.5);
	    c1.draw();
	    glPopMatrix();
		
		glPushMatrix();
		glScaled(0.3,0.8,0.1);
		glTranslated(1.5,-9,-1.5);
	    c2.draw();
	    glPopMatrix();

		glPushMatrix();
		glScaled(0.3,0.8,0.1);
		glTranslated(-1.5,-9,1.5);
	    c3.draw();
	    glPopMatrix();


		glPushMatrix();
		glScaled(0.3,0.8,0.1);
		glTranslated(-1.5,-9,-1.5);
	    c4.draw();
	    glPopMatrix();

		glPushMatrix();
		glScaled(1.2,0.2,0.4);
		glTranslated(0,-34,0);
	    c5.draw();
	    glPopMatrix();

		glPushMatrix();
		glScaled(0.3,0.70,0.4);
		glTranslated(-1.5,-9.3,0);
		c6.draw();
		glPopMatrix();
		glPopMatrix();
		///////////////////////////////’‰œÊﬁ »·« ÿ⁄„…
		glPushMatrix();
		glScaled(12.9,3,3);
		glTranslated(-1.5,-2.1,-2);
		c7.draw();
		glPopMatrix();
		/// <—”„ «·”ﬁ› Ê«·√—÷Ì…>
		glPushMatrix();
		cf.Draw();
		glPopMatrix();
		/// <—”„ «·ÕÌÿ«‰  Ì·Ì ›ÌÂ‰ »«» >
		glPushMatrix();
		glTranslated(-carriageWidth/2, 0, 0);
		wallWithDoor2.Draw(isOpen);
		glPopMatrix();
		//«·ÕÌÿ «·Ì”«—Ì
		glPushMatrix();
		glTranslated(-4, 0, -8);
		wall.Draw();
		glPopMatrix();
		//«·ÕÌÿ «·Ì„Ì‰Ì
		glPushMatrix();
		glTranslated(-4, 0, 8);
		wall2.Draw();
		glPopMatrix();
		///////////////„” ÿÌ· ’€Ì—////////////
		glPushMatrix();
		glTranslated(22, -6, -8);
		q1.Draw();
		glPopMatrix();
		/////////////////////////////////////////
		glPushMatrix();
		glRotated(90,0,1,0);
		glTranslated(0,-6,26);
		q3.Draw();
		glPopMatrix();
		///////////////„” ÿÌ· ’€Ì—////////////
		glPushMatrix();
		glTranslated(22, -6, 8);
		q5.Draw();
		glPopMatrix();
		/////////////„” ÿÌ· ﬂ»Ì— ‘›«›/////////
		glPushMatrix();
		glTranslated(22, 2, -8);
		glEnable(GL_BLEND);
		glColor4f(1.0f, 1.0f, 1.0f,0.5);
		q2.Draw();
		glDisable(GL_BLEND);
		glPopMatrix();
		/////////////„” ÿÌ· ﬂ»Ì— ‘›«›/////////
		glPushMatrix();
		glTranslated(22, 2, +8);
		glEnable(GL_BLEND);
		glColor4f(1.0f, 1.0f, 1.0f,0.5);
		q4.Draw();
		glDisable(GL_BLEND);
		glPopMatrix();
		/////////////„” ÿÌ· ﬂ»Ì— ‘›«›/////////
		glPushMatrix();
		glRotated(90,0,1,0);
		glTranslated(0, 2, 26);
		glEnable(GL_BLEND);
		glColor4f(1.0f, 1.0f, 1.0f,0.5);
		q6.Draw();
		glDisable(GL_BLEND);
		glPopMatrix();
		//////////////////////·ÊÕ… «· Õﬂ„/////////////
		glPushMatrix();
		glScaled(8,4.2,14);
		glTranslated(2.5,-1.4,0);
		cu.draw();
		glPopMatrix();

		glPopMatrix();
		glCallList(list);
	  }
	};








