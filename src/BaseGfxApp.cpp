#include "BaseGfxApp.h"


BaseGfxApp* BaseGfxApp::s_currentApp = NULL;
bool BaseGfxApp::s_glutInitialized = false;

#define INIT_WIDTH 800
#define INIT_HEIGHT 600

BaseGfxApp::BaseGfxApp(int argc, char* argv[], int width, int height, int x, int y, int glutFlags, bool createGLUIWin, int gluiWinX, int gluiWinY)
{
	s_currentApp = this;
	m_glui = NULL;
	m_drag = false;
	m_width = width;
	m_height = height;
	
	// Set window size and position
	glutInitWindowSize(width, height);
	glutInitWindowPosition(x, y);
	glutInitDisplayMode(glutFlags);
	
	if (! s_glutInitialized)
	{
		glutInit(&argc, argv);
		s_glutInitialized = true;
	}
	
	m_glutWindowHandle = glutCreateWindow("Graphics Window");
	
	glutReshapeFunc(s_reshape);
	glutKeyboardFunc(s_keyboard);
	glutKeyboardUpFunc(s_keyboardup);
	glutSpecialFunc(s_keyboardspecial);
	glutSpecialUpFunc(s_keyboardspecialup);
	glutMotionFunc(s_mousemotion);
	glutPassiveMotionFunc(s_mousemotion);
	glutMouseFunc(s_mousebtn);
	glutDisplayFunc(s_draw);
	glutIdleFunc(s_idle);
	
	if (createGLUIWin)
	{
		m_glui = GLUI_Master.create_glui("Controls", 0, gluiWinX, gluiWinY);
		m_glui->set_main_gfx_window(m_glutWindowHandle);
		// Note: if using a glut idle func, it may need to be registered with glui rather than glut.
		GLUI_Master.set_glutIdleFunc(NULL);
	}
}

BaseGfxApp::~BaseGfxApp()
{
	s_currentApp = NULL;
	glutDestroyWindow(m_glutWindowHandle);
}

void BaseGfxApp::setCaption(const std::string& caption)
{
	glutSetWindowTitle(caption.c_str());
	glutSetIconTitle(caption.c_str());
}

void BaseGfxApp::runMainLoop()
{
	glutMainLoop();
}



void BaseGfxApp::reshape(int width, int height)
{
	if (s_currentApp->width() != width || s_currentApp->height() != height)
	{
		glutReshapeWindow( s_currentApp->width(), s_currentApp->height() );
	}
}

void BaseGfxApp::renderOneFrame() {
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	display();
	glutSwapBuffers();
}



void BaseGfxApp::initGraphics() {
	// Initialize OpenGL for Brush
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(0, m_width, 0, m_height);
	glViewport(0, 0, m_width, m_height);
}

void BaseGfxApp::drawPixels(int start_x, int start_y, int width, int height, void const * const pixels) {
	glRasterPos2i(start_x, start_y);
	glDrawPixels(width, height, GL_RGBA, GL_FLOAT, pixels);
	
	int err;
	if ((err = glGetError()) != GL_NO_ERROR)
	{
		std::cerr << "GL is in an error state after call to glDrawPixels()" << std::endl;
		std::cerr << "(GL error code " << err << ")\n";
		assert(0);
	}
	
}



int BaseGfxApp::width() const
{
	return m_width;
}

int BaseGfxApp::height() const
{
	return m_height;
}



void BaseGfxApp::s_reshape(int width, int height)
{
	s_currentApp->reshape(width, height);
}

void BaseGfxApp::s_keyboard(unsigned char c, int x, int y)
{
	s_currentApp->keyboard(c, x, y);
	glutPostRedisplay();
}

void BaseGfxApp::s_keyboardspecial(int key, int x, int y)
{
	s_currentApp->keyboardSpecial(key, x, y);
	glutPostRedisplay();
}

void BaseGfxApp::s_keyboardup(unsigned char c, int x, int y)
{
	s_currentApp->keyboardUp(c, x, y);
	glutPostRedisplay();
}

void BaseGfxApp::s_keyboardspecialup(int key, int x, int y)
{
	s_currentApp->keyboardSpecialUp(key, x, y);
	glutPostRedisplay();
	
}

void BaseGfxApp::s_mousemotion(int x, int y)
{
	if (s_currentApp->m_drag == true)
	{
		s_currentApp->mouseDragged(x,y);
	}
	else
	{
		s_currentApp->mouseMoved(x,y);
	}
	glutPostRedisplay();
	
}

void BaseGfxApp::s_mousebtn(int b, int s, int x, int y)
{
	if ((b==GLUT_LEFT_BUTTON) && (s==GLUT_UP))
	{
		s_currentApp->leftMouseUp(x,y);
		s_currentApp->m_drag = false;
		
	}
	else if ((b==GLUT_LEFT_BUTTON) && (s==GLUT_DOWN))
	{
		s_currentApp->leftMouseDown(x,y);
		s_currentApp->m_drag = true;
	}
	else if ((b==GLUT_RIGHT_BUTTON) && (s==GLUT_UP))
	{
		s_currentApp->rightMouseUp(x,y);
	}
	else if ((b==GLUT_RIGHT_BUTTON) && (s==GLUT_DOWN))
	{
		s_currentApp->rightMouseDown(x,y);
	}
	else if ((b==GLUT_MIDDLE_BUTTON) && (s==GLUT_UP))
	{
		s_currentApp->middleMouseUp(x,y);
	}
	else if ((b==GLUT_MIDDLE_BUTTON) && (s==GLUT_DOWN))
	{
		s_currentApp->middleMouseDown(x,y);
	}
	glutPostRedisplay();
	
}

void BaseGfxApp::s_draw()
{
	s_currentApp->renderOneFrame();
}

void BaseGfxApp::s_gluicallback(int controlID)
{
	s_currentApp->gluiControl(controlID);
}

void BaseGfxApp::s_idle()
{
	int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	int delta = timeSinceStart - s_currentApp->m_milliseconds;
	if (delta > 0) {
		s_currentApp->m_milliseconds = timeSinceStart;
		s_currentApp->update(delta);
		
	}
}

// Added for Iteration #2
void BaseGfxApp::setWindowDimensions(int width, int height) {
    m_height = height;
    m_width = width;
    
    glutReshapeWindow(m_width, m_height);
}

