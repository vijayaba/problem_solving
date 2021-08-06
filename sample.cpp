#include <numeric>
#include <iterator>
using namespace std;
typedef long long ll;
/*
Minimum Absolute Difference in an Array
Sample Input 0

3
3 -7 0

Sample Output 0

3

Explanation 0

The first line of input is the number of array elements. The array,
There are three pairs to test: 3 3, 3 -7, 3 00 , and The absolute differences are:

Remember that the order of values in the subtraction does not influence the result. The smallest of these absolute differences is .

*/
int main() {
    ll iNum; cin >> iNum;
    vector<ll> iVec, sortVec;
    copy_n(istream_iterator<ll>(cin), iNum, back_inserter(iVec));
    sort(begin(iVec),end(iVec));
    adjacent_difference(begin(iVec),end(iVec), back_inserter(sortVec));
    cout << *min_element(begin(sortVec)+1,end(sortVec));
    return 0;
}


/*
Alice and Bob each created one problem for HackerRank. A reviewer rates the two challenges, awarding points on a scale from 1 to 100 for three categories: problem clarity, originality, and difficulty.

The rating for Alice's challenge is the triplet a = (a[0], a[1], a[2]), and the rating for Bob's challenge is the triplet b = (b[0], b[1], b[2]).

The task is to find their comparison points by comparing a[0] with b[0], a[1] with b[1], and a[2] with b[2].

    If a[i] > b[i], then Alice is awarded 1 point.
    If a[i] < b[i], then Bob is awarded 1 point.
    If a[i] = b[i], then neither person receives a point.

Comparison points is the total points a person earned.

Given a and b, determine their respective comparison points. 

Sample Input 0

5 6 7
3 6 10

Sample Output 0

1 1



In this example:
A[3] = 5 6 7
B[3] 3 6 10 
Now, let's compare each individual score:

A[0] > B[0], so Alice receives 1 point.
A[0] = B[0], so nobody receives a point.
A[0] < B[0], so Bob receives 1    point.

Alice's comparison score is 1, and Bob's comparison score is 1. Thus, we return the array . [1, 1]
*/
int main(){
    vector<int> iVec, iVec2;
    copy_n(istream_iterator<int>(cin), 3, back_inserter(iVec)); 
    copy_n(istream_iterator<int>(cin), 3, back_inserter(iVec2));
    cout << 
        inner_product(begin(iVec),end(iVec),begin(iVec2),0,[](int i, int j){return i+j;},[](int i, int j){return i>j;})
        << ' ' << 
        inner_product(begin(iVec),end(iVec),begin(iVec2),0,[](int i, int j){return i+j;},[](int i, int j){return i<j;});
	return 0;
}

inner_product accumulates with initial value - here 0. binary op1 is accumulator, binary_op2 provides to op1 what to accumulate. the above is equivalent to
        inner_product(begin(iVec),end(iVec),begin(iVec2),0,std::plus<>(),std::greater<>()/*ret 1 if a[i]>b[i]*/});
		inner_product(begin(iVec),end(iVec),begin(iVec2),0,std::plus<>(),std::less<00>()/*ret 1 if a[i]>b[i]*/});
		








//LRUCache
// We can use stl container list as a double
// ended queue to store the cache keys, with
// the descending time of reference from front
// to back and a set container to check presence
// of a key. But to fetch the address of the key
// in the list using find(), it takes O(N) time.
// This can be optimized by storing a reference
//	 (iterator) to each key in a hash map.
#include <bits/stdc++.h>
using namespace std;

class LRUCache {
	// store keys of cache
	list<int> dq; //( cache it self)

	// store references of key in cache ( to check if the ele is present in cache or not, because looking up in map is easier than list)
	unordered_map<int, list<int>::iterator> ma;
	int csize; // maximum capacity of cache

public:
	LRUCache(int);
	void set(int);
	void display();
};

// Declare the size
LRUCache::LRUCache(int n)
{
	csize = n;
}

