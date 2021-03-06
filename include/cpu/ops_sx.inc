%if 0

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

%endif

%if S_size == 8
%define OPCODE_PROLOG(op) OPCODE_LABEL OpE1_ %+ op
%else
%define OPCODE_PROLOG(op) OPCODE_LABEL OpE0X %+ X_8bit %+ _ %+ op
%endif


OPCODE_PROLOG(0x5A) ; PHY s
 _PHY
OPCODE_EPILOG

OPCODE_PROLOG(0x7A) ; PLY s
 _PLY
OPCODE_EPILOG

OPCODE_PROLOG(0x84) ; STY d
 _STY Direct
OPCODE_EPILOG

OPCODE_PROLOG(0x86) ; STX d
 _STX Direct
OPCODE_EPILOG

OPCODE_PROLOG(0x94) ; STY d,x
 _STY Direct_Index_X
OPCODE_EPILOG

OPCODE_PROLOG(0x96) ; STX d,y
 _STX Direct_Index_Y
OPCODE_EPILOG

OPCODE_PROLOG(0xA4) ; LDY d
 _LDY Direct
OPCODE_EPILOG

OPCODE_PROLOG(0xA6) ; LDX d
 _LDX Direct
OPCODE_EPILOG

OPCODE_PROLOG(0xB4) ; LDY d,x
 _LDY Direct_Index_X
OPCODE_EPILOG

OPCODE_PROLOG(0xB6) ; LDX d,y
 _LDX Direct_Index_Y
OPCODE_EPILOG

OPCODE_PROLOG(0xC4) ; CPY d
 _CPY Direct
OPCODE_EPILOG

OPCODE_PROLOG(0xDA) ; PHX s
 _PHX
OPCODE_EPILOG

OPCODE_PROLOG(0xE4) ; CPX d
 _CPX Direct
OPCODE_EPILOG

OPCODE_PROLOG(0xFA) ; PLX s
 _PLX
OPCODE_EPILOG

%undef OPCODE_PROLOG
