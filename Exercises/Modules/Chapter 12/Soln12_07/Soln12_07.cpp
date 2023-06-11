// Creating a nested iterator class
import box.random;
import truckload;
import std;

/* 
 Turns out moving the getFirstBox() and getLastBox() functions 
 to the nested iterator class is easy. We used the same names for
 the member variables, so it is just a matter of changing "Truckload::"
 into "Truckload::Iterator::".
 
 Makes sense: the logic for iterating the linked lists has not changed.
 The only difference is that now there are m_next and m_head pointers
 per iteration, instead of only the one pair in the Truckload object.
 This allows nested iterations, concurrent iterations, and so on.
 You will encounter this iterator pattern again in Chapters 19 and 20.

 Btw: if it strikes you as sub-optimal that our findLargestBox() and
 findSmallestBox() are so similar, do not despair: in Chapter 19 we teach
 you the techniques you need to avoid this so-called code duplication.
*/

SharedBox findLargestBox(const Truckload& truckload);
SharedBox findSmallestBox(const Truckload& truckload);

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
  Truckload copy{ load1 };
  std::println("The copied truckload:");
  copy.printBoxes();

  // Find the largest Box in the list
  const auto largestBox{ findLargestBox(load1) };

  std::println("\nThe largest box in the first list is {}", to_string(*largestBox));
  load1.removeBox(largestBox);
  std::println("\nAfter deleting the largest box, the list contains:");
  load1.printBoxes();

  const std::size_t nBoxes{ 16 };            // Number of vector elements
  std::vector<SharedBox> boxes;        // Array of Box objects

  for (std::size_t i{}; i < nBoxes; ++i)
    boxes.push_back(randomSharedBox());

  Truckload load2{ boxes };
  std::println("\nThe second list:");
  load2.printBoxes();

  const auto smallestBox{ findSmallestBox(load2) };

  std::println("\nThe smallest box in the second list is {}", to_string(*smallestBox));
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
  SharedBox smallestBox{ iterator.getFirstBox() };

  SharedBox nextBox{ iterator.getNextBox() };
  while (nextBox)
  {
    if (nextBox->compare(*smallestBox) < 0)
      smallestBox = nextBox;
    nextBox = iterator.getNextBox();
  }

  return smallestBox;
}