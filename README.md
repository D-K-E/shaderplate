# shaderplate

Simple boilerplate for testing shaders.

Best way to learn what's going on is to look at the shader code and source
code. However there is a doxygen generated site as well.


## Requirements

- Assimp for loading models.

- C++17 as the executables use `<filesystem>` header heavily.

- I am using clang-9 as compiler since it supports the `filesystem` but if you
  would like to use another compiler, it should be okay. The code should be
  fairly portable, apart from the `filesystem`.

- GLFW for window management.

- `glad` as well for function pointers but this one is included.

Note that GLFW and Assimp are loaded as **SHARED**  libraries, so you need to
change the path of their relative location in `CMakeLists.txt` file.

## Motivation

This project can be used as an example for learning  different topics related
to OpenGL:

Here is a list of covered topics roughly ordered from simple to advanced:

- Rendering a full screen quad: `texture.cpp`
![texture-out-img](./images/texture.out.png)

- Rendering a cube with phong lightening: `phong/phong.cpp`
![phong-out-img](./images/phong.out.png)

- Rendering a cube without specular lights with phong lightening:
  `phong/phongNoSpec.cpp`
![phong-no-spec-out-img](./images/phongNoSpec.out.png)

- Rendering a cube with heightmap and phong lightening: `heightmap/phong2.cpp`
![heightmap-img](./images/heightmap.out.png)

- Rendering a cube with phong lightening using Uniform Buffer Objects:
  `ubo/phong.cpp`

- Rendering a cube with phong lightening using Shader Storage Buffer Objects:
  `ssbo/phong.cpp`

- Rendering a cube with phong lightening using Parallax Relief Mapping:
  `parallax/phong.cpp`
![parallax-img](./images/phongParallaxRelief.out.png)

- Rendering a cube with phong lightening using Parallax Relief Mapping a
  variation:
  `parallax/phong2.cpp`
![parallax-2-img](./images/phongParallaxRelief2.out.png)

- Rendering a cube with PBR materials: `pbr/simplepbr.cpp`
![pbr-img](./images/pbr.out.png)

- Manipulating normals of a model with Geometry Shader: `geometry/geometry.cpp`
![geometry-img](./images/geometry.out.png)

- Simple Image Processing using Frame Buffer Object:
  `fbo/fbo.cpp`
![fbo-img](./images/fbo.out.png)

- Shadow mapping: `shadowmap/shadowmap.cpp`
![shadowmap-img](./images/shadowmap.out.png)

- Rendering a cube inside a skybox/cubemap: `skybox/sky.cpp`
![skybox-img](./images/skybox.out.png)

- Rendering 10 backpacks with spot light using defered shading:
  `defered/defered.cpp`

- Drawing simple shapes with a compute shader: `raytrace/simplecompute.cpp`
![simple-compute-img](./images/simpleCompute.out.png)

- Ray tracing sphere with a compute shader: `raytrace/compute01.cpp`
![simple-compute-img](./images/compute01.out.png)

- Another more interesting example of raytracing 
  with a compute shader: `raytrace/compute02.cpp`
![simple-compute-2-img](./images/compute02.out.png)
