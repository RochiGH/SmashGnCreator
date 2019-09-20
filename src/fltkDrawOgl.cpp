#include "../include/fltkDrawOgl.h"
#include "../include/GnNode.h" 

extern vector<GnNode> gnRtk; 
extern vector<GnNode> gnPoints;
extern double agriBotSize;

class MyGlWindow : public Fl_Gl_Window {
    // DRAW METHOD
    //      OpenGL window: (w,h) is upper right, (-w,-h) is lower left, (0,0) is center
    //
    void draw() {
        // Viewport not valid? Init viewport, ortho, etc.
        if (!valid()) {
            glLoadIdentity();
            glViewport(0,0,w(),h());
            glOrtho(-w(),w(),-h(),h(),-1,1);
        }
         // Clear screen
        glClear(GL_COLOR_BUFFER_BIT);
        glPointSize(6.5);

        for (int i = 0; i < gnRtk.size(); i++) { 
            glColor3f(1, 0, 0);
            if(i % 2 == 0 && i < gnRtk.size() - 1) {
                glBegin(GL_LINES); glVertex2f(gnRtk.at(i).lon, gnRtk.at(i).lat); glVertex2f(gnRtk.at(i + 1).lon, gnRtk.at(i + 1).lat); glEnd();  
                if(i < gnRtk.size() - 2) {
                    glBegin(GL_LINES); glVertex2f(gnRtk.at(i).lon, gnRtk.at(i).lat); glVertex2f(gnRtk.at(i + 2).lon, gnRtk.at(i + 2).lat); glEnd(); 
                }
            } else if (i < gnRtk.size() - 1) {
                glBegin(GL_LINES); glVertex2f(gnRtk.at(i).lon, gnRtk.at(i).lat); glVertex2f(gnRtk.at(i + 2).lon, gnRtk.at(i + 2).lat); glEnd();     
            }
            glColor3f(0, 1, 0);
            glBegin(GL_POINTS); //starts drawing of points
            glVertex3f(gnRtk.at(i).lon,gnRtk.at(i).lat,0.0f);//upper-right corner
            glEnd();//end drawing of points  
        }

        for (int i = 0; i < gnPoints.size(); i++) { 
            glColor3f(0, 0, 1);
            if(!strcmp(gnPoints.at(i).UID, "LL") || !strcmp(gnPoints.at(i).UID, "LR"))
                glColor3f(0, 0.5, 0.5);
            if(!strcmp(gnPoints.at(i).UID, "HL") || !strcmp(gnPoints.at(i).UID, "HR"))
                glColor3f(0, 0.5, 0.5); 
            if(!strcmp(gnPoints.at(i).UID, "LML") || !strcmp(gnPoints.at(i).UID, "LMR"))
                glColor3f(0.5, 0.5, 0.5);
            if(!strcmp(gnPoints.at(i).UID, "HML") || !strcmp(gnPoints.at(i).UID, "HMR"))
                glColor3f(0.5, 0.5, 0.5); 

            glBegin(GL_POINTS); //starts drawing of points
            glVertex3f(gnPoints.at(i).lon,gnPoints.at(i).lat,0.0f);//upper-right corner
            glEnd();//end drawing of points  
            const char* test = gnPoints.at(i).UID;
            glColor3f(1, 0.5, 0.5);
            glRasterPos2f(gnPoints.at(i).lon,gnPoints.at(i).lat);
            int len, j;
            len = (int)strlen(test);
            for (j = 0; j < len - 1; j++) {
                // glutBitmapCharacter(NULL, test);
            }
        }
    }
public:
    // CONSTRUCTOR
    MyGlWindow(int X,int Y,int W,int H,const char*L=0) : Fl_Gl_Window(X,Y,W,H,L) {
    }
};

/* int fltkDrawOgl() */
int fltkDrawOgl() {
    Fl_Window win(1000, 500, "Smash Graph Node Debug");
    MyGlWindow mygl(10, 10, win.w()-20, win.h()-20);
    win.end();
    win.resizable(mygl);
    win.show();
    return(Fl::run());
}

    