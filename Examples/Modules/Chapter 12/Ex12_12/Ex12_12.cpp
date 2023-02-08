// Const objects and const member functions
import std;
import box;

int main()
{
  const Box myBox {3.0, 4.0, 5.0};
  std::println("myBox dimensions are {} by {} by {}",
      myBox.getLength(), myBox.getWidth(), myBox.getHeight());

  myBox.printVolume();
  myBox.printVolume();
  myBox.printVolume();
}
