#cmake_minimum_required(VERSION 2.8.3)
project(var_monitor)

include_directories(
    ./include
    ../pb/include
    ../thread_help/include/
    /usr/local/include/
)
aux_source_directory(src SRC)
add_library(var_monitor SHARED
	${SRC}
)
target_link_libraries(var_monitor
    pb
	thread_help
	nanomsg
)

link_directories(
    ../bin/
)