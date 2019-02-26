#ifndef H_SYSTEM_PYTHON
#define	H_SYSTEM_PYTHON

#if defined(__APPLE__)
#include <sys/types.h>
#endif

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <structmember.h>

/* For Python 3, use the PyLong type throughout in place of PyInt */
#if PY_MAJOR_VERSION >= 3
#define PyInt_Check PyLong_Check
#define PyInt_AsLong PyLong_AsLong
#define PyInt_FromLong PyLong_FromLong
#define PyInt_AsUnsignedLongMask PyLong_AsUnsignedLongMask
#define PyInt_AsUnsignedLongLongMask PyLong_AsUnsignedLongLongMask
#define PyInt_AsSsize_t PyLong_AsSsize_t
#endif

static inline PyObject * utf8FromString(const char *s)
{
/* In Python 3, we return all strings as surrogate-escaped utf-8 */
#if PY_MAJOR_VERSION >= 3
    if (s != NULL)
	return PyUnicode_DecodeUTF8(s, strlen(s), "surrogateescape");
#else
    if (s != NULL)
	return PyBytes_FromString(s);
#endif
    Py_RETURN_NONE;
}

#endif	/* H_SYSTEM_PYTHON */
