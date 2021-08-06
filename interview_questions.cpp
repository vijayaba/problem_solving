
    //How is a binary search tree implemented? ( sorted, if node is less than root, add left, else add right
    //How do you perform preorder traversal in a given binary tree?( Node-Left-Right)
	
	* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    /* first print data of node */
    cout << node->data << " ";
 
    /* then recur on left sutree */
    printPreorder(node->left);
 
    /* now recur on right subtree */
    printPreorder(node->right);
}

		//	Algorithm Inorder(tree)
		//1. Traverse the left subtree, i.e., call Inorder(left-subtree)
		//2. Visit the root.
		//3. Traverse the right subtree, i.e., call Inorder(right-subtree)
		//
		//Algorithm Preorder(tree)
		//1. Visit the root.
		//2. Traverse the left subtree, i.e., call Preorder(left-subtree)
		//3. Traverse the right subtree, i.e., call Preorder(right-subtree) 
		//
		//Algorithm Postorder(tree)
		//1. Traverse the left subtree, i.e., call Postorder(left-subtree)
		//2. Traverse the right subtree, i.e., call Postorder(right-subtree)
		//3. Visit the root.
		
		
	//How do you traverse a given binary tree in preorder without recursion?
	 // start from root node (set current node to root node)
	/* preorder*/													{ /* inorder*/								void postOrderIterative(Node* root)
	                                                        stack<Node *> s;                                    {
	                                                        Node *curr = root;                                      if (root == NULL)
	                                                                                                                    return;
    Node* curr = root;									    while (curr != NULL || s.empty() == false)           	
                                                            {                                                       // Create two stacks
    // run till stack is not empty or current is                /* Reach the left most Node of the                  stack<Node *> s1, s2;
    // not NULL                                                    curr Node */                                  
    while (!st.empty() || curr != NULL) {				        while (curr !=  NULL)	                            // push root to first stack
        // Print left children while exist				        {	                                                s1.push(root);
        // and keep pushing right into the stack                    /* place pointer to a tree node on              Node* node;
														               the stack before traversing	             
        while (curr != NULL) {                                        the node's left subtree */                    // Run while first stack is not empty
            cout << curr->data << " ";                              s.push(curr);                                   while (!s1.empty()) {
                                                                    curr = curr->left;                                  // Pop an item from s1 and push it to s2
            if (curr->right)                                    }                                                       node = s1.top();
                st.push(curr->right);                                                                                   s1.pop();
                                                                /* Current must be NULL at this point */                s2.push(node);
            curr = curr->left;                                  curr = s.top();                                  
        }                                                       s.pop();                                                // Push left and right children
														 	                                                            // of removed item to s1
        /* We reach when curr is NULL, so We    */                cout << curr->data << " ";                            if (node->left)
        /* take out a right child from stack  */                                                                            s1.push(node->left);
        if (st.empty() == false) {                              /* we have visited the node and its    */               if (node->right)
            curr = st.top();                                    /*   left subtree.  Now, it's right   */                    s1.push(node->right);
            st.pop();                                           /*   subtree's turn */                              }
        }                                                       curr = curr->right;                              
    }                                                                                                               // Print all elements of second stack
	                                                        } /* end of while */                                    while (!s2.empty()) {
	                                                    }	                                                            node = s2.top();
	                                                                                                                    s2.pop();
	                                                                                                                    cout << node->data << " ";
	                                                                                                                }
	                                                                                                            }
	
	//
	//
    //How do you perform an inorder traversal in a given binary tree?LNR
    //How do you print all nodes of a given binary tree using inorder traversal without recursion?
	//1) Create an empty stack S.
	//2) Initialize current node as root
	//3) Push the current node to S and set current = current->left until current is NULL
	//4) If current is NULL and stack is not empty then 
	//	 a) Pop the top item from stack.
	//	 b) Print the popped item, set current = popped_item->right 
	//	 c) Go to step 3.
	//5) If current is NULL and stack is empty then we are done.
	/* Iterative function for inorder tree
   traversal */
