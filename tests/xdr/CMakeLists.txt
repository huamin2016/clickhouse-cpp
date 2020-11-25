#3rd files
#libconfig.h++  libconfig++.so

#.h dir
include_directories (3rd)

#.so dir
link_directories(3rd)

#bin
ADD_EXECUTABLE (test
        test.cpp)


#link
#all .so start with lib prefix and .so suffix, there config content what between lib and .so
TARGET_LINK_LIBRARIES (test
        clickhouse-cpp-lib config++
)