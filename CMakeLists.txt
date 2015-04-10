############
### Project Setup
############
cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(SNEeSe)
set(CMAKE_C_SIZEOF_DATA_PTR 4) # TODO: remove me once we can compile in 64bit mode
enable_language(ASM_NASM)

exec_program("allegro-config" ARGS "--libs" OUTPUT_VARIABLE ALLEGRO_LIBS
	RETURN_VALUE ALLEGRO_STATUS)
if(NOT ${ALLEGRO_STATUS} EQUAL 0)
	message(FATAL_ERROR "allegro-config was not found or failed to run.")
endif()

add_definitions(-DDEBUG) # TODO: fix so it can be compiled with -DRELEASE_BUILD
add_definitions(-DZLIB)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32 -Wall -Wno-unused-but-set-variable")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32 -Wall -Wno-unused-but-set-variable")
set(CMAKE_ASM_NASM_FLAGS "-w+orphan-labels -w+macro-params -O20 -i${CMAKE_CURRENT_SOURCE_DIR}/include/")

include_directories(include)
if(UNIX)
	add_definitions(-DUNIX)
endif()

file(GLOB_RECURSE HEADERS "include/*")
aux_source_directory(src SRCS)
aux_source_directory(src/allegro SRCS)
aux_source_directory(src/apu SRCS)
aux_source_directory(src/cpu SRCS)
aux_source_directory(src/jma SRCS)
aux_source_directory(src/ppu SRCS)
set(ASM_SRCS
	src/apu/apuskip.asm
	src/clear.asm
	src/font.asm
	src/cpu/65c816.asm
	src/cpu/dma.asm
	src/cpu/memmap.asm
	src/ppu/tiles.asm
	src/ppu/sprites.asm
	src/ppu/screen.asm
	src/ppu/ppu.asm
	)

add_executable(sneese ${HEADERS} ${SRCS} ${ASM_SRCS})
target_link_libraries(sneese z ${ALLEGRO_LIBS})
	# TODO: once we can compile in 64bit mode, use find_package for zlib
set_target_properties(sneese PROPERTIES LINK_FLAGS "-m32")
target_compile_features(sneese PRIVATE cxx_range_for)
