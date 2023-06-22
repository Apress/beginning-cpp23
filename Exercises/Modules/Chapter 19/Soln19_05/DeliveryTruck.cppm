export module delivery_truck;
import truckload;

import std;

export class DeliveryTruck
{
public:
  // Type alias for the type of the delivery callback functions
  // std::function<void(SharedBox)> would be just fine as well.
  // Some considerations that made us go for std::move_only_function<>:
  //   - By using std::move_only_function<>, callback objects can be move-only.
  //     That's only a very tiny advantage here, though, as callbacks rarely are move-only in practice.
  //   - By using std::move_only_function<>, DeliveryTruck becomes move-only as well.
  //     This side-effect has some merit to it:
  //	 the default copy members would also copy the list of callbacks,
  //	 and it's highly questionable whether you'd want to receive callbacks 
  //     from a *copy* of a DeliveryTruck that you started to observe...
  using Callback = std::move_only_function<void(SharedBox)>;  
	
  DeliveryTruck(Truckload truckload);   // Create a delivery truck (pass-by-value to allow a Truckload to be either copied or moved!)
  
  void deliverBox(SharedBox box);
  
  void registerOnDelivered(Callback callback);
  
private:
  Truckload m_truckload;
  
  std::vector<Callback> m_callbacks;
};
