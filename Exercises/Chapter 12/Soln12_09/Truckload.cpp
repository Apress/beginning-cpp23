module truckload;

import std;

// Definition of the nested class member
// Since this member is private, its definition can be moved to the source file.
class Truckload::Package
{
public:
  SharedBox m_box;      // Pointer to the Box object contained in this Package
  Package* m_next;      // Pointer to the next Package in the list
  Package* m_previous;  // Pointer to the previous Package in the list

  Package(SharedBox box) : m_box{ box }, m_next{}, m_previous{} {}
  ~Package() { delete m_next; }
};

// Constructor - one Box (moved to source file to gain access to definition of Package)
Truckload::Truckload(SharedBox box)          
{
  m_head = m_tail = new Package{ box };
}

// Constructor - vector of Boxes
Truckload::Truckload(const std::vector<SharedBox>& boxes)
{
  for (const auto& box : boxes)
  {
    addBox(box);
  }
}

// Copy constructor
Truckload::Truckload(const Truckload& src)
{
  for (Package* package{ src.m_head }; package; package = package->m_next)
  {
    addBox(package->m_box);
  }
}

// Destructor: clean up the list (moved to source file to gain access to definition of Package)
Truckload::~Truckload()
{
  delete m_head;
}

void Truckload::printBoxes() const
{
  const std::size_t boxesPerLine{ 4 };
  std::size_t count {};  
  for (Package* package{m_head}; package; package = package->m_next)
  {
    std::print(" {}", to_string(*package->m_box));
    if (! (++count % boxesPerLine)) std::println("");
  }
  if (count % boxesPerLine) std::println("");
}

void Truckload::printBoxesReversed() const
{
  const std::size_t boxesPerLine{ 4 };
  std::size_t count{};
  for (Package* package{ m_tail }; package; package = package->m_previous)
  {
    std::print(" {}", to_string(*package->m_box));
    if (!(++count % boxesPerLine)) std::println("");
  }
  if (count % boxesPerLine) std::println("");
}

Truckload::Iterator Truckload::getIterator() const
{ 
  return Iterator{ m_head, m_tail }; 
}

SharedBox Truckload::Iterator::getFirstBox()
{
  // Return m_head's box (or nullptr if the list is empty)
  m_current = m_head;
  return getCurrentBox();
}

SharedBox Truckload::Iterator::getLastBox()
{
  // Return m_tail's box (or nullptr if the list is empty)
  m_current = m_tail;
  return getCurrentBox();
}

SharedBox Truckload::Iterator::getNextBox()
{
  if (m_current)                                 
    m_current = m_current->m_next;                // Move to the next package

  return getCurrentBox();   // Return its box (or nullptr...).
}

SharedBox Truckload::Iterator::getPreviousBox()
{
  if (m_current)                                 
    m_current = m_current->m_previous;           // Move to the previous package

  return getCurrentBox(); // Return its box (or nullptr...).
}

SharedBox Truckload::Iterator::getCurrentBox() const
{
  return m_current ? m_current->m_box : nullptr;
}

void Truckload::addBox(SharedBox box)
{
  auto package{ new Package{box} }; // Create a new Package

  if (m_tail)                      // Check list is not empty
  {
    package->m_previous = m_tail;  // The package is added after the old tail
    m_tail->m_next = package;      // Append the new object to the tail
  }
  else                             // List is empty
    m_head = package;              // so new object is the head
  
  m_tail = package;                // Either way: the latest object is the (new) tail
}

bool Truckload::removeBox(SharedBox boxToRemove)
{
  for (auto* current{ m_head }; current != nullptr; current = current->m_next)
  {
    if (current->m_box == boxToRemove)  // We found the Box!
    {
      removePackage(current);           // Delegate the heavy lifting to removePackage()...
      return true;
    }  
  }

  return false;     // Return false: boxToRemove was not found
}

bool Truckload::removeBox(Iterator& iter)
{
  if (iter.m_current)
  {
    auto* next{ iter.m_current->m_next };
    removePackage(iter.m_current);
    iter.m_current = next;      // Bonus exercise: make sure the iterator is not invalidated by moving it to the next Package
    return true;
  }
  else
  {
    return false;
  }
}

void Truckload::removePackage(Package* package)
{
  // Update the doubly-linked list pointers
  if (package->m_previous) package->m_previous->m_next = package->m_next;
  if (package->m_next) package->m_next->m_previous = package->m_previous;

  // Update pointers in member variables where required:
  if (package == m_head) m_head = package->m_next;
  if (package == m_tail) m_tail = package->m_previous;

  package->m_next = nullptr;     // Disconnect the current Package from the list
  delete package;                // and delete it
}