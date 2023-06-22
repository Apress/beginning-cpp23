export module boxes:tough_pack;

import :box;

export class ToughPack : public Box
{
public:
  // Inherit the Box(length, width, height) constructor
  using Box::Box;

  // Function to calculate volume of a ToughPack allowing 13% for packing
  double volume() const { return 0.87 * getLength() * getWidth() * getHeight(); }
};