void inOrder(struct Node *root)
{
    stack<Node *> s;
    Node *curr = root;
 
    while (curr != NULL || s.empty() == false)             
    {
        /* Reach the left most Node of the
           curr Node */
        while (curr !=  NULL)
        {
            /* place pointer to a tree node on
               the stack before traversing
              the node's left subtree */
            s.push(curr);
            curr = curr->left;
        }
 
        /* Current must be NULL at this point */
        curr = s.top();
        s.pop();
 
        cout << curr->data << " ";
 
        /* we have visited the node and its
           left subtree.  Now, it's right
           subtree's turn */
        curr = curr->right;
 
    } /* end of while */
}	
	
	
    //How do you implement a postorder traversal algorithm? Left-Right-Node
	
    //How do you traverse a binary tree in postorder traversal without recursion?
	// 	1. Push root to first stack.
	//2. Loop while first stack is not empty
	//   2.1 Pop a node from first stack and push it to second stack
	//   2.2 Push left and right children of the popped node to first stack
	//3. Print contents of second stack
	void postOrderIterative(Node* root)
{
    if (root == NULL)
        return;
 
    // Create two stacks
    stack<Node *> s1, s2;
 
    // push root to first stack
    s1.push(root);
    Node* node;
 
    // Run while first stack is not empty
    while (!s1.empty()) {
        // Pop an item from s1 and push it to s2
        node = s1.top();
        s1.pop();
        s2.push(node);
 
        // Push left and right children
        // of removed item to s1
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }
 
    // Print all elements of second stack
    while (!s2.empty()) {
        node = s2.top();
        s2.pop();
        cout << node->data << " ";
    }
}

	
    //How are all leaves of a binary search tree printed? (DFS or BFS)
    //How do you count a number of leaf nodes in a given binary tree? (DFS)
    //How do you perform a binary search in a given array?
	//	, it should be sorted, divide the lenthg by half and compare x with that number, if it <, then do the same search in the first half  
	//  else in the second half ( has o(logn) time complexity)
	// 
	/ A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
  
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
  
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
  
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
  
    // We reach here when element is not
    // present in array
    return -1;
}

bool check(int dig)
{
    //element at dig position in array
    int ele=a[dig];
  
    //if k is less than
    //element at dig position 
    //then we need to bring our higher ending to dig
    //and then continue further
    if(k<=ele)
    {
        return 1;
    }
    else
    {
    return 0;
    }
}
void binsrch(int lo,int hi)
{
    while(lo<hi)
    {
        int mid=(lo+hi)/2;
        if(check(mid))
        {
            hi=mid;
        }
        else
        {
            lo=mid+1;
        }
    }
    //if a[lo] is k
    if(a[lo]==k)
        cout<<"Element found at index "<<lo;// 0 based indexing
    else
        cout<<"Element doesnt exist in array";//element was not in our array
  
}

    //How is a bubble sort algorithm implemented?
    //How is an iterative quicksort algorithm implemented?
/* low  --> Starting index,  high  --> Ending index */
quickSort(arr[], low, high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[pi] is now
           at right place */
        pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  // Before pi
        quickSort(arr, pi + 1, high); // After pi
    }
}
int partition(arr, l, h)
{
	pivot = arr[low];
	i = low;
	j = h+1;
	
	while( i < j)
	{
		do{
			i++
		}while(a[i] <=pivot)
			
		do{
			j--;
		}while(a[j]>pivot)
		if(i <j)
			swap(a[i],a[j]);
	}
	
	swap(a[j],a[low])
	return j
}
	
}
	
    //How do you implement an insertion sort algorithm?
    //How is a merge sort algorithm implemented?
    //How do you implement a bucket sort algorithm?
    //How do you implement a counting sort algorithm?
    //How is a radix sort algorithm implemented?
    //How do you swap two numbers without using the third variable?
    //How do you check if two rectangles overlap with each other?
    //How do you design a vending machine?
	//
	//
    //How do you print duplicate characters from a string?
	//Method 2: Using Maps
    //Approach: using a map to store the count.Time Complexity: O(N log N), where N = length of the string passed and it generally takes
	//logN time for an element insertion in a map.Space Complexity: O(K), where K = size of the map (0<=K<=input_string_length).
	
    //How do you check if two strings are anagrams of each other?
	//Method 1 (Use Sorting)  
	//
    //Sort both strings --> logn
    //Compare the sorted strings ( both should be same) --> n , so complexity O(nlogn)
	//
	//Method 2, keep count arrays, compare both arrays, they should be same
	//Method 3 (count characters using one array) 
    //The above implementation can be further to use only one count array instead of two. We can increment the value in count array for characters in str1 and decrement for characters in str2. Finally, if all count values are 0, then the two strings are anagram of each other. --> O(n)
	//
    //How do you print the first non-repeated character from a string?
		//Make a hash_map which will map the character to there respective frequencies.
		//Traverse the given string using a pointer.
		//Increase the count of current character in the hash_map.
		//Now traverse the string again and check whether the current character hasfrequency=1.
		//If the frequency>1 continue the traversal.
		//Else break the loop and print the current character as the answer.

