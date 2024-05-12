#include "WHORU.h"

void WHORU_example_001()
{
	const static int a;
	WHORU(a);

	char c;
	WHORU(c);
}

//example_001 Output:
/*
WHORU [int] a
BASIC
[ object ] -> [ scalar ]
[ fundamental ] -> [ arithmetic ] -> [ integral ] -> [ signed ]
[ const ]
CLASS_PROPERTIES
[ constructible ] -> [ default constructible ] -> [ copy constructible ] -> [ move constructible ]
[ destructible ]
CLASS_PROPERTIES_TRIVIAL
[ trivial ]
[ trivially copyable ]
[ trivially constructible ] -> [ trivially default constructible ] -> [ nothrow constructible ] -> [ nothrow default constructible ]
[ trivially copy constructible ] -> [ nothrow copy constructible ]
[ trivially move constructible ] -> [ nothrow move constructible ]
[ trivially destructible ] -> [ nothrow destructible ]
[ alignment of: 4 ]
[ rank: 0 ]

WHORU [char] c
BASIC
[ object ] -> [ scalar ]
[ fundamental ] -> [ arithmetic ] -> [ integral ] -> [ signed ]
CLASS_PROPERTIES
[ constructible ] -> [ default constructible ] -> [ copy constructible ] -> [ move constructible ]
[ destructible ]
[ swappable ] -> [ nothrow swappable ]
CLASS_PROPERTIES_TRIVIAL
[ trivial ]
[ trivially copyable ]
[ trivially constructible ] -> [ trivially default constructible ] -> [ nothrow constructible ] -> [ nothrow default constructible ]
[ trivially copy constructible ] -> [ nothrow copy constructible ]
[ trivially move constructible ] -> [ nothrow move constructible ]
[ trivially copy assignable ] -> [ nothrow copy assignable ]
[ trivially move assignable ] -> [ nothrow move assignable ]
[ trivially destructible ] -> [ nothrow destructible ]
[ alignment of: 1 ]
[ rank: 0 ]
*/