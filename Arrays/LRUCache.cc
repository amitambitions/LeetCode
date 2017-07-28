// Typically LRU cache is implemented using a doubly linked list and a hash map. Doubly
// Linked List is used to store list of pages with most recently used page at the start of
// the list. So, as more pages are added to the list, least recently used pages are moved
// to the end of the list with page at tail being the least recently used page in the list.
// Hash Map (key: page number, value: page) is used for O(1) access to pages in cache
//
// When a page is accessed, there can be 2 cases:
//
// 1. Page is present in the cache - If the page is already present in the cache, we move
// the page to the start of the list.
//
// 2. Page is not present in the cache - If the page is not present in the cache, we add
// the page to the list. 
//
// How to add a page to the list:
//   a. If the cache is not full, add the new page to the start of the list.
//   b. If the cache is full, remove the last node of the linked list and move the new page
// to the start of the list.
//
//
// There could be multiple ways depending on what exactly your memory contains. Say your
// data is indexed using numbers you might need a hashtable in additon to your primary data
// structure for implementing the LRU.
// 
// One of the simplest means of implementing an LRU, where your data is of a single type
// or can be categorised under a single type (say structure or an array) you can use a
// Splay Tree.
//
// A Splay tree keeps the last recently used data closest to the root the tree and the
// least recently used data farthest from the root ( a leaf). You can read more about Splay
// TODO: Need to read more about splay trees and how they can be used in this
// scenario or any other scenario. 
//
// TODO: what will be the difference if we keep the most recently used at the end of the
// list?
