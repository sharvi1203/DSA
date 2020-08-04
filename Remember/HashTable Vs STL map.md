**Unordered_map** : Internally unordered_map is implemented using **Hash Table**, the key provided to map are hashed into indices of hash table that is why performance of data structure depends on hash function a lot but on an average the cost of search, insert and delete from hash table is **O(1)**.

**Map** : It’s implemented as a self-balancing **red-black tree**. Probably the two most common self balancing trees are red-black tree and AVL trees. Time complexity of map operations is **O(Log n)**

**Advantages of BST over Hash Table**

Hash Table supports following operations in Θ(1) time.
1) Search
2) Insert
3) Delete

The time complexity of above operations in a self-balancing Binary Search Tree (BST) (like Red-Black Tree, AVL Tree, Splay Tree, etc) is O(Logn).
So Hash Table seems to beating BST in all common operations. When should we prefer BST over Hash Tables, what are advantages. Following are some important points in favor of BSTs.

1. We can get all keys in sorted order by just doing Inorder Traversal of BST. This is not a natural operation in Hash Tables and requires extra efforts.
2. Doing order statistics, finding closest lower and greater elements, doing range queries are easy to do with BSTs. Like sorting, these operations are not a natural operation with Hash Tables.
3. BSTs are easy to implement compared to hashing, we can easily implement our own customized BST. To implement Hashing, we generally rely on libraries provided by programming languages.
4. With Self-Balancing BSTs, all operations are guaranteed to work in O(Logn) time. But with Hashing, Θ(1) is average time and some particular operations may be costly, especially when table resizing happens.