Pseudo Code : 
	for ( i=0 to str.length())
hash_map[str[i]]++;

for(i=0 to str.length())
  if(hash_map[str[i]]==1)
  return str[i]
  break 
  
    //How can a given string be reversed using recursion?
    //How do you check if a string contains only digits?
	
	bool b = false;
	if (! s.empty() && std::all_of(s.begin(), s.end(), [](char c){return std::isdigit(c);})) {
    b = true;
}
	
	
	// Function that returns true
// if ch is a digit
bool isDigit(char ch)
{
    if (ch >= '0' && ch <= '9')
        return true;
    return false;
}
 
// Function that returns true
// if str contains all the
// digits from 0 to 9
bool allDigits(string str, int len)
{
 
    // To mark the present digits
    bool present[MAX] = { false };
 
    // For every character of the string
    for (int i = 0; i < len; i++) {
 
        // If the current character is a digit
        if (isDigit(str[i])) {
 
            // Mark the current digit as present
            int digit = str[i] - '0';
            present[digit] = true;
        }
    }
 
    // For every digit from 0 to 9
    for (int i = 0; i < MAX; i++) {
 
        // If the current digit is
        // not present in str
        if (!present[i])
            return false;
    }
 
    return true;
}

    //How are duplicate characters found in a string?
    //How do you count a number of vowels and consonants in a given string?
    //How do you count the occurrence of a given character in a string?
    //How do you find all permutations of a string?
	 
		// Function to print permutations of string
		// This function takes three parameters:
		// 1. String
		// 2. Starting index of the string
		// 3. Ending index of the string.
		void permute(string a, int l, int r)
		{
			// Base case
			if (l == r)
				cout<<a<<endl;
			else
			{
				// Permutations made
				for (int i = l; i <= r; i++)
				{
		 
					// Swapping done
					swap(a[l], a[i]);
		 
					// Recursion called
					permute(a, l+1, r);
		 
					//backtrack
					swap(a[l], a[i]);
				}
			}
		}
		
	 
		int main()
		{
			std::string s = "aba";
			std::sort(s.begin(), s.end()); //important
			do {
				std::cout << s << '\n';
			} while(std::next_permutation(s.begin(), s.end()));
		}
		
		output
		aab
		aba
		baa
		int main()
		{
			std::string s="abc";
			std::sort(s.begin(), s.end(), std::greater<char>());
			do {
				std::cout << s << ' ';
			} while(std::prev_permutation(s.begin(), s.end()));
			std::cout << '\n';
		}
		output --> cba cab bca bac acb abc
		
    //How do you reverse words in a given sentence without using any library method?
		// --- use string stream, 
		//get word by word put on stack and pop back
    //How do you check if two strings are a rotation of each other?
	//1. Create a temp string and store concatenation of str1 to
    //   str1 in temp.
    //                      temp = str1 + str1
    //2. If str2 is a substring of temp then str1 and str2 are 
    //   rotations of each other.
	
    //How do you check if a given string is a palindrome?
	// two pointers, first and last, compare the string and do firs-- and last-- for n/2 times. it there is mismatch it is not a palindrom


    //How do you find the middle element of a singly linked list in one pass?
	// -- use fast and slow ptrs. when fast reaches end, slow will point to middle
    //How do you check if a given linked list contains a cycle? How do you find the starting node of the cycle?
		//-- use fast and slow ptrs., increment fast by two, and slow by one. if they both meet  it is  a cyle.
		//1. If a loop is found, initialize a slow pointer to head, let fast pointer be at its position. 
		//2. Move both slow and fast pointers one node at a time. 
		//3. The point at which they meet is the start of the loop.
		Node* detectAndRemoveLoop(Node* head)
{
    // If list is empty or has only one node
    // without loop
    if (head == NULL || head->next == NULL)
        return NULL;
 
    Node *slow = head, *fast = head;
 
    // Move slow and fast 1 and 2 steps
    // ahead respectively.
    slow = slow->next;
    fast = fast->next->next;
 
    // Search for loop using slow and
    // fast pointers
    while (fast && fast->next) {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
 
    // If loop does not exist
    if (slow != fast)
        return NULL;
 
    // If loop exists. Start slow from
    // head and fast from meeting point.
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
 
    return slow;
}

    //How do you reverse a linked list?
	
    //How do you reverse a singly linked list without recursion?
    //How are duplicate nodes removed in an unsorted linked list?
    //How do you find the length of a singly linked list?
    //How do you find the third node from the end in a singly linked list?
		//	Method 2 (Use two pointers) 
		//Maintain two pointers – reference pointer and main pointer. Initialize both reference and main pointers to head. First, move the reference pointer to n nodes from head. Now move both pointers one by one until the reference pointer reaches the end. Now the main pointer will point to nth node from the end. Return the main pointer.
		//
    //How do you find the sum of two linked lists using Stack?
	//
	//
    //How do you find the missing number in a given integer array of 1 to 100?
	// -- n(n-1)/2 -> 100(100-1)/2 = sum ; missing_num = sum - arraysum
    //How do you find the duplicate number on a given integer array?
    //How do you find the largest and smallest number in an unsorted integer array?
    //How do you find all pairs of an integer array whose sum is equal to a given number?
	//Efficient solution – 
A be//tter solution is possible in O(n) time. Below is the Algorithm – 
	//
    //Create a map to store frequency of each number in the array. (Single traversal is required)
    //In the next traversal, for every element check if it can be combined with any other element (other than itself!) to give the desired sum. Increment the counter accordingly.
    //After completion of second traversal, we’d have twice the required value stored in counter because every pair is counted two times. Hence divide count by 2 and return.
	// C++ implementation of simple method to find count of
// pairs with given sum.
#include <bits/stdc++.h>
using namespace std;
 
// Returns number of pairs in arr[0..n-1] with sum equal
// to 'sum'
int getPairsCount(int arr[], int n, int sum)
{
    unordered_map<int, int> m;
 
    // Store counts of all elements in map m
    for (int i = 0; i < n; i++)
        m[arr[i]]++;
 
    int twice_count = 0;
 
    // iterate through each element and increment the
    // count (Notice that every pair is counted twice)
    for (int i = 0; i < n; i++) {
        twice_count += m[sum - arr[i]];
 
        // if (arr[i], arr[i]) pair satisfies the condition,
        // then we need to ensure that the count is
        // decreased by one such that the (arr[i], arr[i])
        // pair is not considered
        if (sum - arr[i] == arr[i])
            twice_count--;
    }
 
    // return the half of twice_count
    r  eturn twice_count / 2;
}

	//Get K random values from a list of values.

//Reservoir sampling is a family of randomized algorithms for randomly choosing k samples from a list of n items, where n is either a very large or unknown number. Typically n is large enough that the list doesn’t fit into main memory. For example, a list of search queries in Google and Facebook.
//So we are given a big array (or stream) of numbers (to simplify), and we need to write an efficient function to randomly select k numbers where 1 <= k <= n. Let the input array be stream[]. 
//
//It can be solved in O(n) time. The solution also suits well for input in the form of stream. The idea is similar to this post. Following are the steps.
//1) Create an array reservoir[0..k-1] and copy first k items of stream[] to it. 
//2) Now one by one consider all items from (k+1)th item to nth item. 
//…a) Generate a random number from 0 to i where i is the index of the current item in stream[]. Let the generated random number is j. 
//…b) If j is in range 0 to k-1, replace reservoir[j] with stream[i]
   // A function to randomly select
// k items from stream[0..n-1].
void selectKItems(int stream[], int n, int k)
{
    int i; // index for elements in stream[]
 
    // reservoir[] is the output array. Initialize
    // it with first k elements from stream[]
    int reservoir[k];
    for (i = 0; i < k; i++)
        reservoir[i] = stream[i];
 
    // Use a different seed value so that we don't get
    // same result each time we run this program
    srand(time(NULL));
 
    // Iterate from the (k+1)th element to nth element
    for (; i < n; i++)
    {
        // Pick a random index from 0 to i.
        int j = rand() % (i + 1);
 
        // If the randomly picked index is smaller than k,
        // then replace the element present at the index
        // with new element from stream
        if (j < k)
        reservoir[j] = stream[i];
    }
 
    cout << "Following are k randomly selected items \n";
    printArray(reservoir, k);
}

	
    //How do you find duplicate numbers in an array if it contains multiple duplicates?
    //How are duplicates removed from a given array in Java?
    //How is an integer array sorted in place using the quicksort algorithm?
    //How do you remove duplicates from an array in place?
    //How do you reverse an array in place in Java?
    //How are duplicates removed from an array without using any library?

// check valid utf8
 //Thought it may be helpful to add some comments. Java Implementation.
    /* How to solve this problem?
    1.Find how many bytes the first number in the data represents
    2.Find whether the rest datas contains correct corresponding 01...byte

    Think About 
    0xxxxxxx 1byte
    110xxxxx 10xxxxxx 2byte(2个 continued 1)
    1110xxxx 10xxxxxx 10xxxxxx 3byte(3个 continued 1)
    0xxxxxxx 1byte-> We want to check whether a num from the input data array
    is a valid utf-8 encoding for 1 byte character.
    Ok. How do we do that? If this number starts with 0,and includes only 8 bit 
    or 1byte. We know it is a valid utf-8 encoding. 
    So how do we know whether it starts with 0 or not? We shift the most 
    siginificant 0 to the very end and compare with the specific res.
    
    e.x data = [197, 130]
    Use the same approach, we check the above data represent a character in 
    UTF8. 
    We first want to make sure it is start with 110. How do we do that?
    We right shift the 110 to the very end, e.x 197 = 11000101 -> 0000 0110
    and compare with the specific res.

    The nextByte is used to match 10xxxxxx.
    e.x data = [197, 130, 1] -> 11000101 10000010 00000001
    We know 197 represents an 2-bytes character, next we need find two representations of 
    0x10...to make this data valid utf-8. So for "130" we shift right by 6 to find whether 
    it start with 10. */ 
     public boolean validUtf8(int[] data) {
        if(data == null || data.length == 0) return false;
        for(int num:data) num = num &(1 << 8 - 1); //We use num&255(1111 1111) -> "Only the least significant 8 bits of each integer is used to store the data."
        
        int oneByte = 0; //Ox0
        int twoByte = 6; //Ox110
        int threeByte = 14; //Ox1110
        int fourByte = 30; //Ox11110
        //Ox10 -->after remove the first 8 bits, and look for the next 8 bits 
        //e.x 11110xxx [10]xxxxxx 10xxxxxx 10xxxxxx
        int nextByte = 2;
        int expectedByteCount = 0;
        
        for(int num:data){
            if(expectedByteCount == 0){
                if(num >> 7 == oneByte) continue; //1byte
                else if(num >> 5 == twoByte){ //2-byte
                    expectedByteCount = 1; //We need one more to make this valid utf-8
                }
                else if(num >> 4 == threeByte){ //3-byte
                    expectedByteCount = 2; 
                }
                else if(num >> 3 == fourByte){ //4-byte
                    expectedByteCount = 3; 
                }
                else{
                    return false;
                }
            }
            else{
                if((num >> 6) != nextByte) return false;
                expectedByteCount--;
            }
        }
        return expectedByteCount == 0;
    }
}
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int count = 0;
        for (auto c : data) {
            if (count == 0) {
                if ((c >> 5) == 0b110) count = 1;
                else if ((c >> 4) == 0b1110) count = 2;
                else if ((c >> 3) == 0b11110) count = 3;
                else if ((c >> 7)) return false;
            } else {
                if ((c >> 6) != 0b10) return false;
                count--;
            }
        }
        return count == 0;
    }
};
	
