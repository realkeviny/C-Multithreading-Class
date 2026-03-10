set(EXECUTABLE_SOURCES "Assignment.cpp")

add_executable(${EXECUTABLE_NAME} ${EXECUTABLE_SOURCES})
target_link_libraries(${EXECUTABLE_NAME} PRIVATE Functions)