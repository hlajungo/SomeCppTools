#include "WHORU.h"

void WHORU_example_001()
{
	WHORU_info();
	const static int a;
	WHORU(a);

}

//example_001 Output:
//==== = WHORU_info==== =
//DEBUG:WHORU�N���`�@�ΡC
//CPP20_OR_GREATER : WHORU�欰�O���`��
//==== = WHORU_info==== =
//WHORU[int] a
//BASIC
//[object] ->[scalar]
//[fundamental] ->[arithmetic] ->[integral] ->[signed]
//CLASS_PROPERTIES_TRIVIAL
//[trivial]
//[trivially copyable]
//[trivially constructible] ->[trivially default constructible] ->[nothrow constructible] ->[nothrow default constructible]
//[trivially copy constructible] ->[nothrow copy constructible]
//[trivially move constructible] ->[nothrow move constructible]
//[trivially destructible] ->[nothrow destructible]
//[alignment of : 4]
//[rank:0]