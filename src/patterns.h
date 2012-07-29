#ifndef PATTERNS_H
#define PATTERNS_H

void draw_pattern(SDL_Surface * destination, int pattern, int time);
Uint32 draw_pattern_pixel(int x, int y, int z, int patternid, SDL_PixelFormat * pfmt);

#endif
