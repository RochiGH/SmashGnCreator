#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Table_Row.H>
#include <FL/Fl_Button.H>
#include <stdio.h>
#include <string>
#include <cstring>

using namespace std;

#include "../include/GnNode.h"
#include "../include/fltkDrawOgl.h"
#include "../include/FltkSmashDisplay.h"

extern vector<GnNode> gnPoints;
extern vector<GnNode> gnRtk; 

//
// Simple demonstration class to derive from Fl_Table_Row
//
class DemoTable : public Fl_Table_Row
{
protected:
    void draw_cell(TableContext context,  		// table cell drawing
    		   int R=0, int C=0, int X=0, int Y=0, int W=0, int H=0);
//    void callback(TableContext context, 		// callback for table events
//    		   int R, int C);

public:
    string tableName;
    DemoTable(int x, int y, int w, int h, const char *l, string lin) : Fl_Table_Row(x,y,w,h)
	{ 
        tableName = lin;
        end(); 
    }
    ~DemoTable() { }
};

/**
 * DemoTable::draw_cell
 * draw_cell 
 *
 * @param context
 * @param R
 * @param C
 * @param X
 * @param Y
 * @param W
 * @param H
 */

void DemoTable::draw_cell(TableContext context, 
			  int R, int C, int X, int Y, int W, int H)
{
    static char s[40];
    strcpy(s, this->tableName.c_str());
	if( !strcmp(s, "RTK log values")) {
        if( R == 0 && C == 0 && context == CONTEXT_COL_HEADER)
            sprintf(s, "Node ID");
        if( R == 0 && C == 1 && context == CONTEXT_COL_HEADER)
            sprintf(s, "Longitude");
        if( R == 0 && C == 2 && context == CONTEXT_COL_HEADER)
            sprintf(s, "Latitude");
        if( R < gnRtk.size() && C == 1 && context == CONTEXT_CELL)
            sprintf(s, "%f", gnRtk.at(R).lon);
        if( R < gnRtk.size() && C == 2 && context == CONTEXT_CELL)
            sprintf(s, "%f", gnRtk.at(R).lat);
    } else {
        if( R == 0 && C == 0 && context == CONTEXT_COL_HEADER)
            sprintf(s, "Node ID");
        if( R == 0 && C == 1 && context == CONTEXT_COL_HEADER)
            sprintf(s, "Longitude");
        if( R == 0 && C == 2 && context == CONTEXT_COL_HEADER)
            sprintf(s, "Latitude");
        if( R < gnPoints.size() && C == 1 && context == CONTEXT_CELL)
            sprintf(s, "%f", gnPoints.at(R).lon);
        if( R < gnPoints.size() && C == 2 && context == CONTEXT_CELL)
            sprintf(s, "%f", gnPoints.at(R).lat);
    }

    switch ( context )
    {
	case CONTEXT_STARTPAGE:
	    fl_font(FL_HELVETICA, 16);
	    return;

	case CONTEXT_ROW_HEADER:
	case CONTEXT_COL_HEADER:
	    fl_push_clip(X, Y, W, H);
	    {
		fl_draw_box(FL_THIN_UP_BOX, X, Y, W, H, color());
		fl_color(FL_BLACK);
		fl_draw(s, X, Y, W, H, FL_ALIGN_CENTER);
	    }
	    fl_pop_clip();
	    return;

	case CONTEXT_CELL:
	{
	    fl_push_clip(X, Y, W, H);
	    {
	        // BG COLOR
		fl_color( row_selected(R) ? selection_color() : FL_WHITE);
		fl_rectf(X, Y, W, H);

		// TEXT
		fl_color(FL_BLACK);
		fl_draw(s, X, Y, W, H, FL_ALIGN_CENTER);

		// BORDER
		fl_color(FL_LIGHT2); 
		fl_rect(X, Y, W, H);
	    }
	    fl_pop_clip();
	    return;
	}

	default:
	    return;
    }
}

/**
 * table_cb
 * table_cb callback 
 *
 * @param o
 * @param data
 */

