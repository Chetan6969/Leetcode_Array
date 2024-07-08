class Solution {
public:
    int findTheWinner(int n, int k) {
        return josephus(n, k) + 1; // Adding 1 to convert from 0-based to 1-based indexing
    }
    
private:
    int josephus(int n, int k) {
        if (n == 1) {
            return 0; // Base case: if there is only one person, they are the winner
        } else {
            // The position returned by josephus(n - 1, k) is adjusted because the 
            // recursive call josephus(n - 1, k) considers the original position 
            // of the survivor when there are n-1 people.
            return (josephus(n - 1, k) + k) % n;
        }
    }
};