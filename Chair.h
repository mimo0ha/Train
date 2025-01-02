#include <windows.h>     // Header File For Windows
#include <gl\gl.h>       // Header File For The OpenGL32 Library
#include <gl\glu.h>      // Header File For The GLu32 Library
#include <glaux.h>       // Header File For The Glaux Library
#include "Train_Carriage.h"

class CHAIR{
public :
  GLuint list;
  Quad22 q10;

  void Init(int fabric) {

	q10.Init(fabric,1,1,2);
	list = glGenLists(1);
    glNewList(list, GL_COMPILE);
    glEndList();
  } 
  void Draw() {
	  //«·„”‰œ
	  //«„«„Ì
	  glPushMatrix();
	  glTranslated(0,0,0.5);
	  q10.Draw();
	  glPopMatrix();
	  
	  //Œ·›Ì
	  glPushMatrix();
	  glTranslated(0,0,-0.5);
	  q10.Draw();
	  glPopMatrix();
	  
	  //Ì„Ì‰Ì
	  glPushMatrix();
	  glRotated(90,0,1,0);
	  glTranslated(0,0,0.5);
	  q10.Draw();
	  glPopMatrix();
	  
	  //Ì”«—Ì
	  glPushMatrix();
	  glRotated(90,0,1,0);
	  glTranslated(0,0,-0.5);
	  q10.Draw();
	  glPopMatrix();
	  
	  //›Êﬁ
	  glPushMatrix();
	  glRotated(90,1,0,0);
	  glTranslated(0,0,0.5);
	  q10.Draw();
	  glPopMatrix();
	  
	  // Õ «‰Ì 
	  glPushMatrix();
	  glRotated(90,1,0,0);
	  glTranslated(0,0,-0.5);
	  q10.Draw();
	  glPopMatrix();
	  
	  //«·ﬁ⁄œ…
	  //«„«„Ì
	  glPushMatrix();
	  glTranslated(0,0,0.5);
	  q10.Draw();
	  glPopMatrix();
	  
	  //Œ·›Ì
	  glPushMatrix();
	  glTranslated(0,0,-0.5);
	  q10.Draw();
	  glPopMatrix();
	  
	  //Ì„Ì‰Ì
	  glPushMatrix();
	  glRotated(90,0,1,0);
	  glTranslated(0,0,0.5);
	  q10.Draw();
	  glPopMatrix();
	  
	  //Ì”«—Ì
	  glPushMatrix();
	  glRotated(90,0,1,0);
	  glTranslated(0,0,-0.5);
	  q10.Draw();
	  glPopMatrix();
	  
	  //›Êﬁ
	  glPushMatrix();
	  glRotated(90,1,0,0);
	  glTranslated(0,0,0.5);
	  q10.Draw();
	  glPopMatrix();
	  
	  // Õ «‰Ì 
	  glPushMatrix();
	  glRotated(90,1,0,0);
	  glTranslated(0,0,-0.5);
	  q10.Draw();
	  glPopMatrix();
	  
	  glCallList(list);
	  
  }
};

















