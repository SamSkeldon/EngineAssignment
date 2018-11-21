#include "MeshRenderer.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"
#include <iostream>

namespace myengine
{

void MeshRenderer::onInit()
{
  /*std::shared_ptr<VertexBuffer> positions = std::make_shared<VertexBuffer>();
  positions->add(glm::vec3(0.0f, 0.5f, 0.0f));
  positions->add(glm::vec3(-0.5f, -0.5f, 0.0f));
  positions->add(glm::vec3(0.5f, -0.5f, 0.0f));

  std::shared_ptr<VertexBuffer> colors = std::make_shared<VertexBuffer>();
  colors->add(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
  colors->add(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
  colors->add(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
*/
 // shape = std::make_shared<VertexArray>();
 // shape->setBuffer("in_Position", positions);
 // shape->setBuffer("in_Color", colors);

  shader = std::make_shared<ShaderProgram>("../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
  glm::mat4 model(1.0f);
  float angle = 0;
  model = glm::mat4(1.0f);
  model = glm::translate(model, glm::vec3(0, -2.1f, -20.0f));
  model = glm::rotate(model, glm::radians(angle), glm::vec3(0, 1, 0));
  shader->setUniform("in_Model", model);
 //shader->setUniform("in_Texture", );
}

void MeshRenderer::onDisplay()
{
  shader->setUniform("in_Model", glm::mat4(1.0f));
  //shader->setUniform("in_Projection", glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.f));
//  shader->draw(*shape);
}

}
