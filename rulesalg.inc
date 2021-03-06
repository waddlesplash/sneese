#
#
# SNEeSe, an Open Source Super NES emulator.
#
#
# Copyright (c) 1998-2015, Charles Bilyue.
# Portions copyright (c) 1998-2003, Brad Martin.
# Portions copyright (c) 2003-2004, Daniel Horchner.
# Portions copyright (c) 2004-2005, Nach. ( http://nsrt.edgeemu.com/ )
# Unzip Technology, copyright (c) 1998 Gilles Vollant.
# zlib Technology ( www.gzip.org/zlib/ ), Copyright (c) 1995-2003,
#  Jean-loup Gailly ( jloup* *at* *gzip.org ) and Mark Adler
#  ( madler* *at* *alumni.caltech.edu ).
# JMA Technology, copyright (c) 2004-2005 NSRT Team. ( http://nsrt.edgeemu.com/ )
# LZMA Technology, copyright (c) 2001-4 Igor Pavlov. ( http://www.7-zip.org )
# Portions copyright (c) 2002 Andrea Mazzoleni. ( http://advancemame.sf.net )
#
# This is free software.  See 'LICENSE' for details.
# You must read and accept the license prior to use.
#
#


# Set up rules for platform-specific dependencies.
$(OBJ)/allegro/platform.$(OBJBASE): $(SRC)/allegro/platform.c \
 $(addprefix $(INCLUDE)/, platform.h misc.h helper.h input.h romload.h \
 apu/sound.h cpu/cpu.h apu/spc.h guicore.h allegro/wrapaleg.h version.h)

PLATFORM_OBJDIRS += allegro

