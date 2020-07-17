// simple compute shader code
// license: see LICENSE
#include <custom/utils.hpp>

void setVertices(GLuint &vao, GLuint &vbo) {
  // set vertices to vao and vbo for rendering quad
  float vertices[] = {
      // viewport position ||   texture coords
      -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, // bottom left
      -1.0f, 1.0f,  0.0f, 0.0f, 1.0f, // bottom right
      1.0f,  -1.0f, 0.0f, 1.0f, 0.0f, // top left
      1.0f,  1.0f,  0.0f, 1.0f, 1.0f  // top right
  };
  glGenVertexArrays(1, &vao);
  glGenBuffers(1, &vbo);

  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindVertexArray(vao);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
                        (void *)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);
}
void computeInfo() {
  // show compute shader related info
  // work group handling
  // work group count
  GLint work_group_count[3];
  glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, 0, &work_group_count[0]);
  glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, 1, &work_group_count[1]);
  glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, 2, &work_group_count[2]);
  std::cout << "total work group count x: " << work_group_count[0] << std::endl;
  std::cout << "total work group count y: " << work_group_count[1] << std::endl;
  std::cout << "total work group count z: " << work_group_count[2] << std::endl;

  // work group size
  GLint work_group_size[3];
  glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 0, &work_group_size[0]);
  glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 1, &work_group_size[1]);
  glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 2, &work_group_size[2]);
  std::cout << "total work group size x: " << work_group_size[0] << std::endl;
  std::cout << "total work group size y: " << work_group_size[1] << std::endl;
  std::cout << "total work group size z: " << work_group_size[2] << std::endl;
  // global work group size is 512 * 512 == texture width * texture height
  // local work group size is 1 since 1 pixel at a time

  // work group invocation
  GLint work_group_inv;
  glGetIntegerv(GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS, &work_group_inv);
  std::cout << "max work group invocation: " << work_group_inv << std::endl;
  // end of work group
}
void setTexture(GLuint texture_output, unsigned int w, unsigned int h) {
  // set texture related
  int texture_width = w;
  int texture_height = h;
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, texture_output);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, texture_width, texture_height, 0,
               GL_RGBA, GL_FLOAT, NULL);
  glBindTexture(GL_TEXTURE_2D, 0); // unbind

  // end texture handling
  gerr();
}
void setDepthRbo(GLuint &rbo) {
  //
  glGenRenderbuffers(1, &rbo);
  glBindRenderbuffer(GL_RENDERBUFFER, rbo);
  glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, WINWIDTH,
                        WINHEIGHT);
  glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,
                            GL_RENDERBUFFER, rbo);
}

void setFbo(GLuint &fbo, GLuint &txt, GLuint &rbo) {
  glGenFramebuffers(1, &fbo);
  setTexture(txt, WINWIDTH, WINHEIGHT);
  GLuint attachments[1] = {GL_COLOR_ATTACHMENT0};
  glDrawBuffers(1, attachments);
  setDepthRbo(rbo);
  gerrf();
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

Shader loadQuadShader() {

  fs::path vpath = shaderDirPath / "pathtrace" / "tquad.vert";
  fs::path fpath = shaderDirPath / "pathtrace" / "tquad.frag";
  Shader quad = Shader(vpath.c_str(), fpath.c_str());
  return quad;
}
Shader loadRayShader() {
  fs::path vpath = shaderDirPath / "pathtrace" / "tquad.vert";
  fs::path cpath = shaderDirPath / "pathtrace" / "gpu1.frag";
  Shader rsh = Shader(cpath.c_str());
  return rsh;
}
void regularDrawing(GLuint vao, GLuint texture_output, Shader quadShader) {
  // regular draw commands for rendering quad
  glClear(GL_COLOR_BUFFER_BIT);
  gerr();
  quadShader.useProgram();
  gerr();
  glBindVertexArray(vao);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, texture_output);
  gerr();

  // drawing call
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  gerr();
  glfwPollEvents();
}

int main() {
  initializeGLFWMajorMinor(4, 3);

  GLFWwindow *window;
  window = glfwCreateWindow(WINWIDTH, WINHEIGHT, "GPU Path 1", NULL, NULL);
  if (window == NULL) {
    std::cout << "Failed creating window" << std::endl;
    return -1;
  }
  glfwMakeContextCurrent(window);
  // window resize
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
  glfwMakeContextCurrent(window);
  // window resize
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
  if (gladLoadGLLoader((GLADloadproc)(glfwGetProcAddress)) == 0) {
    std::cout << "Failed to start glad" << std::endl;
    glfwTerminate();
    return -1;
  }
  gerr();
  glViewport(0, 0, WINWIDTH, WINHEIGHT);

  // load glad
  // set vao and vbo
  GLuint vao, vbo;
  setVertices(vao, vbo);

  // generate framebuffer object
  GLuint pathFbo, pathRbo;

  GLuint texture_output;
  glGenTextures(1, &texture_output);
  setTexture(texture_output, WINWIDTH, WINHEIGHT);

  //
  Shader quadShader = loadQuadShader();

  Shader rayShader = loadRayShader();

  while (glfwWindowShouldClose(window) == 0) {
    glClearColor(0.0, 0.0, 0.0, 1.0); // clear
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBindFramebuffer(GL_FRAMEBUFFER, pathFbo);
    rayShader.useProgram();
    renderQuad();
    gerr();
    // end launch shaders
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    // drawing call
    regularDrawing(vao, texture_output, quadShader);

    if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_ESCAPE)) {
      glfwSetWindowShouldClose(window, 1);
    }
    glfwSwapBuffers(window);
  }
  glDeleteVertexArrays(1, &vao);
  glDeleteBuffers(1, &vbo);
  glfwTerminate();
  return 0;
}
