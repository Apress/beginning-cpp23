// Create a doubly-linked list of Packages
import box.random;
import truckload;
import std;

/*
   To show reverse iteration, we've modified findSmallestBox() to iterate in reverse order
 */

SharedBox findLargestBox(const Truckload& truckload);
SharedBox findSmallestBox(const Truckload& truckload);

int main()
{
  Truckload load;  // Create an empty list

  // Add 12 random Box objects to the list
  const std::size_t boxCount{ 12 };
  for (std::size_t i{}; i < boxCount; ++i)
    load.addBox(randomSharedBox());

  std::println("The random truckload:");
  load.printBoxes();
  std::println("");
  
  std::println("The same random truckload in reverse:");
  load.printBoxesReversed();
  std::println("");

  std::println("The largest box (found using forward iteration) is {}", to_string(*findLargestBox(load)));
  std::println("The smallest box (found using reverse iteration) is {}", to_string(*findSmallestBox(load)));
}

SharedBox findLargestBox(const Truckload& truckload)
{
  auto iterator{ truckload.getIterator() };  // Type of iterator is Truckload::Iterator
  SharedBox largestBox{ iterator.getFirstBox() };

  SharedBox nextBox{ iterator.getNextBox() };
  while (nextBox)
  {
    if (nextBox->compare(*largestBox) > 0)
      largestBox = nextBox;
    nextBox = iterator.getNextBox();
  }

  return largestBox;
}

SharedBox findSmallestBox(const Truckload& truckload)
{
  auto iterator{ truckload.getIterator() };  // Type of iterator is Truckload::Iterator
  SharedBox smallestBox{ iterator.getLastBox() };

  SharedBox nextBox{ iterator.getPreviousBox() };
  while (nextBox)
  {
    if (nextBox->compare(*smallestBox) < 0)
      smallestBox = nextBox;
    nextBox = iterator.getPreviousBox();
  }

  return smallestBox;
}