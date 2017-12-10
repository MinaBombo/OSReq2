CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
PROJECT(OSReq2)
set (CMAKE_C_STANDARD 11)
SET(IncludedFiles include/generic_queue.h include/round_robin.h include/process_struct.h
    include/process_queue.h include/io_utils.h )

SET (MainSourceFiles src/main.c src/generic_queue.c src/round_robin.c
     src/process_queue.c src/io_utils.c )

add_executable(main ${IncludedFiles} ${MainSourceFiles})
include_directories(${CMAKE_ROOT_DIRECTORY} include)

