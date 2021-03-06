/*

SNEeSe, an Open Source Super NES emulator.


Copyright (c) 1998-2015, Charles Bilyue.
Portions copyright (c) 1998-2003, Brad Martin.
Portions copyright (c) 2003-2004, Daniel Horchner.
Portions copyright (c) 2004-2005, Nach. ( http://nsrt.edgeemu.com/ )
Unzip Technology, copyright (c) 1998 Gilles Vollant.
zlib Technology ( www.gzip.org/zlib/ ), Copyright (c) 1995-2003,
 Jean-loup Gailly ( jloup* *at* *gzip.org ) and Mark Adler
 ( madler* *at* *alumni.caltech.edu ).
JMA Technology, copyright (c) 2004-2005 NSRT Team. ( http://nsrt.edgeemu.com/ )
LZMA Technology, copyright (c) 2001-4 Igor Pavlov. ( http://www.7-zip.org )
Portions copyright (c) 2002 Andrea Mazzoleni. ( http://advancemame.sf.net )

This is free software.  See 'LICENSE' for details.
You must read and accept the license prior to use.

*/

#ifndef SNEeSe_types_h
#define SNEeSe_types_h

#include "platform.h"
#include "font.h"
#include "snes.h"

#define cBorder_Back 0
#define cBorder_Fore 7
#define cMenu_Back cWindow_Back
#define cMenu_Fore 0
#define cSelected_Back 0
#define cSelected_Fore 7
#define cText_Back cWindow_Back
#define cText_Fore 0
#define cWindow_Back 7

extern "C" unsigned char *GUI_Screen;

struct SCREEN {
 int depth,w_base,h_base,w,h;
 /* driver for full-screen display */
 int driver;
#ifndef ALLEGRO_DOS
 /* driver for windowed display */
 int driver_win;
#endif  /* !defined(ALLEGRO_DOS) */

 int set(bool windowed = false)
 {
  int error;
  int using_driver;

#ifndef ALLEGRO_DOS
   int depth = desktop_color_depth();
   if (depth == 0 || !windowed) depth = this->depth;

   using_driver = windowed ? driver_win : driver;
#else   /* defined(ALLEGRO_DOS) */
   using_driver = driver;
#endif  /* defined(ALLEGRO_DOS) */

  set_color_depth(depth);
  error = set_gfx_mode(using_driver, w_base, h_base, w_base, h_base);
  if(error) return error;

  return snes_output_init();
 }

};

typedef SCREEN * pSCREEN;

typedef struct
{
 char drive[MAXDRIVE],dir[MAXDIR],file[MAXFILE],ext[MAXEXT];

 void merge(char *path)
 {
  fnmerge(path, drive, dir, file, ext);
 }

 void split(char *path)
 {
  fnsplit(path, drive, dir, file, ext);
 }
} fname;

#endif /* !defined(SNEeSe_types_h) */
