C++ URL Shortener

A high-performance, minimalist URL shortener built from scratch in C++17. This project was built without heavy frameworks or databases to explore and implement core system design principles.

Key System Design Implementations :-

1. Converts auto-incremented sequential database IDs into compact alphanumeric strings to liminate expensive collision retries.
2. Utilizes a dual `std::unordered_map` architecture to achieve guaranteed constant time complexity for both read and write verifications.
3. Implements an in-memory dictionary to intercept read requests, serving popular short codes directly from RAM to bypass disk storage.

No external dependencies required. (Requires C++17)