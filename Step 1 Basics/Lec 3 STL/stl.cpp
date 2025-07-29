#include <iostream>
#include <utility>
#include <list> 
#include <queue> 
#include <stack> 
#include <set> 
#include <unordered_set>
#include <map> 

using namespace std;

void explainPairs(){
    // nested pairs
    pair<int, pair<int, int>> p = {3, {2, 1}};
   
    cout << p.first << ' ' << p.second.first << ' ' << p.second.second << endl;  

    // array of pairs 
    pair <int, int> pairArray[] = {{1, 2}, {3, 4}, {5, 6}};
    int arraySize = sizeof(pairArray) / sizeof(pairArray[0]);
    for (int i = 0; i < arraySize; i++){
        cout << pairArray[i].first << ' ' << pairArray[i].second << endl;
    }
}

void explainVectors(){
    vector<int> v; // creates empty container

    v.push_back(1); // puts 1 in v
    v.emplace_back(2); // pushes 2 in back of v = {1, 2} more efficient than pb

    vector<pair<int, int>> vec; 
    vec.push_back({1, 2}); 
    vec.emplace_back(3, 4); // no need for curly braces 
    // cout << vec[0].first << ' ' << vec[1].second;

    cout << v.back() << endl; // prints last element in vector 

    vector<int> empty(5); // creates empty vector with 5 elements 
    vector<int> preFilled(5, 100); // 5 times 100 is stored in preFilled
    vector <int> copyVector(preFilled); // passing vector will make new vec it's copy 
    for (int i = 0; i < preFilled.size(); i++){
        cout << preFilled[i] << ' ';
    }
    cout << endl;

    // iterators 
    vector <int> vect = {10, 20, 30, 40, 50};
    vector<int>::iterator iter = vect.begin(); // iterator now holds address of first element of vect
    printf("%p, holds %d\n", (void*)&(*iter), *iter); // *iter gives the element at iter address
    iter += 2; // moves iterator 2 positions forward
    iter ++; // moves iterator to next element 
    printf("%p, holds %d\n\n", (void*)&(*iter), *iter); // see notes for a solid explanation of (void*)(&(*iter))

    // other iterators: 
    // vector<int>::iterator iter = vect.end(); **** points to element after last element, need to do iter-- to get iterator to last element. 
    // vector<int>::iterator iter = vect.rbegin(); *** reverse iterators - work stupidly never used 
    // vector<int>::iterator iter = vect.rend();     

    // looping over vector with iterator 
    for(vector<int>::iterator it = vect.begin(); it != vect.end(); it++){
        cout << *(it)<< ' '; 
    }
    cout << endl;

    // auto = automatically assigns data type
    for(auto it = vect.begin(); it != vect.end(); it++){
        cout << *(it) << ' ';
    }
    cout << endl;

    // using for each loop 
    for (auto it : vect){
        cout << it << ' '; // here it is element not iterator 
    }
    cout << endl;

    // deleting elements (reshuffles array to accomodate deleted) 
    vect.erase(vect.begin()+1); // deletes second element (pass address of elemenet to delete) 
    for (auto it : vect){
        cout << it << ' '; // here it is element not iterator 
    }
    cout << endl;
    vect.erase(vect.begin()+1, vect.begin()+3); // start -> end not including end meaning one before end element is erased
    for (auto it : vect){
        cout << it << ' '; // here it is element not iterator 
    } cout << endl;

    // inserting elements 
    vector <int> blueberry(5, 100);
    blueberry.insert(blueberry.begin(), 200); 
    for(auto i: blueberry){
        cout << i << ' ';
    } cout << endl;
    // inserting multiple 
    blueberry.insert(blueberry.begin()+1, 3, 5); // (position, how many?, what?)
    for(auto i: blueberry){
        cout << i << ' ';
    } cout << endl;
    // inserting vector into vector
    // blueberry.insert(blueberry.begin()+2, copy.begin(), copy.end()-3) // where? from where? to) where? take note of type of brakcet i used here

    // size
    cout << blueberry.size() << endl;
    cout << "what "; 
    blueberry.pop_back(); // removes last element 
    blueberry.clear(); // shrinks it to empty vector 
    cout << blueberry.empty(); // empty or non empty true false
}

void explainLists(){ 
    // requires importing list 
    list<int> ls; 

    ls.push_back(2); // {2}
    ls.emplace_back(3); // {2, 3}

    ls.push_front(5); // {5, 2, 3}
    ls.emplace_front(1); // {1, 5, 2, 3}; 
    // pushing to front is much better than inserting in front like in vector 
    // underneath, for vector -> singly linked list 
    // for list -> doubly linked list 

    // rest functions are same 
    // begin, end, rbegin, rend..
}

void explainDeque(){
    deque<int> dq; 
    dq.push_back(1); 
    dq.emplace_back(2); // {1, 2}
    dq.push_front(3); // {3, 1, 2}
    dq.emplace_front(4); // {4, 3, 1, 2} 

    dq.pop_back(); // {4, 3, 1}; 
    dq.pop_front(); // {3, 1}; 

    cout << dq.back() << endl; 
    cout << dq.front(); 

}

void explainStack(){
    // stack is LIFO
    stack<int> st; 
    st.push(1); // {1}
    st.push(2); // {2, 1}
    st.push(3); // {3, 2, 1}
    st.emplace(5); // {5, 3, 2, 1}; 

    // can only use top to see top element. indexing into any element is not allowed
    cout << st.top(); 
    st.pop(); // {3, 2, 1}; 
    cout << st.top(); 

    st.size(); // 3
    // same vector functions
}

