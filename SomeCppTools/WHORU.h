/***********************************************************************
 * WHORN.h
 * author: hlajungo
 * email: hlajungo@gmail.com
 * date: 2024/05/12
 * 
 * 這個文件包含的功能是提供一個接收一個參數X的宏，能夠輸出X的信息，只在DEBUG模式下提供。
 * 他在C++20,C++17,C++14應該要能正常工作。
 * 他在C++23,C++11,UntilC++17不一定能正常工作，因為Visual Studio 2022只有14，17，20能夠選擇，但是為了完整性還是寫上了。
 * 
 * 請在你的編譯命令行內添加 /Zc:__cplusplus ，否則__cplusplus可能不會如預期工作。
 * reference:
 * https://en.cppreference.com/w/cpp/preprocestd::coutor/replace#Predefined_macros
 * https://en.cppreference.com/w/cpp/meta#Type_traits
 * 
 * TODO :更改版本處理模式，我不想維護那麼多代碼。
 * FINISH :我通過宏套宏的方式完成了，宏裡面是不能用#if的，但是通過宏套宏，可以在宏外做#if判斷。
 * 
 * TODO :移除stringstream庫，統一使用std::cout。
 * FINISH :這樣可以不用添加std::couttream庫，我認為是更好的。
 * 
 * TODO :弄好構造函數那個部分，搞懂或者移除。
 * 
 * 無關緊要的日記：宏是個他媽的深淵，它可以完成一些強大的事情，但是維護起來就是一坨屎，報錯了，恭喜，報錯的地方是調用的地方，不是它m的宏內部，去一行行看代碼吧。
 * 
 * 
 ***********************************************************************/
#ifndef WHORU_H 
#define WHORU_H

#include <iostream>

#ifdef _DEBUG

 // cpp version
#if     __cplusplus >= 202302L //c++23
#define CPP23_OR_GREATER 1
#define IF_CONSTEXPR if constexpr

#define IS_BOUNDARY_ARRAY(var)   IF_CONSTEXPR(std::is_bounded_array<decltype(var)>::value) std::cout << "-> [ bounded array ] "; \
                                 IF_CONSTEXPR(std::is_unbounded_array<decltype(var)>::value) std::cout << "-> [ unbounded array ] "; 

#define IS_INVOCABLE(var)  IF_CONSTEXPR(std::is_invocable<decltype(var)>::value) std::cout << "[ invocable ] \n"; \
                           IF_CONSTEXPR(std::is_nothrow_invocable<decltype(var)>::value) std::cout << "[ nothrow invocable ] \n";

#define IS_SWAPPABLE(var)   IF_CONSTEXPR(std::is_swappable<decltype(var)>::value) {\
                            std::cout << "[ swappable ] "; \
                            IF_CONSTEXPR(std::is_nothrow_swappable<decltype(var)>::value) std::cout << "-> [ nothrow swappable ] ";} 

#define IS_AGGERGATE(var) IF_CONSTEXPR(std::is_aggregate<decltype(var)>::value) std::cout << "-> [ aggregate ] ";


#elif   __cplusplus >= 202002L //c++20
#define CPP20_OR_GREATER 1
#define IF_CONSTEXPR if constexpr

#define IS_BOUNDARY_ARRAY(var)   IF_CONSTEXPR(std::is_bounded_array<decltype(var)>::value) std::cout << "-> [ bounded array ] "; \
                                 IF_CONSTEXPR(std::is_unbounded_array<decltype(var)>::value) std::cout << "-> [ unbounded array ] "; 

#define IS_INVOCABLE(var)  IF_CONSTEXPR(std::is_invocable<decltype(var)>::value) std::cout << "[ invocable ] \n"; \
                           IF_CONSTEXPR(std::is_nothrow_invocable<decltype(var)>::value) std::cout << "[ nothrow invocable ] \n";

#define IS_SWAPPABLE(var)   IF_CONSTEXPR(std::is_swappable<decltype(var)>::value) {\
                            std::cout << "[ swappable ] "; \
                            IF_CONSTEXPR(std::is_nothrow_swappable<decltype(var)>::value) std::cout << "-> [ nothrow swappable ] ";} 

