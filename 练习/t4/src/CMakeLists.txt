ADD_EXECUTABLE(main main.c)
INCLUDE_DIRECTORIES(~/b/cmake/t3/lib)
TARGET_LINK_LIBRARIES(main ~/b/cmake/t3/build/lib/libhello.so)
