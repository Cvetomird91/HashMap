This is a rewrite of the Hash Table example from the "Learn C The Hard Way" book into C++.

It involves a way to register hashing functions as function pointers which are arguments to the constructor.

I am using std::string instead of bstrlib and void pointers and C-style arrays for the buckets.
The buckets are single dimensional and directly hold HashMapNode objects. This is one of the main differences.

The architecture includes a way to register hashmap functions, callbacks for comparing the keys and callbacks
to be executed for each node of the hash.
