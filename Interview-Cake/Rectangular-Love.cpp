// A crack team of love scientists from OkEros (a hot new dating site) have devised a way to represent dating profiles as rectangles on a
// two-dimensional plane.

// They need help writing an algorithm to find the intersection of two users' love rectangles. They suspect finding that intersection is
// the key to a matching algorithm so powerful it will cause an immediate acquisition by Google or Facebook or Obama or something.

// Write a function to find the rectangular intersection of two given love rectangles.

// As with the example above, love rectangles are always "straight" and never "diagonal." More rigorously: each side is parallel with
// either the x-axis or the y-axis.

// They are defined as instances of the Rectangle class:
class Rectangle
{
private:
  // coordinates of bottom left corner
  int leftX_;
  int bottomY_;

  // dimensions
  int width_;
  int height_;

public:
  Rectangle() :
      leftX_(0),
      bottomY_(0),
      width_(0),
      height_(0)
  {
  }

  Rectangle(int leftX, int bottomY, int width, int height) :
      leftX_(leftX),
      bottomY_(bottomY),
      width_(width),
      height_(height)
  {
  }

  int getLeftX() const
  {
      return  leftX_;
  }

  int getBottomY() const
  {
      return  bottomY_;
  }

  int getWidth() const
  {
      return  width_;
  }

  int getHeight() const
  {
      return  height_;
  }

  bool operator==(const Rectangle& other) const
  {
      return
          leftX_ == other.leftX_
          && bottomY_ == other.bottomY_
          && width_ == other.width_
          && height_ == other.height_;
  }

  bool operator!=(const Rectangle& other) const
  {
      return !(*this == other);
  }
};

/* Solution:

We divide the problem into two halves:
1 - The intersection along the x-axis
2 - The intersection along the y-axis

Both problems are basically the same as finding the intersection of two "ranges" on a 1-dimensional number line.

So we write a helper function findRangeOverlap() that can be used to find both the x overlap and the y overlap, and we use it to build
the rectangular overlap: */

class RangeOverlap
{
private:
  int startPoint_;
  int length_;

public:
  RangeOverlap() :
      startPoint_(0),
      length_(0)
  {
  }

  RangeOverlap(int startPoint, int width) :
      startPoint_(startPoint),
      length_(width)
  {
  }

  int getStartPoint() const
  {
      return startPoint_;
  }

  int getLength() const
  {
      return length_;
  }

  bool overlapExists() const
  {
      return length_ > 0;
  }

  bool operator==(const RangeOverlap& other) const
  {
      return
          startPoint_ == other.startPoint_
          && length_ == other.length_;
  }

  bool operator!=(const RangeOverlap& other) const
  {
      return !(*this == other);
  }
};

RangeOverlap findRangeOverlap(int point1, int length1, int point2, int length2)
{
  // find the highest start point and lowest end point.
  // the highest ("rightmost" or "upmost") start point is
  // the start point of the overlap.
  // the lowest end point is the end point of the overlap.
  int highestStartPoint = max(point1, point2);
  int lowestEndPoint = min(point1 + length1, point2 + length2);

  // return null overlap if there is no overlap
  if (highestStartPoint >= lowestEndPoint) {
      return RangeOverlap();
  }

  // compute the overlap length
  int overlapLength = lowestEndPoint - highestStartPoint;

  return RangeOverlap(highestStartPoint, overlapLength);
}

Rectangle findRectangularOverlap(
      const Rectangle& rect1,
      const Rectangle& rect2)
{

  // get the x overlap points and lengths
  RangeOverlap xOverlap = findRangeOverlap(
          rect1.getLeftX(), rect1.getWidth(),
          rect2.getLeftX(), rect2.getWidth());

  // get the y overlap points and lengths
  RangeOverlap yOverlap = findRangeOverlap(
          rect1.getBottomY(), rect1.getHeight(),
          rect2.getBottomY(), rect2.getHeight());

  // return "default" rectangle if there is no overlap
  if (!xOverlap.overlapExists() || !yOverlap.overlapExists()) {
      return Rectangle();
  }

  return Rectangle(
      xOverlap.getStartPoint(),
      yOverlap.getStartPoint(),
      xOverlap.getLength(),
      yOverlap.getLength()
  );
}

// Complexity
// O(1) time and O(1) space.
