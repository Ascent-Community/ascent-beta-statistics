project(examples)

link_libraries(ascent)

file(GLOB SRCS ../statistics/*.cpp ../statistics/*.h *.cpp *.h)

add_executable(${PROJECT_NAME} ${SRCS})