#define IS_AGGERGATE(var) IF_CONSTEXPR(std::is_aggregate<decltype(var)>::value) std::cout << "-> [ aggregate ] ";


#elif   __cplusplus >= 201703L //c++17
#define CPP17_OR_GREATER 1
#define IF_CONSTEXPR if constexpr

#define IS_BOUNDARY_ARRAY(var) 

#define IS_INVOCABLE(var)  IF_CONSTEXPR(std::is_invocable<decltype(var)>::value) std::cout << "[ invocable ] \n"; \
                           IF_CONSTEXPR(std::is_nothrow_invocable<decltype(var)>::value) std::cout << "[ nothrow invocable ] \n";

#define IS_SWAPPABLE(var)   IF_CONSTEXPR(std::is_swappable<decltype(var)>::value) {\
                            std::cout << "[ swappable ] "; \
                            IF_CONSTEXPR(std::is_nothrow_swappable<decltype(var)>::value) std::cout << "-> [ nothrow swappable ] ";} 

#define IS_AGGERGATE(var) IF_CONSTEXPR(std::is_aggregate<decltype(var)>::value) std::cout << "-> [ aggregate ] ";



#elif   __cplusplus >= 201402L //c++14
#define CPP14_OR_GREATER 1
#define IF_CONSTEXPR if 

#define IS_BOUNDARY_ARRAY(var)

#define IS_INVOCABLE(var)

#define IS_SWAPPABLE(var)

#define IS_AGGERGATE(var)


#elif   __cplusplus >= 201103L //c++11
#define CPP11_OR_GREATER 1
#define IF_CONSTEXPR if

#define IS_BOUNDARY_ARRAY(var)

#define IS_INVOCABLE(var)

#define IS_SWAPPABLE(var)

#define IS_AGGERGATE(var) 

#elif   __cplusplus >= 199711L //until c++11
#define UNTIL_CPP11_OR_GREATER 1
#define IF_CONSTEXPR if

#define IS_BOUNDARY_ARRAY(var)

#define IS_INVOCABLE(var)

#define IS_SWAPPABLE(var)

#define IS_AGGERGATE(var) 

#endif //cpp version
 

