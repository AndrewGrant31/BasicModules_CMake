# get the current directory by name only
cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME LIBRARYNAME)

# set the current directory as the name of the library
set(LIBRARY_NAME ${LIBRARYNAME})

# add the files in the library (directory) into the library/project
set(FILES 
    Run.cxx 
)
# add the current library into the project
add_library(${LIBRARY_NAME} ${FILES})

# include all the libraries this library relies on
set(LIBRARIES 
    Hello 
    Input
)

# these libraries are not in the direct path for this library
if(LIBRARIES)
    cmake_path(GET CMAKE_CURRENT_BINARY_DIR PARENT_PATH BUILD_DIR)
    foreach(LIBRARY ${LIBRARIES})
        set(LIBRARY_BINARY ${BUILD_DIR}/${LIBRARY} )
        target_link_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_BINARY})
    endforeach(LIBRARY ${LIBRARIES})    
endif()

# create the library target
target_sources(${LIBRARY_NAME} 
    PUBLIC 
    FILE_SET CXX_MODULES FILES 
    ${FILES}
)
# link the required libraries only if the LIBRARIES is set (that is, not empty)
if(LIBRARIES)    
    target_link_libraries(${LIBRARY_NAME} PUBLIC ${LIBRARIES})
endif()

target_compile_features(${LIBRARY_NAME} PUBLIC cxx_std_23)