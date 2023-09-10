module truckload;

import std;

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
  for (Package* package{ src.m_head }; package; package = package->getNext())
  {
    addBox(package->getBox());
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
  for (Package* package{m_head}; package; package = package->getNext())
  {
    std::print(" {}", to_string(*package->getBox()));
    if (! (++count % boxesPerLine)) std::println("");
  }
  if (count && count % boxesPerLine) std::println("");
}

SharedBox Truckload::getFirstBox()
{
  m_next = m_head;      // nullptr only for an empty truckload
  return getNextBox();
}

SharedBox Truckload::getNextBox()
{
  if (!m_next)          // If there's no next...
    return nullptr;     // ...return nullptr

  SharedBox result = m_next->getBox(); // Extract the box to return
  m_next = m_next->getNext();          // Move to the next package
  return result;
}

void Truckload::addBox(SharedBox box)
{
  auto package{ new Package{box} }; // Create a new Package

  if (m_tail)                      // Check list is not empty
    m_tail->setNext(package);      // Append the new object to the tail
  else                             // List is empty
    m_head = package;              // so new object is the head

  m_tail = package;                // Either way: the latest object is the (new) tail
}

bool Truckload::removeBox(SharedBox boxToRemove)
{
  Package* previous {nullptr};      // no previous yet
  Package* current {m_head};        // initialize current to the head of the list
  while (current)
  {
    if (current->getBox() == boxToRemove)      // We found the Box!
    {
      // If there is a previous Package make it point to the next one (Figure 12-10)
      if (previous) previous->setNext(current->getNext());

      // Restore class invariants by updating impacted member variable pointers:
      if (current == m_head) m_head = current->getNext(); // Removing first box
      if (current == m_tail) m_tail = previous;           // Removing last box
      if (current == m_next) m_next = current->getNext(); // Removing "next" box

      current->setNext(nullptr);        // Disconnect the current Package from the list
      delete current;                   // and delete it

      return true;                      // Return true: we found and removed the box
    }
                                        // Move both pointers along (mind the order!)
    previous = current;                 //  - first current becomes the new previous
    current = current->getNext();       //  - then move current along to the next Package
  }

  return false;     // Return false: boxToRemove was not found
}
