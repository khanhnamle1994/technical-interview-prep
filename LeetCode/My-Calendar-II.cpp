/* Implement a MyCalendarTwo class to store your events. A new event can be added if adding the event will not cause a triple booking.

Your class will have one method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end), the range of real numbers x such that start <= x < end.

A triple booking happens when three events have some non-empty intersection (ie., there is some time that is common to all 3 events.)

For each call to the method MyCalendar.book, return true if the event can be added to the calendar successfully without causing a triple booking. Otherwise, return false and do not add the event to the calendar.

Your class will be called like this: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)

Example 1:
MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(50, 60); // returns true
MyCalendar.book(10, 40); // returns true
MyCalendar.book(5, 15); // returns false
MyCalendar.book(5, 10); // returns true
MyCalendar.book(25, 55); // returns true

Explanation:
The first two events can be booked.  The third event can be double booked.
The fourth event (5, 15) can't be booked, because it would result in a triple booking.
The fifth event (5, 10) can be booked, as it does not use time 10 which is already double booked.
The sixth event (25, 55) can be booked, as the time in [25, 40) will be double booked with the third event;
the time [40, 50) will be single booked, and the time [50, 55) will be double booked with the second event. */

set<pair<int, int>> map1;
set<pair<int, int>> map2;

MyCalendarTwo() {

}

bool book(int start, int end) {
    auto it2 = map2.lower_bound(pair<int, int>(start, start));
    // overlaps with intervals with 2 bookings
    if(it2 != map2.end() && it2->second < end)
        return false;

    auto it = map1.lower_bound(pair<int, int>(start, start));
    while(it != map1.end())
    {
        int s = it->second;
        int e = it->first;

        //no overlap
        if(end < s)
        {
            break;
        }else if(end == s) //adjacent interval, combine them
        {
            it = map1.erase(it);
            end = e;
        }else
        {
            // add the 2 booking intervals
            map2.insert(pair<int, int>(min(e, end), max(s, start)));
            start = min(s, start);
            end = max(e, end);
            it = map1.erase(it);

        }
    }
    map1.insert(pair<int, int>(end, start));
    return true;
}
