# add_executable(Executable Command.cpp)
add_executable(Homework Assignment.cpp)

# target_link_libraries(Executable PUBLIC Singleton)
target_link_libraries(Homework PUBLIC ${LIBRARY_NAME})