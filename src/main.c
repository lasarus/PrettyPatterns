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
  int id, ticks;
  
  if(init())
    return 1;

  ticks = 0;
  id = 0;
  
  while(!quit)
    {
      if(SDL_PollEvent(&event))
	{
	  if(event.type == SDL_QUIT)
	    quit = 1;
	  else if(event.type == SDL_KEYDOWN)
	    {
	      SDLKey key = event.key.keysym.sym;

	      if(key == SDLK_RIGHT)
		id++;
	      else if(key == SDLK_LEFT)
		id--;
	      else if(key == SDLK_UP)
		ticks = 0;
	    }
	}
      /*Update/drawing Loop*/

      draw_pattern(screen, id, ticks);
      
      ticks++;
      
      /*End of update/drawing Loop*/
      
      if(SDL_Flip(screen))
	return 1;
    }
  
  return 0;
}
