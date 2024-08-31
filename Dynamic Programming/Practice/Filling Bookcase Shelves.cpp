/*imp question 
approach 1 solve using recursion but give TLE
*/
class Solution {
public:
    //index is pointed to book with we have to put in shelf 
    //we always have to put the book inthe shelf in order
    // but we have option to put book in current shelf level to next shelf level(all books width is <=shelfWidth)
    //we can't rotate the books
    int n;
    int shW;

    //remainWidth pointed to the remaining wdith we have on that shelf level 
    //maxHeight is maximum height we have at that shelf level
    int solve(vector<vector<int>>& books,int index,int remainWidth,int maxHeight) {
        if(index>=n) {
            return maxHeight;
        }
        int keep=INT_MAX;
        int skip=INT_MAX;
        int bookH=books[index][1];
        int bookW=books[index][0];
        if(bookW<=remainWidth) {
            //here we put book in current shelf level 
            keep=solve(books,index+1,remainWidth-bookW,max(bookH,maxHeight));
        }
        //we put in next level
        //to put in next level we make shW-bookW means in new level we put the book
        //and because in new level their only one book so maxHeight=bookH
        skip=maxHeight+solve(books,index+1,shW-bookW,bookH);
        return min(keep,skip);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n=books.size();
        shW=shelfWidth;
        int ans=solve(books,0,shelfWidth,0);
        return ans;
    }
};
/*using memoization*/
class Solution {
public:
    //index is pointed to book with we have to put in shelf 
    //we always have to put the book inthe shelf in order
    // but we have option to put book in current shelf level to next shelf level(all books width is <=shelfWidth)
    //we can't rotate the books
    int n;
    int shW;
    int dp[1001][1001];
    //remainWidth pointed to the remaining wdith we have on that shelf level 
    //maxHeight is maximum height we have at that shelf level
    int solveMemo(vector<vector<int>>& books,int index,int remainWidth,int maxHeight) {
        if(index>=n) {
            return maxHeight;
        }
        if(dp[index][remainWidth]!=-1) {
            return dp[index][remainWidth];
        }
        int keep=INT_MAX;
        int skip=INT_MAX;
        int bookH=books[index][1];
        int bookW=books[index][0];
        if(bookW<=remainWidth) {
            //here we put book in current shelf level 
            keep=solveMemo(books,index+1,remainWidth-bookW,max(bookH,maxHeight));
        }
        //we put in next level
        //to put in next level we make shW-bookW means in new level we put the book
        //and because in new level their only one book so maxHeight=bookH
        skip=maxHeight+solveMemo(books,index+1,shW-bookW,bookH);
        return dp[index][remainWidth]= min(keep,skip);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n=books.size();
        memset(dp,-1,sizeof(dp));
        shW=shelfWidth;
        int ans=solveMemo(books,0,shelfWidth,0);
        return ans;
    }
};