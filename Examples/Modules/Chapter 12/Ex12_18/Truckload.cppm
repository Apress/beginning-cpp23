export module truckload;

export import :shared_box;
import :package;
import std;

export class Truckload
{
public:
  Truckload() = default;            // Default constructor - empty truckload

  Truckload(SharedBox box)          // Constructor - one Box
  { m_head = m_tail = new Package{ box }; }
  Truckload(const std::vector<SharedBox>& boxes);  // Constructor - vector of Boxes
  Truckload(const Truckload& src);  // Copy constructor

  ~Truckload();                     // Destructor

  SharedBox getFirstBox();          // Get the first Box
  SharedBox getNextBox();           // Get the next Box
  void addBox(SharedBox box);       // Add a new SharedBox
  bool removeBox(SharedBox box);    // Remove a Box from the Truckload
  void printBoxes() const;          // Output the Boxes

private:
  Package* m_head{};                // First in the list
  Package* m_tail{};                // Last in the list
  Package* m_next{};                // The package whose Box to retrieve next
};