#define WHORU(var) \
do { \
std::cout << "WHORU [" << typeid(decltype(var)).name() << "] " << #var << "\nBASIC\n"; \
IF_CONSTEXPR (std::is_object<decltype(var)>::value) { \
    std::cout << "[ object ] "; \
    IF_CONSTEXPR (std::is_scalar<decltype(var)>::value) std::cout << "-> [ scalar ] "; \
    std::cout << '\n';} \
IF_CONSTEXPR (std::is_fundamental<decltype(var)>::value) { \
    std::cout << "[ fundamental ] "; \
    IF_CONSTEXPR (std::is_void<decltype(var)>::value) std::cout << "->  [ void ] "; \
    IF_CONSTEXPR (std::is_null_pointer<decltype(var)>::value) std::cout << "-> [ null pointer ] "; \
    IF_CONSTEXPR (std::is_arithmetic<decltype(var)>::value) { \
        std::cout << "-> [ arithmetic ] "; \
        IF_CONSTEXPR (std::is_integral<decltype(var)>::value) std::cout << "-> [ integral ] "; \
        IF_CONSTEXPR (std::is_floating_point<decltype(var)>::value) std::cout << "-> [ floating point ] "; \
        IF_CONSTEXPR  (std::is_signed<decltype(var)>::value) std::cout << "-> [ signed ] "; \
        IF_CONSTEXPR  (std::is_unsigned<decltype(var)>::value) std::cout << "-> [ unsigned ] ";} \
    std::cout << '\n'; } \
IF_CONSTEXPR (std::is_compound<decltype(var)>::value) { \
    std::cout << "[ compound ] "; \
    IF_CONSTEXPR (std::is_function<decltype(var)>::value) std::cout << "-> [ function ] "; \
    IF_CONSTEXPR (std::is_reference<decltype(var)>::value) { \
        std::cout << "-> [ reference ] "; \
        IF_CONSTEXPR (std::is_lvalue_reference<decltype(var)>::value) std::cout << "-> [ lvalue reference ] "; \
        IF_CONSTEXPR (std::is_rvalue_reference<decltype(var)>::value) std::cout << "-> [ rvalue reference ] "; } \
    IF_CONSTEXPR (std::is_array<decltype(var)>::value) { \
        std::cout << "-> [ array ] "; \
        IS_BOUNDARY_ARRAY(var)}\
        IF_CONSTEXPR (std::is_union<decltype(var)>::value) std::cout << "-> [ union ] "; \
    IF_CONSTEXPR (std::is_class<decltype(var)>::value) { \
        std::cout << "-> [ class ] "; \
        IF_CONSTEXPR (std::is_empty<decltype(var)>::value) std::cout << "-> [ empty clastd::cout ] "; \
        IF_CONSTEXPR (std::is_polymorphic<decltype(var)>::value) { \
            std::cout << "-> [ polymorphic class ] "; \
            IF_CONSTEXPR (std::is_abstract<decltype(var)>::value) std::cout << "-> [ abstract clastd::cout ] "; } \
        IF_CONSTEXPR (std::is_final<decltype(var)>::value) std::cout << "-> [ final clastd::cout ] "; \
        IS_AGGERGATE(var)\
    IF_CONSTEXPR (std::is_pointer<decltype(var)>::value) std::cout << "-> [ pointer ] "; \
    IF_CONSTEXPR (std::is_enum<decltype(var)>::value) std::cout << "-> [ enum ] "; \
    IF_CONSTEXPR (std::is_member_pointer<decltype(var)>::value) { \
        std::cout << "-> [ member pointer ] "; \
        IF_CONSTEXPR (std::is_member_object_pointer<decltype(var)>::value) std::cout << "-> [ member object pointer ] "; \
        IF_CONSTEXPR (std::is_member_function_pointer<decltype(var)>::value) std::cout << "-> [ member function pointer ] "; } \
    std::cout << '\n'; } \
IF_CONSTEXPR (std::is_const<decltype(var)>::value) std::cout << "[ const ] \n"; \
IF_CONSTEXPR (std::is_volatile<decltype(var)>::value) std::cout << "[ volatile ] \n"; \
 std::cout << "CLASS_PROPERTIES\n";\
IF_CONSTEXPR (std::is_constructible<decltype(var)>::value) {\
	std::cout << "[ constructible ] ";\
	IF_CONSTEXPR (std::is_default_constructible<decltype(var)>::value) std::cout << "-> [ default constructible ] ";\
	IF_CONSTEXPR (std::is_copy_constructible<decltype(var)>::value) std::cout << "-> [ copy constructible ] ";\
	IF_CONSTEXPR (std::is_move_constructible<decltype(var)>::value) std::cout << "-> [ move constructible ] ";\
	std::cout << '\n';}\
IF_CONSTEXPR (std::is_assignable<decltype(var), decltype(var)>::value) {\
	std::cout << "[ assignable ] ";\
	IF_CONSTEXPR (std::is_copy_assignable<decltype(var)>::value) std::cout << "-> [ copy astd::coutignable ] ";\
	IF_CONSTEXPR (std::is_move_assignable<decltype(var)>::value) std::cout << "-> [ move astd::coutignable ] ";\
	std::cout << '\n';}\
IF_CONSTEXPR (std::is_destructible<decltype(var)>::value) {\
	std::cout << "[ destructible ] ";\
	IF_CONSTEXPR (std::has_virtual_destructor<decltype(var)>::value) std::cout << "-> [ virtual destructor ] ";\
	std::cout << '\n';}\
IS_SWAPPABLE(var)\
	std::cout << '\n';}\
std::cout << "CLASS_PROPERTIES_TRIVIAL\n";\
IF_CONSTEXPR (std::is_trivial<decltype(var)>::value) std::cout << "[ trivial ] \n";\
IF_CONSTEXPR (std::is_trivially_copyable<decltype(var)>::value) std::cout << "[ trivially copyable ] \n";\
IF_CONSTEXPR (std::is_trivially_constructible<decltype(var)>::value) {\
	std::cout << "[ trivially constructible ] ";\
	IF_CONSTEXPR (std::is_trivially_default_constructible<decltype(var)>::value) std::cout << "-> [ trivially default constructible ] ";\
	IF_CONSTEXPR (std::is_nothrow_constructible<decltype(var)>::value) {\
		std::cout << "-> [ nothrow constructible ] ";\
		IF_CONSTEXPR (std::is_nothrow_default_constructible<decltype(var)>::value) std::cout << "-> [ nothrow default constructible ] ";\
		std::cout << '\n';}}\
IF_CONSTEXPR (std::is_trivially_copy_constructible<decltype(var)>::value) {\
	std::cout << "[ trivially copy constructible ] ";\
	IF_CONSTEXPR (std::is_nothrow_copy_constructible<decltype(var)>::value) std::cout << "-> [ nothrow copy constructible ] ";\
	std::cout << '\n';}\
IF_CONSTEXPR (std::is_trivially_move_constructible<decltype(var)>::value) {\
	std::cout << "[ trivially move constructible ] ";\
	IF_CONSTEXPR (std::is_nothrow_move_constructible<decltype(var)>::value) std::cout << "-> [ nothrow move constructible ] ";\
	std::cout << '\n';}\
IF_CONSTEXPR (std::is_trivially_copy_assignable<decltype(var)>::value) {\
	std::cout << "[ trivially copy assignable ] ";\
	IF_CONSTEXPR (std::is_nothrow_copy_assignable<decltype(var)>::value) std::cout << "-> [ nothrow copy astd::coutignable ] ";\
	std::cout << '\n';}\
IF_CONSTEXPR (std::is_trivially_move_assignable<decltype(var)>::value) {\
	std::cout << "[ trivially move assignable ] ";\
	IF_CONSTEXPR (std::is_nothrow_move_assignable<decltype(var)>::value) std::cout << "-> [ nothrow move astd::coutignable ] ";\
	std::cout << '\n';}\
IF_CONSTEXPR (std::is_trivially_destructible<decltype(var)>::value) {\
	std::cout << "[ trivially destructible ] ";\
	IF_CONSTEXPR (std::is_nothrow_destructible<decltype(var)>::value) std::cout << "-> [ nothrow destructible ] ";\
	std::cout << '\n';}\
std::cout << "[ alignment of: " << std::alignment_of<decltype(var)>::value << " ] \n";\
std::cout << "[ rank: " << std::rank<decltype(var)>::value << " ] \n";\
IF_CONSTEXPR  (std::rank<decltype(var)>::value > 0) std::cout << "[ extent: " << std::extent<decltype(var), 0>::value << " ] \n";\
IS_INVOCABLE(var)\
} while (0)