void table_cb(Fl_Widget* o, void* data)
{
    Fl_Table *table = (Fl_Table*)data;
    fprintf(stderr, "%s callback: row=%d col=%d, context=%d, event=%d clicks=%d\n",
	(const char*)table->label(),
	(int)table->callback_row(),
	(int)table->callback_col(),
	(int)table->callback_context(),
	(int)Fl::event(),
	(int)Fl::event_clicks());
}

/**
 * mygl_cb
 * mygl callback 
 *
 * @param o
 * @param data
 */

void mygl_cb(Fl_Widget* o, void* data)
{
    return;
/* 
    Fl_Table *table = (Fl_Table*)data;
    fprintf(stderr, "%s callback: row=%d col=%d, context=%d, event=%d clicks=%d\n",
	(const char*)table->label(),
	(int)table->callback_row(),
	(int)table->callback_col(),
	(int)table->callback_context(),
	(int)Fl::event(),
	(int)Fl::event_clicks());
*/
}

/**
 * mygl_cb
 * mygl callback 
 *
 * @param o
 * @param data
 */

void button_cb( Fl_Widget* obj , void* )
{
    obj->label( "OFF" );
    obj->resize( 10,0,150,20 ); 
    obj->redraw();
}

void button_cbDebug( Fl_Widget* obj , void* )
{
    obj->label( "DEBUG" );
    obj->resize( 10,0,150,20 ); 
    obj->redraw();
}

/**
 * fltkSmashDisplay
 * Main display method , it manages the FL run and views running.
 *
 * @param 
 */

int fltkSmashDisplay()
{
    int w = 300, h = 700;
    int t1x = 20, t1y = 25,         t1w = w - 40, t1h = h - 50;
    int rtkTableSize = gnRtk.size();
    int gnTableSize = gnPoints.size();

    Fl_Window rtkWin(w, h);
    DemoTable rtkTable(t1x, t1y, t1w, t1h, "RTK log values", "RTK log values");
    rtkTable.selection_color(FL_YELLOW);
    rtkTable.when(FL_WHEN_RELEASE);	// handle table events on release
    rtkTable.rows(gnRtk.size());
    rtkTable.cols(3);
    rtkTable.col_header(1);		// enable col header
    rtkTable.col_resize(10);	// enable col resizing
    rtkTable.row_resize(4);		// enable row resizing
    rtkTable.callback(table_cb, (void*)&rtkTable);
    rtkTable.when(FL_WHEN_CHANGED|FL_WHEN_RELEASE);
    rtkTable.end();
    rtkWin.resizable(rtkTable);
    rtkWin.show();

    Fl_Window winGnPoints(w, h);
    DemoTable gnTable(t1x, t1y, t1w, t1h, "GN log values", "GN log values");
    gnTable.selection_color(FL_BLUE);
    gnTable.when(FL_WHEN_RELEASE);	// handle table events on release
    gnTable.rows(gnPoints.size());
    gnTable.cols(3);
    gnTable.col_header(1);		// enable col header
    gnTable.col_resize(10);		// enable col resizing
    gnTable.row_resize(4);		// enable row resizing
    gnTable.callback(table_cb, (void*)&gnTable);
    gnTable.when(FL_WHEN_CHANGED|FL_WHEN_RELEASE);
    gnTable.end();
    winGnPoints.resizable(gnTable);
    winGnPoints.show();

    Fl_Window win(1000, 500, "Smash Graph Node Debug");
    MyGlWindow mygl(10, 20, win.w()-20, win.h()-30);
    Fl_Button* butGnRtk = new Fl_Button( 10, 0, 150, 20, "UPDATE RTK LOG" );
    Fl_Button* butGnPoints = new Fl_Button( 150, 0, 150, 20, "UPDATE GN LOG" );
    Fl_Button* butDebug = new Fl_Button( 300, 0, 150, 20, "UPDATE GPS LOG" );

    win.end();
    win.resizable(mygl);

    butGnRtk->callback(( Fl_Callback* ) button_cb );
    butGnPoints->callback(( Fl_Callback* ) button_cb );
    butDebug->callback(( Fl_Callback* ) button_cbDebug );

    mygl.callback(mygl_cb, (void*)&mygl);
    mygl.when(FL_WHEN_NOT_CHANGED|FL_WHEN_RELEASE_ALWAYS);

    win.show();

    return(Fl::run());
}


