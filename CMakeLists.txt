project(test_monitor)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D PB_FIELD_32BIT")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -D PB_FIELD_32BIT")
set(CMAKE_BUILD_TYPE "debug")

set(EXECUTABLE_OUTPUT_PATH ${test_monitor_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${test_monitor_SOURCE_DIR}/bin)

include_directories(
    ./
    ./pb/include
    ./thread_help/include/
    /usr/local/include/
)
add_subdirectory(pb)
add_subdirectory(thread_help)

add_library(var_monitor SHARED
    ./var_monitor.cpp ./var_monitor_data.pb.c
)
target_link_libraries(var_monitor
    pb
)

link_directories(
    ./bin/
)


add_executable(test_nanopb
	./test_nanopb.cpp   ./var_monitor_data.pb.c
)
target_link_libraries(test_nanopb
    pb
)

add_executable(test_monitor_send 
	./test_monitor_send.cpp  ./var_monitor_data.pb.c
)
target_link_libraries(test_monitor_send
    var_monitor
    pb
    thread_help
    nanomsg
)

add_executable(test_monitor_recv 
	./test_monitor_recv.cpp  ./var_monitor_data.pb.c
)
target_link_libraries(test_monitor_recv
    var_monitor
    pb
    thread_help
    nanomsg
)