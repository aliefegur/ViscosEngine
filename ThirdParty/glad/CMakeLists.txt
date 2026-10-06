project(glad)

add_library(${PROJECT_NAME} src/glad.c src/glad_wgl.c)
target_include_directories(${PROJECT_NAME} PUBLIC include/)
