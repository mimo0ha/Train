/*
 *		This Code Was Created By Jeff Molofee 2000
 *		A HUGE Thanks To Fredric Echols For Cleaning Up
 *		And Optimizing This Code, Making It More Flexible!
 *		If You've Found This Code Useful, Please Let Me Know.
 *		Visit My Site At nehe.gamedev.net
 */

/*


*/
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>	// Header File For The Glaux Library
#include <texture.h>

#include "camera.h"
#include "Chair.h" 
#include "Train_Carriage.h"
#include "CINEMA.h"
#include "Driver.h"
#include "skybox.h"
#include "Goods.h"
#include "Passengers.h"
#include "SleepCarriage.h"
#include "Model.h"
#include "Restaurant.h"

//#include "3DTexture.h"
//#include "Model_3DS.h"

HDC			hDC = NULL;		// Private GDI Device Context
HGLRC		hRC = NULL;		// Permanent Rendering Context
HWND		hWnd = NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active = TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen = TRUE;	// Fullscreen Flag Set To Fullscreen Mode By Default

Camera cam;
 float bx,by,br;
 float ex,ey,er;
Camera MyCamera;

bool isOpen;
bool isOpen2;
float move = +0 ;
Cinema cnema;
Driver driv;
goods good ;
passenger pass;
SleepCarriage bedroom;
Restaurant rest;
Bridge br1 ;
Skybox01 s2;
Quad seke;


/////
//Model_3DS *tree;
//GLTexture BARK,leaf,leaf2;
////

GLfloat LightPos[] = {0,5,4,1};
GLfloat LightAmb[] = {1,1,1,1};
GLfloat LightDiff[] = {1,1,1,1};
GLfloat LightSpec[] = {1,1,1,1};

GLfloat MatAmb[] = {1,0,0,1};
GLfloat MatDiff[] = {0.2,0.6,0.9,1};
GLfloat MatSpec[] = {0,0,0,1};
GLfloat MatShn[] = {128};
LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height == 0)										// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 4000.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

