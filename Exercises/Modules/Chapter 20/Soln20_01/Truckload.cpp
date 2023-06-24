module truckload;

import std;

// Constructor - one Box
Truckload::Truckload(SharedBox box)
  : m_boxes{ 1, std::move(box) }
{
}

// Constructor - vector of Boxes
Truckload::Truckload(std::vector<SharedBox> boxes)
  : m_boxes{ std::move(boxes) }
{
}

// Swap assignment operator (noexcept)
void Truckload::swap(Truckload& other) noexcept
{
  m_boxes.swap(other.m_boxes);
}

// Optional yet conventional non-member function (forwards to member function)
void swap(Truckload& one, Truckload& other) noexcept
{
  one.swap(other);
}

void Truckload::printBoxes() const
{
  const std::size_t boxesPerLine{ 4 };
  std::size_t count {};
  for (const auto& box : m_boxes)   // Can use range-based loop now...
  {
    std::print(" {}", to_string(*box));
    if (!(++count % boxesPerLine)) std::println("");
  }
  if (count % boxesPerLine) std::println("");
}

Truckload::Iterator Truckload::getIterator() const { return Iterator{ m_boxes }; }

SharedBox Truckload::Iterator::getFirstBox()
{
  m_next = m_boxes->begin();
  return getNextBox();
}

SharedBox Truckload::Iterator::getNextBox()
{
  if (m_next == m_boxes->end())   // If there's no next...
    return  {};                   // ...return nullptr

  return *m_next++;
}

void Truckload::addBox(SharedBox box)
{
  m_boxes.push_back(std::move(box));
}

bool Truckload::removeBox(SharedBox boxToRemove)
{
  // Unlike the original implementation, 
  // std::erase() removes all occurrences of boxToRemove.
  // If that is not acceptable, you can use find() as shown below...
  return std::erase(m_boxes, boxToRemove) > 0;

// Remove only the first occurrence of boxToRemove
/*
  if (auto found{ std::ranges::find(m_boxes, boxToRemove) }; found != end(m_boxes))
  {
    m_boxes.erase(found);
    return true;
  }
  else
  {
    return false;
  }
*/
}

SharedBox& Truckload::operator[](std::size_t index)
{
  // Original implementation performed bounds checking, so use at() instead of []
  return m_boxes.at(index);
}

SharedBox Truckload::operator[](std::size_t index) const
{
  // Original implementation performed bounds checking, so use at() instead of []
  return m_boxes.at(index);
}
