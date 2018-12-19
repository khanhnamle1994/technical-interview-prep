/* Given the running logs of n functions that are executed in a nonpreemptive single threaded CPU, find the exclusive time of these functions.

Each function has a unique id, start from 0 to n-1. A function may be called recursively or by another function.

A log is a string has this format : function_id:start_or_end:timestamp. For example, "0:start:0" means function 0 starts from the very beginning of time 0. "0:end:0" means function 0 ends to the very end of time 0.

Exclusive time of a function is defined as the time spent within this function, the time spent by calling other functions should not be considered as this function's exclusive time. You should return the exclusive time of each function sorted by their function id.

Example 1:
Input:
n = 2
logs =
["0:start:0",
 "1:start:2",
 "1:end:5",
 "0:end:6"]

Output:[3, 4]

Explanation:
Function 0 starts at time 0, then it executes 2 units of time and reaches the end of time 1.
Now function 0 calls function 1, function 1 starts at time 2, executes 4 units of time and end at time 5.
Function 0 is running again at time 6, and also end at the time 6, thus executes 1 unit of time.
So function 0 totally execute 2 + 1 = 3 units of time, and function 1 totally execute 4 units of time. */

struct Log {
    int id;
    string status;
    int timestamp;
};

vector<int> exclusiveTime(int n, vector<string>& logs) {
  vector<int> times(n, 0);
  stack<Log> st;
  for(string log: logs) {
      stringstream ss(log);
      string temp, temp2, temp3;
      getline(ss, temp, ':');
      getline(ss, temp2, ':');
      getline(ss, temp3, ':');

      Log item = {stoi(temp), temp2, stoi(temp3)};
      if(item.status == "start") {
          st.push(item);
      } else {
          assert(st.top().id == item.id);

          int time_added = item.timestamp - st.top().timestamp + 1;
          times[item.id] += time_added;
          st.pop();

          if(!st.empty()) {
              assert(st.top().status == "start");
              times[st.top().id] -= time_added;
          }
      }
  }

  return times;
}
