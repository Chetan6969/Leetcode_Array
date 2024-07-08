class Solution {
public:
    int passThePillow(int n, int time) {
        
        int currentPerson = 1;
        
        bool forward = true;

        for (int t = 0; t < time; ++t) {
            if (forward) {
               
                currentPerson++;
                
                if (currentPerson == n) {
                    forward = false;
                }
            } else {
              
                currentPerson--;
                
                if (currentPerson == 1) {
                    forward = true;
                }
            }
        }

        return currentPerson;
    }
};