#include <iostream>
#include <memory>
#include <ThomasTheTank/ThomasTheTank.h>


using namespace ThomasTheTank;
#define Shared std::shared_ptr


int main()
{
	Shared<Core> Core = Core::Initialise();



  return 0;
}