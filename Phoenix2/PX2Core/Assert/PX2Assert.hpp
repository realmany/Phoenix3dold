/*
* Phoenix 3D ���� Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* �ļ�����	��	PX2Assert.hpp
*
* �汾		:	1.0 (2011/01/30)
*
* ����		��	more
*
*/

#ifndef PX2ASSERT_HPP
#define PX2ASSERT_HPP

#include "PX2CorePrerequisites.hpp"

#ifdef PX2_USE_ASSERT
//----------------------------------------------------------------------------
// ʹ��Phoenix2�Ķ���
//----------------------------------------------------------------------------
namespace PX2
{

	class PX2_CORE_ENTRY Assert
	{
	public:
		Assert (bool condition, const char* file, int line, const char* format,
			...);

		~Assert ();

	private:
		enum { MAX_MESSAGE_BYTES = 1024 };
		static const char *msDebugPrompt;
		static const size_t msDebugPromptLength;
		static const char *msMessagePrefix;

#ifdef PX2_USE_ASSERT_WRITE_TO_MESSAGE_BOX
		static const char *msMessageBoxTitle;
#endif

#ifdef PX2_USE_ASSERT_LOG_TO_FILE
		static const char *msLogFileName;
#endif
	};

}

#define assertion(condition, format, ...) \
	PX2::Assert(condition, __FILE__, __LINE__, format, __VA_ARGS__)
//----------------------------------------------------------------------------
#else
//----------------------------------------------------------------------------
// ʹ�ñ�׼����
//----------------------------------------------------------------------------
#define assertion(condition, format, ...) assert(condition)
//----------------------------------------------------------------------------
#endif

#endif