#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;
  // void print() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data;
  int m;
  PComparator comp;




};



// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : m(m), comp(c) {  

}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {  
  // delete c;

}



// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data.front();



}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");

  }
  std::swap(data[0], data[data.size()-1]);
  data.pop_back();
  std::size_t index = 0;

  while(index < data.size()) {
    size_t bestIdx = m * index + 1;
    if (bestIdx >= data.size()) {
      break;
    }
    // T& best = data[bestIdx];
    for (int i = 1; i <= m; ++i) {
      // get the child and compare
      std::size_t indexChild = m * index + i;

      if (indexChild < data.size()) {
        if (comp(data[indexChild], data[bestIdx])) {
          // best = child;
          bestIdx = indexChild;

        }
      } else {
        break;
      }
      

    }
    // if (bestIdx == index) {
    //   break;
    // }

    if (!comp(data[bestIdx], data[index])) {
      break;
    }
    

    std::swap(data[index], data[bestIdx]);
    index = bestIdx;

  }

}
// template <typename T, typename PComparator>
// void Heap<T,PComparator>::print() const {
//   for (size_t i = 0; i < data.size(); i++) {
//     std::cout << " " << data[i];
//   }
//   std::cout << std::endl;
// }


template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
    data.push_back(item);
    std::size_t index = data.size() - 1;
    while (index != 0) {
        std::size_t parentIdx = (index - 1) / m;
        T& current = data[index];
        T& parent = data[parentIdx];
        if (comp(parent, current)) {
            break;
        }
        std::swap(current, parent);
        index = parentIdx;
    }  
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
  return data.empty();

}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
  return data.size();
}




#endif

