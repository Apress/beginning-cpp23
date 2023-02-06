// Accessing private members through getters and setters
import std;
import box;

int main()
{
  Box myBox {3.0, 4.0, 5.0};
  std::println("myBox dimensions are {} by {} by {}",
      myBox.getLength(), myBox.getWidth(), myBox.getHeight());

  myBox.setLength(-20.0);  // ignored!
  myBox.setWidth(40.0);
  myBox.setHeight(10.0);
  std::println("myBox dimensions are now {} by {} by {}",
    myBox.getLength(),     // 3 (unchanged)
    myBox.getWidth(),      // by 40
    myBox.getHeight()      // by 10
  );
}
