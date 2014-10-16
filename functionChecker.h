#ifndef FUNCTIONCHECKER_H
#define FUNCTIONCHECKER_H

#include <array>
#include <iostream>

//IsPrimitiveValue
//{

template<class T>
struct IsPrimitiveType {
    enum { value = 0 };
};

template<>
struct IsPrimitiveType<int> {
    enum { value = 1 };
};

template<>
struct IsPrimitiveType<char> {
    enum { value = 1 };
};
template<>
struct IsPrimitiveType<unsigned char> {
    enum { value = 1 };
};

template<>
struct IsPrimitiveType<signed char> {
    enum { value = 1 };
};

template<>
struct IsPrimitiveType<short> {
    enum { value = 1 };
};

template<>
struct IsPrimitiveType<long> {
    enum { value = 1 };
};

template<>
struct IsPrimitiveType<long long> {
    enum { value = 1 };
};

template<>
struct IsPrimitiveType<unsigned long> {
    enum { value = 1 };
};

template<>
struct IsPrimitiveType<unsigned int> {
    enum { value = 1 };
};

template<>
struct IsPrimitiveType<unsigned short> {
    enum { value = 1 };
};

template<>
struct IsPrimitiveType<double> {
    enum { value = 1 };
};

template<>
struct IsPrimitiveType<float> {
    enum { value = 1 };
};

//Just adding this one in for completion.
template<>
struct IsPrimitiveType<void> {
    enum { value = 1 };
};




// ...

/*
template<class T>
void testPrimative() {
    if (IsPrimitiveType<T>::VALUE) {
        // ...
    } else {
        // ...
    }
}
*/


//}

template<typename F>
struct is_class
{
  typedef char (&yes)[7];
  typedef char (&no)[3];

  template <typename U>
  static yes check (int U::*);

  template <typename>
  static no check (...);

  enum { value = (sizeof(check<F>(0)) == sizeof(yes)) };
};


/*
template<typename U>
struct is_class
{
  typedef char (&yes)[7];
  typedef char (&no)[3];

  template <typename V>
  static yes check (int V::*);

  template <typename>
  static no check (...);

  enum { value = (sizeof(check<T>(0)) == sizeof(yes)) };
};

*/



struct Support {}; bool operator<(Support,Support) { return false; }
struct DoesNotSupport{};

template <class T>
struct supports_less_than
{
  template <typename U>
  static auto less_than_test(const U* u) -> decltype(*u < *u, char(0))
  { }

  static std::array<char, 2> less_than_test(...) { }

  static const bool value = (sizeof(less_than_test((T*)0)) == 1);
};

template <class T>
struct supports_greater_than
{
  template <typename U>
  static auto less_than_test(const U* u) -> decltype(*u < *u, char(0))
  { }

  static std::array<char, 2> less_than_test(...) { }

  static const bool value = (sizeof(less_than_test((T*)0)) == 1);
};

template <class T>
struct supports_equal_to
{
  template <typename U>
  static auto less_than_test(const U* u) -> decltype(*u < *u, char(0))
  { }

  static std::array<char, 2> less_than_test(...) { }

  static const bool value = (sizeof(less_than_test((T*)0)) == 1);
};

/*


template<typename T> struct has_equal_compare {

   typedef char yes[1];
    typedef char no[2];

    template <typename U, U> struct type_check;
    template <typename V> static char (& chk(type_check< bool (T::*)(T), &V::operator== >*))[1];
    template <typename> static char (& chk(...))[2];
    static bool const value = (sizeof(chk<T>(0)) == 1);
};

template<typename T> struct has_less_than_compare {
    template <typename U, U> struct type_check;
    template <typename V> static char (& chk(type_check< bool (T::*)(T), &V::operator< >*))[1];
    template <typename> static char (& chk(...))[2];
    static bool const value = (sizeof(chk<T>(0)) == 1);
};

template<typename T> struct has_greater_than_compare {
    template <typename U, U> struct type_check;
    template <typename V> static char (& chk(type_check< bool (T::*)(T), &V::operator> >*))[1];
    template <typename> static char (& chk(...))[2];
    static bool const value = (sizeof(chk<T>(0)) == 1);
};


*/

//http://stackoverflow.com/questions/16132123/c-templates-how-to-find-whether-the-template-type-is-a-basic-type-or-a-class




//struct A {
//    void foo();
//    bool operator==(A compare);
//};



//   cout << boolalpha << has_foo<A, void (A::*)()>::value << endl; // true
//   cout << boolalpha << has_compare<A, bool (A::*)(A)>::value << endl; // true


#endif // FUNCTIONCHECKER_H_INCLUDED
