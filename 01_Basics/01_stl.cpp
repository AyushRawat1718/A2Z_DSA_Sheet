#include<bits/stdc++.h>
using namespace std;

// Pair
void Pair(){

    pair<int, int> p = {1,3};
    cout<<p.first<<" "<<p.second<<endl;

    pair<int, pair<int, int>> p1 = {1,{4,5}}; //Nested Pairs
    cout<<p1.first<<" "<<p1.second.first<<" "<<p1.second.second<<endl;

    pair<int, int> arr[] = {{1,2},{4,5},{7,8},{9,10}}; //Array of pairs
    for (int i=0; i<4; i++){
        cout<<arr[i].first<<" "<<arr[i].second<<endl;
    }

}

// -------------------------------------------------------------------------------------------------------------------------------------------------

// Vector -> Just a dynamic array.
// Stored in contiguous memory just like array [Imp point]

void print_vector(vector<int> arr){
    for(auto i : arr) cout<<i<<" ";
    cout<<endl;
}

void Vector(){
    vector<int> v;

    v.push_back(5);
    v.emplace_back(7); //Same as push_back, but a little bit faster. [Slight changes in syntax]

    vector<pair<int, int>> v2; //Vector of pairs
    v2.push_back({4,5}); 
    v2.emplace_back(7,8); //Minor change in syntax

    vector<int> v3(5); //Initialize a vector of size 5, every element has garbage or null values

    vector<int> v4(5, 20); //Initialize a vector of size 5, with every element having value 20

    vector<int> v5(v4); //Creating copy of the vector
    vector<int> &v6(v4); //Creating copy of the vector by reference

    cout<<"Before Change\n";
    cout<<"Copy->\n";
    print_vector(v4);
    print_vector(v5);
    cout<<"Refernce->\n";
    print_vector(v4);
    print_vector(v6);
    
    v5[0] = 100;
    v6[0] = 100;

    cout<<"After Change\n";
    cout<<"Copy->\n";
    print_vector(v4);
    print_vector(v5);
    cout<<"Refernce->\n";
    print_vector(v4);
    print_vector(v6);

    //Concept of ITERATORS :
    // They are like pointers, which store the memory address of the elements of container.

    //Syntax -> container_with_dataType :: iterator var_name ;

    vector<int> vec = {10,51,7,6,4,6,7,20};
    
    vector<int> :: iterator it_1 = vec.begin(); //It points to the first element of the vector
    vector<int> :: iterator it_2 = vec.end(); //It points to the memory address which is just after the last element of the container

    cout<<"First element -> "<<*(it_1)<<endl; //Using dereference operator, tells the value which is being pointed by the iterator

    cout<<"Last element -> "<<*(--it_2)<<endl;



    // Traversing in Vector
    for(vector<int> :: iterator it = vec.begin(); it != vec.end(); it++){
        cout<<*(it)<<" ";
    }
    cout<<endl;

    //Using auto keyword [Automatically identifies the data type of the variable]
    for (auto it = vec.begin(); it != vec.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    //The best way , automatically traverse over elements of container ony by one
    for (auto i : vec){
        cout<<i<<" ";
    }
    cout<<endl;

    //Erasing in vector
    vec = {4,5,8,7,9,7,4,6,1,10};
    
    //Deletes the element at the specified position;
    vec.erase(vec.begin()+3); //4 5 8 9 7 4 6 1 10
   
    //Deletes the element for the provided range -> [Start, end) , Last position is not included
    vec.erase(vec.begin(), vec.begin()+5); //4 6 1 10
   
    
    //Inserting in vector
    vec = {200,100,0};

    //Inserting at specified position => (position, element)
    vec.insert(vec.begin()+1, 55); //Inserting at 2nd position. => 200 55 100 0

    //Inserting range of same elements, starting from specified position =>(starting position, number of elements, element)
    vec.insert(vec.begin(), 5, 69); //Inserting 5 elements at starting pos. => 69 69 69 69 69 200 55 100 0

    //Inserting a range of elements from another vector => (starting position for inserting, starting pos of copying, ending position of copying + 1)
    //(start, [start_copy, end_copy))
    vector<int> vec_2 = {1,2,3,4,5,6,7,8,9};
    vec.insert(vec.end() - 1, vec_2.begin()+2, vec_2.end() - 1); // =>69 69 69 69 69 200 55 100 3 4 5 6 7 8  0

    //Some more IMP functions
    cout<<vec.size()<<endl; //Size of vector

    vec.pop_back(); //Removes last element of vector

    vec.clear(); //Clears all elements of the vector

    cout<<vec.empty()<<endl; //Tells whether vector is empty or not

}

// -------------------------------------------------------------------------------------------------------------------------------------------------

// List -> Completely similar to vectors, only difference is that it provides  insertion and deletion in constant time at any place, as in case of vector insertion at front or middle is of high time complexity

void List(){
    list<int> ls = {4,5,6,7,8,9};    
    ls.push_front(45); // 45 4 5 6 7 8 9
    ls.pop_front(); // 4 5 6 7 8 9

    //For inserting or deletion at any other random position, traverse to that position and then perform insertion and deletion

    //Only difference in list and vector is that vector performs shifting after insertion and deletion, while it does not.

    //Rest all functions are same !!.

    // Using advance keyword => moves the iterator to a position [Recommended]
    list<int> lst = {1, 2, 3, 4, 5};

    auto it = lst.begin();
    advance(it, 2);  // Move iterator to the 3rd element (0 based indexing)
    lst.insert(it, 99); // Insert 99 at 3 position

    it = lst.begin();
    advance(it, 4);
    lst.erase(it); //Delete element at given position
    
    cout << "List after update: ";
    for (int num : lst) {
        cout << num << " ";
    }

}

// -------------------------------------------------------------------------------------------------------------------------------------------------

// Deque -> Useful for insertion/deletion at any place  at constant time, also random access of any index at constant time.

// vector -> random access (Yes), Insertion/Deletion at random points(No)
// List -> random access (No), Insertion/Deletion at random points(Yes)
// Deque -> random access (Yes), Insertion/Deletion at random points(Yes)

void Deque(){
    deque<int> dq = {10, 20, 30, 40, 50};

    dq.push_front(5); // Insert at the front     
    dq.push_back(60); // Insert at the back

    // Insert at a specific position (3rd position, index 2)
    auto it = dq.begin() + 2;  // Iterator pointing to the 3rd element
    dq.insert(it, 99);  

    cout << "Deque after insertions: ";
    for (int num : dq) {
        cout << num << " ";
    }
    cout<<endl;
 
    dq.pop_front(); // Remove the first element
    dq.pop_back(); // Remove the last element

    // Remove a specific element by iterator (remove the element at position 2)
    it = dq.begin() + 2;  // Iterator pointing to the 3rd element
    dq.erase(it);

    cout << "Deque after deletions: ";
    for (int num : dq) {
        cout << num << " ";
    }
    cout<<endl;

    cout << "Front element: " << dq.front() <<endl;
    cout << "Back element: " << dq.back() <<endl;

    cout << "Element at index 1: " << dq[1] << endl;

    cout << "Deque using iterator: ";
    for (auto it = dq.begin(); it != dq.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Size of deque: " << dq.size() << endl;
    cout << "Is deque empty? " << (dq.empty() ? "Yes" : "No") <<endl;
}

// -------------------------------------------------------------------------------------------------------------------------------------------------

// Stack => Follows insertion/deletion at top/last only. Follows LIFO order

void Stack(){
    stack<int> st;
    st.push(5); // 5
    st.push(7); // 5 7
    st.push(8); // 5 7 8
    st.push(9); // 5 7 8 9
    st.push(10); // 5 7 8 9 10

    st.top()++;
    
    cout<<st.top()<<endl;

    st.pop(); //Removes the top element
    cout<<st.top()<<endl;

    cout<<st.size()<<endl;
    cout<<st.empty()<<endl;

    while (!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    cout<<st.size()<<endl;
    cout<<st.empty()<<endl;
}

// -------------------------------------------------------------------------------------------------------------------------------------------------

// Queue => Follows insertion/deletion with the order of FIFO

void Queue(){
    queue<int> q;
    q.push(1);
    q.push(5);
    q.push(7);
    q.push(9);
    q.push(3);
    q.push(10);

    // q => 1 5 7 8 3 10
    cout<<q.back()<<endl; //element present at the last in queue or the last added element in the queue
    cout<<q.front()<<endl; //element present at the first position in queue

    q.pop();

    cout<<q.back()<<endl;
    cout<<q.front()<<endl;

    cout<<"Size of the queue is => "<<q.size()<<endl;

    while (!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") <<endl;
}

// -------------------------------------------------------------------------------------------------------------------------------------------------

// Priority Queue => Similar to Queue but it keeps the elements in sorted order, that means largest element would be at the top and lowest element at last

// This is also known as Max Heap

void PriorityQueue(){
    priority_queue<int> pq;

    pq.push(5); // {5}
    pq.push(2); // {5,2}
    pq.push(8); // {8,5,2}
    pq.push(10); // {10,8,5,2}
    pq.push(56); // {56,10,8,5,2}

    cout<<pq.top()<<endl; // Prints the top element or the current largest element 

    pq.pop(); //{10,8,5,2}

    cout<<pq.top()<<endl;

    // For Min Heap
    priority_queue<int, vector<int>, greater<int>> mpq; //Just the syntax for implementation

    mpq.push(5); // {5}
    mpq.push(8); // {5,8}
    mpq.push(10); // {5,8,10}
    mpq.push(2); // {2,5,8,10}
    mpq.push(56); // {2,5,8,10,56}

    cout<<mpq.top()<<endl;

    // Rest all functions are similar as in queue.

    // Insertion and deletion takes O(logn) time as internally a tree structure is maintained, while top function takes constant time
}

// -------------------------------------------------------------------------------------------------------------------------------------------------

// Set => Stores everything in sorted order and only stores unique elements, internally implement as a tree structure so most of the functions like insert, delete, find etc. takes O(logn) time.

void Set(){
    set<int> st;
    st.insert(1); // {1}
    st.insert(5); // {1,5}
    st.insert(7); // {1,5,7}
    st.insert(9); // {1,5,7,9}
    st.insert(5); // {1,5,7,9}

    set<int> set1 = {10, 20, 30, 40, 50};
    set<int> set2 = {100, 200};

    cout << "Size of set1: " << set1.size() << "\n";

    cout << "Is set2 empty? " << (set2.empty() ? "Yes" : "No") << "\n";

    // begin() and end()
    cout << "Elements in set1 (forward): ";
    for (auto it = set1.begin(); it != set1.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";

    // rbegin() and rend()
    cout << "Elements in set1 (reverse): ";
    for (auto rit = set1.rbegin(); rit != set1.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << "\n";

    // swap()
    cout << "Before swap:\n";
    cout << "Set1: ";
    for (int val : set1) cout << val << " ";
    cout << "\nSet2: ";
    for (int val : set2) cout << val << " ";
    cout << "\n";

    set1.swap(set2); // you can also use swap(set1, set2);

    cout << "After swap:\n";
    cout << "Set1: ";
    for (int val : set1) cout << val << " ";
    cout << "\nSet2: ";
    for (int val : set2) cout << val << " ";
    cout << "\n";

    auto it = st.find(2); //If exist it returns the address of the element else returns the end() of set i.e st.end()

    int counter = st.count(2); //As set stores unique element so it returns either 1 or 0

    auto it0 = st.find(1);
    auto it1 = st.find(5);
    auto it2 = st.find(9);

    // Both works i.e. either we provide the element or its iterator

    st.erase(1);
    st.erase(it0); 
    
    // IMP: Actually erase function returns the number of element it deleted , so in case of set it returns either 0 or 1. This only works when we provide the element we want to be deleted, if we provided the iterator then it provides the iterator of the next element

    st.erase(it1, it2);   
}

// -------------------------------------------------------------------------------------------------------------------------------------------------

// Multiset => Similar to set, only difference is that it could store duplicate element also

void Multiset(){
    multiset<int> mst;
    mst.insert(1); // {1}
    mst.insert(1); // {1,1}
    mst.insert(1); // {1,1,1}
    mst.insert(1); // {1,1,1,1}

    mst.erase(1); // all 1's are erased

    mst.erase(mst.find(1)); // only a single 1 is erased

    //Rest all functions are same
}

// -------------------------------------------------------------------------------------------------------------------------------------------------

// UnorderedSet => Similar to set, but in this sorted order is not maintained, due to which in most of the cases time complexity of basic functions is O(1) but once in a worst case it becomes O(n) [very rare]

// -------------------------------------------------------------------------------------------------------------------------------------------------

// Map => It is a key-value pair container, in which keys are unique while values could be duplicate. They are sorted according to keys order.

void Map(){
    map<int, int> mp;

    mp[1] = 69;
    mp.insert({2,59});

    for (auto it: mp){
        cout<<it.first<<" "<<it.second<<endl;
    }

    cout<<mp[1]<<endl; // Getting values
    cout<<mp[3]<<endl; // If key doesn't exist it gives respective null value

    auto it = mp.find(1); //Finding the pair via key, if exist returns the iterator else returns the end()
    cout<<(*it).first<<" "<<(*it).second<<endl;

    // Rest functions are similar
}

// Multimap => Similar to map, but stores duplicate keys
// Unorderedmap => Similar to map, but not sorted

// Concept of comparator => Whenever we have to sort according to our own rules, then we create a comparator

// When using a comparator in sorting, return true if the elements are already in the correct order. Return false if they need to be swapped.[Remember you are handling all the cases]

// TASK => We have a vector of pair, sort it according to second element and when second element is same, then sort according to first element but in descending order.

bool comp(pair<int, int> p1, pair<int, int> p2){
    if (p1.second < p2.second) return true; // Smaller second comes first
    if (p1.second > p2.second) return false; // Larger second comes later
    // When second elements are equal
    if (p1.first > p2.first) return true;
    else return false;
}

void extraConcept(){

    // Sort function of stl
    
    vector<int> v = {4,5,6,1,4,9,10,5,9,50};
    sort(v.begin(), v.end());
    print_vector(v);

    v = {4,5,6,1,4,9,10,5,9,50};
    sort(v.begin(), v.begin()+5); //Sorting selected range of elements
    print_vector(v);

    // For reverse sorting, i.e. in reverse order
    sort(v.begin(), v.end(), greater<int>()); //Just remember the syntax
    print_vector(v);

    // Customized sorting => We have a vector of pair, sort it according to second element and when second element is same, then sort according to first element but in descending order.

    vector<pair<int, int>> arr = {{1,2},{2,1},{4,1}};
    sort(arr.begin(), arr.end(), comp);
    for (auto i : arr){
        cout<<i.first<<" "<<i.second<<endl;
    }

    // Max and Min element of the container
    int maxi = *max_element(v.begin(), v.end());
    int mini = *min_element(v.begin(), v.end());
    cout<<"Maximum element =>"<<maxi<<", Minimum element =>"<<mini<<endl;

    // To get all the permutation of a string  <IMPORTANT>

    // std::next_permutation is a function from <algorithm>.
    
    // It rearranges elements into the next lexicographically greater permutation.
    
    // If such a permutation exists, it returns true.
    
    // If it's the last permutation, it rearranges to the first (sorted) permutation and returns false.

    // 📌 Important: To generate all permutations in order, start from a sorted sequence.

    vector<int> vec_r = {1, 2, 3};

    // Must be sorted to get permutations in order
    sort(vec_r.begin(), vec_r.end());

    do {
        for (int x : vec_r) cout << x << " ";
        cout << "\n";
    } while (next_permutation(vec_r.begin(), vec_r.end()));


    // Similarly for string

    string s = "cba";
    sort(s.begin(), s.end());
    do {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));

}

int main(){
    // Pair();
    // Vector();
    // List();
    // Deque();
    // Stack();
    // Queue();
    // PriorityQueue();
    // Set();
    // Map();
    // extraConcept();
    return 0;
}   