////17
//            /*IF_CONSTEXPR (std::is_bounded_array<decltype(var)>::value) std::cout << "-> [ bounded array ] "; */\
//            /*IF_CONSTEXPR (std::is_unbounded_array<decltype(var)>::value) std::cout << "-> [ unbounded array ] "; */}\
//
//
////14
//            /*IF_CONSTEXPR (std::is_bounded_array<decltype(var)>::value) std::cout << "-> [ bounded array ] ";*/ \
//            /*IF_CONSTEXPR (std::is_unbounded_array<decltype(var)>::value) std::cout << "-> [ unbounded array ] ";*/ }\
//
//            /*IF_CONSTEXPR (std::is_aggregate<decltype(var)>::value) std::cout << "-> [ aggregate ] "; }*/ \
//
//    /*IF_CONSTEXPR (std::is_swappable<decltype(var)>::value) {*/\
//	/*std::cout << "[ swappable ] ";*/\
//	/*IF_CONSTEXPR (std::is_nothrow_swappable<decltype(var)>::value) std::cout << "-> [ nothrow swappable ] ";*/ \
//	/*std::cout << '\n';*/}\
//
///*IF_CONSTEXPR (std::is_invocable<decltype(var)>::value) std::cout << "[ invocable ] \n";*/\
///*IF_CONSTEXPR (std::is_nothrow_invocable<decltype(var)>::value) std::cout << "[ nothrow invocable ] \n";*/\
//


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
