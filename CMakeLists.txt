cmake_minimum_required (VERSION 3.0.2)
project("OpenGL Shader Testbed")

find_package(OpenGL REQUIRED)

include_directories(
    # my headers
    "./include/"
    )
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "-std=c++17")

set(FLAGS "-ldl -ggdb -Wall -Wextra -pedantic -Wextra-tokens")


set(AbsPathPrefix "/media/kaan/Elements/GitProjects")

# glfw
add_library(glfwLib SHARED IMPORTED)
set_target_properties(
    glfwLib 
    PROPERTIES
    IMPORTED_LOCATION
    "${AbsPathPrefix}/glfw-3.3.4/bin/lib/libglfw.so")

include_directories("${AbsPathPrefix}/glfw-3.3.4/bin/include/")

# assimp
add_library(
    AssimpLib 
    SHARED
    IMPORTED
)
set_target_properties(
   AssimpLib 
   PROPERTIES IMPORTED_LOCATION 
   "${AbsPathPrefix}/assimp-5.0.1/build/code/libassimp.so.5"
   )

include_directories("${AbsPathPrefix}/assimp-5.0.1/build/include/")

# glm
include_directories("${AbsPathPrefix}/glm/")


set( ALL_LIBS
    ${FLAGS}
    ${OpenGL}
 )

add_executable(texture.out
    "src/glad.c"
    "src/texture.cpp"
    )
add_executable(phong.out
    "src/glad.c"
    "src/phong/phong.cpp"
    )
add_executable(phong2MovingLight.out
    "src/glad.c"
    "src/phong/phong2.cpp"
    )
add_executable(phongUbo.out
   "src/glad.c"
   "src/ubo/phong.cpp"
   )
add_executable(phongSSBO.out
   "src/glad.c"
   "src/ssbo/phong.cpp"
   )
add_executable(phongNoSpec.out
   "src/glad.c"
   "src/phong/phongNoSpec.cpp"
   )
add_executable(phongParallaxRelief.out
   "src/glad.c"
   "src/parallax/phong.cpp"
   )
add_executable(phongParallaxRelief2.out
   "src/glad.c"
   "src/parallax/phong2.cpp"
   )
add_executable(heightmap.out
   "src/glad.c"
   "src/heightmap/phong.cpp"
   )
add_executable(shadowmap.out
   "src/glad.c"
   "src/shadowmap/shadowmap.cpp"
   )
#add_executable(model.out
#   "src/glad.c"
#   "src/model/phong.cpp"
#   )
#add_executable(modelNormalMap.out
#   "src/glad.c"
#   "src/model/phongNormalMap.cpp"
#   )
#add_executable(modelPbr.out
#    "src/glad.c"
#    "src/model/pbr.cpp"
#    )
add_executable(pbr.out 
   "src/glad.c"
   "src/pbr/simplepbr.cpp"
   )
add_executable(pbr2.out 
   "src/glad.c"
   "src/pbr/simplepbr2.cpp"
   )
add_executable(simpleCompute.out 
    "src/glad.c"
    "src/raytrace/simplecompute.cpp"
    )
#add_executable(compute3d.out 
#    "src/glad.c"
#    "src/raytrace/compute3d.cpp"
#    )
add_executable(compute01.out 
    "src/glad.c"
    "src/raytrace/compute01.cpp"
    )
add_executable(compute02.out 
    "src/glad.c"
    "src/raytrace/compute02.cpp"
    )
add_executable(geometry.out 
   "src/glad.c"
   "src/geometry/geometry.cpp"
   )
#add_executable(argparse.out 
#   "src/glad.c"
#   "src/argparse/model.cpp"
#   )

add_executable(skybox.out 
   "src/glad.c"
   "src/skybox/sky.cpp"
   )
add_executable(fbo.out 
   "src/glad.c"
   "src/fbo/fbo.cpp"
   )
#add_executable(bloom.out 
#   "src/glad.c"
#   "src/bloom/bloom.cpp"
#   )
#
add_executable(ibl.out 
   "src/glad.c"
   "src/ibl/ibl.cpp"
   )
#add_executable(vct.out 
#   "src/glad.c"
#   "src/vct/vctutils.hpp"
#   "src/vct/vct.cpp"
#   )
#add_executable(lightprobs.out 
#   "src/glad.c"
#   "src/lightprobs/lightprobs2.cpp"
#   )

add_executable(defered.out 
   "src/glad.c"
   "src/defered/defered.cpp"
   )
add_executable(ssao.out 
   "src/glad.c"
   "src/ssao/ssao.cpp"
   )
#add_executable(screenspace.out 
#   "src/glad.c"
#   "src/screen/screen.cpp"
#   )

#add_executable(dirt.out 
#    "src/glad.c"
#    "src/dirt/dirt.cpp"
#    )



#target_link_libraries(myWin.out ${ALL_LIBS})
target_link_libraries(
    texture.out 
    ${ALL_LIBS}
    )

target_link_libraries(
    texture.out 
    glfwLib
    )
target_link_libraries(
    texture.out 
    AssimpLib
    )
