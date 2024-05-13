/***********************************************************************
 * WHORN.h
 * author: hlajungo
 * email: hlajungo@gmail.com
 * date: 2024/05/12
 *
 * 這個文件包含的功能是提供一個接收一個參數X的宏，能夠輸出X的信息，在DEBUG模式下提供。
 * 他在C++20,C++17,C++14應該要能正常工作。
 * 他在C++23,C++11,UntilC++17不一定能正常工作，因為Visual Studio 2022只有14，17，20，但是為了完整性還是寫上了。
 * reference:
 * https://en.cppreference.com/w/cpp/preprocessor/replace#Predefined_macros
 * https://en.cppreference.com/w/cpp/meta#Type_traits
 ***********************************************************************/
#ifndef WHORU_H 
#define WHORU_H

#include <iostream>
#include <sstream>




#ifdef _DEBUG

 // cpp version
#if     __cplusplus >= 202302L //c++23
#define CPP23_OR_GREATER 1
#define IF_CONSTEXPR if constexpr

#define WHORU(var) \
do { \
    std::stringstream ss; \
    ss << "WHORU [" << typeid(decltype(var)).name() << "] " << #var << "\nBASIC\n"; \
    IF_CONSTEXPR (std::is_object<decltype(var)>::value) { \
        ss << "[ object ] "; \
        IF_CONSTEXPR (std::is_scalar<decltype(var)>::value) ss << "-> [ scalar ] "; \
        ss << '\n';} \
    IF_CONSTEXPR (std::is_fundamental<decltype(var)>::value) { \
        ss << "[ fundamental ] "; \
        IF_CONSTEXPR (std::is_void<decltype(var)>::value) ss << "->  [ void ] "; \
        IF_CONSTEXPR (std::is_null_pointer<decltype(var)>::value) ss << "-> [ null pointer ] "; \
        IF_CONSTEXPR (std::is_arithmetic<decltype(var)>::value) { \
            ss << "-> [ arithmetic ] "; \
            IF_CONSTEXPR (std::is_integral<decltype(var)>::value) ss << "-> [ integral ] "; \
            IF_CONSTEXPR (std::is_floating_point<decltype(var)>::value) ss << "-> [ floating point ] "; \
            IF_CONSTEXPR  (std::is_signed<decltype(var)>::value) ss << "-> [ signed ] "; \
            IF_CONSTEXPR  (std::is_unsigned<decltype(var)>::value) ss << "-> [ unsigned ] ";} \
        ss << '\n'; } \
    IF_CONSTEXPR (std::is_compound<decltype(var)>::value) { \
        ss << "[ compound ] "; \
        IF_CONSTEXPR (std::is_function<decltype(var)>::value) ss << "-> [ function ] "; \
        IF_CONSTEXPR (std::is_reference<decltype(var)>::value) { \
            ss << "-> [ reference ] "; \
            IF_CONSTEXPR (std::is_lvalue_reference<decltype(var)>::value) ss << "-> [ lvalue reference ] "; \
            IF_CONSTEXPR (std::is_rvalue_reference<decltype(var)>::value) ss << "-> [ rvalue reference ] "; } \
        IF_CONSTEXPR (std::is_array<decltype(var)>::value) { \
            ss << "-> [ array ] "; \
            IF_CONSTEXPR (std::is_bounded_array<decltype(var)>::value) ss << "-> [ bounded array ] "; \
            IF_CONSTEXPR (std::is_unbounded_array<decltype(var)>::value) ss << "-> [ unbounded array ] "; }\
        IF_CONSTEXPR (std::is_union<decltype(var)>::value) ss << "-> [ union ] "; \
        IF_CONSTEXPR (std::is_class<decltype(var)>::value) { \
            ss << "-> [ class ] "; \
            IF_CONSTEXPR (std::is_empty<decltype(var)>::value) ss << "-> [ empty class ] "; \
            IF_CONSTEXPR (std::is_polymorphic<decltype(var)>::value) { \
                ss << "-> [ polymorphic class ] "; \
                IF_CONSTEXPR (std::is_abstract<decltype(var)>::value) ss << "-> [ abstract class ] "; } \
            IF_CONSTEXPR (std::is_final<decltype(var)>::value) ss << "-> [ final class ] "; \
            IF_CONSTEXPR (std::is_aggregate<decltype(var)>::value) ss << "-> [ aggregate ] "; } \
        IF_CONSTEXPR (std::is_pointer<decltype(var)>::value) ss << "-> [ pointer ] "; \
        IF_CONSTEXPR (std::is_enum<decltype(var)>::value) ss << "-> [ enum ] "; \
        IF_CONSTEXPR (std::is_member_pointer<decltype(var)>::value) { \
            ss << "-> [ member pointer ] "; \
            IF_CONSTEXPR (std::is_member_object_pointer<decltype(var)>::value) ss << "-> [ member object pointer ] "; \
            IF_CONSTEXPR (std::is_member_function_pointer<decltype(var)>::value) ss << "-> [ member function pointer ] "; } \
        ss << '\n'; } \
    IF_CONSTEXPR (std::is_const<decltype(var)>::value) ss << "[ const ] \n"; \
    IF_CONSTEXPR (std::is_volatile<decltype(var)>::value) ss << "[ volatile ] \n"; \
     ss << "CLASS_PROPERTIES\n";\
IF_CONSTEXPR (std::is_constructible<decltype(var)>::value) {\
	ss << "[ constructible ] ";\
	IF_CONSTEXPR (std::is_default_constructible<decltype(var)>::value) ss << "-> [ default constructible ] ";\
	IF_CONSTEXPR (std::is_copy_constructible<decltype(var)>::value) ss << "-> [ copy constructible ] ";\
	IF_CONSTEXPR (std::is_move_constructible<decltype(var)>::value) ss << "-> [ move constructible ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_assignable<decltype(var), decltype(var)>::value) {\
	ss << "[ assignable ] ";\
	IF_CONSTEXPR (std::is_copy_assignable<decltype(var)>::value) ss << "-> [ copy assignable ] ";\
	IF_CONSTEXPR (std::is_move_assignable<decltype(var)>::value) ss << "-> [ move assignable ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_destructible<decltype(var)>::value) {\
	ss << "[ destructible ] ";\
	IF_CONSTEXPR (std::has_virtual_destructor<decltype(var)>::value) ss << "-> [ virtual destructor ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_swappable<decltype(var)>::value) {\
	ss << "[ swappable ] ";\
	IF_CONSTEXPR (std::is_nothrow_swappable<decltype(var)>::value) ss << "-> [ nothrow swappable ] "; \
	ss << '\n';}\
ss << "CLASS_PROPERTIES_TRIVIAL\n";\
IF_CONSTEXPR (std::is_trivial<decltype(var)>::value) ss << "[ trivial ] \n";\
IF_CONSTEXPR (std::is_trivially_copyable<decltype(var)>::value) ss << "[ trivially copyable ] \n";\
IF_CONSTEXPR (std::is_trivially_constructible<decltype(var)>::value) {\
	ss << "[ trivially constructible ] ";\
	IF_CONSTEXPR (std::is_trivially_default_constructible<decltype(var)>::value) ss << "-> [ trivially default constructible ] ";\
	IF_CONSTEXPR (std::is_nothrow_constructible<decltype(var)>::value) {\
		ss << "-> [ nothrow constructible ] ";\
		IF_CONSTEXPR (std::is_nothrow_default_constructible<decltype(var)>::value) ss << "-> [ nothrow default constructible ] ";\
		ss << '\n';}}\
IF_CONSTEXPR (std::is_trivially_copy_constructible<decltype(var)>::value) {\
	ss << "[ trivially copy constructible ] ";\
	IF_CONSTEXPR (std::is_nothrow_copy_constructible<decltype(var)>::value) ss << "-> [ nothrow copy constructible ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_trivially_move_constructible<decltype(var)>::value) {\
	ss << "[ trivially move constructible ] ";\
	IF_CONSTEXPR (std::is_nothrow_move_constructible<decltype(var)>::value) ss << "-> [ nothrow move constructible ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_trivially_copy_assignable<decltype(var)>::value) {\
	ss << "[ trivially copy assignable ] ";\
	IF_CONSTEXPR (std::is_nothrow_copy_assignable<decltype(var)>::value) ss << "-> [ nothrow copy assignable ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_trivially_move_assignable<decltype(var)>::value) {\
	ss << "[ trivially move assignable ] ";\
	IF_CONSTEXPR (std::is_nothrow_move_assignable<decltype(var)>::value) ss << "-> [ nothrow move assignable ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_trivially_destructible<decltype(var)>::value) {\
	ss << "[ trivially destructible ] ";\
	IF_CONSTEXPR (std::is_nothrow_destructible<decltype(var)>::value) ss << "-> [ nothrow destructible ] ";\
	ss << '\n';}\
ss << "[ alignment of: " << std::alignment_of<decltype(var)>::value << " ] \n";\
ss << "[ rank: " << std::rank<decltype(var)>::value << " ] \n";\
IF_CONSTEXPR  (std::rank<decltype(var)>::value > 0) ss << "[ extent: " << std::extent<decltype(var), 0>::value << " ] \n";\
IF_CONSTEXPR (std::is_invocable<decltype(var)>::value) ss << "[ invocable ] \n";\
IF_CONSTEXPR (std::is_nothrow_invocable<decltype(var)>::value) ss << "[ nothrow invocable ] \n";\
std::cout << ss.str()<<'\n';\
} while (0)


#elif   __cplusplus >= 202002L //c++20
#define CPP20_OR_GREATER 1
#define IF_CONSTEXPR if constexpr

#define WHORU(var) \
do { \
    std::stringstream ss; \
    ss << "WHORU [" << typeid(decltype(var)).name() << "] " << #var << "\nBASIC\n"; \
    IF_CONSTEXPR (std::is_object<decltype(var)>::value) { \
        ss << "[ object ] "; \
        IF_CONSTEXPR (std::is_scalar<decltype(var)>::value) ss << "-> [ scalar ] "; \
        ss << '\n';} \
    IF_CONSTEXPR (std::is_fundamental<decltype(var)>::value) { \
        ss << "[ fundamental ] "; \
        IF_CONSTEXPR (std::is_void<decltype(var)>::value) ss << "->  [ void ] "; \
        IF_CONSTEXPR (std::is_null_pointer<decltype(var)>::value) ss << "-> [ null pointer ] "; \
        IF_CONSTEXPR (std::is_arithmetic<decltype(var)>::value) { \
            ss << "-> [ arithmetic ] "; \
            IF_CONSTEXPR (std::is_integral<decltype(var)>::value) ss << "-> [ integral ] "; \
            IF_CONSTEXPR (std::is_floating_point<decltype(var)>::value) ss << "-> [ floating point ] "; \
            IF_CONSTEXPR  (std::is_signed<decltype(var)>::value) ss << "-> [ signed ] "; \
            IF_CONSTEXPR  (std::is_unsigned<decltype(var)>::value) ss << "-> [ unsigned ] ";} \
        ss << '\n'; } \
    IF_CONSTEXPR (std::is_compound<decltype(var)>::value) { \
        ss << "[ compound ] "; \
        IF_CONSTEXPR (std::is_function<decltype(var)>::value) ss << "-> [ function ] "; \
        IF_CONSTEXPR (std::is_reference<decltype(var)>::value) { \
            ss << "-> [ reference ] "; \
            IF_CONSTEXPR (std::is_lvalue_reference<decltype(var)>::value) ss << "-> [ lvalue reference ] "; \
            IF_CONSTEXPR (std::is_rvalue_reference<decltype(var)>::value) ss << "-> [ rvalue reference ] "; } \
        IF_CONSTEXPR (std::is_array<decltype(var)>::value) { \
            ss << "-> [ array ] "; \
            IF_CONSTEXPR (std::is_bounded_array<decltype(var)>::value) ss << "-> [ bounded array ] "; \
            IF_CONSTEXPR (std::is_unbounded_array<decltype(var)>::value) ss << "-> [ unbounded array ] "; }\
        IF_CONSTEXPR (std::is_union<decltype(var)>::value) ss << "-> [ union ] "; \
        IF_CONSTEXPR (std::is_class<decltype(var)>::value) { \
            ss << "-> [ class ] "; \
            IF_CONSTEXPR (std::is_empty<decltype(var)>::value) ss << "-> [ empty class ] "; \
            IF_CONSTEXPR (std::is_polymorphic<decltype(var)>::value) { \
                ss << "-> [ polymorphic class ] "; \
                IF_CONSTEXPR (std::is_abstract<decltype(var)>::value) ss << "-> [ abstract class ] "; } \
            IF_CONSTEXPR (std::is_final<decltype(var)>::value) ss << "-> [ final class ] "; \
            IF_CONSTEXPR (std::is_aggregate<decltype(var)>::value) ss << "-> [ aggregate ] "; } \
        IF_CONSTEXPR (std::is_pointer<decltype(var)>::value) ss << "-> [ pointer ] "; \
        IF_CONSTEXPR (std::is_enum<decltype(var)>::value) ss << "-> [ enum ] "; \
        IF_CONSTEXPR (std::is_member_pointer<decltype(var)>::value) { \
            ss << "-> [ member pointer ] "; \
            IF_CONSTEXPR (std::is_member_object_pointer<decltype(var)>::value) ss << "-> [ member object pointer ] "; \
            IF_CONSTEXPR (std::is_member_function_pointer<decltype(var)>::value) ss << "-> [ member function pointer ] "; } \
        ss << '\n'; } \
    IF_CONSTEXPR (std::is_const<decltype(var)>::value) ss << "[ const ] \n"; \
    IF_CONSTEXPR (std::is_volatile<decltype(var)>::value) ss << "[ volatile ] \n"; \
     ss << "CLASS_PROPERTIES\n";\
IF_CONSTEXPR (std::is_constructible<decltype(var)>::value) {\
	ss << "[ constructible ] ";\
	IF_CONSTEXPR (std::is_default_constructible<decltype(var)>::value) ss << "-> [ default constructible ] ";\
	IF_CONSTEXPR (std::is_copy_constructible<decltype(var)>::value) ss << "-> [ copy constructible ] ";\
	IF_CONSTEXPR (std::is_move_constructible<decltype(var)>::value) ss << "-> [ move constructible ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_assignable<decltype(var), decltype(var)>::value) {\
	ss << "[ assignable ] ";\
	IF_CONSTEXPR (std::is_copy_assignable<decltype(var)>::value) ss << "-> [ copy assignable ] ";\
	IF_CONSTEXPR (std::is_move_assignable<decltype(var)>::value) ss << "-> [ move assignable ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_destructible<decltype(var)>::value) {\
	ss << "[ destructible ] ";\
	IF_CONSTEXPR (std::has_virtual_destructor<decltype(var)>::value) ss << "-> [ virtual destructor ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_swappable<decltype(var)>::value) {\
	ss << "[ swappable ] ";\
	IF_CONSTEXPR (std::is_nothrow_swappable<decltype(var)>::value) ss << "-> [ nothrow swappable ] "; \
	ss << '\n';}\
ss << "CLASS_PROPERTIES_TRIVIAL\n";\
IF_CONSTEXPR (std::is_trivial<decltype(var)>::value) ss << "[ trivial ] \n";\
IF_CONSTEXPR (std::is_trivially_copyable<decltype(var)>::value) ss << "[ trivially copyable ] \n";\
IF_CONSTEXPR (std::is_trivially_constructible<decltype(var)>::value) {\
	ss << "[ trivially constructible ] ";\
	IF_CONSTEXPR (std::is_trivially_default_constructible<decltype(var)>::value) ss << "-> [ trivially default constructible ] ";\
	IF_CONSTEXPR (std::is_nothrow_constructible<decltype(var)>::value) {\
		ss << "-> [ nothrow constructible ] ";\
		IF_CONSTEXPR (std::is_nothrow_default_constructible<decltype(var)>::value) ss << "-> [ nothrow default constructible ] ";\
		ss << '\n';}}\
IF_CONSTEXPR (std::is_trivially_copy_constructible<decltype(var)>::value) {\
	ss << "[ trivially copy constructible ] ";\
	IF_CONSTEXPR (std::is_nothrow_copy_constructible<decltype(var)>::value) ss << "-> [ nothrow copy constructible ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_trivially_move_constructible<decltype(var)>::value) {\
	ss << "[ trivially move constructible ] ";\
	IF_CONSTEXPR (std::is_nothrow_move_constructible<decltype(var)>::value) ss << "-> [ nothrow move constructible ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_trivially_copy_assignable<decltype(var)>::value) {\
	ss << "[ trivially copy assignable ] ";\
	IF_CONSTEXPR (std::is_nothrow_copy_assignable<decltype(var)>::value) ss << "-> [ nothrow copy assignable ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_trivially_move_assignable<decltype(var)>::value) {\
	ss << "[ trivially move assignable ] ";\
	IF_CONSTEXPR (std::is_nothrow_move_assignable<decltype(var)>::value) ss << "-> [ nothrow move assignable ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_trivially_destructible<decltype(var)>::value) {\
	ss << "[ trivially destructible ] ";\
	IF_CONSTEXPR (std::is_nothrow_destructible<decltype(var)>::value) ss << "-> [ nothrow destructible ] ";\
	ss << '\n';}\
ss << "[ alignment of: " << std::alignment_of<decltype(var)>::value << " ] \n";\
ss << "[ rank: " << std::rank<decltype(var)>::value << " ] \n";\
IF_CONSTEXPR  (std::rank<decltype(var)>::value > 0) ss << "[ extent: " << std::extent<decltype(var), 0>::value << " ] \n";\
IF_CONSTEXPR (std::is_invocable<decltype(var)>::value) ss << "[ invocable ] \n";\
IF_CONSTEXPR (std::is_nothrow_invocable<decltype(var)>::value) ss << "[ nothrow invocable ] \n";\
std::cout << ss.str()<<'\n';\
} while (0)

#elif   __cplusplus >= 201703L //c++17
#define CPP17_OR_GREATER 1
#define IF_CONSTEXPR if constexpr

#define WHORU(var) \
do { \
    std::stringstream ss; \
    ss << "WHORU [" << typeid(decltype(var)).name() << "] " << #var << "\nBASIC\n"; \
    IF_CONSTEXPR (std::is_object<decltype(var)>::value) { \
        ss << "[ object ] "; \
        IF_CONSTEXPR (std::is_scalar<decltype(var)>::value) ss << "-> [ scalar ] "; \
        ss << '\n';} \
    IF_CONSTEXPR (std::is_fundamental<decltype(var)>::value) { \
        ss << "[ fundamental ] "; \
        IF_CONSTEXPR (std::is_void<decltype(var)>::value) ss << "->  [ void ] "; \
        IF_CONSTEXPR (std::is_null_pointer<decltype(var)>::value) ss << "-> [ null pointer ] "; \
        IF_CONSTEXPR (std::is_arithmetic<decltype(var)>::value) { \
            ss << "-> [ arithmetic ] "; \
            IF_CONSTEXPR (std::is_integral<decltype(var)>::value) ss << "-> [ integral ] "; \
            IF_CONSTEXPR (std::is_floating_point<decltype(var)>::value) ss << "-> [ floating point ] "; \
            IF_CONSTEXPR  (std::is_signed<decltype(var)>::value) ss << "-> [ signed ] "; \
            IF_CONSTEXPR  (std::is_unsigned<decltype(var)>::value) ss << "-> [ unsigned ] ";} \
        ss << '\n'; } \
    IF_CONSTEXPR (std::is_compound<decltype(var)>::value) { \
        ss << "[ compound ] "; \
        IF_CONSTEXPR (std::is_function<decltype(var)>::value) ss << "-> [ function ] "; \
        IF_CONSTEXPR (std::is_reference<decltype(var)>::value) { \
            ss << "-> [ reference ] "; \
            IF_CONSTEXPR (std::is_lvalue_reference<decltype(var)>::value) ss << "-> [ lvalue reference ] "; \
            IF_CONSTEXPR (std::is_rvalue_reference<decltype(var)>::value) ss << "-> [ rvalue reference ] "; } \
        IF_CONSTEXPR (std::is_array<decltype(var)>::value) { \
            ss << "-> [ array ] "; \
            /*IF_CONSTEXPR (std::is_bounded_array<decltype(var)>::value) ss << "-> [ bounded array ] "; */\
            /*IF_CONSTEXPR (std::is_unbounded_array<decltype(var)>::value) ss << "-> [ unbounded array ] "; */}\
        IF_CONSTEXPR (std::is_union<decltype(var)>::value) ss << "-> [ union ] "; \
        IF_CONSTEXPR (std::is_class<decltype(var)>::value) { \
            ss << "-> [ class ] "; \
            IF_CONSTEXPR (std::is_empty<decltype(var)>::value) ss << "-> [ empty class ] "; \
            IF_CONSTEXPR (std::is_polymorphic<decltype(var)>::value) { \
                ss << "-> [ polymorphic class ] "; \
                IF_CONSTEXPR (std::is_abstract<decltype(var)>::value) ss << "-> [ abstract class ] "; } \
            IF_CONSTEXPR (std::is_final<decltype(var)>::value) ss << "-> [ final class ] "; \
            IF_CONSTEXPR (std::is_aggregate<decltype(var)>::value) ss << "-> [ aggregate ] "; } \
        IF_CONSTEXPR (std::is_pointer<decltype(var)>::value) ss << "-> [ pointer ] "; \
        IF_CONSTEXPR (std::is_enum<decltype(var)>::value) ss << "-> [ enum ] "; \
        IF_CONSTEXPR (std::is_member_pointer<decltype(var)>::value) { \
            ss << "-> [ member pointer ] "; \
            IF_CONSTEXPR (std::is_member_object_pointer<decltype(var)>::value) ss << "-> [ member object pointer ] "; \
            IF_CONSTEXPR (std::is_member_function_pointer<decltype(var)>::value) ss << "-> [ member function pointer ] "; } \
        ss << '\n'; } \
    IF_CONSTEXPR (std::is_const<decltype(var)>::value) ss << "[ const ] \n"; \
    IF_CONSTEXPR (std::is_volatile<decltype(var)>::value) ss << "[ volatile ] \n"; \
     ss << "CLASS_PROPERTIES\n";\
IF_CONSTEXPR (std::is_constructible<decltype(var)>::value) {\
	ss << "[ constructible ] ";\
	IF_CONSTEXPR (std::is_default_constructible<decltype(var)>::value) ss << "-> [ default constructible ] ";\
	IF_CONSTEXPR (std::is_copy_constructible<decltype(var)>::value) ss << "-> [ copy constructible ] ";\
	IF_CONSTEXPR (std::is_move_constructible<decltype(var)>::value) ss << "-> [ move constructible ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_assignable<decltype(var), decltype(var)>::value) {\
	ss << "[ assignable ] ";\
	IF_CONSTEXPR (std::is_copy_assignable<decltype(var)>::value) ss << "-> [ copy assignable ] ";\
	IF_CONSTEXPR (std::is_move_assignable<decltype(var)>::value) ss << "-> [ move assignable ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_destructible<decltype(var)>::value) {\
	ss << "[ destructible ] ";\
	IF_CONSTEXPR (std::has_virtual_destructor<decltype(var)>::value) ss << "-> [ virtual destructor ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_swappable<decltype(var)>::value) {\
	ss << "[ swappable ] ";\
	IF_CONSTEXPR (std::is_nothrow_swappable<decltype(var)>::value) ss << "-> [ nothrow swappable ] "; \
	ss << '\n';}\
ss << "CLASS_PROPERTIES_TRIVIAL\n";\
IF_CONSTEXPR (std::is_trivial<decltype(var)>::value) ss << "[ trivial ] \n";\
IF_CONSTEXPR (std::is_trivially_copyable<decltype(var)>::value) ss << "[ trivially copyable ] \n";\
IF_CONSTEXPR (std::is_trivially_constructible<decltype(var)>::value) {\
	ss << "[ trivially constructible ] ";\
	IF_CONSTEXPR (std::is_trivially_default_constructible<decltype(var)>::value) ss << "-> [ trivially default constructible ] ";\
	IF_CONSTEXPR (std::is_nothrow_constructible<decltype(var)>::value) {\
		ss << "-> [ nothrow constructible ] ";\
		IF_CONSTEXPR (std::is_nothrow_default_constructible<decltype(var)>::value) ss << "-> [ nothrow default constructible ] ";\
		ss << '\n';}}\
IF_CONSTEXPR (std::is_trivially_copy_constructible<decltype(var)>::value) {\
	ss << "[ trivially copy constructible ] ";\
	IF_CONSTEXPR (std::is_nothrow_copy_constructible<decltype(var)>::value) ss << "-> [ nothrow copy constructible ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_trivially_move_constructible<decltype(var)>::value) {\
	ss << "[ trivially move constructible ] ";\
	IF_CONSTEXPR (std::is_nothrow_move_constructible<decltype(var)>::value) ss << "-> [ nothrow move constructible ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_trivially_copy_assignable<decltype(var)>::value) {\
	ss << "[ trivially copy assignable ] ";\
	IF_CONSTEXPR (std::is_nothrow_copy_assignable<decltype(var)>::value) ss << "-> [ nothrow copy assignable ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_trivially_move_assignable<decltype(var)>::value) {\
	ss << "[ trivially move assignable ] ";\
	IF_CONSTEXPR (std::is_nothrow_move_assignable<decltype(var)>::value) ss << "-> [ nothrow move assignable ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_trivially_destructible<decltype(var)>::value) {\
	ss << "[ trivially destructible ] ";\
	IF_CONSTEXPR (std::is_nothrow_destructible<decltype(var)>::value) ss << "-> [ nothrow destructible ] ";\
	ss << '\n';}\
ss << "[ alignment of: " << std::alignment_of<decltype(var)>::value << " ] \n";\
ss << "[ rank: " << std::rank<decltype(var)>::value << " ] \n";\
IF_CONSTEXPR  (std::rank<decltype(var)>::value > 0) ss << "[ extent: " << std::extent<decltype(var), 0>::value << " ] \n";\
IF_CONSTEXPR (std::is_invocable<decltype(var)>::value) ss << "[ invocable ] \n";\
IF_CONSTEXPR (std::is_nothrow_invocable<decltype(var)>::value) ss << "[ nothrow invocable ] \n";\
std::cout << ss.str()<<'\n';\
} while (0)

#elif   __cplusplus >= 201402L //c++14
#define CPP14_OR_GREATER 1
#define IF_CONSTEXPR if 

#define WHORU(var) \
do { \
    std::stringstream ss; \
    ss << "WHORU [" << typeid(decltype(var)).name() << "] " << #var << "\nBASIC\n"; \
    IF_CONSTEXPR (std::is_object<decltype(var)>::value) { \
        ss << "[ object ] "; \
        IF_CONSTEXPR (std::is_scalar<decltype(var)>::value) ss << "-> [ scalar ] "; \
        ss << '\n';} \
    IF_CONSTEXPR (std::is_fundamental<decltype(var)>::value) { \
        ss << "[ fundamental ] "; \
        IF_CONSTEXPR (std::is_void<decltype(var)>::value) ss << "->  [ void ] "; \
        IF_CONSTEXPR (std::is_null_pointer<decltype(var)>::value) ss << "-> [ null pointer ] "; \
        IF_CONSTEXPR (std::is_arithmetic<decltype(var)>::value) { \
            ss << "-> [ arithmetic ] "; \
            IF_CONSTEXPR (std::is_integral<decltype(var)>::value) ss << "-> [ integral ] "; \
            IF_CONSTEXPR (std::is_floating_point<decltype(var)>::value) ss << "-> [ floating point ] "; \
            IF_CONSTEXPR  (std::is_signed<decltype(var)>::value) ss << "-> [ signed ] "; \
            IF_CONSTEXPR  (std::is_unsigned<decltype(var)>::value) ss << "-> [ unsigned ] ";} \
        ss << '\n'; } \
    IF_CONSTEXPR (std::is_compound<decltype(var)>::value) { \
        ss << "[ compound ] "; \
        IF_CONSTEXPR (std::is_function<decltype(var)>::value) ss << "-> [ function ] "; \
        IF_CONSTEXPR (std::is_reference<decltype(var)>::value) { \
            ss << "-> [ reference ] "; \
            IF_CONSTEXPR (std::is_lvalue_reference<decltype(var)>::value) ss << "-> [ lvalue reference ] "; \
            IF_CONSTEXPR (std::is_rvalue_reference<decltype(var)>::value) ss << "-> [ rvalue reference ] "; } \
        IF_CONSTEXPR (std::is_array<decltype(var)>::value) { \
            ss << "-> [ array ] "; \
            /*IF_CONSTEXPR (std::is_bounded_array<decltype(var)>::value) ss << "-> [ bounded array ] ";*/ \
            /*IF_CONSTEXPR (std::is_unbounded_array<decltype(var)>::value) ss << "-> [ unbounded array ] ";*/ }\
        IF_CONSTEXPR (std::is_union<decltype(var)>::value) ss << "-> [ union ] "; \
        IF_CONSTEXPR (std::is_class<decltype(var)>::value) { \
            ss << "-> [ class ] "; \
            IF_CONSTEXPR (std::is_empty<decltype(var)>::value) ss << "-> [ empty class ] "; \
            IF_CONSTEXPR (std::is_polymorphic<decltype(var)>::value) { \
                ss << "-> [ polymorphic class ] "; \
                IF_CONSTEXPR (std::is_abstract<decltype(var)>::value) ss << "-> [ abstract class ] "; } \
            IF_CONSTEXPR (std::is_final<decltype(var)>::value) ss << "-> [ final class ] "; \
            /*IF_CONSTEXPR (std::is_aggregate<decltype(var)>::value) ss << "-> [ aggregate ] "; }*/ \
        IF_CONSTEXPR (std::is_pointer<decltype(var)>::value) ss << "-> [ pointer ] "; \
        IF_CONSTEXPR (std::is_enum<decltype(var)>::value) ss << "-> [ enum ] "; \
        IF_CONSTEXPR (std::is_member_pointer<decltype(var)>::value) { \
            ss << "-> [ member pointer ] "; \
            IF_CONSTEXPR (std::is_member_object_pointer<decltype(var)>::value) ss << "-> [ member object pointer ] "; \
            IF_CONSTEXPR (std::is_member_function_pointer<decltype(var)>::value) ss << "-> [ member function pointer ] "; } \
        ss << '\n'; } \
    IF_CONSTEXPR (std::is_const<decltype(var)>::value) ss << "[ const ] \n"; \
    IF_CONSTEXPR (std::is_volatile<decltype(var)>::value) ss << "[ volatile ] \n"; \
     ss << "CLASS_PROPERTIES\n";\
IF_CONSTEXPR (std::is_constructible<decltype(var)>::value) {\
	ss << "[ constructible ] ";\
	IF_CONSTEXPR (std::is_default_constructible<decltype(var)>::value) ss << "-> [ default constructible ] ";\
	IF_CONSTEXPR (std::is_copy_constructible<decltype(var)>::value) ss << "-> [ copy constructible ] ";\
	IF_CONSTEXPR (std::is_move_constructible<decltype(var)>::value) ss << "-> [ move constructible ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_assignable<decltype(var), decltype(var)>::value) {\
	ss << "[ assignable ] ";\
	IF_CONSTEXPR (std::is_copy_assignable<decltype(var)>::value) ss << "-> [ copy assignable ] ";\
	IF_CONSTEXPR (std::is_move_assignable<decltype(var)>::value) ss << "-> [ move assignable ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_destructible<decltype(var)>::value) {\
	ss << "[ destructible ] ";\
	IF_CONSTEXPR (std::has_virtual_destructor<decltype(var)>::value) ss << "-> [ virtual destructor ] ";\
	ss << '\n';}\
    /*IF_CONSTEXPR (std::is_swappable<decltype(var)>::value) {*/\
	/*ss << "[ swappable ] ";*/\
	/*IF_CONSTEXPR (std::is_nothrow_swappable<decltype(var)>::value) ss << "-> [ nothrow swappable ] ";*/ \
	/*ss << '\n';*/}\
ss << "CLASS_PROPERTIES_TRIVIAL\n";\
IF_CONSTEXPR (std::is_trivial<decltype(var)>::value) ss << "[ trivial ] \n";\
IF_CONSTEXPR (std::is_trivially_copyable<decltype(var)>::value) ss << "[ trivially copyable ] \n";\
IF_CONSTEXPR (std::is_trivially_constructible<decltype(var)>::value) {\
	ss << "[ trivially constructible ] ";\
	IF_CONSTEXPR (std::is_trivially_default_constructible<decltype(var)>::value) ss << "-> [ trivially default constructible ] ";\
	IF_CONSTEXPR (std::is_nothrow_constructible<decltype(var)>::value) {\
		ss << "-> [ nothrow constructible ] ";\
		IF_CONSTEXPR (std::is_nothrow_default_constructible<decltype(var)>::value) ss << "-> [ nothrow default constructible ] ";\
		ss << '\n';}}\
IF_CONSTEXPR (std::is_trivially_copy_constructible<decltype(var)>::value) {\
	ss << "[ trivially copy constructible ] ";\
	IF_CONSTEXPR (std::is_nothrow_copy_constructible<decltype(var)>::value) ss << "-> [ nothrow copy constructible ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_trivially_move_constructible<decltype(var)>::value) {\
	ss << "[ trivially move constructible ] ";\
	IF_CONSTEXPR (std::is_nothrow_move_constructible<decltype(var)>::value) ss << "-> [ nothrow move constructible ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_trivially_copy_assignable<decltype(var)>::value) {\
	ss << "[ trivially copy assignable ] ";\
	IF_CONSTEXPR (std::is_nothrow_copy_assignable<decltype(var)>::value) ss << "-> [ nothrow copy assignable ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_trivially_move_assignable<decltype(var)>::value) {\
	ss << "[ trivially move assignable ] ";\
	IF_CONSTEXPR (std::is_nothrow_move_assignable<decltype(var)>::value) ss << "-> [ nothrow move assignable ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_trivially_destructible<decltype(var)>::value) {\
	ss << "[ trivially destructible ] ";\
	IF_CONSTEXPR (std::is_nothrow_destructible<decltype(var)>::value) ss << "-> [ nothrow destructible ] ";\
	ss << '\n';}\
ss << "[ alignment of: " << std::alignment_of<decltype(var)>::value << " ] \n";\
ss << "[ rank: " << std::rank<decltype(var)>::value << " ] \n";\
IF_CONSTEXPR  (std::rank<decltype(var)>::value > 0) ss << "[ extent: " << std::extent<decltype(var), 0>::value << " ] \n";\
/*IF_CONSTEXPR (std::is_invocable<decltype(var)>::value) ss << "[ invocable ] \n";*/\
/*IF_CONSTEXPR (std::is_nothrow_invocable<decltype(var)>::value) ss << "[ nothrow invocable ] \n";*/\
std::cout << ss.str()<<'\n';\
} while (0)

#elif   __cplusplus >= 201103L //c++11
#define CPP11_OR_GREATER 1
#define IF_CONSTEXPR if

#define WHORU(var) \
do { \
    std::stringstream ss; \
    ss << "WHORU [" << typeid(decltype(var)).name() << "] " << #var << "\nBASIC\n"; \
    IF_CONSTEXPR (std::is_object<decltype(var)>::value) { \
        ss << "[ object ] "; \
        IF_CONSTEXPR (std::is_scalar<decltype(var)>::value) ss << "-> [ scalar ] "; \
        ss << '\n';} \
    IF_CONSTEXPR (std::is_fundamental<decltype(var)>::value) { \
        ss << "[ fundamental ] "; \
        IF_CONSTEXPR (std::is_void<decltype(var)>::value) ss << "->  [ void ] "; \
        IF_CONSTEXPR (std::is_null_pointer<decltype(var)>::value) ss << "-> [ null pointer ] "; \
        IF_CONSTEXPR (std::is_arithmetic<decltype(var)>::value) { \
            ss << "-> [ arithmetic ] "; \
            IF_CONSTEXPR (std::is_integral<decltype(var)>::value) ss << "-> [ integral ] "; \
            IF_CONSTEXPR (std::is_floating_point<decltype(var)>::value) ss << "-> [ floating point ] "; \
            IF_CONSTEXPR  (std::is_signed<decltype(var)>::value) ss << "-> [ signed ] "; \
            IF_CONSTEXPR  (std::is_unsigned<decltype(var)>::value) ss << "-> [ unsigned ] ";} \
        ss << '\n'; } \
    IF_CONSTEXPR (std::is_compound<decltype(var)>::value) { \
        ss << "[ compound ] "; \
        IF_CONSTEXPR (std::is_function<decltype(var)>::value) ss << "-> [ function ] "; \
        IF_CONSTEXPR (std::is_reference<decltype(var)>::value) { \
            ss << "-> [ reference ] "; \
            IF_CONSTEXPR (std::is_lvalue_reference<decltype(var)>::value) ss << "-> [ lvalue reference ] "; \
            IF_CONSTEXPR (std::is_rvalue_reference<decltype(var)>::value) ss << "-> [ rvalue reference ] "; } \
        IF_CONSTEXPR (std::is_array<decltype(var)>::value) { \
            ss << "-> [ array ] "; \
            IF_CONSTEXPR (std::is_bounded_array<decltype(var)>::value) ss << "-> [ bounded array ] "; \
            IF_CONSTEXPR (std::is_unbounded_array<decltype(var)>::value) ss << "-> [ unbounded array ] "; }\
        IF_CONSTEXPR (std::is_union<decltype(var)>::value) ss << "-> [ union ] "; \
        IF_CONSTEXPR (std::is_class<decltype(var)>::value) { \
            ss << "-> [ class ] "; \
            IF_CONSTEXPR (std::is_empty<decltype(var)>::value) ss << "-> [ empty class ] "; \
            IF_CONSTEXPR (std::is_polymorphic<decltype(var)>::value) { \
                ss << "-> [ polymorphic class ] "; \
                IF_CONSTEXPR (std::is_abstract<decltype(var)>::value) ss << "-> [ abstract class ] "; } \
            IF_CONSTEXPR (std::is_final<decltype(var)>::value) ss << "-> [ final class ] "; \
            IF_CONSTEXPR (std::is_aggregate<decltype(var)>::value) ss << "-> [ aggregate ] "; } \
        IF_CONSTEXPR (std::is_pointer<decltype(var)>::value) ss << "-> [ pointer ] "; \
        IF_CONSTEXPR (std::is_enum<decltype(var)>::value) ss << "-> [ enum ] "; \
        IF_CONSTEXPR (std::is_member_pointer<decltype(var)>::value) { \
            ss << "-> [ member pointer ] "; \
            IF_CONSTEXPR (std::is_member_object_pointer<decltype(var)>::value) ss << "-> [ member object pointer ] "; \
            IF_CONSTEXPR (std::is_member_function_pointer<decltype(var)>::value) ss << "-> [ member function pointer ] "; } \
        ss << '\n'; } \
    IF_CONSTEXPR (std::is_const<decltype(var)>::value) ss << "[ const ] \n"; \
    IF_CONSTEXPR (std::is_volatile<decltype(var)>::value) ss << "[ volatile ] \n"; \
     ss << "CLASS_PROPERTIES\n";\
IF_CONSTEXPR (std::is_constructible<decltype(var)>::value) {\
	ss << "[ constructible ] ";\
	IF_CONSTEXPR (std::is_default_constructible<decltype(var)>::value) ss << "-> [ default constructible ] ";\
	IF_CONSTEXPR (std::is_copy_constructible<decltype(var)>::value) ss << "-> [ copy constructible ] ";\
	IF_CONSTEXPR (std::is_move_constructible<decltype(var)>::value) ss << "-> [ move constructible ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_assignable<decltype(var), decltype(var)>::value) {\
	ss << "[ assignable ] ";\
	IF_CONSTEXPR (std::is_copy_assignable<decltype(var)>::value) ss << "-> [ copy assignable ] ";\
	IF_CONSTEXPR (std::is_move_assignable<decltype(var)>::value) ss << "-> [ move assignable ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_destructible<decltype(var)>::value) {\
	ss << "[ destructible ] ";\
	IF_CONSTEXPR (std::has_virtual_destructor<decltype(var)>::value) ss << "-> [ virtual destructor ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_swappable<decltype(var)>::value) {\
	ss << "[ swappable ] ";\
	IF_CONSTEXPR (std::is_nothrow_swappable<decltype(var)>::value) ss << "-> [ nothrow swappable ] "; \
	ss << '\n';}\
ss << "CLASS_PROPERTIES_TRIVIAL\n";\
IF_CONSTEXPR (std::is_trivial<decltype(var)>::value) ss << "[ trivial ] \n";\
IF_CONSTEXPR (std::is_trivially_copyable<decltype(var)>::value) ss << "[ trivially copyable ] \n";\
IF_CONSTEXPR (std::is_trivially_constructible<decltype(var)>::value) {\
	ss << "[ trivially constructible ] ";\
	IF_CONSTEXPR (std::is_trivially_default_constructible<decltype(var)>::value) ss << "-> [ trivially default constructible ] ";\
	IF_CONSTEXPR (std::is_nothrow_constructible<decltype(var)>::value) {\
		ss << "-> [ nothrow constructible ] ";\
		IF_CONSTEXPR (std::is_nothrow_default_constructible<decltype(var)>::value) ss << "-> [ nothrow default constructible ] ";\
		ss << '\n';}}\
IF_CONSTEXPR (std::is_trivially_copy_constructible<decltype(var)>::value) {\
	ss << "[ trivially copy constructible ] ";\
	IF_CONSTEXPR (std::is_nothrow_copy_constructible<decltype(var)>::value) ss << "-> [ nothrow copy constructible ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_trivially_move_constructible<decltype(var)>::value) {\
	ss << "[ trivially move constructible ] ";\
	IF_CONSTEXPR (std::is_nothrow_move_constructible<decltype(var)>::value) ss << "-> [ nothrow move constructible ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_trivially_copy_assignable<decltype(var)>::value) {\
	ss << "[ trivially copy assignable ] ";\
	IF_CONSTEXPR (std::is_nothrow_copy_assignable<decltype(var)>::value) ss << "-> [ nothrow copy assignable ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_trivially_move_assignable<decltype(var)>::value) {\
	ss << "[ trivially move assignable ] ";\
	IF_CONSTEXPR (std::is_nothrow_move_assignable<decltype(var)>::value) ss << "-> [ nothrow move assignable ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_trivially_destructible<decltype(var)>::value) {\
	ss << "[ trivially destructible ] ";\
	IF_CONSTEXPR (std::is_nothrow_destructible<decltype(var)>::value) ss << "-> [ nothrow destructible ] ";\
	ss << '\n';}\
ss << "[ alignment of: " << std::alignment_of<decltype(var)>::value << " ] \n";\
ss << "[ rank: " << std::rank<decltype(var)>::value << " ] \n";\
IF_CONSTEXPR  (std::rank<decltype(var)>::value > 0) ss << "[ extent: " << std::extent<decltype(var), 0>::value << " ] \n";\
IF_CONSTEXPR (std::is_invocable<decltype(var)>::value) ss << "[ invocable ] \n";\
IF_CONSTEXPR (std::is_nothrow_invocable<decltype(var)>::value) ss << "[ nothrow invocable ] \n";\
std::cout << ss.str()<<'\n';\
} while (0)

#define CPP11_OR_GREATER
#elif   __cplusplus >= 199711L //until c++11
#define UNTIL_CPP11_OR_GREATER 1
#define IF_CONSTEXPR if

#define WHORU(var) \
do { \
    std::stringstream ss; \
    ss << "WHORU [" << typeid(decltype(var)).name() << "] " << #var << "\nBASIC\n"; \
    IF_CONSTEXPR (std::is_object<decltype(var)>::value) { \
        ss << "[ object ] "; \
        IF_CONSTEXPR (std::is_scalar<decltype(var)>::value) ss << "-> [ scalar ] "; \
        ss << '\n';} \
    IF_CONSTEXPR (std::is_fundamental<decltype(var)>::value) { \
        ss << "[ fundamental ] "; \
        IF_CONSTEXPR (std::is_void<decltype(var)>::value) ss << "->  [ void ] "; \
        IF_CONSTEXPR (std::is_null_pointer<decltype(var)>::value) ss << "-> [ null pointer ] "; \
        IF_CONSTEXPR (std::is_arithmetic<decltype(var)>::value) { \
            ss << "-> [ arithmetic ] "; \
            IF_CONSTEXPR (std::is_integral<decltype(var)>::value) ss << "-> [ integral ] "; \
            IF_CONSTEXPR (std::is_floating_point<decltype(var)>::value) ss << "-> [ floating point ] "; \
            IF_CONSTEXPR  (std::is_signed<decltype(var)>::value) ss << "-> [ signed ] "; \
            IF_CONSTEXPR  (std::is_unsigned<decltype(var)>::value) ss << "-> [ unsigned ] ";} \
        ss << '\n'; } \
    IF_CONSTEXPR (std::is_compound<decltype(var)>::value) { \
        ss << "[ compound ] "; \
        IF_CONSTEXPR (std::is_function<decltype(var)>::value) ss << "-> [ function ] "; \
        IF_CONSTEXPR (std::is_reference<decltype(var)>::value) { \
            ss << "-> [ reference ] "; \
            IF_CONSTEXPR (std::is_lvalue_reference<decltype(var)>::value) ss << "-> [ lvalue reference ] "; \
            IF_CONSTEXPR (std::is_rvalue_reference<decltype(var)>::value) ss << "-> [ rvalue reference ] "; } \
        IF_CONSTEXPR (std::is_array<decltype(var)>::value) { \
            ss << "-> [ array ] "; \
            IF_CONSTEXPR (std::is_bounded_array<decltype(var)>::value) ss << "-> [ bounded array ] "; \
            IF_CONSTEXPR (std::is_unbounded_array<decltype(var)>::value) ss << "-> [ unbounded array ] "; }\
        IF_CONSTEXPR (std::is_union<decltype(var)>::value) ss << "-> [ union ] "; \
        IF_CONSTEXPR (std::is_class<decltype(var)>::value) { \
            ss << "-> [ class ] "; \
            IF_CONSTEXPR (std::is_empty<decltype(var)>::value) ss << "-> [ empty class ] "; \
            IF_CONSTEXPR (std::is_polymorphic<decltype(var)>::value) { \
                ss << "-> [ polymorphic class ] "; \
                IF_CONSTEXPR (std::is_abstract<decltype(var)>::value) ss << "-> [ abstract class ] "; } \
            IF_CONSTEXPR (std::is_final<decltype(var)>::value) ss << "-> [ final class ] "; \
            IF_CONSTEXPR (std::is_aggregate<decltype(var)>::value) ss << "-> [ aggregate ] "; } \
        IF_CONSTEXPR (std::is_pointer<decltype(var)>::value) ss << "-> [ pointer ] "; \
        IF_CONSTEXPR (std::is_enum<decltype(var)>::value) ss << "-> [ enum ] "; \
        IF_CONSTEXPR (std::is_member_pointer<decltype(var)>::value) { \
            ss << "-> [ member pointer ] "; \
            IF_CONSTEXPR (std::is_member_object_pointer<decltype(var)>::value) ss << "-> [ member object pointer ] "; \
            IF_CONSTEXPR (std::is_member_function_pointer<decltype(var)>::value) ss << "-> [ member function pointer ] "; } \
        ss << '\n'; } \
    IF_CONSTEXPR (std::is_const<decltype(var)>::value) ss << "[ const ] \n"; \
    IF_CONSTEXPR (std::is_volatile<decltype(var)>::value) ss << "[ volatile ] \n"; \
     ss << "CLASS_PROPERTIES\n";\
IF_CONSTEXPR (std::is_constructible<decltype(var)>::value) {\
	ss << "[ constructible ] ";\
	IF_CONSTEXPR (std::is_default_constructible<decltype(var)>::value) ss << "-> [ default constructible ] ";\
	IF_CONSTEXPR (std::is_copy_constructible<decltype(var)>::value) ss << "-> [ copy constructible ] ";\
	IF_CONSTEXPR (std::is_move_constructible<decltype(var)>::value) ss << "-> [ move constructible ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_assignable<decltype(var), decltype(var)>::value) {\
	ss << "[ assignable ] ";\
	IF_CONSTEXPR (std::is_copy_assignable<decltype(var)>::value) ss << "-> [ copy assignable ] ";\
	IF_CONSTEXPR (std::is_move_assignable<decltype(var)>::value) ss << "-> [ move assignable ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_destructible<decltype(var)>::value) {\
	ss << "[ destructible ] ";\
	IF_CONSTEXPR (std::has_virtual_destructor<decltype(var)>::value) ss << "-> [ virtual destructor ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_swappable<decltype(var)>::value) {\
	ss << "[ swappable ] ";\
	IF_CONSTEXPR (std::is_nothrow_swappable<decltype(var)>::value) ss << "-> [ nothrow swappable ] "; \
	ss << '\n';}\
ss << "CLASS_PROPERTIES_TRIVIAL\n";\
IF_CONSTEXPR (std::is_trivial<decltype(var)>::value) ss << "[ trivial ] \n";\
IF_CONSTEXPR (std::is_trivially_copyable<decltype(var)>::value) ss << "[ trivially copyable ] \n";\
IF_CONSTEXPR (std::is_trivially_constructible<decltype(var)>::value) {\
	ss << "[ trivially constructible ] ";\
	IF_CONSTEXPR (std::is_trivially_default_constructible<decltype(var)>::value) ss << "-> [ trivially default constructible ] ";\
	IF_CONSTEXPR (std::is_nothrow_constructible<decltype(var)>::value) {\
		ss << "-> [ nothrow constructible ] ";\
		IF_CONSTEXPR (std::is_nothrow_default_constructible<decltype(var)>::value) ss << "-> [ nothrow default constructible ] ";\
		ss << '\n';}}\
IF_CONSTEXPR (std::is_trivially_copy_constructible<decltype(var)>::value) {\
	ss << "[ trivially copy constructible ] ";\
	IF_CONSTEXPR (std::is_nothrow_copy_constructible<decltype(var)>::value) ss << "-> [ nothrow copy constructible ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_trivially_move_constructible<decltype(var)>::value) {\
	ss << "[ trivially move constructible ] ";\
	IF_CONSTEXPR (std::is_nothrow_move_constructible<decltype(var)>::value) ss << "-> [ nothrow move constructible ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_trivially_copy_assignable<decltype(var)>::value) {\
	ss << "[ trivially copy assignable ] ";\
	IF_CONSTEXPR (std::is_nothrow_copy_assignable<decltype(var)>::value) ss << "-> [ nothrow copy assignable ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_trivially_move_assignable<decltype(var)>::value) {\
	ss << "[ trivially move assignable ] ";\
	IF_CONSTEXPR (std::is_nothrow_move_assignable<decltype(var)>::value) ss << "-> [ nothrow move assignable ] ";\
	ss << '\n';}\
IF_CONSTEXPR (std::is_trivially_destructible<decltype(var)>::value) {\
	ss << "[ trivially destructible ] ";\
	IF_CONSTEXPR (std::is_nothrow_destructible<decltype(var)>::value) ss << "-> [ nothrow destructible ] ";\
	ss << '\n';}\
ss << "[ alignment of: " << std::alignment_of<decltype(var)>::value << " ] \n";\
ss << "[ rank: " << std::rank<decltype(var)>::value << " ] \n";\
IF_CONSTEXPR  (std::rank<decltype(var)>::value > 0) ss << "[ extent: " << std::extent<decltype(var), 0>::value << " ] \n";\
IF_CONSTEXPR (std::is_invocable<decltype(var)>::value) ss << "[ invocable ] \n";\
IF_CONSTEXPR (std::is_nothrow_invocable<decltype(var)>::value) ss << "[ nothrow invocable ] \n";\
std::cout << ss.str()<<'\n';\
} while (0)

#endif //cpp version

#else //_DEBUG
#define WHORU(var)
#endif //_DEBUG

void WHORU_info()
{
    std::cout << "=====WHORU_info=====\n";
#ifdef _DEBUG

    std::cout << "DEBUG:WHORU將正常作用。\n";

#ifdef CPP23_OR_GREATER
    std::cout << "CPP23_OR_GREATER:WHORU行為可能是未定義或出錯的\n";

#elif CPP20_OR_GREATER
    std::cout << "CPP20_OR_GREATER:WHORU行為是正常的\n";

#elif CPP17_OR_GREATER
    std::cout << "CPP17_OR_GREATER:WHORU行為是正常的\n";

#elif CPP14_OR_GREATER
    std::cout << "CPP14_OR_GREATER:WHORU行為是正常的\n";

#elif CPP11_OR_GREATER
    std::cout << "CPP11_OR_GREATER:WHORU行為可能是未定義或出錯的\n";

#elif UNTIL_CPP11_OR_GREATER
    std::cout << "UNTIL_CPP11_OR_GREATER:WHORU行為可能是未定義或出錯的\n";

#endif //CPP23_OR_GREATER
#else //_DEBUG
    std::cout << "RELEASE:WHORU將沒有作用。\n";
#endif //_DEBUG
    std::cout << "=====WHORU_info=====\n";
    
}

#endif //WHORU_H
