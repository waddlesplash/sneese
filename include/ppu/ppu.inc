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

%ifndef SNEeSe_ppu_ppu_inc
%define SNEeSe_ppu_ppu_inc

EXTERN COLDATA

%ifndef SNEeSe_ppu_ppu_asm

EXTERN PPU_text_start,PPU_data_start,PPU_bss_start
EXTERN Read_Map_20_5F,Write_Map_20_5F
EXTERN Read_Map_21,Write_Map_21
EXTERN Read_Map_40,Write_Map_40
EXTERN Read_Map_42,Write_Map_42
EXTERN Read_Map_43,Write_Map_43
EXTERN WRAM,VRAM,SRAM,PortRAM

EXTERN Tile_Recache_Set_Begin,Tile_Recache_Set_End
EXTERN Mosaic_Size_Select,Mosaic_Size,MOSAIC
EXTERN INIDISP,BGMODE,Base_BGMODE
EXTERN BG12NBA,BG34NBA
EXTERN VMAIN

EXTERN Current_Line_Timing, Current_Line_IRQ
EXTERN SETINI
EXTERN STAT78
EXTERN Redo_Offset_Change,Redo_Offset_Change_VOffsets

EXTERN BGMODE_Allowed_Layer_Mask,BGMODE_Tile_Layer_Mask
EXTERN BGMODE_Allowed_Offset_Change

%macro EXTERN_BG_WIN_DATA 2
EXTERN TableWin%2BG%1
EXTERN WinBG%1_%2_Count
EXTERN WinBG%1_%2_Bands
%endmacro

%macro EXTERN_BG_DATA 1
EXTERN TableBG%1
EXTERN WSELBG%1
EXTERN WLOGBG%1
EXTERN BGSC%1      ; SC size
EXTERN DepthBG%1

EXTERN VScroll_%1
EXTERN HScroll_%1
EXTERN VLMapAddressBG%1
EXTERN VRMapAddressBG%1

EXTERN LineRenderBG%1
EXTERN SetAddressBG%1   ; Address of BG tileset
EXTERN VMapAddressBG%1

EXTERN MapAddressBG%1       ; Screen address of BG
EXTERN TLMapAddressBG%1
EXTERN TRMapAddressBG%1
EXTERN BLMapAddressBG%1
EXTERN BRMapAddressBG%1

EXTERN TileHeightBG%1
EXTERN TileWidthBG%1
EXTERN MosaicBG%1
EXTERN NBABG%1      ; Unused in BG3/4
EXTERN NBATableBG%1 ; Unused in BG3/4
EXTERN LineCounter_BG%1
EXTERN M0_Color_BG%1
EXTERN BG_Flag_BG%1
EXTERN OC_Flag_BG%1 ; Unused in BG3/4
EXTERN Priority_Used_BG%1
EXTERN Priority_Unused_BG%1

EXTERN_BG_WIN_DATA %1,Main
EXTERN_BG_WIN_DATA %1,Sub
EXTERN_BG_WIN_DATA %1,Low
EXTERN_BG_WIN_DATA %1,High
EXTERN_BG_WIN_DATA %1,Both
%endmacro

EXTERN_BG_DATA 1
EXTERN_BG_DATA 2
EXTERN_BG_DATA 3
EXTERN_BG_DATA 4

EXTERN BG1SC,BG2SC,BG3SC,BG4SC
EXTERN BG1HOFS,BG2HOFS,BG3HOFS,BG4HOFS
EXTERN BG1VOFS,BG2VOFS,BG3VOFS,BG4VOFS

EXTERN Reset_Ports
EXTERN Toggle_Offset_Change
EXTERN Update_Layering

EXTERN Last_Bus_Value_PPU1
EXTERN Last_Bus_Value_PPU2


EXTERN SNES_R2134,SNES_R2135,SNES_R2136
EXTERN SNES_W211A,SNES_W211B,SNES_W211C,SNES_W211D
EXTERN SNES_W211E,SNES_W211F,SNES_W2120

EXTERN SCREEN_MODE_7

EXTERN Reset_Mode_7

EXTERN M7H_13,M7V_13
EXTERN Redo_M7
EXTERN M7SEL
EXTERN EXTBG_Mask
EXTERN M7_Handler_Table,M7_Handler
%endif

%define Read_21_Address(reg) (Read_Map_21+(reg)*4)
%define Write_21_Address(reg) (Write_Map_21+(reg)*4)

;%1 = address, %2 = handler
%macro Set_21_Read 2
 mov dword [Read_21_Address(%1)],(%2)
%endmacro

%macro Set_21_Write 2
  mov dword [Write_21_Address(%1)],(%2)
%endmacro


; Offsets from _TableBG#
%define WSEL 0
%define WLOG 1
%define BGSC 2
%define Depth 3
%define TileHeight 4
%define TileWidth 5
%define Mosaic 6
%define NBA 7
%define VScroll 8
%define HScroll 0x0C
%define VLMapAddress 0x10
%define VRMapAddress 0x14
%define LineRender 0x18
%define SetAddress 0x1C
%define VMapAddress 0x20
%define MapAddress 0x24
%define TLMapAddress 0x24
%define TRMapAddress 0x28
%define BLMapAddress 0x2C
%define BRMapAddress 0x30
%define NBATable 0x34
%define LineCounter 0x38
%define M0_Color 0x3C
%define BG_Flag 0x40
%define OC_Flag 0x41

%define BG_Win_Main 0x42
%define BG_Win_Sub 0x49
%define BG_Win_Low 0x50
%define BG_Win_High 0x57
%define BG_Win_Both 0x5E

%define Priority_Used 0x65
%define Priority_Unused 0x66

; Offsets from _TableWin*
%define Win_Count 0
%define Win_Bands 1

; Offsets from TableWin#
%define Win_Out 0
%define Win_Count_Out (Win_Out + Win_Count)
%define Win_Bands_Out (Win_Out + Win_Bands)
%define Win_In 5
%define Win_Count_In (Win_In + Win_Count)
%define Win_Bands_In (Win_In + Win_Bands)


%macro LOAD_BG_TABLE 1-2 edx
 mov dword %2,TableBG%1
%endmacro

%macro LOAD_WIN_TABLE 1-2 edx
 mov dword %2,TableWin%1
%endmacro

%endif ; !defined(SNEeSe_ppu_ppu_inc)
