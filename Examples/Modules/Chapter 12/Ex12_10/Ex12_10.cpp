// Const objects and const member functions
import std;
import box;

int main()
{
  // v-- this const was added...
  const Box myBox {3.0, 4.0, 5.0};
  std::println("myBox dimensions are {} by {} by {}",
      myBox.getLength(), myBox.getWidth(), myBox.getHeight());

  // Invoking mutators / setters is not possible on a const object:
  //myBox.setLength(-20.0);       // ignored!
  //myBox.setWidth(40.0);
  //myBox.setHeight(10.0);
  //std::println("myBox dimensions are now {} by {} by {}",
  //  myBox.getLength(),     // 3 (unchanged)
  //  myBox.getWidth(),      // by 40
  //  myBox.getHeight()      // by 10
  //);

  std::println("myBox's volume is {}", myBox.volume());
}
