
#include "../include/fltkDevTools.h"



int fltkDrawBoxInfo(int argc, char **argv) {
  Fl_Window *window = new Fl_Window(340,180);
  Fl_Box *box = new Fl_Box(20,40,300,100,"Sei in Moto ???");
  box->box(FL_UP_BOX);
  box->labelfont(FL_BOLD+FL_ITALIC);
  box->labelsize(36);
  box->labeltype(FL_SHADOW_LABEL);
  window->end();
  window->show(argc, argv);
  return Fl::run();
}


// COMPILE: fltk-config --use-images --compile load-jpeg.cxx
int fltkDrawJpg() {
    fl_register_images();                       // initialize image lib
    Fl_Window     win(720,486);                 // make a window
    Fl_Box        box(10,10,720-20,486-20);     // widget that will contain image
    // Fl_JPEG_Image jpg("/var/tmp/foo.jpg");      // load jpeg image into ram
    Fl_JPEG_Image jpg("./test.jpg");      // load jpeg image into ram
    box.image(jpg);                             // attach jpg image to box
    win.show();
    return(Fl::run());
} 
//
// Demonstrate creating a table of widgets without Fl_Table
//                                                   --erco Mar 8 2005


