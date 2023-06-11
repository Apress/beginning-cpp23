// Using nested classes
import box.random;
import truckload;
import std;

int main()  
{
  Truckload load1;  // Create an empty list

  // Add 12 random Box objects to the list
  const std::size_t boxCount {12};
  for (std::size_t i {} ; i < boxCount ; ++i)
    load1.addBox(randomSharedBox());

  std::println("The first list:");
  load1.printBoxes();

  // Copy the truckload
  Truckload copy{load1};
  std::println("The copied truckload:");
  copy.printBoxes();

  // Find the largest Box in the list
  SharedBox largestBox{load1.getFirstBox()};

  SharedBox nextBox{load1.getNextBox()};
  while (nextBox)
  {
    if (nextBox->compare(*largestBox) > 0)
      largestBox = nextBox;
    nextBox = load1.getNextBox();
  }

  std::println("\nThe largest box in the first list is {}", to_string(*largestBox));
  load1.removeBox(largestBox);
  std::println("\nAfter deleting the largest box, the list contains:");
  load1.printBoxes();

  const std::size_t nBoxes {16};       // Number of vector elements
  std::vector<SharedBox> boxes;        // Array of Box objects

  for (std::size_t i {} ; i < nBoxes ; ++i)
    boxes.push_back(randomSharedBox());

  Truckload load2{boxes};
  std::println("\nThe second list:");
  load2.printBoxes();

  auto smallestBox{ load2.getFirstBox() };
  for (auto box{ load2.getNextBox() }; box; box = load2.getNextBox())
    if (box->compare(*smallestBox) < 0)
      smallestBox = box;

  std::println("\nThe smallest box in the second list is {}", to_string(*smallestBox));
}
