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
  Truckload(const Truckload& src);  // Copy constructor

  ~Truckload();                     // Destructor

  class Iterator;      // Declaration of a public nested class, Truckload::Iterator

  Iterator getIterator() const;

  void addBox(SharedBox box);       // Add a new SharedBox
  bool removeBox(SharedBox box);    // Remove a Box from the Truckload
  bool removeBox(Iterator& iter);   // Remove the Box pointed to by this Iterator

  void printBoxes() const;           // Output the Boxes
  void printBoxesReversed() const;   // Output the Boxes in reversed order

private:
  class Package;

  void removePackage(Package* package);

  Package* m_head {};               // First in the list
  Package* m_tail {};               // Last in the list
};

// Out-of-class definition of the nested Iterator class 
// (class itself is part of the public interface, so belongs in the module interface)
class Truckload::Iterator
{
public:
  SharedBox getFirstBox();    // Get the first Box
  SharedBox getLastBox();     // Get the last Box
  SharedBox getNextBox();     // Get the next Box
  SharedBox getPreviousBox(); // Get the previous Box
  SharedBox getCurrentBox() const;  // Get the current Box

private:
  Package* m_head;          // The head of the linked list (needed for getFirstBox())
  Package* m_tail;          // The tail of the linked list (needed for getLastBox())
  Package* m_current;       // The package whose Box was last retrieved

  friend class Truckload;   // Only a Truckload can create an Iterator
  explicit Iterator(Package* head, Package* tail) 
    : m_head{ head }
    , m_tail{ tail }
    , m_current{ nullptr } 
  {}
};
