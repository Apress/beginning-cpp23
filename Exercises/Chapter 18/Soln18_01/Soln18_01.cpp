// Exercise 18-1 Define move operators for the Truckload class
import std;
import truckload;
import box.random;

/*
  Things to watch out for:
    - use of copy-and-swap / move-and-swap function
    - noexcept move and swap members
    - dislodge the linked list from the moved load in the move constructor
*/

int main()
{
  Truckload load;
  const std::size_t boxCount {20};      // Number of Box object to be created

  // Create boxCount Box objects
  for (std::size_t i {}; i < boxCount; ++i)
    load.addBox(randomSharedBox());

  std::println("The boxes in the Truckload are:");
  load.printBoxes();

  Truckload moveConstructedLoad{ std::move(load) };

  std::println("\nThe boxes in the move constructed Truckload are:");
  moveConstructedLoad.printBoxes();

  Truckload moveAssignedLoad;
  moveAssignedLoad = std::move(moveConstructedLoad);
  
  std::println("\nThe boxes in the move assigned Truckload are:");
  moveAssignedLoad.printBoxes();
}
