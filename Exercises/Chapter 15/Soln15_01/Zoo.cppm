// The Zoo class representing a collection of animals 
export module zoo;

import animals;
import std;

export using AnimalPtr = std::shared_ptr<Animal>;         // Define a type alias for convenience

export class Zoo
{
public:
  Zoo() = default;                                 // Default constructor for an empty zoo
  Zoo(const std::vector<AnimalPtr>& new_animals);  // Constructor from a vector of animals
  virtual ~Zoo() = default;                        // Add a virtual destructor to allow classes to safely derive from Zoo;
                                                   // possible examples of Zoo specializations include SafariPark, PettingZoo, ...
  void addAnimal(AnimalPtr animal);                // Add an animal to the zoo
  void showAnimals() const;                        // Output the animals and the sound they make

private:
  std::vector<AnimalPtr> m_animals;      // Stores pointers to the animals
};
