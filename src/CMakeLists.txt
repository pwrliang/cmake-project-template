cmake_minimum_required(VERSION 3.2)
project(divider)

add_subdirectory(division)
set(SOURCE_FILES main.cpp flags.cc)

add_executable(divider ${SOURCE_FILES})
target_link_libraries(divider division ${MPI_CXX_LIBRARIES}
        ${GLOG_LIBRARIES} ${GFLAGS_LIBRARIES} ${CMAKE_DL_LIBS})
install(TARGETS divider DESTINATION ${DIVISIBLE_INSTALL_BIN_DIR})
