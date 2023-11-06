#cmake_minimum_required(VERSION 2.8.3)
project(pb)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D PB_FIELD_16BIT")

include_directories(
	include
)

aux_source_directory(src SRC)

add_library(pb SHARED
	${SRC}
)

target_link_libraries(pb
    /usr/local/lib
)


