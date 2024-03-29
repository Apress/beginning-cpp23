export module boxes:tough_pack;

import :box;

export class ToughPack : public Box
{
public:
  // Inherit the Box(length, width, height) constructor
  using Box::Box;

protected:
  // Function to calculate volume of a ToughPack allowing 13% for packing
  double volume() const override { return 0.87 * getLength() * getWidth() * getHeight(); }
};
