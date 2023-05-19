// Exercise 20-1 Rework the Truckload class using std::vector<>
import std;
import truckload;
import box.random;

/*
  In this solution we preserved the interface of the nested Iterator class.
  An alternative, of course, would be to define Iterator as an alias 
  for std::vector<Box>::iterator, and introduce begin() and end() members.
  But then all code using the iterators would have to be updated as well.
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