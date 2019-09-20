// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/SmashGnCreatorConfig.h"
#ifdef USE_MYMATH
#include "../MathFunctions/MathFunctions.h"
#endif

#ifdef SMASH_FLTK
#include "../include/GnNode.h"
#include "../include/FltkSmashDisplay.h"
#endif
 
int main (int argc, char *argv[])
{

    if (true) // TODO check on arc < 2 to load the log file.
    {
    fprintf(stdout,"%s SmashGnCreator Version %d.%d\n", argv[0],
            Tutorial_VERSION_MAJOR,
            Tutorial_VERSION_MINOR);
    fprintf(stdout,"Usage: %s rtk.log file path\n",argv[0]);
    }

    GnNodeSmashRtkCreator();
    while(true)
    {
        int test = fltkSmashDisplay();
    }

     

   
 
  double inputValue = 4;
#ifdef USE_MYMATH
  double outputValue = mysqrt(inputValue);
#else
  double outputValue = sqrt(inputValue);
#endif
 
  fprintf(stdout,"The square root of %g is %g\n",
          inputValue, outputValue);
  return 0;
}
