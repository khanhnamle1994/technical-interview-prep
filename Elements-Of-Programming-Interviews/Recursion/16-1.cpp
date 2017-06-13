// A peg contains rings in sorted order, with the largest ring being the lowest. You are to transfer these rings to another peg, which is
// initially empty. Write a program which prints a sequence of operations that transfers n rings from one peg to another. You have a 3rd peg,
// which is initially empty. The only operation you can perform is taking a single ring from the top of one peg and placing it on the top of
// another peg. You must never place a larger ring above a smaller ring.

const int kNumPegs = 3;

void ComputeTowerHanoi(int num_rings) {
  array<stack<int>, kNumPegs> pegs;
  // Initialize pegs
  for(int i = num_rings; i >= 1; i--) {
    pegs[0].push(i);
  }
  ComputeTowerHanoiSteps(num_rings, pegs, 0, 1, 2);
}

void ComputeTowerHanoiSteps(int num_rings_to_move, array<stack<int>, kNumPegs>& pegs, int from_peg, int to_peg, int use_peg) {
  if(num_rings_to_move > 0) {
    ComputeTowerHanoiSteps(num_rings_to_move - 1, pegs, from_peg, use_peg, to_peg);
    pegs[to_peg].push(pegs[from_peg].top());
    pegs[from_peg].pop();
    cout << "Move from peg " << from_peg << " to peg " << to_peg << endl;
    ComputeTowerHanoiSteps(num_rings_to_move - 1, pegs, use_peg, to_peg, from_peg);
  }
}
