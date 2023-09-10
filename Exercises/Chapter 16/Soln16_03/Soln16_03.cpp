// Using exceptions to signal index-out-of-bounds errors.
import std;
import truckload;
import box.random;

int main()
{
  Truckload load;
  const std::size_t boxCount {20};   // Number of Box object to be created

  // Create boxCount Box objects
  for (std::size_t i {}; i < boxCount; ++i)
    load.addBox(randomSharedBox());

  try
  {
    std::println("The truckload contains the following boxes: ");
    for (std::size_t i {}; i < 100; ++i)
    {
	    std::println("{}", to_string(*load[i]));
    }
  }
  catch (const std::exception& caughtException)
  {
    std::println("Oops: {}", caughtException.what());
  }
}
