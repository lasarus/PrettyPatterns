#include <SDL/SDL.h>
#include <math.h>
#include "patterns.h"

#define SINGLE_COLOR(x) x, x, x

void draw_pattern(SDL_Surface * destination, int pattern, int time)
{
  int x, y;
  Uint32 * pixels;

  pixels = (Uint32 *)destination->pixels;

  for(y = 0; y < destination->h; y++)
    for(x = 0; x < destination->w; x++)
      {
	*pixels = draw_pattern_pixel(x, y, time, pattern, destination->format);
	pixels++;
      }
}

/*x and y is the pixel coordinates,
  z is time,
  patternid decides what pattern to display.
  pfmt is the pixel format*/
Uint32 draw_pattern_pixel(int x, int y, int z, int patternid, SDL_PixelFormat * pfmt)
{
  switch(patternid)
    {
      /*No break needed since the switch is terminated by return;*/
    case 0:
      return SDL_MapRGB(pfmt, x * y + z, x * y + z, x * y + z);

    case 1:
      return SDL_MapRGB(pfmt, SINGLE_COLOR(sin((x / 128.) * (y / 128.)) * 128. + z));

    default:
      return 0;
    }
  return 0;
}