# 
## using phong lightening model
target_link_libraries(phong.out glfwLib)
target_link_libraries(phong.out AssimpLib)
target_link_libraries(phong.out ${ALL_LIBS})
#
target_link_libraries(phongUbo.out glfwLib)
target_link_libraries(phongUbo.out AssimpLib)
target_link_libraries(phongUbo.out ${ALL_LIBS})
#
target_link_libraries(phongSSBO.out glfwLib)
target_link_libraries(phongSSBO.out AssimpLib)
target_link_libraries(phongSSBO.out ${ALL_LIBS})
#
target_link_libraries(phongNoSpec.out glfwLib)
target_link_libraries(phongNoSpec.out AssimpLib)
target_link_libraries(phongNoSpec.out ${ALL_LIBS})
#
target_link_libraries(phongParallaxRelief.out glfwLib)
target_link_libraries(phongParallaxRelief.out AssimpLib)
target_link_libraries(phongParallaxRelief.out ${ALL_LIBS})
#
target_link_libraries(phongParallaxRelief2.out glfwLib)
target_link_libraries(phongParallaxRelief2.out AssimpLib)
target_link_libraries(phongParallaxRelief2.out ${ALL_LIBS})
#
target_link_libraries(phong2MovingLight.out glfwLib)
target_link_libraries(phong2MovingLight.out AssimpLib)
target_link_libraries(phong2MovingLight.out ${ALL_LIBS})
#
target_link_libraries(heightmap.out glfwLib)
target_link_libraries(heightmap.out AssimpLib)
target_link_libraries(heightmap.out ${ALL_LIBS})
#
#target_link_libraries(model.out ${ALL_LIBS})
#target_link_libraries(modelNormalMap.out ${ALL_LIBS})
#
target_link_libraries(geometry.out glfwLib)
target_link_libraries(geometry.out AssimpLib)
target_link_libraries(geometry.out ${ALL_LIBS})
#
target_link_libraries(skybox.out glfwLib)
target_link_libraries(skybox.out AssimpLib)
target_link_libraries(skybox.out ${ALL_LIBS})
#
target_link_libraries(fbo.out glfwLib)
target_link_libraries(fbo.out AssimpLib)
target_link_libraries(fbo.out ${ALL_LIBS})
#
target_link_libraries(shadowmap.out glfwLib)
target_link_libraries(shadowmap.out AssimpLib)
target_link_libraries(shadowmap.out ${ALL_LIBS})
#
#target_link_libraries(bloom.out ${ALL_LIBS})
#target_link_libraries(argparse.out ${ALL_LIBS})
#target_link_libraries(lightprobs.out ${ALL_LIBS})
# 
## using pbr based models
#target_link_libraries(modelPbr.out ${ALL_LIBS})
#
target_link_libraries(pbr.out glfwLib)
target_link_libraries(pbr.out AssimpLib)
target_link_libraries(pbr.out ${ALL_LIBS})
#
target_link_libraries(pbr2.out glfwLib)
target_link_libraries(pbr2.out AssimpLib)
target_link_libraries(pbr2.out ${ALL_LIBS})
#
target_link_libraries(ibl.out glfwLib)
target_link_libraries(ibl.out AssimpLib)
target_link_libraries(ibl.out ${ALL_LIBS})
#
target_link_libraries(defered.out glfwLib)
target_link_libraries(defered.out AssimpLib)
target_link_libraries(defered.out ${ALL_LIBS})
#
target_link_libraries(ssao.out glfwLib)
target_link_libraries(ssao.out AssimpLib)
target_link_libraries(ssao.out ${ALL_LIBS})
#
#target_link_libraries(screenspace.out ${ALL_LIBS})
#target_link_libraries(dirt.out ${glfwLib})
#target_link_libraries(vct.out ${ALL_LIBS})
#
target_link_libraries(simpleCompute.out glfwLib)
target_link_libraries(simpleCompute.out AssimpLib)
target_link_libraries(simpleCompute.out ${ALL_LIBS})
#
#target_link_libraries(compute3d.out glfwLib)
#target_link_libraries(compute3d.out AssimpLib)
#target_link_libraries(compute3d.out ${ALL_LIBS})
#
target_link_libraries(compute01.out glfwLib)
target_link_libraries(compute01.out AssimpLib)
target_link_libraries(compute01.out ${ALL_LIBS})
#
target_link_libraries(compute02.out glfwLib)
target_link_libraries(compute02.out AssimpLib)
target_link_libraries(compute02.out ${ALL_LIBS})
# 
# 
#install(TARGETS myWin.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
install(TARGETS texture.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
# 
## 
install(TARGETS phong.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
install(TARGETS phongUbo.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
install(TARGETS phongSSBO.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
install(TARGETS phongParallaxRelief.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
install(TARGETS phongParallaxRelief2.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
install(TARGETS phong2MovingLight.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
install(TARGETS phongNoSpec.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
install(TARGETS heightmap.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
#install(TARGETS model.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
#install(TARGETS modelNormalMap.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
install(TARGETS geometry.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
install(TARGETS skybox.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
install(TARGETS fbo.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
install(TARGETS shadowmap.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
#install(TARGETS bloom.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
#install(TARGETS argparse.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
#install(TARGETS lightprobs.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
# 
#install(TARGETS modelPbr.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
install(TARGETS pbr.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
install(TARGETS pbr2.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
install(TARGETS ibl.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
#install(TARGETS vct.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
install(TARGETS defered.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
install(TARGETS ssao.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
#install(TARGETS screenspace.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
#install(TARGETS dirt.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
install(TARGETS simpleCompute.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
#install(TARGETS compute3d.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
install(TARGETS compute01.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
install(TARGETS compute02.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
