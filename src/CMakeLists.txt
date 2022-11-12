# main executable
set(MAIN ${CMAKE_CURRENT_SOURCE_DIR}/main)
add_executable(brickout
    ${MAIN}/brickout.cpp
)

# set library locations
set(TYPES ${MAIN}/types)
set(BACKEND ${MAIN}/backend)
set(SHAPES ${MAIN}/shapes)

# add library source files
add_library(types INTERFACE
    ${TYPES}/aliases/math.h
    ${TYPES}/aliases/opengl.h

    ${TYPES}/structs/Vertex.h
    ${TYPES}/structs/ModelViewProjection.h
)

add_library(backend
    ${BACKEND}/Window.cpp
    ${BACKEND}/Object.cpp
    ${BACKEND}/Shader.cpp
    ${BACKEND}/Texture.cpp
    ${BACKEND}/Error.cpp
)

add_library(shapes
    ${SHAPES}/Shape.cpp
    ${SHAPES}/Circle.cpp
    ${SHAPES}/Rectangle.cpp
)

# replace include directive
target_include_directories(types PRIVATE INTERFACE ${MAIN})
target_include_directories(backend PRIVATE ${MAIN})
target_include_directories(shapes PRIVATE ${MAIN})

# shared library
find_package(OpenGL REQUIRED)

# linking needed library
target_link_libraries(types PRIVATE INTERFACE OpenGL::GL ${CONAN_LIBS})
target_link_libraries(shapes PRIVATE
    backend
)
target_link_libraries(brickout PRIVATE
    types
    backend
    shapes
)

# copy resource file
file(
    COPY            ${CMAKE_CURRENT_SOURCE_DIR}/res 
    DESTINATION     ${PROJECT_SOURCE_DIR}/dist
)