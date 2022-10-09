export module truckload:shared_box;

import std;
import box;

export using SharedBox = std::shared_ptr<Box>;
