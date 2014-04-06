#include <Python.h>

/*
 * Function to be called from Python
 */
static PyObject* py_simple_function(PyObject* self, PyObject* args) {
  char* s = "Well this was easy!";
  return Py_BuildValue("s", s);
}

/*
 * Another function to be called from Python
 */
static PyObject* py_another_simple_function(PyObject* self, PyObject* args) {
  int x, y;
  PyArg_ParseTuple(args, "ii", &x, &y);
  return Py_BuildValue("i", x*y);
  char* s = "Equally easy!";
  return Py_BuildValue("s", s);
}

/*
 * Bind Python function names to our C functions
 */
static PyMethodDef simplemodule_methods[] = {
  {"simpleFunction", py_simple_function, METH_VARARGS},
  {"anotherSimpleFunction", py_another_simple_function, METH_VARARGS},
  {NULL, NULL, 0}
};

/*
 * Python calls this to let us initialize our module
 */
void initsimplemodule() {
  (void) Py_InitModule("simplemodule", simplemodule_methods);
}
