This is a rewrite of the Hash Table example from the "Learn C The Hard Way" book into C++.

It involves a way to register outer hashing functions as arguments to the HashMap constructor.

I am using std::string instead of bstrlib and void pointers. 

The bucket consists of C-style arrays of HashMapNode objects.
The buckets are single dimensional and directly hold HashMapNode objects. This is one of the main differences
between both implementations.

The architecture provides a way to register different hashing functions, different functions for comparing the node keys and callbacks
to be executed for each node of the hash.
