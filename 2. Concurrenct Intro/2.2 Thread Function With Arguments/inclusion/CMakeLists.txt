set(LIBRARY_MODULES "Functions.ixx")

add_library(Functions)
target_sources(Functions PUBLIC FILE_SET CXX_MODULES FILES ${LIBRARY_MODULES})
target_include_directories(Functions PUBLIC "./")