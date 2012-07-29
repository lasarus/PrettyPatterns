#include <SDL/SDL.h>
#include "patterns.h"

int screen_w = 640, screen_h = 480, screen_bpp = 32;
int quit = 0;

SDL_Surface * screen = NULL;
SDL_Event event;

int init()
{
  if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
    return 1;

  screen = SDL_SetVideoMode(screen_w, screen_h, screen_bpp, SDL_SWSURFACE);

  if(screen == NULL)
    return 1;

  return 0;
}

int main(int argc, char ** argv)
{
  if(init())
    return 1;

  int ticks = 0;
  while(!quit)
    {
      if(SDL_PollEvent(&event))
	{
	  if(event.type == SDL_QUIT)
	    quit = 1;
	}
      /*Update/drawing Loop*/

      draw_pattern(screen, 0, ticks);
      
      ticks++;
      
      /*End of update/drawing Loop*/
      
      if(SDL_Flip(screen))
	return 1;
    }
  
  return 0;
}
