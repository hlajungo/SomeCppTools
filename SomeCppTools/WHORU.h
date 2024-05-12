#ifndef WHORU_H 
#define WHORU_H

#include <iostream>
#include <sstream>

#ifdef _DEBUG

#define WHORU(var) \
do { \
    std::stringstream ss; \
    ss << "\nWHORU [" << typeid(decltype(var)).name() << "] " << #var << "\nBASIC\n"; \
    if constexpr(std::is_object<decltype(var)>::value) { \
        ss << "[ object ] "; \
        if constexpr(std::is_scalar<decltype(var)>::value) ss << "-> [ scalar ] "; \
        ss << '\n';} \
    if constexpr(std::is_fundamental<decltype(var)>::value) { \
        ss << "[ fundamental ] "; \
        if constexpr(std::is_void<decltype(var)>::value) ss << "->  [ void ] "; \
        if constexpr(std::is_null_pointer<decltype(var)>::value) ss << "-> [ null pointer ] "; \
        if constexpr(std::is_arithmetic<decltype(var)>::value) { \
            ss << "-> [ arithmetic ] "; \
            if constexpr(std::is_integral<decltype(var)>::value) ss << "-> [ integral ] "; \
            if constexpr(std::is_floating_point<decltype(var)>::value) ss << "-> [ floating point ] "; \
            if constexpr (std::is_signed<decltype(var)>::value) ss << "-> [ signed ] "; \
            if constexpr (std::is_unsigned<decltype(var)>::value) ss << "-> [ unsigned ] ";} \
        ss << '\n'; } \
    if constexpr(std::is_compound<decltype(var)>::value) { \
        ss << "[ compound ] "; \
        if constexpr(std::is_function<decltype(var)>::value) ss << "-> [ function ] "; \
        if constexpr(std::is_reference<decltype(var)>::value) { \
            ss << "-> [ reference ] "; \
            if constexpr(std::is_lvalue_reference<decltype(var)>::value) ss << "-> [ lvalue reference ] "; \
            if constexpr(std::is_rvalue_reference<decltype(var)>::value) ss << "-> [ rvalue reference ] "; } \
        if constexpr(std::is_array<decltype(var)>::value) { \
            ss << "-> [ array ] "; \
            if constexpr(std::is_bounded_array<decltype(var)>::value) ss << "-> [ bounded array ] "; \
            if constexpr(std::is_unbounded_array<decltype(var)>::value) ss << "-> [ unbounded array ] "; } \
        if constexpr(std::is_union<decltype(var)>::value) ss << "-> [ union ] "; \
        if constexpr(std::is_class<decltype(var)>::value) { \
            ss << "-> [ class ] "; \
            if constexpr(std::is_empty<decltype(var)>::value) ss << "-> [ empty class ] "; \
            if constexpr(std::is_polymorphic<decltype(var)>::value) { \
                ss << "-> [ polymorphic class ] "; \
                if constexpr(std::is_abstract<decltype(var)>::value) ss << "-> [ abstract class ] "; } \
            if constexpr(std::is_final<decltype(var)>::value) ss << "-> [ final class ] "; \
            if constexpr(std::is_aggregate<decltype(var)>::value) ss << "-> [ aggregate ] "; } \
        if constexpr(std::is_pointer<decltype(var)>::value) ss << "-> [ pointer ] "; \
        if constexpr(std::is_enum<decltype(var)>::value) ss << "-> [ enum ] "; \
        if constexpr(std::is_member_pointer<decltype(var)>::value) { \
            ss << "-> [ member pointer ] "; \
            if constexpr(std::is_member_object_pointer<decltype(var)>::value) ss << "-> [ member object pointer ] "; \
            if constexpr(std::is_member_function_pointer<decltype(var)>::value) ss << "-> [ member function pointer ] "; } \
        ss << '\n'; } \
    if constexpr(std::is_const<decltype(var)>::value) ss << "[ const ] \n"; \
    if constexpr(std::is_volatile<decltype(var)>::value) ss << "[ volatile ] \n"; \
     ss << "CLASS_PROPERTIES\n";\
if constexpr(std::is_constructible<decltype(var)>::value) {\
	ss << "[ constructible ] ";\
	if constexpr(std::is_default_constructible<decltype(var)>::value) ss << "-> [ default constructible ] ";\
	if constexpr(std::is_copy_constructible<decltype(var)>::value) ss << "-> [ copy constructible ] ";\
	if constexpr(std::is_move_constructible<decltype(var)>::value) ss << "-> [ move constructible ] ";\
	ss << '\n';}\
if constexpr(std::is_assignable<decltype(var), decltype(var)>::value) {\
	ss << "[ assignable ] ";\
	if constexpr(std::is_copy_assignable<decltype(var)>::value) ss << "-> [ copy assignable ] ";\
	if constexpr(std::is_move_assignable<decltype(var)>::value) ss << "-> [ move assignable ] ";\
	ss << '\n';}\
if constexpr(std::is_destructible<decltype(var)>::value) {\
	ss << "[ destructible ] ";\
	if constexpr(std::has_virtual_destructor<decltype(var)>::value) ss << "-> [ virtual destructor ] ";\
	ss << '\n';}\
if constexpr(std::is_swappable<decltype(var)>::value) {\
	ss << "[ swappable ] ";\
	if constexpr(std::is_nothrow_swappable<decltype(var)>::value) ss << "-> [ nothrow swappable ] "; \
	ss << '\n';}\
ss << "CLASS_PROPERTIES_TRIVIAL\n";\
if constexpr(std::is_trivial<decltype(var)>::value) ss << "[ trivial ] \n";\
if constexpr(std::is_trivially_copyable<decltype(var)>::value) ss << "[ trivially copyable ] \n";\
if constexpr(std::is_trivially_constructible<decltype(var)>::value) {\
	ss << "[ trivially constructible ] ";\
	if constexpr(std::is_trivially_default_constructible<decltype(var)>::value) ss << "-> [ trivially default constructible ] ";\
	if constexpr(std::is_nothrow_constructible<decltype(var)>::value) {\
		ss << "-> [ nothrow constructible ] ";\
		if constexpr(std::is_nothrow_default_constructible<decltype(var)>::value) ss << "-> [ nothrow default constructible ] ";\
		ss << '\n';}}\
if constexpr(std::is_trivially_copy_constructible<decltype(var)>::value) {\
	ss << "[ trivially copy constructible ] ";\
	if constexpr(std::is_nothrow_copy_constructible<decltype(var)>::value) ss << "-> [ nothrow copy constructible ] ";\
	ss << '\n';}\
if constexpr(std::is_trivially_move_constructible<decltype(var)>::value) {\
	ss << "[ trivially move constructible ] ";\
	if constexpr(std::is_nothrow_move_constructible<decltype(var)>::value) ss << "-> [ nothrow move constructible ] ";\
	ss << '\n';}\
if constexpr(std::is_trivially_copy_assignable<decltype(var)>::value) {\
	ss << "[ trivially copy assignable ] ";\
	if constexpr(std::is_nothrow_copy_assignable<decltype(var)>::value) ss << "-> [ nothrow copy assignable ] ";\
	ss << '\n';}\
if constexpr(std::is_trivially_move_assignable<decltype(var)>::value) {\
	ss << "[ trivially move assignable ] ";\
	if constexpr(std::is_nothrow_move_assignable<decltype(var)>::value) ss << "-> [ nothrow move assignable ] ";\
	ss << '\n';}\
if constexpr(std::is_trivially_destructible<decltype(var)>::value) {\
	ss << "[ trivially destructible ] ";\
	if constexpr(std::is_nothrow_destructible<decltype(var)>::value) ss << "-> [ nothrow destructible ] ";\
	ss << '\n';}\
ss << "[ alignment of: " << std::alignment_of<decltype(var)>::value << " ] \n";\
ss << "[ rank: " << std::rank<decltype(var)>::value << " ] \n";\
if constexpr (std::rank<decltype(var)>::value > 0) ss << "[ extent: " << std::extent<decltype(var), 0>::value << " ] \n";\
if constexpr(std::is_invocable<decltype(var)>::value) ss << "[ invocable ] \n";\
if constexpr(std::is_nothrow_invocable<decltype(var)>::value) ss << "[ nothrow invocable ] \n";\
std::cout << ss.str();\
} while (0)
#else
#define WHORU(var)
#endif //_DEBUG
#endif //WHORU_H