// Refers key x with in the LRU cache
void LRUCache::set(int x)
{
	// not present in cache
	if (ma.find(x) == ma.end()) {
		// cache is full
		if (dq.size() == csize) {
			// delete least recently used element
			int last = dq.back();

			// Pops the last elmeent
			dq.pop_back();

			// Erase the last
			ma.erase(last);
		}
	}

	// present in cache
	else
		dq.erase(ma[x]);

	// update reference
	dq.push_front(x);
	ma[x] = dq.begin();
}

// Function to display contents of cache
void LRUCache::display()
{

	// Iterate in the deque and print
	// all the elements in it
	for (auto i : dq)
		cout << i << " ";

	cout << endl;
}

// Driver Code
int main()
{
	LRUCache ca(4);

	ca.set(1);
	ca.set(2);
	ca.set(3);
	ca.set(1);
	ca.set(4);
	ca.set(5);
	ca.display();

	return 0;
}


// reverse linked list
    void reverse()
    {
        // Initialize current, previous and
        // next pointers
        Node* current = head;
        Node *prev = NULL, *next = NULL;

        while (current != NULL) {
            // Store next
            next = current->next;

            // Reverse current node's pointer
            current->next = prev;

            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }
	
//find middle
/*
Given a singly linked list, find the middle of the linked list. For example, if the given linked list is 1->2->3->4->5 then the output should be 3. 
If there are even nodes, then there would be two middle nodes, we need to print the second middle element. For example, if given linked list is 1->2->3->4->5->6 then the output should be 4. 


Method 1: 
Traverse the whole linked list and count the no. of nodes. Now traverse the list again till count/2 and return the node at count/2. 



Method 2: 
Traverse linked list using two pointers. Move one pointer by one and the other pointers by two. When the fast pointer reaches the end slow pointer will reach the middle of the linked list.
*/
    void printMiddle(class Node *head){
        struct Node *slow_ptr = head;
        struct Node *fast_ptr = head;
 
        if (head!=NULL)
        {
            while (fast_ptr != NULL && fast_ptr->next != NULL)
            {
                fast_ptr = fast_ptr->next->next;
                slow_ptr = slow_ptr->next;
            }
            cout << "The middle element is [" << slow_ptr->data << "]" << endl;
        }
    }	
	
 //second method
void printMiddle(class Node *head)
{ 
   int count = 0;
   Node* current = head;
   while(current != nullptr)
   {
       count++;
       current = current->next;
   }
   int middle = count/2;
   current = head;
   while(middle--)
   {
       current = current->next;
   }
   return current->data;
}


/*
METHOD 1 (Use a Stack) 

    A simple solution is to use a stack of list nodes. This mainly involves three steps.
    Traverse the given list from head to tail and push every visited node to stack.
    Traverse the list again. For every visited node, pop a node from the stack and compare data of popped node with the currently visited node.
    If all nodes matched, then return true, else false.
	
METHOD 2

    Get the middle of the linked list. 
    Reverse the second half of the linked list. 
    Check if the first half and second half are identical. 
    Construct the original linked list by reversing the second half again and attaching it back to the first half
    Return 1 if list is palindrome else 0.

 	
*/

 bool isPalindrome(Node *head)
    {
        //push items to the stack
        stack<int> st;
        Node* current = head;
        while(current != nullptr)
        {
            st.push(current->data);
            current = current->next;
        }
        current = head;
        while( current != nullptr)
        {
            if(current->data == st.top())
            {
                st.pop();
                current = current->next;
            }
            else
            {
                return 0;
            }
        }
        return 1;
    }   
/*
Finding a loop in linked list
Solution 1: Hashing Approach:

Traverse the list one by one and keep putting the node addresses in a Hash Table. At any point, if NULL is reached then return false, and if the next of the current nodes points to any of the previously stored nodes in  Hash then return true.
    Time complexity: O(n). 
    Only one traversal of the loop is needed.
    Auxiliary Space: O(n). 
    n is the space required to store the value in hashmap.


Solution 2: This problem can be solved without hashmap by modifying the linked list data structure. 
Approach: This solution requires modifications to the basic linked list data structure. 

    Have a visited flag with each node.
    Traverse the linked list and keep marking visited nodes.
    If you see a visited node again then there is a loop. This solution works in O(n) but requires additional information with each node.
    A variation of this solution that doesn't require modification to basic data structure can be implemented using a hash, just store the addresses of visited nodes in a hash and if you see an address that already exists in hash then there is a loop.
    Time complexity:O(n). 
    Only one traversal of the loop is needed.
    Auxiliary Space:O(1). 
    No extra space is needed.
	
Solution 3: Floyd's Cycle-Finding Algorithm 
Approach: This is the fastest method and has been described below:  

    Traverse linked list using two pointers.
    Move one pointer(slow_p) by one and another pointer(fast_p) by two.
    If these pointers meet at the same node then there is a loop. If pointers do not meet then linked list doesn't have a loop	
	Time complexity: O(n). 
	Only one traversal of the loop is needed.
	Auxiliary Space:O(1). 
	There is no space required

Solution 4: Marking visited nodes without modifying the linked list data structure 
In this method, a temporary node is created. The next pointer of each node that is traversed is made to point to this temporary node. This way we are using the next pointer of a node as a flag to indicate whether the node has been traversed or not. Every node is checked to see if the next is pointing to a temporary node or not. In the case of the first node of the loop, the second time we traverse it this condition will be true, hence we find that loop exists. If we come across a node that points to null then the loop doesn’t exist.
    Time complexity: O(n). 
    Only one traversal of the loop is needed.
    Auxiliary Space: O(1). 
    There is no space required.
	
Solution 5: Store lengtH
In this method, two pointers are created, first (always points to head) and last. Each time the last pointer moves we calculate no of nodes in between first and last and check whether the current no of nodes > previous no of nodes, if yes we proceed by moving last pointer else it means we’ve reached the end of the loop, so we return output accordingly.
	
This is the simplest approach of the given problem, the only thing we have to do is to assign a new value to each data of node in the linked list which is not in the range given.
for ex: assign -1 as data to all the visited node, if  you see a node with value -1 , then   you have a cycle.	
*/
int detectLoop(Node* list)
{
    Node *slow_p = list, *fast_p = list;

    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            return 1;
        }
    }
    return 0;
}