class CAMERAA{
public:
void cameraa(){
	glPushMatrix();
	if (keys['W'])
		cam.MoveForward(1);
	if (keys['S'])
		cam.MoveForward(-1);
	if (keys['A'])
		cam.RotateY(1);
	if (keys['D'])
		cam.RotateY(-1);
	if (keys['E']){
		cam.MoveUpward(1);};
	if (keys['Q'] )
		cam.MoveUpward(-1);
	if (keys[VK_UP])
		cam.RotateX(-1);
	if (keys[VK_DOWN])
		cam.RotateX(1);
	if (keys[VK_LEFT])
		cam.RotateZ(1);
	if (keys[VK_RIGHT])
		cam.RotateZ(-1);
	glPopMatrix();
}
void keybord()
{
	glPushMatrix();
	if (keys['Q'])    		MyCamera.MoveUpward(0.8);
	if (keys['E'])			MyCamera.MoveUpward(-0.8);
	if (keys['A'])			MyCamera.RotateY(0.8);
	if (keys['D'])		    MyCamera.RotateY(-0.8);
	if (keys['S'])		    MyCamera.RotateX(-0.8);
	if (keys['W'])		    MyCamera.RotateX(0.8);
	if (keys[VK_DOWN])        MyCamera.MoveForward(-0.8);
	if (keys[VK_UP])      MyCamera.MoveForward(0.8);
	if (keys[VK_LEFT])	    MyCamera.MoveRight(-0.8);
	if (keys[VK_RIGHT])		MyCamera.MoveRight(0.8);
	glPopMatrix();
 }
};
float a , b , c ;
int fe , se , mbc , fabric ,cur , s , win , control , blue, wood , gray , mount , fe10 , woodgood , FeFloor , Orange ,ColumnPassenger;
int bedCube,railImg,TrainWall,bedImg ,SubWay ,sekeh , top , down , med , chess ,MountBack , MountRight , GROUND , SKY ;
int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);              // Enable Smooth Shading
  glClearColor(0.0f, 0.0f, 0.0f, 0.5f);        // Black Background
  glClearDepth(1.0f);                  // Depth Buffer Setup
  glEnable(GL_DEPTH_TEST);              // Enables Depth Testing
  glDepthFunc(GL_LEQUAL);                // The Type Of Depth Testing To Do
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Really Nice Perspective Calculations
  glEnable(GL_TEXTURE_2D);
  /*
 glLightfv(GL_LIGHT1,GL_POSITION,LightPos);
 glLightfv(GL_LIGHT1,GL_AMBIENT,LightAmb);
 glLightfv(GL_LIGHT1,GL_DIFFUSE,LightDiff);
 glLightfv(GL_LIGHT1,GL_SPECULAR,LightSpec);
 glEnable(GL_LIGHT1);
 glEnable(GL_LIGHTING);
 glMaterialfv(GL_FRONT,GL_AMBIENT,MatAmb);
 glMaterialfv(GL_FRONT,GL_DIFFUSE,MatDiff);
 glMaterialfv(GL_FRONT,GL_SPECULAR,MatSpec);
 glMaterialfv(GL_FRONT,GL_SHININESS,MatShn);
 glEnable(GL_COLOR_MATERIAL);
  */
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_TEXTURE_WRAP_T);// Really Nice Perspective Calculations
  glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  
    MyCamera = Camera();
    MyCamera.Position.x = -540;
    MyCamera.Position.y = -730.0;
    MyCamera.Position.z = 0.0;
    MyCamera.RotateY(0.0);

	fe = LoadTexture("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\images\\TrainWall.bmp",255);
	se = LoadTexture("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\images\\sejad.bmp",255);
	mbc = LoadTexture("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\images\\MBC.bmp",255);
	fabric = LoadTexture("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\images\\chair.bmp",255);
	cur = LoadTexture("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\images\\CURTAIN.bmp",255);
	s = LoadTexture("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\images\\sky.bmp",255);
	win = LoadTexture("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\images\\window.bmp",255);
	control = LoadTexture("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\images\\ControllBoard.bmp",255);
	blue = LoadTexture("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\images\\BlueControl.bmp",255);
	wood = LoadTexture("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\images\\WoodHouse.bmp",255);
	gray = LoadTexture("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\images\\gray.bmp",255);
	mount = LoadTexture("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\images\\mout.bmp",255);
	fe10 = LoadTexture("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\images\\fe10.bmp",255);
	woodgood = LoadTexture("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\images\\WoodGood.bmp",255);
	FeFloor = LoadTexture("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\images\\FeFloor.bmp",255);
	Orange  = LoadTexture("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\images\\Orange.bmp",255);
	ColumnPassenger =  LoadTexture("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\images\\ColumnPassenger.bmp",255);
	bedImg = LoadTexture("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\images\\bed004.bmp",255);
	bedCube = LoadTexture("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\images\\bedCube1.bmp",255);
	SubWay = LoadTexture("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\images\\SubWay.bmp",255);
	sekeh = LoadTexture("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\images\\sekeh.bmp",255);
	top = LoadTexture("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\images\\top.bmp",255);
	down = LoadTexture("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\images\\down.bmp",255);
	med = LoadTexture("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\images\\med.bmp",255); 
	MountBack = LoadTexture("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\images\\MountBack.bmp",255);
	MountRight = LoadTexture("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\images\\MountRight.bmp",255);
	GROUND = LoadTexture("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\images\\GROUND.bmp",255); 
	SKY = LoadTexture("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\images\\sky.bmp",255); 
	
	cnema.Init(med,se , mbc ,fabric,cur ,gray);
	s2.init(MountBack,MountRight,MountRight,MountBack,SKY,GROUND,1500,1500);
	driv.Init(med,blue,control,wood,gray);
	good.Init(fe10 ,fe,fe10,wood,woodgood,gray);
	pass.Init(med,top,FeFloor,Orange,gray,ColumnPassenger,gray,top,med,down);
	bedroom.init(med,wood,bedImg,top,gray,bedCube);
	rest.Init(med,top,med,down,top,gray);
	br1.init(SubWay,1);
	seke.Init(sekeh,8,12);

	/*
  leaf.LoadBMP("C:\\Users\\USER\\Documents\\Visual Studio 2012\\Projects\\graf0\\leaf.bmp");
  leaf2.LoadBMP("C:\\Users\\USER\\Documents\\Visual Studio 2012\\Projects\\graf0\\leaf2.bmp");
  BARK.LoadBMP("C:\\Users\\USER\\Documents\\Visual Studio 2012\\Projects\\graf0\\trunk.bmp");
  tree=new Model_3DS();
  tree->Load("C:\\Users\\USER\\Documents\\Visual Studio 2012\\Projects\\graf0\\graf0tree.3ds");
  */
	return TRUE;										// Initialization Went OK
}
bool ismove = false;
void MoveTrain(bool ismove) {
		if (ismove )
		{	if(move >= -750)
			move-=2;
		}
}
void DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();// Reset The Current Modelview Matrix
	
	CAMERAA cameraobj;
    MyCamera.Render();
    cameraobj.cameraa();
    cameraobj.keybord();

	/*
//3d tree
	tree->pos.x=-200;
	tree->pos.y=-745;
	tree->pos.z=+30;
	tree->scale=1;
	tree->Draw();
	tree->Materials[0].tex=BARK;
	tree->Materials[1].tex=leaf;
	tree->Materials[2].tex=leaf2;
	//tree->Materials[3].tex=leaf2;
//	tree->Materials[4].tex=leaf2;
	*/
  glEnable(GL_FOG);
  GLfloat color[]={0.3,0.3,0.3,0.1};
  glFogfv(GL_FOG_COLOR,color);
  glFogi(GL_FOG_MODE,GL_LINEAR);
  glFogf(GL_FOG_START,-1500);
  glFogf(GL_FOG_END,1500); 
  

	if (keys['N']) {
    isOpen = !isOpen;
  }
	if (keys['C']) {
    isOpen2 = !isOpen2;
  }
    if (keys['M']) {
		ismove = !ismove;
  }
	if(keys[VK_SPACE]){
		PlaySound("C:\\Users\\ASUS\\Desktop\\projects\\C++_OpenGL\\graf0\\sound.wav" , NULL  , SND_ASYNC);
	}
	//PlaySound("birds.wav" , NULL  , SND_ASYNC);
	
	////////////////������
	MoveTrain(ismove);
	
	glPushMatrix();

	glTranslated(move,0,0);


	glPushMatrix();
    s2.draw(1500,1500);
    glPopMatrix();

	glPushMatrix();
	glTranslated(0,-735,0);
	glScaled(38,3,8);
    br1.draw();
    glPopMatrix();
	
	for(int i = -100 ; i <=100 ; i++){
	glPushMatrix();
	glTranslated(i*12,-750,0);
	glRotated(90,1,0,0);
	glRotated(90,0,0,1);
	seke.Draw();
	glPopMatrix();
	}
	glPopMatrix();
	glPushMatrix();	
	///////////////////////////////////////////������
	glPushMatrix();
	glTranslated(-540,-740,0);
	glPushMatrix();
	glTranslated(-171,0,0);
	good.Draw(isOpen);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-114,0,0);
	bedroom.draw(isOpen);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-57,0,0);
	bedroom.draw(isOpen);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,0);
	cnema.Draw(isOpen,isOpen2);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(57,0,0);
	pass.Draw(isOpen);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(114,0,0);
	pass.Draw(isOpen);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(171,0,0);
	pass.Draw(isOpen);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(228,0,0);
	rest.Draw(isOpen);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(285,0,0);
	rest.Draw(isOpen);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(329,0,0);
	driv.Draw(isOpen);
	glPopMatrix();
	
	glPopMatrix();
	
	glPopMatrix();
	/*
	*/
 
	

	glDisable(GL_FOG);
	glFlush();											// Done Drawing The Quad	
	//DO NOT REMOVE THIS
	SwapBuffers(hDC);
}

GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL, 0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL, NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL, "Release Of DC And RC Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL, "Release Rendering Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd, hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL, "Release Device Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hDC = NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL, "Could Not Release hWnd.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL", hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL, "Could Not Unregister Class.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;									// Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
 *	title			- Title To Appear At The Top Of The Window				*
 *	width			- Width Of The GL Window Or Fullscreen Mode				*
 *	height			- Height Of The GL Window Or Fullscreen Mode			*
 *	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
 *	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/

BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left = (long)0;			// Set Left Value To 0
	WindowRect.right = (long)width;		// Set Right Value To Requested Width
	WindowRect.top = (long)0;				// Set Top Value To 0
	WindowRect.bottom = (long)height;		// Set Bottom Value To Requested Height

	fullscreen = fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance = GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc = (WNDPROC)WndProc;					// WndProc Handles Messages
	wc.cbClsExtra = 0;									// No Extra Window Data
	wc.cbWndExtra = 0;									// No Extra Window Data
	wc.hInstance = hInstance;							// Set The Instance
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground = NULL;									// No Background Required For GL
	wc.lpszMenuName = NULL;									// We Don't Want A Menu
	wc.lpszClassName = "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL, "Failed To Register The Window Class.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth = width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight = height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel = bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL, "The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?", "NeHe GL", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
			{
				fullscreen = FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL, "Program Will Now Close.", "ERROR", MB_OK | MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle = WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle = WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd = CreateWindowEx(dwExStyle,							// Extended Style For The Window
		"OpenGL",							// Class Name
		title,								// Window Title
		dwStyle |							// Defined Window Style
		WS_CLIPSIBLINGS |					// Required Window Style
		WS_CLIPCHILDREN,					// Required Window Style
		0, 0,								// Window Position
		WindowRect.right - WindowRect.left,	// Calculate Window Width
		WindowRect.bottom - WindowRect.top,	// Calculate Window Height
		NULL,								// No Parent Window
		NULL,								// No Menu
		hInstance,							// Instance
		NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Window Creation Error.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};

	if (!(hDC = GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Device Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!SetPixelFormat(hDC, PixelFormat, &pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Set The PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC = wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!wglMakeCurrent(hDC, hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd, SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(HWND	hWnd,			// Handle For This Window
	UINT	uMsg,			// Message For This Window
	WPARAM	wParam,			// Additional Message Information
	LPARAM	lParam)			// Additional Message Information
{
	static PAINTSTRUCT ps;

	switch (uMsg)									// Check For Windows Messages
	{
	case WM_PAINT:
		DrawGLScene();
		BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		return 0;

	case WM_TIMER:
		DrawGLScene();
		return 0;

	case WM_ACTIVATE:							// Watch For Window Activate Message
	{
		if (!HIWORD(wParam))					// Check Minimization State
		{
			active = TRUE;						// Program Is Active
		}
		else
		{
			active = FALSE;						// Program Is No Longer Active
		}

		return 0;								// Return To The Message Loop
	}

	case WM_SYSCOMMAND:							// Intercept System Commands
	{
		switch (wParam)							// Check System Calls
		{
		case SC_SCREENSAVE:					// Screensaver Trying To Start?
		case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
			return 0;							// Prevent From Happening
		}
		break;									// Exit
	}

	case WM_CLOSE:								// Did We Receive A Close Message?
	{
		PostQuitMessage(0);						// Send A Quit Message
		return 0;								// Jump Back
	}

	case WM_KEYDOWN:							// Is A Key Being Held Down?
	{
		keys[wParam] = TRUE;					// If So, Mark It As TRUE
		return 0;								// Jump Back
	}

	case WM_KEYUP:								// Has A Key Been Released?
	{
		keys[wParam] = FALSE;					// If So, Mark It As FALSE
		return 0;								// Jump Back
	}

	case WM_SIZE:								// Resize The OpenGL Window
	{
		ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));  // LoWord=Width, HiWord=Height
		return 0;								// Jump Back
	}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE	hInstance,			// Instance
	HINSTANCE	hPrevInstance,		// Previous Instance
	LPSTR		lpCmdLine,			// Command Line Parameters
	int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done = FALSE;								// Bool Variable To Exit Loop

	// Ask The User Which Screen Mode They Prefer
	//if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen = FALSE;							// Windowed Mode
	}

	// Create Our OpenGL Window
	char c[] = "";
	if (!CreateGLWindow(c, 640, 480, 16, fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}


	//Set drawing timer to 20 frame per second
	UINT timer = SetTimer(hWnd, 0, 50, (TIMERPROC)NULL);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}