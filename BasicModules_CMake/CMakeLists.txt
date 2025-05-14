
set(DIRS
Input
Hello 
Run
)

# add all the directories
foreach(DIR ${DIRS})
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/${DIR} ${CMAKE_CURRENT_BINARY_DIR}/${DIR})
endforeach()
    
add_executable(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}.cpp)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/${DIRS})

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${DIRS})

target_compile_features(${CMAKE_PROJECT_NAME} PUBLIC cxx_std_23)
