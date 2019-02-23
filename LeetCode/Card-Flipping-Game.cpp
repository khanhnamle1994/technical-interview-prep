/* On a table are N cards, with a positive integer printed on the front and back of each card (possibly different).

We flip any number of cards, and after we choose one card.

If the number X on the back of the chosen card is not on the front of any card, then this number X is good.

What is the smallest number that is good?  If no number is good, output 0.

Here, fronts[i] and backs[i] represent the number on the front and back of card i.

A flip swaps the front and back numbers, so the value on the front is now on the back and vice versa.

Example:
Input: fronts = [1,2,4,4,7], backs = [1,3,4,1,3]
Output: 2
Explanation: If we flip the second card, the fronts are [1,3,4,4,7] and the backs are [1,2,4,1,3].
We choose the second card, which has number 2 on the back, and it isn't on the front of any card, so 2 is good. */

int flipgame(vector<int>& fronts, vector<int>& backs) {
    int a[2001]={0};
    for(int i=0;i<fronts.size();i++)
    {
        if(fronts[i]==backs[i])
        {
            a[fronts[i]]=2;


        }
        if(a[fronts[i]]!=2)
        {
          a[fronts[i]]=1;


        }
           if(a[backs[i]]!=2)
        {
          a[backs[i]]=1;


        }



    }
    for(int i=0;i<2001;i++)
    {
        if(a[i]==1)
            return i;


    }
    return 0;
}
