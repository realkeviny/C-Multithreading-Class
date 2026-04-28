# set(LIBRARY_MODULE_FOR_COURSE "Singleton.ixx")
set(LIBRARY_MODULE_FOR_ASSIGNMENT "Traditional_Singleton.ixx" "New_Singleton.ixx")

# add_library(Singleton)
add_library(${LIBRARY_NAME})
# target_sources(Singleton PUBLIC FILE_SET CXX_MODULES FILES ${LIBRARY_MODULE_FOR_COURSE})
target_sources(${LIBRARY_NAME} PUBLIC FILE_SET CXX_MODULES FILES ${LIBRARY_MODULE_FOR_ASSIGNMENT})