/*returns distance between first and last node every time
 * last node moves forwars*/
int distance(Node* first, Node* last)
{
    /*counts no of nodes between first and last*/
    int counter = 0;
 
    Node* curr;
    curr = first;
 
    while (curr != last) {
        counter += 1;
        curr = curr->next;
    }
 
    return counter + 1;
}
 
 
/* delete substr from string */

std::string t = "Banana Republic";
std::string s = "nana";

//note find returns start position of s
std::string::size_type i = t.find(s);

if (i != std::string::npos)
   t.erase(i, s.length());



/* find matching brackets

1. using stack
	push open brackets on to stack, when you see close bracketes, check if the top has matching open brackets, if so pop. (if not ret false) at end if the stack is empty, all bracketes are matched ret ture.
2. using string replace
	start by erasing () {} []  substr. at the end if the str is empty, all the brkts are matched. else ret false
*/

void checkBrkts1(string str)
{
    stack<char> s;
    for(char c : str)
    {
        if (c == '(' ||
            c == '{' ||
            c == '[')
        {
            s.push(c);     
        }
        else
        {
            if(!s.empty())
            {
                char top = s.top();
                if((top == '(' && c ==')') ||
                (top == '[' && c ==']') ||
                (top == '{' && c =='}') )
                {
                    s.pop();
                }
                else
                {
                cout << "NO" << endl;
                return;
                }
            }
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
    
    }
    if(s.empty())
         cout << "YES" << endl;
    else
         cout << "NO" << endl;
         
    return;
}

void checkBrkts2(string str)
{
    int prev_size = -1;
    string sq = "[]";
    string pa = "()";
    string f  = "{}";
	string::size_type  i;
    while ((int) str.size()!= prev_size)
    {
        prev_size = str.size();
		
        i = str.find(sq);
		if( i != string::npos) 	{ str.erase(i,sq.size());}
		  i = str.find(pa);
		if( i != string::npos)  { str.erase(i,pa.size());}
		  i = str.find(f); 
		if( i != string::npos)  { str.erase(i,f.size());}
		
    }
    
    if ((int)str.size()==0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return;
}

// Function to calculate height of tree
int treeHeight(Node *root){
	if(!root) return 0;
	int lHeight = treeHeight(root->left);
	int rHeight = treeHeight(root->right);
	return max(lHeight, rHeight) + 1;
}

// Helper Function to store the zig zag order traversal
// of tree in a list recursively. 
//Note, height is very important here. it stop the recursion from going to next level
//Time Complexity: Worst case time complexity of the above method is O(n^2). Worst case occurs in case of skewed trees.
void zigZagTraversalRecursion(Node* root, int height, bool lor, vector<int> &ans){
	// Height = 1 means the tree now has only one node
	if(height <= 1){
		if(root) ans.push_back(root->data);
	}
	// When Height > 1
	else{
		if(lor){
			if(root->left) zigZagTraversalRecursion(root->left, height - 1, lor, ans);
			if(root->right) zigZagTraversalRecursion(root->right, height - 1, lor, ans);
		}
		else{
			if(root->right) zigZagTraversalRecursion(root->right, height - 1, lor, ans);
			if(root->left) zigZagTraversalRecursion(root->left, height - 1, lor, ans);
		}
	}
}
//

// Function to traverse tree in zig zag order
vector <int> zigZagTraversal(Node* root)
{
	vector<int> ans;
	bool leftOrRight = true;
	int height = treeHeight(root);
	for(int i = 1; i <= height; i++){
		zigZagTraversalRecursion(root, i, leftOrRight, ans);
		leftOrRight = !leftOrRight;
		cout <<"ans at level " << i << "\n";
		for(auto j:ans)
		    cout << j << " ";
		cout << endl;
	}
	return ans;
}
/*
Another Approach:
In this approach, use a deque to solve the problem. 
Push and pop in different ways depending on if the level is odd or level is even.
*/
// Function to print the zigzag traversal
vector<int> zigZagTraversal(Node* root)
{
    deque<Node*> q;
    vector<int> v;
    q.push_back(root);
    v.push_back(root->data);
    Node* temp;
   
    // set initial level as 1, because root is
    // already been taken care of.
    int l = 1;
                
    while (!q.empty()) {
        int n = q.size();
 
        for (int i = 0; i < n; i++) {
 
            // popping mechanism
            if (l % 2 == 0) {
                temp = q.back();
                q.pop_back();
            }
            else {
                temp = q.front();
                q.pop_front();
            }
 
            // pushing mechanism
            if (l % 2 != 0) {
 
                if (temp->right) {
                    q.push_back(temp->right);
                    v.push_back(temp->right->data);
                }
                if (temp->left) {
                    q.push_back(temp->left);
                    v.push_back(temp->left->data);
                }
            }
            else if (l % 2 == 0) {
 
                if (temp->left) {
                    q.push_front(temp->left);
                    v.push_back(temp->left->data);
                }
                if (temp->right) {
                    q.push_front(temp->right);
                    v.push_back(temp->right->data);
                }
            }
        }
        l++; // level plus one
    }
    return v;
}
/*
Method 2 (Iterative) 
We can print spiral order traversal in O(n) time and O(n) extra space. The idea is to use two stacks. We can use one stack for printing from left to right and other stack for printing from right to left. In every iteration, we have nodes of one level in one of the stacks. We print the nodes, and push nodes of next level in other stack. 
*/
//spiral order is same as zig zag
void printSpiral(struct node* root)
{
    if (root == NULL)
        return; // NULL check
 
    // Create two stacks to store alternate levels
    stack<struct node*> s1; // For levels to be printed from right to left
    stack<struct node*> s2; // For levels to be printed from left to right
 
    // Push first level to first stack 's1'
    s1.push(root);
 
    // Keep printing while any of the stacks has some nodes
    while (!s1.empty() || !s2.empty()) {
        // Print nodes of current level from s1 and push nodes of
        // next level to s2
        while (!s1.empty()) {
            struct node* temp = s1.top();
            s1.pop();
            cout << temp->data << " ";
 
            // Note that is right is pushed before left
            if (temp->right)
                s2.push(temp->right);
            if (temp->left)
                s2.push(temp->left);
        }
 
        // Print nodes of current level from s2 and push nodes of
        // next level to s1
        while (!s2.empty()) {
            struct node* temp = s2.top();
            s2.pop();
            cout << temp->data << " ";
 
            // Note that is left is pushed before right
            if (temp->left)
                s1.push(temp->left);
            if (temp->right)
                s1.push(temp->right);
        }
    }
}


// C++ program to find med in
// stream of running integers
#include<bits/stdc++.h>
using namespace std;

// function to calculate median of stream
void printMedians(double arr[], int n)
{
	// max heap to store the smaller half elements
	priority_queue<double> s;

	// min heap to store the greater half elements
	priority_queue<double,vector<double>,greater<double> > g;

	double med = arr[0];
	s.push(arr[0]);

	cout << med << endl;

	// reading elements of stream one by one
	/* At any time we try to make heaps balanced and
		their sizes differ by at-most 1. If heaps are
		balanced,then we declare median as average of
		min_heap_right.top() and max_heap_left.top()
		If heaps are unbalanced,then median is defined
		as the top element of heap of larger size */
	for (int i=1; i < n; i++)
	{
		double x = arr[i];

		// case1(left side heap has more elements)
		if (s.size() > g.size())
		{
			if (x < med)
			{
				g.push(s.top());
				s.pop();
				s.push(x);
			}
			else
				g.push(x);

			med = (s.top() + g.top())/2.0;
		}

		// case2(both heaps are balanced)
		else if (s.size()==g.size())
		{
			if (x < med)
			{
				s.push(x);
				med = (double)s.top();
			}
			else
			{
				g.push(x);
				med = (double)g.top();
			}
		}

		// case3(right side heap has more elements)
		else
		{
			if (x > med)
			{
				s.push(g.top());
				g.pop();
				g.push(x);
			}
			else
				s.push(x);

			med = (s.top() + g.top())/2.0;
		}

		cout << med << endl;
	}
}
/*
Given set: [1, 5, 3]

Start with an empty set: [[]]
Add the first number (1) to all the existing subsets to create new subsets: [[], [1]];
Add the second number (5) to all the existing subsets: [[], [1], [5], [1,5]];
Add the third number (3) to all the existing subsets: [[], [1], [5], [1,5], [3], [1,3], [5,3], [1,5,3]].
*/

static vector<vector<int>> findSubsets(const vector<int>& nums) {
    vector<vector<int>> subsets;
    // start by adding the empty subset
    subsets.push_back(vector<int>());
    for (auto currentNumber : nums) {
      // we will take all existing subsets and insert the current number in them to create new
      // subsets
      int n = subsets.size();
      for (int i = 0; i < n; i++) {
        // create a new subset from the existing subset and insert the current element to it
        vector<int> set(subsets[i]); //NOTE this, creat a vec(set) with vec(subset[i])
        set.push_back(currentNumber);
        subsets.push_back(set);
      }
    }
    return subsets;
  }
  
/*
Time complexity #
Since, in each step, the number of subsets doubles as we add each element to all the existing subsets, therefore, we will have a total of O(2^N)​ subsets, where ‘N’ is the total number of elements in the input set. And since we construct a new subset from an existing set, therefore, the time complexity of the above algorithm will be O(N*2^N)

Space complexity #
All the additional space used by our algorithm is for the output list. Since we will have a total of O(2^N) subsets, and each subset can take up to O(N) space, therefore, the space complexity of our algorithm will be O(N*2^N)

*/

/*
Given a set of numbers that might contain duplicates, find all of its distinct subsets
Input: [1, 5, 3, 3]
Output: [], [1], [5], [3], [1,5], [1,3], [5,3], [1,5,3], [3,3], [1,3,3], [3,3,5], [1,5,3,3] 

To handle this, we will do two extra things:

Sort all numbers of the given set. This will ensure that all duplicate numbers are next to each other.
Follow the same BFS approach but whenever we are about to process a duplicate (i.e., when the current and the previous numbers are same), instead of adding the current number (which is a duplicate) to all the existing subsets, only add it to the subsets which were created in the previous step.

Start with an empty set: [[]]
Add the first number (1) to all the existing subsets to create new subsets: [[], [1]];
Add the second number (3) to all the existing subsets: [[], [1], [3], [1,3]].
The next number (3) is a duplicate. If we add it to all existing subsets we will get:
[[], [1], [3], [1,3], [3], [1,3], [3,3], [1,3,3]]
We got two duplicate subsets: [3], [1,3]  
Whereas we only needed the new subsets: [3,3], [1,3,3]  
To handle this instead of adding (3) to all the existing subsets, we only add it to the new subsets which were created in the previous (3rd) step:
  [[], [1], [3], [1,3], [3,3], [1,3,3]]
Finally, add the forth number (5) to all the existing subsets: [[], [1], [3], [1,3], [3,3], [1,3,3], [5], [1,5], [3,5], [1,3,5], [3,3,5], [1,3,3,5]]
*/
static vector<vector<int>> findSubsets(vector<int>& nums) {
    sort(nums.begin(), nums.end());  // sort the numbers to handle duplicates
    vector<vector<int>> subsets;
    subsets.push_back(vector<int>()); //note empty subset(
    int startIndex = 0, endIndex = 0;
    for (int i = 0; i < nums.size(); i++) {
      startIndex = 0;
      // if current and the previous elements are same, create new subsets only from the subsets
      // added in the previous step
      if (i > 0 && nums[i] == nums[i - 1]) {
        startIndex = endIndex + 1;
      }
      endIndex = subsets.size() - 1;
      for (int j = startIndex; j <= endIndex; j++) {
        // create a new subset from the existing subset and add the current element to it
        vector<int> set(subsets[j]);
        set.push_back(nums[i]);
        subsets.push_back(set);
      }
    }
    return subsets;
  }
  
//implemente queue using stack
//Method 2 (By making deQueue operation costly)In this method, in en-queue operation, the new element is entered at the top of stack1. In de-queue operation, if stack2 is empty then all the elements are moved to stack2 and finally top of stack2 is returned. 
//
//enQueue(q,  x)
//  1) Push x to stack1 (assuming size of stacks is unlimited).
//Here time complexity will be O(1)
//
//deQueue(q)
//  1) If both stacks are empty then error.
//  2) If stack2 is empty
//       While stack1 is not empty, push everything from stack1 to stack2.
//  3) Pop the element from stack2 and return it.
//Here time complexity will be O(n)

struct Queue {
    stack<int> s1, s2;
 
    // Enqueue an item to the queue
    void enQueue(int x)
    {
        // Push item into the first stack
        s1.push(x);
    }
 
    // Dequeue an item from the queue
    int deQueue()
    {
        // if both stacks are empty
        if (s1.empty() && s2.empty()) {
            cout << "Q is empty";
            exit(0);
        }
 
        // if s2 is empty, move
        // elements from s1
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
 
        // return the top item from s2
        int x = s2.top();
        s2.pop();
        return x;
    }
};


//DFS graph traversal
// Graph class represents a directed graph
// using adjacency list representation
    // Time complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
    //Space Complexity: O(V). 
    //Since an extra visited array is needed of size V.
class Graph
{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::DFS(int v)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";
 
    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}
 
//BFS
// This class represents a directed graph using
// adjacency list representation
//Time Complexity: O(V+E) where V is number of vertices in the graph and E is number of edges in the graph.
class Graph
{
    int V;    // No. of vertices
 
    // Pointer to an array containing adjacency
    // lists
    list<int> *adj;  
public:
    Graph(int V);  // Constructor
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // prints BFS traversal from a given source s
    void BFS(int s); 
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

//convert binary tree to linked list

node* bintree2listUtil(node* root)
{
    // Base case
    if (root == NULL)
        return root;
 
    // Convert the left subtree and link to root
    if (root->left != NULL) {
        // Convert the left subtree
        node* left = bintree2listUtil(root->left);
 
        // Find inorder predecessor. After this loop, left
        // will point to the inorder predecessor
        for (; left->right != NULL; left = left->right)
            ;
 
        // Make root as next of the predecessor
        left->right = root;
 
        // Make predecssor as previous of root
        root->left = left;
    }
 
    // Convert the right subtree and link to root
    if (root->right != NULL) {
        // Convert the right subtree
        node* right = bintree2listUtil(root->right);
 
        // Find inorder successor. After this loop, right
        // will point to the inorder successor
        for (; right->left != NULL; right = right->left)
            ;
 
        // Make root as previous of successor
        right->left = root;
 
        // Make successor as next of root
        root->right = right;
    }
 
    return root;
}
 
// The main function that first calls
// bintree2listUtil(), then follows step 3
// of the above algorithm
node* bintree2list(node* root)
{
    // Base case
    if (root == NULL)
        return root;
 
    // Convert to DLL using bintree2listUtil()
    root = bintree2listUtil(root);
 
    // bintree2listUtil() returns root node of the converted
    // DLL. We need pointer to the leftmost node which is
    // head of the constructed DLL, so move to the leftmost
    // node
    while (root->left != NULL)
        root = root->left;
 
    return (root);
}

// A reservoir sampling based function to print a
// random node from a linked list
void Node::printRandom(Node *head)
{
    // IF list is empty
    if (head == NULL)
    return;
 
    // Use a different seed value so that we don't get
    // same result each time we run this program
    srand(time(NULL));
 
    // Initialize result as first node
    int result = head->key;
 
    // Iterate from the (k+1)th element to nth element
    Node *current = head;
    int n;
    for (n = 2; current != NULL; n++)
    {
        // change result with probability 1/n
        if (rand() % n == 0)
        result = current->key;
 
        // Move to next node
        current = current->next;
    }

/*
You are given q queries, where each query consists of n (the total number of programs), a list of dependencies for the n programs, and a list of the m specific indices of the programs you wish to install. For each query, perform the following tasks:

    Find the minimum number of programs that must be installed in order for you to install the m specific programs you want, then print this number on a new line.

Find the order in which you must install each program such that the following conditions are satisfied:

    The m specific programs you wanted to install are all installed.
    The number of installed programs is minimal.
    None of the dependencies are broken.

Then print this installation sequence as a single line of space-separated integers. If there is more than one way to accomplish this, then print the lexicographically smallest installation sequence.

Sample Input 0

1
8 3
1 8
0
1 7
1 7
1 2
1 2
0
2 3 4
1 5 6

Sample Output 0

8
2 5 6 7 3 4 8 1


*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <list>
#include <map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

class graph
{
    int n;
    int m;
    vector<int> pgm_list;
    map<int,vector<int>> prog_dep;
    list<int> build_list;
    void build(int pgm);
    public:
        graph():n(0),m(0){};
        ~graph()
        {
            pgm_list.clear();
            prog_dep.clear();
            build_list.clear();
        };
        friend istream& operator>>( istream& i, graph g)
        {
            i >> g.n >> g.m;
            //cout << g.n << " " << g.m << "\n";
            for (auto j = 1; j <=g.n ;j++)
            {
                //int prog = 0;
                int n_dep = 0;
                i>> n_dep;
                //cout << n_dep << "\n";
                vector<int> dep_prg;
                if(n_dep)
                {
                    copy_n(istream_iterator<int>(i), n_dep, back_inserter(dep_prg));
                    g.prog_dep[j] = dep_prg;
                    dep_prg.clear();
                }
            }
            copy_n(istream_iterator<int>(i), g.m, back_inserter(g.pgm_list));
            
            for(auto e : g.prog_dep)
            {
                cout << e.first <<" --> ";
                for(auto pgm : e.second)
                {
                    cout << pgm << " ";
                }
                cout <<"\n";
            }
            
            for(auto pgm : g.pgm_list)
            {
                cout << pgm << " ";
            }
            cout <<"\n";
            g.build_build_list();
            g.print_list();
            return i;
        };

        void build_build_list();
        void print_list()
        {
            cout << build_list.size() << "\n";
            for ( auto pgm : build_list)
            {
                cout << pgm << " ";
            }
            cout << "\n";
        };
};
void graph::build_build_list()
{

    for ( auto pgm : pgm_list)
    {
        build(pgm);
    }
}
void graph::build(int pgm)
{
    cout << pgm <<"\n";
    
    if (find(build_list.begin(), build_list.end(), pgm)!=build_list.end())
    {
        //already in list
        return;
    }
    if(prog_dep[pgm].empty())
    {
        build_list.push_back(pgm);
        return;
    }
    
    for( auto i : prog_dep[pgm])
    {
        build(i);
    }
    build_list.push_back(pgm);
    
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q;
    cin >> q;
    while(q--)
    {
        graph g;
        cin >> g;
        g.build_build_list();
        g.print_list();
    }
        
    return 0;
}




// same pgm as above, diff solution
//Tanuj Khattar
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);


int indeg[20000];
bool to_take[20000];

bool taken[20000];

VI E[20000], rE[20000];

int main()
{
  int test;
  si(test); 
  while (test--)
  {
    int n, m;
    si(n); si(m);
    for (int i = 0; i < n; i++)
    {
      E[i].clear();
      rE[i].clear();
      to_take[i] = false;
      taken[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
      si(indeg[i]);
      for (int j = 0; j < indeg[i]; j++)
      {
        int y; si(y); y--; 
        E[y].push_back(i);
        rE[i].push_back(y);
      }
    }
    VI toposort;
    priority_queue<int> Q;
    for (int i = 0; i < n; i++)
      if (indeg[i] == 0) Q.push(-i);
    while(!Q.empty())
    {
      int x = - Q.top(); Q.pop();
      toposort.push_back(x);
      for (auto y : E[x])
      {
        indeg[y]--;
        if (indeg[y] == 0)
          Q.push(-y);
      }
    }
      
    VI spl(m);

    for (int i = 0; i < m; i++)
    {
      scanf("%d", &spl[i]);
      spl[i]--;
      to_take[spl[i]] = true;
    }
    reverse(toposort.begin(), toposort.end());

    VI ans;

    for (auto x : toposort)
    {
      if (to_take[x])
      {
        ans.push_back(x);
		trace(x);
        taken[x] = true;
        for (auto y : rE[x])
          to_take[y] = true;
      }
    }
    for (auto x : spl)
      assert(taken[x]);
    printf("%d\n", ans.size());
    for (int i = ans.size() - 1; i >=0; i--)
      printf("%d ", ans[i] + 1);
    printf("\n");
  }
  return 0;	
}
