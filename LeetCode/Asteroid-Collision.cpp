/* We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

Example 1:
Input:
asteroids = [5, 10, -5]
Output: [5, 10]
Explanation:
The 10 and -5 collide resulting in 10.  The 5 and 10 never collide.

Example 2:
Input:
asteroids = [8, -8]
Output: []
Explanation:
The 8 and -8 collide exploding each other.

Example 3:
Input:
asteroids = [10, 2, -5]
Output: [10]
Explanation:
The 2 and -5 collide resulting in -5.  The 10 and -5 collide resulting in 10.

Example 4:
Input:
asteroids = [-2, -1, 1, 2]
Output: [-2, -1, 1, 2]
Explanation:
The -2 and -1 are moving left, while the 1 and 2 are moving right.
Asteroids moving the same direction never meet, so no asteroids will meet each other. */

void reverse_stck(stack<int>& st){
    if(st.empty()) return;
    queue<int> newq;
    while(!st.empty()){newq.push(st.top());st.pop();}
    while(!newq.empty()){st.push(newq.front());newq.pop();}
}

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> pos;
    stack<int> neg;

    for(int i=0;i<asteroids.size();i++){
        int flag=0; // to retain info on asteroids were of same size or no
        if(asteroids[i]>0) pos.push(asteroids[i]);
        else if(asteroids[i]<0){
            while(!pos.empty()){
                if(abs(asteroids[i])>pos.top()) pos.pop();
                else if(abs(asteroids[i])==pos.top()){pos.pop();flag=1;break;}
                else if(abs(asteroids[i])<pos.top()) break;
            }
            if(pos.empty() && flag==0) neg.push(asteroids[i]);
        }
    }
    vector<int> ans;
    reverse_stck(pos);
    reverse_stck(neg);
    while(!neg.empty()){ans.push_back(neg.top());neg.pop();}
    while(!pos.empty()){ans.push_back(pos.top());pos.pop();}

    return ans;
}
