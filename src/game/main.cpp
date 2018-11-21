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

  //load the ogg audio file into the game 
  std::shared_ptr<myengine::Audio> A = std::make_shared < myengine::Audio>("../dixie_horn.ogg");
  //send it to the engine so it will play 
  A->play();

  std::shared_ptr<TestScreen> ts = e->addComponent<TestScreen>("Green");
  std::shared_ptr<myengine::MeshRenderer> mr = e->addComponent<myengine::MeshRenderer>();



  //std::shared_ptr<myengine::MeshRenderer> mr2 = e->getComponent<myengine::MeshRenderer>();

  c->start();

  return 0;
}