void explainQueue(){
    // FIFO
    queue<int> q; 
    q.push(1); // {1} 
    q.push(2); // {1, 2}
    q.push(4); // {1, 2, 4} 

    q.back() += 5; // {1, 2, 9} (back is basically last element)
    cout << q.front(); // 1
    q.pop(); // removes first element 1 
    cout << q.front(); // 2  Q-> {2, 9}
}

void explainPQ(){
    // aka max heap
    priority_queue<int>pq;
    // data is not stored inside in a linear fashion, some tree format to maintain order according to value 

    pq.push(5); // {5}
    pq.push(2); // {5, 2}
    pq.push(8); // {8, 5, 2}
    pq.emplace(10); // {10, 8, 5, 2}; 

    cout << pq.top(); // 10

    pq.pop(); // {8, 5, 2}; 

    cout << pq.top(); // 8

    // priority queue that stores minimum element at top 
    // Minimum Heap 
    priority_queue <int, vector<int>, greater<int>> pq; 
    pq.push(5); // {5}
    pq.push(2); // {2, 5}
    pq.push(8); // {2, 5, 8}; 
    pq.push(10); // {2, 5, 8, 10}

    cout << pq.top(); 
    // push -> O(logn)
    // top -> O(1)
    // pop -> O(logn)
}

void explainSet(){
    // stores everything in sorted order
    // everything is unique
    set <int> st;
    st.insert(1); 
    st.emplace(2); // {1, 2}
    st.insert(2); // {1, 2}
    st.insert(4); // {1, 2, 4};
    st.insert(3); // {1, 2, 3, 4}

    // returns iterator pointing to found address
    auto it = st.find(3); 
    // returns iterator pointing to st.end() if not found
    auto it = st.find(9); 

    st.erase(2); // takes logarithmic time 
    // can also give address to erase
    auto it = st.find(2);
    st.erase(it); 
    // [start, stop)
    // st.erase(start, stop); 

    // since set stores unique
    // cnt = 0 -> does not exist in set
    // cnt = 1 -> exists in set 
    int cnt = st.count(1); 

    // insert, erase everything takes O(logn)
}

void explainMultiSet(){
    // everything same as set 
    // allows storing multiple elements 
    // same sorted fashion

    multiset<int> ms; 
    ms.insert(1); 
    ms.insert(1);
    ms.insert(1); // {1, 1, 1}

    ms.erase(1); // deletes all occurences of 1
    // ms.erase(<element>) removes all occurences of element from multiset 
    ms.erase(ms.find(1)); // removes 1 occurence from set 
    // ms.erase(ms.find(1), ms.find(1) + 3); // removes 3 
}

void explainUSet(){
    unordered_set<int> us; 
    // same as set, except no order is maintained.
    // therefore gives better complexity 
    // lowerbound and upperbound functions dont work other than that all same. 
    
    // O(1) for operations
    // O(n) worst case, happens once in a blue moon, why??? 
}

void explainMap(){
    // stores everything like <key, value> 
    // stores unique keys in sorted order 
    map<int, int>mpp;
    map<int, pair<int, int>> mpp; 
    map<pair<int, int>, int> mpp; 

    mpp[1] = 2;  
    mpp.insert({2, 4}); 

    for (auto it : mpp){ 
        cout << it.first << ' ' << it.second << endl;
        // it.first -> key
        // it.second -> value
    }

    auto it = mpp.find(3); 
    // shows error, why????
    // cout << *(it).second;

    // syntax for lower and upper bound 
    auto it = mpp.lower_bound(2); 
    auto it = mpp.upper_bound(3); 
    

    // erase, swap, size, empty are same 
}

void explainMultiMap(){ 
    // same as map, but allows duplicate keys 
    // mpp[key] cannot be used, but everything is sorted
}

void explainUnorderedMap(){
    // same as map but no sorting, 
    // unique keys </ 
}

bool comp(pair <int, int> p1, pair <int, int> p2){
    // true if both pairs are in correct order 
    // false if swapping is required 
    
    if(p1.second < p2.second) return true;
    if (p1.second > p2.second) return false; 
    
    if (p1.first > p2.first) return true; 
    return false; 
}

void explainExtra(){
    // sort(v.begin(), v.end()); // [start, end)
    // sort(a, a+n, greater<int>); // descending sort 

    // crazy sorting (my way) 
    pair <int, int> a[] = {{1, 2}, {2, 1}, {4, 1}}; 

    // sort according to second element in ascending order 
    // if same second element 
    // sort according to first element in descending order 

    // comp is a self written comparator (boolean function) 
    // sort(a, a+n, comp); 
    // // {{4, 1}, {2, 1}, {4, 1}}; 

    // int num = 7;
    // int cnt = __builtin_popcount(); // 3;

    // long long num = 123123123123;
    // int cnt = __builtin_popcountll(); 

    // // printing all permutations of string 
    // string s = "123";
    // // must start in sorted fashion to print all permutations 
    // sort(s.begin(), s.end()); 
    // do {
    //     cout << s << endl; 
    // } while (next_permutation(s.begin(), s.end()));  

    // int maxi = *max_element(a, a+n); 
}

int main(){ 
    // explainPairs();
    // explainVectors();
    // explainLists(); 
    // explainDeque(); 
    // explainStack(); 
    // explainQueue();
    // explainPQ();
    // explainSet();
    // explainMultiSet();
    // explainUSet();
    // explainMap();
    // explainMultiMap(); 
    // explainUnorderdMap(); 
    // explainExtra(); 
}
