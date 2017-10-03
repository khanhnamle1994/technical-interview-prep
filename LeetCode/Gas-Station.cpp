// There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1).
// You begin the journey with an empty tank at one of the gas stations.

// Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  int start(0),total(0),tank(0);
  // if car fails at 'start', record the next station
  for (int i = 0; i < gas.size(); i++) {
      if( (tank = tank + gas[i] - cost[i]) <0 ) {
          start = i + 1;
          total += tank;
          tank = 0;
      }
  }
  return (total + tank < 0) ? -1 : start;
}
