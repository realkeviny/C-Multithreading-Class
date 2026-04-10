set(LIBRARY_MODULE "Singleton.ixx")

add_library(Singleton)
target_sources(Singleton PUBLIC FILE_SET CXX_MODULES FILES ${LIBRARY_MODULE})

