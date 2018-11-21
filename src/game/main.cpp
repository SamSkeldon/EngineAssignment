#include <myengine/myengine.h>

#include <iostream>

class TestScreen : public myengine::Component
{
public:
  void onInit(std::string color)
  {
    //std::cout << "onInit " << color << std::endl;
  }

  void onBegin()
  {
    //std::cout << "onBegin" << std::endl;
  }

  void onTick()
  {
    //std::cout << "onTick" << std::endl;
  }

  void onDisplay()
  {
    //std::cout << "onTick" << std::endl;
  }
};

int main()
{
  std::shared_ptr<myengine::Core> c = myengine::Core::initialize();
  std::shared_ptr<myengine::Entity> e = c->addEntity();


  std::shared_ptr<myengine::VertexArray> hallShape = std::make_shared<myengine::VertexArray>("../re_hall_baked.obj");
  std::shared_ptr<myengine::Texture> hallTexture = std::make_shared<myengine::Texture>("../ re_hall_diffuse.png");
  std::shared_ptr<myengine::VertexArray> shape = std::make_shared<myengine::VertexArray>("../curuthers.obj");
  std::shared_ptr<myengine::Texture> texture = std::make_shared<myengine::Texture>("../curuthers_diffuse.png");
  std::shared_ptr<myengine::ShaderProgram> shader = std::make_shared<myengine::ShaderProgram>("../simple.vert", "../simple.frag");


  //load the ogg audio file into the game 
  std::shared_ptr<myengine::Audio> A = std::make_shared < myengine::Audio>("../dixie_horn.ogg");
  //send it to the engine so it will play 
  
  A->play();


  std::shared_ptr<TestScreen> ts = e->addComponent<TestScreen>("Green");
  std::shared_ptr<myengine::MeshRenderer> mr = e->addComponent<myengine::MeshRenderer>();


  glm::mat4 model(1.0f);
  shader->setUniform("in_View", glm::inverse(model)); 

  //std::shared_ptr<myengine::MeshRenderer> mr2 = e->getComponent<myengine::MeshRenderer>();

  c->start();

  return 0;
}
