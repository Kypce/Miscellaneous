# Operating Systems Heap

This project implements the concept of how heaps function. The heap is created to organize used and free data chunks.

### Overview
- This is a memory heap created with memory "chunks" that store information and indicate their availability.
- The program also has the ability to recycle recently freed chunks and merge neighboring free chunks to prevent fragmentation from occuring.

- A custom linked list is also utilized to test the heap and observe where the objects are placed.
  - The testing shows that even a linked list, which has strongly connected data, has its data split up around the memory heap.

### Memory Chunk Format
- There are two types of chunks: in-use and free.
  - In-use chunks: Organized by its size, the data, its size, and the code (98989898).
  - Free chunks: Organized by its size, the previous free chunk location, the next free chunk location, its size, and the code (12121212).

  <img width="619" alt="image" src="https://github.com/Kypce/Miscellaneous-Projects/assets/69166331/3f807962-8f0c-45a1-8200-3fc7248921b9">

- The code is used to easily tell if a chunk is free or used without having to read and look at the format of the entire chunk.
