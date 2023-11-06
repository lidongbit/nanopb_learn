project(test_monitor)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D PB_FIELD_16BIT")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -D PB_FIELD_16BIT")
set(CMAKE_BUILD_TYPE "debug")

set(EXECUTABLE_OUTPUT_PATH ${test_monitor_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${test_monitor_SOURCE_DIR}/bin)

include_directories(
    ./
    ./pb/include
)
add_subdirectory(pb)
add_library(var_monitor SHARED
    ./var_monitor.cpp
)


add_executable(test_monitor 
	./test_monitor.cpp
)

link_directories(
	/usr/lib/
    ./bin/
)

target_link_libraries(test_monitor
    var_monitor
)

add_executable(test_nanopb
	./test_nanopb.cpp  ./var_monitor_data.pb.c
)
target_link_libraries(test_nanopb
    pb
)