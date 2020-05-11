#ifndef EDAMI_FREQUENTPATTERNDISCO_SPADEMODULE_H
#define EDAMI_FREQUENTPATTERNDISCO_SPADEMODULE_H

#endif //EDAMI_FREQUENTPATTERNDISCO_SPADEMODULE_H

#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject *
spade_system(PyObject *self, PyObject *args)
{
    const char *command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    sts = system(command);
    return PyLong_FromLong(sts);
}

PyMODINIT_FUNC
PyInit_spade(void)
{
    PyObject *m;

    m = PyModule_Create(&spademodule);
    if (m == NULL)
        return NULL;

    SpadeError = PyErr_NewException("spade.error", NULL, NULL);
    Py_XINCREF(SpadeError);
    if (PyModule_AddObject(m, "error", SpadeError) < 0) {
        Py_XDECREF(SpadeError);
        Py_CLEAR(SpadeError);
        Py_DECREF(m);
        return NULL;
    }

    return m;
}