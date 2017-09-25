#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>

template <class RandomAccessIterator, class Compare>
  void my_merge_sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp)
  {
      //static assert
      auto dist = distance(first, last);
      if (dist <= 1)
          return;

      if (dist == 2)
      {
          if (comp(*first, *(first + 1)))
              std::swap(*first, *(first + 1));
          return;
      }

      //разбиение на подпоследовательности
      RandomAccessIterator middle = first + (dist)/2;
      my_merge_sort(first, middle, comp);
      my_merge_sort(middle, last, comp);

      //слияние уже отсортированных
      RandomAccessIterator it_1st_part = first;
      RandomAccessIterator it_2nd_part = middle;

      //доп. память для слияния
      std::vector<typename std::iterator_traits<RandomAccessIterator>::value_type> merge_vector;

      while (it_1st_part < middle && it_2nd_part < last)
      {
          if (*it_1st_part <= *it_2nd_part) //берем элемент из первой части
          {
              merge_vector.push_back(*it_1st_part);
              ++it_1st_part;
          }
          else //берем элемент из второй части
          {
              merge_vector.push_back(*it_2nd_part);
              ++it_2nd_part;
          }
      } //один из итераторов вышел за границы своей части, осталось просто добрать вторую уже отсорт. часть
      while (it_1st_part < middle)
      {
          merge_vector.push_back(*it_1st_part);
          ++it_1st_part;
      }
      while (it_2nd_part < last)
      {
          merge_vector.push_back(*it_2nd_part);
          ++it_2nd_part;
      }
      // копируем в оригинал отсортированный массив
      auto copy_iter = first;
      for (auto it: merge_vector)
      {
          *copy_iter = it;
          ++copy_iter;
      }
  }

#endif // MERGE_SORT_H
