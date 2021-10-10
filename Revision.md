# Quick Revision

1. GFG Must Do Questions

2. Generics Algorithms
    1. Matric Chain Multiplication
    2. Knap Sack
        1. Fractional KnapSack  : Choose Elements with Highest Profit/Weight
        2. 01 KnapSack          : Form a No of Objects x Weight os Object Table
        3. Unbounded KnapSack   : Form a 1 x W table, run a nested loop checking for each object
        <details>
            <summary>Click To Expand</summary>
            
            ```
            for (int i=0; i<=W; i++){
                for (int j=0; j<n; j++){
                    if (wt[j] <= i) dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);
                    }
                }
            ```
        </details>

    3. Job Sequencing           : Sort the Jobs According to the decreasing order of their profits and then sequence the Job at the latest time slot available(before it's deadline and in an then available slot).

    *Assumption : All the Jobs take the same amount of time.*

    4. Optimal Merge Pattern    : Sort the list according to their lengths, merge two smallest list and form another list and once again place it in the overall list, again choose two smallest lists and repeat the process.
    
    **Question:** Merge multiple lists of elements such that the total time taken to complete the Job is minimum.

    *Why This Works : The sorting of lists according to sizes makes the larger lists add the minimum number of times.*

    5. Activity Selection       : Sort the Jobs according to the increasing order of their end time, choose the Job which finishes the first and then move onto the Next.

    
3. Good Questions
    1.  Find Median of 2 Sorted Arrays
    2.  2 Sum, 3 Sum and 4 Sum 
    3.  Reverse a Linked List
    4.  Search In Matrix
    5.  LRU Page Faults             : Vector.erase(iterator) can be used to simplify the approach
    6.  Minimize Height             : Don't Do All the Calculations, Look for Answer instead
    7.  Egg Dropping Puzzle         : Don't Do All the Calculations, Look for Answer instead
    8.  Find Missing & Repeating    : Interesting Answer Approach
    9.  Max Index                   : Sliding Window Variation
    10. Triplet With Sum in Range   : Think of Alternate Aporach if original Approach Fails.
    11. Number Of Islands           : Remember Question's done before not their difficulty, it overwhelms. 
    12. GFG Covid Spread            : Approach might be correct but COde might fail, in this case quickly try the same approach by a different DataStructure or Fresh Code, if that fails too skip the Question and come back to it later.
    13. PreReq Tasks GFG Must Do    :
    14. Jump Game 2 Leet Code       : Sometimes Greedy Aproach is better than DP, Remember similar questions sometime distract from actual approach as we are struck with a totally wrong approach because of percieved familiarity.
    15. Merge Intervals Leet Code
    16. Gray Code Leet Code         : The Gray code has the feature of a single bit switch between consecutive numbers, it also has the added benifit of a difference of 2^itr in the reverse order of traversal of current list.
    17. Declare a comparaotr for Set: 

```
struct comparator{
    bool operator()(const vector<int>&v1,const vector<int>&v2) const{
        // Code
    }
};
```

4. Theory Topics                : MySQL

5. Other Topics
    1. Huffman Coding           : Switch ASCII codes with self codes that one can build using a Huffman Tree, since not al ASCII codes are used in our file.

    2. Prims & Kruskal Algorithm: A Min-Spanning Tree is a subset of a graph such that all the vertices are present in it but with only |N| - 1 edges.

    Thus there will will |E| C |N|-1.

    Prims   : Select the Min Edge and Repeat |N| - 1 times to add connected edges with min weights such that a new vertex is added.

    Kruskal : Select the Min Ege which is not making a cycle, Repeat.

    3. Source Shortest Path     : A way to find the Min path rom source vertex to all other vertex.
        1. Dijikstra Algorithm  : Initially distance to all vertex except the source is set to Infinity while source will ofcourse be zero. Later we all connected vertex and update their distance to the Min(Original Distance, New Connected Vertex + WT of Edge), Repeat.
        2. Bellman Ford Algo    : Repeat for |N| - 1 time, Relax all vertices


            |Bellman Fords|Dijikstra|
            |:---|:---|
            |Works for Negative Edge Weights|Doesn't work for Negative Edge Weight|
            |Dynamic Programming|Greedy Approach|
            |O(V * E)|O(E * log V)|

    4. String Pattern Matching  :
        1. Naive Algo           : A simple nested look. *i will shift back to original i + 1 in case of mis-match*.
                                : O(m * n)
        2. KMP Algorithm        : Prepare a PI table to show the position of preffix that appears sometime before in same string, in case of mismatch fall back to last prefix instead of initial position + 1.
                                : O(n)
        3. Rabin Karp Algo      : Convert the pattern into a hash code, save the length of the pattern and run a loop over the String taking the previously saved number of characters at a time and use that to create and another hash, now compare this hash with the hash of the pattern, continuously add the new character into the hash while removing the previous first one and continue to compare hash until a match is found, when the hash matches, make sure to check the entire pattern then.
                                : O(n - m + 1)

6. Note To Self     :       Always check the Return Type, might be using long over int.

7. Aditya Verma     :

    1. Stack PLaylist : **When we are using a Nested Loop, and the j of the second loop is dependent on the i of first loop, then one must think of somehow implementing the Stack.**

        1. Nearest Greater To Left
        2. Nearest Greater To Right : Next Largest Element  : Declare a Stack, Traverse the Array from Right To Left, Check in every turn of loop to see if the element in the stack is greater than the given element, if the stack gets empty without filling the result then put a -1 in it. Finally push the current element into the Stack.

        3. Nearest Smallest To Left : Next Smallest Element
        4. Nearest Smallest To Right

        5. Stock Span Problem       : Save the index of the Greatest element to the left instead of the element itself and use it to calculate the Span of Stocks.
        6. Maximum Area of Histogram: Find the inndex of Nearest Smallest to Left and Nearest Smallest to Right element use the Current Height and the difference in the Span as Width to calculate the Area of Histogram and Maximize it over the Array.

        7. Max Area of Rectangle in Binary Matrix : Traverse through the Matrix to compress the 2-D matrix into the 1-D matrix form by adding the value of 1 level above, the end send the current 1-D matrix to the MAH function made above.

        8. Rain Water Trapping      : First calculate the height of the Greatest building to the Left and Right, their Minima will be the level of water in that region, then subtract the current height of building from the level and add this to the result which was initially Zero.

        9. Implementation of Min Stack : 
        
        With Extra Space    : Use two stack one contains all elements, while the supporting stack will hold elements that are smallest.
        No Extra Space      : Use a variable to save the min element, we will use the Stack for 2 functions, one to store the elements, other to put a flag on when the minEle turns and what it will be.

        ```
        int top(){
            if(s.size() == 0) return -1;

            if(s.top() >= minEle) return s.top();
            else return minEle;
        }

        void pop(){
            if(s.size() == 0) return -1;

            if(s.top() >= minEle) s.pop();
            else{
                minEle = 2 * minEle - s.top();
                s.pop();
            }
        }

        void push(int x){
            if(s.size() == 0){
                s.push(x);
                minEle = x;
            }
            else{
                if(x >= minEle) s.push(x);
                else{
                    s.push(2 * x - minEle);
                    minEle = x;
                }
            }
        }

        ```

        10. Stack using Heap
        11. Celebrity Problem
        12. Longest Valid Palindrome
        13. Iterative TOH

    2. Heap
        1. Heap Introduction and Identification: Condition regarding a variable K, Smallest/Largest them the Question is of Heap

        Space Complexity : O(K)
        Time Complexity  : O(N log K)

        2. 