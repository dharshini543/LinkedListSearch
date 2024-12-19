cmake_minimum_required(VERSION 3.16)

project(SearchNode LANGUAGES C)

add_executable(SearchNode main.c)

include(GNUInstallDirs)
install(TARGETS SearchNode
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
