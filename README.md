#Restaurant Review Management System

#Overview

This program implements a restaurant review management system using a hash table and priority queue to store and manage reviews efficiently. Users can add reviews, retrieve the most recent review, remove the most recent review, and view all reviews for a restaurant. The program also provides options to view hash table statistics like the number of collisions.

Features

Build Data Structure: Load restaurant review data from a file into a hash table.

Add a Review: Insert a new review into the system.

Retrieve Most Recent Review: Fetch the latest review for a given restaurant.

Pop Most Recent Review: Remove the latest review for a restaurant.

Print Reviews for a Restaurant: Display all stored reviews for a restaurant.

Display Number of Collisions: Show the count of hash table collisions.

Display Table Results: Print the contents of the hash table.

Exit: Quit the program.

Prerequisites

C++ Compiler (e.g., g++, clang)

C++ Standard Library

Compilation and Execution

Use the following command to compile the program:

 g++ -o restaurant_review main.cpp hash.cpp PriorityQueue.cpp -std=c++11

./restaurant_review <dataset_filename> <table_size>
