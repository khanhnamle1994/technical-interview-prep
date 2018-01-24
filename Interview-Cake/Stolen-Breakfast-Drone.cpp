// Your company delivers breakfast via autonomous quadcopter drones. And something mysterious has happened.

// Each breakfast delivery is assigned a unique ID, a positive integer. When one of the company's 100 drones takes off with a delivery, the delivery's
// ID is added to a vector, deliveryIdConfirmations. When the drone comes back and lands, the ID is again added to the same vector.

// After breakfast this morning there were only 99 drones on the tarmac. One of the drones never made it back from a delivery. We suspect a secret
// agent from Amazon placed an order and stole one of our patented drones. To track them down, we need to find their delivery ID.

// Given the vector of IDs, which contains many duplicate integers and one unique integer, find the unique integer.

// Solution
// We XOR all the integers in the vector. We start with a variable uniqueDeliveryId set to 0. Every time we XOR with a new ID, it will change the bits.
// When we XOR with the same ID again, it will cancel out the earlier change.

// In the end, we'll be left with the ID that appeared once!

int findUniqueDeliveryId(const vector<int>& deliveryIds)
{
  int uniqueDeliveryId = 0;

  for (int deliveryId : deliveryIds) {
      uniqueDeliveryId ^= deliveryId;
  }

  return uniqueDeliveryId;
}

// Complexity
// O(n) time, and O(1) space
