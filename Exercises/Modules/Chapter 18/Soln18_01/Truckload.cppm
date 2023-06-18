export module truckload;

import box;
import std;

export using SharedBox = std::shared_ptr<Box>;

export class Truckload
{
public:
  Truckload() = default;            // Default constructor - empty truckload

  Truckload(SharedBox box);         // Constructor - one Box
  Truckload(const std::vector<SharedBox>& boxes);  // Constructor - vector of Boxes

  Truckload(const Truckload& src);             // Copy constructor
  Truckload& operator=(const Truckload& src);  // Copy assignment operator

  Truckload(Truckload&& src) noexcept;             // Move constructor
  Truckload& operator=(Truckload&& src) noexcept;  // Move assignment operator

  ~Truckload();                     // Destructor

  class Iterator;      // Declaration of a public nested class, Truckload::Iterator

  Iterator getIterator() const;

  void addBox(SharedBox box);       // Add a new SharedBox
  bool removeBox(SharedBox box);    // Remove a Box from the Truckload
  
  void printBoxes() const;          // Output the Boxes

  SharedBox& operator[](std::size_t index);   // Overloaded subscript operator

  void swap(Truckload& other) noexcept;

private:
  class Package;

  Package* m_head {};               // First in the list
  Package* m_tail {};               // Last in the list
};

// Out-of-class definition of the nested Iterator class 
// (class itself is part of the public interface, so belongs in the module interface)
class Truckload::Iterator
{
public:
  SharedBox getFirstBox();  // Get the first Box
  SharedBox getNextBox();   // Get the next Box

private:
  Package* m_head;          // The head of the linked list (needed for getFirstBox())
  Package* m_next;          // The package whose Box to retrieve next

  friend class Truckload;   // Only a Truckload can create an Iterator
  explicit Iterator(Package* head) : m_head{ head }, m_next{} {}
};