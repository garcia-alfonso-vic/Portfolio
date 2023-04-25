cmake_minimum_required(VERSION 3.10)

project(Queue-Class)

#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
#   Grab all cpp files from includes folder
#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
set(INCLUDES_FOLDER includes)
FILE(GLOB_RECURSE SOURCE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}   "${INCLUDES_FOLDER}/*.cpp" )
#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

ADD_EXECUTABLE(main
    main.cpp
    ${SOURCE_FILES}
)
ADD_EXECUTABLE(basic_test
    _tests/basic_test.cpp
    ${SOURCE_FILES}
)
