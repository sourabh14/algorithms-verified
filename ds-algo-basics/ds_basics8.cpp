/* 
	Hashing Data Structure
*/

#include <bits/stdc++.h>

using namespace std;

int main() {

	/* Hashing
		- Hashing is a technique or process of mapping keys, values into the hash table by using a hash function. 
		- It is done for faster access to elements. The efficiency of mapping depends on the efficiency of the hash function used.
		- Many applications require only dictionary operations - insert, search, delete. Eg compiler. Hash tables are effective ds for implementing dictionaries.
		- Search - average time O(1), worst case O(n)

		-Eg: Let a hash function H(x) maps the value x at the index x%10 in an Array. For example if the list of values is [11,12,13,14,15] it will be stored at positions {1,2,3,4,5} in the array or Hash table respectively
		
	Direct Address table
		- With array we can have direct addressing. We can take advantage of direct addressing when we can afford to allocate an array that has one position for every possible key.
		- Eg: if each element is of range [1, m-1] where m is not too large and no two elements have same key, we can use direct address table.

	Hash Tables
		- When no of keys actually stored is small relative to total no of possible keys, hash tables become an effective alternative, since has table typically uses an array of size proportional to the no of keys actually stored.
		- Therefore hash tables require much less storage than direct address tables.

	Hash function
		- hash function maps a big number or string to a small integer that can be used as index in hash table. 
		- we also say h(k) is the hash value of key 'k'
		- Eg: let's say there are 10 keys to be stored in hash. we will create hash table of size 10 and hash function as h(key) = key % 10
	*/

	/*	

	Collision
		- two keys may hash to same value i.e. h(k1) = h(k2). This situation is called collision.
		- A well designed hash function can minimize the no of collision, but we still need a method of resolving collision, since possible key values are greater than total hash table capacity.
		- Collision is resolved through - Chaining or Open addressing

	Chaining
		- we use linked list to place all elements that hash to same slot
		- Chaining is simple, but requires additional memory outside the table.

		Performance of Chaining: 
			- Performance of hashing can be evaluated under the assumption that each key is equally likely to be hashed to any slot 
			m = Number of slots in hash table
	 		n = Number of keys to be inserted in hash table
	 		Load factor α = n/m 
	  			- Expected time to search = O(1 + α)
	 			- Expected time to delete = O(1 + α)
				- Time to insert = O(1)

	Open Addressing: 
		- In open addressing, all elements are stored in the hash table itself. 
		- No lists and no elements are stored outside the table.
		- So at any point, the size of the table must be greater than or equal to the total number of keys (Note that we can increase table size by copying old data if needed). 
		- When searching for an element, we examine the table slots one by one until the desired element is found or it is clear that the element is not in the table.

		Operations
			- Insert(k): Keep probing until an empty slot is found. Once an empty slot is found, insert k. 
			- Search(k): Keep probing until slot’s key doesn’t become equal to k or an empty slot is reached. 
			- Delete(k): Delete operation is interesting. If we simply delete a key, then the search may fail. So slots of deleted keys are marked specially as “deleted”. 
				The insert can insert an item in a deleted slot, but the search doesn’t stop at a deleted slot. 

		Advantages of Open addressing
			- avoids pointers altogether. The extra memory freed by not storing pointers provide the hash table with a larger number of slots for same amount of memory - leading to fewer collisions and faster retrieval.

		Open Addressing is done in the following ways: 
			
			1. Linear Probing: 
				In linear probing, we linearly probe for next slot. For example, the typical gap between two probes is 1 as seen in the example below. 
				Let hash(x) be the slot index computed using a hash function and S be the table size 

				If slot hash(x) % S is full, then we try (hash(x) + 1) % S
				If (hash(x) + 1) % S is also full, then we try (hash(x) + 2) % S
				If (hash(x) + 2) % S is also full, then we try (hash(x) + 3) % S 

			2. Quadratic Probing We look for i2‘th slot in i’th iteration.  
				let hash(x) be the slot index computed using hash function.  
				If slot hash(x) % S is full, then we try (hash(x) + 1*1) % S
				If (hash(x) + 1*1) % S is also full, then we try (hash(x) + 2*2) % S
				If (hash(x) + 2*2) % S is also full, then we try (hash(x) + 
		
			3. ) Double Hashing We use another hash function hash2(x) and look for i*hash2(x) slot in i’th rotation
				let hash(x) be the slot index computed using hash function.  
				If slot hash(x) % S is full, then we try (hash(x) + 1*hash2(x)) % S
				If (hash(x) + 1*hash2(x)) % S is also full, then we try (hash(x) + 2*hash2(x)) % S
				If (hash(x) + 2*hash2(x)) % S is also full, then we try (hash(x) + 3*hash2(x)) % S
				................

			Challenges in Linear Probing :
				- Primary Clustering: One of the problems with linear probing is Primary clustering, many consecutive elements form groups and it starts taking time to find a free slot or to search for an element.  
				- Secondary Clustering: Secondary clustering is less severe, two records only have the same collision chain (Probe Sequence) if their initial position is the same.

			Comparison of above three: 
				- Linear probing has the best cache performance but suffers from clustering. One more advantage of Linear probing is easy to compute. 
				- Quadratic probing lies between the two in terms of cache performance and clustering. 
				- Double hashing has poor cache performance but no clustering. Double hashing requires more computation time as two hash functions need to be computed. 
	*/
	return 0;
}