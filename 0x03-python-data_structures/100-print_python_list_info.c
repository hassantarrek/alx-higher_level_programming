#include <python.h>

/**
 * print_python_list_info - Prints basic info about Python lists
 * @p:PyObject list
 * Return: void
 */

void print_python_list_info(PyObject *p)
{
	int size, loc, x;
	PyObject *obj;
	size = Py_SIZE(p);
	loc = ((PyListObject *)p)->allocated;
	printf("[*] Size of the Python List = %d\n", size);
	printf("[*] Allocated = %d\n", loc);
	for (x = 0; x < size; x++)
	{
		printf("Element %d: ", x);
		obj = PyList_GetItem(p, x);
		printf("%s\n", Py_TYPE(obj)->tp_name);
	}
}
