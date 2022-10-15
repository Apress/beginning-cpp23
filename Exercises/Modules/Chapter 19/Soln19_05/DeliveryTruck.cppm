export module delivery_truck;
import truckload;

import std;

export class DeliveryTruck
{
public:
  using Callback = std::function<void(SharedBox)>;  // Type alias for the type of the delivery callback functions
	
  DeliveryTruck(Truckload truckload);   // Create a delivery truck (pass-by-value to allow a Truckload to be either copied or moved!)
  
  void deliverBox(SharedBox box);
  
  void registerOnDelivered(Callback callback);
  
private:
  Truckload m_truckload;
  
  std::vector<Callback> m_callbacks;
};
