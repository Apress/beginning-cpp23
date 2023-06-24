export module truckload;

import box;

import std;

export using SharedBox = std::shared_ptr<Box>;

export class Truckload
{
public:
  Truckload() = default;            // Default constructor - empty truckload
  Truckload(SharedBox box);         // Constructor - one Box
  Truckload(std::vector<SharedBox> boxes);  // Constructor - vector of Boxes (accept by value!)

  class Iterator;      // Declaration of a public nested class, Truckload::Iterator

  Iterator getIterator() const;

  void addBox(SharedBox box);       // Add a new SharedBox
  bool removeBox(SharedBox box);    // Remove a Box from the Truckload

  void printBoxes() const;          // Output the Boxes

  SharedBox& operator[](std::size_t index);      // Overloaded subscript operator (can no longer be const!)
  SharedBox operator[](std::size_t index) const; // Overloaded subscript operator (new const version returns by value)

  void swap(Truckload& other) noexcept;

private:
  std::vector<SharedBox> m_boxes;
};

// Out-of-class definition of the nested Iterator class 
// (class itself is part of the public interface, so belongs in a module interface file)
// Note that this is effectively a const iterator...
class Truckload::Iterator
{
public:
  SharedBox getFirstBox();  // Get the first Box
  SharedBox getNextBox();   // Get the next Box

private:
  const std::vector<SharedBox>* m_boxes;         // Pointer to the underlying vector
  std::vector<SharedBox>::const_iterator m_next; // Iterator pointing to the next Box to retrieve

  friend class Truckload;   // Only a Truckload can create an Iterator
  explicit Iterator(const std::vector<SharedBox>& boxes) 
    : m_boxes{ &boxes }, m_next{ boxes.end() } {}
};

// Optional yet conventional non-member function (forwards to member function)
export void swap(Truckload& one, Truckload& other) noexcept;

