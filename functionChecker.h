#ifndef FUNCTIONCHECKER_H
#define FUNCTIONCHECKER_H



//IsPrimitiveValue
//{
template<class T>
struct IsPrimitiveType {
    enum { VALUE = 0 };
};

template<>
struct IsPrimitiveType<int> {
    enum { VALUE = 1 };
};

template<>
struct IsPrimitiveType<char> {
    enum { VALUE = 1 };
};
template<>
struct IsPrimitiveType<unsigned char> {
    enum { VALUE = 1 };
};

template<>
struct IsPrimitiveType<signed char> {
    enum { VALUE = 1 };
};

template<>
struct IsPrimitiveType<short> {
    enum { VALUE = 1 };
};

template<>
struct IsPrimitiveType<long> {
    enum { VALUE = 1 };
};

template<>
struct IsPrimitiveType<long long> {
    enum { VALUE = 1 };
};

template<>
struct IsPrimitiveType<unsigned long> {
    enum { VALUE = 1 };
};

template<>
struct IsPrimitiveType<unsigned int> {
    enum { VALUE = 1 };
};

template<>
struct IsPrimitiveType<unsigned short> {
    enum { VALUE = 1 };
};

template<>
struct IsPrimitiveType<double> {
    enum { VALUE = 1 };
};

template<>
struct IsPrimitiveType<float> {
    enum { VALUE = 1 };
};

//Just adding this one in for completion.
template<>
struct IsPrimitiveType<void> {
    enum { VALUE = 1 };
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

template<typename T, typename Sig> struct has_equal_compare {
    template <typename U, U> struct type_check;
    template <typename V> static char (& chk(type_check<Sig, &V::operator== >*))[1];
    template <typename  > static char (& chk(...))[2];
    static bool const value = (sizeof(chk<T>(0)) == 1);
};

template<typename T, typename Sig> struct has_less_than_compare {
    template <typename U, U> struct type_check;
    template <typename V> static char (& chk(type_check<Sig, &V::operator< >*))[1];
    template <typename  > static char (& chk(...))[2];
    static bool const value = (sizeof(chk<T>(0)) == 1);
};

template<typename T, typename Sig> struct has_greater_than_compare {
    template <typename U, U> struct type_check;
    template <typename V> static char (& chk(type_check<Sig, &V::operator> >*))[1];
    template <typename  > static char (& chk(...))[2];
    static bool const value = (sizeof(chk<T>(0)) == 1);
};


//http://stackoverflow.com/questions/16132123/c-templates-how-to-find-whether-the-template-type-is-a-basic-type-or-a-class




//struct A {
//    void foo();
//    bool operator==(A compare);
//};



//   cout << boolalpha << has_foo<A, void (A::*)()>::value << endl; // true
//   cout << boolalpha << has_compare<A, bool (A::*)(A)>::value << endl; // true


#endif // FUNCTIONCHECKER_H_INCLUDED
